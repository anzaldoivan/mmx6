#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800186A8(); /* extern */
extern u8 D_8008EAFC;
extern u8 D_800C4570;
extern u8 D_800CD40C;

void func_800EA3F8(void* arg0) {
    if (D_800C4570 != 0) {
        func_800186A8();
    }
    if (D_8008EAFC == 0) {
        func_800186A8();
        if ((D_800CD40C == 0) && (M2C_FIELD(arg0, s16*, 0xA) != 0)) {
            M2C_FIELD(arg0, s16*, 0xA) =
                (s16)((u16)M2C_FIELD(arg0, s16*, 0xA) - 1);
            M2C_FIELD(arg0, s8*, 3) = 0;
            M2C_FIELD(arg0, u16*, 8) = (u16)(M2C_FIELD(arg0, u16*, 8) + 1);
        }
    }
}
