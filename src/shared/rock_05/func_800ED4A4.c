#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800ED4A4(struct X4_MainObj* arg0) {
    if ((u32)((u8)arg0->unk2 - 8) < 2) {
        background_objects[0].unk28 = background_objects[0].unk2A;
        play_sound(5, 1, arg0);
        func_80012D9C(4);
    }
    arg0->unk7C = 0x78;
    arg0->unk6++;
}
