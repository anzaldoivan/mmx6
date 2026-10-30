#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F12FC(struct X4_MainObj* arg0) {
    struct X4_MainObj* p = (struct X4_MainObj*)arg0->ext.raw[0];

    if (p->active != 0) {
        if (p->unk7 == 0) {
            if (--arg0->unk7E == -1) {
                arg0->unk7E = 5;
                arg0->unk42 ^= 0x8000;
            }
            func_8002CCB0(arg0, 0xA0, 0xA0);
        }
    } else {
        clear_object_slot();
    }
}
