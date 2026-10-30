#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80012D9C(s32);
s32 play_sound(s32 a0, s32 a1, void* arg2);
s32 random_byte();
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CCBC();
M2C_UNK func_8003CDBC();
void func_8003CE30(void* arg0);
extern u8 D_80073C70[];
extern s32 D_80073C78[][4];
extern u8 D_80073CD8[];
extern u8 D_800CCF2F;

void func_8003963C(void* arg0) {
    s32 i;
    s32 f;

    ((void (*)())func_8003CCBC)();
    M2C_FIELD(arg0, u8*, 0x5C) = M2C_FIELD(arg0, u8*, 0x5C) & 0x7F;
    func_80012D9C(1);
    play_sound(3, (random_byte() & 1) ^ 1, arg0);
    play_sound(3, 0x11, arg0);
    if (M2C_FIELD(arg0, s8*, 5) != 0x11) {
        s32 one = 1;
        M2C_FIELD(arg0, s8*, 0xA4) = one;
        M2C_FIELD(arg0, s8*, 0xCF) = one;
        M2C_FIELD(arg0, s8*, 0x84) = 0;
        M2C_FIELD(arg0, s8*, 0x8C) = 0;
        func_8003CDBC(arg0);
        func_8003CE30(arg0);
        i = M2C_FIELD(arg0, s8*, 0x63);
        M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0xA5);
        ((void (*)(void*, s32))func_8003BA04)(arg0, D_80073C70[i]);
        M2C_FIELD(arg0, s32*, 0x20) = D_80073C78[i][0];
        M2C_FIELD(arg0, s32*, 0x28) = D_80073C78[i][1];
        f = 0;
        M2C_FIELD(arg0, s32*, 0x24) = D_80073C78[i][2];
        M2C_FIELD(arg0, s32*, 0x2C) = D_80073C78[i][3];
        if ((M2C_FIELD(arg0, s32*, 0xEC) & 0x200) ||
            (M2C_FIELD(arg0, s8*, 2) != 0 && (D_800CCF2F & 0x20))) {
            f = 1;
        }
        if (f != 0 && ((u32)(i - 1) < 2U || i == 4)) {
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
        }
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
        }
        M2C_FIELD(arg0, u8*, 0x61) = D_80073CD8[i];
        if ((u32)(i - 2) < 2U || i == 5) {
            M2C_FIELD(arg0, s8*, 0x67) = 1;
        }
        M2C_FIELD(arg0, s8*, 5) = 0x11;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
