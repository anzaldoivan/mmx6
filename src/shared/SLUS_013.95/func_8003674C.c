#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
M2C_UNK func_8002D5D0(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003D394(void* arg0);
extern struct X4_BackgroundObj D_800971F8[3];

void func_8003674C(struct X4_MainObj* arg0) {
    ((void (*)())func_80017A04)();
    if (arg0->unk6 == 0) {
        if (arg0->animation_step.fields.relative_step == 0) {
            D_800971F8[0].unk28 = D_800971F8[0].y_pos.i.hi;
            D_800971F8[0].unk2A = D_800971F8[0].y_pos.i.hi;
            D_800971F8[0].unk20 = D_800971F8[0].y_pos.i.hi;
            D_800971F8[0].unk22 = D_800971F8[0].y_pos.i.hi;
            ((void (*)(void*, s32))func_8003BA04)(arg0, 4);
            arg0->terrain_box = 0;
            arg0->unk6++;
        }
    } else {
        if (func_8002CBFC(arg0, 0x20, 0x40) == 0) {
            func_8002D5D0(arg0);
            func_8003D394(arg0);
            return;
        }
        arg0->on_screen = 0;
        arg0->state = 3;
        arg0->unk5 = 0;
        arg0->unk6 = 0;
    }
}
