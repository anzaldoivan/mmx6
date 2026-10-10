#include "common.h"
#include "mmx6/x4.h"

extern u32* D_8008EC18[2][102];
#define EC18(b, l, i)                                                          \
    (*(u32**)((u8*)D_8008EC18 + (i) * 4 + (l) * 68 + (b) * 408))
extern u32 D_80090E78[2][6][17];
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_DrawInfo* D_8009B7A0;
extern u8 D_800CC870[];
#define D_800CC870 (*(X4_P_TAG(*)[2][6][17]) & D_800CC870)
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) ((u32)((X4_P_TAG*)(p))->addr)

void func_80026ECC(s32 arg0) {
    struct X4_DrawInfo* info;
    u32 v;
    s32 buf;
    s32 l;
    u32 i;

    l = arg0 + 3;
    buf = SP_DRAW_BUFFER;
    info = D_8009B7A0;
    for (i = 0; i < 17; i++) {
        v = D_80090E78[buf][arg0][i];
        if (v != 0) {
            SETADDR(&D_800CC870[buf][arg0][i], v);
            SETADDR(EC18(buf, arg0, i), GETADDR(&info->ordering_table.start +
                                                (s8)D_800971F8[arg0].unk4A));
            SETADDR(&info->ordering_table.start + (s8)D_800971F8[arg0].unk4A,
                    &D_800CC870[buf][arg0][i]);
        }
        v = D_80090E78[buf][l][i];
        if (v != 0) {
            SETADDR(&D_800CC870[buf][l][i], v);
            SETADDR(EC18(buf, l, i), GETADDR(&info->ordering_table.start +
                                             (s8)D_800971F8[arg0].unk4B));
            SETADDR(&info->ordering_table.start + (s8)D_800971F8[arg0].unk4B,
                    &D_800CC870[buf][l][i]);
        }
    }
}
#undef GETADDR
#undef SETADDR
#undef D_800CC870
#undef EC18
