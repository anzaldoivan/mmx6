#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();

void func_800F5FD4(struct X4_MainObj* arg0) {
    register s32 t asm("$2");

    ((M2C_UNK(*)())func_80017A04)();
    func_800F82C0(arg0);
    t = *(u16*)&arg0->unk7C + 1;
    arg0->unk7C = t;
    if ((s16)t == 0x79) {
        func_80016C48(2, 0x24, arg0);
    }
    if (arg0->unk7 == 1) {
        arg0->unk7 = 0;
        arg0->unk7C = 0;
        arg0->unk6++;
        func_800179A4(arg0, 9);
    }
}
