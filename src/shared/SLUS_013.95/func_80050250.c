#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B79C();
void* func_8002BBF4();
void func_80031DA8(struct X4_MainObj*);
s32 func_80050C88(void*);
void func_80051104(struct X4_ItemObj* arg0);
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEF6;
extern s8 D_800CCEF8;

#define I84 (*(u32*)((u8*)arg0 + 0x84))
#define I88 (*(s32*)((u8*)arg0 + 0x88))

void func_80050250(struct X4_ItemObj* arg0, s32 arg1, u8* arg2) {
    u8* p;
    s8 t;

    ((void (*)())func_80031DA8)();
    func_80051104(arg0);
    t = arg0->unk2;
    if (t == 7 && D_800CCEF6 == 0) {
        return;
    }
    if (t == 8 && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0xC && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0xA && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0xE && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0xF && D_800CCEF6 == 0) {
        return;
    }
    if (t == 0x22 && D_800CCEF8 == 0) {
        return;
    }
    if (t == 0x2C && D_800CCEF6 != 0) {
        return;
    }
    if (func_80050C88(arg0) == 0) {
        return;
    }
    if (D_800CCED0.unk1C == 0) {
        if (arg0->unk2 == 0x19 || arg0->unk2 == 0x27) {
            func_80016C48(5, 1, 0);
            func_80012D9C(4);
        }
    }
    D_800CCED0.unk1C = 1;
    arg2[0xD4] = 1;
    if (arg0->unk2 == 0x19) {
        if ((s16)D_800971F8[1].unk42 >= -0x4F) {
            if (!(D_80097420 & 1)) {
                D_800971F8[1].unk42--;
            }
            if (I88 == 0) {
                func_8002943C(0xA, 2, 2);
                I88 = 0xA;
            } else {
                I88--;
            }
            return;
        }
        func_80016C48(5, 3, p);
        D_800971F8[1].unk3 = 0;
    } else if (arg0->unk2 == 0x27) {
        if (I84++ < 0x70) {
            D_800971F8[1].unk42--;
            if (I88 == 0) {
                func_8002943C(0xA, 2, 2);
                I88 = 0xA;
            } else {
                I88--;
            }
            return;
        }
        D_800971F8[1].unk3 = 0;
        func_80016C48(5, 3, p);
    }
    if (arg0->unk7C.timer == 0) {
        func_8002B79C();
    }
    if (arg0->unk2 == 7) {
        p = func_8002BBF4();
        p[0] = 0x41;
        p[1] = 0x19;
        p[2] = 4;
    }
    D_800971F8[0].unk34 &= 0xF;
    arg0->unk5 = 1;
}
