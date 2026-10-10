#include "common.h"

extern u8 D_800CCF36;

s32 func_8002CEF0(void) {
    return ((u8)D_800CCF36 >= 3U) * 2;
}
