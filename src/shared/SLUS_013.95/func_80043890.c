#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
s32 get_weapon_energy_cost(void* arg0, s32 arg1);
void use_weapon_energy(void*, s32);

#define SB(o) (*(s8*)((u8*)self + (o)))
#define UB(o) (*(u8*)((u8*)self + (o)))
#define SH(o) (*(s16*)((u8*)self + (o)))
#define UH(o) (*(u16*)((u8*)self + (o)))
#define ENERGY(p, i) (*(s16*)((u8*)(p) + ((i) << 1) + 0xA8))

void func_80043890(struct X4_MainObj* self) {
    struct X4_PlayerObj* player;
    s32 flag;
    s32 i;
    s32 arg;
    s32 b;
    s32 t;
    s32 v;
    u8 f;

    if (SH(0x94) != 0x1000) {
        SH(0x94) = (UH(0x94) + 0x22) & 0xFFF;
    }
    f = UB(0x93) & 0xFE;
    player = &g_Player;
    UB(0x93) = f;
    if (f & 2) {
        if ((s16)(++SH(0x88) % 20) == 0) {
            UB(0x93) = f | 1;
        }
        if (SH(0x88) >= 0x1E1) {
            SH(0x88) = 0;
            UB(0x93) = UB(0x93) & 0xFD;
        }
    } else {
        flag = 0;
        if (player->unk2 != 0) {
            if (player->input.buttons.held & 4) {
                if (player->pressed_input & 0x20) {
                    player->weapon = 3;
                    goto set;
                }
            }
        } else if (player->pressed_input & 0x10) {
        set:
            flag = 1;
        }
        if (flag == 1 && UB(0x8D) != 7) {
            i = 0;
            b = 1;
            do {
                if (!((UB(0x8D) >> i) & 1)) {
                    if (player->unk2 != 0) {
                        if (ENERGY(player, 3) >=
                            get_weapon_energy_cost(player, 3)) {
                            arg = player->weapon;
                            goto give;
                        }
                    } else {
                        if (ENERGY(player, player->weapon) >=
                            get_weapon_energy_cost(player, player->weapon)) {
                            arg = self->id;
                        give:
                            use_weapon_energy(player, arg);
                            {
                                // !FAKE: depin: dropping it breaks the match (186/192)
                                register s32 m asm("$3") = UB(0x8D);
                                m |= b << i;
                                UB(0x8D) = m;
                            }
                        }
                    }
                }
                i++;
            } while (i < 3);
        }
        if (UH(0x8C) == 3) {
            self->state = 2;
            SB(0x8F) = 1;
            return;
        }
        if (SH(0x94) != 0x1000) {
            if (self->id == 0xA && UB(0x8D) == 7) {
                self->id = 1;
                UB(0x93) = 2;
                return;
            }
            if (player->shot_type == 0xA) {
                if (ENERGY(player, player->weapon) >=
                    get_weapon_energy_cost(player, player->weapon)) {
                    use_weapon_energy(player, self->id);
                    {
                        // !FAKE: depin: dropping it breaks the match (88/192)
                        register s32 s asm("$3") = 7;
                        UB(0x8D) = s;
                    }
                    v = 2;
                    goto store;
                }
            }
            if (player->unk2 != 0) {
                t = player->pressed_input & 0x30;
            } else {
                t = player->pressed_input & 0x10;
            }
            if (t != 0) {
                v = 1;
            store:
                UB(0x93) = v;
            }
        }
    }
}
