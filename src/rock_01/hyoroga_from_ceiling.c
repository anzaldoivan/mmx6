#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);
void attack_hyoroga_from_ceiling(u8* arg0);
s32 func_801ECCD4(void*);

// 0x801ECA50 try_hyoroga_from_ceiling: starts the Hyoroga from the ceiling when weapon energy allows: animation, sound, energy use, state 0x3F.
// basis: xref attack_hyoroga_from_ceiling (docs/leads/derived.tsv:31)
// callers: none known (no jal caller)
s32 try_hyoroga_from_ceiling(u8* p) {
    if (get_weapon_energy_cost(p, 1) <= *(s16*)(p + 0xAA)) {
        if (func_801ECCD4(p) != 0) {
            player_set_animation(p, 0x64);
            play_sound(1, 0x14, p);
            p[0x84] = 0;
            p[0x86] = 0;
            p[0x93] = 1;
            use_weapon_energy(p, 1);
            p[5] = 0x3F;
            p[6] = 0;
            attack_hyoroga_from_ceiling(p);
            return 1;
        }
        return 0;
    }
    return 0;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
void* func_8002C32C();
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK func_801ECD54();

// 0x801ECAF0 attack_hyoroga_from_ceiling: Hyoroga attack from ceiling.
// basis: community tweaks-index.tsv:194
// callers: try_hyoroga_from_ceiling
void attack_hyoroga_from_ceiling(u8* arg0) {
    s32 i;
    u8 bits;
    u8* obj;

    if (((s8*)arg0)[6] == 0) {
        arg0[6]++;
    } else {
        if (((s8*)arg0)[7] != 0) {
            arg0[7]--;
        }
        animate_object(arg0);
        func_801ECD54(arg0, 0x30);
        bits = arg0[0x45];
        if (bits & 0x40) {
            arg0[0x45] = bits & 0xBF;
            i = 0;
            do {
                obj = func_8002C32C();
                if (obj != 0) {
                    obj[0] = 0x21;
                    obj[1] = 0x21;
                    obj[2] = i;
                    obj[0x14] = arg0[0x14];
                }
                i++;
            } while (i < 3);
        }
    }
    if (((s8*)arg0)[0x46] == 0) {
        player_set_animation(arg0, 0x54);
        arg0[0x8E] = 0;
        arg0[5] = 0x1F;
        arg0[6] = 3;
    }
}
