#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800660B8(M2C_UNK);
void func_800E9F7C(void);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FA1AC(u8* arg0) {
    ((void (*)(s32))func_800660B8)(1);
    D_800971F8[0].unk3 = 0;
    D_800971F8[1].unk3 = 0;
    D_800971F8[2].unk3 = 1;
    D_800971F8[2].x_pos.val = 0;
    D_800971F8[2].y_pos.val = 0;
    func_800E9F7C();
    {
        s32 v = arg0[1];
        s32 c = 0x152;
        *(s16*)(arg0 + 8) = c;
        c = 1;
        *(s16*)(arg0 + 0xA) = c;
        arg0[1] = v + 1;
    }
}
