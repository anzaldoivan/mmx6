#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
struct X4_QuadObj* func_8002C7F0(void);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA44C(struct X4_BackgroundObj* arg0) {
    u8* q = (u8*)func_8002C7F0();
    if (q != 0) {
        q[0] = 1;
        q[1] = 0xA;
        q[0x36] = 0x11;
        q[2] = 1;
    }
    D_800971F8[0].unk3 = 0;
    D_800971F8[1].unk3 = 0;
    D_800971F8[2].unk3 = 1;
    ((void (*)(s32))func_800139A0)(8);
    *(s16*)&arg0->unk4 = 0;
    arg0->unk1++;
}
