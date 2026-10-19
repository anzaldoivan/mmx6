#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;

void func_800EF31C(void* arg0) {
    if (!(D_800CCED0.unk5F & 0x10) || (D_800CCED0.unk1 == 6)) {
        func_800179D0(arg0, 2, 1);
    } else if (D_800CCED0.unk1 == 5) {
        func_800179D0(arg0, 2, 0);
    }
    func_8002CCB0(arg0, 0x60, 0x10);
}
