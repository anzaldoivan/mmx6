#include "common.h"

#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 check_enemy_hits(void*);
s32 func_800EFAEC(u8* arg0);
extern s32 D_8007451C;
extern s32 D_800745BC;
extern s32 D_800FBCAC[];
extern u8 D_800FBEA4[][8][4];
extern void (*D_800FC28C[])(u8*);

void func_800EF5B8(u8* arg0) {

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    func_80017A04();
    D_800FC28C[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    func_8002CCB0(arg0, 0x10, 0x10);
    M2C_FIELD(arg0, u8*, 0x5C) = 0x7F;
    if (check_enemy_hits(arg0) != 0) {
        M2C_FIELD(arg0, u8*, 0x8B) = 0x21;
        M2C_FIELD(arg0, s32**, 0x58) = &D_800745BC;
        if ((M2C_FIELD(arg0, s8*, 0x2) & 0xF0) == 0x40) {
            if (M2C_FIELD(arg0, u8*, 0x89) == 1) {
                M2C_FIELD(arg0, u8*, 0x8C) = M2C_FIELD(arg0, u8*, 0x89);
                M2C_FIELD(arg0, u8*, 0x89) = 0;
            }
            play_sound(2, 0x4E, arg0);
            M2C_FIELD(arg0, u8*, 0x87) = (M2C_FIELD(arg0, u8*, 0x87) + 1) & 7;
            M2C_FIELD(arg0, u8*, 0x88) =
                D_800FBEA4[M2C_FIELD(arg0, u8*, 0x2) & 0xF]
                          [M2C_FIELD(arg0, u8*, 0x87)][0];
            M2C_FIELD(arg0, s32**, 0x54) =
                &D_800FBCAC[M2C_FIELD(arg0, u8*, 0x88)];
            set_animation(arg0, M2C_FIELD(arg0, u8*, 0x88) + 0x10);
        }
    }
    if (func_800EFAEC(arg0) != 0) {
        if (M2C_FIELD(arg0, u8*, 0x89) == 0) {
            M2C_FIELD(arg0, u8*, 0x8C) = 1;
        }
    } else {
        M2C_FIELD(arg0, u8*, 0x89) = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x8B) != 0) {
        if (--M2C_FIELD(arg0, u8*, 0x8B) == 0) {
            M2C_FIELD(arg0, s32**, 0x58) = &D_8007451C;
        }
    }
}
