#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
extern struct X4_PlayerObj D_800970A0;
extern s8 D_8009724F;
extern s8 D_800CCEF6;

void func_800EC580(void* self) {
    M2C_FIELD(self, s32*, 0x80) = 0;
    M2C_FIELD(self, s32*, 0x84) = 0;
    M2C_FIELD(self, s32*, 0x88) = 0;
    M2C_FIELD(self, s32*, 0x8C) = 0;
    M2C_FIELD(self, s32*, 0x90) = 0;
    M2C_FIELD(self, s32*, 0x94) = 0;
    if (M2C_FIELD(self, s8*, 0x2) >= 4) {
        D_8009724F = 0;
        D_800CCEF6 = 1;
        if ((M2C_FIELD(self, s8*, 0x2) == 5) &&
            (D_800970A0.x_pos.i.hi < 0x3B0)) {
            if (D_800970A0.y_pos.i.hi < 0x1B0) {
                D_800970A0.y_pos.i.hi = 0x1B0;
            }
        } else {
            func_8002C9B0(self);
        }
    } else {
        func_8002C9B0(self);
    }
}
