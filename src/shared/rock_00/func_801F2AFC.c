#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void func_8002D2B0(struct X4_MovingObj*);
extern struct X4_BackgroundObj D_800971F8[3];

void func_801F2AFC(struct X4_WeaponObj* arg0) {
    s16 d;
    s32 flag;

    func_80017A04((struct X4_AnimatedObj*)arg0);
    func_8002D2B0((struct X4_MovingObj*)arg0);
    flag = 0;
    d = arg0->y_pos.i.hi - D_800971F8[arg0->bg_offset].y_pos.i.hi;
    if (arg0->unk2 == 0) {
        flag = d < -0x80;
    } else if (d < -0x20) {
        flag = 1;
    }
    if (flag != 0) {
        arg0->state = 3;
    }
}
