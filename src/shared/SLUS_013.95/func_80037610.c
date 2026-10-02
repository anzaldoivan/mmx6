#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);              /* extern */
M2C_UNK func_8002D5D0(void*);              /* extern */
s32 func_8003A514();                       /* extern */
M2C_UNK func_8003B810(void*);              /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */
s32 func_8003E260(void*);                  /* extern */
s32 func_801EA560(void*);                  /* extern */
s32 func_801EC0F0(void*);                  /* extern */

void func_80037610(void* arg0) {
    s32 var_v0;
    s8 temp_s0;
    u16 temp_v1;

    if (func_8003A514() == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            var_v0 = func_8003E260(arg0);
            goto block_5;
        }
        if (func_801EA560(arg0) == 0) {
            var_v0 = func_801EC0F0(arg0);
        block_5:
            if (var_v0 == 0) {
                if (M2C_FIELD(arg0, u16*, 0x80) & 2) {
                    M2C_FIELD(arg0, s8*, 0x15) = 0;
                }
                if (M2C_FIELD(arg0, u16*, 0x80) & 1) {
                    M2C_FIELD(arg0, s8*, 0x15) = 0x40;
                }
                temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
                if (temp_v1 & 4) {
                    func_80017A04(arg0);
                    func_8002D5D0(arg0);
                    return;
                }
                if (temp_v1 & 8) {
                    temp_s0 = M2C_FIELD(arg0, s8*, 0x44);
                    func_8003BB94(arg0, 0x20, M2C_FIELD(arg0, s8*, 0x45));
                    M2C_FIELD(arg0, s8*, 0x44) = temp_s0;
                    func_8003B810(arg0);
                }
            }
        }
    }
}
