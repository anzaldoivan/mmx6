#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0();
s32 func_8002D354(void* arg0, s32 arg1, s32 arg2);
void func_8002D3B4(void*, s32);
extern s32 D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

void func_800EC9D0(struct X4_MainObj* self) {
    ((void (*)())func_80017A04)();
    if (--self->unk7C == 0) {
        self->unk5 = 8;
        self->unk6 = 0;
    }
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, s32*, 0x90) + 1;
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, u8*, 0x90) & 3;
    if (M2C_FIELD(self, u8*, 0x90) == 0) {
        func_8002D3B4(self, func_8002D354(self, D_800970A0.x_pos.val,
                                          D_800970A0.y_pos.val) &
                                0xFF);
    }
    func_8002D2B0(self);
}
#undef D_800970A0
