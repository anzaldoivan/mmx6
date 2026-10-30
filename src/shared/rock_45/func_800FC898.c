#include "common.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
extern s32 D_800FCA84;

void func_800FC898(s32 arg0) {
    u8* p = *(u8**)((u8*)&D_800FCA84 + 0x3DC);

    p[7]--;
    clear_object_slot(arg0, p);
}
