#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();
M2C_UNK func_80030ECC(void*);
extern s32 D_800F6AB4;

void func_800EAF68(void* self) {
    void* parent;
    u8 dir;
    s8 step;

    parent = M2C_FIELD(self, void**, 0x7C);
    dir = M2C_FIELD(parent, u8*, 0x15);
    M2C_FIELD(self, u8*, 0x15) = dir;
    if (dir == 0) {
        M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) - 0x2D;
    } else {
        M2C_FIELD(self, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + 0x2D;
    }
    M2C_FIELD(self, s16*, 0xE) =
        M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s16*, 0xE) + 3;
    if (M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s8*, 4) != 2) {
        step = M2C_FIELD(self, s8*, 5);
        M2C_FIELD(self, s8*, 6)++;
        switch (step) {
        case 0:
            if (M2C_FIELD(self, s8*, 0x46) == 0) {
                ((void (*)(void*, s32))func_800179A4)(self, 0xD);
                M2C_FIELD(self, void**, 0x50) = &D_800F6AB4;
                M2C_FIELD(self, s8*, 5)++;
            }
            break;
        case 1:
            if (M2C_FIELD(self, s8*, 6) == 0x5A) {
                ((void (*)(void*, s32))func_800179A4)(self, 0xE);
                M2C_FIELD(self, void**, 0x50) = 0;
                M2C_FIELD(self, s8*, 5)++;
            }
            break;
        case 2:
            if (M2C_FIELD(self, s8*, 0x46) == 0) {
                goto next;
            }
            break;
        }
        func_80030ECC(self);
        func_80017A04(self);
        func_8002D230(self);
        if (func_8002CBFC(self, 0x20, 0x20) == 0) {
            func_8002CCB0(self, 0x20, 0x20);
            return;
        }
        if ((u8)(M2C_FIELD(M2C_FIELD(self, void**, 0x7C), u8*, 2) - 4) < 2) {
            return;
        }
    }
next:
    M2C_FIELD(self, s8*, 4)++;
}
