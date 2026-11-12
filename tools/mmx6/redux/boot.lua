-- tools/mmx6/redux/boot.lua -- boot chain, front-end state loop and rock_18 residency datapoints (T19.c1, phase 2.6); run:
--   MMX6_INPUTS=tools/mmx6/redux/inputs/<sched>.lua [MMX6_STOP=<frame>] [MMX6_RUN_TAG=<tag>] \
--     tools/mmx6/redux/run.sh tools/mmx6/redux/boot.lua --timeout 240
-- Schedule {name, steps, stop}; env MMX6_STOP overrides sched.stop; run name = <name>[-<MMX6_RUN_TAG>].
-- Exec breakpoints (sites from SLUS_013.95 bytes):
--   0x8001D178  `jalr v1` of `D_800710E8[state](&D_800CD3F8)` in func_8001D0E4 (a0 is set in the delay slot from s2,
--               so at the bp target = v1, arg = s2). Control: pass iff v1 == word(0x800710E8 + 4*state) and
--               s2 == 0x800CD3F8 (state = u8 at 0x800CD3F8). A line per state change.
--   D_800710E8  read once at the first func_8001D0E4 entry: words until the first outside 0x80010000-0x8006D5D4 (cap
--               16) → one `table` line; a first-hit bp is added on each distinct target.
--   Residency   rock_18 member (a0 0x12) at 0x800E9860: resident after BinSeek 0x80016858 (a0 0x12, a1 0x800E9860)
--               completes (ready callback 0x800165A4 at 0x80016628 with remaining word 0x800E01A8 == 0, as
--               loads.lua); not resident from any BinSeek with a1 in [0x800E9860, 0x800E9860+0x7EE8). The 16 rock_18
--               fn bps are enabled only while resident (bp:enable()/disable() when present; callbacks check too).
--   First-hit   BIN loader, boot chain, P0/P1 fns and the table targets: hits, first frame, first ra (no gate).
--   Range (T19.c2) Exec bps with a width: rock_18 range (residency-gated, a row per residency seq); ctl_exe over
--               func_8001D0E4 (ungated, must fire); ctl_other over the rock_18 range while a non-0x12 member is
--               resident at 0x800E9860 (BinSeek a1 0x800E9860, a0 != 0x12, ready callback done).
-- Output .run/redux/boot/<run>.jsonl, one object per line:
--   {"table":[{"i","addr"}...]}  {"load":seq,"frame","index","dest","resident"}  (resident = after this event)
--   {"resident":seq,"frame"}  {"state":to,"from","frame","target"}  {"control":"jalr","pass","state","target","want","arg","frame"}
--   (control lines: first 8 and every failure).
-- <run>.summary.txt (≤ ~80 lines, deterministic; run= is the schedule name without the tag, so runs `cmp` equal):
--   `BOOT CONTROL k/n`, `summary run= frames= loads= resident_loads=
--   transitions=`, `table i:addr ...`, `state <s> first=<frame> target=<addr> count=<n>`,
--   `fn <group> <addr> <label> hits=<n> first=<frame|-> ra=<addr|-> [seq=<n>]` (seq = residency load of the first hit),
--   `range rock_18 seq=<k> hits= first= pc= min= max=`, `range ctl_exe ...`, `range ctl_other ...`.
-- Opt-in (T25.c1; off → the lines above only, byte-identical to T19):
--   sched.asm = true: asm-reach layer (see asmArm) → `first state6=<frame|->`, `load k:index:dest:frame ...`,
--     `asm <prog> <addr> <name> hits= first= ra= [seq=]` per function hit (by addr), `asm <prog> armed= hit=
--     not_reached=` per prog, `range rock_NN seq=<k> ...` per member residency (rock_18: its T19 lines).
--   sched.stop_on = 'player_dispatch': run ends the Vsync after the first passing player dispatch →
--     `stop player_dispatch frame= action= target=` (never → `frame=-`, rc 1).
--   sched.require = {addr...}: `require <addr> hits= first=` each; rc 1 unless all hit.
--   env MMX6_EXPLORE=1 [MMX6_DUMP=f,f]: state bytes 0x800CD3F8+0..+0xF on change and screens, .run/redux/explore/.
-- rc 0 iff `BOOT CONTROL k/k`, k >= 3 (and the stop/require conditions when set). Errors → quit(1).
local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')

