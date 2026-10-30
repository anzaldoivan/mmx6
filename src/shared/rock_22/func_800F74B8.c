#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
void* func_8002C458();
s32 random_byte();
extern u8 D_800CCF38;
extern void (*D_800FD014[])(void*);

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800F74B8(u8* arg0) {
    u8* parent;
    u8* c;

    parent = FP(arg0, 0x84);
    ((void (*)())func_80017A04)();
    if (D_800CCF38 >= 2 && FU8(parent, 0x8D) != F8(arg0, 2) + 2) {
        if (FU8(arg0, 0x93) != 0) {
            FU8(arg0, 0x93)--;
        } else {
            c = func_8002C458();
            if (c != 0 && !(random_byte() & 1)) {
                FU8(c, 0) = 0x41;
                FU8(c, 1) = 0x1E;
                FU8(c, 2) = 0xA;
                FU16(c, 0x42) = FU16(arg0, 0x42) & 0x7FFF;
                F32(c, 0x30) = F32(arg0, 0x30);
                F32(c, 0x3C) = F32(arg0, 0x3C);
                FU16(c, 0x40) = FU16(arg0, 0x40);
                FU8(c, 0x14) = FU8(arg0, 0x14);
                FU16(c, 0xA) = FU16(arg0, 0xA);
                FU16(c, 0xE) = FU16(arg0, 0xE);
                FU8(c, 0x15) = FU8(arg0, 0x15);
                FP(c, 0x7C) = arg0;
            }
            FU8(arg0, 0x93) = (random_byte() & 3) * 0x10 + 0x60;
        }
    }
    if (FU8(parent, 0x8E) != 0) {
        if (F16(arg0, 0x7C) != 0) {
            F16(arg0, 0x7C)--;
        }
    } else {
        D_800FD014[F8(arg0, 6)](arg0);
    }
}
