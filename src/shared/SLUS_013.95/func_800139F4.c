#include "common.h"

#define M2C_UNK s32

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
#include "mmx6/state.h"
extern s8 D_800C8861;
void func_80013530(void);

M2C_UNK func_800139F4(M2C_UNK a0) {
    s8 arg0 = a0;

    if (D_80097420.transition.active == 0) {
        D_80097420.transition.active = -1;
        D_800C8861 = arg0;
        create_task(2, &func_80013530);
    }
}
