#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void animate_object(struct X4_AnimatedObj*);
extern void (*D_801F36F8[])(void*);

void update_hover(s8* arg0) {
    if (arg0[0xD3] != 0) {
        ((void (*)())func_8003AFF4)();
        return;
    }
    if (try_shoot_in_air(arg0) == 0) {
        animate_object((struct X4_AnimatedObj*)arg0);
        D_801F36F8[arg0[6]](arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void animate_object(struct X4_AnimatedObj*);
M2C_UNK end_dash(s32);
M2C_UNK player_load_weapon_palette();
extern void (*D_801F3724[])(void*);

void func_801EB844(s8* arg0) {
    if (arg0[0xD3] != 0) {
        arg0[0xE0] = 0;
        ((void (*)())player_load_weapon_palette)();
        end_dash((s32)arg0);
        return;
    }
    animate_object((struct X4_AnimatedObj*)arg0);
    D_801F3724[arg0[6]](arg0);
}
