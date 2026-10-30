#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80013BD0(s32, s32);
M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_80097427;
extern M2C_UNK* D_800B91B8;
extern struct X4_MiscObj D_800E2F90;

void func_800EB1CC(u8* arg0) {
    u8* bg;
    s32 k;
    struct X4_QuadObj* q;
    s8* obj;

    reset_level();
    {
        s32 base;

        bg = (u8*)background_objects;
        *(s16*)(bg + 0xB2) = 0x200;
        base = (s32)D_800B91B8;
        bg[0xF4] = 1;
        *(s32*)&D_800E2F90 = base;
        D_800E2F90.y_pos.val = base + 0x200;
        func_80013BD0(base, base + 0x1FFC);
    }
    D_80097427 = 0;
    D_800E2F90.x_pos.bytes[1] = 1;
    func_800F03B8(0x24, 0, 0x130, 0x30);
    k = 0x10;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = k;
        q->unk2 = k;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        *(s16*)(obj + 0xA) = 0xE0;
        *(s16*)(obj + 0xE) = 0x58;
        obj[0] = 1;
        obj[1] = 0x2E;
        obj[2] = -0x10;
    }
    arg0[3] = 0;
    D_800E2F90.unk6 = 0;
    D_800E2F90.x_pos.bytes[2] = 3;
    arg0[1] = arg0[1] + 1;
}
