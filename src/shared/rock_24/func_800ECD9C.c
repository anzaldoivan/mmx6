#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_EngineObj D_800CCED0;

void func_800ECD9C(void* self) {
    s8 hi;
    struct X4_EngineObj* e;

    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        M2C_FIELD(self, s16*, 0x7C) = 2;
        hi = D_800970A0.hp & 0x80;
        e = (struct X4_EngineObj*)((s8*)&D_800CCED0 - -D_800970A0.unk2);
        if ((D_800970A0.hp & 0x7F) >= e->unk5C[-1]) {
            D_800970A0.hp = hi | e->unk5C[-1];
            M2C_FIELD(self, s16*, 0x7C) = 0x1B;
            M2C_FIELD(self, s8*, 6) += 1;
        } else {
            D_800970A0.hp = hi | (D_800970A0.hp + 1);
        }
        ((void (*)(s32, s32, s32, void*))func_80016C48)(0, 0xD, 0, self);
    }
}
#undef D_800970A0
