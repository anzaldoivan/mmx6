#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, u16*, o)

void* func_8002C4C4();
M2C_UNK func_8002C9B0();
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F5990[];

void func_800ED950(s32 arg0) {
    void* temp_v0;

    temp_v0 = func_8002C4C4();
    if (temp_v0 != 0) {
        u8* t = D_800F5990;
        struct X4_EngineObj* e = &D_800CCED0;
        B(temp_v0, 0) = 0x41;
        B(temp_v0, 1) = 3;
        B(temp_v0, 2) = 0;
        H(temp_v0, 0xA) = *(u16*)((M2C_FIELD(e, s8*, 0x2F) * 4) + t);
        H(temp_v0, 0xE) =
            *(u16*)(D_800F5990 + (M2C_FIELD(e, s8*, 0x2F) * 4) + 2);
    }
    func_8002C9B0(arg0);
}
