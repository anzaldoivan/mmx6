#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F02A0(u8, s8, s32, s16);
void func_800F04C8(void*, u8, s8, s32, s32);
s32 func_800F05AC(s32);
s32 func_800F05E8(u8);
s32 func_800F0724(u8, s32);
void func_800F0784(s32);
extern s32 D_8006D674[];
extern s8 D_800CCEF8;
extern u16 D_800F36CC;
extern s32 D_800F370C[];
extern s16 D_800F3920[];
extern u16 D_800F48EC;
extern s16 D_800F48EE;
extern s16 D_800F48F0;
extern u8 D_800F48F2;
extern u8 D_800F48F5;
extern u8 D_800F48F7;

#define S_2 M2C_FIELD(self, u8*, 0x2)
#define S_3 M2C_FIELD(self, s8*, 0x3)
#define S_6C M2C_FIELD(self, s32*, 0x6C)
#define S_70 M2C_FIELD(self, s32*, 0x70)

void func_800E9E34(void* self) {
    s32* e;
    s32* f;
    s32 mask;
    s32 mask2;
    s32 i;
    s8 n;

    for (; (s8)D_800F48F2 >= 0; D_800F48F2++) {
        if (func_800F05E8(D_800F48F2) != 0) {
            if (D_800F48F7 == 0) {
                S_3 = 2;
                func_800F0784(2);
                func_800F02A0(0xBA, 2, 0xD2, 0x9A);
                D_800F48F7 = 1;
            }
            func_800F04C8(self, D_800F48F2, (s8)(D_800F48F5 + 2), 0xDC,
                          D_800F3920[(s8)D_800F48F5 + 1]);
            if (D_8006D674[D_800F48F2] != 0) {
                i = func_800F05AC(D_8006D674[D_800F48F2]);
                {
                    s32* t = D_800F370C;
                    e = &t[i * 3];
                }
                switch (e[0]) {
                case 1:
                    mask = 0x100 << ((u8)func_800F0724(D_800F48F2, 1) - 1);
                    if (!(S_6C & mask)) {
                        func_800F02A0(((u8*)e)[4], (s8)(D_800F48F5 + 2), 0x48,
                                      D_800F3920[(s8)D_800F48F5 + 1] - 4);
                    }
                    break;
                case 2:
                    mask2 = 0x01000000
                            << ((u8)func_800F0724(D_800F48F2, 2) - 1);
                    if (!(S_6C & mask2)) {
                        func_800F02A0(((u8*)e)[4], (s8)(D_800F48F5 + 2), 0x48,
                                      D_800F3920[(s8)D_800F48F5 + 1] - 4);
                    }
                    break;
                default:
                    f = &D_800F370C[i * 3];
                    if (!(S_70 & f[0])) {
                        func_800F02A0(((u8*)f)[4], (s8)(D_800F48F5 + 2), 0x48,
                                      D_800F3920[(s8)D_800F48F5 + 1] - 4);
                    }
                    break;
                }
            }
            if ((s8)++D_800F48F5 == 4) {
                D_800F48F2++;
                break;
            }
        }
    }
    n = D_800F48F5;
    if (n != 0) {
        D_800F48EE = 0;
        D_800CCEF8 = 1;
        D_800F48F0 = n + 1;
        D_800F48EC = D_800F36CC;
        S_2 = S_2 + 1;
    } else {
        S_2 = 4;
    }
}
