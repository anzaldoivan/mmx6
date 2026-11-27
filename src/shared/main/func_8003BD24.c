#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_UnkObj D_800972F8[3];
extern u32* D_8007789C[];
extern u8 D_800911A8[];
extern u16 D_80073CEC[];
extern u8 D_801EF6D0[];
extern u8 D_801F4AD4[];

s32 func_800179A4(void*, s32);
void func_8002ABA8();
struct X4_VisualObj* func_8002C398(void);
void func_8003C4EC();
void func_8003DF58(void*);
void func_8003F0BC(void*);

#define PL(T, o) (*(T*)((u8*)p + (o)))
#define EN(T, o) (*(T*)((u8*)e + (o)))
#define ENG(T, o) (*(T*)((u8*)e2 + (o)))
#define UO(T, i, o) (*(T*)((u8*)u + (o)))
#define SO(T, i, o) (*(T*)((u8*)q + (o)))
#define SCR14 (*(u8**)0x1F800014)
#define SCR1C (*(u8**)0x1F80001C)

void func_8003BD24(void) {
    u8* prev;
    s32 x;
    u8* q;
    u8* u;
    u8* t;
    s32 off;
    u8* t14;
    u8* tl;
    s32 offl;
    u8* tc;
    s32 offc;
    u32 i;
    u8 v;
    s8* tbl;
    struct X4_VisualObj* vis;
    struct X4_PlayerObj* p;
    struct X4_EngineObj* e;
    struct X4_EngineObj* e2;

    p = &D_800970A0;
    e = &D_800CCED0;

    PL(u8, 0x0) = 1;
    PL(u8, 0x3) = 0;
    PL(s32, 0xF0) = 0x8000;
    PL(u8, 0x14) = 0;
    PL(u8, 0xE5) = 0;
    PL(s32, 0xF4) = 0x20000;
    PL(s32, 0xF8) = 0x5D000;
    PL(s32, 0x134) = 0x4200;
    PL(s32, 0xFC) = 0xFFF98000;
    PL(s32, 0x100) = 0x4200;
    PL(s32, 0x104) = 0x68000;
    PL(s32, 0x108) = 0x42000;
    PL(s32, 0x10C) = -0x3000;
    PL(s32, 0x110) = 0xFFFE9000;
    PL(s32, 0x114) = 0x5A000;
    PL(s32, 0x118) = 0x10000;
    PL(s32, 0x11C) = 0x18000;
    PL(u8, 0x2) = EN(u8, 0x38);
    PL(s32, 0x120) = 0x20000;
    PL(s32, 0x124) = 0x20000;
    PL(s32, 0x128) = 0x18000;
    PL(s32, 0x12C) = 0x42000;
    PL(s32, 0x130) = 0x42000;
    switch (EN(s8, 0x1E)) {
    case -2:
    case 0:
        i = 0;
        v = *((u8*)e + PL(s8, 0x2) + 0x5B);
        tbl = (s8*)e + 0x61;
        x = tbl[PL(s8, 0x2)];
        PL(u8, 0x5C) = v;
        PL(u8, 0x5D) = v;
        PL(u8, 0x5E) = v;
        PL(u16, 0x14A) = x * 6;
        for (; i < 16; i++) {
            PL(u16, 0xA8 + i * 2) = PL(u16, 0x14A);
        }
        break;
    case -1:
        i = 0;
        tbl = (s8*)e + 0x61;
        PL(u8, 0x5E) = PL(u8, 0x5D) = PL(u8, 0x5C) = EN(u8, 0x5A);
        for (; i < 16; i++) {
            PL(u16, 0xA8 + i * 2) = EN(u16, 0x3A + i * 2);
        }
        PL(u8, 0x93) = EN(u8, 0x5D);
        PL(u16, 0x14A) = tbl[PL(s8, 0x2)] * 6;
        func_8003F0BC(p);
        func_8003DF58(p);
        break;
    }
    if (PL(s8, 0x2) == 0) {
        PL(void*, 0x30) = D_801F4AD4;
    } else {
        PL(void*, 0x30) = D_801EF6D0;
    }
    t14 = SCR14;
    PL(u8*, 0x38) = t14 + *(s32*)t14;
    t = SCR1C;
    off = *(s32*)t;
    PL(u16, 0x40) = 0x500;
    PL(u8, 0x16) = 2;
    PL(u16, 0x42) = 0x7800;
    PL(u8, 0x49) = 3;
    t += off;
    PL(u8*, 0x3C) = t;
    func_8003C4EC(p);
    func_8002ABA8();
    u = (u8*)D_800972F8;
    for (i = 0; i < 3; i++) {
        UO(u8, i, 0x0) = 0x11;
        UO(u8, i, 0x2) = i;
        UO(u8, i, 0x14) = PL(u8, 0x14);
        UO(void*, i, 0x38) = PL(void*, 0x38);
        UO(void*, i, 0x3C) = PL(void*, 0x3C);
        UO(u16, i, 0x40) = PL(u16, 0x40);
        UO(u16, i, 0x42) = D_80073CEC[(s8)i];
        UO(u8, i, 0x16) = 4;
        if (i != 0) {
            UO(void*, i, 0x50) = prev;
        } else {
            UO(void*, i, 0x50) = &D_800970A0;
        }
        prev = u;
        u += 0x60;
    }
    q = D_800911A8;
    for (i = 0; i < 2; i++) {
        SO(u8, i, 0x0) = 0x21;
        SO(u8, i, 0x2) = i;
        SO(u8, i, 0x14) = PL(u8, 0x14);
        SO(void*, i, 0x38) = 0;
        tl = SCR1C;
        offl = *(s32*)(tl + 0x70);
        SO(void*, i, 0x30) = D_8007789C;
        SO(u16, i, 0x40) = 0;
        SO(u16, i, 0x42) = 0x7802;
        SO(u8, i, 0x16) = 2;
        SO(u8, i, 0x15) = 0;
        SO(u8*, i, 0x3C) = tl + offl;
        q += 0x50;
    }
    if (PL(s8, 0x2) == 0) {
        e2 = &D_800CCED0;
        if (ENG(u8, 0x5E) == 1) {
            u8* qa;
            SO(u8, 2, 0x0) = 0x21;
            SO(u8, 2, 0x2) = 3;
            SO(void*, 2, 0x38) = 0;
            SO(u8, 2, 0x14) = PL(u8, 0x14);
            tc = SCR1C;
            offc = *(s32*)(tc + 0x20);
            SO(void*, 2, 0x30) = D_8007789C;
            SO(u16, 2, 0x40) = 0;
            SO(u16, 2, 0x42) = 0x7802;
            SO(u8, 2, 0x16) = 2;
            SO(u8, 2, 0x15) = 0;
            SO(u8, 2, 0x3) = 0;
            SO(u8*, 2, 0x3C) = tc + offc;
            func_800179A4(q, 0x2A);
        }
    }
    if (EN(s8, 0xC) == 6) {
        for (i = 0; i < 4; i++) {
            vis = func_8002C398();
            if (vis != 0) {
                vis->active = 0x41;
                vis->id = 7;
                vis->unk2 = i;
            }
        }
    }
    D_800971F8[0].unk44 = 0;
    D_800971F8[1].unk44 = 0;
    D_800971F8[2].unk44 = 0;
}
#undef PL
#undef EN
#undef ENG
#undef UO
#undef SO
#undef SCR14
#undef SCR1C
