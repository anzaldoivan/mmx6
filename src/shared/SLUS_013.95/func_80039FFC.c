#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CFB0(void* arg);

s32 func_80039FFC(void* arg0) {
    s32 mask;
    // !FAKE: the limit stays in the second return register across both arms
    register s32 lim asm("$3");
    s32 cond;
    s32 bits;
    s32 ret;

    mask = 2;
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        mask = 1;
    }
    if (M2C_FIELD(arg0, u8*, 0x89) & mask) {
        return 1;
    }
    func_8002CFB0(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        cond = M2C_FIELD(arg0, s32*, 0x20);
        lim = M2C_FIELD(arg0, s32*, 0x108);
        cond = cond < lim;
    } else {
        lim = -M2C_FIELD(arg0, s32*, 0x108);
        cond = lim < M2C_FIELD(arg0, s32*, 0x20);
    }
    if (cond) {
        M2C_FIELD(arg0, s32*, 0x20) = lim;
    }
    if (--M2C_FIELD(arg0, s8*, 0x85) == 0) {
        return 1;
    }
    bits = M2C_FIELD(arg0, u16*, 0x7C) & 0x103;
    if (bits == 0) {
        return 1;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if ((bits & 2) == 0) {
            // !FAKE: the flag-2 zero test branches to the shared return-0 tail
            goto zero;
        }
    one:
        return 1;
    }
    bits &= 1;
    if (bits != 0) {
        // !FAKE: the flag-1 test branches to the shared return-1 block
        goto one;
    }
zero:
    return 0;
}
