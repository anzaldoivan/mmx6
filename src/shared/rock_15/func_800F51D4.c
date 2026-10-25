#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
M2C_UNK func_80049D90(void*);

void func_800F51D4(u8* arg0) {
    func_80017A04();
    ((void (*)(void*))move_object)(arg0);
    if (arg0[0x70] != 0) {
        func_80049D90(arg0);
        arg0[4] = 2;
    }
}
