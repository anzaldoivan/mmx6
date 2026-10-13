#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
void* func_8003D480(M2C_UNK, s8, s8, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)

#define F_45(p) (*(u8*)((u8*)(p) + 0x45))
#define F_46(p) (*(s8*)((u8*)(p) + 0x46))
#define F_8C(p) (*(s8*)((u8*)(p) + 0x8C))

void func_801F1B64(struct X4_WeaponObj* arg0) {
    func_80017A04(ANIMATED_OBJECT(arg0));
    if (F_45(arg0) & 0x40) {
        F_45(arg0) = 0;
        if (func_8003D480(arg0->active, arg0->id, arg0->unk2 + 1, arg0) != 0) {
            F_8C(arg0)++;
        }
    }
    if (F_46(arg0) == 0) {
        arg0->state = 2;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    if (arg0->on_screen == 0 && F_8C(arg0) == 0) {
        arg0->state = 2;
    }
}
#undef func_8002CCB0
#undef F_45
#undef F_46
#undef F_8C
