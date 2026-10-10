#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;
extern u8 D_800F7BA0[][6];
extern s16 D_800F7E10;
extern s16 D_800F7E40[][4];

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F174C(void* arg0) {
    s16 ang;
    u8 idx;

    if (H(arg0, 0x7C) == 0x5A) {
        func_80016C48(2, 0x2A, arg0);
    }
    if (!(H(arg0, 0x7C) & 7)) {
        if (D_800970A0.x_pos.i.hi > H(arg0, 0xA)) {
            UB(arg0, 0x15) = 0x40;
        } else {
            UB(arg0, 0x15) = 0;
        }
        ang = func_80065B74(D_800970A0.y_pos.i.hi - H(arg0, 0xE),
                            D_800970A0.x_pos.i.hi - H(arg0, 0xA));
        W(arg0, 0x20) = func_80065A14(ang) << 5;
        W(arg0, 0x24) = -func_80065944(ang) << 5;
    }
    D_800F7E40[H(arg0, 0x8E)][0] = H(arg0, 0xA);
    D_800F7E40[H(arg0, 0x8E)][1] = H(arg0, 0xE);
    D_800F7E40[H(arg0, 0x8E)][2] = UB(arg0, 0x15);
    if (++H(arg0, 0x8E) == 0xD2) {
        H(arg0, 0x8E) = 0;
    }
    if (++H(arg0, 0x7C) == 0x1F4 || D_800F7E10 == 0) {
        func_800179A4(arg0, 0);
        idx = UB(arg0, 0x87)++;
        W(arg0, 0x20) = 0;
        W(arg0, 0x24) = 0;
        UB(arg0, 0x5) = D_800F7BA0[UB(arg0, 0x86)][idx];
        UB(arg0, 0x6) = 0;
    }
}
