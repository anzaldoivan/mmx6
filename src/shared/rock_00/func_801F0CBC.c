#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
void func_80017A04(struct X4_AnimatedObj*);

void func_801F0CBC(struct X4_WeaponObj* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    if (p->unk5 != 0x2C) {
        arg0->state = 2;
        return;
    }
    func_80017A04(ANIMATED_OBJECT(arg0));
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        p->unk7 = 1;
        arg0->unk5++;
    }
    arg0->x_pos.u.hi = M2C_FIELD(arg0, u16*, 0x8C) + p->x_pos.u.hi;
    arg0->y_pos.u.hi = M2C_FIELD(arg0, u16*, 0x8E) + p->y_pos.u.hi;
}
#undef g_Player
