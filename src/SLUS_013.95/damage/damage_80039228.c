// prog SLUS_013.95 | system damage | range 0x80039228-0x80039638
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/class4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/state.h"
#include "mmx6/damage.h"
#include "mmx6/engine_state.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

#define ENG_98 M2C_FIELD(e, s32*, 0x98)

// 0x80039228 update_player_damage: damage pass each frame: crush and spike deaths, hit damage, invincibility countdown; a pending hurt (hp bit 7) runs start_hurt and refills energy.
// basis: code via=invincibility_timer; derived.tsv:91
// callers: update_player
void update_player_damage(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    struct Class4Obj* p;
    s32 i;
    s32 v;
    s16 lim;
    s16 cur;
    s16* q;
    s32 best;
    s16 m;

    if (self->action == 0) {
        return;
    }
top:
    if (self->action == 1) {
        return;
    }
    if ((self->collision_flags & 0xC) == 0xC) {
        {
            void* e = &g_playthrough_state;
            ENG_98 += *(u8*)&self->hp & 0x7F;
        }
        self->hp = -0x80;
    }
    if ((self->collision_flags & 3) == 3) {
        {
            void* e = &g_playthrough_state;
            ENG_98 += *(u8*)&self->hp & 0x7F;
        }
        self->hp = -0x80;
    }
    if (self->hp != -0x80 && ((self->latched_collision_flags & 0xC) == 0xC ||
                              (self->latched_collision_flags & 3) == 3)) {
        if (self->character == 0) {
            D_8009711A = 0;
            if (self->nova_strike_active == 1) {
                self->nova_strike_active = 0;
                D_800CCEEC = 0;
                func_8002ABA8();
            }
        } else {
            D_8009711A = 0;
        }
        self->unkE5 = 0x4B;
        {
            u8 b;
            b = *(u8*)& self->hp &= 0x7F;
            if (*(s8*)&self->hit_damage >= b) {
                {
                    void* e = &g_playthrough_state;
                    ENG_98 += b;
                }
            }
        }
        p = (struct Class4Obj*)g_class4_slots;
        *(u8*)&self->hp -= self->hit_damage;
        for (i = 0x4F; i >= 0; i--) {
            p->unk76 = 0;
            p->unk72 = 0;
            p++;
        }
        if (self->hp > 0) {
            *(u8*)&self->hp |= 0x80;
            self->unkCA = 0;
            self->hurt_type = 1;
            self->hit_facing = self->facing;
            if ((u32)(self->armor - 1) < 4) {
                self->hurt_type = 4;
            }
            {
                void* e = &g_playthrough_state;
                ENG_98 += *(s8*)&self->hit_damage;
            }
        } else {
            self->hp = -0x80;
        }
    }
    if (self->touching_spikes != 0 && self->invincibility_timer == 0 &&
        self->spike_immune != 1) {
        {
            void* e = &g_playthrough_state;
            ENG_98 += (u8)D_800970FC & 0x7F;
        }
        self->hp = -0x80;
    }
    if (self->hp == -0x80) {
        self->hp = 0;
        D_800CCEEC = 1;
        cancel_player_attack(arg0);
        refresh_weapon_state(arg0);
        self->terrain_box = 0;
        self->unk54 = 0;
        self->state = 2;
        self->action = 0;
        self->action_phase = 0;
        return;
    }
    if (self->invincibility_timer != 0) {
        if (self->invincibility_timer >= 0x3C) {
            --*(u8*)&self->invincibility_timer;
        } else if (!(self->equipped_parts & 0x400) ||
                   (D_80097420.frame_counter & 1)) {
            if ((self->invincibility_timer =
                     (u8)self->invincibility_timer - 1) == 0) {
                self->hurt_phase = 0;
                player_load_weapon_palette(arg0);
            }
        }
    }
    if (self->hp > 0) {
        return;
    }
    start_hurt(arg0);
    if (self->character == 0) {
        lim = self->giga_energy_max;
        v = lim / 8;
        self->weapon_energy[0] += v;
        if (lim < self->weapon_energy[0] || lim - self->weapon_energy[0] < v) {
            self->weapon_energy[0] = self->giga_energy_max;
        }
    } else {
        self->weapon_energy[5] += get_weapon_energy_cost(arg0, 5) / 2;
        if (self->weapon_energy[5] >= self->giga_energy_max) {
            self->weapon_energy[5] = self->giga_energy_max;
        }
    }
    best = 0;
    if (self->equipped_parts & 0x800) {
        s16* arr;
        s32 mm;
        u16 ul;
        i = 1;
        arr = &self->weapon_energy[0];
        q = &self->weapon_energy[1];
        mm = self->weapon_energy[0];
        ul = *(u16*)&self->giga_energy_max;
        do {
            cur = *q;
            if (cur < mm) {
                mm = cur;
                best = i;
            }
            i++;
            q++;
        } while (i < 9);
        mm += 0xC;
        if ((s16)ul < mm) {
            mm = (s16)ul;
        }
        {
            s32 o = best * 2;
            *(s16*)((s8*)arr + o) = mm;
        }
    }
}
