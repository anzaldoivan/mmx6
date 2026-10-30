#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CFE0(void*, M2C_UNK);
M2C_UNK func_801EC440(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_801EA34C(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (!(F_U8(arg0, 0xC9) & 8)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x7C) & 8)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x80) & 0x10)) {
        return 0;
    }
    if (F_S8(arg0, 0x8E) != 0) {
        return 0;
    }
    F_U8(arg0, 0xDD) = 1;
    F_U8(arg0, 0x8E) = 1;
    F_U8(arg0, 0xCB) = 0;
    F_U8(arg0, 0x8C) = 0;
    func_8003BA04(arg0, 0x62);
    func_8003CFE0(arg0, 5);
    play_sound(1, 0x17, arg0);
    if (F_U16(arg0, 0x7C) & 2) {
        F_U8(arg0, 0x15) = 0;
    }
    if (F_U16(arg0, 0x7C) & 1) {
        F_U8(arg0, 0x15) = 0x40;
    }
    F_U8(arg0, 0x93) = 2;
    F_U8(arg0, 0x5) = 0x38;
    F_U8(arg0, 0x6) = 0;
    func_801EC440(arg0);
    return 1;
}
