// prog SLUS_013.95 | system cling | range 0x80046E14-0x800472CC
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/cling.h"
#include "mmx6/globals.h"
#include "mmx6/pilot_globals.h"

// kept here: the objfields census types g_Player.m only from a file-scope declaration
extern struct X4_PlayerObj g_Player;

#define CHECK()                                                                \
    t = player->y_pos.i.hi + box->unk1 - box->unk3;                            \
    if (var_s3 >= t) {                                                         \
        d = var_s3 - t;                                                        \
        player->hit_damage = 0x7F;                                             \
        player->y_pos.i.hi = d + player->y_pos.i.hi;                           \
        player->unk71 |= 4;                                                    \
    }

// 0x80046E14 clamp_player_to_ceiling: player/ceiling position compare.
// basis: community tweaks-index.tsv:257
// callers: none known
void clamp_player_to_ceiling(struct X4_MainObj* self) {
    struct X4_MainObj* arg0 = self;
    struct X4_PlayerObj* player = &g_Player;
    s16 var_s3;
    s16 t;
    s16 d;
    s32 flag;
    struct X4_Unk_unk68* box;

    if (g_playthrough_state.stage >= 0x13) {
        if (g_playthrough_state.checkpoint != 0) {
            return;
        }
    } else if (g_playthrough_state.stage != 4 &&
               g_playthrough_state.checkpoint != 2) {
        return;
    }
    if (g_Player.nova_strike_active == 2) {
        return;
    }
    background_objects[1].unk18.i.hi = background_objects[1].y_pos.i.hi;
    ceiling_state_table[arg0->state](arg0);
    if (background_objects[0].unk20 != background_objects[0].unk22) {
        background_objects[0].unk34 = 0;
    }
    background_objects[1].y_pos.i.hi =
        background_objects[0].y_pos.i.hi + arg0->unk2 - (arg0->unk1C.val >> 16);
    if ((player->action == 0x1F && player->action_phase < 4) ||
        player->action == 0x3F) {
        s16 diff =
            background_objects[1].y_pos.i.hi - background_objects[1].unk18.i.hi;
        if (diff > 0) {
            player->y_pos.i.hi -= diff;
        }
    }
    if (g_playthrough_state.stage >= 0x13) {
        if ((box = player->terrain_box) != 0) {
            if (g_Player.x_pos.i.hi >= 0xB50 ||
                g_playthrough_state.checkpoint == 1) {
                ((void (*)())clear_object_slot)(arg0);
                return;
            }
            var_s3 = background_objects[0].y_pos.i.hi -
                     background_objects[1].y_pos.i.hi + 0xF0;
            CHECK();
        }
    } else if (g_playthrough_state.stage == 4) {
        if (g_playthrough_state.substage != 0) {
            if ((box = player->terrain_box) != 0) {
                if (g_Player.x_pos.i.hi >= 0x1180 ||
                    g_playthrough_state.checkpoint == 1) {
                    ((void (*)())clear_object_slot)(arg0);
                    return;
                }
                if (player->x_pos.i.hi >= 0x10A1) {
                    return;
                }
                var_s3 = background_objects[0].y_pos.i.hi -
                         background_objects[1].y_pos.i.hi + 0xF0;
                CHECK();
            }
        } else {
            if ((box = player->terrain_box) != 0) {
                if (g_Player.y_pos.i.hi >= 0x500 ||
                    g_playthrough_state.checkpoint >= 2) {
                    ((void (*)())clear_object_slot)(arg0);
                    return;
                }
                if (g_playthrough_state.checkpoint == 0) {
                    if (player->x_pos.i.hi >= 0x1381) {
                        return;
                    }
                    var_s3 = background_objects[0].y_pos.i.hi -
                             background_objects[1].y_pos.i.hi + 0x100;
                } else {
                    if (player->x_pos.i.hi >= 0x13C1) {
                        return;
                    }
                    var_s3 = background_objects[0].y_pos.i.hi -
                             background_objects[1].y_pos.i.hi + 0x2E0;
                }
                CHECK();
            }
        }
    } else {
        if ((box = player->terrain_box) != 0) {
            if (g_playthrough_state.checkpoint >= 3) {
                ((void (*)())clear_object_slot)(arg0);
                return;
            }
            flag = 0;
            if (player->x_pos.i.hi < 0x780) {
                if (player->x_pos.i.hi >= 0x741) {
                    return;
                }
                flag = 1;
                var_s3 = background_objects[0].y_pos.i.hi -
                         background_objects[1].y_pos.i.hi + 0x7D1;
            } else if (player->x_pos.i.hi < 0xF00) {
                if (player->x_pos.i.hi < 0x900 || player->x_pos.i.hi >= 0xEC1) {
                    return;
                }
                flag = 1;
                var_s3 = background_objects[0].y_pos.i.hi -
                         background_objects[1].y_pos.i.hi + 0x811;
            } else if (player->x_pos.i.hi < 0x17C0) {
                if (player->x_pos.i.hi < 0x1090 ||
                    player->x_pos.i.hi >= 0x1781) {
                    return;
                }
                flag = 1;
                var_s3 = background_objects[0].y_pos.i.hi -
                         background_objects[1].y_pos.i.hi + 0x831;
            }
            if (flag != 0) {
                t = player->y_pos.i.hi + box->unk1 - box->unk3;
                if (var_s3 >= t) {
                    d = var_s3 - t;
                    player->hit_damage = 0x7F;
                    player->y_pos.i.hi = d + player->y_pos.i.hi;
                    player->unk71 |= 4;
                }
            }
        }
    }
    if (background_objects[0].unk20 != background_objects[0].unk22) {
        background_objects[0].unk34 = 0;
    }
}
