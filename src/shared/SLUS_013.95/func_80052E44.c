#include "common.h"
#define M2C_UNK s32

s32 func_80014B78(void);
void read_rock_bin_member(s32, s32);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
void* func_8002BCCC(void*, s32);
M2C_UNK clear_object_slot();
extern u8 D_800CD30B;

#define SCRATCH_30 (*(s32**)0x1F800030)

void func_80052E44(u8* arg0) {
    s32 a0;
    u8* p;
    s32* a1;
    u8 d;

    if (*(s8*)(arg0 + 4) == 0) {
        switch (D_800CD30B) {
        default:
            a0 = 0x2D;
            break;
        case 0:
            a0 = 0x2B;
            break;
        case 1:
            a0 = 0x2C;
            break;
        }
        read_rock_bin_member(a0, 0x800FA000);
        {
            s32 t = arg0[4] + 1;
            arg0[4] = t;
        }
        return;
    }
    if (func_80014B78() != 0) {
        p = func_8002BCCC(0, 0);
        if (p != 0) {
            p[0] = 0x41;
            d = D_800CD30B;
            if (d == 0) {
                p[1] = 0x35;
                a1 = SCRATCH_30;
            } else if (d == 1) {
                p[1] = 0x37;
                p[2] = d;
                a1 = SCRATCH_30 + 0x40;
            } else {
                p[1] = 0x3F;
                a1 = SCRATCH_30 + 0x60;
            }
            load_palette(0x58, a1, 8);
            ((M2C_UNK(*)())clear_object_slot)(arg0);
        }
    }
}
