#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800429D4();
extern s32 D_80075EDC;
extern s32 D_80075EE4;
extern u8 D_800CCF38;

void func_80042538(void* self) {
    if (M2C_FIELD(self, u16*, 0x7C) & 1) {
        M2C_FIELD(self, u8*, 0x3) = 0;
    } else {
        M2C_FIELD(self, u8*, 0x3) = 1;
    }
    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        M2C_FIELD(self, u8*, 0x8F) = 0;
        M2C_FIELD(self, u8*, 0x2) = (M2C_FIELD(self, u8*, 0x2) & 0xF0) + 2;
        ((void (*)(void*))func_800429D4)(self);
        M2C_FIELD(self, u8*, 0x60) = 4;
        M2C_FIELD(self, u8*, 0x5C) = 10;
        switch (D_800CCF38) {
        case 0:
            M2C_FIELD(self, u8*, 0x5C) = 2;
            break;
        case 1:
            break;
        case 2:
        default:
            M2C_FIELD(self, u8*, 0x5C) += 8;
            break;
        }
        M2C_FIELD(self, void**, 0x50) = &D_80075EDC;
        M2C_FIELD(self, void**, 0x54) = &D_80075EE4;
        M2C_FIELD(self, s32*, 0x68) = 0;
    }
}
