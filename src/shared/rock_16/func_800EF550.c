#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F1520[][2];

void func_800EF550(void* arg0) {
    u16 v;

    v = D_800F1520[*(s8*)((u8*)arg0 + 2)][0];
    *(u16*)((u8*)arg0 + 0xA) = v;
    *(u16*)((u8*)arg0 + 0xE) = D_800F1520[*(s8*)((u8*)arg0 + 2)][1];
    if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi >= 0x401) {
        *(u16*)((u8*)arg0 + 0xA) = v + 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
}
