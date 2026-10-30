#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

void func_800F70B0(void* arg0) {
    set_animation(arg0, 2);
    {
        s32 t = background_objects[0].unk1E - 0x140;
        if (background_objects[0].unk1E +
                (background_objects[0].unk1C - t) / 2 <
            *(s16*)((u8*)arg0 + 0xA)) {
            *(s32*)((u8*)arg0 + 0x20) = 0xFFFC0000;
        } else {
            *(s32*)((u8*)arg0 + 0x20) = 0x40000;
        }
    }
    ((u8*)arg0)[7] = 0;
    *(s32*)((u8*)arg0 + 0x24) = 0;
    ((u8*)arg0)[6] += 1;
}
