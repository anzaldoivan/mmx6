#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                 /* extern */
s32 func_80039EB0(struct X4_PlayerObj*); /* extern */
void func_8003B114(s32 arg0);            /* extern */
M2C_UNK func_8003B298(void*);            /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);   /* extern */
M2C_UNK func_8003F700(void*);            /* extern */
s32 func_801ECA50(void*);                /* extern */

void func_800365D4(void* arg0) {
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (func_80039EB0(arg0) != 0) {
        func_8003B298(arg0);
        func_8003BA04(arg0, 0x55);
        {
            // !FAKE: depin: dropping it breaks the match (91/94)
            register s32 a asm("$2") = 0x1F;
            // !FAKE: depin: dropping it breaks the match (91/94)
            register s32 b asm("$3") = 4;
            M2C_FIELD(arg0, u8*, 5) = a;
            M2C_FIELD(arg0, u8*, 6) = b;
        }
        return;
    }
    ((void (*)())func_80017A04)(arg0);
    if ((M2C_FIELD(arg0, u16*, 0x7C) & 8) ||
        (M2C_FIELD(arg0, u16*, 0x80) & 0x80) ||
        !(M2C_FIELD(arg0, u8*, 0x89) & 4)) {
        M2C_FIELD(arg0, u8*, 7) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s8*, 7) = M2C_FIELD(arg0, u8*, 7) - 1;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_8003F700(arg0);
        } else if (func_801ECA50(arg0) != 0) {
            return;
        }
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            func_8003BA04(arg0, 0x8C);
        }
        if (M2C_FIELD(arg0, s8*, 0x90) != 0) {
            func_8003BA04(arg0, 0x54);
        }
    }
    if ((M2C_FIELD(arg0, s8*, 7) == 0) && (M2C_FIELD(arg0, s8*, 0x46) == 0)) {
        func_8003B114((s32)arg0);
    }
}
