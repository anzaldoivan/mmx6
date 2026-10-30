#include "common.h"
#define M2C_UNK s32

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);
M2C_UNK func_80018774(M2C_UNK);
extern u8 D_800CD40C;

void func_80051A44(s8* arg0) {
    if (arg0[6] == 0) {
        if (arg0[0x45] != 0) {
            ((void (*)(M2C_UNK))func_80018774)(3);
            {
                // !FAKE: pin the increment temp to the second return register
                register s32 u asm("$3") = (u8)arg0[6] + 1;
                arg0[0x45] = 0;
                arg0[6] = u;
            }
        }
    } else if (D_800CD40C == 0) {
        ((void (*)(M2C_UNK, M2C_UNK))play_bgm_xa_track)(0x1C, 0x7F);
        {
            s32 t = (u8)arg0[5] + 1;
            arg0[6] = 0;
            arg0[5] = t;
        }
    }
}
