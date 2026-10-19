#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80013300(M2C_UNK, M2C_UNK*);
M2C_UNK func_800133A0();
void func_800186A8();
extern M2C_UNK D_8001D0E4;
extern s32 D_8008EC0C;
extern s8 D_80097424;
extern M2C_UNK D_800CD3F8;
extern s8 D_800F2246;

void func_800ECA88(void) {
    if (D_80097424 == 0) {
        M2C_FIELD(&D_800CD3F8, s8*, 0) = 3;
        M2C_FIELD(&D_800CD3F8, s8*, 1) = 0;
        M2C_FIELD(&D_800CD3F8, s8*, 2) = 0;
        M2C_FIELD(&D_800CD3F8, s8*, 3) = 0;
        D_800F2246 = 1;
        D_8008EC0C = 0;
        func_800186A8();
        func_80013300(0, &D_8001D0E4);
        func_800133A0();
    }
}
