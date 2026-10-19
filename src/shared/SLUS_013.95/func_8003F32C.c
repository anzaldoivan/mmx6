#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039EB0(struct X4_PlayerObj*);                  /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);                    /* extern */
M2C_UNK func_8003CDBC();                                  /* extern */
void* func_8003D3F8(s8 arg0, s8 arg1, s8 arg2, s32 arg3); /* extern */

s32 func_8003F32C(void* arg0) {
    if (!(M2C_FIELD(arg0, u16*, 0x80) & 0x80) && func_80039EB0(arg0) == 0) {
        return 0;
    }
    func_8003BA04(arg0, 0xBD);
    {
        // !FAKE: numeric pin keeps 0xF loaded before the first byte store
        register s32 f asm("$3") = 0xF;
        M2C_FIELD(arg0, u8*, 0x84) = 1;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 0x85) = f;
        M2C_FIELD(arg0, u8*, 0x86) = 7;
    }
    M2C_FIELD(arg0, u8*, 0xD9) = 0;
    func_8003CDBC(arg0);
    M2C_FIELD(arg0, u8*, 5) = 0x4A;
    M2C_FIELD(arg0, u8*, 6) = 0;
    func_8003D3F8(0x21, 0x20, 0, (s32)arg0);
    return 1;
}
