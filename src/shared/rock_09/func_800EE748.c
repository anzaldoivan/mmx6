#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50();                         /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*); /* extern */
s32 func_800EE330(void*, M2C_UNK*);              /* extern */
extern M2C_UNK D_800970A0;
extern M2C_UNK D_800F62E0;

void func_800EE748(void* arg0) {
    func_8002CB50();
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        func_800477E4(3, &D_800F62E0, arg0);
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (func_800EE330(arg0, &D_800970A0) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) - 1);
    }
}
