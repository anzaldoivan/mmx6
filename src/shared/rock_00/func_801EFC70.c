#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;

void func_801EFC70(u8* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    if (p->unk6 == 0) {
        if (p->unk5 != 0x23) {
            if (p->unk5 < 0x24) {
                if (p->unk5 < 0xE) {
                    if (p->unk5 < 0xC) {
                        // !FAKE: jump to the shared exit keeps the range test unfolded
                        goto end;
                    }
                    // !FAKE: jump to the shared store block keeps the retail block order
                    goto block_7;
                }
            } else if (p->unk5 == 0x4A) {
                // !FAKE: shared store block reached from the 0x4A arm
                goto block_7;
            }
        } else {
        block_7:
            *(u16*)(arg0 + 0x8E) = p->x_pos.u.hi;
            *(u16*)(arg0 + 0x90) = p->y_pos.u.hi;
            arg0[0x92] = p->unk5;
            arg0[5]++;
        }
    }
end:;
}
