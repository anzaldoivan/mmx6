#include "common.h"
#include "mmx6/x4.h"

void func_80039228(void* arg0);
void func_80039DFC(void* arg0);
void func_80039F78(void* arg0);
void func_8003A1C8(void* arg0);
void func_8003A268(void* arg0);
void func_8003C3C8(void* arg0);
void func_8003CE38(struct X4_PlayerObj* self);
void func_8003EC78(void* arg0);
void func_8003F048(void* arg0);
extern void (*D_80073ACC[])(struct X4_PlayerObj*);
extern struct X4_EngineObj D_800CCED0;

#define PB(o) (*(s8*)((u8*)p + (o)))
#define PU(o) (*(u8*)((u8*)p + (o)))

void func_80034FBC(struct X4_PlayerObj* p) {
    s32 d = PU(0xD0);
    s32 f = (u8)D_800CCED0.unkF;
    s32 d4 = PU(0xD4);
    s32 t = PU(0x71);

    PB(0x8F) = 0;
    PB(0x90) = 0;
    PB(0xCF) = 0;
    PB(0xDD) = 0;
    PU(0xD3) = d | f | d4;
    PU(0x89) = PU(0x70) | t;
    if (D_800CCED0.unk10 == 0) {
        if (PU(0xE5) != 0) {
            PU(0xE5)--;
        }
        func_80039228(p);
        if (PB(0x5C) == 0) {
            return;
        }
        if (PU(0x92) != 0) {
            PU(0x92)--;
        }
        if (PU(0x91) != 0) {
            if (--PU(0x91) == 0) {
                PB(0x90) = 1;
                PB(0x8E) = 0;
            }
        }
        if (PB(0x8D) > 0) {
            if (--PB(0x8D) == 0) {
                PB(0x8D) = -1;
            }
        }
        func_8003A1C8(p);
        func_8003A268(p);
        func_80039F78(p);
        func_80039DFC(p);
        func_8003F048(p);
        D_80073ACC[p->unk5](p);
        PB(0x71) = 0;
        PB(0x72) = 0;
        PB(0x4A) = 0;
    }
    if (D_800CCED0.unk10 != 2) {
        func_8003EC78(p);
        func_8003CE38(p);
        func_8003C3C8(p);
    }
}

#undef PB
#undef PU
