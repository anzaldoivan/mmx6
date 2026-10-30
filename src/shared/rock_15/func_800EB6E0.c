#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
void func_800EC428(struct X4_MainObj* self);
extern M2C_UNK D_800F618C;
extern void (*D_800F61A8[])(void*);

void func_800EB6E0(void* arg0) {
    s32 r;
    u8 f;
    // !FAKE: depin: dropping it breaks the match (35/66)
    register s32 c asm("$2");

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800F61A8[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800EC428(arg0);
    r = check_enemy_hits(arg0);
    func_80030ECC(arg0);
    c = 0xC;
    if (r < 0 || (f = M2C_FIELD(arg0, u8*, 0x70), (f & 0xC) == c) ||
        (f & 3) == 3) {
        func_800477E4(5, &D_800F618C, arg0);
        c = 0x1E;
        M2C_FIELD(arg0, s16*, 0x7C) = c;
        M2C_FIELD(arg0, u8*, 3) = 0;
        c = 5;
        M2C_FIELD(arg0, s16*, 0x7E) = c;
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    if (func_8002CBFC(arg0, 0x60, 0x40) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = 4;
}
