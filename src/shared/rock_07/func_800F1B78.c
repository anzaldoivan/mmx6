#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04();                        /* extern */
void* func_8002C458();                          /* extern */

void func_800F1B78(void* arg0) {
    void* temp_v0;

    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        temp_v0 = func_8002C458();
        if (temp_v0 != NULL) {
            func_80016C48(2, 0x2E, arg0);
            M2C_FIELD(temp_v0, s8*, 0) = 0x41;
            M2C_FIELD(temp_v0, s8*, 1) = 0x20;
            M2C_FIELD(temp_v0, s32*, 8) = (s32)M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(temp_v0, s32*, 0xC) = (s32)M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(temp_v0, s32*, 0x3C) = (s32)M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(temp_v0, u16*, 0x40) = (u16)M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(temp_v0, u16*, 0x42) = (u16)M2C_FIELD(arg0, u16*, 0x42);
            M2C_FIELD(temp_v0, u8*, 0x14) = (u8)M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(temp_v0, s32*, 0x30) = (s32)M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(temp_v0, u8*, 0x15) = (u8)M2C_FIELD(arg0, u8*, 0x15);
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        func_800179A4(arg0, 1);
        M2C_FIELD(arg0, s8*, 0x83) = 0x78;
        M2C_FIELD(arg0, u8*, 0x80) = (u8)(M2C_FIELD(arg0, u8*, 0x80) & 0xFD);
    }
}
