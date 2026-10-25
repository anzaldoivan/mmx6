#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object();
s32 func_8002D354(void* arg0, s32 arg1, s32 arg2);
void set_velocity_from_angle(void*, s32);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EA294(struct X4_MainObj* self) {
    ((void (*)())func_80017A04)();
    if (--self->unk7C == 0) {
        self->unk5 = 8;
        self->unk6 = 0;
    }
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, s32*, 0x90) + 1;
    M2C_FIELD(self, s32*, 0x90) = M2C_FIELD(self, u8*, 0x90) & 3;
    if (M2C_FIELD(self, u8*, 0x90) == 0) {
        set_velocity_from_angle(
            self,
            func_8002D354(self, g_Player.x_pos.val, g_Player.y_pos.val) & 0xFF);
    }
    move_object(self);
}
#undef g_Player
