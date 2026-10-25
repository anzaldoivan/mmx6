#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
s8 func_80032BE8(struct X4_PlayerObj* arg0);
void func_80051158(struct X4_MainObj* self);
M2C_UNK func_80051890();
extern s32 D_80075B9C;
extern s32 D_80078DFC;
extern s32 D_80078E04;
extern u8 D_80097185;

void func_80031DA8(struct X4_MainObj*);
void func_800515B4(struct X4_MainObj* self) {
    s8* link;
    u8 st;

    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    if (self->unk2 != 0x10) {
        if (self->state == 0) {
            func_80051158(self);
            return;
        }
        func_80051890(self);
        return;
    }
    link = M2C_FIELD(self, s8**, 0x7C);
    if (link[0] == 0) {
        ((M2C_UNK(*)())func_8002C9B0)(self);
        return;
    }
    st = M2C_FIELD(self, u8*, 4);
    if (self->state == 0) {
        self->terrain_box = (struct X4_Unk_unk68*)&D_80078DFC;
        self->hurt_box = &D_80078E04;
        M2C_FIELD(self, u8*, 0xA2) = 1;
        self->collision_data = &D_80075B9C;
        self->unk75 = 1;
        M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(link, u16*, 0xA);
        {
            s32 e = M2C_FIELD(link, u16*, 0xE);
            self->state = st + 1;
            M2C_FIELD(self, u16*, 0xE) = e - 0x4E;
        }
    }
    func_80032B34((struct X4_PlayerObj*)self);
    func_80032BE8((struct X4_PlayerObj*)self);
    {
        s32 f = D_80097185;
        if (f == 0) {
            ((M2C_UNK(*)())func_80031DA8)(self);
        }
    }
    func_8003208C(self);
    func_80031F4C((struct X4_PlayerObj*)self);
}
