#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800FA418(void*);

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F7BE4(void* arg0) {
    s16 a;
    s16 b;
    s16 e;
    s16 q;
    s32 n;
    s16 x;
    s16 i;
    s16 r;
    s16 m;

    a = M2C_FIELD(arg0, s16*, 0xA);
    b = M2C_FIELD(arg0, s16*, 0x8);
    e = M2C_FIELD(arg0, s16*, 0xE);
    if (ABS(b - a) < 5) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        return;
    }
    q = ABS(a - b) / 48;
    m = ABS(a - b) % 48;
    {
        // !FAKE: depin: dropping it breaks the match (64/149)
        register s32 v asm("$2");
        if (m != 0) {
            v = q;
        } else {
            v = q - 1;
        }
        n = (s8)v;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        x = a - 0x18;
    } else {
        x = a + 0x18;
    }
    for (i = 0; i < n; i++) {
        M2C_FIELD(arg0, s16*, 0xA) = x;
        M2C_FIELD(arg0, s16*, 0xE) = e;
        func_800FA418(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            x = x - 0x30;
        } else {
            x = x + 0x30;
        }
    }
    M2C_FIELD(arg0, s16*, 0xA) = x;
    M2C_FIELD(arg0, s16*, 0xE) = e;
    r = ABS(a - b) - n * 48;
    r = r / 4 - 1;
    M2C_FIELD(arg0, s8*, 0x47) = r - 0x65;
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    func_8002CCB0(arg0, 0x80, 0x80);
}
