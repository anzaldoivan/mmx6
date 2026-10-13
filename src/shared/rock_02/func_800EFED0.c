#include "common.h"
#include "mmx6/x4.h"

void func_8002F288();
void func_800F1388();
extern void (*D_800FB198[])(struct X4_MainObj*);

void func_800EFED0(struct X4_MainObj* arg0) {
    if (arg0->unk2 == 1) {
        func_800F1388();
        return;
    }
    arg0->unk18.val = arg0->x_pos.val;
    arg0->on_screen = 0;
    arg0->unk1C.val = arg0->y_pos.val;
    D_800FB198[arg0->state](arg0);
    func_8002F288(arg0);
}
