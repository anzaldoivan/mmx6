#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_80071EE0[];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 g_tilemap_width;
extern u8 g_tilemap_height;
extern M2C_UNK D_800CD3F0;
#define D_800CD3F0 (*(u8(*)[4]) & D_800CD3F0)

void func_800280F4(void) {
    struct X4_BackgroundObj* bg;
    u32 i;
    u8* p;

    bg = background_objects;
    i = 0;
    do {
        bg->unk0 = 1;
        bg->unk3 = 1;
        bg->unk44 = 1;
        bg->pad52[0] = -1;
        bg->unk4D = 0;
        bg->min_y = 0;
        bg->unk4E = g_tilemap_width - 1;
        bg->max_y = g_tilemap_height - 1;
        bg++;
        i++;
    } while (i < 3);
    p = &D_80071EE0[g_playthrough_state.stage * 20 +
                    g_playthrough_state.substage * 10];
    D_800CD3F0[0] = *p++;
    D_800CD3F0[1] = *p++;
    D_800CD3F0[2] = *p++;
    D_800CD3F0[3] = *p++;
    background_objects[0].unk4B = *p++;
    background_objects[0].unk4A = *p++;
    background_objects[1].unk4B = *p++;
    background_objects[1].unk4A = *p++;
    background_objects[2].unk4B = *p++;
    background_objects[2].unk4A = *p++;
}
#undef D_800CD3F0
