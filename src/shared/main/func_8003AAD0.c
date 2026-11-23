#include "common.h"

#define F8(o) (*(s8*)(p + (o)))
#define U8(o) (*(u8*)(p + (o)))
#define S32(o) (*(s32*)(p + (o)))

void func_8003A678(void* arg0);
void func_8003CDF0();
void func_8003F000(void* arg0);
s32 play_sound_unless_low_health(void*, s32);
s32 random_byte();
void set_pose_size();
s32 set_stand_animation_by_hp(void*);
extern u8 D_80073CE4[];
s32 player_set_animation(void*, s32);
#define player_set_animation(a, b)                                             \
    ((void (*)(void*, s32))player_set_animation)(a, b)

void func_8003AAD0(u8* p) {
    p[6] = 0;
    p[5] = p[0xD1];
    func_8003CDF0(p);
    switch (F8(5)) {
    case 20:
        if ((u8)(p[0x17] - 5) >= 2) {
            set_stand_animation_by_hp(p);
        }
        F8(0xD0) = -1;
        p[0x15] = p[0xD2];
        break;
    case 73:
        if (p[0x17] != 6) {
            player_set_animation(p, 6);
        }
        F8(0xD0) = -1;
        p[0x15] = p[0xD2];
        break;
    case 21:
        player_set_animation(p, 0x26);
        S32(0x24) = 0;
        S32(0x28) = 0;
        S32(0x2C) = 0;
        if (p[0xD2] == 0) {
            func_8003A678(p);
            return;
        }
        p[0x15] = 0x40;
        break;
    case 29:
        player_set_animation(p, 0x26);
        F8(0xD0) = -1;
        S32(0x20) = 0x10000;
        S32(0x24) = 0;
        S32(0x28) = 0;
        S32(0x2C) = 0;
        p[0x15] = p[0xD2];
        if (p[0xD2] == 0) {
            S32(0x20) = -S32(0x20);
        }
        break;
    case 30:
        player_set_animation(p, 0x26);
        p[0x67] = 1;
        S32(0x20) = 0x20000;
        S32(0x28) = 0;
        S32(0x24) = 0x2E800;
        S32(0x2C) = 0x840;
        p[6] = 0;
        play_sound_unless_low_health(
            p, D_80073CE4[(random_byte() & 3) + F8(2) * 4]);
        player_set_animation(p, 0xA);
        p[0x15] = p[0xD2];
        break;
    case 22:
        player_set_animation(p, 3);
        F8(0xD0) = -1;
        p[0x15] = p[0xD2];
        break;
    case 23:
        player_set_animation(p, 0xA);
        set_pose_size(p);
        S32(0x20) = 0;
        S32(0x28) = 0;
        p[0x67] = 1;
        S32(0x24) = S32(0xF8);
        S32(0x2C) = S32(0x100);
        p[0x15] = p[0xD2];
        break;
    case 24:
        if (F8(2) != 0) {
            player_set_animation(p, 5);
        } else {
            player_set_animation(p, 0x6B);
        }
        func_8003F000(p);
        p[0x15] = p[0xD2];
        break;
    }
}
#undef player_set_animation
