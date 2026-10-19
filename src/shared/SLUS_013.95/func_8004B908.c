#include "common.h"
#include "mmx6/x4.h"

extern void (*D_80077E80[])();
extern u8 D_8008EAFC;

void func_8004B908(struct X4_WeaponObj* arg0) {
    if (D_8008EAFC == 0) {
        arg0->state++;
        return;
    }
    D_80077E80[arg0->unk5](arg0);
}
