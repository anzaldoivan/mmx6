#include "../shared/entity/state_dispatch.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                     /* extern */
M2C_UNK move_by_velocity(void*);              /* extern */
M2C_UNK player_enter_ladder_climb_up(void*);  /* extern */
M2C_UNK player_set_animation(void*, M2C_UNK); /* extern */

void func_80037488(void* arg0) {
    animate_object();
    move_by_velocity(arg0);
    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        player_set_animation(arg0, 0x1F);
        player_enter_ladder_climb_up(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();       /* extern */
void func_8003ADB4(void* arg0); /* extern */
void set_pose_size();           /* extern */

void func_800374D8(void* arg0) {
    ((void (*)())animate_object)();
    if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x10;
        M2C_FIELD(arg0, s16*, 0x1E) = M2C_FIELD(arg0, s16*, 0xE) - 0x10;
        set_pose_size(arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        func_8003ADB4(arg0);
    }
}
