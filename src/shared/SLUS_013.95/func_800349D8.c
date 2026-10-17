#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);          /* extern */
void func_8001750C(u8, u8); /* extern */
M2C_UNK func_80025FB0();                 /* extern */
extern s16 D_800971EC;

void func_800349D8(void* arg0) {
    func_8001750C(0xFF, 0);
    func_800139F4(0x20);
    func_80025FB0();
    M2C_FIELD(arg0, s8*, 5) = 1;
    D_800971EC = 1;
}
