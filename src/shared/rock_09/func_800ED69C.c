#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
void func_800ED18C(s32 arg0, s32 arg1, u8* arg2);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEF6;
extern s32 D_800F6BA4;
extern s16 D_800F6BC4[16];

void func_800ED69C(u8* arg0) {
    u8* bg;

    if (D_800CCEF6 != 0) {
        bg = (u8*)background_objects;
        *(u16*)(arg0 + 0x14) = 0;
        *(u16*)(arg0 + 0x16) = 0;
        *(u16*)(arg0 + 0x18) = 0;
        *(s16*)(bg + 0x5E) = 0;
        *(s16*)(bg + 0x62) = 0;
        bg[0xA0] = 1;
        *(u16*)(arg0 + 0x1E) = 1;
        *(u16*)(arg0 + 0x1A) = 0;
        func_8002B410((s32*)D_800F6BC4, &D_800F6BA4, 0x10, 0x1E, 0x1E);
        load_palette(0x63, (s32*)D_800F6BC4, 1);
        func_800ED18C(0x1E - *(u16*)(arg0 + 0x1A), 0x1E, arg0);
        play_sound(5, 4, 0);
        arg0[4]++;
    }
}
