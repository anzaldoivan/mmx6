-- tools/mmx6/redux/loads.lua -- overlay load capture (T5.c1); run: make redux-loads (one run per inputs/*.lua).
-- Env MMX6_INPUTS = a pad schedule (tools/mmx6/redux/inputs/<name>.lua) returning
--   {name = <run>, steps = {{frame, 'BUTTON', hold}, ...}, stop = <frame>}.
-- Per load: Exec bp on BinSeek 0x80016858 records caller = ra, index = a0, dest = a1, size = TOC word at
-- 0x800E0B58 + index*8 + 4, and dumps [dest, dest+size) "before". The read completes in the ready callback
-- 0x800165A4: at 0x80016628 it has just loaded remaining (word 0x800E01A8) after the per-sector copy; the
-- first hit with remaining = 0 dumps "after" (same point for the synchronous 0x80013xxx callers and the
-- async 0x80052E94 path). Output .run/redux/loads/<run>.jsonl, one line per load:
--   {"seq","frame","caller","index","dest","size","before","after","w10000"}
-- (w10000 = word at 0x80010000 at the call: the base 0x80013E7C loads to), dumps <run>-<seq>-{before,after}.bin.
-- At frame `stop` a summary line is logged and written to <run>.summary.txt; PCSX.quit(0). Errors → quit(1).
-- Optional env MMX6_SCREEN_EVERY=N: screen dump every N frames to .run/redux/screens/<run>/f<frame>-*.bin (finding timings).
local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')

local BINSEEK = 0x80016858
local CB_REMAINING = 0x80016628 -- in 0x800165A4, after `lw v1, 0x1A8(0x800E0000)`
local REMAINING = 0x800E01A8
local TOC = 0x800E0B58
local W10000 = 0x80010000
local E7C_RA = 0x80013E84 -- return address of the call at 0x80013E7C

local sched = dofile(assert(os.getenv('MMX6_INPUTS'), 'MMX6_INPUTS not set'))
local RUN = sched.name
local OUT = lib.root .. '/.run/redux/loads'
os.execute('mkdir -p "' .. OUT .. '"')
local SCREEN_EVERY = tonumber(os.getenv('MMX6_SCREEN_EVERY') or '')
local SCREEN_DIR = lib.root .. '/.run/redux/screens/' .. RUN
if SCREEN_EVERY then os.execute('mkdir -p "' .. SCREEN_DIR .. '"') end

local jsonl = assert(io.open(OUT .. '/' .. RUN .. '.jsonl', 'w'))
local seq = 0
local pending = nil
local finished = false
local e7c = {}

local function finish(code)
    if finished then return end
    finished = true
    jsonl:close()
    lib.quit(code)
end

local function guarded(fn)
    return function(...)
        if finished then return end
        local ok, err = pcall(fn, ...)
        if not ok then
            lib.log('error', err)
            finish(1)
        end
    end
end

local function emit(rec, after)
    local line = string.format('{"seq":%d,"frame":%d,"caller":"%s","index":%d,"dest":"%s","size":%d,'
                                   .. '"before":"%s","after":%s,"w10000":"%s"}\n', rec.seq, rec.frame,
                               lib.hex(rec.caller), rec.index, lib.hex(rec.dest), rec.size, rec.before,
                               after and ('"' .. after .. '"') or 'null', lib.hex(rec.w10000))
    jsonl:write(line)
    jsonl:flush()
    lib.log('load', line)
end

lib.breakpoint(BINSEEK, 'BinSeek', guarded(function(regs)
    if pending then
        lib.log('warn: BinSeek before load', pending.seq, 'completed; after = null')
        emit(pending, nil)
    end
    seq = seq + 1
    local index = tonumber(regs.GPR.n.a0)
    local rec = {seq = seq, frame = lib.frame, caller = regs.GPR.n.ra, index = index, dest = regs.GPR.n.a1,
                 size = lib.word(TOC + index * 8 + 4), w10000 = lib.word(W10000)}
    rec.before = string.format('%s-%03d-before.bin', RUN, seq)
    lib.dumpRange(OUT .. '/' .. rec.before, rec.dest, rec.size)
    if tonumber(rec.caller) == E7C_RA then e7c[#e7c + 1] = lib.hex(rec.dest) end
    pending = rec
end))

lib.breakpoint(CB_REMAINING, 'ReadDone', guarded(function(regs)
    if pending == nil or lib.word(REMAINING) ~= 0 then return end
    local after = string.format('%s-%03d-after.bin', RUN, pending.seq)
    lib.dumpRange(OUT .. '/' .. after, pending.dest, pending.size)
    emit(pending, after)
    pending = nil
end))

lib.padSchedule(sched.steps)

lib.onVsync(guarded(function(frame)
    if SCREEN_EVERY and frame % SCREEN_EVERY == 0 then lib.dumpScreen(string.format('%s/f%06d', SCREEN_DIR, frame)) end
    if frame >= sched.stop then
        if pending then emit(pending, nil) end
        local s = string.format('summary run=%s frames=%d loads=%d e7c_dests=[%s] w10000=%s', RUN, frame, seq,
                                table.concat(e7c, ','), lib.hex(lib.word(W10000)))
        lib.log(s)
        lib.writeText(OUT .. '/' .. RUN .. '.summary.txt', s .. '\n')
        finish(0)
    end
end))

lib.log('loads armed: run', RUN, 'stop', sched.stop)
