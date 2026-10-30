#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
extern struct X4_PlayerObj g_Player;
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_8004B3A0(struct X4_VisualObj* arg0) {
    u8* sp;

    if (g_Player.unk5 != 0x23) {
        ((M2C_UNK(*)())clear_object_slot)();
        return;
    }
    if (arg0->state == 0) {
        sp = SCRATCH_1C;
        arg0->unk3C = sp + *(s32*)(sp + 0x1C);
        arg0->unk40 = 0x500;
        arg0->unk42 = 0x7802;
        arg0->unk16 = 3;
        arg0->unk5C.value = 0;
        arg0->state++;
    }
    arg0->animation_step.fields.frame_index =
        g_Player.animation_step.fields.frame_index - 0x42;
    arg0->unk15 = g_Player.unk15;
    arg0->x_pos = g_Player.x_pos;
    arg0->y_pos = g_Player.y_pos;
    if (arg0->unk5C.value == 0) {
        arg0->unk5C.value = 8;
    } else {
        arg0->unk5C.value--;
    }
    func_8002CCB0(arg0, 0x28, 0x28);
}
