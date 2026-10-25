#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj D_800CCED0;

void func_800EE27C(void* self) {
    s8 hi;
    struct X4_EngineObj* e;

    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        M2C_FIELD(self, s16*, 0x7C) = 2;
        hi = g_Player.hp & 0x80;
        e = (struct X4_EngineObj*)((s8*)&D_800CCED0 - -g_Player.unk2);
        if ((g_Player.hp & 0x7F) >= e->unk5C[-1]) {
            g_Player.hp = hi | e->unk5C[-1];
            M2C_FIELD(self, s16*, 0x7C) = 0x1B;
            M2C_FIELD(self, s8*, 6) += 1;
        } else {
            g_Player.hp = hi | (g_Player.hp + 1);
        }
        ((void (*)(s32, s32, s32, void*))func_80016C48)(0, 0xD, 0, self);
    }
}
#undef g_Player
