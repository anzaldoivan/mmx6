// rolefeed (3.1 T4): func_800F2AD4 of src/rock_04/E9860.c
#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 func_80030ECC();
s32 check_enemy_hits(void*);
void func_800F4FD8(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F7518[])(void*);

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
#include "mmx6/state.h"
#include "mmx6/globals.h"
extern s32 D_800F7694;
extern s32 D_800F7698;

void func_800F2AD4(struct X4_MainObj* self) {
    s32 a;
    s32 b;
    s32 c;
    s32 q;

    set_animation(self,
                  ((u32)(D_80097420.frame_counter + self->unk2) % 3) + 0x1C);
    if (D_800CCF38 >= 2) {
        self->hurt_box = &D_800F7694;
        self->attack_box = &D_800F7698;
    }
    self->terrain_box = 0;
    a = ((u32)random_byte() % 40 & 0xFF) + 10;
    b = ((u32)random_byte() % 30 & 0xFF) + 30;
    c = ((u32)random_byte() % 10 & 0xFF) + 15;
    q = (b << 16) / ((c * c) >> 1);
    self->y_speed = q * c;
    self->gravity = q;
    self->x_accel = 0;
    switch (self->unk2) {
    case 16:
        self->x_speed = (-a << 16) / c;
        break;
    case 18:
        if (random_byte() & 1) {
            self->x_speed = (-a << 16) / c;
            break;
        }
    case 17:
        self->x_speed = (a << 16) / c;
        break;
    }
    self->action_phase++;
}
