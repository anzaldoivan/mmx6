#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern void (*D_800FCDFC[])(void*);

void func_800F7AE8(void* arg0) {
    void* parent;

    parent = M2C_FIELD(arg0, void**, 0x80);
    if (M2C_FIELD(parent, s8*, 4) != 1 || M2C_FIELD(parent, s8*, 7) == 0) {
        M2C_FIELD(arg0, s8*, 4) = 7;
        M2C_FIELD(arg0, u8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (M2C_FIELD(parent, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, u8*, 0x47) = M2C_FIELD(parent, u8*, 0x47);
    M2C_FIELD(arg0, u8*, 3) = M2C_FIELD(parent, u8*, 3);
    M2C_FIELD(arg0, s32*, 0x50) = M2C_FIELD(parent, s32*, 0x50);
    M2C_FIELD(arg0, s32*, 0x54) = M2C_FIELD(parent, s32*, 0x54);
    D_800FCDFC[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (++M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 3) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 3) = 1;
    }
    check_enemy_hits(arg0);
    func_80030ECC(arg0);
}
