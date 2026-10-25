#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800F82C0();
extern M2C_UNK D_8007523C;

void func_800F6E50(void* arg0) {
    u8* p = SPAD4C;
    // !FAKE: depin: dropping it breaks the match (29/36)
    register s32 t asm("$2");

    if (M2C_FIELD(p, s8*, 0x89) == 0) {
        M2C_FIELD(p, s8*, 0x89) = 0x78;
    }
    func_800F82C0(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t > 0x28) {
        SPAD4C[0x89] = 0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007523C;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
