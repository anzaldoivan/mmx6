#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);
extern s16 D_800F4480;

void func_800F26D4(u8* arg0) {
    ((void (*)(void*))func_8002D2B0)(arg0);
    ((void (*)(void*))func_80017A04)(arg0);
    if (D_800F4480 + 0x460 < *(s16*)(arg0 + 0xE)) {
        *(s32*)(arg0 + 0x24) = 0;
        *(u8*)(arg0 + 6) = *(u8*)(arg0 + 6) + 1;
    }
}
