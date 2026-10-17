#include "common.h"
#include "mmx6/x4.h"

void* func_8002BBF4();
s32 func_8002D2D4();
extern u8 D_80078860[];
extern u8 D_800788F0[];
extern u8 D_800CCF38;

void func_8004E680(struct X4_BaseObj* arg0, s8 arg1, s16 arg2, s16 arg3) {
    u8 i;
    u8 idx;
    u32 r;
    struct X4_MainObj* obj;

    if (D_800CCF38 < 2) {
        idx = arg1 * 6;
        r = func_8002D2D4();
        i = -1;
        do {
            i++;
            r &= 0xFF;
            r = (u16)(r - D_80078860[i + idx]);
        } while (r < 0x100);
        if (i != 0) {
            obj = func_8002BBF4();
            if (obj != 0) {
                obj->active = 0x21;
                obj->id = 0x2F;
                obj->unk2 = D_800788F0[i - 1];
                obj->x_pos.i.hi = arg2;
                obj->y_pos.i.hi = arg3;
                obj->bg_offset = arg0->bg_offset;
                obj->backref = 0;
                obj->ext.main_0.flags[0] = 0;
            }
        }
    }
}
