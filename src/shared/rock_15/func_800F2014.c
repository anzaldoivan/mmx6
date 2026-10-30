#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern void (*D_800F70D0[])(void*, void*);

void func_800F2014(struct X4_AnimatedObj* arg0) {
    struct X4_AnimatedObj* p;
    s8 v;
    s8 w;

    p = M2C_FIELD(arg0, struct X4_AnimatedObj**, 0x50);
    M2C_FIELD(arg0, u8*, 0x47) = M2C_FIELD(p, u8*, 0x47);
    arg0->unk15 = p->unk15;
    arg0->unk38 = p->unk38;
    arg0->unk3C = p->unk3C;
    arg0->unk18 = arg0->x_pos;
    arg0->unk1C = arg0->y_pos;
    if (arg0->state == 0) {
        v = p->unk7;
        if (v != 0) {
            if (v > 0) {
                arg0->on_screen = 1;
                M2C_FIELD(arg0, s16*, 0x54) = 3;
                M2C_FIELD(arg0, s16*, 0x56) = 8;
                M2C_FIELD(arg0, s16*, 0x58) = 0xA;
                arg0->x_pos = p->x_pos;
                arg0->y_pos = p->y_pos;
                arg0->state = 1;
                arg0->unk5 = 0;
            } else {
                p->unk7 = 0;
            }
        }
    } else {
        w = p->unk7;
        if (w == 0) {
            arg0->on_screen = 0;
            arg0->state = 0;
        } else if (w == 0xA) {
            arg0->state = w;
        } else {
            D_800F70D0[arg0->unk5](arg0, p);
        }
    }
    if (p->state == 2 || arg0->state == 0xA) {
        clear_object_slot(arg0);
    }
}
