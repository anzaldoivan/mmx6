#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F0050(s32);               /* extern */
void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern s8 D_800FD51C;
extern s8 D_800FD520;

void func_800F2B80(void* arg0) {
    if (D_800FD520 == 1) {
        func_800F0050((s32)arg0);
        return;
    }
    D_800FD51C = 0;
    M2C_FIELD(arg0, u8*, 7) = 6;
    func_800F3E10(arg0, 2);
    func_800F3E10(arg0, 0x10);
    func_800F3E10(arg0, 0x11);
    func_800F3E10(arg0, 0x12);
    func_800F3E10(arg0, 0x13);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
