-- tools/mmx6/redux/lib.lua -- helpers for repo Lua scripts run by tools/mmx6/redux/run.sh (PCSX-Redux).
-- Load with: local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')
-- API names per the Lua sources embedded in the Redux binary (core/pcsxffi.lua, the event-name list):
-- PCSX.addBreakpoint(addr, 'Exec', 4, cause, invoker(address, width, cause)), PCSX.getRegisters().GPR.n.a0,
-- PCSX.Events.createEventListener('GPU::Vsync', fn), Support.File.open(path, 'TRUNCATE'):write(ptr, size).
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

function M.log(...) print('[mmx6]', ...) end

-- Exit Redux with code (PCSX.quit is deferred to the end of the current chunk).
function M.quit(code)
    M.log('quit', code)
    PCSX.quit(code)
end

return M
