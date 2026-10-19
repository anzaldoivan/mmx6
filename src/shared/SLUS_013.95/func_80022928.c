#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
#define SCR_A8 (*(s32*)0x1F8000A8)

M2C_UNK func_80022928(s32 arg0, s32 arg1) {
    func_8002B3D4((arg0 << 4) + 0x1E0, (M2C_UNK*)(SCR_A8 + (arg1 << 9)), 0x10);
}
