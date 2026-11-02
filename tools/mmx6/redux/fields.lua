-- tools/mmx6/redux/fields.lua -- object field watch (T5.c1, phase 2.5); run: tools/mmx6/redux/run.sh tools/mmx6/redux/fields.lua.
-- Input: env MMX6_INPUTS (a tools/mmx6/redux/inputs/<name>.lua schedule), default inputs/intro_stage.lua.
-- Env MMX6_FIELDS ("0x5C:s8,0x84:u8,..."; types s8 u8 s16 u16 s32 u32) overrides the default watch list.
-- Exec breakpoints (sites from SLUS_013.95 bytes):
--   0x800200EC  temp#1 dispatch `jalr a1` in func_8002000C: a0 = obj in g_enemies 0x8008EF48 (stride 0x9C, 48 slots);
--               samples the watch list → {frame,slot,id,fields} and per-field {change,slot,id,from,to,frame}.
--   0x8002D2B0  move_object entry (control, src/SLUS_013.95/object/object.c): a0, x_pos +8, y_pos +0xC, x_vel +0x20,
--               y_vel +0x24 recorded.
--   0x8002D2CC  move_object `jr ra` (bytes: sw v0,8(a0) at 0x8002D2C8; delay slot sw v1,0xC(a0) at 0x8002D2D0):
--               checks a0 same, word +8 == x+vx and v1 (the y about to be stored) == y-vy.
-- Slot state resets when the slot's +0x00 (active) byte reads 0 at a Vsync.
-- Output .run/redux/fields/<run>.jsonl; summary (control, per field: distinct, min/max, changes, slots) at `stop`
-- → <run>.summary.txt, PCSX.quit(rc): rc 1 if a control fails or fewer than 3 control datapoints. Errors → quit(1).
local ffi = require('ffi')
local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')

local DISPATCH = {pc = 0x800200EC, array = 0x8008EF48, stride = 0x9C, slots = 48}
local MOVE_ENTRY, MOVE_RET = 0x8002D2B0, 0x8002D2CC
local CONTROL_LOG_MAX = 200 -- control lines written to the jsonl; all are counted
local DEFAULT_FIELDS = '0x00:s8,0x01:s8,0x04:s8,0x08:s32,0x0C:s32,0x18:s32,0x1A:s16,0x20:s32,0x24:s32,'
                       .. '0x5C:s8,0x60:s8,0x61:s8,0x7C:s16,0x84:s8'
local CTYPE = {s8 = 'int8_t*', u8 = 'uint8_t*', s16 = 'int16_t*', u16 = 'uint16_t*', s32 = 'int32_t*',
               u32 = 'uint32_t*'}

