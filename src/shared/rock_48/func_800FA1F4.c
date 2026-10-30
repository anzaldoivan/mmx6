#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA1F4(struct X4_BackgroundObj* arg0) {
    u8* q = (u8*)alloc_class6_slot();
    if (q != 0) {
        q[0] = 1;
        q[1] = 0xA;
        q[0x36] = 0x11;
        q[2] = 1;
    }
    background_objects[2].unk3 = 1;
    background_objects[2].x_pos.i.hi = 0;
    background_objects[2].y_pos.i.hi = 0;
    *(s16*)&arg0->unk4 = 0x3C;
    arg0->unk1++;
}
