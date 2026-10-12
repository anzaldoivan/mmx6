#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

extern u8 D_800FB26C[];

void func_800EA758(void* self) {
    u8* s1 = M2C_FIELD(SPAD, u8**, 0x80);

    if (M2C_FIELD(s1, s8*, 0x4) == 2) {
        M2C_FIELD(self, u8*, 0x5) = 5;
        M2C_FIELD(self, u8*, 0x6) = 0;
        return;
    }
    ((void (**)(void*))(D_800FB26C + 0xB84))[M2C_FIELD(self, s8*, 0x6)](self);
    if (M2C_FIELD(s1, s8*, 0x4) == 3) {
        M2C_FIELD(self, u8*, 0x5) = 5;
        M2C_FIELD(self, u8*, 0x6) = 1;
    }
}
