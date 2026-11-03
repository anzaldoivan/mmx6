#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void player_load_weapon_palette(struct X4_PlayerObj* self);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);
M2C_UNK set_shot_types(void* self);
void player_reset_charge();

M2C_UNK refresh_weapon_state(void* arg0) {
    s8* p = arg0;
    s8 mode;

    if (p[2] == 0) {
        player_reset_charge();
        set_shot_types(p);
        player_load_weapon_palette((struct X4_PlayerObj*)p);
        mode = p[0x93];
        if (mode == 1) {
            player_spawn_visual(1, 0x1B, 0, 0);
        } else if (mode == 6) {
            player_spawn_visual(1, 0x1B, 0xA, 0);
        } else if (mode == 8) {
            player_spawn_visual(1, 0x1B, 0xC, 0);
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

void silence_sound(u8, u8);
void clear_flash_palette(void* arg0);

void player_reset_charge(struct X4_PlayerObj* self) {
    silence_sound(1, 7);
    clear_flash_palette(self);
    self->charge_state[0] = 0;
    self->charge_state[1] = 0;
    self->charge_timer = 0;
    self->special_charge_timer = 0;
}
