/* Adapted from sozud/mmx4 @29b62af src/main/background.c:func_80027974, AGPL-3.0; proven shared with X6 by exact signature a09eb2b42e5f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_80029598(struct X4_BackgroundObj*);
void func_800295E8(struct X4_BackgroundObj*);
void func_800296A8(struct X4_Unk9*);
void func_8002820C(struct X4_BackgroundObj*);

void func_80029538(struct X4_BackgroundObj* arg0) {
    s32 temp_a1;
    arg0->unk14.val = arg0->x_pos.val;
    temp_a1 = arg0->y_pos.val;
    arg0->unk18.val = temp_a1;
    arg0->unk49 = -arg0->unk48;
    func_80029658(arg0);
    func_80029598(arg0);
    func_800295E8(arg0);
    func_800296A8(arg0);
    func_8002820C(arg0);
}
