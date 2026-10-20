#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D654(s8*, u8*);
#define M2C_UNK s32
extern M2C_UNK D_800970A0;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EC780(s8* arg0) {
    u8* p = (u8*)&D_800970A0;
    u16 v;
    u16 w;

    if (func_8002D654(arg0, p) != 0) {
        if (arg0[2] == 2) {
            v = FU16(p, 0xA);
            FU16(arg0, 0x7C) = 0;
            arg0[5] = 3;
            arg0[6] = 0;
            FU16(arg0, 0x84) = v;
            return;
        }
        w = FU16(p, 0xA);
        arg0[5] = 2;
        arg0[6] = 0;
        FU16(arg0, 0x84) = w;
    }
}
