#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 set_animation(void*, s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80031DA8();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800743DC;
extern s32 D_800970A8;
extern s16 D_800970AA;
extern M2C_UNK D_800F914C;
extern M2C_UNK D_800F916C;
extern void (*D_800F9180[])(void*);

void func_800EE178(void* arg0) {
    void* parent;
    s8 saved;
    s32 d;

    parent = FX(arg0, void*, 0x7C);
    saved = FX(arg0, s8, 0x5C);
    FX(arg0, u16, 0x42) &= 0x7FFF;
    if (FX(arg0, s8, 0x2) >= 10) {
        FX(arg0, u8, 0x15) = (FX(arg0, s32, 0x8) <= D_800970A8) << 6;
    }
    if (FX(arg0, s8, 0x45) & 0xF0) {
        FX(arg0, void*, 0x58) = &D_8007433C;
    } else {
        FX(arg0, void*, 0x58) = &D_800743DC;
    }
    if (check_enemy_hits(arg0) < 0 && FX(arg0, s8, 0x2) != 0) {
        FX(parent, u8, 0x5C)--;
        func_80049E50(arg0);
        func_800477E4(3, &D_800F914C, arg0);
        FX(arg0, void*, 0x54) = &D_800F916C;
        FX(arg0, s32, 0x50) = 0;
        FX(arg0, void*, 0x58) = &D_8007433C;
        FX(arg0, s8, 0x4) = 2;
        switch (FX(arg0, s8, 0x2)) {
        case 10:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F914C, arg0);
            break;
        case 11:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F914C, arg0);
            break;
        case 12:
            FX(arg0, s8, 0x3) = 0;
            FX(arg0, s8, 0x4) = 3;
            func_800477E4(5, &D_800F914C, arg0);
            play_sound(2, 0x14, arg0);
            break;
        case 13:
            set_animation(arg0, 0x14);
            func_800477E4(3, &D_800F914C, arg0);
            break;
        case 14:
            set_animation(arg0, 0x15);
            func_800477E4(3, &D_800F914C, arg0);
            break;
        }
        return;
    }
    if (FX(arg0, s8, 0x5C) != saved) {
        FX(arg0, u16, 0x42) |= 0x8000;
    }
    D_800F9180[FX(arg0, s8, 0x6)](arg0);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x80);
    d = D_800970AA - FX(arg0, s16, 0xA);
    if (d >= 0) {
        if (d < 0x30) {
            goto near;
        }
    } else if (FX(arg0, s16, 0xA) - D_800970AA < 0x30) {
    near:
        func_80031DA8(arg0);
    }
    if (FX(arg0, s8, 0x6) != 2) {
        func_80030ECC(arg0);
    }
}
#undef FX
