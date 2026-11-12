/* Adapted from sozud/mmx4 @4e16dfc src/main/object_update.c:func_80021C14, AGPL-3.0; proven shared with X6 by exact signature cac1f7cae392 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
extern struct X4_EngineObj g_playthrough_state;
extern void (*D_80071380[])(struct X4_RideArmorObj*);

void func_80020A08(void) {
    if (g_playthrough_state.unk10 == 0) {
        if (D_800CD340.active != 0) {
            D_80071380[D_800CD340.id](&D_800CD340);
            return;
        }
    } else if (D_800CD340.active != 0) {
        if (D_800CD340.active & 8) {
            D_80071380[D_800CD340.id](&D_800CD340);
            return;
        }
        if (D_800CD340.on_screen != 0) {
            func_8002CD6C(&D_800CD340);
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
extern M2C_UNK g_Player;

void func_80020AA8(struct X4_AnimatedObj* arg0) {
    struct X4_PlayerObj* pl = &g_Player;
    s32 var_v1;
    s8 temp_a1;

    temp_a1 = arg0->unk2;
    arg0->x_pos.val = pl->x_pos.val;
    arg0->y_pos.val = pl->y_pos.val;
    if (temp_a1 == 3) {
        if ((pl->action == 0x23) && (pl->action_phase > 0)) {
            arg0->on_screen = 1;
            if (arg0->action_phase != pl->action_phase) {
                arg0->action_phase = pl->action_phase;
                if (pl->y_vel.val > 0) {
                    set_animation(arg0, 0x2B);
                } else if (pl->y_vel.val < 0) {
                    set_animation(arg0, 0x2C);
                } else {
                    set_animation(arg0, 0x2A);
                }
            }
            arg0->unk15 = pl->facing;
            animate_object(arg0);
            return;
        }
        set_animation(arg0, 0x2A);
        {
            // !FAKE: depin: dropping it breaks the match (100/102)
            register s32 two asm("$2") = 2;
            arg0->action_phase = two;
        }
        arg0->on_screen = 0;
        return;
    }
    if (arg0->state == 0) {
        var_v1 = 1;
        if (temp_a1 == 0) {
            var_v1 = 2;
        }
        if ((pl->charge_state[0] == var_v1) ||
            (pl->charge_state[1] == var_v1)) {
            arg0->on_screen = 1;
            set_animation(arg0, temp_a1 + 8);
            {
                // !FAKE: depin: dropping it breaks the match (99/102)
                register s32 t asm("$2") = (u8)arg0->state + 1;
                arg0->state = t;
            }
        }
    } else {
        if ((pl->charge_state[0] == 0) && (pl->charge_state[1] == 0)) {
            arg0->on_screen = 0;
            arg0->state = 0;
            return;
        }
        animate_object(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

void func_80017B04(u8*, s16, s16); /* extern */
void func_8002000C(void);          /* extern */
void func_8002012C(void);          /* extern */
void func_80020258(void);          /* extern */
void func_80020378(void);          /* extern */
void func_8002048C(void);          /* extern */
void func_800205A0();              /* extern */
void func_800206C0(void);          /* extern */
void func_800207D4(void);          /* extern */
void update_layer_objects(void);   /* extern */
void func_80020A08(void);          /* extern */
void run_text_box(void);           /* extern */
M2C_UNK func_80020D74();           /* extern */
void func_80020DC8(void);          /* extern */
void func_8002927C(void);          /* extern */
void func_8002935C(void);          /* extern */
void func_800293CC();              /* extern */
void func_80029D18(void);          /* extern */
void func_8002ACA8();     /* extern; was M2C_UNK (W14 regate of 2ACA8) */
void func_8002E84C(void); /* extern */
void func_8002F288(struct X4_PlayerObj*); /* extern */
void func_80034DCC(void);                 /* extern */
M2C_UNK read_player_input();              /* extern */
extern M2C_UNK g_Player;

void func_80020C40(void) {
    func_8002E84C();
    read_player_input();
    func_80020A08();
    func_80034DCC();
    func_8002012C();
    update_layer_objects();
    func_8002000C();
    func_80020258();
    func_80020378();
    func_800205A0();
    func_800206C0();
    func_800207D4();
    func_80029D18();
    func_8002048C();
    run_text_box();
    func_8002F288(&g_Player);
    func_8002927C();
    func_8002935C();
    func_800293CC();
    func_8002ACA8();
    func_80020D74();
    func_80020DC8();
    func_80017B04(&g_Player, 0x140, 0);
}
