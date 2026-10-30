#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017B04(u8*, s16, s16);
#define func_80017B04 func_80017B04
M2C_UNK clear_object_slot();
extern s8 D_800970A2;

#define SCRATCH_14 (*(u8**)0x1F800014)
#define OFS(o) (SCRATCH_14 + *(s32*)(SCRATCH_14 + (o)))

void func_8004AF94(struct X4_VisualObj* arg0) {
    s32 big;

    big = 0;
    if (arg0->unk2 == 0) {
        arg0->unk38 = OFS(0x8);
    } else if (arg0->unk2 == 1) {
        arg0->unk38 = OFS(0x40);
    } else if (arg0->unk2 == 2) {
        if (D_800970A2 != 0) {
            arg0->unk38 = OFS(0xC);
        } else {
            arg0->unk38 = OFS(0x14);
        }
    } else if (arg0->unk2 == 3) {
        arg0->unk38 = OFS(0x44);
    } else if (arg0->unk2 == 4) {
        arg0->unk38 = OFS(0x20);
    } else if (arg0->unk2 == 5) {
        arg0->unk38 = OFS(0x8);
    } else if (arg0->unk2 == 6) {
        arg0->unk38 = OFS(0xC);
        big = 1;
    } else if (arg0->unk2 == 7) {
        arg0->unk38 = OFS(0x10);
        big = 1;
    } else if (arg0->unk2 == 8) {
        arg0->unk38 = OFS(0x3C);
        big = 1;
    } else if (arg0->unk2 == 9) {
        arg0->unk38 = OFS(0x34);
    } else if (arg0->unk2 == 10) {
        arg0->unk38 = OFS(0x1C);
    } else if (arg0->unk2 == 11) {
        arg0->unk38 = OFS(0x2C);
    } else if (arg0->unk2 == 12) {
        arg0->unk38 = OFS(0x24);
    }
    arg0->previous_animation_index = 0xFF;
    arg0->animation_step.fields.frame_index = 0;
    if (big == 0) {
        arg0->unk40 = 0x520;
        arg0->unk49 = 0;
        func_80017B04(arg0, 0x140, 0x20);
    } else {
        arg0->unk40 = 0x540;
        arg0->unk49 = 1;
        func_80017B04(arg0, 0x140, 0x40);
    }
    ((M2C_UNK(*)())clear_object_slot)(arg0);
}
