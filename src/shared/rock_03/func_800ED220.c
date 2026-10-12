#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(s32);
extern struct X4_PlayerObj D_800970A0;

#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800ED220(void* arg0) {
    register s32 t asm("$2");

    func_80017A04();
    func_8002D2B0((s32)arg0);
    {
        register s32 n asm("$3");
        t = FU16(arg0, 0x8C);
        n = t + 1;
        FU16(arg0, 0x8C) = n;
    }
    if ((s16)t < 0x5B) {
        struct X4_PlayerObj* p = &D_800970A0;
        s32 d;
        d = F16(p, 0xA) - F16(arg0, 0xA);
        if (d >= 0) {
            if (d < 0x20) {
                goto y;
            }
            return;
        }
        if (F16(arg0, 0xA) - F16(p, 0xA) < 0x20) {
            struct X4_PlayerObj* q;
            s32 e;
        y:
            q = &D_800970A0;
            e = F16(q, 0xE) - F16(arg0, 0xE);
            if (e >= 0) {
                if (e < 0x10) {
                    goto reset;
                }
                return;
            }
            if (F16(arg0, 0xE) - F16(q, 0xE) < 0x10) {
                goto reset;
            }
        }
        return;
    }
reset:
    FU16(arg0, 0x8C) = 0;
    FU8(arg0, 6) = FU8(arg0, 6) + 1;
}
