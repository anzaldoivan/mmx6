#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
s32 func_8002D2D4();
s32 func_8002DCF4(void*, void*);
void func_8004ED4C(u8* arg0, u8 arg1, u8 a2);
void func_8004FF00(u8, s32);
extern u8 D_80078BE8[];
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
extern struct X4_RideArmorObj D_800CD340;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

s32 func_8004EECC(void* arg0) {
    void* tgt;
    s32 r;

    tgt = &D_800970A0;
    if (S8(&D_800970A0, 0xD5) != 0) {
        tgt = &D_800CD340;
        if (D_800CD340.unk5 == 0) {
            tgt = (u8*)&D_800CD340 + 0xB0;
        }
    }
    if (!(F8(tgt, 0x5C) & 0x7F)) {
        return 0;
    }
    if (func_8002DCF4(arg0, tgt) != 0) {
        if (F8(arg0, 2) != 0x80) {
            func_8004FF00(F8(arg0, 2), 2);
        }
        {
            u8* e = (u8*)&D_800CCED0;
            F8(arg0, 5) = 0;
            if ((s8)++e[0x39] >= 10) {
                e[0x39] = 9;
            } else {
                func_80016C48(0, 0x15, 0);
            }
        }
        r = func_8002D2D4() & 3;
        func_8004ED4C(arg0, D_80078BE8[r], r);
        return 1;
    }
    return 0;
}
