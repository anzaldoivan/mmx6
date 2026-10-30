#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_80090C98;
extern s8 D_80097244;
extern u8 D_800C4560;
extern u8 D_800F6EF8[];
extern u8 D_800F6F00[];

void func_800F356C(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x79) {
        func_80027BA0(0, 0xDA0, 0xD0, D_800F6EF8);
        func_80027BA0(0, 0xD80, 0x150, D_800F6F00);
        D_80097244 = 1;
        D_80090C98 = -1;
        D_800C4560 |= 1;
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        play_sound(0, 4, arg0);
        M2C_FIELD(arg0, u16*, 0x7E) = 0x32;
        func_80029478((s8)M2C_FIELD(arg0, u16*, 0x7E), 8, 1);
        func_80012D9C(3);
    }
}
