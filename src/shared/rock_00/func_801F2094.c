#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_8002D2B0(struct X4_MovingObj*);
extern struct X4_BackgroundObj D_800971F8[3];

void func_801F2094(struct X4_WeaponObj* arg0) {
    s32 off;
    s16 dx;
    s16 dy;

    func_80017A04((struct X4_AnimatedObj*)arg0);
    func_8002D2B0((struct X4_MovingObj*)arg0);
    off = 0;
    dx = arg0->x_pos.i.hi - D_800971F8[arg0->bg_offset].x_pos.i.hi;
    dy = arg0->y_pos.i.hi - D_800971F8[arg0->bg_offset].y_pos.i.hi;
    if (arg0->unk15 != 0) {
        {
            s32 t = dx - 0x20;
            off = t > 0x140;
        }
    } else if (dx + 0x20 < 0) {
        off = 1;
    }
    if (dy - 0x38 > 0xF0) {
        off = 1;
    }
    if (off != 0) {
        arg0->unk50 = 0;
        arg0->on_screen = 0;
        arg0->state = 2;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
}
