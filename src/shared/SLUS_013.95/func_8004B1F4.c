#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u32* D_8007789C[];
extern struct X4_PlayerObj g_Player;
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK set_animation(void* arg0, M2C_UNK arg1);
M2C_UNK func_80017A04();
M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);

void func_8004B1F4(struct X4_VisualObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    s32 idx;
    u8 f;

    if (arg0->state == 0) {
        s32* frames;
        s32 off;

        arg0->on_screen = 1;
        arg0->unk2 = -1;
        frames = SP_SPRITE_FRAMES;
        off = frames[12];
        arg0->unk40 = 0;
        arg0->animation_table = &D_8007789C;
        arg0->unk16 = 3;
        arg0->unk42 = 0x7802;
        arg0->unk5C.value = 0;
        arg0->state++;
        arg0->unk3C = (void*)((s8*)frames + off);
    }
    f = player->animation_step.fields.frame_index;
    idx = -1;
    if ((u8)(f + 0x35) < 2) {
        idx = 0;
    }
    if ((u8)(f + 0x3D) < 2) {
        idx = 1;
    }
    if ((u8)(f + 0x3B) < 2) {
        idx = 2;
    }
    if ((u8)(f + 0x39) < 2) {
        idx = 3;
    }
    if ((u8)(f + 0x37) < 2) {
        idx = 4;
    }
    if (idx == -1) {
        ((M2C_UNK(*)())clear_object_slot)(arg0);
        return;
    }
    if (idx != arg0->unk2) {
        set_animation(arg0, idx + 0x20);
        arg0->unk2 = idx;
    } else {
        func_80017A04(arg0);
    }
    arg0->unk15 = player->unk15;
    arg0->x_pos = player->x_pos;
    arg0->y_pos = player->y_pos;
    if (arg0->unk5C.value == 0) {
        arg0->unk5C.value = 8;
        play_sound(0, 0x1F, arg0);
    } else {
        arg0->unk5C.value--;
    }
    func_8002CCB0(arg0, 0x28, 0x28);
}
