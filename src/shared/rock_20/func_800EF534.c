#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800F0784(s32);
M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_80097169;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F366C[];

#define ENG37 ((u8*)&D_800CCED0)

void func_800EF534(u8* arg0) {
    u8* e = ENG37;
    u8 c = e[0x26];
    // !FAKE: regalloc pin, the joined result lives in the first return register
    register s32 v asm("$2");

    if ((u32)(c - 1) < 8U) {
        if (*(s8*)(e + 0x27) != 0) {
            v = 2;
            arg0[2] = v;
            return;
        }
        {
            if (!((D_80097169 >> ((s8)c - 1)) & 1)) {
                arg0[3] = 3;
                func_800F0784(3);
                {
                    u16* t = (u16*)(D_800F366C + 0x34);
                    s32 i;
                    e[0x28] = 1;
                    i = *(s8*)(e + 0x26) - 1;
                    func_80021760(t[i], 0xFF, 0);
                }
                v = arg0[2] + 1;
                arg0[2] = v;
                return;
            } else {
                // !FAKE: shared else block reached from the inner bit test
                goto block_4;
            }
        }
    } else {
    block_4:
        v = 2;
    }
    arg0[2] = v;
}

#undef ENG37
