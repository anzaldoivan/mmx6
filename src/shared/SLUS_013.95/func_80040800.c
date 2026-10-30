#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80017A04();
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
s32 func_8002DCF4(void*, void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
s32 func_80042CE8(void*);
void register_orb(void*);
void func_80049E50(struct X4_MainObj* self);
extern s32 D_80075EE0;
extern void (*D_80076018[])(void*);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_RideArmorObj D_800CD340;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_80040800(struct X4_MainObj* self) {
    void* tgt;
    u16* cnt;
    s8 st;

    self->unk18 = self->x_pos;
    self->unk1C = self->y_pos;
    ((void (*)())func_80017A04)();
    if (self->unk5 != 7) {
        func_8002CCB0(self, 0x30, 0x30);
    }
    D_80076018[self->unk5](self);
    if (self->unk5 != 5) {
        if (self->unk5 != 7) {
            if (self->hurt_box != 0 && check_enemy_hits(self) < 0) {
                if (func_80042CE8(self) == 0) {
                    func_80049E50(self);
                    st = 2;
                    goto set;
                }
                func_80049E50(self);
                register_orb(self);
                self->contact_damage = 0;
                F8(self, 0x8E) = 1;
                self->attack_box = 0;
                self->hurt_box = 0;
                self->unk5 = 5;
                self->unk6 = 0;
                self->unk42 &= 0x7FFF;
                return;
            }
            func_80030ECC(self);
        }
    } else {
        tgt = &g_Player;
        if (S8(&g_Player, 0xD5) != 0) {
            tgt = &D_800CD340;
            if (D_800CD340.unk5 == 0) {
                tgt = (u8*)&D_800CD340 + 0xB0;
            }
        }
        if (F8(self, 0x8E) != 0) {
            PTR(self, 0x68) = &D_80075EE0;
        } else {
            PTR(self, 0x68) = 0;
        }
        if (func_8002DCF4(self, tgt) != 0) {
            {
                u8* e = (u8*)&g_playthrough_state;
                s32 i = g_Player.unk2 << 1;
                u16* b = (u16*)(e + 0xD2);
                cnt = (u16*)((u8*)b + i);
            }
            *cnt += U16(self, 0x8A);
            play_sound(0, 0x29, self);
            st = 2;
            PTR(self, 0x68) = 0;
            goto set;
        }
        PTR(self, 0x68) = 0;
    }
    if (func_8002CBFC(self, 0x40, 0x40) == 1) {
        if (F8(self, 0x8D) == 0) {
            st = 3;
        set:
            self->state = st;
        }
    }
}
