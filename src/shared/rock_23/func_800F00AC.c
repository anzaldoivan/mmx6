#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))

s32 set_animation(void*, s32);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230();
extern struct X4_PlayerObj g_Player;

void func_800F00AC(struct X4_MainObj* self) {
    s32 a;

    func_80017A04();
    {
        // !FAKE: inherited from src/shared/rock_08/func_800ECBC4.c
        register s32 t asm("$2") = OH(self, 0x80);
        if (t == 0) {
            // !FAKE: inherited from src/shared/rock_08/func_800ECBC4.c
            goto ready;
        }
    }
    {
        OH(self, 0x80)--;
        func_8002D230((s32)self);
        return;
    }
ready:
    OH(self, 0x82) = g_Player.x_pos.i.hi;
    OH(self, 0x84) = g_Player.y_pos.i.hi;
    set_animation(self, 0x11);
    {
        u16 x = g_Player.x_pos.i.hi;
        u16 y;
        OH(self, 0x82) = x;
        y = g_Player.y_pos.i.hi;
        OH(self, 0x84) = y;
        a = ratan2((s16)y - self->y_pos.i.hi, (s16)x - self->x_pos.i.hi);
    }
    OW(self, 0x20) = rcos(a) << 5;
    OW(self, 0x24) = -rsin(a) << 5;
    self->unk7++;
}