local function parseFields(spec)
    local out = {}
    for item in spec:gmatch('[^,%s]+') do
        local off, ty = item:match('^(0[xX]%x+):(%a+%d+)$')
        assert(off and CTYPE[ty], 'bad MMX6_FIELDS item ' .. item)
        out[#out + 1] = {off = tonumber(off), ty = ty, key = string.format('+0x%02X', tonumber(off))}
    end
    assert(#out > 0, 'empty field list')
    return out
end

local spec = os.getenv('MMX6_FIELDS')
if spec == nil or spec == '' then spec = DEFAULT_FIELDS end
local FIELDS = parseFields(spec)

local inputs = os.getenv('MMX6_INPUTS')
if inputs == nil or inputs == '' then inputs = lib.root .. '/tools/mmx6/redux/inputs/intro_stage.lua' end
local sched = dofile(inputs)
local RUN = sched.name
local OUT = lib.root .. '/.run/redux/fields'
os.execute('mkdir -p "' .. OUT .. '"')

local jsonl = assert(io.open(OUT .. '/' .. RUN .. '.jsonl', 'w'))
local finished = false
local prev = {} -- slot -> {key -> value}
local stats = {} -- key -> {distinct = {v = true}, n, min, max, changes, slots = {slot = true}}
for _, f in ipairs(FIELDS) do stats[f.key] = {distinct = {}, n = 0, changes = 0, slots = {}} end
local ctl = {n = 0, pass = 0, pending = nil}
local samples = 0

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

local function read(addr, ty) -- typed main-RAM read, signed per ty
    return tonumber(ffi.cast(CTYPE[ty], PCSX.getMemPtr() + bit.band(addr, 0x1FFFFF))[0])
end

local function s32(v) return bit.tobit(tonumber(v)) end

lib.breakpoint(DISPATCH.pc, 'fields-dispatch', guarded(function(regs)
    local obj = tonumber(regs.GPR.n.a0)
    local slot = math.floor((obj - DISPATCH.array) / DISPATCH.stride)
    local id = read(obj + 1, 'u8')
    local p = prev[slot]
    if p == nil then p = {}; prev[slot] = p end
    local parts = {}
    for _, f in ipairs(FIELDS) do
        local v = read(obj + f.off, f.ty)
        parts[#parts + 1] = string.format('"%s":%d', f.key, v)
        local st = stats[f.key]
        if not st.distinct[v] then st.distinct[v] = true; st.n = st.n + 1 end
        if st.min == nil or v < st.min then st.min = v end
        if st.max == nil or v > st.max then st.max = v end
        st.slots[slot] = true
        local was = p[f.key]
        if was ~= nil and was ~= v then
            st.changes = st.changes + 1
            jsonl:write(string.format('{"change":"%s","slot":%d,"id":%d,"from":%d,"to":%d,"frame":%d}\n', f.key, slot,
                                      id, was, v, lib.frame))
        end
        p[f.key] = v
    end
    samples = samples + 1
    jsonl:write(string.format('{"frame":%d,"slot":%d,"id":%d,"fields":{%s}}\n', lib.frame, slot, id,
                              table.concat(parts, ',')))
end))

lib.breakpoint(MOVE_ENTRY, 'fields-move-entry', guarded(function(regs)
    local a0 = tonumber(regs.GPR.n.a0)
    ctl.pending = {obj = a0, x = s32(lib.word(a0 + 8)), y = s32(lib.word(a0 + 0xC)), vx = s32(lib.word(a0 + 0x20)),
                   vy = s32(lib.word(a0 + 0x24)), frame = lib.frame}
end))

lib.breakpoint(MOVE_RET, 'fields-move-ret', guarded(function(regs)
    local c = ctl.pending
    if c == nil then return end
    ctl.pending = nil
    local a0 = tonumber(regs.GPR.n.a0)
    local x2 = s32(lib.word(a0 + 8))
    local y2 = s32(regs.GPR.n.v1) -- stored to +0xC by the delay slot of this jr ra
    local pass = a0 == c.obj and x2 == bit.tobit(c.x + c.vx) and y2 == bit.tobit(c.y - c.vy)
    ctl.n = ctl.n + 1
    if pass then ctl.pass = ctl.pass + 1 end
    if ctl.n <= CONTROL_LOG_MAX or not pass then
        jsonl:write(string.format('{"control":"move_object","obj":"%s","pass":%s,"x":%d,"vx":%d,"x2":%d,"y":%d,'
                                      .. '"vy":%d,"y2":%d,"frame":%d}\n', lib.hex(c.obj), tostring(pass), c.x, c.vx,
                                  x2, c.y, c.vy, y2, c.frame))
    end
end))

lib.padSchedule(sched.steps)

lib.onVsync(guarded(function(frame)
    for slot in pairs(prev) do
        if read(DISPATCH.array + slot * DISPATCH.stride, 'u8') == 0 then prev[slot] = nil end
    end
    if frame >= sched.stop then
        local lines = {string.format('FIELDS CONTROL %d/%d', ctl.pass, ctl.n),
                       string.format('summary run=%s frames=%d samples=%d fields=%d', RUN, frame, samples, #FIELDS)}
        for _, f in ipairs(FIELDS) do
            local st = stats[f.key]
            local ns = 0
            for _ in pairs(st.slots) do ns = ns + 1 end
            lines[#lines + 1] = string.format('field %s %s distinct=%d min=%s max=%s changes=%d slots=%d', f.key, f.ty,
                                              st.n, tostring(st.min), tostring(st.max), st.changes, ns)
        end
        local s = table.concat(lines, '\n')
        lib.log(s)
        lib.writeText(OUT .. '/' .. RUN .. '.summary.txt', s .. '\n')
        finish((ctl.n >= 3 and ctl.pass == ctl.n) and 0 or 1)
    end
end))

lib.log('fields armed: run', RUN, 'stop', sched.stop, 'fields', #FIELDS)
