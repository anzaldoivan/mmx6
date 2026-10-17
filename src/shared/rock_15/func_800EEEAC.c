#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230(void*);

void func_800EEEAC(u8* arg0) {
    s16 a;
    s16 b;
    s32 d;

    if (arg0[0x15] == 0 && (arg0[0x70] & 1)) {
        arg0[6] += 2;
        return;
    }
    if (arg0[0x15] == 0x40 && (arg0[0x70] & 2)) {
        arg0[6] += 2;
        return;
    }
    a = *(s16*)(arg0 + 0xA);
    b = *(s16*)(arg0 + 0x84);
    d = a - b;
    if (d >= 0) {
        if (d >= 0x30) {
            // !FAKE: keeps the near arm's far test a branch to the shared store block
            goto set;
        }
        // !FAKE: near arm jumps to the call; a fallthrough cross-jumps the slti tests
        goto call;
    }
    if ((b - a) >= 0x30) {
    set:
        *(s32*)(arg0 + 0x28) = 0x2000;
        arg0[6] += 1;
        return;
    }
call:
    func_8002D230(arg0);
}
