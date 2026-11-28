#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_04.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 func_80030ECC();
s32 check_enemy_hits(void*);
void func_800F4FD8(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F7518[])(void*);

#include "../shared/rock_04/func_800F1738.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_04.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F54B8(s32, void*);
extern struct X4_EngineObj g_playthrough_state;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

#include "../shared/rock_04/func_800F18C4.c"

#include "../shared/rock_04/func_800F19EC.c"

#include "../shared/rock_04/func_800F1B50.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void move_object();
s32 random_byte();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F5360(void*, s32);
extern struct X4_PlayerObj g_Player;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

#include "../shared/rock_04/func_800F1CF0.c"

#include "../shared/rock_04/func_800F1EB0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void move_object();
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);

void func_800F1FE0(void* arg0) {
    s32 var_v0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
    if (temp_v1 & 8) {
        play_sound(2, 0x12, arg0);
        start_pad_vibration(8);
        set_animation(arg0, 9);
        {
            // !FAKE: depin: dropping it breaks the match (51/56)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        var_v0 = temp_v1 & 1;
    } else {
        var_v0 = temp_v1 & 2;
    }
    if (var_v0 != 0) {
        play_sound(2, 0x12, arg0);
        start_pad_vibration(8);
        set_animation(arg0, 0xB);
        func_800F5088(arg0, 0x20);
        func_800F5088(arg0, 0x21);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
        return;
    }
    move_object(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F52AC(void* arg0, u8 arg1);
extern u8 D_800F75F8[][2];

#include "../shared/rock_04/func_800F20C0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void move_object();
s32 random_byte();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F5360(void*, s32);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800F21E8(void* arg0) {
    move_object(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (79/81)
        register s32 f asm("$2") = UB(arg0, 0x15);
        if (f == 0) {
            if (UB(arg0, 0x70) & 2) {
                // !FAKE: goto shares the hit block holding the pinned increment; duplicating it needs a second pin
                goto hit;
            }
            if (SH(arg0, 0xA) <= SH(arg0, 0x84)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) - ((random_byte() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x12);
            }
        } else {
            if (UB(arg0, 0x70) & 1) {
            hit:
                play_sound(2, 0x12, arg0);
                start_pad_vibration(8);
                set_animation(arg0, 0xB);
                {
                    // !FAKE: depin: dropping it breaks the match (78/81)
                    register s32 c asm("$2") = UB(arg0, 6);
                    UB(arg0, 6) = c + 1;
                }
                return;
            }
            if (SH(arg0, 0xA) >= SH(arg0, 0x84)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) + ((random_byte() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x12);
            }
        }
    }
    if (--SH(arg0, 0x7C) == 0) {
        UH(arg0, 0x7C) = 8;
        func_800F5360(arg0, 1);
    }
}

#include "../shared/rock_04/func_800F232C.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
M2C_UNK func_80049D90(void*);
void func_800F51F0(struct X4_AnimatedObj* arg0, u8 arg1);
extern s16 D_800970AA;
extern u16 D_800F70DC;

#include "../shared/rock_04/func_800F2464.c"

// clang-format off
INCLUDE_ASM("rock_04/nonmatchings/E9860", func_800F25A0);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern s32 D_800F769C;

#include "../shared/rock_04/func_800F2750.c"

#include "../shared/rock_04/func_800F2954.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
#include "mmx6/state.h"
#include "mmx6/globals.h"
extern s32 D_800F7694;
extern s32 D_800F7698;

#include "../shared/rock_04/func_800F2AD4.c"

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_PlayerObj g_Player;
extern s16 D_800970AA;
extern s32 D_800F76A0;
extern s32 D_800F76A4[];
extern s32 D_800F76A8[];

void func_800F2CC4(void* arg0) {
    struct X4_PlayerObj* p;
    s32 ang;
    s32 num;
    s32 den;
    s32 dx;
    s32 v;
    s32 t;
    // !FAKE: depin: dropping it breaks the match (110/114)
    register s32 py asm("$3");
    s32 px;
    s32 den2;
    s8 type;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x5) == 3) {
        M2C_FIELD(arg0, s8*, 0x4) = 2;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        M2C_FIELD(arg0, s8*, 0x3) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        play_sound(2, 0x16, arg0);
        M2C_FIELD(arg0, void**, 0x54) = &D_800F76A0;
        M2C_FIELD(arg0, void**, 0x50) = D_800F76A4;
        M2C_FIELD(arg0, void**, 0x68) = D_800F76A8;
        type = M2C_FIELD(arg0, s8*, 0x2);
        if (type == 0) {
            dx = D_800970AA - M2C_FIELD(arg0, s16*, 0xA);
            num = 0x600000;
            den = 264;
            M2C_FIELD(arg0, s32*, 0x2C) = num / den;
            M2C_FIELD(arg0, s32*, 0x24) = 0x85D11;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            dx <<= 16;
            den2 = 46;
            M2C_FIELD(arg0, s32*, 0x20) = dx / den2;
        } else if (type == 1) {
            p = &g_Player;
            px = p->x_pos.i.hi;
            py = p->y_pos.i.hi;
            ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                         px - M2C_FIELD(arg0, s16*, 0xA));
            M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 6;
            M2C_FIELD(arg0, s32*, 0x24) = rsin(ang) << 6;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
        } else if (type == 2) {
            p = &g_Player;
            px = p->x_pos.i.hi;
            py = p->y_pos.i.hi;
            ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                         px - M2C_FIELD(arg0, s16*, 0xA));
            v = rcos(ang);
            M2C_FIELD(arg0, s32*, 0x20) = -(v << 4) + (v << 7);
            v = rsin(ang);
            t = v << 4;
            M2C_FIELD(arg0, s32*, 0x24) = (v << 7) - t;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
