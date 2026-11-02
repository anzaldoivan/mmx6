#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80051FE8(void* arg0, void* arg1);
extern s8 D_80097182;
#define D_80097182 (*(u8*)&D_80097182)

void func_800516E0(s8* arg0) {
    s8* temp_a1;

    temp_a1 = *(s8**)(arg0 + 0x50);
    if (*temp_a1 == 0) {
        clear_object_slot(arg0, temp_a1);
        return;
    }
    if (arg0[4] == 0) {
        func_80051FE8(arg0, temp_a1);
    } else if (D_80097182 == 1) {
        clear_object_slot(arg0, temp_a1);
        return;
    } else {
        ((M2C_UNK(*)())func_80017A04)(arg0, temp_a1);
    }
    func_8002CCB0((struct X4_BaseObj*)arg0, 0x88, 0x88);
}
#undef D_80097182

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80017A04();
M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_80051FE8(void* arg0, void* arg1);
extern s8 D_80097182;

void func_80051780(s8* arg0) {
    s32 temp_a1;

    temp_a1 = *(s32*)(arg0 + 0x50);
    if (arg0[4] == 0) {
        ((void (*)())func_80051FE8)(arg0, temp_a1);
        *(s16*)(arg0 + 0x54) = 0x78;
        play_sound(0, 0x24, 0);
    } else if (*(s16*)(arg0 + 0x54) == 0) {
        D_80097182 = 2;
        clear_object_slot(arg0, temp_a1);
        return;
    } else {
        ((void (*)())func_80017A04)(arg0, temp_a1);
        (*(s16*)(arg0 + 0x54))--;
    }
    func_8002CCB0((struct X4_BaseObj*)arg0, 0x88, 0x88);
}

#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);

