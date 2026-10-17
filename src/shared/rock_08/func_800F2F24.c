#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(s32);

void func_800F2F24(s8* arg0) {
    func_80017A04();
    ((void (*)(void*))func_8002D230)(arg0);
    if ((*(u8*)(arg0 + 0x70) & 8) && (*(s32*)(arg0 + 0x24) < 0)) {
        func_80012D9C(5);
        func_80029478(0x14, 2, 2);
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x2C) = 0;
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[6] = 4;
    }
}
