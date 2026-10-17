#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_8002C9B0();
extern struct X4_PlayerObj D_800970A0;
extern void (*D_800F6CE8[])(void*);

void func_800EED40(struct X4_PlayerObj* arg0) {
    if (D_800970A0.x_pos.i.hi >= 0x1241) {
        if (D_800970A0.y_pos.i.hi >= 0x4F1) {
            func_8002C9B0();
        }
    }
    D_800F6CE8[arg0->state](arg0);
}
