#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8003D480(M2C_UNK, s8, s8, void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_801F2000(struct X4_WeaponObj* arg0) {
    if (--F_S16(arg0, 0x8E) == 0) {
        F_S16(arg0, 0x8E) = 0x14;
        if (func_8003D480(arg0->active, arg0->id, 0x10, arg0) != 0) {
            arg0->unk6++;
        }
        if (++F_S8(arg0, 0x8C) >= 0xA) {
            arg0->state = 2;
        }
    }
}
