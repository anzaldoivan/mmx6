#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CFB0(void* arg);          /* extern */
M2C_UNK func_8003B054(void*);          /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
void func_8003D394(void* arg0);        /* extern */
s32 func_801EC028();                   /* extern */

// 0x8003737C end_ceiling_dash: end of ceiling dash.
// basis: community tweaks-index.tsv:195
// callers: none known
void end_ceiling_dash(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        ((void (*)())func_8003B054)();
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 2) != 0) && (func_801EC028(arg0) != 0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = -1;
        M2C_FIELD(arg0, s8*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x100);
        return;
    }
    func_8002CFB0(arg0);
    func_8003D394(arg0);
    if ((M2C_FIELD(arg0, s8*, 0x46) < 0) || (M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
        ((void (*)(void*, s32))func_8003BA04)(arg0, 0x14);
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
