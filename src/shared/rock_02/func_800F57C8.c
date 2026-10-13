#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
M2C_UNK func_8002D230(void*);
extern struct X4_BackgroundObj D_800971F8[3];
void func_800F57C8(void* arg0) {
    ((void (*)(void*))func_8002D230)(arg0);
    {
        register s32 t asm("$3") = D_800971F8[0].unk1C + 0x100;
        if (M2C_FIELD(arg0, s16*, 0xA) >= t) {
            M2C_FIELD(arg0, s16*, 0xA) = D_800971F8[0].unk1C + 0x100;
        }
    }
    if (M2C_FIELD(arg0, s16*, 0xE) < (D_800971F8[0].unk22 + 0x40)) {
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
