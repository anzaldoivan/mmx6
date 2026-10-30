#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 select_air_dash(void*);
s32 func_80039984(void*);
s32 func_8003A2CC(void*);
s32 func_8003A488(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);
void func_8003D18C(void* arg0);
void func_8003D394(void* arg0);
s32 func_801ECCD4(void*);
M2C_UNK func_801ECD54(void*, M2C_UNK);
void func_801EB324(s8* p);

#define U8(o) (((u8*)p)[o])
#define U16(o) (*(u16*)((u8*)p + (o)))
#define S32(o) (*(s32*)((u8*)p + (o)))

static inline s32 try_switch_801EB324(s8* p) {
    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    if (p[0x86] == 6) {
        func_8003BA04(p, 0x60);
        play_sound(1, 7, p);
        p[5] = 0x35;
    } else {
        func_8003BA04(p, 0x5B);
        play_sound(1, 8, p);
        p[5] = 0x31;
    }
    p[6] = 0;
    func_801EB324(p);
    return 1;
}

void func_801EB324(s8* p) {
    s8 saved;

    if (func_80039984(p) != 0) {
        return;
    }
    if (p[6] == 0) {
        U8(6)++;
    } else {
        func_80017A04(p);
        if (p[5] == 0x35) {
            func_801ECD54(p, 0x1D);
        }
        if (p[5] == 0x31) {
            func_801ECD54(p, 0x1B);
        }
    }
    if (p[0xD3] != 0) {
        S32(0x24) = 0;
    }
    if (U8(0x89) & 4) {
        S32(0x24) = 0;
    }
    if (!(U16(0x7C) & 0x80)) {
        S32(0x24) = 0;
    }
    if (p[0x8E] != 0 && p[0x46] == 0) {
        p[0x8E] = 0;
    }
    if (try_switch_801EB324(p) != 0) {
        return;
    }
    saved = p[0x8E];
    p[0x8E] = 0;
    if (U8(0x45) & 0x40) {
        if (try_switch_801EB324(p) != 0) {
            return;
        }
    }
    if (p[0x8B] == 0) {
        if (func_8003A488(p) != 0) {
            return;
        }
        if (func_8003A2CC(p) != 0) {
            return;
        }
        if (select_air_dash(p) != 0) {
            return;
        }
    } else {
        U8(0x8B)--;
    }
    p[0x8E] = saved;
    func_8003D18C(p);
    func_8003D394(p);
    if (S32(0x24) <= 0) {
        if (p[0x8E] != 0) {
            if (p[5] == 0x31) {
                p[5] = 0x32;
            } else {
                p[5] = 0x36;
            }
            p[6] = 1;
        } else {
            ((void (*)(void*, s32, s8))func_8003BB94)(p, 0xB, 5);
            p[0x8A] = 0;
            p[5] = 7;
            p[6] = 0;
        }
        p[0x67] = -1;
    }
}

#undef U8
#undef U16
#undef S32
