#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
s32 func_8002D654(s8*, u8*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK g_Player;

void func_800EDBB4(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    move_object((s32)arg0);
    if (func_80030ECC(arg0) == 0) {
        if (func_80031474(arg0) < 0) {
        block_2:
            func_80049E50(arg0);
        } else if (func_8002D654((s8*)arg0, (u8*)&g_Player) == 0) {
            if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
                goto block_2;
            }
            if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
                func_8002CCB0(arg0, 0x10, 0x10);
                return;
            }
        }
    }
    M2C_FIELD(arg0, u8*, 4)++;
}
