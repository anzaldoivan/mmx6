#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */
extern M2C_UNK D_80101A40;
extern M2C_UNK D_80101A4C;
extern M2C_UNK D_80101A58;

void func_80100D30(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFD0000;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_80101A40;
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_80101A4C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, M2C_UNK**, 0x68) = &D_80101A58;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
