#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
void* alloc_class3_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

#define SPAD4C (*(u8**)0x1F80004C)

void func_800F527C(struct X4_MainObj* arg0) {
    u8* p;
    s32 t;
    s32 v;
    // !FAKE: depin: dropping it breaks the match (29/65)
    register s16 d asm("$2");

    ((M2C_UNK(*)())func_80017A04)();
    d = arg0->unk7C - 1;
    arg0->unk7C = d;
    if (d == 0) {
        arg0->unk5 = 2;
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x1A;
            *(u16*)(p + 0xA) = *(u16*)((u8*)arg0 + 0xA);
            *(u16*)(p + 0xE) = *(u16*)((u8*)arg0 + 0xE);
            *(u8**)(SPAD4C + 0x80) = p;
        }
    }
    func_8002CCB0(arg0, 0x60, 0x60);
    d = arg0->unk7E - 1;
    arg0->unk7E = d;
    if (d == -1) {
        arg0->unk42 ^= 0x8000;
        arg0->invincibility_timer -= 5;
        if (arg0->invincibility_timer >= 0x1A) {
            arg0->invincibility_timer = 0;
        }
        t = arg0->invincibility_timer;
        v = t < 6;
        if (v) {
            v = 5;
        } else {
            v = t;
        }
        arg0->unk7E = v;
    }
}
