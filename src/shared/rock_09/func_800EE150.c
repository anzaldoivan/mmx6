#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK func_8004E78C(M2C_UNK);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_800EE150(void* self) {
    struct X4_VisualObj* obj;

    if (g_Player.unk5 == 0x14) {
        ((void (*)(s32))func_8004E78C)(1);
        M2C_FIELD(self, s8*, 0) |= 8;
        if ((g_Player.hp & 0x7F) >=
            ((struct X4_EngineObj*)((s8*)&g_playthrough_state - -g_Player.unk2))
                ->sub_tanks[-1]) {
            ((void (*)(void*, s32))set_animation)(self, 2);
            M2C_FIELD(self, s8*, 6) += 1;
            return;
        }
        ((void (*)(s32, s32, void*))play_sound)(2, 0x55, self);
        ((void (*)(void*, s32))set_animation)(self, 1);
        M2C_FIELD(self, s16*, 0x7C) = 0x1F;
        M2C_FIELD(self, s8*, 6) += 2;
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0xE;
            obj->unk2 = 0;
            obj->unk16 = 1;
            obj->unk15 = 0;
            obj->unk50 = self;
        }
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0xE;
            obj->unk2 = 1;
            obj->unk16 = 6;
            obj->unk15 = 0;
            obj->unk50 = self;
        }
    }
}
#undef g_Player
