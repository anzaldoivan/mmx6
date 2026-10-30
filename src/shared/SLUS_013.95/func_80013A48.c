#include "common.h"

#define M2C_UNK s32

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
extern M2C_UNK D_80013788;
extern s8 D_80090C8D;
extern s8 D_80097425;

void func_80013A48(s8 arg0) {
    D_80097425 = 1;
    if (arg0 < 0) {
        D_80090C8D = -arg0;
        create_task(3, &D_80013788);
        return;
    }
    D_80090C8D = arg0;
}
