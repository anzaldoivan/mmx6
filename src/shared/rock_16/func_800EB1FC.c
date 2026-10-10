#include "common.h"
#define M2C_UNK s32

void func_8001D218();
M2C_UNK func_8002B838();
s32 func_80042F50(s32, s32);
void func_80042F7C(s8 arg0, s8* arg1, s8* arg2);
M2C_UNK func_80066150(M2C_UNK);
M2C_UNK func_800663FC(M2C_UNK*, M2C_UNK*);

extern s8 D_80097424;
extern M2C_UNK* D_800B91B8;
extern M2C_UNK D_800F0EE4;
extern s8 D_800F0F14[];

static inline void clr(s8* base, s32 idx) {
    s32 i;
    for (i = 0; i < 32; i++) {
        base[idx * 32 + i] = 0;
    }
}

#define A(n) clr(self + 0x178, func_80042F50((n), 0))
#define C(n) clr(self + 0x178, func_80042F50((n), 1))

static inline void pair(s8* self, s32 n) {
    s8 x;
    s8 y;
    func_80042F7C(n, &x, &y);
    clr(self + 0x178, func_80042F50(x, y));
}
#define B(n) pair(self, (n))

void func_800EB1FC(s8* self) {
    s32 i;
    s8* p;
    s32 idx;
    s8* q;
    s8* r;
    s8 x;
    s8 y;
    s8 v;

    if (D_80097424 == 0) {
        func_800663FC(&D_800F0EE4, D_800B91B8);
        func_80066150(0);
        for (i = 15, p = self + 0x35; i >= 0; i--) {
            *p-- = 0;
        }
        self[0x464] = 0;
        func_8001D218();
        func_8002B838();
        if ((u8)(self[0xC] - 1) < 8) {
            for (i = 0; i < 3; i++) {
                v = D_800F0F14[i + (self[0xC] - 1) * 3];
                q = self + 0x168;
                q[v] = self[0xC];
                r = self + 0x465;
                r[i] = v;
            }
            switch (self[0xC]) {
            case 1:
                A(3);
                B(3);
                A(7);
                B(7);
                break;
            case 2:
                A(4);
                B(4);
                C(4);
                break;
            case 3:
                A(2);
                B(2);
                A(8);
                B(8);
                break;
            case 4:
                A(3);
                B(3);
                A(5);
                B(5);
                A(8);
                B(8);
                break;
            case 5:
                A(4);
                B(4);
                C(4);
                A(7);
                B(7);
                break;
            case 6:
                A(1);
                B(1);
                A(5);
                B(5);
                break;
            case 7:
                A(2);
                B(2);
                A(6);
                B(6);
                break;
            case 8:
                A(1);
                B(1);
                A(6);
                B(6);
                break;
            }
        }
        if (self[0xC] >= 9) {
            self[0] = 7;
        } else if (((u8)self[0x60] >> (self[0xC] - 1)) & 1) {
            self[0] = 7;
        } else {
            self[0] = 5;
        }
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
    }
}
