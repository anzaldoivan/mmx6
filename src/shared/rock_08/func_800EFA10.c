#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(s32);
s32 random_byte();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);

extern M2C_UNK D_800F5D38;
extern M2C_UNK D_800F5D3C;

void func_800EFA10(void* self) {
    ((void (*)(s32))func_8002D230)((s32)self);
    if (M2C_FIELD(self, u8*, 0x70) != 0) {
        func_80049E50(self);
        if (random_byte() & 1) {
            func_800477E4(2, &D_800F5D38, self);
        } else {
            func_800477E4(2, &D_800F5D3C, self);
        }
        M2C_FIELD(self, u8*, 0x4) = 2;
    }
}
