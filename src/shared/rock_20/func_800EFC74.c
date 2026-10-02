/* Adapted from sozud/mmx4 @29b62af src/main/menu.c:func_8001C5A8, AGPL-3.0; proven shared with X6 by exact signature e4a5fdbaa049 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800F3C00[32];
extern struct X4_MenuTextureData D_800F3C20;

void func_800EFC74(u8** arg0) {
    __builtin_memcpy(*arg0 + 0x60, D_800F3C00, 0x20);
    __builtin_memcpy(*arg0 + 0x80, D_800F3C20.texture, 0x180);
}
