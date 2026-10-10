#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800F629C;
extern M2C_UNK D_800F62A4;

void func_800F1470(void* arg0) {
    s32 i;
    s32 t;

    if (!(M2C_FIELD(arg0, u8*, 0x90) & 7)) {
        M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x90) & 0xF)) {
        t = M2C_FIELD(arg0, s8*, 2) * 16;
        func_80049EBC(arg0, 1, t, t);
    }
    if (M2C_FIELD(arg0, s16*, 0x90)++ >= 0x79) {
        if (M2C_FIELD(arg0, u8*, 0x96) == 0) {
            for (i = 0; i < M2C_FIELD(arg0, s8*, 2); i++) {
                func_800477E4(6, &D_800F629C, arg0);
            }
        } else {
            for (i = 0; i < M2C_FIELD(arg0, s8*, 2); i++) {
                func_800477E4(6, &D_800F62A4, arg0);
            }
        }
        for (i = 0; i < M2C_FIELD(arg0, s8*, 2) * 4; i++) {
            func_80049EBC(arg0, 1, (s8)M2C_FIELD(arg0, u8*, 2) * 16,
                          (s8)M2C_FIELD(arg0, u8*, 2) * 16);
        }
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
