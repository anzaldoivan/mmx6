#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3);

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define AB_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define AB_SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800ED87C(void* arg0) {
    struct X4_QuadObj* q;
    void* obj;
    s32 k;

    reset_level();
    func_800ED50C(0x25, 0, 0x130, 0x30);
    k = 0x10;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = k;
        q->unk2 = k;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        AB_B(obj, 0) = 1;
        AB_H(obj, 0xA) = 0xE0;
        AB_H(obj, 0xE) = 0x58;
        AB_B(obj, 1) = 0x2E;
        AB_SB(obj, 2) = -0x10;
    }
    AB_B(arg0, 1)++;
}

#undef AB_B
#undef AB_H
#undef AB_SB
