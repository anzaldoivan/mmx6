#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800EBB70(u8* arg0, u8 arg1);

void func_800EB870(void* arg0) {
    s32 s;
    s32 c;

    F32(SPAD, 0x80) += F32(SPAD, 0x84);
    F32(SPAD, 0x80) &= 0xFFF;
    s = (rcos(F32(SPAD, 0x80)) << 4) >> 12;
    c = (rsin(F32(SPAD, 0x80)) << 4) >> 12;
    F16(arg0, 0xA) = F16(SPAD, 0x8A) + s;
    F16(arg0, 0xE) = F16(SPAD, 0x8C) - c;
    if (--F16(arg0, 0x7C) == 0) {
        F16(arg0, 0x7C) = 0x14;
        play_sound(2, 5, arg0);
        func_800EBB70(arg0, 0);
        if (--F16(arg0, 0x7E) == 0) {
            FU8(arg0, 0x5) = 2;
            FU8(arg0, 0x6) = 0;
        }
    }
}
