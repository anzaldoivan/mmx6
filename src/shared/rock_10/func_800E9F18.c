#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern u32* D_80095098;
extern u8 D_800FA900[];

#define SCRATCH_20 (*(u8**)0x1F800020)

void func_800E9F18(void* arg0) {
    struct X4_VisualObj* obj = arg0;
    u8* tbl;
    s32 a;
    s8 t;

    obj->state = 1;
    obj->unk6 = 0;
    obj->bg_offset = 0;
    obj->animation_table = (u32**)(D_800FA900 + 0xAFC);
    obj->unk40 = D_80095098[func_8002A47C(0x8B)] >> 7;
    obj->unk42 = (func_8002A47C(0x8B) * 4 + 0x20) % 16 |
                 ((func_8002A47C(0x8B) + 8) / 4 + 0x1E0) << 6;
    a = func_8002A47C(0x8B);
    tbl = SCRATCH_20;
    obj->unk3C = tbl + *(s32*)(tbl + a * 4);
    t = obj->unk2;
    if (t == 5) {
        obj->unk16 = t;
    } else {
        obj->unk16 = 0x11;
    }
    set_animation(obj, obj->unk2);
}
