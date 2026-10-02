#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK);           /* extern */
M2C_UNK func_8001FB90(M2C_UNK*, M2C_UNK); /* extern */
M2C_UNK func_8002AA74();                  /* extern */
extern M2C_UNK D_800711F4;
extern s8 D_80097427;

void func_8001FF30(void* arg0) {
    M2C_FIELD(arg0, s8*, 7) = 1;
    M2C_FIELD(arg0, s32*, 0x34) = 0;
    func_8002AA74();
    D_80097427 = 0;
    func_8001FB90(&D_800711F4, 0x78);
    func_800139A0(0x20);
}
