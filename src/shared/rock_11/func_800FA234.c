#include "common.h"

void* enemy_slot_alloc();
extern u8 D_800FDA78[];

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800FA234(void* arg0, s32 arg1) {
    void* obj;
    u8 id;

    id = arg1;
    obj = enemy_slot_alloc();
    if (obj != 0) {
        UB(obj, 0) = 0x41;
        UB(obj, 1) = 0x3A;
        UB(obj, 0x15) = UB(arg0, 0x15);
        UB(obj, 2) = id;
        UH(obj, 0xA) = UH(arg0, 0xA);
        UH(obj, 8) = 0;
        UH(obj, 0xE) = UH(arg0, 0xE);
        UH(obj, 0xC) = 0;
        UH(obj, 0x42) = UH(arg0, 0x42) & 0x7FFF;
        W(obj, 0x30) = W(arg0, 0x30);
        W(obj, 0x3C) = W(arg0, 0x3C);
        UH(obj, 0x40) = UH(arg0, 0x40);
        UB(obj, 0x14) = UB(arg0, 0x14);
        if (SB(arg0, 2) == 0) {
            P(obj, 0x80) = arg0;
        } else {
            P(obj, 0x80) = P(arg0, 0x80);
        }
        D_800FDA78[id & 0xF] = 1;
    }
}
