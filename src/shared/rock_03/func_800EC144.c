#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D230();
s32 func_80030CCC(void*, s16, s16);

#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EC144(void* arg0) {
    u8* p;
    s16 x;
    // !FAKE: depin: dropping it breaks the match (68/70)
    register s32 t asm("$2");

    func_80017A04();
    func_8002D230(arg0);
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
                goto set;
            }
            return;
        }
        if (!(FU8(arg0, 0x70) & 1)) {
            return;
        }
    }
set:
    FU8(arg0, 6) = 3;
    FU8(arg0, 0x80) = 0x28;
}
