#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001750C(u8, u8); /* extern */
void func_800186A8();       /* extern */
void func_80025F84();       /* extern */
void func_8002B838(void);    /* extern */
void func_8002C2B8();       /* extern */
extern s8 D_80097424;

void func_8001DC04(void* arg0) {
    if (D_80097424 == 0) {
        func_80025F84();
        func_800186A8();
        func_8001750C(0xFF, 0);
        func_8002B838();
        func_8002C2B8();
        M2C_FIELD(arg0, s16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}
