#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80040498();
M2C_UNK func_800F82C0();
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FBC7C;
#define D_800FBC7C (*(u8*)&D_800FBC7C)

void func_800F5420(void* arg0) {
    ((void (*)())func_800F82C0)();
    if (func_80040498() == 0) {
        if (((s8*)arg0)[2] == 0) {
            background_objects[0].unk24 = 0x1800;
            background_objects[0].unk26 = 0x17B0;
        }
        *(s16*)((u8*)arg0 + 0x7C) = 2;
        ((u8*)arg0)[6] += 1;
        background_objects[0].unk48 = D_800FBC7C;
    }
}
#undef D_800FBC7C
