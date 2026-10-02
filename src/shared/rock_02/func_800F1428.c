#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
M2C_UNK func_80030ECC(void*);                   /* extern */
s32 func_80031474(void*);                       /* extern */
M2C_UNK func_80049E50(void*);                   /* extern */
extern s32 D_800FBC70;
extern s32 D_800FBC74;

void func_800F1428(void* arg0) {
    if ((D_800FBC70 != 0) || (D_800FBC74 != 0)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if ((func_80031474(arg0) < 0) || (M2C_FIELD(arg0, u8*, 0x70) != 0)) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x10, 0x10);
}
