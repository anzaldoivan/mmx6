#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230();
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049D90(void*);
void func_800F5A94(void* arg0, u8 arg1);

void func_800F55FC(u8* arg0) {
    register s32 v asm("$2");

    func_8002D230(arg0);
    if ((v = arg0[0x70]) == 0) {
        func_8002EE10(arg0);
        if (arg0[0x70] == 0) {
            return;
        }
    }
    func_80016C48(2, 0x17, arg0);
    func_80012D9C(8);
    func_80049D90(arg0);
    func_800F5A94(arg0, 0x10);
    func_800F5A94(arg0, 0x11);
    func_800F5A94(arg0, 0x12);
    arg0[4] = 2;
}
