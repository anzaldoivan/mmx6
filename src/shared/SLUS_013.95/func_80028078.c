#include "common.h"

extern u16 g_tilemap_layer_stride;
extern u8 g_tilemap_width;
extern u8 g_tilemap_height;

#define SCRATCH_04 (*(u8**)0x1F800004)

s32 func_80028078(s32 arg0, s32 arg1, u32 arg2) {
    u32 x = arg1;

    if ((x >= g_tilemap_width) || (arg2 >= g_tilemap_height)) {
        return 0;
    }
    return *(SCRATCH_04 + (arg0 * g_tilemap_layer_stride) + (g_tilemap_width * arg2) + x);
}
