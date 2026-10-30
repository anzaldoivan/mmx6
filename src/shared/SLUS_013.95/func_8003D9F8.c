#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
void func_8003DAF4(s8 direction);
void func_8003DB44(s8);

void func_8003D9F8(void* arg0) {
    u32 i;

    if (!(M2C_FIELD(arg0, u8*, 0xD7) & 3)) {
        i = 0;
        do {
            i++;
            func_8003DAF4((u8)(random_byte() & 0x1F) | 0x80);
        } while (i < 4);
    }
    if (M2C_FIELD(arg0, s8*, 0xD6) != 3) {
        if (M2C_FIELD(arg0, s8*, 0xD7) == 0) {
            func_8003DB44(M2C_FIELD(arg0, s8*, 0xD6));
            if (M2C_FIELD(arg0, s8*, 0xD6) == 2) {
                func_8003DB44(3);
            }
            M2C_FIELD(arg0, u8*, 0xD7) = 0x12;
            M2C_FIELD(arg0, u8*, 0xD6) = M2C_FIELD(arg0, u8*, 0xD6) + 1;
            return;
        }
        M2C_FIELD(arg0, u8*, 0xD7) = M2C_FIELD(arg0, u8*, 0xD7) - 1;
        return;
    }
    M2C_FIELD(arg0, u8*, 0xD7) = 0x14;
    M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
}
