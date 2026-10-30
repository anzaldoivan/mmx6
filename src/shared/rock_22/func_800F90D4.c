#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();
M2C_UNK func_8003D308(M2C_UNK, u8);
extern s8 D_800970A5;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEDF;
extern u8 D_800FD598;

void func_800F90D4(void* arg0) {
    void* temp_v0;

    if (D_800CCEDF == 0 && D_800970A5 == 0x14) {
        background_objects[0].unk47 = 2;
        D_800FD598 = background_objects[0].unk48;
        func_8003D308(0x1D, 0x40);
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x18;
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = 0x80;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
