#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002C9B0();
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCEF6;

void func_800E9D78(void* arg0) {
    if (D_800CCEF6 != 0) {
        u8* pl = (u8*)&D_800970A0;
        *(s32*)(pl + 0xF4) -= 0x8000;
        func_8002C9B0();
        return;
    }
    if (D_800971F8[0].x_pos.i.hi < *(s16*)((u8*)arg0 + 0x14)) {
        D_800971F8[0].x_pos.val += 0x8000;
        D_800971F8[0].unk1C = D_800971F8[0].x_pos.i.hi;
        D_800971F8[0].unk1E = D_800971F8[0].x_pos.i.hi;
        D_800971F8[0].unk24 = D_800971F8[0].x_pos.i.hi;
        D_800971F8[0].unk26 = D_800971F8[0].x_pos.i.hi;
    }
}
