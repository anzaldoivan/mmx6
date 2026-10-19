#include "common.h"
#include "mmx6/x4.h"

extern s32 D_800F90B8;
extern s32 D_800F90BC;
void func_800F6E48(struct X4_MainObj*);

void func_800F5DF8(struct X4_MainObj* arg0) {
    arg0->attack_box = &D_800F90B8;
    arg0->hurt_box = &D_800F90BC;
    arg0->unk7C = 0x32;
    func_800F6E48(arg0);
    arg0->unk6++;
}
