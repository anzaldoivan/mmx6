#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F02A0(u8, s8, s32, s16);
s32 func_800F05AC(s32);
s32 func_800F05E8(u8);
s32 func_800F0724(u8, s32);
void func_800F0784(s32);
extern s32 D_8006D674[];
extern s8 D_800CCEF8;
extern u8 D_800CCF2B[];
extern u8 D_800CCF31[];
extern u16 D_800F36CC;
extern s32 D_800F370C[];
extern u8 D_800F3844[];
extern s16 D_800F3920[];
extern u16 D_800F48EC;
extern s16 D_800F48EE;
extern s16 D_800F48F0;
extern u8 D_800F48F2;
extern u8 D_800F48F4;
extern u8 D_800F48F5;
extern u8 D_800F48F7;
extern u8 D_800F48F8;

#define S_2 M2C_FIELD(self, u8*, 0x2)
#define S_3 M2C_FIELD(self, s8*, 0x3)
#define S_38 M2C_FIELD(self, s8*, 0x38)
#define S_6C M2C_FIELD(self, s32*, 0x6C)
#define S_70 M2C_FIELD(self, s32*, 0x70)

#define LINE(a, b, pos)                                                        \
    {                                                                          \
        func_800F02A0((a), (s8)(D_800F48F5 + 2), 0x48,                         \
                      (pos)[(s8)D_800F48F5 + 1] - 4);                          \
        func_800F02A0((b), (s8)(D_800F48F5 + 2), 0xDC,                         \
                      (pos)[(s8)D_800F48F5 + 1]);                              \
    }

#define HEADER()                                                               \
    if (D_800F48F8 == 0) {                                                     \
        func_800F02A0(0x24, 1, 0xC8, 0x9A);                                    \
        D_800F48F8 = 1;                                                        \
    }

void func_800EA1F0(void* self) {
    extern u8 g_playthrough_state[];
    s16* pos;
    s32* e;
    s32* f;
    s32 mask;
    s32 mask2;
    s32 i;
    u8* m;
    s8 n;

    {
        while ((s8)D_800F48F2 >= 0) {
            if (func_800F05E8(D_800F48F2) != 0) {
                if (D_8006D674[D_800F48F2] != 0) {
                    if (D_800F48F7 == 0) {
                        S_3 = 2;
                        func_800F0784(2);
                        D_800F48F7 = 1;
                    }
                    i = func_800F05AC(D_8006D674[D_800F48F2]);
                    {
                        s32* t = D_800F370C;
                        e = &t[i * 3];
                    }
                    switch (e[0]) {
                    case 1:
                        mask = 0x100 << ((u8)func_800F0724(D_800F48F2, 1) - 1);
                        if (!(S_6C & mask)) {
                            HEADER();
                            LINE(((u8*)e)[4], ((u8*)e)[5], D_800F3920);
                            D_800CCF2B[S_38] += 2;
                            S_6C |= mask;
                            D_800F48F5++;
                        }
                        break;
                    case 2:
                        mask2 = 0x01000000
                                << ((u8)func_800F0724(D_800F48F2, 2) - 1);
                        if (!(S_6C & mask2)) {
                            HEADER();
                            LINE(((u8*)e)[4], ((u8*)e)[5], D_800F3920);
                            D_800CCF31[S_38] += 2;
                            S_6C |= mask2;
                            D_800F48F5++;
                        }
                        break;
                    default: {
                        s32* t = D_800F370C;
                        f = &t[i * 3];
                    }
                        if (!(S_70 & f[0])) {
                            HEADER();
                            LINE(((u8*)f)[4], ((u8*)f)[5], D_800F3920);
                            S_70 |= f[0];
                            D_800F48F5++;
                        }
                        break;
                    }
                }
                if ((s8)D_800F48F5 == 4) {
                    D_800F48F2++;
                    break;
                }
            }
            D_800F48F2++;
        }
    }
    if ((s8)D_800F48F2 < 0 && (s8)D_800F48F5 < 4) {
        s8 req = D_800F48F4;
        if (req == 1) {
            D_800F48F4 = 0;
            if (D_800F48F7 == 0) {
                S_3 = 2;
                func_800F0784(2);
                D_800F48F7 = req;
            }
            if (D_800F48F8 == 0) {
                func_800F02A0(0x24, 1, 0xC8, 0x9A);
                D_800F48F8 = req;
            }
            switch (g_playthrough_state[0x69] ^ g_playthrough_state[0xC8]) {
            case 0x1:
                LINE(D_800F3844[1], D_800F3844[2], D_800F3920);
                break;
            case 0x2:
                LINE(D_800F3844[4], D_800F3844[5], D_800F3920);
                break;
            case 0x4:
                LINE(D_800F3844[7], D_800F3844[8], D_800F3920);
                break;
            case 0x8:
                LINE(D_800F3844[10], D_800F3844[11], D_800F3920);
                break;
            case 0x10:
                LINE(D_800F3844[13], D_800F3844[14], D_800F3920);
                break;
            case 0x20:
                LINE(D_800F3844[16], D_800F3844[17], D_800F3920);
                break;
            case 0x40:
                LINE(D_800F3844[19], D_800F3844[20], D_800F3920);
                break;
            case 0x80:
                LINE(D_800F3844[22], D_800F3844[23], D_800F3920);
                break;
            }
            D_800F48F5++;
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
        S_2 = 3;
    }
}
