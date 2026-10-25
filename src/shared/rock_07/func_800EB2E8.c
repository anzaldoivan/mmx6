#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80030ECC();
void func_80031DA8(void*);
void func_8003208C(void*);
s32 func_80032B34(struct X4_PlayerObj*);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern void (*D_800F88CC[])(void*);

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define BG ((u8*)&background_objects[0])
#define PL ((u8*)&g_Player)

void func_800EB2E8(u8* self) {
    u8* parent;
    s8 st;
    s32 y;

    parent = *(u8**)(self + 0x7C);
    S32(self, 0x18) = S32(self, 0x8);
    S32(self, 0x1C) = S32(self, 0xC);
    st = S8(parent, 0x4);
    if (st != 1) {
        S8(self, 0x3) = 0;
        S8(self, 0x5) = 0;
        U8(self, 0x4)++;
        return;
    }
    if ((S8(self, 0x2) & 0xF0) != 0x20) {
        u8* bg = BG;
        s32 t;
        U16(self, 0xA) = U16(self, 0x82) + (U16(bg, 0xA) + U16(bg, 0x5E));
        t = U16(bg, 0xE) + 0x3B8;
        t -= U16(bg, 0x62);
        y = U16(self, 0x86) + t;
        U16(self, 0xE) = y;
        if (S8(parent, 0x5) == 9) {
            U16(self, 0xE) = y + 0x10;
        }
    } else {
        U16(self, 0xA) = U16(parent, 0xA);
        U16(self, 0xE) = U16(parent, 0xE);
        if (S8(parent, 0x8F) == 0 || S8(parent, 0x8F) == st) {
            return;
        }
    }
    if (S8(parent, 0x5) != 2) {
        // !FAKE: depin: dropping it breaks the match (114/120)
        register s32 k asm("$3");
        D_800F88CC[S8(self, 0x5)](self);
        func_80030ECC(self);
        k = S8(self, 0x2) & 0xF0;
        if (k == 0x10) {
            func_80031DA8(self);
        } else {
            u8* pl = PL;
            if (U8(pl, 0xE5) == 0) {
                func_80031DA8(self);
                k = S8(self, 0x2) & 0xF0;
                if (k == 0x20 && S8(parent, 0x91) == 1 &&
                    (U8(self, 0x72) & 4) && (U8(pl, 0x89) & 8)) {
                    S8(pl, 0x71) = 0;
                }
            }
        }
        func_80032B34((struct X4_PlayerObj*)self);
        func_8003208C(self);
    }
}

#undef S8
#undef U8
#undef U16
#undef S32
#undef BG
#undef PL
