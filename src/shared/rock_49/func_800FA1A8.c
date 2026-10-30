#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
struct X4_QuadObj* alloc_class6_slot(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA1A8(struct X4_BackgroundObj* arg0) {
    u8* q = (u8*)alloc_class6_slot();
    if (q != 0) {
        q[0] = 1;
        q[1] = 0xA;
        q[0x36] = 0x11;
        q[2] = 1;
    }
    background_objects[2].unk3 = 1;
    background_objects[1].unk3 = 0;
    background_objects[0].unk3 = 0;
    ((void (*)())func_800139A0)(8, q);
    arg0->unk1++;
}
