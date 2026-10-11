#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                        /* extern */
s32 func_8002FE30(void*);                       /* extern */
void func_80038CD0(void* arg0);                 /* extern */
M2C_UNK func_80038F64(void*);                   /* extern */
s32 func_8003A764(void*);                       /* extern */
s32 func_8003A814(void*, s32);                  /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);      /* extern */
s32 func_8003E06C(void*);                       /* extern */
s32 func_801EA124(void*);                       /* extern */
s32 func_801EA560(void*);                       /* extern */

void func_800361D4(void* arg0) {
    s8 temp_s0;
    s32 temp_v0;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if ((func_8003E06C(arg0) == 0) && (func_8003A764(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EA560(arg0) == 0) && (func_801EA124(arg0) == 0)))) {
        if (M2C_FIELD(arg0, s8*, 6) == 0) {
            ((void (*)())func_80017A04)(arg0);
            if ((M2C_FIELD(arg0, s8*, 0x8F) != 0) &&
                (M2C_FIELD(arg0, s8*, 2) == 0)) {
                temp_s0 = M2C_FIELD(arg0, s8*, 0x44);
                func_8003BB94(arg0,
                              func_8003A814(arg0, func_8002FE30(arg0) & 0xFF) +
                                  0x94,
                              M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
                M2C_FIELD(arg0, s8*, 0x44) = temp_s0;
            }
            if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                M2C_FIELD(arg0, u8*, 6) = 1;
            }
        } else {
            func_80038F64(arg0);
            func_80038CD0(arg0);
            if (M2C_FIELD(arg0, s32*, 0x18) != M2C_FIELD(arg0, s32*, 8)) {
                if (M2C_FIELD(arg0, s8*, 0xDE) == 0) {
                    func_80016C48(0, 0x27, arg0);
                }
                temp_v0 = M2C_FIELD(arg0, u8*, 0xDE) + 1;
                M2C_FIELD(arg0, u8*, 0xDE) = temp_v0;
                if ((s8)temp_v0 >= 0x15) {
                    goto block_19;
                }
            } else {
            block_19:
                M2C_FIELD(arg0, u8*, 0xDE) = 0;
            }
        }
    }
}
