#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
extern s16 D_800970AA;
extern u8 D_800CCF5F;
extern u8 D_800FA000[];

void func_800FB8EC(void* arg0) {
    u8 tbl[4];

    __builtin_memcpy(tbl, D_800FA000 + 0xC, 4);
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        void* e = func_8002C458();
        if (e != 0) {
            M2C_FIELD(e, u8*, 0) = 0x41;
            M2C_FIELD(e, u8*, 1) = 0x22;
            if (M2C_FIELD(arg0, s16*, 0x7E) == 0) {
                M2C_FIELD(e, u8*, 2) = 0;
            } else {
                M2C_FIELD(e, u8*, 2) = 1;
            }
            M2C_FIELD(e, void**, 0x7C) = arg0;
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if ((s16)++M2C_FIELD(arg0, u16*, 0x7E) == tbl[D_800CCF5F]) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 1);
            M2C_FIELD(arg0, u8*, 0x6)++;
            return;
        }
        ((void (*)(void*, s32))func_800179A4)(arg0, 2);
    }
}
