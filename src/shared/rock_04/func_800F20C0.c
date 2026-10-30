#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F52AC(void* arg0, u8 arg1);
extern s8 D_800970A2;
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
