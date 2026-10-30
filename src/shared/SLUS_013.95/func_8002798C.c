#include "common.h"
#include "mmx6/x4.h"

extern u8* D_800762E0[][2];
extern u16 g_tilemap_layer_stride;
extern struct X4_EngineObj g_playthrough_state;
extern u8* D_800EA514[];

void func_800268B0(s32 arg0);

#define SCRATCH_04 (*(u8**)0x1F800004)

void func_8002798C(void) {
    u8* src;
    u8* dst;
    u32 i;

    if (g_playthrough_state.stage == 0xB) {
        src = D_800EA514[g_playthrough_state.checkpoint];
    } else {
        src =
            D_800762E0[g_playthrough_state.stage][g_playthrough_state.substage];
    }
    i = 0;
    dst = SCRATCH_04;
    if (g_tilemap_layer_stride * 3 != 0) {
        do {
            *dst = *src;
            src++;
            i++;
            dst++;
        } while (i < (u32)(g_tilemap_layer_stride * 3));
    }
    func_800268B0(-1);
}
