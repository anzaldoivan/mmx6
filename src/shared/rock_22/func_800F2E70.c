#include "common.h"
#define M2C_UNK s32

#define SPAD (*(u8**)0x1F80004C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_80017A04();
void* func_8002C458();
s32 random_byte();
void set_velocity_from_angle(void*, s32);
extern s16 D_800FC6D8[];

void func_800F2E70(u8* arg0) {
    u8* p;
    s32 i;

    if (F8(arg0, 0x46) < 0) {
        F8(arg0, 5) = 2;
        F8(arg0, 6) = 0;
        F8(SPAD, 0x80) = random_byte() & 1;
        return;
    }
    if (F8(arg0, 0x45) != 0) {
        p = func_8002C458();
        if (p != 0) {
            F8(p, 0) = 0x41;
            F8(p, 1) = 0x24;
            i = (FU8(SPAD, 0x81) * 2) & 0xFF;
            F16(p, 0xA) = F16(arg0, 0xA) + D_800FC6D8[i];
            F16(p, 0xE) = F16(arg0, 0xE) + D_800FC6D8[i | 1];
            F32(p, 0x30) = F32(arg0, 0x30);
            F16(p, 0x40) = F16(arg0, 0x40);
            F32(p, 0x3C) = F32(arg0, 0x3C);
            F16(p, 0x42) = F16(arg0, 0x42) & 0x7FFF;
            {
                u8 t = FU8(arg0, 0x16);
                *(u8**)(p + 0x7C) = arg0;
                F8(p, 0x16) = t;
            }
            F8(p, 0x15) = F8(arg0, 0x15);
            set_velocity_from_angle(p, FU8(SPAD, 0x83));
        }
        F8(arg0, 0x45) = 0;
        return;
    }
    func_80017A04(arg0);
}
