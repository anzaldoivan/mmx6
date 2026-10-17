#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2); /* extern */
extern struct X4_PlayerObj D_800970A0;
extern s32 D_80097420;
extern s8 D_800CD334;

void func_80034614(u8* arg0) {
    s32 flag;
    u32 i;

    if (!(D_80097420 & 1)) {
        flag = 0;
        i = 0;
        do {
            u8* pl = (u8*)&D_800970A0;
            s16* p = (s16*)(pl + 0xA8) + i;
            if (*p >= *(s16*)(pl + 0x14A)) {
                *p = *(s16*)(pl + 0x14A);
            } else {
                *p += 6;
                if (*(s16*)(pl + 0x14A) < *p) {
                    *p = *(s16*)(pl + 0x14A);
                } else {
                    flag = 1;
                }
            }
            i++;
        } while (i < 9);
        if (flag) {
            if (!(D_80097420 & 3)) {
                func_80016C48(0, 0x17, 0);
            }
        } else {
            arg0[5] = 8;
            D_800CD334 = 1;
        }
    }
}
