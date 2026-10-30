#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);        /* extern */
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16); /* extern */
extern M2C_UNK D_800F62F0;
extern M2C_UNK D_800F66F0;

void func_800EA4E0(void* arg0) {
    s32 temp_v0;

    if (!(M2C_FIELD(arg0, u16*, 0x16) & 1)) {
        if (M2C_FIELD(arg0, u16*, 0x14) == 0x20) {
            M2C_FIELD(arg0, u16*, 0x14) = 0;
        } else {
            M2C_FIELD(arg0, u16*, 0x14) = 0x20;
        }
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 0x16) - 1;
    M2C_FIELD(arg0, u16*, 0x16) = temp_v0;
    if ((temp_v0 & 0xFFFF) == 0xFFFF) {
        M2C_FIELD(arg0, u16*, 0x14) = 0;
        M2C_FIELD(arg0, u16*, 0x16) = 0;
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    func_8002B54C(&D_800F66F0, &D_800F62F0, 0x200, M2C_FIELD(arg0, u16*, 0x14));
    load_palette(0x93, &D_800F66F0, 0x20);
}
