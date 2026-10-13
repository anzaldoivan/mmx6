#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_800F5D58();
extern M2C_UNK D_8007433C;

void func_800F7F70(u8* arg0) {
    if (*(u8*)(arg0 + 0x8D) == 1) {
        func_800179A4(arg0, 0xD);
        *(s32*)(arg0 + 0x50) = 0;
        *(s32*)(arg0 + 0x54) = 0;
        *(u16*)(arg0 + 0x7E) += 1;
        *(u8*)(arg0 + 0x6) += 1;
        return;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(void**)(arg0 + 0x58) = &D_8007433C;
        *(u8*)(arg0 + 0x8E) = 1;
        func_800F5D58(arg0);
    }
}
