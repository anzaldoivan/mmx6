-- tools/mmx6/redux/datloads.lua -- ROCK_X6.DAT slot load trace (2.2 T4.c1); loads.lua covers BinSeek only.
-- run: MMX6_INPUTS=tools/mmx6/redux/inputs/<name>.lua tools/mmx6/redux/run.sh tools/mmx6/redux/datloads.lua
-- Env MMX6_INPUTS = a pad schedule (same format as loads.lua). Exec bps on the readers of the slot table
-- D_800E0398 (filled by func_800147D0): 0x8001642C (slot, dest, ..) raw read, 0x80016548 (slot, &size) -> lba,
-- 0x80014F70 (slot, mode, dest) packed async read (also re-entered by the retry path 0x80016178).
-- No memory dumps. Output .run/redux/datloads/<run>.jsonl, one line per hit:
--   {"seq","frame","fn","ra","a0","a1"}  (a0 = slot index)
-- At frame `stop` a summary line is logged and written to <run>.summary.txt; PCSX.quit(0). Errors → quit(1).
local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')

local READERS = {{0x8001642C, 'read'}, {0x80016548, 'lba'}, {0x80014F70, 'pack'}}

local sched = dofile(assert(os.getenv('MMX6_INPUTS'), 'MMX6_INPUTS not set'))
local RUN = sched.name
local OUT = lib.root .. '/.run/redux/datloads'
os.execute('mkdir -p "' .. OUT .. '"')

local jsonl = assert(io.open(OUT .. '/' .. RUN .. '.jsonl', 'w'))
local seq = 0
local slots = {}
local nslots = 0
local finished = false

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

for _, r in ipairs(READERS) do
    local addr, name = r[1], r[2]
    lib.breakpoint(addr, name, guarded(function(regs)
        seq = seq + 1
        local a0 = tonumber(regs.GPR.n.a0)
        if not slots[a0] then
            slots[a0] = true
            nslots = nslots + 1
        end
        local line = string.format('{"seq":%d,"frame":%d,"fn":"%s","ra":"%s","a0":%d,"a1":"%s"}\n', seq,
                                   lib.frame, lib.hex(addr), lib.hex(regs.GPR.n.ra), a0, lib.hex(regs.GPR.n.a1))
        jsonl:write(line)
        jsonl:flush()
        lib.log('dat', line)
    end))
end

lib.padSchedule(sched.steps)

lib.onVsync(guarded(function(frame)
    if frame >= sched.stop then
        local s = string.format('summary run=%s frames=%d hits=%d slots=%d', RUN, frame, seq, nslots)
        lib.log(s)
        lib.writeText(OUT .. '/' .. RUN .. '.summary.txt', s .. '\n')
        finish(0)
    end
end))

lib.log('datloads armed: run', RUN, 'stop', sched.stop)
