#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003F3DC(void*);
void func_8003F4C4(struct X4_PlayerObj* self, s32 animation);

s32 func_8003A870(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s8*, 2) != 0) {
        if (!(M2C_FIELD(arg0, u8*, 0xC9) & 2)) {
            return 0;
        }
    } else if (M2C_FIELD(arg0, u8*, 0xE7) != 2) {
        return 0;
    }
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 4)) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 0x80) {
        M2C_FIELD(arg0, s8*, 0x67) = 1;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0xF8) * 2;
        func_8003F4C4(arg0, 0xA);
        M2C_FIELD(arg0, s8*, 0x8B) = 0xA;
        func_8003F3DC(arg0);
        {
            // !FAKE: depin: dropping it breaks the match (66/68)
            register s32 t asm("$2") = M2C_FIELD(arg0, s8*, 2);
            if (t != 0) {
                M2C_FIELD(arg0, s8*, 0x93) = 1;
                M2C_FIELD(arg0, s8*, 0x86) = 6;
            }
        }
        func_80016C48(1, 1, arg0);
        M2C_FIELD(arg0, s8*, 5) = 0x1F;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 7) = 0;
        return 1;
    }
    return 0;
}
