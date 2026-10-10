#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);
s32 func_80030CCC(void*, s16, s16);

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800ED428(void* arg0) {
    u8* p;
    s16 x;
    u16 t;

    func_80017A04();
    func_8002D2B0((s32)arg0);
    t = FU8(arg0, 0x15);
    if (t != 0) {
        u8* q = *(u8**)((u8*)arg0 + 0x68);
        x = q[2] + (FU16(arg0, 0xA) + (s8)q[0]);
        p = q;
    } else {
        u8* q = *(u8**)((u8*)arg0 + 0x68);
        x = FU16(arg0, 0xA) - (s8)q[0] - q[2];
        p = q;
    }
    if (func_80030CCC(arg0, x, p[3] + (FU16(arg0, 0xE) + (s8)p[1]) + 8) &
        0xFF) {
        if (FU8(arg0, 0x15) == 0) {
            if (FU8(arg0, 0x70) & 2) {
                goto flip;
            }
            goto end;
        }
        if (!(FU8(arg0, 0x70) & 1)) {
            goto end;
        }
    }
flip:
    FU8(arg0, 0x15) = (FU8(arg0, 0x15) == 0) << 6;
    F32(arg0, 0x20) = -F32(arg0, 0x20);
    func_8002D2B0((s32)arg0);
end:
    t = FU16(arg0, 0x8C);
    FU16(arg0, 0x8C) = t + 1;
    if ((s16)t >= 0xF1) {
        FU16(arg0, 0x8C) = 0;
        FU8(arg0, 6) = FU8(arg0, 6) + 1;
    }
}
