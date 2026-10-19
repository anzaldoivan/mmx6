#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002B2F8(s32);                                  /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s16 D_80090D5C;
extern s8 D_8009724F;
extern s16 D_80097430;
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800CF854;

void func_800ED55C(void* arg0) {
    s32 var_s0;

    func_8002B2F8(0);
    var_s0 = 0xB;
    D_80090D5C = 0;
    D_80097430 = 0;
    D_800CF854 = 0;
    D_800CCED0.enable_boss = 0;
    D_800CCED0.boss_ptr = 0;
    D_8009724F = 0;
    do {
        func_80049EBC(arg0, 1, 0x40, 0x40);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
