#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s32 D_800754BC;

void func_800F7170(void* arg0) {
    // !FAKE: inherited from src/shared/rock_02/func_800F8468.c
    register s32 v asm("$2");

    func_80017A04(arg0);
    if (M2C_FIELD(arg0, u8*, 0x8E) != 0) {
        M2C_FIELD(arg0, u8*, 0x8E)--;
        return;
    }
    M2C_FIELD(arg0, s32**, 0x58) = &D_800754BC;
    move_object(arg0);
    v = M2C_FIELD(arg0, u8*, 0x70) & 8;
    if (v) {
        v = M2C_FIELD(arg0, u8*, 0x15);
        if (v == 0) {
            v = 0xFFFD0000;
        } else {
            v = 0x30000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = v;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        v = M2C_FIELD(arg0, u8*, 6);
        M2C_FIELD(arg0, u8*, 6) = v + 1;
    }
}
