#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
s32 func_8003906C(void*);              /* extern */
s32 func_80039984(void*);              /* extern */
s32 func_8003A2CC(void*);              /* extern */
s32 func_8003A488(void*);              /* extern */
s32 func_8003A870();                   /* extern */
M2C_UNK func_8003B054(void*);          /* extern */
M2C_UNK func_8003D18C(void*);          /* extern */
M2C_UNK func_8003D394(void*);          /* extern */
s32 func_8003E174(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA454(void*);              /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EC028();                   /* extern */

void func_800368FC(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        if (((s32(*)())func_8003A870)() == 0) {
            func_8003B054(arg0);
        }
    } else {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            var_v0 = func_8003E174(arg0);
            goto block_8;
        }
        if ((func_801EA560(arg0) == 0) && (func_801EA454(arg0) == 0)) {
            var_v0 = func_801EC028(arg0);
        block_8:
            if ((var_v0 == 0) && (func_8003A488(arg0) == 0) &&
                (func_80039984(arg0) == 0) && (func_8003A2CC(arg0) == 0) &&
                (func_8003906C(arg0) == 0)) {
                func_80017A04(arg0);
                func_8003D18C(arg0);
                func_8003D394(arg0);
                func_8003F508(arg0, 0xB);
            }
        }
    }
}
