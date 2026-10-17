#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();
extern s16 D_800970AE;

void func_800F4A04(void* arg0) {
    // !FAKE: arm value in v0 as retail
    register s32 var_v0 asm("$2");
    // !FAKE: field value in v0 as retail
    register s32 temp_v0_2 asm("$2");
    u16 temp_v0_3;

    func_80017A04();
    {
        // !FAKE: load lands in v0 as retail
        register s32 temp_v0 asm("$2");
        temp_v0 = M2C_FIELD(arg0, u8*, 0x93);
        M2C_FIELD(arg0, u8*, 0x93) = temp_v0 + 1;
        if ((s8)temp_v0 >= 0x33) {
            temp_v0_2 = M2C_FIELD(arg0, s32*, 0x20);
            if (temp_v0_2 == 0) {
                temp_v0_2 = M2C_FIELD(arg0, s32*, 0x24);
                if (temp_v0_2 < 0) {
                    M2C_FIELD(arg0, s16*, 0x90) = 0;
                } else {
                    var_v0 = 1;
                    // !FAKE: shared store block with the nonzero arm, as retail lays it out
                    goto block_6;
                }
            } else {
                if (temp_v0_2 < 0) {
                    var_v0 = 2;
                } else {
                    var_v0 = 3;
                }
            block_6:
                M2C_FIELD(arg0, s16*, 0x90) = var_v0;
            }
            temp_v0_3 = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, u8*, 0x93) = 0;
            M2C_FIELD(arg0, u16*, 0x94) = temp_v0_3;
            if ((s16)temp_v0_3 >= D_800970AE) {
                func_800179A4(arg0, 0x13);
            }
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}
