#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
void func_800F9F7C(void* arg0, M2C_UNK arg1, M2C_UNK arg2);
extern struct X4_EngineObj D_800CCED0;

void func_800F67E8(void* arg0) {
    s8 state;
    s32 one;
    struct X4_EngineObj* eng;

    state = M2C_FIELD(arg0, s8*, 0x45);
    one = 1;
    if (state == one) {
        func_80016C48(2, 0x44, arg0);
        func_800F9F7C(arg0, 0x30, 0);
        func_800F9F7C(arg0, 0x30, 0x200);
        func_800F9F7C(arg0, 0x30, 0x400);
        func_800F9F7C(arg0, 0x30, 0x600);
        func_800F9F7C(arg0, 0x30, 0x800);
        func_800F9F7C(arg0, 0x30, 0xA00);
        func_800F9F7C(arg0, 0x30, 0xC00);
        func_800F9F7C(arg0, 0x30, 0xE00);
    } else if (state == 2) {
        func_800F9F7C(arg0, 0x30, 0x100);
        func_800F9F7C(arg0, 0x30, 0x300);
        func_800F9F7C(arg0, 0x30, 0x500);
        func_800F9F7C(arg0, 0x30, 0x700);
        func_800F9F7C(arg0, 0x30, 0x900);
        func_800F9F7C(arg0, 0x30, 0xB00);
        func_800F9F7C(arg0, 0x30, 0xD00);
        func_800F9F7C(arg0, 0x30, 0xF00);
    } else if (state == 3) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        eng = &D_800CCED0;
        if (eng->stage != 0xC) {
            func_80021760(0, 0xFF, M2C_FIELD(eng, u8*, 0x2E));
            M2C_FIELD(eng, u8*, 0x2E) = one;
        }
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}
