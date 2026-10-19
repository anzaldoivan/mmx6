#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PTR(off) (*(u8**)(0x1F800000 + (off)))
#define ONS(p) (((s8*)(p))[3])

extern s8 D_8008EF48[];
extern u8 D_800911A8[];
extern u8 D_80091298[];
extern u8 D_80093C98[];
extern s8 D_800950A0[];
extern u8 D_800964A0[];
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern u8 D_800973B8[];
extern s8 D_80097428;
#define D_80097428 (*(u8*)&D_80097428)
extern u8 D_8009C9B0[];
extern u8 D_800A51B8[];
extern s32 D_800C1220[];
extern u8 D_800C4858[];
extern struct X4_RideArmorObj D_800CD340;
extern struct X4_MiscObj D_800CD410[];
extern u8 D_800E3420[];
extern u8 D_800E3C20[];
extern u8 D_800E4020[];

void func_80022E44(void);
void func_800232D4(void*);
void func_800239CC(void*);
void func_80023ED8(u8* arg0);
void func_800241D4(void*);
void func_800244C0(void);
void func_80026128(void);
void func_8002619C(u8* arg0);
s32 func_8002FE30(void*);

void func_80022960(void) {
    struct X4_PlayerObj* pl;
    u8* p;
    u8* end;
    s32 buf;
    s16 savedX;
    u8 e7;

    buf = SCR_BUF;
    SCR_PTR(0x124) = 0;
    SCR_PTR(0x100) = D_800A51B8 + buf * 0xA000;
    SCR_PTR(0x104) = D_800C4858 + buf * 0x2000;
    SCR_PTR(0x108) = D_800E3420 + buf * 0x400;
    SCR_PTR(0x10C) = D_800E3C20 + buf * 0x200;
    SCR_PTR(0x110) = D_800E4020 + buf * 0xB4;
    if (D_80097428 == 0) {
        func_800244C0();
    }
    func_80026128();
    pl = &D_800970A0;
    if (pl->on_screen != 0) {
        savedX = pl->x_pos.i.hi;
        if (pl->unk5 == 0x1B ||
            (pl->unk5 == 0x3D && func_8002FE30(pl) == 0x2E)) {
            if (pl->unk2 == 0) {
                if (pl->unk15 == 0x40) {
                    pl->x_pos.i.hi++;
                }
            } else if (pl->unk15 == 0x40) {
                pl->x_pos.i.hi--;
            }
        }
        func_800232D4(pl);
        if (pl->unk2 == 0) {
            e7 = ((u8*)pl)[0xE7];
            if (e7 == 3 || e7 == 1 || e7 == 2 || e7 == 4) {
                func_8002619C(pl);
            }
        }
        pl->x_pos.i.hi = savedX;
    }
    if (pl->unk2 == 0) {
        p = D_800911A8;
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
        p += 0x50;
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
        p += 0x50;
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = D_800973B8; p >= D_800973B8 - 0xC0; p -= 0x60) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)D_8008EF48; p < (u8*)D_8008EF48 + 0x1D40; p += 0x9C) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)D_800950A0; p < (u8*)D_800950A0 + 0x1400; p += 0xA0) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = D_80093C98; p < D_80093C98 + 0x1400; p += 0xA0) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = D_80091298; p < D_80091298 + 0x2A00; p += 0x70) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)D_800C1220; p < (u8*)D_800C1220 + 0x3340; p += 0xA4) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    for (p = (u8*)D_800CD410; p < (u8*)D_800CD410 + 0x2400; p += 0x60) {
        if (ONS(p) == 1) {
            func_800232D4(p);
        }
        if (ONS(p) == 2) {
            func_800239CC(p);
        }
    }
    for (p = D_800964A0; p < D_800964A0 + 0xC00; p += 0x60) {
        if (ONS(p) != 0) {
            func_800232D4(p);
        }
    }
    if (D_800CD340.on_screen != 0) {
        func_800232D4(&D_800CD340);
    }
    for (p = D_8009C9B0; p < D_8009C9B0 + 0x1800; p += 0x60) {
        if (ONS(p) != 0) {
            if (*p & 2) {
                func_800241D4(p);
            } else {
                func_80023ED8(p);
            }
        }
    }
    func_80022E44();
}
#undef D_800970A0
#undef D_80097428
