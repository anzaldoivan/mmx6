#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80013BD0(s32, s32);
M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3);
extern u8 D_80097427;
extern M2C_UNK* D_800B91B8;
extern struct X4_MiscObj D_800E2F90;

void func_800EA9D0(u8* arg0) {
    s32 k;
    struct X4_QuadObj* q;
    s8* obj;

    ((void (*)())reset_level)();
    {
        s32 b;

        b = (s32)D_800B91B8;
        *(s32*)&D_800E2F90 = b;
        D_800E2F90.y_pos.val = b + 0x200;
        func_80013BD0(b, b + 0x1FFC);
    }
    D_80097427 = 0;
    D_800E2F90.x_pos.bytes[1] = 0;
    D_800E2F90.unk6 = 0;
    func_800ED50C(0x24, 0, 0x130, 0x30);
    k = 0x10;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = k;
        q->unk2 = k;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        *(s16*)(obj + 0xA) = 0xE0;
        *(s16*)(obj + 0xE) = 0x58;
        obj[1] = 0x2E;
        obj[2] = -0x10;
    }
    arg0[3] = 0;
    D_800E2F90.x_pos.bytes[2] = 3;
    arg0[1] = arg0[1] + 1;
}
