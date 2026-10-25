#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj D_800CCED0;
M2C_UNK func_8002D230();
s32 func_80016C48(s32, s32, void*);

void func_8004292C(struct X4_BaseObj* self) {
    struct X4_EngineObj* e;
    u16* p;

    ((void (*)(void*))func_8002D230)(self);
    if (self->y_pos.i.hi >= g_Player.y_pos.i.hi) {
        u8* b;
        s32 i;
        e = &D_800CCED0;
        i = g_Player.unk2 * 2;
        b = (u8*)e + 0xD2;
        p = (u16*)(i + b);
        *p += *(u16*)((u8*)self + 0x8A);
        func_80016C48(0, 0x29, self);
        e->unkF = 0x10;
        self->on_screen = 0;
        self->unk6++;
    }
}
