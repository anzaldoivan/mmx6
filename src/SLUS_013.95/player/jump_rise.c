#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80017A04();                    /* extern */
s32 select_air_dash(void*);                 /* extern */
s32 func_80039984(void*);                   /* extern */
s32 try_enter_wall_cling(void*);                   /* extern */
s32 func_8003A488(void*);                   /* extern */
void func_8003D18C(void* arg0);             /* extern */
void func_8003D394(void* arg0);             /* extern */
s32 func_8003E174(void*);                   /* extern */
void player_set_animation_shooting(struct X4_PlayerObj* self,
                                   s32 animation); /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK);             /* extern */
s32 func_801EA454(void*);                          /* extern */
s32 func_801EA560(void*);                          /* extern */
s32 func_801EBF94(void*);                          /* extern */

// 0x80035620 handle_jump_rise: jump rising state.
// basis: community tweaks-index.tsv:231
// callers: none known
void handle_jump_rise(struct X4_PlayerObj* arg0) {
    s32 var_v0;

    if (arg0->move_lock != 0) {
        arg0->y_vel.val = 0;
    }
    if (arg0->unk88.bytes.collision_flags & 4) {
        arg0->y_vel.val = 0;
    }
    if (!(arg0->input.buttons.held & 0x80)) {
        arg0->y_vel.val = 0;
    }
    if (arg0->unk2 == 0) {
        var_v0 = func_8003E174(arg0);
        goto block_11;
    }
    if ((func_801EA560(arg0) == 0) && (func_801EA454(arg0) == 0)) {
        var_v0 = func_801EBF94(arg0);
    block_11:
        if (var_v0 == 0) {
            func_80017A04(arg0);
            {
                // !FAKE: depin: dropping it breaks the match (93/98)
                register s32 t asm("$2") = arg0->animation_step.fields.event & 0x80;
                if (t) {
                    *(u8*)&arg0->animation_step.fields.event =
                        (u8)(*(u8*)&arg0->animation_step.fields.event & 0x3F);
                    play_sound(1, 1, arg0);
                }
            }
            if ((func_8003A488(arg0) == 0) && (func_80039984(arg0) == 0)) {
                if (arg0->wall_cling_delay == 0) {
                    if (try_enter_wall_cling(arg0) != 0) {
                        return;
                    }
                } else {
                    --*(u8*)&arg0->wall_cling_delay;
                }
                if (select_air_dash(arg0) == 0) {
                    func_8003D18C(arg0);
                    func_8003D394(arg0);
                    if (arg0->y_vel.val <= 0) {
                        player_set_animation_shooting(arg0, 0xB);
                        {
                            s32 m = -1;
                            s32 n = 7;
                            arg0->air_state = m;
                            *(u8*)&arg0->unk5 = n;
                        }
                        *(u8*)&arg0->unk6 = 0;
                        return;
                    }
                    func_8003F508(arg0, 0xA);
                }
            }
        }
    }
}
