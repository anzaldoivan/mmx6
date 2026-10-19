#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCED3;
extern s16 D_800F0F60[];

void func_800EF878(void* arg0) {
    s16* p;
    s16* tbl;

    tbl = D_800F0F60;
    p = &tbl[(s8)D_800CCED3];
    if (M2C_FIELD(arg0, s16*, 0xA) < *p) {
        M2C_FIELD(arg0, s16*, 0xA) += 4;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = *p;
    }
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 3) = 1;
}
