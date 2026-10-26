-- tools/mmx6/redux/objects.lua -- object-type map capture (T5.c1); run: tools/mmx6/redux/run.sh tools/mmx6/redux/objects.lua.
-- Input: env MMX6_INPUTS (a tools/mmx6/redux/inputs/<name>.lua schedule), default inputs/intro_stage.lua.
-- Exec breakpoints (sites from SLUS_013.95 bytes, T5.c1 log):
--   0x80013EC0 / 0x80013ED8  stage-load setter: `sw v1,0x80/0x84(0x1F800000)`; v1 = temp#1 / temp#2 type table,
--                            s3+0xC / +0xD = stage / substage. Dumps the table words (77 / 58, bound = next
--                            table in the per-stage block) to <run>-<seq>-<table>.bin.
--   0x800200EC / 0x80020338  dispatch `jalr a1` in func_8002000C (temp#1) / func_80020258 (temp#2): a0 = obj,
--                            id = obj[1], fn = a1.
--   0x8002A148 / 0x8002A51C  return of func_8002A3AC (class allocator by record type & 0xF) in func_80029F38 /
--                            func_8002A4E4 (stage-list spawners): rec = s2 / s0 {flags,id,sub,type,x,y}, obj = v0.
-- Output .run/redux/objects/<run>.jsonl: {table,slot,id,fn,frame} per dispatch (slot = (obj-array)/stride),
-- {table:"origin",rec,type,id,sub,alloc,obj,frame} per spawn, {table:"set-temp#n",stage,sub,ptr,dump,frame}
-- per setter; summary line at `stop` → <run>.summary.txt, PCSX.quit(0). Errors → quit(1).
local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')

local SETTERS = {[0x80013EC0] = {name = 'temp#1', words = 77}, [0x80013ED8] = {name = 'temp#2', words = 58}}
local DISPATCH = {{pc = 0x800200EC, name = 'temp#1', array = 0x8008EF48, stride = 0x9C},
                  {pc = 0x80020338, name = 'temp#2', array = 0x80093C98, stride = 0xA0}}
local SPAWN = {{pc = 0x8002A148, rec = 's2'}, {pc = 0x8002A51C, rec = 's0'}}
local ALLOC_TBL = 0x8007347C

local inputs = os.getenv('MMX6_INPUTS')
if inputs == nil or inputs == '' then inputs = lib.root .. '/tools/mmx6/redux/inputs/intro_stage.lua' end
local sched = dofile(inputs)
local RUN = sched.name
local OUT = lib.root .. '/.run/redux/objects'
os.execute('mkdir -p "' .. OUT .. '"')

local jsonl = assert(io.open(OUT .. '/' .. RUN .. '.jsonl', 'w'))
local finished = false
local seq = 0
local counts = {dispatch = 0, origin = 0, set = 0, mismatch = 0}
local live = {} -- table name -> {ptr, words}

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

local function byte(addr, k) -- byte k of the aligned word at addr (little-endian)
    return bit.band(bit.rshift(lib.word(addr), 8 * k), 0xFF)
end

for pc, s in pairs(SETTERS) do
    lib.breakpoint(pc, 'set-' .. s.name, guarded(function(regs)
        seq = seq + 1
        local ptr = tonumber(regs.GPR.n.v1)
        local s3 = tonumber(regs.GPR.n.s3)
        local stage, sub = byte(s3 + 0xC, 0), byte(s3 + 0xC, 1)
        local dump = string.format('%s-%03d-%s.bin', RUN, seq, s.name:gsub('#', ''))
        lib.dumpRange(OUT .. '/' .. dump, ptr, s.words * 4)
        live[s.name] = {ptr = ptr, words = s.words}
        counts.set = counts.set + 1
        jsonl:write(string.format('{"table":"set-%s","stage":%d,"sub":%d,"ptr":"%s","dump":"%s","frame":%d}\n',
                                  s.name, stage, sub, lib.hex(ptr), dump, lib.frame))
        jsonl:flush()
        lib.log('set', s.name, stage, sub, lib.hex(ptr))
    end))
end

for _, d in ipairs(DISPATCH) do
    lib.breakpoint(d.pc, 'dispatch-' .. d.name, guarded(function(regs)
        local obj = tonumber(regs.GPR.n.a0)
        local fn = tonumber(regs.GPR.n.a1)
        local id = byte(obj, 1)
        local t = live[d.name]
        if t and lib.word(t.ptr + 4 * id) ~= fn then counts.mismatch = counts.mismatch + 1 end
        counts.dispatch = counts.dispatch + 1
        jsonl:write(string.format('{"table":"%s","slot":%d,"id":%d,"fn":"%s","frame":%d}\n', d.name,
                                  math.floor((obj - d.array) / d.stride), id, lib.hex(fn), lib.frame))
    end))
end

for _, s in ipairs(SPAWN) do
    lib.breakpoint(s.pc, 'spawn', guarded(function(regs)
        local rec = tonumber(regs.GPR.n[s.rec])
        local w = lib.word(rec)
        local typ = bit.band(bit.rshift(w, 24), 0xF)
        counts.origin = counts.origin + 1
        jsonl:write(string.format('{"table":"origin","rec":"%s","type":%d,"id":%d,"sub":%d,"alloc":"%s","obj":"%s",'
                                      .. '"frame":%d}\n', lib.hex(rec), typ, bit.band(bit.rshift(w, 8), 0xFF),
                                  bit.band(bit.rshift(w, 16), 0xFF), lib.hex(lib.word(ALLOC_TBL + 4 * typ)),
                                  lib.hex(regs.GPR.n.v0), lib.frame))
    end))
end

lib.padSchedule(sched.steps)

lib.onVsync(guarded(function(frame)
    if frame >= sched.stop then
        local s = string.format('summary run=%s frames=%d sets=%d dispatch=%d origin=%d mismatch=%d', RUN, frame,
                                counts.set, counts.dispatch, counts.origin, counts.mismatch)
        lib.log(s)
        lib.writeText(OUT .. '/' .. RUN .. '.summary.txt', s .. '\n')
        finish(counts.mismatch == 0 and 0 or 1)
    end
end))

lib.log('objects armed: run', RUN, 'stop', sched.stop)
