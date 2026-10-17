#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);

void func_800F3500(u8* arg0) {
    if ((*(u8**)(arg0 + 0x7C))[0x15] == 0) {
        *(s32*)(arg0 + 0x20) = 0xFFFEAAAB;
    } else {
        *(s32*)(arg0 + 0x20) = 0x15555;
    }
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x24) = 0x38000;
    *(s32*)(arg0 + 0x2C) = 0x1C00;
    func_80016C48(2, 0x35, arg0);
    arg0[6] = arg0[6] + 1;
}
