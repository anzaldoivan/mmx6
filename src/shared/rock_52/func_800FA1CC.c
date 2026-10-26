#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

void func_800E9F7C(void);

void func_800FA1CC(u8* arg0) {
    ((void (*)(s32))SetDispMask)(1);
    func_800E9F7C();
    {
        s32 v = arg0[1];
        s32 c = 0x141;
        *(s16*)(arg0 + 8) = c;
        c = 2;
        *(s16*)(arg0 + 0xA) = c;
        arg0[1] = v + 1;
    }
}
