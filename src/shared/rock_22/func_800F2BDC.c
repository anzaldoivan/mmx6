#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
M2C_UNK func_8002F288(M2C_UNK*);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
extern s16 D_800970AA;
extern s16 D_800970AE;

void func_800F2BDC(struct X4_MainObj* self) {
    s32 ref;
    // !FAKE: depin: dropping it breaks the match (41/165)
    register s32 p asm("$3");
    s16 x;
    s16 y;
    s32 near;
    s32 d;
    u8 r;

    move_object((s32)self);
    func_8002F288((M2C_UNK*)self);
    near = 0;
    if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index < 2) {
        if (SP_CUR_MAIN_OBJ->ext.main_19.unk80 == 0) {
            p = (u16)self->y_pos.i.hi;
            y = p - self->terrain_box->unk3;
            ref = p;
        } else {
            p = (u16)self->y_pos.i.hi;
            y = p + self->terrain_box->unk3;
            ref = p;
        }
        if (self->unk15 == 0) {
            x = self->x_pos.i.hi - 4;
        } else {
            x = self->x_pos.i.hi + 4;
        }
        d = D_800970AE - (s16)ref;
        if (d >= 0 ? d < 0x18 : (s16)ref - D_800970AE < 0x18) {
            near = 1;
        }
    } else {
        if (self->unk15 == 0) {
            p = (u16)self->x_pos.i.hi;
            x = p - self->terrain_box->unk2;
            ref = p;
        } else {
            p = (u16)self->x_pos.i.hi;
            x = p + self->terrain_box->unk2;
            ref = p;
        }
        y = self->y_pos.i.hi - 4;
        d = D_800970AA - (s16)ref;
        if (d >= 0 ? d < 0x18 : (s16)ref - D_800970AA < 0x18) {
            near = 1;
        }
    }
    r = ((u8(*)(void*, s16, s16, s32))func_80030234)(self, x, y, ref);
    if ((self->collision_flags & ~SP_CUR_MAIN_OBJ->ext.main_19.unk82) ||
        r < 0x38 || near) {
        if (SP_CUR_MAIN_OBJ->ext.main_19.animation_index < 2) {
            set_animation(self, 0xB);
            {
                // !FAKE: depin: dropping it breaks the match (159/165)
                register s32 six asm("$2") = 6;
                self->unk6 = six;
            }
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
            if ((self->collision_flags >>
                 (SP_CUR_MAIN_OBJ->ext.main_19.unk80 + 2)) &
                1) {
                SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
            }
        } else {
            set_animation(self, 0xA);
            {
                s32 six = 6;
                // !FAKE: depin: dropping it breaks the match (156/165)
                register s32 f asm("$2") = self->unk15;
                self->unk6 = six;
                self->unk15 = f ^ 0x40;
            }
            SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
            if ((self->collision_flags >> SP_CUR_MAIN_OBJ->ext.main_19.unk80) &
                1) {
                SP_CUR_MAIN_OBJ->ext.main_19.unk80 ^= 1;
            }
        }
    } else {
        func_80017A04(self);
    }
}
