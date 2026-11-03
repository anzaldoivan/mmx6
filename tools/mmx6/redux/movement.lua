-- tools/mmx6/redux/movement.lua -- player movement datapoints (T6.c1, phase 2.6); run:
--   MMX6_INPUTS=tools/mmx6/redux/inputs/mv_<move>.lua tools/mmx6/redux/run.sh tools/mmx6/redux/movement.lua --timeout 240
-- Schedule: {name, steps, stop, focus = frame the move starts (default 0), pokes = {{frame, field, value, label}}}.
-- Watches g_Player 0x800970A0 (PlayerObj, include/mmx6/player.h). Exec breakpoints (sites from SLUS_013.95 bytes):
--   0x800350F0  `jalr a1` of `D_80073ACC[p->action](p)` in update_player 0x80034FBC (a0 is set in the delay slot:
--               p = s0, target = a1): checks s0 == g_Player and a1 == word(0x80073ACC + 4*action); a line per
--               (action, phase) change → {dp, frame, action, phase, timer, target, fields}.
--   MEMBERS     entries of named movement functions (docs/systems/movement.md ## Members): first K hits per fn at or
--               after `focus` (+ the first hit before it) → {dp, fn, a0 == g_Player, ra, fields}; all hits counted.
--   0x8002D2B0 / 0x8002D2CC  move_object entry / `jr ra` control, as fields.lua (C0316).
--   PROBES      fixed PCs (T6.c2), only those named in the schedule's `probes`: register value at the PC; first K
--               hits per distinct value (pre-EXE-load hits included: check s0_player and frame) →
--               {dp, probe, reg, value, s0_player, fields}; all values counted in the summary.
-- Pokes: at a frame, write a named field of g_Player (labelled stimulus) → {"dp","poke":{...}} line. A numeric field
--   is an absolute u8 address (a global, e.g. the armor source g_playthrough_state+0x5E); an optional 5th element
--   `hold` rewrites it every frame up to that frame (one dp line, write count in the summary).
-- dp ids `<schedule>-<seq4>`, one sequence per run. Optional env MMX6_SCREEN_EVERY=N: screen dumps every N frames to
-- .run/redux/movement/screens/<run>/f<frame>-<w>x<h>-<bpp>.bin (finding pad timings; never committed).
-- Output .run/redux/movement/<run>.jsonl and <run>.summary.txt; quit rc 0 iff `MOVEMENT CONTROL k/k`, k >= 3, and
-- every dispatch check held. Errors → quit(1).
local ffi = require('ffi')
local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')

local PLAYER = 0x800970A0
local DISPATCH_PC, TABLE = 0x800350F0, 0x80073ACC
local MOVE_ENTRY, MOVE_RET = 0x8002D2B0, 0x8002D2CC
local K = 3 -- member hits logged per fn
local CONTROL_LOG_MAX = 20 -- control lines written to the jsonl; all are counted
local SUMMARY_TRANS_MAX = 70 -- transition lines in the summary (all in the jsonl)

-- name, offset, type (include/mmx6/player.h)
local FIELDS = {
    {'action', 0x05, 's8'}, {'phase', 0x06, 's8'}, {'timer', 0x07, 's8'}, {'x', 0x08, 's32'}, {'y', 0x0C, 's32'},
    {'facing', 0x15, 'u8'}, {'x_vel', 0x20, 's32'}, {'y_vel', 0x24, 's32'}, {'gravity', 0x2C, 's32'},
    {'hp', 0x5C, 's8'}, {'air_state', 0x67, 's8'}, {'collision_flags', 0x70, 'u8'}, {'input', 0x7C, 'u16'},
    {'dash_momentum', 0x84, 's8'}, {'dash_timer', 0x85, 's8'}, {'air_action', 0x86, 's8'},
    {'wall_cling_delay', 0x8B, 's8'}, {'low_health_timer', 0x8D, 'u8'}, {'hover_timer', 0xD5, 'u8'},
    {'armor', 0xE7, 'u8'}, {'dash_speed', 0x104, 's32'},
}
local FIELD_BY_NAME = {}
for _, f in ipairs(FIELDS) do FIELD_BY_NAME[f[1]] = f end

-- named movement members (docs/systems/movement.md ## Members) + player_hurt (D_80073ACC target, damage/hurt.c)
local MEMBERS = {
    {'handle_jump_rise', 0x80035620}, {'handle_slide_down', 0x80036EB0}, {'check_dash_input', 0x80039EB0},
    {'end_dash', 0x8003B114}, {'select_air_dash', 0x8003906C}, {'try_start_air_dash', 0x8003F32C},
    {'start_falcon_dash', 0x8003F28C}, {'start_hover', 0x8003F200}, {'try_enter_wall_cling', 0x8003A2CC},
    {'player_enter_wall_cling', 0x8003B3B8}, {'check_ceiling_jump', 0x8003A870},
    {'perform_ceiling_jump', 0x8003649C}, {'move_ceiling', 0x80047460}, {'clamp_player_to_ceiling', 0x80046E14},
    {'end_ceiling_dash', 0x8003737C}, {'try_enter_ladder', 0x8003A3DC}, {'try_leave_ladder', 0x8003A514},
    {'player_enter_ladder_climb_on_top', 0x8003B708}, {'player_enter_ladder_step_off_bottom', 0x8003B774},
    {'player_ladder_climb_on_top', 0x80037548}, {'player_ladder_let_go', 0x800377FC},
    {'player_ladder_step_off_bottom', 0x800375D0}, {'check_low_health', 0x8003D014},
    {'player_check_dash_jump_walk', 0x80039BC4}, {'player_spawn_dash_spark', 0x8003C6A4}, {'spawn_dust', 0x8003D2BC},
    {'player_hurt', 0x80037838},
}
-- T6.c2 probes (sites from SLUS_013.95 bytes): name, pc, register. Armed only when the schedule lists them
-- (`probes = {'name', ...}`), so schedules without probes keep their dp ids.
local PROBE_DEFS = {
    {'falcon_store_action', 0x8003F2EC, 'v0'}, -- start_falcon_dash `sb v0,5(s0)`
    {'ladder_tile_up', 0x8003A428, 'v0'},      -- try_enter_ladder: return of func_8002FD3C (0x20 grabs)
    {'ladder_tile_down', 0x8003A460, 'v0'},    -- try_enter_ladder: return of func_80030068 (0x21 climbs on top)
    {'armor_init', 0x8003D718, 'a0'},          -- func_8003D718 entry: armor = g_playthrough_state+0x5E (8003D598.c)
}
local NAME_AT = {}
for _, m in ipairs(MEMBERS) do NAME_AT[m[2]] = m[1] end
local function fname(addr) return NAME_AT[addr] or string.format('func_%08X', addr) end

local CTYPE = {s8 = 'int8_t*', u8 = 'uint8_t*', s16 = 'int16_t*', u16 = 'uint16_t*', s32 = 'int32_t*'}
local function read(addr, ty) return tonumber(ffi.cast(CTYPE[ty], PCSX.getMemPtr() + bit.band(addr, 0x1FFFFF))[0]) end
local function write(addr, ty, v) ffi.cast(CTYPE[ty], PCSX.getMemPtr() + bit.band(addr, 0x1FFFFF))[0] = v end
local function s32(v) return bit.tobit(tonumber(v)) end
local function u32(v) return bit.band(tonumber(v), 0xFFFFFFFF) % 0x100000000 end

local inputs = os.getenv('MMX6_INPUTS')
if inputs == nil or inputs == '' then inputs = 'tools/mmx6/redux/inputs/mv_walk.lua' end
if inputs:sub(1, 1) ~= '/' then inputs = lib.root .. '/' .. inputs end -- Redux cwd is .run/redux/work
local okSched, sched = pcall(dofile, inputs)
if not okSched then -- a top-level error would leave Redux running until the timeout
    lib.log('error', sched)
    lib.quit(1)
    return
end
local RUN = sched.name
local FOCUS = sched.focus or 0
local OUT = lib.root .. '/.run/redux/movement'
os.execute('mkdir -p "' .. OUT .. '"')
local SCREEN_EVERY = tonumber(os.getenv('MMX6_SCREEN_EVERY') or '')
local SCREEN_DIR = OUT .. '/screens/' .. RUN
if SCREEN_EVERY then os.execute('mkdir -p "' .. SCREEN_DIR .. '"') end

local jsonl = assert(io.open(OUT .. '/' .. RUN .. '.jsonl', 'w'))
local finished = false
local seq = 0
local ctl = {n = 0, pass = 0, pending = nil, player = 0}
local disp = {n = 0, bad = 0, last = nil, targets = {}, order = {}} -- targets[action] = {addr, n, dp}
local trans = {} -- summary lines
local ntrans = 0
local hits = {} -- addr -> {n, logged, first = {dp, frame, player, fields}}
local pokes = {}
for _, p in ipairs(sched.pokes or {}) do
    pokes[#pokes + 1] = {f = p[1], field = p[2], value = p[3], label = p[4], hold = p[5], writes = 0}
end
local probeVals = {} -- probe name -> {order = {v...}, [v] = {n, logged, dp}}
local PROBES = {}
for _, want in ipairs(sched.probes or {}) do
    local def
    for _, d in ipairs(PROBE_DEFS) do if d[1] == want then def = d end end
    PROBES[#PROBES + 1] = assert(def, 'unknown probe ' .. tostring(want))
end

local function nextDp()
    seq = seq + 1
    return string.format('%s-%04d', RUN, seq)
end

local function fieldsJson(obj)
    local parts = {}
    for _, f in ipairs(FIELDS) do parts[#parts + 1] = string.format('"%s":%d', f[1], read(obj + f[2], f[3])) end
    return '{' .. table.concat(parts, ',') .. '}'
end

local function fieldsShort(obj) -- compact summary form
    local function g(n) local f = FIELD_BY_NAME[n]; return read(obj + f[2], f[3]) end
    return string.format('a=%d/%d t=%d x=%d y=%d vx=%d vy=%d g=%d air=%d aa=%d col=0x%02X in=0x%04X dm=%d dt=%d '
                             .. 'wcd=%d lht=%d hov=%d hp=%d arm=%d ds=%d', g('action'), g('phase'), g('timer'),
                         g('x'), g('y'), g('x_vel'), g('y_vel'), g('gravity'), g('air_state'), g('air_action'),
                         g('collision_flags'), g('input'), g('dash_momentum'), g('dash_timer'),
                         g('wall_cling_delay'), g('low_health_timer'), g('hover_timer'), g('hp'), g('armor'),
                         g('dash_speed'))
end

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

lib.breakpoint(DISPATCH_PC, 'mv-dispatch', guarded(function(regs)
    local p = u32(regs.GPR.n.s0)
    local target = u32(regs.GPR.n.a1)
    local action = read(p + 5, 's8')
    local phase = read(p + 6, 's8')
    local expect = lib.word(TABLE + 4 * action)
    disp.n = disp.n + 1
    local ok = p == PLAYER and target == expect
    if not ok then
        disp.bad = disp.bad + 1
        jsonl:write(string.format('{"dispatch_check":"fail","p":"%s","target":"%s","expect":"%s","frame":%d}\n',
                                  lib.hex(p), lib.hex(target), lib.hex(expect), lib.frame))
    end
    local t = disp.targets[action]
    if t == nil then
        t = {addr = target, n = 0}
        disp.targets[action] = t
        disp.order[#disp.order + 1] = action
    end
    t.n = t.n + 1
    local key = action * 256 + phase
    if disp.last ~= key then
        disp.last = key
        local dp = nextDp()
        if t.dp == nil then t.dp = dp end
        jsonl:write(string.format('{"dp":"%s","frame":%d,"action":%d,"phase":%d,"timer":%d,"target":"%s","fn":"%s",'
                                      .. '"fields":%s}\n', dp, lib.frame, action, phase, read(p + 7, 's8'),
                                  lib.hex(target), fname(target), fieldsJson(p)))
        if lib.frame >= FOCUS then
            ntrans = ntrans + 1
            if ntrans <= SUMMARY_TRANS_MAX then
                trans[#trans + 1] = string.format('%s f%d %s %s', dp, lib.frame, fname(target), fieldsShort(p))
            end
        end
    end
end))

for _, m in ipairs(MEMBERS) do
    local name, addr = m[1], m[2]
    hits[addr] = {n = 0, nf = 0, logged = 0}
    lib.breakpoint(addr, 'mv-' .. name, guarded(function(regs)
        local h = hits[addr]
        h.n = h.n + 1
        if lib.frame >= FOCUS then h.nf = h.nf + 1 end
        if lib.frame < FOCUS then -- one pre-focus hit kept (who calls it before the move)
            if h.pre then return end
            h.pre = true
        else
            if h.logged >= K then return end
            h.logged = h.logged + 1
        end
        local a0 = u32(regs.GPR.n.a0)
        local dp = nextDp()
        jsonl:write(string.format('{"dp":"%s","frame":%d,"fn":"%s","addr":"%s","a0_player":%s,"ra":"%s","fields":%s}\n',
                                  dp, lib.frame, name, lib.hex(addr), tostring(a0 == PLAYER), lib.hex(u32(regs.GPR.n.ra)),
                                  fieldsJson(PLAYER)))
        if lib.frame >= FOCUS and h.first == nil then
            h.first = string.format('%s f%d a0_player=%s %s', dp, lib.frame, tostring(a0 == PLAYER), fieldsShort(PLAYER))
        end
    end))
end

for _, pr in ipairs(PROBES) do
    local name, pc, reg = pr[1], pr[2], pr[3]
    probeVals[name] = {order = {}}
    lib.breakpoint(pc, 'mv-' .. name, guarded(function(regs)
        local s0 = u32(regs.GPR.n.s0)
        local v = u32(regs.GPR.n[reg])
        local pv = probeVals[name]
        local e = pv[v]
        if e == nil then
            e = {n = 0, logged = 0}
            pv[v] = e
            pv.order[#pv.order + 1] = v
        end
        e.n = e.n + 1
        if e.logged >= K then return end
        e.logged = e.logged + 1
        local dp = nextDp()
        if e.dp == nil then e.dp = dp end
        jsonl:write(string.format('{"dp":"%s","frame":%d,"probe":"%s","pc":"%s","reg":"%s","value":"%s",'
                                      .. '"s0_player":%s,"fields":%s}\n', dp, lib.frame, name, lib.hex(pc), reg,
                                  lib.hex(v), tostring(s0 == PLAYER), fieldsJson(PLAYER)))
    end))
end

lib.breakpoint(MOVE_ENTRY, 'mv-move-entry', guarded(function(regs)
    local a0 = u32(regs.GPR.n.a0)
    ctl.pending = {obj = a0, x = s32(lib.word(a0 + 8)), y = s32(lib.word(a0 + 0xC)), vx = s32(lib.word(a0 + 0x20)),
                   vy = s32(lib.word(a0 + 0x24)), frame = lib.frame}
end))

lib.breakpoint(MOVE_RET, 'mv-move-ret', guarded(function(regs)
    local c = ctl.pending
    if c == nil then return end
    ctl.pending = nil
    local a0 = u32(regs.GPR.n.a0)
    local x2 = s32(lib.word(a0 + 8))
    local y2 = s32(regs.GPR.n.v1) -- stored to +0xC by the delay slot of this jr ra
    local pass = a0 == c.obj and x2 == bit.tobit(c.x + c.vx) and y2 == bit.tobit(c.y - c.vy)
    ctl.n = ctl.n + 1
    if pass then ctl.pass = ctl.pass + 1 end
    if c.obj == PLAYER then ctl.player = ctl.player + 1 end
    if ctl.n <= CONTROL_LOG_MAX or not pass then
        jsonl:write(string.format('{"control":"move_object","obj":"%s","pass":%s,"x":%d,"vx":%d,"x2":%d,"y":%d,'
                                      .. '"vy":%d,"y2":%d,"frame":%d}\n', lib.hex(c.obj), tostring(pass), c.x, c.vx,
                                  x2, c.y, c.vy, y2, c.frame))
    end
end))

lib.padSchedule(sched.steps)

lib.onVsync(guarded(function(frame)
    for _, pk in ipairs(pokes) do
        if pk.done and pk.hold and frame <= pk.hold then -- held global: rewrite every frame up to `hold`
            write(pk.addr, pk.ty, pk.value)
            pk.writes = pk.writes + 1
        end
        if not pk.done and frame >= pk.f then
            pk.done = true
            local name, off
            if type(pk.field) == 'number' then -- absolute u8 address (a global)
                pk.addr, pk.ty = pk.field, 'u8'
                name, off = lib.hex(pk.field), 0
            else
                local f = assert(FIELD_BY_NAME[pk.field], 'unknown poke field ' .. tostring(pk.field))
                pk.addr, pk.ty = PLAYER + f[2], f[3]
                name, off = pk.field, f[2]
            end
            local from = read(pk.addr, pk.ty)
            write(pk.addr, pk.ty, pk.value)
            pk.writes = 1
            local dp = nextDp()
            pk.dp = dp
            jsonl:write(string.format('{"dp":"%s","poke":{"field":"%s","off":"0x%02X","from":%d,"to":%d,"hold":%d,'
                                          .. '"label":"%s"},"frame":%d}\n', dp, name, off, from, pk.value,
                                      pk.hold or frame, pk.label or '', frame))
            pk.line = string.format('poke %s f%d %s %d->%d hold=%d (%s)', dp, frame, name, from, pk.value,
                                    pk.hold or frame, pk.label or '')
        end
    end
    if SCREEN_EVERY and frame % SCREEN_EVERY == 0 then lib.dumpScreen(string.format('%s/f%06d', SCREEN_DIR, frame)) end
    if frame >= sched.stop then
        local ok = ctl.n >= 3 and ctl.pass == ctl.n and disp.bad == 0 and disp.n > 0
        local L = {string.format('MOVEMENT CONTROL %d/%d', ctl.pass, ctl.n),
                   string.format('summary run=%s frames=%d focus=%d dps=%d control_player=%d dispatch=%d bad=%d', RUN,
                                 frame, FOCUS, seq, ctl.player, disp.n, disp.bad)}
        for _, pk in ipairs(pokes) do
            if pk.line then L[#L + 1] = pk.line .. ' writes=' .. pk.writes end
        end
        for _, pr in ipairs(PROBES) do
            local pv = probeVals[pr[1]]
            local parts = {}
            for _, v in ipairs(pv.order) do parts[#parts + 1] = string.format('%s:%d(%s)', lib.hex(v), pv[v].n, pv[v].dp) end
            L[#L + 1] = string.format('probe %s values=%s', pr[1], #parts > 0 and table.concat(parts, ' ') or '-')
        end
        table.sort(disp.order)
        for _, a in ipairs(disp.order) do
            local t = disp.targets[a]
            L[#L + 1] = string.format('dispatch action=%d target=%s %s frames=%d first=%s', a, lib.hex(t.addr),
                                      fname(t.addr), t.n, t.dp)
        end
        L[#L + 1] = string.format('transitions from focus: %d (first %d listed)', ntrans, math.min(ntrans,
                                                                                                   SUMMARY_TRANS_MAX))
        for _, l in ipairs(trans) do L[#L + 1] = l end
        for _, m in ipairs(MEMBERS) do
            local h = hits[m[2]]
            L[#L + 1] = string.format('fn %s hits=%d from_focus=%d first=%s', m[1], h.n, h.nf, h.first or '-')
        end
        local s = table.concat(L, '\n')
        lib.log(L[1])
        lib.writeText(OUT .. '/' .. RUN .. '.summary.txt', s .. '\n')
        finish(ok and 0 or 1)
    end
end))

lib.log('movement armed: run', RUN, 'stop', sched.stop, 'focus', FOCUS, 'members', #MEMBERS)
