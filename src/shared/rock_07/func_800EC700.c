#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define B(p, o) M2C_FIELD(p, u8*, o)

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EC700(void* arg0) {
    s32 cur;
    // !FAKE: retail holds the compare constant in the first return register
    register s32 want asm("$2");
    s8 temp_s0;

    temp_s0 = SB(M2C_FIELD(arg0, void**, 0x80), 7);
    if (temp_s0 == 0) {
        return;
    }
    switch (temp_s0) {
    case 1:
        cur = SB(arg0, 2);
        want = 0x20;
        // !FAKE: shared compare block reached from cases 1-3
        goto block_11;
    case 2:
        cur = SB(arg0, 2);
        want = 0x21;
        // !FAKE: shared compare block reached from cases 1-3
        goto block_11;
    case 3:
        cur = SB(arg0, 2);
        want = 0x22;
    // !FAKE: shared compare block reached from cases 1-3
    block_11:
        if (cur == want) {
            set_animation(arg0, 4);
            {
                // !FAKE: retail increments the byte in the first return register
                register s32 n asm("$2") = B(arg0, 6) + 1;
                B(arg0, 6) = n;
            }
        }
        break;
    case 4:
        if (SB(arg0, 2) == 0x22) {
            set_animation(arg0, 2);
            SB(arg0, 6) = temp_s0;
        }
        break;
    }
}
