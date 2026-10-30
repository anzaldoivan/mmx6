#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003C4EC(struct X4_PlayerObj* self);
M2C_UNK func_8003CD9C();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_801EC504(void* arg0);
M2C_UNK func_801ECD90();

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_801EA560(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0 || F_S8(arg0, 0x86) == 8 ||
        !(F_U8(arg0, 0xC9) & 0x20) || !(F_U16(arg0, 0x7C) & 8) ||
        !(F_U16(arg0, 0x80) & 0x20)) {
        return 0;
    }
    if (F_S8(arg0, 0x8E) != 0) {
        return 0;
    }
    F_S8(arg0, 0xDD) = 1;
    F_S8(arg0, 0x8E) = 1;
    F_S8(arg0, 0xCB) = 0;
    F_S8(arg0, 0x8C) = 0;
    func_8003CD9C(arg0);
    func_8003BA04(arg0, 0x67);
    func_801ECD90(arg0, 0x2A);
    func_8003CFE0(arg0, 5);
    play_sound(1, 0x18, arg0);
    F_S8(arg0, 0x61) = 0;
    F_S8(arg0, 0xA4) = 0;
    func_8003C4EC(arg0);
    F_S8(arg0, 0x7A) = 1;
    F_S8(arg0, 0x5) = 0x3A;
    F_S8(arg0, 0x6) = 0;
    F_S8(arg0, 0x86) = 8;
    func_801EC504(arg0);
    return 1;
}
