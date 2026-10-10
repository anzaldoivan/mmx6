#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CDF0();      /* extern */
M2C_UNK func_8003F3DC(void*); /* extern */

void func_8003A268(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD5) > 0) {
        func_8003CDF0();
        func_8003F3DC(arg0);
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 1;
        M2C_FIELD(arg0, s8*, 5) = 0x12;
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s8*, 0xD5) = (s8) - (s8)(u8)M2C_FIELD(arg0, s8*, 0xD5);
    }
}
