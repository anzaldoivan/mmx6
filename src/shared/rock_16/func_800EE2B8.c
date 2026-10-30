#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */
extern s8 D_800CCF02;
extern void (*D_800F126C[])(s8*);

void func_800EE2B8(s8* arg0) {
    if (D_800CCF02 != 0) {
        clear_object_slot();
        return;
    }
    D_800F126C[arg0[4]](arg0);
}
