#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void move_object(struct X4_MovingObj*);
extern struct X4_BackgroundObj background_objects[3];

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_801F1F4C(struct X4_WeaponObj* arg0) {
    if (F_S8(arg0->owner, 0x45) & 0x80) {
        F_S8(arg0, 0x8D) = 1;
    }
    if (F_S8(arg0, 0x8D) != 0) {
        func_80017A04((struct X4_AnimatedObj*)arg0);
        move_object((struct X4_MovingObj*)arg0);
    }
    if (arg0->y_pos.i.hi - background_objects[arg0->bg_offset].y_pos.i.hi <
        -0x10) {
        arg0->on_screen = 0;
        F_S16(arg0, 0x8E) = 0x1E;
        arg0->unk5++;
    }
}
