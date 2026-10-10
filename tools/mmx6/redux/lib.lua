-- tools/mmx6/redux/lib.lua -- helpers for repo Lua scripts run by tools/mmx6/redux/run.sh (PCSX-Redux).
-- Load with: local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')
-- API names per the Lua sources embedded in the Redux binary (core/pcsxffi.lua, the event-name list):
-- PCSX.addBreakpoint(addr, 'Exec', 4, cause, invoker(address, width, cause)), PCSX.getRegisters().GPR.n.a0,
-- PCSX.Events.createEventListener('GPU::Vsync', fn), Support.File.open(path, 'TRUNCATE'):write(ptr, size),
-- PCSX.SIO0.slots[1].pads[1].setOverride/clearOverride(PCSX.CONSTS.PAD.BUTTON.x), PCSX.GPU.getVRAM() (T5.c1).
local ffi = require('ffi')
local M = {}
-- Anchor everything Redux calls back into in a global: a listener or breakpoint reachable only from the
-- script's locals is collected once the chunk returns, and the next callback segfaults Redux (T4.c1).
MMX6_LIB = M

M.root = os.getenv('MMX6_ROOT') or '.'
M.RAM_SIZE = 0x200000 -- main RAM, 2 MiB; getMemPtr() offset = addr & 0x1FFFFF

-- Unthrottled: SPU master-clock speed 0 = run as fast as the host allows (~150 fps interpreter, M-series).
-- run.sh passes -portable, so this never reaches the user's ~/.config/pcsx-redux settings.
PCSX.settings.spu.Speed = 0

M.frame = 0
M._listeners = {}
local vsyncHooks = {}

-- Frame counter: one tick per GPU::Vsync; hooks run as fn(frame).
M._listeners[#M._listeners + 1] = PCSX.Events.createEventListener('GPU::Vsync', function()
    M.frame = M.frame + 1
    for _, fn in ipairs(vsyncHooks) do fn(M.frame) end
end)
function M.onVsync(fn) vsyncHooks[#vsyncHooks + 1] = fn end

-- Exec breakpoint; fn(regs) runs on each hit; returns the breakpoint (keep it referenced).
M._bps = {}
function M.breakpoint(addr, label, fn)
    local bp = PCSX.addBreakpoint(addr, 'Exec', 4, label, function(address, width, cause)
        fn(PCSX.getRegisters())
        return true
    end, label)
    M._bps[#M._bps + 1] = bp
    return bp
end

function M.hex(v) return string.format('0x%08X', tonumber(v)) end

-- u32 at a main-RAM address.
function M.word(addr) return tonumber(ffi.cast('uint32_t*', PCSX.getMemPtr() + bit.band(addr, 0x1FFFFC))[0]) end

-- Write [addr, addr+size) of main RAM to path (raw bytes).
function M.dumpRange(path, addr, size)
    local f = Support.File.open(path, 'TRUNCATE')
    f:write(PCSX.getMemPtr() + bit.band(addr, 0x1FFFFF), size)
    f:close()
end

function M.dumpRAM(path) M.dumpRange(path, 0x80000000, M.RAM_SIZE) end

function M.writeText(path, text)
    local f = Support.File.open(path, 'TRUNCATE')
    f:write(text)
    f:close()
end

-- Save state given to run.sh --state (MMX6_REDUX_STATE); returns true if one was loaded.
function M.loadState()
    local p = os.getenv('MMX6_REDUX_STATE')
    if p == nil or p == '' then return false end
    PCSX.loadSaveState(Support.File.open(p))
    return true
end

-- Displayed screen (PCSX.GPU.takeScreenShot: raw pixels, bpp 0 = 16-bit BGR555, 1 = 24-bit RGB) to
-- <stem>-<w>x<h>-<bpp>.bin, for identifying screens offline.
function M.dumpScreen(stem)
    local ss = PCSX.GPU.takeScreenShot()
    local f = Support.File.open(string.format('%s-%dx%d-%d.bin', stem, ss.width, ss.height, tonumber(ss.bpp)), 'TRUNCATE')
    f:write(ss.data)
    f:close()
end

-- Pad 1 on port 1: PCSX.SIO0.slots[1].pads[1].setOverride(b) holds button b pressed until clearOverride(b);
-- b = PCSX.CONSTS.PAD.BUTTON.<NAME> (START SELECT CROSS CIRCLE SQUARE TRIANGLE UP DOWN LEFT RIGHT L1 R1 ...).
M.BUTTON = PCSX.CONSTS.PAD.BUTTON
local function pad() return PCSX.SIO0.slots[1].pads[1] end
function M.press(name) pad().setOverride(M.BUTTON[name]) end
function M.release(name) pad().clearOverride(M.BUTTON[name]) end

-- Steps {frame, 'BUTTON', hold}: press at frame, release at frame + hold (default 4). M.mash expands
-- repeated taps: every `every` frames in [from, to). Events apply on the first Vsync at or past their frame.
function M.mash(name, from, to, every, hold)
    local steps = {}
    for f = from, to - 1, every do steps[#steps + 1] = {f, name, hold} end
    return steps
end

function M.padSchedule(steps)
    local ev = {}
    for i, s in ipairs(steps) do
        assert(M.BUTTON[s[2]] ~= nil, 'unknown button ' .. tostring(s[2]))
        ev[#ev + 1] = {f = s[1], press = true, b = s[2], k = 2 * i}
        ev[#ev + 1] = {f = s[1] + (s[3] or 4), press = false, b = s[2], k = 2 * i + 1}
    end
    table.sort(ev, function(x, y) if x.f ~= y.f then return x.f < y.f end return x.k < y.k end)
    local i = 1
    M.onVsync(function(frame)
        while i <= #ev and ev[i].f <= frame do
            if ev[i].press then M.press(ev[i].b) else M.release(ev[i].b) end
            i = i + 1
        end
    end)
end

function M.log(...) print('[mmx6]', ...) end

-- Exit Redux with code (PCSX.quit is deferred to the end of the current chunk).
function M.quit(code)
    M.log('quit', code)
    PCSX.quit(code)
end

return M
