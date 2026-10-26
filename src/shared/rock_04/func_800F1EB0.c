#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002D2D4();

void func_800F1EB0(void* arg0) {
    s32 r;
    // !FAKE: depin: dropping it breaks the match (74/76)
    register s32 v asm("$2");
    s32 ang;
    s32 m;

    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        func_80016C48(2, 0x11, arg0);
        r = (u32)func_8002D2D4() % 3 & 0xFF;
        switch (r) {
        case 0:
            func_80016C48(2, 0x22, arg0);
            break;
        case 1:
            func_80016C48(2, 0x23, arg0);
            break;
        case 2:
            func_80016C48(2, 0x24, arg0);
            break;
        }
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            v = rcos(0x71D);
            ang = 0x71D;
        } else {
            v = rcos(0xE3);
            ang = 0xE3;
        }
        m = v * 0x10;
        v = m * 2 + m;
        M2C_FIELD(arg0, s32*, 0x20) = v * 2;
        v = rsin(ang);
        m = v * 0x10;
        v = m * 2 + m;
        v = v * 2;
        M2C_FIELD(arg0, s32*, 0x24) = v;
        v = M2C_FIELD(arg0, u8*, 0x6);
        M2C_FIELD(arg0, u8*, 0x6) = v + 1;
    }
}
