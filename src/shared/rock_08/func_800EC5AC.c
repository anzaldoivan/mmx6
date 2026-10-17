#include "common.h"
#include "mmx6/x4.h"

extern s8 D_80097174;
extern void (*D_800F5600[])(struct X4_AnimatedObj*);

void func_800EC5AC(struct X4_AnimatedObj* arg0) {
    arg0->unk18.val = arg0->x_pos.val;
    arg0->unk1C.val = arg0->y_pos.val;
    if (D_80097174 != 0) {
        arg0->state = 3;
        return;
    }
    D_800F5600[arg0->state](arg0);
}
