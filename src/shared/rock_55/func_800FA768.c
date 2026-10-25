#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCF08;

void func_800FA768(u8* arg0) {
    if (*(s16*)(arg0 + 4) >= 0x78) {
        u8* q = (u8*)background_objects;

        q[0x57] = 1;
        *(s16*)(q + 0x5E) = 0x120;
        *(s16*)(q + 0x62) = 0x300;
        q[0xA0] = 1;
        if (D_800CCF08 != 0) {
            *(s16*)(arg0 + 8) = 0x1D4;
            *(s16*)(arg0 + 0xA) = 2;
        }
        arg0[1]++;
        return;
    }
    *(s16*)(arg0 + 4) += 1;
}
