#include "common.h"
#include "mmx6/x4.h"

void* func_8002C458();

void func_800ECAA0(struct X4_MainObj* arg0) {
    struct X4_MainObj* temp_v0;

    temp_v0 = func_8002C458();
    if (temp_v0 != 0) {
        temp_v0->active = 0x41;
        temp_v0->id = 0x11;
        temp_v0->unk2 = 0;
        temp_v0->unk40 = arg0->unk40;
        temp_v0->unk42 = arg0->unk42;
        temp_v0->animation_table = arg0->animation_table;
        temp_v0->sprite_frames = arg0->sprite_frames;
        temp_v0->bg_offset = arg0->bg_offset;
        temp_v0->unk15 = arg0->unk15;
        temp_v0->x_pos = arg0->x_pos;
        temp_v0->y_pos = arg0->y_pos;
        *(void**)&temp_v0->unk7C = arg0;
        temp_v0->unk16 = 6;
    }
}
