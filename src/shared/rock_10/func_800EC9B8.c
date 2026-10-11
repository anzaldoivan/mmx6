#include "common.h"
#define M2C_UNK s32
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_800EAA00(void*);
extern u8 D_800FA900[];

void func_800EC9B8(u8* self) {
    *(s32*)(self + 0x18) = *(s32*)(self + 0x8);
    *(s32*)(self + 0x1C) = *(s32*)(self + 0xC);
    ((void (*)(void*))func_80017A04)(self);
    ((void (**)(void*))(D_800FA900 + 0x1634))[*(s8*)(self + 5)](self);
    if ((*(s8*)(self + 2) & 0xF0) == 0x20) {
        if (func_800EAA00(self) != 0) {
            if (*(s8*)(self + 5) != 4) {
                self[5] = 4;
                self[6] = 0;
            }
        }
    }
    func_8002CCB0(self, 0x10, 0x10);
}
