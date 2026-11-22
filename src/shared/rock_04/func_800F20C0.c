// rolefeed (3.1 T4): func_800F20C0 of src/rock_04/E9860.c
#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_04.h"
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
#include "mmx6/globals.h"

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F52AC(void* arg0, u8 arg1);
extern u8 D_800F75F8[][2];

void func_800F20C0(void* arg0) {
    switch (F(arg0, s8*, 0x45)) {
    case 1:
        play_sound(2, 0x15, arg0);
        func_800F52AC(arg0, D_800970A2);
        break;
    case 2:
        play_sound(2, 0x18, arg0);
        func_800F5088(arg0, D_800970A2);
        break;
    case 3: {
        if (--F(arg0, s16*, 0x7E) != 0) {
            u8 v = D_800F75F8[D_800970A2][0];
            F(arg0, u8*, 6) += 1;
            F(arg0, s16*, 0x7C) = v;
        } else {
            u8 v;
            set_animation(arg0, 0);
            v = D_800F75F8[D_800970A2][1];
            F(arg0, u8*, 6) += 2;
            F(arg0, s16*, 0x7C) = v;
        }
    } break;
    }
}
