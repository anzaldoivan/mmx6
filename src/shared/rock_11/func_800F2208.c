#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
void func_800F1BE8(void* arg0);
void func_800F3D24(u8* self);
extern void (*D_800FCA14[])(void*);
extern s8 D_800FD51D;

void func_800F2208(void* arg0) {
    s32 r;

    M2C_FIELD(arg0, s16*, 0xA) = 0xA0;
    M2C_FIELD(arg0, s16*, 0xE) = 0x88;
    func_80017A04();
    D_800FCA14[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800F3D24(arg0);
    r = func_80031474(arg0);
    if (r < 0) {
        M2C_FIELD(arg0, s8*, 0x5C) = 0;
    } else if (r > 0 && r != 0x7F) {
        if (r == 7 || r == 0x10 || r == 0x2B) {
            if (M2C_FIELD(arg0, s8*, 5) != 0xA) {
                D_800FD51D = 1;
                M2C_FIELD(arg0, s8*, 5) = 0xA;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        }
    }
    func_80030ECC(arg0);
    func_800F1BE8(arg0);
}
