#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
s32 func_800EC1FC(s32);
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F12A8[][2];

void func_800EEDA0(void* arg0) {
    s8 t;
    u16 v;

    t = *(s8*)((u8*)arg0 + 2);
    if (t >= 0x18) {
        func_800179D0(arg0, 0, t);
    } else if (func_800EC1FC(t) != 0) {
        func_800179D0(arg0, 1, *(s8*)((u8*)arg0 + 2));
    } else {
        func_800179D0(arg0, 0, *(s8*)((u8*)arg0 + 2));
    }
    v = D_800F12A8[*(s8*)((u8*)arg0 + 2)][0];
    *(u16*)((u8*)arg0 + 0xA) = v;
    *(u16*)((u8*)arg0 + 0xE) = D_800F12A8[*(s8*)((u8*)arg0 + 2)][1];
    if (background_objects[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi >= 0x400) {
        *(u16*)((u8*)arg0 + 0xA) = v + 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
}
