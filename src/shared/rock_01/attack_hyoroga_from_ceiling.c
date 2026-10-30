#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
void* func_8002C32C();
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_801ECD54();

// 0x801ECAF0 attack_hyoroga_from_ceiling: Hyoroga attack from ceiling.
// basis: community tweaks-index.tsv:194
// callers: func_801ECA50
void attack_hyoroga_from_ceiling(u8* arg0) {
    s32 i;
    u8 bits;
    u8* obj;

    if (((s8*)arg0)[6] == 0) {
        arg0[6]++;
    } else {
        if (((s8*)arg0)[7] != 0) {
            arg0[7]--;
        }
        func_80017A04(arg0);
        func_801ECD54(arg0, 0x30);
        bits = arg0[0x45];
        if (bits & 0x40) {
            arg0[0x45] = bits & 0xBF;
            i = 0;
            do {
                obj = func_8002C32C();
                if (obj != 0) {
                    obj[0] = 0x21;
                    obj[1] = 0x21;
                    obj[2] = i;
                    obj[0x14] = arg0[0x14];
                }
                i++;
            } while (i < 3);
        }
    }
    if (((s8*)arg0)[0x46] == 0) {
        func_8003BA04(arg0, 0x54);
        arg0[0x8E] = 0;
        arg0[5] = 0x1F;
        arg0[6] = 3;
    }
}
