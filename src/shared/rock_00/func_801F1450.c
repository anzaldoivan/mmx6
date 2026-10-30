#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void move_object(struct X4_MovingObj*);
void func_8002E974(void*);
extern struct X4_BackgroundObj background_objects[3];

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_801F1450(struct X4_WeaponObj* arg0) {
    s32 flag;
    u8 bits;

    if (F_S8(arg0->owner, 0x45) & 0x80) {
        F_S8(arg0, 0x8D) = 1;
    }
    if (F_S8(arg0, 0x8D) != 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        move_object((struct X4_MovingObj*)arg0);
    }
    flag = 0;
    if (arg0->unk70 == 0) {
        func_8002E974(arg0);
    }
    bits = arg0->unk70;
    if ((bits & 0xC) == 0xC) {
        arg0->y_pos.i.hi += 9;
        set_animation(arg0, 4);
        arg0->unk50 = 0;
        arg0->unk68 = 0;
        arg0->unk5 = 4;
        return;
    }
    if (bits & 4) {
        flag = 1;
    }
    if (arg0->y_pos.i.hi - background_objects[arg0->bg_offset].y_pos.i.hi <
        0x10) {
        flag = 1;
    }
    if (flag != 0) {
        set_animation(arg0, 2);
        arg0->unk5++;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    if (arg0->on_screen == 0 && F_S8(arg0, 0x8C) == 0) {
        arg0->state = 2;
    }
}
#undef set_animation
#undef func_8002CCB0
