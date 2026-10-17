#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;

void func_80049854(struct X4_ShotObj* arg0) {
    struct X4_ShotObj* p;
    s8 v;

    if (arg0->animation_step.fields.event != 0) {
        v = arg0->unk2;
        if (v != 0 && v != 0x2D) {
            p = func_8002C32C();
            if (p != 0) {
                p->active = 0x21;
                p->id = arg0->unk2;
                p->unk2 = 0;
                p->x_pos = arg0->x_pos;
                p->y_pos = arg0->y_pos;
                p->unk15 = arg0->unk15;
                p->unk3C = arg0->unk3C;
                p->animation_table = arg0->animation_table;
                p->unk40 = arg0->unk40;
                p->unk42 = arg0->unk42;
                p->unk16 = arg0->unk16;
                {
                    u8* pl = (u8*)&D_800970A0;
                    pl[0x98]++;
                }
            }
        }
        arg0->unk5++;
    }
    func_8002CCB0(arg0, 0x40, 0x20);
}
