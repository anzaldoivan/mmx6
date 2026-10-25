#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800FCF50;

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F6484(void* arg0) {
    void* parent;
    s32 state;
    s32 t;
    // !FAKE: depin: dropping it breaks the match (62/86)
    register s32 u asm("$3");

    parent = *(void**)((u8*)arg0 + 0x7C);
    state = B(parent, 4);
    if (state != 1) {
        B(arg0, 4) = 3;
        B(arg0, 3) = 0;
        return;
    }
    if (B(parent, 5) == 9) {
        B(arg0, 4) = 2;
        B(arg0, 5) = 0;
        B(arg0, 3) = 0;
        return;
    }
    W(arg0, 0x18) = W(arg0, 8);
    W(arg0, 0x1C) = W(arg0, 0xC);
    func_80017A04(arg0);
    ((void (**)(void*)) & D_800FCF50)[B(arg0, 5)](arg0);
    if (B(arg0, 4) != state) {
        B(arg0, 3) = 0;
        return;
    }
    if (func_80031474(arg0) < 0) {
        {
            // !FAKE: depin: dropping it breaks the match (46/86)
            register void* a asm("$4") = arg0;
            B(arg0, 3) = 0;
            func_80049E50(a);
        }
        u = 3;
        goto set3;
    }
    if (func_80030ECC(arg0) != 0) {
        t = B(arg0, 2) & 0xF0;
        if (t == 0x10 || t == 0x30) {
            {
                // !FAKE: depin: dropping it breaks the match (84/86)
                register void* a asm("$4") = arg0;
                B(arg0, 3) = 0;
                func_80049D90(a);
            }
            u = 3;
        set3:
            B(arg0, 4) = u;
            return;
        }
    }
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    B(arg0, 4) = 3;
}
#undef B
#undef W
