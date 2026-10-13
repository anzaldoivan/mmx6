#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s32 D_800F7DE4;
extern s32 D_800F7DE8;
extern s32 D_800F7E30;

void func_800F5C78(u8* arg0) {
    if (*(s8*)(arg0 + 0x46) == 0) {
        goto set2;
    }
    if (D_800F7DE4 != 0 || D_800F7DE8 != 0 || D_800F7E30 != 0) {
    set2:
        arg0[4] = 2;
        return;
    }
    if ((s8)++arg0[6] == 0x16) {
        func_80016C48(2, 0x31, arg0);
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x60, 0x60);
}
