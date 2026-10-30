#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
s32 func_801EE34C();
void func_8002F06C(void*);
void* func_8003D480(M2C_UNK, s8, s8, void*);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_801F3AB0[];
extern s32 D_801F3AB8[];

#define F_8C(p) (*(s16*)((u8*)(p) + 0x8C))

void func_801F23C8(struct X4_WeaponObj* arg0) {
    s32 x;
    s32 mask;
    struct X4_PlayerObj* player;
    // !FAKE: depin: dropping it breaks the match (114/117)
    register s32 t asm("$3");

    func_80017A04(ANIMATED_OBJECT(arg0));
    move_object(MOVING_OBJECT(arg0));
    player = &g_Player;
    x = arg0->x_pos.val;
    if (arg0->unk6 == 0) {
        switch (player->unk5) {
        case 9:
        case 10:
        case 11:
        case 14:
        case 15:
        case 16:
        case 27:
        case 28:
        case 32:
            arg0->unk6 = 1;
            F_8C(arg0) = arg0->y_pos.i.hi - player->y_pos.i.hi;
            break;
        }
    }
    if (arg0->unk6 != 0) {
        arg0->y_pos.i.hi = g_Player.y_pos.i.hi + F_8C(arg0);
    } else {
        func_801EE34C(arg0, player, arg0->id);
    }
    arg0->x_pos.val = x;
    mask = 2;
    if (arg0->unk15 != 0) {
        mask = 1;
    }
    func_8002F06C(arg0);
    t = arg0->unk70 & mask;
    if (t) {
        if (func_8003D480(arg0->active, arg0->id, 1, arg0) != 0) {
            arg0->unk7++;
        }
        arg0->unk70 = 0;
        arg0->unk50 = D_801F3AB0;
        arg0->unk68 = (struct X4_Unk_unk68*)D_801F3AB8;
        set_animation(arg0, 1);
        if (g_Player.input.buttons.held & 8) {
            arg0->y_vel.val = -0x6C000;
        } else {
            arg0->y_vel.val = 0x6C000;
        }
        arg0->x_vel.val = 0;
        arg0->unk5++;
    } else {
        func_8002CCB0(arg0, 0x20, 0x20);
        if (arg0->on_screen == 0) {
            arg0->state = 3;
            arg0->unk50 = 0;
            arg0->unk68 = 0;
        }
    }
}
#undef g_Player
#undef set_animation
#undef func_8002CCB0
#undef F_8C
