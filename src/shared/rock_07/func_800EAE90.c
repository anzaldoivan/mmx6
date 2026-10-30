#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);
extern s8 D_800970A2;
extern void (*D_800F8868[])(void*);

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EAE90(void* arg0) {
    W(arg0, 0x18) = W(arg0, 0x8);
    W(arg0, 0x1C) = W(arg0, 0xC);
    if (UB(arg0, 0x91) == 0) {
        func_80017A04(arg0);
    }
    D_800F8868[B(arg0, 6)](arg0);
    if (UB(arg0, 0x90) != 0 && check_enemy_hits(arg0) < 0) {
    kill: {
        // !FAKE: depin: dropping it breaks the match (26/91)
        register void* a asm("$4");
        a = arg0;
        B(arg0, 3) = 0;
        ((void (*)())func_80049E50)(a);
    }
        goto done;
    }
    if (func_80030ECC(arg0) != 0) {
        switch (B(arg0, 2) & 0xF0) {
        case 0x10:
            B(arg0, 3) = 0;
            if (D_800970A2 == 0) {
                func_80049D90(arg0);
            } else {
                func_80049E50(arg0);
            }
            goto done;
        case 0:
        case 0x20:
            goto kill;
        }
    }
    if ((B(arg0, 2) & 0xF0) != 0x30) {
        if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x10, 0x10);
            if (UB(arg0, 0x92) != 0) {
                B(arg0, 3) = 0;
            }
            return;
        }
    done:
        B(arg0, 4) = 2;
    }
}
