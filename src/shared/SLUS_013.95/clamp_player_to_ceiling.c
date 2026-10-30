#include "common.h"
#include "mmx6/x4.h"

extern void (*D_800762C0[])(struct X4_MainObj*);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
s32 clear_object_slot();

#define PLAYER_E6 (((s8*)player)[0xE6])
#define CHECK()                                                                \
    t = player->y_pos.i.hi + box->unk1 - box->unk3;                            \
    if (var_s3 >= t) {                                                         \
        d = var_s3 - t;                                                        \
        PLAYER_E6 = 0x7F;                                                      \
        player->y_pos.i.hi = d + player->y_pos.i.hi;                           \
        player->unk71 |= 4;                                                    \
    }

// 0x80046E14 clamp_player_to_ceiling: player/ceiling position compare.
// basis: community tweaks-index.tsv:257
// callers: none known
void clamp_player_to_ceiling(struct X4_MainObj* self) {
    struct X4_MainObj* arg0 = self;
    // !FAKE: depin: dropping it breaks the match (270/303)
    register struct X4_PlayerObj* player asm("$18") = &g_Player;
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
    D_800762C0[arg0->state](arg0);
    if (background_objects[0].unk20 != background_objects[0].unk22) {
        background_objects[0].unk34 = 0;
    }
    background_objects[1].y_pos.i.hi =
        background_objects[0].y_pos.i.hi + arg0->unk2 - (arg0->unk1C.val >> 16);
    if ((player->unk5 == 0x1F && player->unk6 < 4) || player->unk5 == 0x3F) {
        s16 diff =
            background_objects[1].y_pos.i.hi - background_objects[1].unk18.i.hi;
        if (diff > 0) {
            player->y_pos.i.hi -= diff;
        }
    }
    if (g_playthrough_state.stage >= 0x13) {
        if ((box = player->unk68) == 0) {
            goto end;
        }
        if (g_Player.x_pos.i.hi >= 0xB50 ||
            g_playthrough_state.checkpoint == 1) {
            goto call;
        }
        var_s3 = background_objects[0].y_pos.i.hi -
                 background_objects[1].y_pos.i.hi + 0xF0;
        CHECK();
        goto end;
    } else if (g_playthrough_state.stage == 4) {
        if (g_playthrough_state.substage != 0) {
            if ((box = player->unk68) == 0) {
                goto end;
            }
            if (g_Player.x_pos.i.hi >= 0x1180 ||
                g_playthrough_state.checkpoint == 1) {
                goto call;
            }
            if (player->x_pos.i.hi >= 0x10A1) {
                return;
            }
            var_s3 = background_objects[0].y_pos.i.hi -
                     background_objects[1].y_pos.i.hi + 0xF0;
            CHECK();
            goto end;
        }
        if ((box = player->unk68) == 0) {
            goto end;
        }
        if (g_Player.y_pos.i.hi >= 0x500 ||
            g_playthrough_state.checkpoint >= 2) {
            goto call;
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
        goto check;
    } else {
        if ((box = player->unk68) == 0) {
            goto end;
        }
        if (g_playthrough_state.checkpoint >= 3) {
        call:
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
            if (player->x_pos.i.hi < 0x1090 || player->x_pos.i.hi >= 0x1781) {
                return;
            }
            flag = 1;
            var_s3 = background_objects[0].y_pos.i.hi -
                     background_objects[1].y_pos.i.hi + 0x831;
        }
        if (flag != 0) {
        check:
            t = player->y_pos.i.hi + box->unk1 - box->unk3;
            if (var_s3 >= t) {
                d = var_s3 - t;
                PLAYER_E6 = 0x7F;
                player->y_pos.i.hi = d + player->y_pos.i.hi;
                player->unk71 |= 4;
            }
        }
    }
end:
    if (background_objects[0].unk20 != background_objects[0].unk22) {
        background_objects[0].unk34 = 0;
    }
}
