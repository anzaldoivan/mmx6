#include "common.h"
#include "mmx6/x4.h"
extern u16* D_800A21B0;

void func_80017F24(void) {
    u16* src = SP_BG_TILE_PIXELS;
    u16* dst = D_800A21B0;
    s32 count = (u32)((u8*)SP_BG_TILE_ATTRS - (u8*)src) >> 1;

    while (count > 0) {
        *dst++ = *src++;
        count--;
    }
}
