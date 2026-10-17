#include "common.h"
#define M2C_UNK s32

void func_8001750C(u8, u8);
M2C_UNK func_8002D5D0(void*);
s32 func_8002FE30(void*);
M2C_UNK func_8003CD9C();

#define FLD(o, t) (*(t*)((u8*)arg0 + (o)))

#define TURN(s)                                                                \
    {                                                                          \
        u16 f;                                                                 \
        s32 r;                                                                 \
        func_8001750C(1, 5);                                                   \
        func_8003CD9C(arg0);                                                   \
        f = FLD(0x7C, u16);                                                    \
        s = 0;                                                                 \
        if (f & 3) {                                                           \
            if (f & 2) {                                                       \
                s = 1;                                                         \
                FLD(0x20, s32) = -FLD(0x124, s32);                             \
            } else {                                                           \
                s = 2;                                                         \
                FLD(0x20, s32) = FLD(0x124, s32);                              \
            }                                                                  \
            func_8002D5D0(arg0);                                               \
            r = (u8)(func_8002FE30(arg0) - 0x25) >= 0xB;                       \
            FLD(0x8, s32) = FLD(0x18, s32);                                    \
            if (r) {                                                           \
                s = 0;                                                         \
            } else {                                                           \
                func_8002D5D0(arg0);                                           \
            }                                                                  \
        }                                                                      \
    }

s32 func_80038594(void* arg0) {
    s32 c;
    register s32 m asm("$4");
    s32 s;
    s32 w;
    s32 r;
    u16 f;
    s32 t;

    t = --FLD(0x85, s8);
    if (t == 0) {
        c = 1;
    } else {
        f = FLD(0x7C, u16);
        if (!(f & 0x103)) {
            c = 1;
        } else {
            m = 1;
            if (FLD(0x15, u8) != 0) {
                m = 2;
            }
            c = (f & m) != 0;
        }
    }
    if (c) {
        TURN(s);
        return s;
    }
    w = 2;
    if (FLD(0x15, u8) == 0) {
        w = 1;
        FLD(0x20, s32) = -FLD(0x12C, s32);
    } else {
        FLD(0x20, s32) = FLD(0x12C, s32);
    }
    func_8002D5D0(arg0);
    r = (u8)(func_8002FE30(arg0) - 0x25) >= 0xB;
    FLD(0x8, s32) = FLD(0x18, s32);
    if (r) {
        w = 0;
    } else {
        func_8002D5D0(arg0);
    }
    if (w == 0) {
        TURN(s);
        return s;
    }
    return w;
}
