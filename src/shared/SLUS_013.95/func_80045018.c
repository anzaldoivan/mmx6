#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
void func_80049E50(struct X4_MainObj* self);
extern s32 D_80076160;
extern void (*D_8007617C[])(void*);

void func_80045018(void* arg0) {
    u8 temp_a0;

    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_80017A04(arg0);
        if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
            M2C_FIELD(arg0, void**, 0x50) = &D_80076160;
        }
        D_8007617C[M2C_FIELD(arg0, s8*, 5)](arg0);
        temp_a0 = M2C_FIELD(arg0, u8*, 0x8F);
        if (((temp_a0 & 0xC) == 0xC) || ((temp_a0 & 3) == 3) ||
            (M2C_FIELD(arg0, u8*, 0x90) >= 8U)) {
            ((s32(*)(void*))func_80049E50)(arg0);
            M2C_FIELD(arg0, s8*, 4) = 2;
        }
    } else {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
