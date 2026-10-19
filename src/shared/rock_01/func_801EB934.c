#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002D2D4();
s32 func_8003A5D8();
M2C_UNK func_8003B7B4(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);
M2C_UNK func_8003CFE0(void*, M2C_UNK);
s32 func_801ECCD4(void*);
void func_801EB934(s8* p);

#define U8(o) (((u8*)p)[o])
#define U16(o) (*(u16*)((u8*)p + (o)))

M2C_UNK func_801ECD54(void*, M2C_UNK);
static inline s32 try_fall_801EB934(s8* p) {
    if (func_801ECCD4(p) == 0) {
        return 0;
    }
    func_8003BA04(p, 0x5D);
    func_80016C48(1, 7, p);
    if (func_8002D2D4() & 4) {
        func_8003CFE0(p, 8);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[5] = 0x33;
    p[6] = 0;
    func_801EB934(p);
    return 1;
}

void func_801EB934(s8* p) {
    if (func_8003A5D8(p) != 0) {
        p[0x8E] = 0;
        return;
    }
    if (p[6] == 0) {
        p[6]++;
    } else {
        func_80017A04(p);
    }
    ((void (*)())func_801ECD54)(p, 0x1E);
    if (U8(0x45) & 0x40) {
        p[0x8E] = 0;
        if (try_fall_801EB934(p) != 0) {
            return;
        }
        p[0x8E] = 1;
    }
    if (U16(0x80) & 2) {
        p[0x15] = 0;
    }
    if (U16(0x80) & 1) {
        p[0x15] = 0x40;
    }
    if (p[0x46] == 0) {
        p[0x8E] = 0;
        func_8003BB94(p, 0x1F, 2);
        func_8003B7B4(p);
    }
}
