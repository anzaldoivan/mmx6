#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
M2C_UNK func_8002C9B0();
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern u8 D_800F6DF4[];
extern void (*D_800F6DFC[])(void*);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F049C(void* arg0) {
    if (D_800970A0.x_pos.i.hi >= 0x12E1 && D_800970A0.y_pos.i.hi >= 0x4C1) {
        func_80027BA0(0, 0x1240, 0x420, D_800F6DF4);
        func_80016C48(5, 3, 0);
        func_8002C9B0(arg0);
        return;
    }
    if (SH(arg0, 0x14) != 0) {
        if (!(SH(arg0, 0x14) & 1)) {
            D_800971F8[0].y_pos.i.hi += 3;
        } else {
            D_800971F8[0].y_pos.i.hi -= 3;
        }
        SH(arg0, 0x14)--;
    }
    D_800F6DFC[SB(arg0, 4)](arg0);
}