local BINSEEK = 0x80016858
local CB_ENTRY = 0x800165A4
local CB_REMAINING = 0x80016628 -- in 0x800165A4, after `lw v1, 0x1A8(0x800E0000)`
local REMAINING = 0x800E01A8
local R18_INDEX, R18_BASE, R18_SIZE = 0x12, 0x800E9860, 0x7EE8
local JALR = 0x8001D178 -- objdump-style decode of SLUS_013.95 0x8001D0E4-0x8001D218: `jalr v1` / delay `addu a0,s2,zero`
local LOOP_FN = 0x8001D0E4
local TABLE, STATE = 0x800710E8, 0x800CD3F8
local TEXT_LO, TEXT_HI = 0x80010000, 0x8006D5D4
local CONTROL_LOG_MAX = 8

local R18_FNS = {0x800EA5C8, 0x800ED6D4, 0x800ED760, 0x800EDBA8, 0x800EEF88, 0x800EF6A4, 0x800EF8D0, 0x800EF964,
                 0x800EFBFC, 0x800EFDE4, 0x800F00F4, 0x800F0114, 0x800F03C4, 0x800F05C4, 0x800F0618, 0x800F0870,
                 0x800ED96C, 0x800EDA38, 0x800EDB6C} -- last three: the span the range bp saw executing (T19 attempt 2)
local FIRST = {
    {'loader', 0x80016780, 'func_80016780'}, {'loader', BINSEEK, 'BinSeek'}, {'loader', 0x80014E60, 'func_80014E60'},
    {'loader', 0x80014D50, 'func_80014D50'}, {'loader', CB_ENTRY, 'ready_cb'},
    {'chain', 0x800120A0, 'func_800120A0'}, {'chain', 0x80012658, 'init_system'},
    {'chain', 0x8001CB3C, 'func_8001CB3C'}, {'chain', LOOP_FN, 'func_8001D0E4'},
    {'p0p1', 0x8001344C, 'func_8001344C'}, {'p0p1', 0x80013DE8, 'func_80013DE8'}, {'p0p1', 0x80014F70, 'func_80014F70'},
    {'p0p1', 0x800139F4, 'func_800139F4'}, {'p0p1', 0x80013530, 'func_80013530'},
}

local function resolve(p)
    if p:sub(1, 1) ~= '/' then p = lib.root .. '/' .. p end
    return p
end
local sched = dofile(resolve(assert(os.getenv('MMX6_INPUTS'), 'MMX6_INPUTS not set')))
local STOP = tonumber(os.getenv('MMX6_STOP') or '') or sched.stop
local TAG = os.getenv('MMX6_RUN_TAG') or ''
local RUN = sched.name .. (TAG ~= '' and ('-' .. TAG) or '')
local OUT = lib.root .. '/.run/redux/boot'
os.execute('mkdir -p "' .. OUT .. '"')
local jsonl = assert(io.open(OUT .. '/' .. RUN .. '.jsonl', 'w'))

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
local function out(line)
    jsonl:write(line .. '\n')
    jsonl:flush()
end

-- One bp per address; hooks run in registration order. Kept in MMX6_LIB (lib.breakpoint anchors the bp).
local sites = {}
lib.boot_sites = sites
local function site(addr)
    local s = sites[addr]
    if s == nil then
        s = {hooks = {}}
        s.bp = lib.breakpoint(addr, string.format('boot-%08X', addr), guarded(function(regs)
            for _, h in ipairs(s.hooks) do h(regs) end
        end))
        sites[addr] = s
    end
    return s
end
local function bpCall(bp, method)
    local ok, f = pcall(function() return bp[method] end)
    if ok and f then pcall(f, bp) end
