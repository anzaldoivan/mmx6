#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
extern M2C_UNK D_8007433C;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800CCF5C;
extern u8 D_800FB810[];

#define SPAD (*(u8**)0x1F80004C)

void func_800F2584(void* arg0) {
    s8 st;
    u32 r;
    u8* p;

    r = func_8002D2D4() & 0xF;
    st = M2C_FIELD(arg0, s8*, 2);
    if (st == 0) {
        if (r < 2) {
            SPAD[0x84] = 0;
        } else if (r < 7) {
            SPAD[0x84] = 2;
        } else {
            SPAD[0x84] = 3;
        }
    } else if (st == 1) {
        u8* e = (u8*)&D_800CCED0;
        if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)((s8)e[0x8C] / 3) * 2) {
            if (r < 8) {
                SPAD[0x84] = 4;
            } else {
                SPAD[0x84] = 6;
            }
        } else if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)((s8)e[0x8C] / 3)) {
            if (r < 5) {
                SPAD[0x84] = 4;
            } else if (r < 0xB) {
                SPAD[0x84] = 5;
            } else {
                SPAD[0x84] = 6;
            }
        } else {
            goto dead;
        }
        {
            u8* e2 = (u8*)&D_800CCED0;
            if (M2C_FIELD(arg0, s8*, 0x5C) < (s8)((s8)e2[0x8C] / 3)) {
            dead:
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                SPAD[0x8B] = 0x3C;
                M2C_FIELD(arg0, u8*, 5) = 0xC;
                M2C_FIELD(arg0, u8*, 6) = 0;
                return;
            }
        }
    } else if (st == 2) {
        if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)((s8)D_800CCF5C / 3) * 2) {
            if (r < 5) {
                SPAD[0x84] = 7;
            } else if (r < 0xA) {
                SPAD[0x84] = 8;
            } else {
                SPAD[0x84] = 9;
            }
        } else if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)((s8)D_800CCF5C / 3)) {
            if (r < 3) {
                SPAD[0x84] = 8;
            } else if (r < 7) {
                SPAD[0x84] = 0xA;
            } else if (r < 0xC) {
                SPAD[0x84] = 0xB;
            } else {
                SPAD[0x84] = 0xC;
            }
        }
    }
    SPAD[0x85] = 0;
    p = SPAD;
    M2C_FIELD(arg0, u8*, 5) = D_800FB810[(p[0x85] & 3) + p[0x84] * 4];
    M2C_FIELD(arg0, u8*, 6) = 0;
}
