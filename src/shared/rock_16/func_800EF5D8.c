#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800F12A8[][2];
extern s8 D_800F1CEA;

void func_800EF5D8(void* arg0) {
    *(u16*)((u8*)arg0 + 0xA) =
        D_800F12A8[(s8)g_playthrough_state.character_state.bytes[4]][0];
    *(u16*)((u8*)arg0 + 0xE) =
        D_800F12A8[(s8)g_playthrough_state.character_state.bytes[4]][1];
    ((void (*)())func_8002CB50)(arg0);
    if (D_800F1CEA != 2) {
        ((void (*)())clear_object_slot)(arg0);
    }
}
