#include "common.h"
#define M2C_UNK s32

void func_8002D2B0(void*);
M2C_UNK func_800FB0F8();

void func_800FC158(u8* arg0) {
    s32 t;

    func_8002D2B0(arg0);
    t = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = t;
    if ((t << 16) == 0) {
        func_800FB0F8(arg0);
    }
}
