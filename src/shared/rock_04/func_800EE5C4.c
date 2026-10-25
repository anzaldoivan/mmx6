#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEED;
extern M2C_UNK D_800F6CE0;
extern void (*D_800F6CF4[])(void*);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EE5C4(void* arg0) {
    s8 t;

    W(arg0, 0x18) = W(arg0, 0x8);
    W(arg0, 0x1C) = W(arg0, 0xC);
    D_800F6CF4[SB(arg0, 5)](arg0);
    if (func_80031474(arg0) < 0) {
        {
            u8* e = (u8*)&D_800CCED0;
            if (SB(e, 0x27) == 0) {
                SB(e, 0x27) = 0x78;
            }
        }
        if ((u8)(UB(arg0, 2) - 4) < 2 || SB(arg0, 2) == 7) {
            func_8004E654(arg0, 0x15);
        }
        func_800477E4(3, &D_800F6CE0, arg0);
        goto set2;
    }
    func_80030ECC(arg0);
    t = SB(arg0, 2);
    if (t == 4) {
        if (H(arg0, 0xA) < D_800970AA - 0xF0) {
            goto set2;
        }
        if (D_800CCEED > 0) {
            SB(arg0, 4) = 2;
        }
    } else if (t == 5) {
        if (g_Player.x_pos.i.hi + 0xF0 < H(arg0, 0xA) ||
            (g_Player.y_pos.i.hi >= 0x211 && g_Player.x_pos.i.hi >= 0x13A1)) {
        set2:
            SB(arg0, 4) = 2;
        }
    } else if (t >= 6) {
        if (func_8002CBFC(arg0, 0xF0, 0x40) == 1) {
            SB(arg0, 4) = 2;
        }
        if (UB(arg0, 0x70) & 8) {
            SB(arg0, 0x67) = 0;
        } else if (W(arg0, 0x24) < 0) {
            SB(arg0, 0x67) = -1;
        } else {
            SB(arg0, 0x67) = 1;
        }
    }
}
