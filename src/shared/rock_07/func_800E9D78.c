#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEF6;

void func_800E9D78(void* arg0) {
    if (D_800CCEF6 != 0) {
        u8* pl = (u8*)&g_Player;
        *(s32*)(pl + 0xF4) -= 0x8000;
        clear_object_slot();
        return;
    }
    if (background_objects[0].x_pos.i.hi < *(s16*)((u8*)arg0 + 0x14)) {
        background_objects[0].x_pos.val += 0x8000;
        background_objects[0].unk1C = background_objects[0].x_pos.i.hi;
        background_objects[0].unk1E = background_objects[0].x_pos.i.hi;
        background_objects[0].unk24 = background_objects[0].x_pos.i.hi;
        background_objects[0].unk26 = background_objects[0].x_pos.i.hi;
    }
}
