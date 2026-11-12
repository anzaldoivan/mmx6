#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

void animate_object(struct X4_AnimatedObj*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK set_stand_animation_by_hp(void*);
M2C_UNK func_801EBF28();
extern struct X4_EngineObj g_playthrough_state;

void update_x_stand_animation(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
        func_801EBF28(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x90) != 0) {
        set_stand_animation_by_hp(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x17) == 6) {
        struct X4_EngineObj* e =
            (struct X4_EngineObj*)((s8*)&g_playthrough_state -
                                   -M2C_FIELD(arg0, s8*, 2));
        if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)(M2C_FIELD(e, s8*, 0x5B) / 3)) {
            player_set_animation(arg0, 5);
            return;
        }
    }
    animate_object(arg0);
}
