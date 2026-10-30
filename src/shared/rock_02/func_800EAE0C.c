#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void* func_8002C458();
extern s16 D_800970AA;
extern u8 D_800CCF38;

void func_800EAE0C(void* arg0) {
    s32 d;
    void* child;

    d = M2C_FIELD(arg0, s16*, 0xA) - D_800970AA;
    if (d >= 0) {
        if (d >= 0x71) {
            goto far;
        }
    } else if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) >= 0x71) {
    far:
        M2C_FIELD(arg0, s16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 5) = 1;
        set_animation(arg0, 0);
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            set_animation(arg0, 1);
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        if (D_800CCF38 >= 2) {
            play_sound(2, 0x21, arg0);
        } else {
            play_sound(2, 0x1A, arg0);
        }
        child = func_8002C458();
        if (child != 0) {
            M2C_FIELD(child, u8*, 0) = 0x41;
            M2C_FIELD(child, u8*, 1) = 0;
            M2C_FIELD(child, u8*, 2) = 0;
            M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(child, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(child, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(child, u8*, 4) = 0;
            M2C_FIELD(child, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
    func_80017A04(arg0);
}
