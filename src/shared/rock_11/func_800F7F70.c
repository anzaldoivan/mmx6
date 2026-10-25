#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C3F8();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s8* D_800FDA74;

void func_800F7F70(void* arg0) {
    void* p;
    s8 t;
    s16 h;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        p = func_8002C3F8();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0x0) = 1;
            M2C_FIELD(p, u8*, 0x1) = 0x1A;
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
            M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            D_800FDA74 = p;
        }
    }
    func_8002CCB0(arg0, 0x60, 0x60);
    {
        // !FAKE: depin: dropping it breaks the match (54/61)
        register s32 q asm("$2");
        q = M2C_FIELD(arg0, u16*, 0x7E) - 1;
        M2C_FIELD(arg0, s16*, 0x7E) = q;
        h = q;
    }
    if (h == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        M2C_FIELD(arg0, s8*, 0x61) -= 5;
        if (M2C_FIELD(arg0, s8*, 0x61) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        t = M2C_FIELD(arg0, s8*, 0x61);
        {
            // !FAKE: depin: dropping it breaks the match (53/61)
            register s32 m asm("$2");
            if (t >= 6) {
                m = t;
                M2C_FIELD(arg0, s16*, 0x7E) = m;
            } else {
                m = 5;
                M2C_FIELD(arg0, s16*, 0x7E) = m;
            }
        }
    }
}
