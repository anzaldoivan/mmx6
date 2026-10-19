#include "common.h"
#include "mmx6/x4.h"

s32 func_80030234(struct X4_PlayerObj*, s16, s16);

s32 func_800FA630(void* arg0, s16 x, s16 y) {
    return (func_80030234(arg0, x, y) & 0xFF) == 0x2D;
}