void func_80051828(struct X4_PlayerObj* arg0, s8 arg1, s8 arg2) {
    struct X4_VisualObj* obj;

    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x49;
        obj->id = arg1;
        obj->unk2 = arg2;
        obj->bg_offset = arg0->bg_offset;
        obj->unk50 = arg0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
extern void (*D_80078E18[])(struct X4_PlayerObj*);
extern u8 D_80097185;

void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void collide_solid_object(struct X4_MainObj*);
s8 func_80032BE8(struct X4_PlayerObj* arg0);
M2C_UNK func_80051890(struct X4_PlayerObj* self) {
    ((M2C_UNK(*)())func_80017A04)();
    D_80078E18[self->unk5](self);
    func_80032B34(self);
    if (D_80097185 == 0) {
        ((M2C_UNK(*)())collide_solid_object)(self);
    }
    func_8003208C(self);
    func_80031F4C(self);
    ((void (*)())func_80032BE8)(self);
    return ((M2C_UNK(*)())func_8002CCB0)(self, 0x88, 0x88);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);

void func_80051924(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    s16 d;
    // !FAKE: depin: dropping it breaks the match (66/72)
    register s32 dx asm("$2");

    d = p->x_pos.i.hi - arg0->x_pos.i.hi;
    if (d < 0) {
        d = -d;
    }
    if (d < 0x41) {
        d = p->y_pos.i.hi - arg0->y_pos.i.hi;
        if (d > 0) {
            if (d >= 0x11) {
                return;
            }
        } else {
            d = -d;
            if (d >= 0x69) {
                return;
            }
        }
        set_animation(arg0, 0xA);
        dx = p->x_pos.val;
        dx -= arg0->x_pos.val;
        if (dx > 0) {
            func_8003D308(0x14, 0);
            dx = 0x40;
            arg0->unk15 = dx;
        } else {
            func_8003D308(0x14, 0x40);
            arg0->unk15 = 0;
        }
        g_playthrough_state.unk16 = 1;
        g_playthrough_state.unk12 = 1;
        g_playthrough_state.unk13 = 1;
        g_playthrough_state.unk17 = 1;
        arg0->unk6 = 0;
        arg0->unk5++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);
M2C_UNK func_80018774(M2C_UNK);
extern u8 D_800CD40C;

void func_80051A44(s8* arg0) {
    if (arg0[6] == 0) {
        if (arg0[0x45] != 0) {
            ((void (*)(M2C_UNK))func_80018774)(3);
            {
                // !FAKE: pin the increment temp to the second return register
                register s32 u asm("$3") = (u8)arg0[6] + 1;
                arg0[0x45] = 0;
                arg0[6] = u;
            }
        }
    } else if (D_800CD40C == 0) {
        ((void (*)(M2C_UNK, M2C_UNK))play_bgm_xa_track)(0x1C, 0x7F);
        {
            s32 t = (u8)arg0[5] + 1;
            arg0[6] = 0;
            arg0[5] = t;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_80078E48[];
extern u8 D_800CD40C;

void func_80051AC8(s8* arg0) {
    if (D_800CD40C == 2) {
        ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))open_text_box)(
            D_80078E48[arg0[2]], 0xFF, 0);
        arg0[5]++;
    }
}

#include "common.h"
#define M2C_UNK s32

extern u8 D_8008EAFC;
M2C_UNK set_animation(void*, M2C_UNK);

void func_80051B28(u8* arg0) {
    if (D_8008EAFC == 1) {
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xB);
        arg0[6] = 0;
        arg0[5]++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void play_stage_bgm(void);
M2C_UNK func_80018774(M2C_UNK);
extern u8 D_8008EAFC;
extern u8 D_800CD40C;

void func_80051B74(s8* arg0) {
    if (arg0[6] == 0) {
        if (D_8008EAFC == 0) {
            func_80018774(3);
            arg0[6]++;
        }
    } else if (D_800CD40C == 0) {
        play_stage_bgm();
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0xC);
        arg0[6] = 0;
        arg0[5]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D330();
extern struct X4_EngineObj g_playthrough_state;

void func_80051C08(s8* arg0) {
    if (arg0[0x45] != 0) {
        func_8003D330();
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk17 = 0;
        arg0[5]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_80051C68(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player;
    struct X4_VisualObj* obj;

    if (arg0->unk72 & 8) {
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        player = &g_Player;
        func_8003D308(0x18, player->unk15);
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0x24;
            obj->unk2 = 0;
            obj->bg_offset = arg0->bg_offset;
            obj->unk50 = arg0;
        }
        {
            s32 x = arg0->x_pos.val;
            player->item_step = 1;
            g_playthrough_state.unk16 = 1;
            g_playthrough_state.unk12 = 1;
            g_playthrough_state.unk13 = 1;
            g_playthrough_state.unk17 = 1;
            player->x_pos.val = x;
        }
        arg0->unk5++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);
extern struct X4_PlayerObj g_Player;

void func_80051D28(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    struct X4_VisualObj* obj1;
    struct X4_VisualObj* obj2;
    struct X4_VisualObj* obj3;
    struct X4_VisualObj* obj4;
    u8 step;
    s32 id;

    step = player->item_step;
    player->x_pos.val = arg0->x_pos.val;
    if (step == 2) {
        id = 0x25;
        obj1 = func_8002C398();
        if (obj1 != 0) {
            obj1->active = 0x49;
            obj1->id = id;
            obj1->unk2 = 0;
            obj1->bg_offset = arg0->bg_offset;
            obj1->unk50 = arg0;
        }
        obj2 = func_8002C398();
        if (obj2 != 0) {
            obj2->active = 0x49;
            obj2->id = id;
            obj2->unk2 = 1;
            obj2->bg_offset = arg0->bg_offset;
            obj2->unk50 = arg0;
        }
        obj3 = func_8002C398();
        if (obj3 != 0) {
            obj3->active = 0x49;
            obj3->id = id;
            obj3->unk2 = step;
            obj3->bg_offset = arg0->bg_offset;
            obj3->unk50 = arg0;
        }
        obj4 = func_8002C398();
        if (obj4 != 0) {
            obj4->active = 0x49;
            obj4->id = id;
            obj4->unk2 = 3;
            obj4->bg_offset = arg0->bg_offset;
            obj4->unk50 = arg0;
        }
        arg0->unk5++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
M2C_UNK set_animation(void*, M2C_UNK);

void func_80051E40(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    p->x_pos.val = arg0->x_pos.val;
    if (p->item_step == 3) {
        ((void (*)(void*, s32))set_animation)(arg0, 2);
        *(s32*)((u8*)arg0 + 0x7C) = 0x28;
        arg0->unk5++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800970A8;

void func_80051E9C(void* arg0) {
    s32 temp_v0;

    D_800970A8 = M2C_FIELD(arg0, s32*, 8);
    temp_v0 = M2C_FIELD(arg0, s32*, 0x7C);
    if (temp_v0 == 0) {
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
        return;
    }
    M2C_FIELD(arg0, s32*, 0x7C) = (s32)(temp_v0 - 1);
}
