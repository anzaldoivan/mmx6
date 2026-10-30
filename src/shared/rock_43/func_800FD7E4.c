#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern s32 D_800FDE30;
extern s32 D_800FE294;

void func_800FD7E4(void* arg0) {
    if ((M2C_FIELD(&D_800FDE30, s32*, 0x460) != 0) || (D_800FE294 != 0)) {
        M2C_FIELD(arg0, u8*, 4) += 1;
        return;
    }
    check_enemy_hits(arg0);
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 10) {
            M2C_FIELD(arg0, u8*, 0x16) = 4;
            M2C_FIELD(arg0, u8*, 5) += 1;
        }
        break;
    case 1:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 100) {
            M2C_FIELD(arg0, u8*, 4) += 1;
        }
        break;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    func_80017A04(arg0);
    move_object(arg0);
}
