#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230(void*);
void func_801EF0FC(u8* arg0);

void func_801EFAB4(u8* arg0) {
    s32 t;

    ((void (*)(void*))func_8002D230)(arg0);
    t = *(u16*)(arg0 + 0x88) - 1;
    *(u16*)(arg0 + 0x88) = t;
    if ((t << 0x10) == 0) {
        func_801EF0FC(arg0);
        *(u16*)(arg0 + 0x88) = 3;
    }
}
