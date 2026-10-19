#include "common.h"
#define M2C_UNK s32

s32 func_8002FE30(void*);
M2C_UNK func_8003AF1C(void*);
M2C_UNK func_8003AFF4(s32);

#define B(o) (*(s8*)((u8*)self + (o)))
#define H(o) (*(u16*)((u8*)self + (o)))

s32 func_8003A764(void* arg0) {
    void* self = arg0;
    // !FAKE: pin: the shared call's argument stays in the first argument register (C0161)
    register s32 a asm("$4");

    if (B(0xD0) > 0) {
        // !FAKE: repeated store keeps jump1 from hoisting it, so the call argument stays explicit
        a = (s32)self;
        a = (s32)self;
        // !FAKE: goto: positive-timer arm shares the out-of-range call (C0115)
        goto tail;
    }
    if ((u8)(func_8002FE30(self) - 0x25) >= 0xB) {
        B(0xE3) = 4;
        a = (s32)self;
    tail:
        func_8003AFF4(a);
        return 1;
    }
    if (!(H(0x80) & 0x80)) {
        return 0;
    }
    if (H(0x7C) & 8) {
        ((void (*)(void*))func_8003AFF4)(self);
    } else {
        func_8003AF1C(self);
    }
    B(0xE3) = 4;
    return 1;
}
#undef B
#undef H
