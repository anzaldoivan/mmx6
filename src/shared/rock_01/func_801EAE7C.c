#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002D2D4();
s32 func_80039C40(void*);
s32 func_80039C9C(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CD9C();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
s32 func_801EB12C(void*);
M2C_UNK func_801EC95C(void*);
s32 func_801ECCD4(void*);
M2C_UNK func_801ECD3C(void*);
M2C_UNK func_801ECD54(void*, M2C_UNK);
M2C_UNK func_801ECD90(void*, M2C_UNK);
s32 func_801ECE08(void*);
void func_801ECE60(void* arg0);
void func_801EAE7C(void* arg0);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_801EA680(u8* arg0);
static inline s32 func_801EAE7C_try_a(void* arg0) {
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
    F_U8(arg0, 5) = 0x37;
    F_U8(arg0, 6) = 0;
    func_801ECD3C(arg0);
    func_801EC95C(arg0);
    return 1;
}

static inline s32 func_801EAE7C_try_b(void* arg0) {
    if (F_S8(arg0, 0xD3) == 0) {
        F_U8(arg0, 0xDD) = 1;
        if (((s32(*)())func_801EA680)(arg0) != 0) {
            return 1;
        }
        F_U8(arg0, 0xDD) = 0;
    }
    return 0;
}

static inline s32 func_801EAE7C_try_c(void* arg0) {
    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    func_8003BA04(arg0, 0x58);
    func_80016C48(1, 7, arg0);
    if (func_8002D2D4() & 4) {
        func_8003CFE0(arg0, 3);
    }
    F_U8(arg0, 0x84) = 0;
    F_U8(arg0, 0x86) = 0;
    F_U8(arg0, 5) = 0x30;
    F_U8(arg0, 6) = 0;
    func_801EAE7C(arg0);
    return 1;
}

void func_801EAE7C(void* arg0) {
    if (F_S8(arg0, 6) == 0) {
        F_S8(arg0, 6)++;
    } else {
        func_80017A04(arg0);
        if (F_U8(arg0, 0x17) == 0x5C) {
            func_801ECD54(arg0, 0x1C);
        } else {
            func_801ECD54(arg0, 0x18);
        }
        if (!(F_U8(arg0, 0x45) & 1) && F_S8(arg0, 0xCB) < 2 &&
            func_801EAE7C_try_a(arg0)) {
            return;
        }
        if (func_801EB12C(arg0) != 0) {
            return;
        }
    }
    if (F_S8(arg0, 0xD3) == 0) {
        F_U8(arg0, 0x8E) = 0;
        if (!(F_U8(arg0, 0x45) & 1)) {
            if (func_80039C40(arg0) != 0) {
                return;
            }
            if (F_S8(arg0, 0xCB) < 2) {
                if (func_80039C9C(arg0) != 0) {
                    return;
                }
                if (F_U8(arg0, 0x45) & 0x40) {
                    if (func_801EAE7C_try_b(arg0)) {
                        return;
                    }
                    if (func_801EAE7C_try_c(arg0)) {
                        return;
                    }
                    if (func_801ECE08(arg0) != 0) {
                        return;
                    }
                }
            }
        }
        F_U8(arg0, 0x8E) = 1;
    }
    func_801ECE60(arg0);
}

#undef F_S8
#undef F_U8
#undef F_U16
