#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04(void*);          /* extern */
extern s16 D_800970AA;

void func_800EE82C(void* arg0) {
    if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) > 0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    }
    func_800179A4(arg0, 1);
    func_80017A04(arg0);
    M2C_FIELD(arg0, s16*, 0x7E) = 0x20;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFE0000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