end
-- Gated sites (T25.c1): s.gates = list of fn() → bool; the bp is enabled iff any gate holds (s.always: never gated).
local function gate(s, fn)
    s.gates = s.gates or {}
    s.gates[#s.gates + 1] = fn
end
local function refresh(s)
    if s.always or s.gates == nil then return end
    local on = false
    for _, g in ipairs(s.gates) do if g() then on = true break end end
    bpCall(s.bp, on and 'enable' or 'disable')
end

local stats = {} -- addr → {group, label, hits, first, ra, seq}
local order = {}
local resident, rseq = false, 0
local function watch(group, addr, label, gated)
    local st = stats[addr]
    if st then
        if not st.label:find(label, 1, true) then st.label = st.label .. '/' .. label end
        return st
    end
    st = {group = group, label = label, hits = 0}
    stats[addr] = st
    order[#order + 1] = addr
    local s = site(addr)
    s.hooks[#s.hooks + 1] = function(regs)
        if gated and not resident then return end
        st.hits = st.hits + 1
        if st.first == nil then
            st.first, st.ra, st.seq = lib.frame, tonumber(regs.GPR.n.ra), rseq
        end
    end
    return st
end

-- Range Exec bps (T19.c2): PCSX.addBreakpoint with a width (lib.breakpoint is width 4); per hit: count, first frame,
-- first pc, min/max pc. rowFn() returns the row to count into, or nil (gate). Anchored in lib._bps.
local function rangeBp(name, base, width, rowFn)
    local cb = guarded(function()
        local row = rowFn()
        if row == nil then return end
        local pc = tonumber(PCSX.getRegisters().pc)
        row.hits = row.hits + 1
        if row.first == nil then
            row.first, row.pc, row.min, row.max = lib.frame, pc, pc, pc
        elseif pc < row.min then row.min = pc
        elseif pc > row.max then row.max = pc end
    end)
    local label = 'boot-range-' .. name
    local bp = PCSX.addBreakpoint(base, 'Exec', width, label, function() cb() return true end, label)
    lib._bps[#lib._bps + 1] = bp
    return bp
end
local function newRow() return {hits = 0} end
local r18rows = {} -- rseq → row
local ctlExe, ctlOther = newRow(), newRow()
local otherResident = false
local r18range = rangeBp('rock_18', R18_BASE, R18_SIZE, function() return resident and r18rows[rseq] or nil end)
rangeBp('ctl_exe', LOOP_FN, 0x8001D218 - LOOP_FN, function() return ctlExe end)
local otherRange = rangeBp('ctl_other', R18_BASE, R18_SIZE, function() return otherResident and ctlOther or nil end)
local function setOther(v)
    otherResident = v
    bpCall(otherRange, v and 'enable' or 'disable')
end

local r18sites = {}
local function setResident(v)
    resident = v
    if v and r18rows[rseq] == nil then r18rows[rseq] = newRow() end
    for _, s in ipairs(r18sites) do refresh(s) end
    bpCall(r18range, v and 'enable' or 'disable')
end

-- Residency (BinSeek / ready callback as loads.lua).
local nloads, pending, pendingOther = 0, nil, nil
local bs = site(BINSEEK)
bs.hooks[#bs.hooks + 1] = function(regs)
    nloads = nloads + 1
    local index, dest = tonumber(regs.GPR.n.a0), tonumber(regs.GPR.n.a1)
    pending = (index == R18_INDEX and dest == R18_BASE) and nloads or nil
    pendingOther = (index ~= R18_INDEX and dest == R18_BASE) and nloads or nil
    if dest >= R18_BASE and dest < R18_BASE + R18_SIZE then
        setResident(false)
        setOther(false)
    end
    out(string.format('{"load":%d,"frame":%d,"index":%d,"dest":"%s","resident":%s}', nloads, lib.frame, index,
                      lib.hex(dest), tostring(resident)))
end
site(CB_REMAINING).hooks[1] = function(regs)
    if pending == nil or lib.word(REMAINING) ~= 0 then return end
    pending = nil
    rseq = rseq + 1
    setResident(true)
    out(string.format('{"resident":%d,"frame":%d}', rseq, lib.frame))
end
site(CB_REMAINING).hooks[2] = function(regs)
    if pendingOther == nil or lib.word(REMAINING) ~= 0 then return end
    pendingOther = nil
    setOther(true)
end

for _, f in ipairs(FIRST) do watch(f[1], f[2], f[3], false) end
for _, a in ipairs(R18_FNS) do
    watch('rock_18', a, string.format('r18_%08X', a), true)
    r18sites[#r18sites + 1] = sites[a]
    gate(sites[a], function() return resident end)
end
setResident(false)
setOther(false)

-- Asm-reach layer (T25.c1), on iff sched.asm: every INCLUDE_ASM function of src/SLUS_013.95 and src/rock_NN gets
-- an entry first-hit bp (SLUS ungated; rock_NN gated by member NN residency, the rock_18 rule generalised: resident
-- after BinSeek a0 = NN, a1 = loadmap base completes via the ready callback; not resident from any BinSeek with a1 in
-- [base, base+size), size from the config/rock_NN.yaml header) plus a range bp per member, a row per residency seq.
-- Name → addr: config/symbols.<prog>.txt row; else a func_<hex> name (splat auto-name). Excluded: LIB* segments,
-- __start, D_ names, rows with a type: other than func.
-- Entry hooks (T25.c1): an Exec bp on a dispatch `jalr` masks the entry bp of an overlay target (rock_18
-- 0x800EA5C8: 0 hits with the 0x8001D178 bp on, 911 = the state-8 dispatch count with it off; SLUS targets fire).
-- So entries through a known dispatch jalr are counted by that jalr's hook (h(ra = jalr+8)) and the site hook skips
-- ra == jalr+8: one count per entry either way.
local enterHooks, JALR_RA = {}, {[JALR + 8] = true}
local function onEnter(addr, h)
    local l = enterHooks[addr]
    if l == nil then
        l = {}
        enterHooks[addr] = l
        local s = site(addr)
        s.hooks[#s.hooks + 1] = function(regs)
            local ra = tonumber(regs.GPR.n.ra)
            if JALR_RA[ra] then return end
            for _, f in ipairs(l) do f(ra) end
        end
    end
    l[#l + 1] = h
    return sites[addr]
end
local function jalrEnter(target, ra)
    local l = enterHooks[target]
    if l then for _, f in ipairs(l) do f(ra) end end
end
local asmFns, asmProgs, members, asmPending = {}, {}, {}, nil
local function readLines(path)
    local f = assert(io.open(path, 'r'), 'cannot open ' .. path)
    local t = {}
    for l in f:lines() do t[#t + 1] = l end
    f:close()
    return t
end
local function asmArm()
    local loadmap = {}
    for _, l in ipairs(readLines(lib.root .. '/config/loadmap.txt')) do
        local i, b = l:match('^(%d+) 0x(%x+) ')
        if i then loadmap[tonumber(i)] = tonumber(b, 16) end
    end
    local sizeOf = {} -- member index → size (config/rock_NN.yaml header), for every member that has a yaml
    for i in pairs(loadmap) do
        local f = io.open(string.format('%s/config/rock_%02d.yaml', lib.root, i), 'r')
        if f then
            for yl in f:lines() do
                local sz = yl:match('^#.*size 0x(%x+)')
                if sz then sizeOf[i] = tonumber(sz, 16) break end
            end
            f:close()
        end
    end
    local syms = {}
    local function symsOf(prog)
        if syms[prog] then return syms[prog] end
        local t = {}
        for _, l in ipairs(readLines(lib.root .. '/config/symbols.' .. prog .. '.txt')) do
            local n, a, rest = l:match('^([%w_]+) = 0x(%x+);(.*)$')
            if n then t[n] = {addr = tonumber(a, 16), type = rest:match('type:(%S+)')} end
        end
        syms[prog] = t
        return t
    end
    local p = io.popen('cd "' .. lib.root .. '" && grep -rn --include="*.c" INCLUDE_ASM src/SLUS_013.95 src/rock_[0-9][0-9]')
    local seen = {}
    for l in p:lines() do
        local file, line, prog, seg, name = l:match('^([^:]+):(%d+):INCLUDE_ASM%("asm/([^/]+)/nonmatchings/([^"]+)", *([%w_]+)%)')
        if file and seg:sub(1, 3) ~= 'LIB' and name ~= '__start' and name:sub(1, 2) ~= 'D_' then
            local row = symsOf(prog)[name]
            local addr = row and row.addr or (name:match('^func_(%x+)$') and tonumber(name:sub(6), 16))
            local ok = addr ~= nil and (row == nil or row.type == nil or row.type == 'func')
            local key = prog .. ':' .. tostring(addr)
            if ok and not seen[key] then
                seen[key] = true
                local pg = asmProgs[prog]
                if pg == nil then
                    pg = {name = prog, armed = 0, hit = 0}
                    local nn = prog:match('^rock_(%d+)$')
                    if nn then
                        local m = {index = tonumber(nn), prog = prog, resident = false, seq = 0, rows = {}}
                        m.base = assert(loadmap[m.index], 'no loadmap base for ' .. prog)
                        m.size = assert(sizeOf[m.index], 'no size in config/' .. prog .. '.yaml')
                        members[#members + 1] = m
                        pg.member = m
                    end
                    asmProgs[prog] = pg
                end
                pg.armed = pg.armed + 1
                asmFns[#asmFns + 1] = {prog = prog, addr = addr, name = name, src = file .. ':' .. line, hits = 0,
                                       pg = pg, m = pg.member}
            end
        end
    end
    p:close()
    for _, fn in ipairs(asmFns) do
        local m = fn.m
        local s = onEnter(fn.addr, function(ra)
            if m and not m.resident then return end
            fn.hits = fn.hits + 1
            if fn.first == nil then
                fn.first, fn.ra, fn.seq = lib.frame, ra, m and m.seq or nil
                fn.pg.hit = fn.pg.hit + 1
            end
        end)
        if m then gate(s, function() return m.resident end) else s.always = true end
    end
    for _, m in ipairs(members) do
        if m.index ~= R18_INDEX then -- rock_18 keeps its T19 range bp and lines
            m.range = rangeBp(m.prog, m.base, m.size, function() return m.resident and m.rows[m.seq] or nil end)
            bpCall(m.range, 'disable')
        end
    end
    local function setMember(m, v)
        m.resident = v
        if v then m.seq = m.seq + 1; m.rows[m.seq] = newRow() end
        if m.range then bpCall(m.range, v and 'enable' or 'disable') end
    end
    local function refreshAll() for _, fn in ipairs(asmFns) do if fn.m then refresh(sites[fn.addr]) end end end
    bs.hooks[#bs.hooks + 1] = function(regs)
        local index, dest = tonumber(regs.GPR.n.a0), tonumber(regs.GPR.n.a1)
        asmPending = nil
        local changed = false
        -- Not resident when the incoming member's extent [a1, a1+size) overlaps (size known), else when a1 falls in
        -- [base, base+size): e.g. rock_02 at 0x800E9860 (size 0x12420) overwrites rock_46 at 0x800FA000.
        local len = (dest == loadmap[index] and sizeOf[index]) or 1
        for _, m in ipairs(members) do
            if m.resident and dest < m.base + m.size and dest + len > m.base then setMember(m, false); changed = true end
            if index == m.index and dest == m.base then asmPending = m end
        end
        if changed then refreshAll() end
    end
    site(CB_REMAINING).hooks[#site(CB_REMAINING).hooks + 1] = function(regs)
        if asmPending == nil or lib.word(REMAINING) ~= 0 then return end
        setMember(asmPending, true)
        asmPending = nil
        refreshAll()
    end
    refreshAll()
    lib.log('asm armed', #asmFns, 'members', #members)
end
if sched.asm then asmArm() end

-- Load list (asm layer only): one entry per BinSeek.
local loadList = {}
bs.hooks[#bs.hooks + 1] = function(regs)
    loadList[#loadList + 1] = {index = tonumber(regs.GPR.n.a0), dest = tonumber(regs.GPR.n.a1), frame = lib.frame}
end

-- sched.stop_on = 'player_dispatch' (T25.c1): bp 0x800350F0 as movement.lua; the first hit with s0 == 0x800970A0
-- and a1 == word(0x80073ACC + 4*action) (action = s8 at s0+5) ends the run at the next Vsync; never → rc 1.
local PLAYER, DISPATCH_PC, ACTION_TABLE = 0x800970A0, 0x800350F0, 0x80073ACC
local function byte(a) return bit.band(bit.rshift(lib.word(a - a % 4), 8 * (a % 4)), 0xFF) end
local stopHit = nil
if sched.stop_on then
    assert(sched.stop_on == 'player_dispatch', 'unknown stop_on ' .. tostring(sched.stop_on))
    local s = site(DISPATCH_PC)
    s.always = true
    JALR_RA[DISPATCH_PC + 8] = true
    s.hooks[#s.hooks + 1] = function(regs)
        jalrEnter(tonumber(regs.GPR.n.a1), DISPATCH_PC + 8)
        if stopHit then return end
        local p, target = tonumber(regs.GPR.n.s0), tonumber(regs.GPR.n.a1)
        if p ~= PLAYER then return end
        local action = byte(p + 5)
        if action >= 0x80 then action = action - 0x100 end
        if target == lib.word(ACTION_TABLE + 4 * action) then
            stopHit = {frame = lib.frame, action = action, target = target}
        end
    end
end
-- sched.require = {addr...}: rc 1 unless each was hit.
local required = {}
for _, a in ipairs(sched.require or {}) do
    local r = {addr = a, hits = 0}
    required[#required + 1] = r
    local s = onEnter(a, function()
        r.hits = r.hits + 1
        if r.first == nil then r.first = lib.frame end
    end)
    s.always = true
    bpCall(s.bp, 'enable')
end

-- Exploration (env MMX6_EXPLORE=1; never in the summary): state byte and bytes +1..+0xF of 0x800CD3F8 on change,
-- and screens at the frames in MMX6_DUMP (comma list), to .run/redux/explore/<run>.txt / <run>-<frame>-*.bin.
if os.getenv('MMX6_EXPLORE') == '1' then
    local dir = lib.root .. '/.run/redux/explore'
    os.execute('mkdir -p "' .. dir .. '"')
    local ef = assert(io.open(dir .. '/' .. RUN .. '.txt', 'w'))
    lib.explore_file = ef
    local dumps = {}
    for f in (os.getenv('MMX6_DUMP') or ''):gmatch('%d+') do dumps[tonumber(f)] = true end
    local prev = ''
    lib.onVsync(guarded(function(frame)
        local b = {}
        for i = 0, 15 do b[#b + 1] = string.format('%02X', byte(STATE + i)) end
        local cur = table.concat(b, ' ')
        if cur ~= prev then
            ef:write(string.format('%d %s\n', frame, cur))
            ef:flush()
            prev = cur
        end
        if dumps[frame] then lib.dumpScreen(string.format('%s/%s-%d', dir, RUN, frame)) end
    end))
end

-- D_800710E8, read once the EXE is running.
local tbl = nil
local lp = site(LOOP_FN)
lp.hooks[#lp.hooks + 1] = function(regs)
    if tbl then return end
    tbl = {}
    local parts = {}
    for i = 0, 15 do
        local w = lib.word(TABLE + 4 * i)
        if w < TEXT_LO or w > TEXT_HI then break end
        tbl[i] = w
        parts[#parts + 1] = string.format('{"i":%d,"addr":"%s"}', i, lib.hex(w))
        watch('target', w, string.format('D_800710E8[%d]', i), false)
    end
    out('{"table":[' .. table.concat(parts, ',') .. ']}')
end

-- Dispatch jalr: control + per-state stats.
local ctl = {n = 0, pass = 0}
local states, prevState, transitions = {}, nil, 0
site(JALR).hooks[1] = function(regs)
    local state = bit.band(lib.word(STATE), 0xFF)
    local target = tonumber(regs.GPR.n.v1)
    local arg = tonumber(regs.GPR.n.s2)
    local want = lib.word(TABLE + 4 * state)
    local pass = target == want and arg == STATE
    ctl.n = ctl.n + 1
    if pass then ctl.pass = ctl.pass + 1 end
    if ctl.n <= CONTROL_LOG_MAX or not pass then
        out(string.format('{"control":"jalr","pass":%s,"state":%d,"target":"%s","want":"%s","arg":"%s","frame":%d}',
                          tostring(pass), state, lib.hex(target), lib.hex(want), lib.hex(arg), lib.frame))
    end
    local s = states[state]
    if s == nil then
        s = {first = lib.frame, target = target, count = 0}
        states[state] = s
    end
    s.count = s.count + 1
    if state ~= prevState then
        transitions = transitions + 1
        out(string.format('{"state":%d,"from":%s,"frame":%d,"target":"%s"}', state,
                          prevState and tostring(prevState) or 'null', lib.frame, lib.hex(target)))
        prevState = state
    end
end

site(JALR).hooks[#site(JALR).hooks + 1] = function(regs) jalrEnter(tonumber(regs.GPR.n.v1), JALR + 8) end

lib.padSchedule(sched.steps)

lib.onVsync(guarded(function(frame)
    if frame < STOP and stopHit == nil then return end
    local lines = {string.format('BOOT CONTROL %d/%d', ctl.pass, ctl.n),
                   string.format('summary run=%s frames=%d loads=%d resident_loads=%d transitions=%d', sched.name, frame,
                                 nloads, rseq, transitions)}
    local tp = {}
    for i = 0, 15 do if tbl and tbl[i] then tp[#tp + 1] = string.format('%d:%s', i, lib.hex(tbl[i])) end end
    lines[#lines + 1] = 'table ' .. table.concat(tp, ' ')
    for i = 0, 255 do
        local s = states[i]
        if s then
            lines[#lines + 1] = string.format('state %d first=%d target=%s count=%d', i, s.first, lib.hex(s.target),
                                              s.count)
        end
    end
    for _, a in ipairs(order) do
        local st = stats[a]
        lines[#lines + 1] = string.format('fn %s %s %s hits=%d first=%s ra=%s%s', st.group, lib.hex(a), st.label,
                                          st.hits, st.first and tostring(st.first) or '-',
                                          st.ra and lib.hex(st.ra) or '-',
                                          st.group == 'rock_18' and (' seq=' .. (st.first and st.seq or '-')) or '')
    end
    local function rangeLine(name, row, seq)
        local h = function(v) return v and lib.hex(v) or '-' end
        return string.format('range %s%s hits=%d first=%s pc=%s min=%s max=%s', name, seq and (' seq=' .. seq) or '',
                             row.hits, row.first and tostring(row.first) or '-', h(row.pc), h(row.min), h(row.max))
    end
    if rseq == 0 then lines[#lines + 1] = rangeLine('rock_18', newRow(), '-') end
    for k = 1, rseq do lines[#lines + 1] = rangeLine('rock_18', r18rows[k] or newRow(), tostring(k)) end
    lines[#lines + 1] = rangeLine('ctl_exe', ctlExe)
    lines[#lines + 1] = rangeLine('ctl_other', ctlOther)
    local ok = ctl.n >= 3 and ctl.pass == ctl.n
    if sched.asm then
        lines[#lines + 1] = 'first state6=' .. (states[6] and tostring(states[6].first) or '-')
        local lp = {}
        for k, l in ipairs(loadList) do lp[#lp + 1] = string.format('%d:%d:%s:%d', k, l.index, lib.hex(l.dest), l.frame) end
        lines[#lines + 1] = 'load ' .. table.concat(lp, ' ')
        local hit = {}
        for _, fn in ipairs(asmFns) do if fn.hits > 0 then hit[#hit + 1] = fn end end
        table.sort(hit, function(x, y) if x.addr ~= y.addr then return x.addr < y.addr end return x.prog < y.prog end)
        for _, fn in ipairs(hit) do
            lines[#lines + 1] = string.format('asm %s %s %s hits=%d first=%d ra=%s%s', fn.prog, lib.hex(fn.addr), fn.name,
                                              fn.hits, fn.first, lib.hex(fn.ra), fn.m and (' seq=' .. fn.seq) or '')
        end
        local pn = {}
        for n in pairs(asmProgs) do pn[#pn + 1] = n end
        table.sort(pn)
        for _, n in ipairs(pn) do
            local pg = asmProgs[n]
            lines[#lines + 1] = string.format('asm %s armed=%d hit=%d not_reached=%d', n, pg.armed, pg.hit,
                                              pg.armed - pg.hit)
        end
        local ms = {}
        for _, m in ipairs(members) do if m.range then ms[#ms + 1] = m end end
        table.sort(ms, function(x, y) return x.prog < y.prog end)
        for _, m in ipairs(ms) do
            for k = 1, m.seq do lines[#lines + 1] = rangeLine(m.prog, m.rows[k], tostring(k)) end
        end
    end
    if sched.stop_on then
        lines[#lines + 1] = stopHit and string.format('stop player_dispatch frame=%d action=%d target=%s', stopHit.frame,
                                                      stopHit.action, lib.hex(stopHit.target))
                            or 'stop player_dispatch frame=- action=- target=-'
        if stopHit == nil then ok = false end
    end
    for _, r in ipairs(required) do
        lines[#lines + 1] = string.format('require %s hits=%d first=%s', lib.hex(r.addr), r.hits,
                                          r.first and tostring(r.first) or '-')
        if r.hits == 0 then ok = false end
    end
    local text = table.concat(lines, '\n') .. '\n'
    lib.log(text)
    lib.writeText(OUT .. '/' .. RUN .. '.summary.txt', text)
    if lib.explore_file then lib.explore_file:close() end
    finish(ok and 0 or 1)
end))

lib.log('boot armed: run', RUN, 'stop', STOP)
