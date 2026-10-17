#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80017A04();                        /* extern */
s32 func_80039C40(void*);                       /* extern */
s32 func_80039CFC(void*);                       /* extern */
s32 func_8003A628(void*);                       /* extern */
void func_8003AD18(void* arg0);                 /* extern */
M2C_UNK func_8003AE8C(void*);                   /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);          /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);      /* extern */
void func_8003C6A4(void* arg0);                   /* extern */
M2C_UNK func_8003CCBC();                        /* extern */
void func_8003CD00(void* arg0);                 /* extern */
s32 func_8003F644(void*);                       /* extern */
s32 func_801EA560(void*);                       /* extern */
s32 func_801EBEDC(void*);                       /* extern */
s32 func_801EC1F8(void*);                       /* extern */
s32 func_801EC86C(void*);                       /* extern */

void func_80035D38(void* arg0) {
    s8 temp_s0;
    s8 temp_v1;

    ((void (*)())func_8003CCBC)();
    if (M2C_FIELD(arg0, u16*, 0x80) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if ((func_8003A628(arg0) == 0) && (func_8003F644(arg0) == 0)) {
        if (func_80039C40(arg0) != 0) {
            if (M2C_FIELD(arg0, s8*, 5) == 0xC) {
                func_8003CD00(arg0);
                if (M2C_FIELD(arg0, s8*, 0x8E) != 0) {
                    func_8003BB94(arg0, 0x80, 5);
                } else {
                    func_8003BB94(arg0, 0x10, 5);
                }
                func_8003C6A4(arg0);
                func_80016C48(1, 5, arg0);
                M2C_FIELD(arg0, u8*, 0x8C) = 1;
                M2C_FIELD(arg0, u8*, 6) += 1;
            }
        } else if ((M2C_FIELD(arg0, s8*, 2) == 0) ||
                   ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
                    (func_801EC1F8(arg0) == 0) && (func_801EBEDC(arg0) == 0))) {
            if (!(M2C_FIELD(arg0, u16*, 0x7C) & 8) &&
                (func_80039CFC(arg0) != 0)) {
                func_8003AE8C(arg0);
                return;
            }
            func_80017A04(arg0);
            temp_v1 = M2C_FIELD(arg0, s8*, 6);
            if (temp_v1 == 0) {
                if ((M2C_FIELD(arg0, s8*, 0x8F) != 0) &&
                    (M2C_FIELD(arg0, s8*, 2) == 0)) {
                    temp_s0 = M2C_FIELD(arg0, s8*, 0x44);
                    func_8003BB94(arg0, 0x6D,
                                  M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
                    M2C_FIELD(arg0, s8*, 0x44) = temp_s0;
                }
                if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                    M2C_FIELD(arg0, u8*, 6) += 1;
                }
            } else if (temp_v1 == 1) {
                func_8003CD00(arg0);
                if ((M2C_FIELD(arg0, s8*, 0x8F) != 0) &&
                    (M2C_FIELD(arg0, s8*, 2) == 0)) {
                    temp_v1 = M2C_FIELD(arg0, s8*, 0x96);
                    if ((temp_v1 == 0x12) || (temp_v1 == 0x14) ||
                        (temp_v1 == 0x2E) || (temp_v1 == 0x13) ||
                        (temp_v1 == 0x2B)) {
                        func_8003BA04(arg0, 0x8B);
                    } else {
                        func_8003BA04(arg0, 0x6C);
                    }
                } else if ((M2C_FIELD(arg0, s8*, 0x8E) == 0) &&
                           (M2C_FIELD(arg0, s8*, 2) == 0)) {
                    func_8003BB94(arg0, 0x51, 2);
                }
                if (!(M2C_FIELD(arg0, u16*, 0x7C) & 8)) {
                    if ((M2C_FIELD(arg0, s32*, 0x8C) & 0xFFFF0000) &&
                        (M2C_FIELD(arg0, s8*, 2) == 0)) {
                        func_8003BA04(arg0, 0x6E);
                    } else {
                        func_8003BA04(arg0, 0x52);
                    }
                    M2C_FIELD(arg0, u8*, 6) = 2;
                }
            } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                func_8003AD18(arg0);
            }
        }
    }
}
