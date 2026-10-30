#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CA54();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
s32 random_byte();
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_800F5D38;
extern M2C_UNK D_800F5D3C;
extern M2C_UNK D_800F5D40;
extern M2C_UNK D_800F5D44;
extern void (*D_800F5D54[])(void*);

void func_800EF340(void* arg0) {
    s8 old;

    old = FLD(arg0, s8, 0x5C);
    if (check_enemy_hits(arg0) < 0) {
        s8 t = FLD(arg0, s8, 0x2);
        if (t == 1) {
            if (random_byte() & 1) {
                func_800477E4(2, &D_800F5D40, arg0);
            } else {
                func_800477E4(2, &D_800F5D44, arg0);
            }
            func_80049E50(arg0);
        } else if (t == 2 || t == 0) {
            if (random_byte() & 1) {
                func_800477E4(2, &D_800F5D38, arg0);
            } else {
                func_800477E4(2, &D_800F5D3C, arg0);
            }
            func_80049E50(arg0);
        }
        func_8004E654(arg0, 0x12);
        t = 2;
        FLD(arg0, s8, 0x4) = t;
        return;
    }
    func_80030ECC(arg0);
    if (FLD(arg0, s8, 0x5C) != old) {
        FLD(arg0, u16, 0x42) |= 0x8000;
    }
    D_800F5D54[FLD(arg0, s8, 0x6)](arg0);
    func_80017A04(arg0);
    if (func_8002CBFC(arg0, 0x30, 0x30) == 0) {
        if (FLD(arg0, s8, 0x6) == 0) {
            FLD(arg0, u8, 0x3) ^= 1;
        } else {
            func_8002CCB0(arg0, 0x30, 0x30);
        }
    } else {
        func_8002CA54(arg0);
    }
    if (FLD(arg0, u8, 0x70) & 8) {
        FLD(arg0, s8, 0x67) = 0;
    } else {
        s32 d = FLD(arg0, s32, 0x24);
        if (d < 0) {
            d = -1;
        } else {
            d = 1;
        }
        FLD(arg0, s8, 0x67) = d;
    }
    func_8002F288(arg0);
}
