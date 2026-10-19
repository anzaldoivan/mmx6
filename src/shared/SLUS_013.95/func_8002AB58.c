#include "common.h"
#define M2C_UNK s32

extern void (*D_80073674[])();
extern u8 D_800E4188;
void func_800210E8(void);
void func_80025E1C();

M2C_UNK func_8002AB58(s32 arg0) {
    D_80073674[D_800E4188](arg0);
    func_800210E8();
    func_80025E1C();
}
