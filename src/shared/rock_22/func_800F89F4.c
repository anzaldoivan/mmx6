#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
M2C_UNK move_object(s32);              /* extern */

void func_800F89F4(void* arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    u8 temp_v1;

    func_80017A04();
    move_object(arg0);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
    if (temp_v0 > 0) {
        temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
        if (temp_v1 & 1) {
            if (temp_v1 & 4) {
                set_animation(arg0, 0x28);
            } else {
                set_animation(arg0, 0x22);
            }
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, u8*, 5) = 5;
            M2C_FIELD(arg0, u8*, 6) = 0;
            M2C_FIELD(arg0, u16*, 0xA) -= 8;
        }
    } else if (temp_v0 < 0) {
        temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
        if (temp_v1 & 2) {
            if (temp_v1 & 4) {
                set_animation(arg0, 0x28);
            } else {
                set_animation(arg0, 0x22);
            }
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, u8*, 5) = 5;
            M2C_FIELD(arg0, u8*, 6) = 0;
            M2C_FIELD(arg0, u16*, 0xA) += 8;
        }
    } else {
        temp_v0_2 = M2C_FIELD(arg0, s32*, 0x24);
        if (temp_v0_2 > 0) {
            temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
            if (temp_v1 & 4) {
                if (temp_v1 & 2) {
                    M2C_FIELD(arg0, u8*, 0x15) = 0;
                    set_animation(arg0, 0x23);
                } else {
                    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                    set_animation(arg0, 0x23);
                }
                M2C_FIELD(arg0, u8*, 5) = 5;
                M2C_FIELD(arg0, u8*, 6) = 0;
                M2C_FIELD(arg0, u16*, 0xE) += 8;
            }
        } else if (temp_v0_2 < 0) {
            temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
            if (temp_v1 & 8) {
                if (temp_v1 & 2) {
                    M2C_FIELD(arg0, u8*, 0x15) = 0;
                    set_animation(arg0, 0x26);
                } else {
                    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                    set_animation(arg0, 0x26);
                }
                M2C_FIELD(arg0, u8*, 5) = 5;
                M2C_FIELD(arg0, u8*, 6) = 0;
                M2C_FIELD(arg0, u16*, 0xE) -= 8;
            }
        }
    }
}
