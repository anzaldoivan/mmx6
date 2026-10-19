#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80012D9C(s32);
void func_8001750C(u8, u8);
M2C_UNK func_8003BA04(void*, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;

void func_8003D8A8(void* arg0) {
    func_8001750C(1, 5);
    func_8001750C(1, 7);
    func_80012D9C(0);
    if (M2C_FIELD(arg0, s8*, 0xD5) != 0) {
        M2C_FIELD(arg0, s8*, 0x3) = 0;
        M2C_FIELD(arg0, s8*, 0xD7) = 1;
    } else {
        struct X4_EngineObj* e = &D_800CCED0;
        e->unk12 = 1;
        e->unk13 = 1;
        e->unk14 = 1;
        e->unk15 = 1;
        e->unk16 = 1;
        e->unk17 = 1;
        e->unk18 = 1;
        e->unk19 = 1;
        e->unk1A = 1;
        M2C_FIELD(arg0, s8*, 0xD7) = 8;
        func_8003BA04(arg0, 0x21);
    }
    M2C_FIELD(arg0, u8*, 0x5) += 1;
}
