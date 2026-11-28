#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_shot_types(void*);         /* extern */
M2C_UNK react_to_weapon_change(void*); /* extern */
void player_reset_charge();            /* extern */

void func_8003F000(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, s8*, 0x93) = 0;
        player_reset_charge();
        set_shot_types(arg0);
        react_to_weapon_change(arg0);
    }
}
