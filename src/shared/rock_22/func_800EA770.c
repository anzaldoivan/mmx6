#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002BBF4();
M2C_UNK func_8003D308(M2C_UNK, u8);

extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern u16 D_8009728E;
extern u8 D_800FB6F8[];

void func_800EA770(struct X4_PlayerObj* self) {
    struct X4_AnimatedObj* obj;
    s32 i;
    s32 n;
    u8 b;
    struct X4_PlayerObj* pl;

    if (self->unk2 == 0) {
        struct X4_BackgroundObj* bg = D_800971F8;

        *(s16*)&bg[1].unk40 = -0x1540;
        *(s16*)&bg[1].unk42 = -0x50;
        bg[1].unk4 = 2;
        bg[1].unk3 = 0;
        bg[1].unk4C = 1;
        i = 0;
        do {
            obj = func_8002BBF4();
            n = i + 1;
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 0x1D;
                obj->unk2 = 0xA;
                obj->x_pos.i.hi = n * 0xA0 + 0x1520;
                obj->y_pos.u.hi = self->y_pos.u.hi;
            }
            i = n;
        } while (i < 5);
        self->unk5 = 2;
        func_8003D308(0x14, D_800970A0.unk15);
    } else if (self->unk2 == 1) {
        struct X4_BackgroundObj* bg = D_800971F8;

        *(s16*)&bg[1].unk40 = -0x17C0;
        *(s16*)&bg[1].unk42 = -0x50;
        bg[1].unk4 = 2;
        bg[1].unk3 = 0;
        bg[1].unk4C = 1;
        i = 0;
        do {
            obj = func_8002BBF4();
            n = i + 1;
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 0x1D;
                obj->unk2 = 0xA;
                obj->x_pos.i.hi = n * 0xB0 + 0x1790;
                obj->y_pos.u.hi = self->y_pos.u.hi;
            }
            i = n;
        } while (i < 5);
        self->unk5 = 3;
    } else if (self->unk2 == 2) {
        struct X4_BackgroundObj* bg = D_800971F8;

        *(s16*)&bg[1].unk40 = -0x1B70;
        *(s16*)&bg[1].unk42 = -0x50;
        bg[1].unk4 = 2;
        bg[1].unk3 = 0;
        bg[1].unk4C = 1;
        i = 0;
        do {
            obj = func_8002BBF4();
            n = i + 1;
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 0x1D;
                obj->unk2 = 0xA;
                obj->x_pos.i.hi = n * 0xA0 + 0x1B50;
                obj->y_pos.u.hi = self->y_pos.u.hi;
            }
            i = n;
        } while (i < 5);
        self->unk5 = 4;
    } else if (self->unk2 == 10) {
        self->unk60 = 0x7F;
        self->y_pos.u.hi = 0x2F8 - D_8009728E;
        self->unk50 = D_800FB6F8;
        self->unk5 = 5;
    }
    pl = &D_800970A0;
    self->invincibility_timer = 0;
    b = M2C_FIELD(pl, u8*, 0x14);
    {
        register s32 c asm("$2") = 5;
        self->unk16 = c;
    }
    self->x_vel.val = 0;
    self->y_vel.val = 0;
    self->unk15 = 0;
    self->unk70 = 0;
    self->input.buttons.held = 0;
    self->input.buttons.previous = 0;
    self->state = 1;
    self->unk6 = 0;
    self->unk7 = 0;
    M2C_FIELD(self, u8*, 0x80) = 0;
    M2C_FIELD(self, u8*, 0x14) = b;
}
