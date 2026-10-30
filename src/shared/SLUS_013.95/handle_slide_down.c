#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D5D0(void*);          /* extern */
s32 func_8003A33C(void*);              /* extern */
s32 func_8003A394(void*);              /* extern */
M2C_UNK func_8003AFF4(s32);            /* extern */
M2C_UNK func_8003B054(void*);          /* extern */
s32 func_8003B5B8(void*);              /* extern */
void func_8003D394(void* arg0);        /* extern */
s32 func_8003E174(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EC178(void*);              /* extern */

// 0x80036EB0 handle_slide_down: sliding-down state routine.
// basis: community tweaks-index.tsv:188
// callers: func_80036E70
M2C_UNK handle_slide_down(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        ((void (*)())func_8003B054)();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        // !FAKE: goto: shared tail block inlined where retail lays it (C0115)
        goto block_9;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        var_v0 = func_8003E174(arg0);
    } else {
        if (func_801EA560(arg0) != 0) {
            return;
        }
        var_v0 = func_801EC178(arg0);
    }
    if (var_v0 != 0) {
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x89) & 3)) {
    block_9:
        func_8003AFF4((s32)arg0);
        return;
    }
    if (func_8003A33C(arg0) == 0) {
        if (func_8003A394(arg0) != 0) {
            func_80017A04(arg0);
            func_8002D5D0(arg0);
            func_8003D394(arg0);
            func_8003F508(arg0, 0xF);
            return;
        }
        func_8003B5B8(arg0);
    }
}
