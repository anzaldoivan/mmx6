#include "common.h"
#include "mmx6/x4.h"

void* enemy_slot_alloc();
s32 random_byte();
extern u8 D_80078860[];
extern u8 D_800788F0[];
extern u8 D_800CCF38;

// 0x8004E680 drop_item: item drop; off on Xtreme.
// basis: community tweaks-index.tsv:271
// callers: func_8004E654, func_800F259C, func_800F3444
// str 0x800788F0 sha1=7b10bb32ce7696f0a4aca07d87c2b471482a6437 = "printable byte run: data, not text"
void drop_item(struct X4_BaseObj* arg0, s8 arg1, s16 arg2, s16 arg3) {
    u8 i;
    u8 idx;
    u32 r;
    struct X4_MainObj* obj;

    if (D_800CCF38 < 2) {
        idx = arg1 * 6;
        r = random_byte();
        i = -1;
        do {
            i++;
            r &= 0xFF;
            r = (u16)(r - D_80078860[i + idx]);
        } while (r < 0x100);
        if (i != 0) {
            obj = enemy_slot_alloc();
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
