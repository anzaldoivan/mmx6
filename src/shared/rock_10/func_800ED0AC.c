#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D380(void*, void*);
extern struct X4_PlayerObj g_Player;
extern u8 D_800E987C[];

s32 func_800ED0AC(u8* arg0) {
    u8 tbl[33];
    u8 cur;
    u32 d;

    __builtin_memcpy(tbl, D_800E987C, 33);
    d = (u8)(tbl[func_8002D380(arg0, &g_Player)] - arg0[0x88]) & 7;
    cur = arg0[0x88];
    if (d != 0) {
        if (d < 4) {
            cur = (cur + 1) & 7;
        } else {
            cur = (cur - 1) & 7;
        }
    }
    return cur;
}
