#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
void func_801EE638(void* arg0);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 random_byte();

void func_801EE538(struct X4_WeaponObj* arg0) {
    arg0->unk50 = 0;
    arg0->unk68 = 0;
    if (arg0->unk98 > 0) {
        func_801EE638(arg0);
        return;
    }
    arg0->x_vel.val = -arg0->x_vel.val;
    if (random_byte() & 1) {
        arg0->y_vel.val = 0x40CCB;
    } else {
        arg0->y_vel.val = -0x40CCB;
    }
    arg0->state = 2;
    arg0->unk5 = 0;
    arg0->unk15 ^= 0x40;
    func_8002CCB0(arg0, 0xC, 8);
}
