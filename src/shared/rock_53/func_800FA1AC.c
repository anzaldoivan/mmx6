#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800E9F7C(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA1AC(u8* arg0) {
    ((void (*)(s32))SetDispMask)(1);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 1;
    background_objects[2].x_pos.val = 0;
    background_objects[2].y_pos.val = 0;
    func_800E9F7C();
    {
        s32 v = arg0[1];
        s32 c = 0x152;
        *(s16*)(arg0 + 8) = c;
        c = 1;
        *(s16*)(arg0 + 0xA) = c;
        arg0[1] = v + 1;
    }
}
