-- tools/mmx6/redux/smoke.lua -- runtime-oracle smoke + exe load proof input (T4.c1); run: make redux-smoke.
-- Dumps main RAM (2 MiB at 0x80000000) at three distinct moments to .run/redux/smoke/<moment>.bin, with
-- <moment>.json {moment, frame, pc, a0, a1}:
--   binseek1   first Exec hit of BinSeek 0x80016858 (no input: frame 1478)
--   frame4000  GPU::Vsync count == FRAME_N (fixed; between the two hits)
--   binseek2   second BinSeek hit (no input: frame 7787); must come after FRAME_N
-- then PCSX.quit(0). Any failure (error in a callback, wrong order, MAX_FRAME passed) → PCSX.quit(1).
local lib = dofile(os.getenv('MMX6_ROOT') .. '/tools/mmx6/redux/lib.lua')

local BINSEEK = 0x80016858
local FRAME_N = 4000
local MAX_FRAME = 20000
local OUT = lib.root .. '/.run/redux/smoke'
os.execute('mkdir -p "' .. OUT .. '"')

local done = {}
local hits = 0
local finished = false

local function finish(code)
    if finished then return end
    finished = true
    lib.quit(code)
end

local function capture(moment, regs)
    local rec = string.format('{"moment":"%s","frame":%d,"pc":"%s","a0":"%s","a1":"%s"}\n', moment, lib.frame,
                              lib.hex(regs.pc), lib.hex(regs.GPR.n.a0), lib.hex(regs.GPR.n.a1))
    lib.dumpRAM(OUT .. '/' .. moment .. '.bin')
    lib.writeText(OUT .. '/' .. moment .. '.json', rec)
    done[moment] = true
    lib.log('captured', rec)
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

lib.breakpoint(BINSEEK, 'BinSeek', guarded(function(regs)
    hits = hits + 1
    if hits == 1 then
        capture('binseek1', regs)
    elseif hits == 2 then
        if not done.frame4000 then error('second BinSeek hit at frame ' .. lib.frame .. ' before FRAME_N') end
        capture('binseek2', regs)
        finish(0)
    end
end))

lib.onVsync(guarded(function(frame)
    if frame == FRAME_N then
        if not done.binseek1 then error('FRAME_N reached before the first BinSeek hit') end
        capture('frame4000', PCSX.getRegisters())
    elseif frame >= MAX_FRAME then
        error('MAX_FRAME ' .. MAX_FRAME .. ' reached; BinSeek hits ' .. hits)
    end
end))

lib.log('smoke armed: BinSeek', lib.hex(BINSEEK), 'FRAME_N', FRAME_N)
