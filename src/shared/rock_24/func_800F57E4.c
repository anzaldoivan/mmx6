#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
extern s32 D_800F77D8;
extern s32 D_800F77DC;

void func_800F57E4(void* arg0) {
    // !FAKE: register pin for the parent pointer
    register void* temp_a1 asm("$5");
    s32 temp_v0;
    s32 g;

    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    g = D_800F77D8;
    {
        // !FAKE: register pin for the copied halfword
        register s32 v asm("$2");
        v = M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xA) = v;
        v = M2C_FIELD(temp_a1, u16*, 0xE);
        M2C_FIELD(arg0, u16*, 0xE) = v;
    }
    if ((g != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s32*, 0x8C) + 1;
    M2C_FIELD(arg0, s32*, 0x8C) = temp_v0;
    if (temp_v0 == 0x32) {
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
    }
    func_8002D230(arg0);
    func_80017A04(arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
}
