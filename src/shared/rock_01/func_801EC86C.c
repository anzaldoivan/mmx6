#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CD9C();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
M2C_UNK func_801EC95C(void*);
M2C_UNK func_801ECD3C(void*);
M2C_UNK func_801ECD90(void*, M2C_UNK);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_801EC86C(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (!(F_U8(arg0, 0xC9) & 4)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x7C) & 4)) {
        return 0;
    }
    if (!(F_U16(arg0, 0x80) & 0x10)) {
        return 0;
    }
    F_U8(arg0, 0x8E) = 1;
    func_8003BA04(arg0, 0x5A);
    func_801ECD90(arg0, 0x1A);
    func_801ECD90(arg0, 0x22);
    func_80016C48(1, 7, arg0);
    func_80016C48(1, 0x16, arg0);
    func_8003CFE0(arg0, 5);
    func_8003CD9C(arg0);
    F_U8(arg0, 0x5) = 0x37;
    F_U8(arg0, 0x6) = 0;
    func_801ECD3C(arg0);
    func_801EC95C(arg0);
    return 1;
}

#undef F_S8
#undef F_U8
#undef F_U16
