#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80012890(M2C_UNK);  /* extern */
M2C_UNK func_8001A9B0();         /* extern */
M2C_UNK func_80066058(M2C_UNK*); /* extern */
M2C_UNK func_800660B8(M2C_UNK);  /* extern */
extern M2C_UNK func_80012FE4;

void func_8001CBE0(void) {
    func_80012890(0);
    func_8001A9B0();
    func_800660B8(0);
    func_80066058(&func_80012FE4);
}
