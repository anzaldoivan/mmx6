#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
void* func_8002C458();

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800ED9B8(void* arg0) {
    void* p;

    func_80017A04();
    if (F8(arg0, 0x45) == 1) {
        p = func_8002C458();
        if (p != 0) {
            FU8(p, 0) = 0x41;
            FU8(p, 1) = 0x1B;
            FU8(p, 2) = 0;
            FU16(p, 0x40) = FU16(arg0, 0x40);
            F16(p, 0x42) = F16(arg0, 0x42) & 0x7FFF;
            F32(p, 0x3C) = F32(arg0, 0x3C);
            FU8(p, 0x14) = FU8(arg0, 0x14);
            F32(p, 8) = F32(arg0, 8);
            F32(p, 0xC) = F32(arg0, 0xC);
            F32(p, 0x30) = F32(arg0, 0x30);
            {
                s32 t = FU8(arg0, 0x15);
                *(void**)((u8*)p + 0x7C) = arg0;
                FU8(p, 0x15) = t;
            }
        }
        FU8(arg0, 6) = FU8(arg0, 6) + 1;
    }
}
