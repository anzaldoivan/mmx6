#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F862C(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_v1 == 1) {
        register s32 flag asm("$2");

        func_800179A4(arg0, 0x10);
        flag = M2C_FIELD(arg0, u8*, 0x15);
        if (flag == 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s16*, 0xA) = D_800971F8[0].x_pos.i.hi + 0x40;
            M2C_FIELD(arg0, s16*, 0xE) = D_800971F8[0].y_pos.i.hi + 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s16*, 0xA) = D_800971F8[0].x_pos.i.hi + 0x100;
            M2C_FIELD(arg0, s16*, 0xE) = D_800971F8[0].y_pos.i.hi + 0x40;
        }
        M2C_FIELD(arg0, u8*, 6)++;
    } else if (temp_v1 == 2) {
        func_80016C48(2, 0x59, arg0);
    }
}
