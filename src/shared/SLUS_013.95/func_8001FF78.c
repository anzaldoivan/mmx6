#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002AA74(); /* extern */
extern s8 D_80097424;

void func_8001FF78(void* arg0) {
    if (D_80097424 == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_8002AA74();
        M2C_FIELD(arg0, s8*, 7) = 0;
        M2C_FIELD(arg0, s32*, 0x34) = 0;
    }
}
