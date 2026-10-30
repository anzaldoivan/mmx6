#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EC858(struct X4_MainObj* arg0) {
    arg0->unk15 = ((struct X4_MainObj*)arg0->attack_box)->unk15;
    set_animation(arg0, 0xD);
    {
        // !FAKE: depin: dropping it breaks the match (14/20)
        register s32 t asm("$2") = arg0->unk42;
        arg0->on_screen = 1;
        arg0->state = 1;
        arg0->unk42 = t & 0x7FFF;
    }
}
