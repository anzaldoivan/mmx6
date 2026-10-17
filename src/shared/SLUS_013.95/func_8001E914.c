#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80013DE8(); /* extern */
extern u8 D_800CC868;
extern u16 D_800E3142;

void func_8001E914(void* arg0) {
    s32* var_a0;
    s32* var_v1;
    s32 var_a1;
    u8* tblD2;
    u8* tbl168;

    func_80013DE8();
    M2C_FIELD(arg0, s8*, 0x1D) = 0;
    M2C_FIELD(arg0, s8*, 0x1E) = 0;
    D_800CC868 = 0;
    D_800E3142 = 0;
    if ((M2C_FIELD(arg0, s8*, 0xC) < 0x13) &&
        (M2C_FIELD(arg0, s8*, 0xD) == 0)) {
        tblD2 = (u8*)arg0 + 0xD2;
        tbl168 = (u8*)arg0 + 0x168;
        var_a0 = (s32*)((u8*)arg0 + 0x118);
        var_v1 = (s32*)((u8*)arg0 + 0xD8);
        var_a1 = 0xF;
        M2C_FIELD(arg0, s32*, 0x90) = 0;
        M2C_FIELD(arg0, s32*, 0x460) = 0;
        M2C_FIELD(arg0, s32*, 0x94) = 0;
        M2C_FIELD(arg0, s32*, 0x98) = 0;
        M2C_FIELD(arg0, s16*, 0x9C) = 0;
        M2C_FIELD(arg0, s32*, 0x43C) = 0;
        M2C_FIELD(arg0, u8*, 0xC8) = M2C_FIELD(arg0, u8*, 0x69);
        do {
            *var_a0++ = *var_v1++;
            var_a1 -= 1;
        } while (var_a1 >= 0);
        {
            s32 off = M2C_FIELD(arg0, s8*, 0x38) * 2;
            M2C_FIELD(arg0, u16*, 0xD6) = *(u16*)(tblD2 + off);
        }
        M2C_FIELD(arg0, u8*, 0x43A) = tbl168[M2C_FIELD(arg0, s8*, 0xC)];
    }
    M2C_FIELD(arg0, s8*, 0) = 9;
}
