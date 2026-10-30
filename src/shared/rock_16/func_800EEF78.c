#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F1328[][2];
extern s8 D_800F1CE0[][5];

void func_800EEF78(void* arg0) {
    u16 v;

    set_animation_frame(arg0, 6,
                  D_800F1CE0[g_playthrough_state.character_state.bytes[3]]
                            [*(s8*)((u8*)arg0 + 2)]);
    *(u16*)((u8*)arg0 + 0xA) = D_800F1328[*(s8*)((u8*)arg0 + 2)][0];
    v = D_800F1328[*(s8*)((u8*)arg0 + 2)][1];
    *(u16*)((u8*)arg0 + 0xE) = v;
    if (g_playthrough_state.character_state.bytes[3] != 0) {
        *(u16*)((u8*)arg0 + 0xE) = v + 0x2B;
    }
    if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi > 0x400) {
        *(u16*)((u8*)arg0 + 0xA) += 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
}
