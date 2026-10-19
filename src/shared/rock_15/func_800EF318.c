#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EF318(void* self) {
    s32 v;

    M2C_FIELD(self, s32*, 8) += M2C_FIELD(self, s32*, 0x20);
    if (M2C_FIELD(self, u8*, 0x15) != 0) {
        M2C_FIELD(self, s32*, 0x20) += M2C_FIELD(self, s32*, 0x28);
    } else {
        M2C_FIELD(self, s32*, 0x20) -= M2C_FIELD(self, s32*, 0x28);
    }
    v = M2C_FIELD(self, s32*, 0x20);
    if ((v < 0 ? -v : v) > 0x60000) {
        if (M2C_FIELD(self, u8*, 0x15) != 0) {
            M2C_FIELD(self, s32*, 0x20) = 0x60000;
        } else {
            M2C_FIELD(self, s32*, 0x20) = -0x60000;
        }
        M2C_FIELD(self, s32*, 0x28) = 0;
    }
}
