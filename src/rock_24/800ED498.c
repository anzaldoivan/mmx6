#define func_800484D8 func_800ED498
#define D_80077BA4 D_800F6B84
#include "../shared/SLUS_013.95/func_800484D8.c"
#undef func_800484D8
#undef D_80077BA4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ED4E4(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK animate_object(void*);
void func_80027BA0(s32, s32, s32, void*);
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */
M2C_UNK func_80030ECC(void*, s16);              /* extern */
#define func_80030ECC (*(M2C_UNK(*)(void*)) & func_80030ECC)
s32 check_enemy_hits(void*);                     /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*); /* extern */
M2C_UNK func_80049E50(void*);                    /* extern */
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_80097222;
extern struct X4_EngineObj g_playthrough_state;
extern M2C_UNK D_800F6C84;
extern s16 D_800F6D6C[];
extern s16 D_800F6D7C[][2];
extern u8 D_800F6D98[];
extern void (*D_800F6DA8[])(struct X4_MainObj*);
extern u8 D_800F7794;

void func_800ED504(struct X4_MainObj* arg0) {
    s32 r;

    r = check_enemy_hits(arg0);
    if (D_800970AA >= D_800F6D7C[D_800F7794][0] &&
        D_800970AA <= D_800F6D7C[D_800F7794][1]) {
        g_playthrough_state.character_state.bytes[0] = 1;
    } else {
        g_playthrough_state.character_state.bytes[0] = 0;
    }
    if (r < 0) {
        if (D_800F7794 == 5) {
            background_objects[0].unk26 = background_objects[0].unk24;
        }
        if (D_800F6D6C[D_800F7794] != 0) {
            D_8009721C = D_800F6D6C[D_800F7794];
        }
        if (D_800F7794 == 1) {
            D_80097222 = 0xE0;
            func_80027BA0(0, 0xA20, 0x60, D_800F6D98);
            func_80027BA0(0, 0xB10, 0, D_800F6D98 + 8);
        }
        g_playthrough_state.character_state.bytes[0] = 0;
        func_80049E50(arg0);
        func_800477E4(4, &D_800F6C84, arg0);
        set_animation(arg0, 0xD);
        arg0->state = 2;
        arg0->unk42 &= 0x7FFF;
        func_8002CCB0(arg0, 0x28, 0x40);
        return;
    }
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0x28, 0x40) == 0) {
        func_8002CCB0(arg0, 0x28, 0x40);
    }
    D_800F6DA8[arg0->action](arg0);
    apply_object_motion(arg0);
    animate_object(arg0);
}
#undef func_80030ECC

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F6BA4;
extern s32 D_800F6BA8;
extern u16 D_800F6CFC[][4][2];
extern u8 D_800F7794;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED704(void* self) {
    void* parent;
    u16 t;
    u8 b;

    parent = F(void*, 0x80);
    F(u16, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    F(s32, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    F(s32, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    F(u16, 0x42) = M2C_FIELD(parent, u16*, 0x42);
    b = D_800970B4;
    F(u8, 0x16) = 6;
    F(u8, 0x67) = 0;
    F(u8, 0x3) = 0;
    F(s32, 0x68) = 0;
    F(void*, 0x50) = &D_800F6BA4;
    F(void*, 0x54) = &D_800F6BA8;
    F(void*, 0x58) = &D_800743DC;
    F(u8, 0x61) = 0;
    F(u8, 0x15) = 0;
    F(u8, 0x14) = b;
    F(u16, 0xA) = D_800F6CFC[D_800F7794][F(s8, 0x2) - 1][0];
    t = D_800F6CFC[D_800F7794][F(s8, 0x2) - 1][1];
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x5C) = 0x10;
    F(u8, 0x60) = 4;
    F(u16, 0xE) = t;
    set_animation(self, 9);
    F(u8, 0x5) = 2;
    F(u8, 0x6) = 0;
    F(u8, 0x4) = F(u8, 0x4) + 1;
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800ED828);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F6B9C;
extern s32 D_800F6C88;
extern u16 D_800F6CE0[][2];
extern u8 D_800F7794;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED8F0(void* self) {
    s32 b;
    s32 z;

    z = 0;
    D_800F7794 = F(u8, 0x2) & 0xF;
    F(u8, 0x2) = 0;
    F(void*, 0x30) = &D_800F6C88;
    b = D_800970B4;
    {
        // !FAKE: depin: dropping it breaks the match (58/70)
        register s32 t asm("$2") = 6;
        F(u8, 0x16) = t;
    }
    {
        // !FAKE: depin: dropping it breaks the match (65/70)
        register void* a asm("$2") = &D_800F6B9C;
        F(void*, 0x68) = a;
    }
    {
        void* a = &D_800743DC;
        F(void*, 0x58) = a;
    }
    F(u8, 0x67) = 0;
    F(u8, 0x3) = 0;
    F(s32, 0x50) = 0;
    F(s32, 0x54) = 0;
    F(u8, 0x61) = 0;
    F(u8, 0x15) = 0;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0x40000;
    F(u8, 0x5C) = 0x20;
    F(u8, 0x60) = 0;
    F(u8, 0x14) = b;
    set_animation(self, z);
    F(u16, 0xA) = D_800F6CE0[D_800F7794][0];
    F(u16, 0xE) = D_800F6CE0[D_800F7794][1];
    D_800CCEF6 = 1;
    F(u8, 0x5) = 2;
    F(u8, 0x6) = 0;
    F(u8, 0x7) = 5;
    F(u8, 0x4) = F(u8, 0x4) + 1;
}

#include "common.h"

void func_800EDA08(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EDA10);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800CCEF8;
extern u8 D_800F7794;

void func_800EDACC(void* arg0) {
    if (D_800F7794 == 3) {
        D_800CCEF8 = 1;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    func_8002CCB0(arg0, 0x28, 0x40);
}

#define func_800EB8F0 func_800EDB20
#include "../shared/rock_09/func_800EB8F0.c"
#undef func_800EB8F0

#define func_800EB5A0 func_800EDB44
#define D_800F6A84 D_800F6DB4
#include "../shared/rock_04/func_800EB5A0.c"
#undef func_800EB5A0
#undef D_800F6A84

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object(void*);
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */
M2C_UNK func_80030ECC(void*, s16);              /* extern */
#define func_80030ECC (*(M2C_UNK(*)(void*)) & func_80030ECC)
s32 check_enemy_hits(void*);                     /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*); /* extern */
M2C_UNK func_80049E50(void*);                    /* extern */
extern M2C_UNK D_800F6C80;
extern void (*D_800F6DC4[])(struct X4_MainObj*);

void func_800EDBA4(struct X4_MainObj* arg0) {
    if (check_enemy_hits(arg0) < 0) {
        u8* p = *(u8**)((u8*)arg0 + 0x80);
        p[7] = p[7] - 1;
        func_80049E50(arg0);
        func_800477E4(3, &D_800F6C80, arg0);
        arg0->state = 2;
        return;
    }
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0x10, 0x10) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
    }
    D_800F6DC4[arg0->action](arg0);
    apply_object_motion(arg0);
    animate_object(arg0);
}
#undef func_80030ECC

#include "common.h"

void func_800EDC70(void) {
}

#include "common.h"

void func_800EDC78(void) {
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EDC80(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EB5A0 func_800EDCC0
#define D_800F6A84 D_800F6DD0
#include "../shared/rock_04/func_800EB5A0.c"
#undef func_800EB5A0
#undef D_800F6A84

#define func_800EBAF0 func_800EDD20
#include "../shared/rock_09/func_800EBAF0.c"
#undef func_800EBAF0

#define func_800EBBD4 func_800EDE04
#include "../shared/rock_09/func_800EBBD4.c"
#undef func_800EBBD4

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EDF04(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EB5A0 func_800EDF44
#define D_800F6A84 D_800F6DE0
#include "../shared/rock_04/func_800EB5A0.c"
#undef func_800EB5A0
#undef D_800F6A84

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EDFA4);
// clang-format on

#define func_800EBE60 func_800EE090
#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((M2C_UNK(*)(void*))func_80030ECC)

void func_800EE090(void* arg0) {
    switch (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 0x7)) {
    case 3:
        if (M2C_FIELD(arg0, u8*, 0x17) != 6) {
            set_animation(arg0, 6);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, u8*, 0x17) != 7) {
            set_animation(arg0, 7);
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, u8*, 0x17) != 8) {
            set_animation(arg0, 8);
        }
        break;
    case 0:
        M2C_FIELD(arg0, u8*, 0x4) = 2;
        return;
    }
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0x30, 0x40) == 0) {
        func_8002CCB0(arg0, 0x30, 0x40);
    }
    apply_object_motion(arg0);
    animate_object(arg0);
}
#undef func_80030ECC
#undef func_800EBE60

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EE194(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800ED3E4 func_800EE1D4
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s32 g_Player;

#define PL ((u8*)&g_Player)
#define F_S8(p, o) (*(s8*)((p) + (o)))
#define F_S16(p, o) (*(s16*)((p) + (o)))

void func_800EE1D4(u8* arg0) {
    u8* pl;
    s8 hp;
    s8 v;

    if (D_800CCEF6 == 0) {
        arg0[4]++;
        return;
    }
    pl = PL;
    if (F_S16(pl, 0x14C) != 0) {
        play_sound(5, 4, 0);
    }
    if (F_S8(pl, 0x5C) != 0 && F_S8(pl, 0xE0) == 0) {
        if (++*(u16*)(arg0 + 0x16) >= 0xB4) {
            *(u16*)(arg0 + 0x16) = 0;
            hp = F_S8(pl, 0x5C);
            v = F_S8(pl, 0x5C) & 0x7F;
            F_S8(pl, 0x5C) = v;
            if (D_8008EAFC == 0) {
                if (v < 2) {
                    F_S8(pl, 0x5C) = -0x80;
                } else {
                    F_S8(pl, 0x5C) = v - 1;
                }
            }
            if (hp < 0) {
                u8* q = PL;
                F_S8(q, 0x5C) |= 0x80;
            }
        }
        if (++*(u16*)(arg0 + 0x18) >= 0x33) {
            u8* q = PL;
            *(u16*)(arg0 + 0x18) = 0;
            F_S8(q, 0xE8) = 1;
        }
    }
}
#undef PL
#undef F_S8
#undef F_S16
#undef func_800ED3E4

#include "../shared/rock_24/func_800EE300.c"

#include "common.h"
#define M2C_UNK s32

extern M2C_UNK D_800F7798;

#define SP_30 (*(u8**)0x1F800030)

void func_800EE3A0(u8* arg0) {
    u8* src;

    arg0[0] |= 8;
    if (*(s8*)(arg0 + 2) == 0) {
        *(s16*)(arg0 + 0x20) = 0xF;
        src = SP_30 + 0x200;
    } else {
        *(s16*)(arg0 + 0x20) = 0x16;
        src = SP_30;
    }
    __builtin_memcpy(&D_800F7798, src, 0x20);
    arg0[4]++;
}

#undef SP_30

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800F7798;
extern M2C_UNK D_800F77B8;

void func_800EE478(u8* arg0) {
    if (D_800CCEF6 != 0) {
        *(u16*)(arg0 + 0x14) = 0;
        *(u16*)(arg0 + 0x16) = 0;
        *(u16*)(arg0 + 0x18) = 0;
        {
            u8* bg = (u8*)background_objects;
            *(u16*)(bg + 0x5E) = 0;
            *(u16*)(bg + 0x62) = 0;
            bg[0xA0] = 1;
        }
        *(u16*)(arg0 + 0x1E) = 1;
        *(u16*)(arg0 + 0x1A) = 0;
        func_8002B410(&D_800F77B8, &D_800F7798, 0x10, 0x3C, 0x3C);
        load_palette(*(u16*)(arg0 + 0x20) + 0x60, &D_800F77B8, 1);
        play_sound(5, 4, 0);
        arg0[4]++;
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800F7798;
extern M2C_UNK D_800F77B8;

void func_800EE538(u8* arg0) {
    if (D_800CCEF6 == 0) {
        arg0[4] += 2;
        return;
    }
    if (++*(u16*)(arg0 + 0x1A) >= 0x3C) {
        *(u16*)(arg0 + 0x1A) = 0x3C;
    }
    func_8002B410(&D_800F77B8, &D_800F7798, 0x10, 0x3C - *(u16*)(arg0 + 0x1A),
                  0x3C);
    load_palette(*(u16*)(arg0 + 0x20) + 0x60, &D_800F77B8, 1);
    if (*(u16*)(arg0 + 0x1A) == 0x3C) {
        arg0[4]++;
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK load_palette(s32, M2C_UNK*, M2C_UNK);                 /* extern */
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK D_800F7798;
extern M2C_UNK D_800F77B8;

void func_800EE604(void* arg0) {
    u16 temp_v0;

    if (D_800CCEF6 != 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) - 2);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 0x1A);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u16*, 0x1A) = (u16)(temp_v0 - 1);
    }
    func_8002B410(&D_800F77B8, &D_800F7798, 0x10,
                  0x3C - M2C_FIELD(arg0, u16*, 0x1A), 0x3C);
    load_palette(M2C_FIELD(arg0, u16*, 0x20) + 0x60, &D_800F77B8, 1);
    if (M2C_FIELD(arg0, u16*, 0x1A) == 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) - 3);
        play_sound(5, 3, 0);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EE6C8);
// clang-format on

#define func_800EE70C func_800EE808
#define g_Player g_Player
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002B6B0();
M2C_UNK player_load_weapon_palette(void*);
M2C_UNK func_8003CDF0(void*);
M2C_UNK clear_flash_palette(void*);
M2C_UNK refresh_weapon_state(void*);
extern M2C_UNK g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EE808(u8* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    u8* q;
    u16 a;
    s32 two;

    if (F8(p, 0x5C) != 0) {
        background_objects[0].unk44 = 0;
        background_objects[1].unk44 = 0;
        background_objects[2].unk44 = 0;
        two = 2;
        q = (u8*)&g_playthrough_state;
        q[0x10] = two;
        q[0x11] = two;
        q[0x12] = two;
        q[0x13] = two;
        q[0x14] = two;
        q[0x15] = two;
        q[0x16] = two;
        q[0x17] = two;
        q[0x19] = two;
        arg0[0] |= 8;
        F32(arg0, 0x88) = F32(p, 0x68);
        F32(p, 0x68) = 0;
        FU8(p, 0x5) = 2;
        refresh_weapon_state(p);
        func_8003CDF0(p);
        clear_flash_palette(p);
        player_load_weapon_palette(p);
        func_8002B6B0();
        F16(arg0, 0x7C) = 0;
        a = FU16(p, 0xA);
        FU16(arg0, 0x80) = a;
        FU16(arg0, 0x82) = a;
        arg0[6]++;
        play_sound(1, 1, arg0);
    }
}
#undef func_800EE70C
#undef g_Player

#define func_800EE800 func_800EE8FC
#define D_80097420 D_80097420
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"
extern struct X4_EngineObj g_playthrough_state;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EE8FC(u8* arg0) {
    s32 a;
    s32 b;
    void* t;

    a = FU16(arg0, 0x80) + 1;
    b = FU16(arg0, 0x82) - 1;
    FU16(arg0, 0x80) = a;
    FU16(arg0, 0x82) = b;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (D_80097420.transition.active == 0) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi = FU16(arg0, 0x84);
        t = *(void**)(arg0 + 0x88);
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk19 = 0;
        g_Player.terrain_box = t;
    }
}
#undef g_Player
#undef func_800EE800
#undef D_80097420

#define func_800EE8C4 func_800EE9C0
#define background_objects background_objects
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B6B0();
M2C_UNK player_load_weapon_palette();
M2C_UNK func_8003CDF0();
M2C_UNK clear_flash_palette(void*);
M2C_UNK refresh_weapon_state(void*);
extern M2C_UNK g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800EE9C0(void* arg0) {
    void* p;
    s32 v;

    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
        return;
    }
    play_sound(1, 1, arg0);
    p = &g_Player;
    background_objects[0].unk44 = 0;
    background_objects[1].unk44 = 0;
    background_objects[2].unk44 = 0;
    v = 2;
    g_playthrough_state.unk10 = v;
    g_playthrough_state.unk11 = v;
    g_playthrough_state.unk12 = v;
    g_playthrough_state.unk13 = v;
    g_playthrough_state.unk14 = v;
    g_playthrough_state.unk15 = v;
    g_playthrough_state.unk16 = v;
    g_playthrough_state.unk17 = v;
    g_playthrough_state.unk19 = v;
    M2C_FIELD(arg0, u8*, 0) |= 8;
    M2C_FIELD(arg0, s32*, 0x88) = M2C_FIELD(p, s32*, 0x68);
    M2C_FIELD(p, s32*, 0x68) = 0;
    M2C_FIELD(p, s8*, 5) = 2;
    refresh_weapon_state(p);
    func_8003CDF0(p);
    clear_flash_palette(p);
    player_load_weapon_palette(p);
    func_8002B6B0();
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x82) = M2C_FIELD(arg0, s16*, 0x80) =
        M2C_FIELD(p, s16*, 0xA);
    M2C_FIELD(arg0, u8*, 6) += 1;
}
#undef func_800EE8C4
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EEAC0);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EEEB4);
// clang-format on

#define func_800EA1D8 func_800EEFC0
#define D_800FAA64 D_800F6E4C
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EF00C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EF088(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EEFCC func_800EF0C8
#define g_Player g_Player
#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D654(s8*, u8*);
#define M2C_UNK s32
extern M2C_UNK g_Player;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EF0C8(s8* arg0) {
    u8* p = (u8*)&g_Player;
    u16 v;
    u16 w;

    if (func_8002D654(arg0, p) != 0) {
        if (arg0[2] == 2) {
            v = FU16(p, 0xA);
            FU16(arg0, 0x7C) = 0;
            arg0[5] = 3;
            arg0[6] = 0;
            FU16(arg0, 0x84) = v;
            return;
        }
        w = FU16(p, 0xA);
        arg0[5] = 2;
        arg0[6] = 0;
        FU16(arg0, 0x84) = w;
    }
}
#undef func_800EEFCC
#undef g_Player

#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EF140(void* arg0) {
    if ((D_800CCEF6 == 0) && (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA))) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EF18C(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800EF1C8
#define D_80073C1C D_800F6E74
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800EF204
#define D_80073C1C D_800F6F10
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF144 func_800EF240
#include "../shared/commander_yammark/func_800EF144.c"
#undef func_800EF144

#define func_800EF1E8 func_800EF2E4
#include "../shared/commander_yammark/func_800EF1E8.c"
#undef func_800EF1E8

#define func_800EF27C func_800EF378
#define D_80097420 D_80097420
#include "../shared/commander_yammark/func_800EF27C.c"
#undef func_800EF27C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EF3E0(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define F(type, off) M2C_FIELD(arg0, type*, off)

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_8007573C[];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E98B8[];
extern s32 D_800F6F2C;
extern s32 D_800F6F30[];
extern s32 D_800F74A0;
extern s32 D_800F77E4;
extern M2C_UNK D_800F77EC;
extern s16 D_800F77F8;
extern s16 D_800F7804;
extern s8 D_800F7806;

void func_800EF400(void* arg0) {
    u8 tbl[4];
    u8 bg;

    __builtin_memcpy(tbl, D_800E98B8, 4);
    F(void*, 0x30) = &D_800F74A0;
    bg = D_800970B4;
    {
        // !FAKE: depin: dropping it breaks the match (64/100)
        register s32 c5 asm("$2") = 5;
        F(u8, 0x16) = c5;
    }
    {
        // !FAKE: depin: dropping it breaks the match (62/100)
        register void* a50 asm("$2") = &D_800F6F2C;
        // !FAKE: depin: dropping it breaks the match (89/100)
        register void* a54 asm("$3") = D_800F6F30;
        F(void*, 0x50) = a50;
        {
            // !FAKE: depin: dropping it breaks the match (85/100)
            register void* a58 asm("$2") = D_8007573C;
            F(void*, 0x58) = a58;
        }
        F(void*, 0x54) = a54;
    }
    {
        // !FAKE: depin: dropping it breaks the match (87/100)
        register s32 cA asm("$2") = 0xD80;
        F(s16, 0xA) = cA;
    }
    F(u8, 0x60) = 6;
    F(u8, 0x15) = 0;
    F(u8, 0x67) = 0;
    F(u8, 0x3) = 0;
    F(s32, 0x68) = 0;
    F(u8, 0x62) = 0;
    F(u8, 0x61) = 0;
    {
        // !FAKE: depin: dropping it breaks the match (81/100)
        register s32 cE asm("$3") = 0x390;
        F(s16, 0xE) = cE;
    }
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x5C) = 0;
    F(u8, 0x14) = bg;
    g_playthrough_state.unk25 = 0;
    M2C_FIELD(&g_playthrough_state, void**, 0x20) = arg0;
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x30;
    set_boss_level();
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) +=
        tbl[M2C_FIELD(&g_playthrough_state, u8*, 0x8F)];
    F(u8, 0x87) = 0;
    F(u8, 0x86) = 0;
    F(u8, 0x84) = 0;
    func_8003D308(0x14, 0x40);
    D_800F77D8 = 0;
    D_800F77DC = 0;
    D_800F7800 = arg0;
    D_800F77E4 = 0;
    D_800F77E8 = 0;
    D_800F77EC = 0;
    D_800F77F0 = 0;
    D_800F77F4 = 0;
    D_800F7804 = 0;
    D_800F7806 = 0;
    D_800F77F8 = 0;
    F(u8, 0x5) = 2;
    F(u8, 0x4)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EF590 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC (*(M2C_UNK(*)(void*)) & func_80030ECC)
s32 check_enemy_hits(void*);
extern s32 D_8007573C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;
extern void (*D_800F75FC[])(void*);
extern s16 D_800F7804;
extern s8 D_800F7806;
extern u16 D_800F7808;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EF590(void* self) {
    s8 hp;
    u8 t;
    s32 r;

    D_800F7804 = 0;
    hp = F(s8, 0x5C);
    r = check_enemy_hits(self);
    D_800F7806 = 0;
    if (r > 0) {
        D_800F7806 = hp - F(u8, 0x5C);
        F(s8, 0x5C) = hp;
    }
    if (D_800F77DC != 0) {
        if (F(s8, 0x5) != 8) {
            if ((F(s8, 0x5C) -= 4) <= 0) {
                F(u16, 0x40) = 0x140;
                F(s16, 0x42) =
                    ((func_8002A47C(F(s8, 1)) * 4 + 0x20) % 16) |
                    (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
                F(u8*, 0x3C) = (u8*)SPAD20_800EF590 +
                               SPAD20_800EF590[func_8002A47C(F(s8, 1))];
                set_animation(self, 7);
                F(s8, 0x4) = 2;
                F(s8, 0x5C) = 0;
                F(s32, 0x20) = 0;
                F(s32, 0x24) = 0;
                F(s32, 0x28) = 0;
                F(s32, 0x2C) = 0;
                F(s8, 0x5) = 0;
                F(s8, 0x6) = 0;
                F(u16, 0x42) &= 0x7FFF;
                {
                    // !FAKE: depin: dropping it breaks the match (159/164)
                    register s32 one asm("$3") = 1;
                    D_800F77D8 = one;
                    g_Player.spike_immune = one;
                }
                g_Player.terrain_box = 0;
                func_8002CCB0(self, 0x30, 0x40);
                return;
            }
            F(s8, 0x5) = 8;
            F(s8, 0x6) = 0;
        }
    } else if (F(s8, 0x5) != 8) {
        func_80030ECC(self);
    }
    t = F(u8, 0x84);
    if (t != 0) {
        F(u8, 0x84) = t + 0xFF;
        if (t & 2) {
            F(u16, 0x42) |= 0x8000;
        } else {
            F(u16, 0x42) &= 0x7FFF;
        }
        if (F(u8, 0x84) == 0) {
            F(s32*, 0x58) = D_8007573C;
            F(u16, 0x42) &= 0x7FFF;
        }
    }
    if (D_800F77E8 & (s16)D_800F7808++ & 1) {
        g_playthrough_state.unk10 = 1;
        g_playthrough_state.unk11 = 1;
        g_playthrough_state.unk13 = 1;
    } else {
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk13 = 0;
    }
    D_800F75FC[F(s8, 0x5)](self);
}

#undef F
#undef g_Player
#undef func_80030ECC
#undef SPAD20_800EF590

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define S8(o) M2C_FIELD(arg0, s8*, o)
#define U8(o) M2C_FIELD(arg0, u8*, o)
#define U16(o) M2C_FIELD(arg0, u16*, o)
#define S16(o) M2C_FIELD(arg0, s16*, o)
#define S32(o) M2C_FIELD(arg0, s32*, o)
#define PTR(o) M2C_FIELD(arg0, void**, o)
#define SCRATCH_PTR (*(u8**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s16 D_800970AA;

void func_800EF820(void* arg0) {
    s32 x;
    s32 y;
    s32 t;
    u8* p;

    if (D_800CCEDF == 0) {
        if (--S16(0x7C) == 0) {
            func_8003D308(0x14, 0x40);
        }
        if (*(s8*)PTR(0x80) == 0) {
            S32(0x24) = 0xFFFF0000;
            {
                s32 g = D_800970AA;
                if (S16(0xA) < g) {
                    U8(0x15) = 0x40;
                } else {
                    U8(0x15) = 0;
                }
            }
            S16(0x40) = 0x140;
            x = func_8002A47C(S8(1));
            y = func_8002A47C(S8(1));
            x *= 4;
            S16(0x42) = ((x + 0x20) % 16) | (((y + 8) / 4 + 0x1E0) << 6);
            t = func_8002A47C(S8(1));
            p = SCRATCH_PTR;
            t = *(s32*)(p + t * 4);
            PTR(0x3C) = p + t;
            ((void (*)(void*, s32, s32))set_animation)(arg0, 0, t);
            U8(6)++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define S8(o) M2C_FIELD(arg0, s8*, o)
#define U8(o) M2C_FIELD(arg0, u8*, o)
#define U16(o) M2C_FIELD(arg0, u16*, o)
#define S16(o) M2C_FIELD(arg0, s16*, o)
#define S32(o) M2C_FIELD(arg0, s32*, o)
#define PTR(o) M2C_FIELD(arg0, void**, o)
#define SCRATCH_PTR (*(u8**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800EF95C(void* arg0) {
    s32 x;
    s32 y;
    s32 t;
    u8* p;

    if (S16(0xE) >= 0x458) {
        S32(0x68) = 0;
        S16(0x40) = 0x140;
        x = func_8002A47C(S8(1));
        y = func_8002A47C(S8(1));
        x *= 4;
        S16(0x42) = ((x + 0x20) % 16) | (((y + 8) / 4 + 0x1E0) << 6);
        t = func_8002A47C(S8(1));
        p = SCRATCH_PTR;
        {
            // !FAKE: depin: dropping it breaks the match (42/63)
            register s32 u asm("$6") = *(s32*)(p + t * 4);
            PTR(0x3C) = p + u;
            ((void (*)(void*, s32, s32))set_animation)(arg0, 1, u);
        }
        S32(0x24) = 0;
        U8(6)++;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EFA58 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
s32 func_8002A47C(s32);
s32 func_8002B2F8(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800EFA58(void* arg0) {
    s32 c;

    if ((s16)--M2C_FIELD(arg0, u16*, 0x7C) == -1) {
        M2C_FIELD(arg0, u16*, 0x7C) = 2;
        c = (u16)D_800CF854 - 1;
        D_800CF854 = c;
        D_80097430 -= 0x20;
        D_80090D5C -= 0x400;
        D_800C4560 |= 1;
        if ((u16)c == 0) {
            func_8002B2F8(0);
            M2C_FIELD(arg0, s16*, 0x40) = 0x140;
            M2C_FIELD(arg0, s16*, 0x42) =
                ((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 8) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(arg0, u8**, 0x3C) =
                (u8*)SPAD20_800EFA58 +
                SPAD20_800EFA58[func_8002A47C(M2C_FIELD(arg0, s8*, 1))];
            set_animation(arg0, 2);
            {
                // !FAKE: depin: dropping it breaks the match (84/87)
                register s32 n asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
                M2C_FIELD(arg0, u8*, 6) = n;
            }
        }
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EFBB4 (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80040488(M2C_UNK);

void func_800EFBB4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x89, (s32)arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        M2C_FIELD(arg0, s16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, u8**, 0x3C) =
            (u8*)SPAD20_800EFBB4 +
            SPAD20_800EFBB4[func_8002A47C(M2C_FIELD(arg0, s8*, 1))];
        set_animation(arg0, 3);
        func_80040488(0);
        D_800CCEF4 = 1;
        {
            s32 n = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = n;
        }
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002A47C(s32);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;

#define SPAD20 (*(s32**)0x1F800020)
#define F_S8(o) M2C_FIELD(self, s8*, (o))
#define F_U8(o) M2C_FIELD(self, u8*, (o))
#define F_S16(o) M2C_FIELD(self, s16*, (o))
#define F_PTR(o) M2C_FIELD(self, void**, (o))

void func_800EFCDC(void* self) {
    s32 a;
    s32 b;
    s32 g;

    g = D_800970AA;
    if (F_S16(0xA) < g) {
        F_U8(0x15) = 0x40;
    } else {
        F_U8(0x15) = 0;
    }
    F_S16(0x40) = 0x140;
    a = func_8002A47C(F_S8(0x1));
    b = func_8002A47C(F_S8(0x1));
    F_S16(0x42) = ((a * 4 + 0x20) % 16) | ((((b + 8) / 4) + 0x1E0) << 6);
    F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[func_8002A47C(F_S8(0x1))];
    ((void (*)(void*, s32))set_animation)(self, 3);
    F_S16(0x7C) = 0;
    F_U8(0x6)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 random_byte();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E98BC[];
extern s32 D_800F77E4;
extern M2C_UNK D_800F77EC;

#define ENG ((u8*)&g_playthrough_state)

void func_800EFDCC(u8* arg0) {
    u8 sp10[4];
    u32 r;
    u8 idx;
    s32 t;
    u8* eng;
    u8* eng2;

    __builtin_memcpy(sp10, D_800E98BC, 4);
    r = random_byte() & 0xF;
    eng = (u8*)&g_playthrough_state;
    arg0[0x87] = 0;
    if (D_800F77EC < sp10[eng[0x8F]] && D_800F77F0 == 0 && D_800F77F4 == 0) {
        if (((s8)eng[0x8C] / 2) < (s8)arg0[0x5C]) {
            if (r < 8) {
                // !FAKE: goto keeps retail block order of the shared state arms (C0173); nested if/else reorders blocks
                goto zero;
            }
            arg0[0x86] = 1;
        } else if (r < 5) {
        zero:
            arg0[0x86] = 0;
        } else {
            if (r >= 10) {
                arg0[0x86] = 2;
            } else {
                arg0[0x86] = 1;
            }
        }
        D_800F77E4 = 0;
    } else if (eng2 = (u8*)&g_playthrough_state,
               ((s8)eng2[0x8C] / 2) < (s8)arg0[0x5C]) {
        if (D_800F77E4 < 4) {
            // !FAKE: goto keeps retail block order of the shared state arms (C0173); nested if/else reorders blocks
            goto three;
        }
        // !FAKE: goto keeps retail block order of the shared state arms (C0173); nested if/else reorders blocks
        goto four;
    } else if (D_800F77E4 < 3) {
    three:
        arg0[0x86] = 3;
    } else {
    four:
        arg0[0x86] = 4;
        D_800F77E4 = 0;
    }
    idx = arg0[0x87]++;
    t = D_800F7528[idx + arg0[0x86] * 6];
    arg0[6] = 0;
    arg0[5] = t;
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}

#undef ENG

#include "common.h"
#define M2C_UNK s32

#define F(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))
#define SPAD_20 (*(u8**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;

void func_800EFFA4(void* self) {
    // !FAKE: first result scaled in place in its callee-saved register
    register s32 a asm("$16");
    s32 b;
    u8* base;
    s32 g;
    s32 c;

    g = D_800970AA;
    if (F(self, s16, 0xA) < g) {
        F(self, u8, 0x15) = 0x40;
    } else {
        F(self, u8, 0x15) = 0;
    }
    F(self, s16, 0x40) = 0x140;
    a = func_8002A47C(F(self, s8, 0x1));
    b = func_8002A47C(F(self, s8, 0x1));
    c = a * 4;
    F(self, s16, 0x42) = ((c + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    a = func_8002A47C(F(self, s8, 0x1));
    base = SPAD_20;
    F(self, u8*, 0x3C) = base + *(s32*)(base + a * 4);
    set_animation(self, 3);
    {
        // !FAKE: byte counter read into the first return register
        register s32 t asm("$2") = F(self, u8, 0x6);
        F(self, s16, 0x7C) = 0x5A;
        F(self, u8, 0x6) = t + 1;
    }
}

#undef SPAD_20
#undef F

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 random_byte();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E98C0[];

// str 0x800E98C0 sha1=1319e42db8e4d96764593c2726f8a8f863f48283 = "printable byte run: data, not text"
void func_800F0098(void* arg0) {
    u8 tbl[4];
    s32 r;
    s32 a;
    s32 b;
    s16 angle;
    u16 px;
    u16 py;

    __builtin_memcpy(tbl, D_800E98C0, 4);
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        r = random_byte() & 0xF;
        if (r < 3) {
            ((void (*)(s32, s32, s32))play_sound)(2, 0x22, (s32)arg0);
        } else if (r < 6) {
            ((void (*)(s32, s32, s32))play_sound)(2, 0x23, (s32)arg0);
        }
        if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u16*, 0x40) = 0x140;
        a = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        b = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        M2C_FIELD(arg0, u16*, 0x42) =
            ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, u16*, 0x88) = px = g_Player.x_pos.i.hi;
        M2C_FIELD(arg0, u16*, 0x8A) = py = g_Player.y_pos.i.hi;
        angle = ratan2((s16)py - M2C_FIELD(arg0, s16*, 0xE),
                       (s16)px - M2C_FIELD(arg0, s16*, 0xA));
        {
            u8* e;
            s32 c;
            c = rcos(angle);
            e = (u8*)&g_playthrough_state;
            M2C_FIELD(arg0, s32*, 0x20) = c * tbl[e[0x8F]];
            M2C_FIELD(arg0, s32*, 0x24) = -rsin(angle) * tbl[e[0x8F]];
        }
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
#undef g_Player

#include "common.h"
#include "mmx6/rock_24.h"

extern s32 D_800F77E4;

void func_800F02AC(void* arg0) {
    s32 v;
    s32 c;
    u8 i;
    s32 t;
    s32 m;

    v = *(s32*)((u8*)arg0 + 0x20);
    if (v < 0) {
        {
            // !FAKE: depin: dropping it breaks the match (61/68)
            register s32 x asm("$2") = *(s16*)((u8*)arg0 + 0xA);
            c = x < *(s16*)((u8*)arg0 + 0x88);
        }
        // !FAKE: goto shares the clamp tail between the sign arms; a copied tail moved bytes
        goto block_4;
    }
    if (v > 0) {
        c = *(s16*)((u8*)arg0 + 0xA) > *(s16*)((u8*)arg0 + 0x88);
    block_4:
        m = *(u16*)((u8*)arg0 + 0x88);
        if (c != 0) {
            *(s16*)((u8*)arg0 + 0xA) = m;
            *(s32*)((u8*)arg0 + 0x20) = 0;
        }
    }
    v = *(s32*)((u8*)arg0 + 0x24);
    if (v < 0) {
        c = *(s16*)((u8*)arg0 + 0xE) > *(s16*)((u8*)arg0 + 0x8A);
        // !FAKE: goto shares the clamp tail between the sign arms; a copied tail moved bytes
        goto block_10;
    }
    if (v > 0) {
        {
            // !FAKE: depin: dropping it breaks the match (61/68)
            register s32 x asm("$2") = *(s16*)((u8*)arg0 + 0xE);
            c = x < *(s16*)((u8*)arg0 + 0x8A);
        }
    block_10:
        m = *(u16*)((u8*)arg0 + 0x8A);
        if (c != 0) {
            *(s16*)((u8*)arg0 + 0xE) = m;
            *(s32*)((u8*)arg0 + 0x24) = 0;
        }
    }
    if (*(s32*)((u8*)arg0 + 0x20) == 0 && *(s32*)((u8*)arg0 + 0x24) == 0) {
        D_800F77E4 += 1;
        i = (*((u8*)arg0 + 0x87))++;
        t = D_800F7528[i + *((u8*)arg0 + 0x86) * 6];
        *((u8*)arg0 + 6) = 0;
        *((u8*)arg0 + 5) = t;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F03BC (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 random_byte();
extern s16 D_800970AA;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F03BC(void* self) {
    s32 t = D_800970AA;

    {
        // !FAKE: depin: dropping it breaks the match (63/68)
        register s32 f asm("$3") = F(s16, 0xA);
        if (f < t) {
            F(u8, 0x15) = 0x40;
        } else {
            F(u8, 0x15) = 0;
        }
    }
    if (!(random_byte(t) & 3)) {
        play_sound(2, 0x24, self);
    }
    F(u16, 0x40) = 0x140;
    F(s16, 0x42) = ((func_8002A47C(F(s8, 1)) * 4 + 0x20) % 16) |
                   (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
    F(u8*, 0x3C) =
        (u8*)SPAD20_800F03BC + SPAD20_800F03BC[func_8002A47C(F(s8, 1))];
    ((void (*)(void*, s32))set_animation)(self, 6);
    F(s16, 0x7C) = 0;
    F(u8, 0x6)++;
}

#undef F
#undef SPAD20_800F03BC
#undef M2C_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
void* func_8002C458();
s32 random_byte();
extern M2C_UNK D_800F77EC;

void func_800F04CC(void* arg0) {
    void* child;
    s16 t;

    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s8*, 7) = random_byte() % 5;
        if ((M2C_FIELD(arg0, s8*, 7) == 3) && (D_800F77EC != 0)) {
            M2C_FIELD(arg0, s8*, 7) -= 1;
        }
        if ((M2C_FIELD(arg0, s8*, 7) == 4) && (D_800F77EC != 0)) {
            M2C_FIELD(arg0, s8*, 7) -= 3;
        }
        child = func_8002C458();
        if (child != 0) {
            u8 b0 = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(child, u8*, 1) = 0x1A;
            M2C_FIELD(child, u8*, 0) = b0;
            b0 = M2C_FIELD(arg0, u8*, 7);
            M2C_FIELD(child, void**, 0x7C) = arg0;
            M2C_FIELD(child, u8*, 2) = b0 + 0x1E;
        }
    }
    t = ++M2C_FIELD(arg0, s16*, 0x7C);
    if (t == 22) {
        child = func_8002C458();
        if (child != 0) {
            u8 b0 = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(child, u8*, 1) = 0x1A;
            M2C_FIELD(child, u8*, 0) = b0;
            b0 = M2C_FIELD(arg0, u8*, 7);
            M2C_FIELD(child, void**, 0x7C) = arg0;
            M2C_FIELD(child, u8*, 2) = b0;
            play_sound(2, 0x8A, (s32)arg0);
        }
    } else if (t == 50) {
        u8 i = M2C_FIELD(arg0, u8*, 0x87)++;
        u8 v = D_800F7528[i + M2C_FIELD(arg0, u8*, 0x86) * 6];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 random_byte();
extern s16 D_800970AA;

void func_800F0654(void* arg0) {
    s32 a;
    s32 b;

    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (random_byte() & 1) {
        play_sound(2, 0x25, arg0);
    } else {
        play_sound(2, 0x26, arg0);
    }
    M2C_FIELD(arg0, u16*, 0x40) = 0x140;
    a = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    b = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    M2C_FIELD(arg0, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(arg0, s32*, 0x3C) =
        SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
    ((void (*)(void*, s32))set_animation)(arg0, 4);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6)++;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F0778 (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern M2C_UNK D_8007433C;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F0778(void* self) {
    play_sound(2, 0x21, self);
    F(s16, 0x40) = 0x140;
    F(s16, 0x42) = ((func_8002A47C(F(s8, 1)) * 4 + 0x20) % 16) |
                   (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
    F(u8*, 0x3C) =
        (u8*)SPAD20_800F0778 + SPAD20_800F0778[func_8002A47C(F(s8, 1))];
    set_animation(self, 7);
    F(void*, 0x58) = &D_8007433C;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(s16, 0x7C) = 0;
    F(u8, 6)++;
    func_8002CCB0(self, 0x30, 0x40);
    apply_object_motion(self);
}

#undef F

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800F0884);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800F0A24);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F77EC;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F0B90(struct X4_MainObj* arg0) {
    s32 a;
    s32 b;

    arg0->animation_table = D_800F7800->animation_table;
    arg0->bg_offset = D_800F7800->bg_offset;
    arg0->unk16 = 4;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = &D_8007433C;
    arg0->unk15 = D_800F7800->unk15;
    arg0->unk40 = 0x140;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 9);
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi - 0x18;
    } else {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi + 0x18;
    }
    arg0->y_pos.i.hi = D_800F7800->y_pos.i.hi - 0xE;
    {
        // !FAKE: depin: dropping it breaks the match (102/111)
        register s32 e asm("$2") = 8;
        // !FAKE: depin: dropping it breaks the match (97/111)
        register s32 f asm("$3") = 4;

        arg0->hp = e;
        arg0->contact_damage = f;
    }
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->ext.raw[3] = 0;
    D_800F77EC += 1;
    arg0->ext.raw[6] = 0;
    arg0->action = 0;
    arg0->state++;
}
#undef D_800F7800

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800F0D4C);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F77EC;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F12FC(struct X4_MainObj* arg0) {
    s32 a;
    s32 b;

    arg0->animation_table = D_800F7800->animation_table;
    arg0->bg_offset = D_800F7800->bg_offset;
    arg0->unk16 = 4;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = &D_8007433C;
    arg0->unk15 = D_800F7800->unk15;
    arg0->unk40 = 0x140;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 0xE);
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi - 0x18;
    } else {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi + 0x18;
    }
    arg0->y_pos.i.hi = D_800F7800->y_pos.i.hi - 0xE;
    {
        // !FAKE: depin: dropping it breaks the match (102/111)
        register s32 e asm("$2") = 8;
        // !FAKE: depin: dropping it breaks the match (97/111)
        register s32 f asm("$3") = 4;

        arg0->hp = e;
        arg0->contact_damage = f;
    }
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->ext.raw[3] = 0;
    D_800F77EC += 1;
    arg0->ext.raw[6] = 0;
    arg0->action = 0;
    arg0->state++;
}
#undef D_800F7800

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*, s16);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_8007573C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800970AA;
extern u8 D_800E99AC[];
extern s32 D_800F76A4[];
extern s32 D_800F76A8[];
extern s8 D_800F7806;
#define D_1F800020 (*(u8**)SP(0x20))
#define func_80030ECC (*(void (*)(void*)) & func_80030ECC)

void func_800F14B8(void* arg0) {
    u8 tbl[4];
    void* child;
    void* q;
    s32 i;
    s16 angle;
    s32 a;
    s32 b;
    s32 c;
    u8* base;

    __builtin_memcpy(tbl, D_800E99AC, 4);
    ((void (*)(void*))apply_object_motion)(arg0);
    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    M2C_FIELD(arg0, s8*, 7) = check_enemy_hits(arg0);
    if (M2C_FIELD(arg0, s8*, 7) < 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 1;
        M2C_FIELD(arg0, s8*, 5) = 10;
    } else {
        M2C_FIELD(arg0, u32*, 0x98) += D_800F7806;
        if ((M2C_FIELD(arg0, u32*, 0x98) >= 0x10) &&
            (M2C_FIELD(arg0, s8*, 5) < 11)) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, void**, 0x50) = 0;
            M2C_FIELD(arg0, void**, 0x54) = 0;
            M2C_FIELD(arg0, s16*, 0x88) = 0x3C;
            M2C_FIELD(arg0, s8*, 5) = 0x14;
        }
    }
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 12) {
            M2C_FIELD(arg0, void**, 0x50) = D_800F76A4;
            M2C_FIELD(arg0, void**, 0x54) = D_800F76A8;
            if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            {
                s32 px = g_Player.x_pos.i.hi;
                s32 py;
                M2C_FIELD(arg0, s32*, 0x90) = px;
                py = g_Player.y_pos.i.hi;
                M2C_FIELD(arg0, s32*, 0x94) = py;
                angle = ratan2(py - M2C_FIELD(arg0, s16*, 0xE),
                               px - M2C_FIELD(arg0, s16*, 0xA));
            }
            M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) * 48;
            M2C_FIELD(arg0, s32*, 0x24) = -rsin(angle) * 48;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(arg0, u32*, 0x90)) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, u32*, 0x90);
            }
        } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xA) > M2C_FIELD(arg0, u32*, 0x90)) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, u32*, 0x90);
            }
        }
        if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xE) > M2C_FIELD(arg0, u32*, 0x94)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, u32*, 0x94);
            }
        } else if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xE) < M2C_FIELD(arg0, u32*, 0x94)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, u32*, 0x94);
            }
        }
        if ((M2C_FIELD(arg0, s32*, 0x20) == 0) &&
            (M2C_FIELD(arg0, s32*, 0x24) == 0)) {
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(child, u8*, 1) = 0x1A;
                M2C_FIELD(child, u8*, 2) = 0xB;
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
            M2C_FIELD(arg0, s32**, 0x58) = D_8007573C;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s32*, 0x90) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 2:
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 60) {
            {
                void* p = D_800F7800;
                M2C_FIELD(arg0, u16*, 0x40) = 0x140;
                a = func_8002A47C(M2C_FIELD(p, s8*, 1));
            }
            b = func_8002A47C(M2C_FIELD(D_800F7800, s8*, 1));
            c = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            q = D_800F7800;
            M2C_FIELD(arg0, u16*, 0x42) = c;
            b = func_8002A47C(M2C_FIELD(q, s8*, 1));
            base = D_1F800020;
            M2C_FIELD(arg0, u8**, 0x3C) = base + ((s32*)base)[b];
            ((void (*)(void*, s32))set_animation)(arg0, 0xF);
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s32*, 0x90) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 3:
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 180) {
            if (M2C_FIELD(arg0, u32*, 0x90) < tbl[D_800CCF5F]) {
                child = func_8002C458();
                if (child != 0) {
                    M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                    M2C_FIELD(child, u8*, 1) = 0x1A;
                    M2C_FIELD(child, u8*, 2) = 0xD;
                    M2C_FIELD(child, void**, 0x7C) = arg0;
                }
                M2C_FIELD(arg0, s32*, 0x90)++;
            }
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
        }
        break;
    case 10:
        if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
            ((void (*)(s32, s32, s32))play_sound)(2, 0x8B, (s32)arg0);
            ((void (*)(void*))func_80049E50)(arg0);
            for (i = 0; i < 6; i++) {
                child = func_8002C458();
                if (child != 0) {
                    M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                    M2C_FIELD(child, u8*, 1) = 0x1A;
                    M2C_FIELD(child, u8*, 2) = i + 5;
                    M2C_FIELD(child, u8*, 7) = M2C_FIELD(arg0, u8*, 2);
                    M2C_FIELD(child, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
                    M2C_FIELD(child, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
                    M2C_FIELD(child, void**, 0x7C) = arg0;
                }
            }
            M2C_FIELD(arg0, u8*, 4)++;
        }
        break;
    case 20:
        if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
            M2C_FIELD(arg0, u8*, 3) = 0;
            M2C_FIELD(arg0, u8*, 4)++;
        } else if (M2C_FIELD(arg0, s16*, 0x88) & 1) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        } else {
            M2C_FIELD(arg0, u8*, 3) = 0;
        }
        break;
    }
    if ((M2C_FIELD(arg0, s8*, 5) != 10) || (M2C_FIELD(arg0, s32*, 0x8C) & 1)) {
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
    }
    ((void (*)(void*))animate_object)(arg0);
}
#undef func_80030ECC
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F77EC;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F1AC0(struct X4_MainObj* arg0) {
    s32 a;
    s32 b;
    u8 bg;

    arg0->animation_table = D_800F7800->animation_table;
    bg = D_800F7800->bg_offset;
    arg0->unk16 = 4;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->bg_offset = bg;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = &D_8007433C;
    arg0->unk15 = D_800F7800->unk15;
    arg0->unk40 = 0x140;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 0x12);
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi - 0x18;
    } else {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi + 0x18;
    }
    arg0->y_pos.i.hi = D_800F7800->y_pos.i.hi - 0xE;
    {
        // !FAKE: depin: dropping it breaks the match (102/111)
        register s32 e asm("$2") = 8;
        // !FAKE: depin: dropping it breaks the match (97/111)
        register s32 f asm("$3") = 4;

        arg0->hp = e;
        arg0->contact_damage = f;
    }
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->ext.raw[3] = 0;
    D_800F77EC += 1;
    arg0->ext.raw[6] = 0;
    arg0->action = 0;
    arg0->state++;
}
#undef D_800F7800

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800F1C7C);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F77EC;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F23C4(struct X4_MainObj* arg0) {
    s32 a;
    s32 b;
    struct X4_MainObj* p;

    p = D_800F7800;
    arg0->animation_table = p->animation_table;
    arg0->bg_offset = p->bg_offset;
    arg0->unk16 = 4;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = &D_8007433C;
    arg0->unk15 = D_800F7800->unk15;
    arg0->unk40 = 0x140;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 0x16);
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi - 0x18;
    } else {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi + 0x18;
    }
    arg0->y_pos.i.hi = D_800F7800->y_pos.i.hi - 0xE;
    arg0->contact_damage = 4;
    arg0->hp = 8;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->ext.raw[3] = 0;
    D_800F77EC += 1;
    D_800F77F0 = 1;
    *(s16*)((u8*)arg0 + 0x8A) = 0;
    arg0->ext.raw[6] = 0;
    arg0->action = 0;
    arg0->state++;
}
#undef D_800F7800

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*, s16);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_8007573C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800970AA;
extern s32 D_800F76A4[];
extern s32 D_800F76A8[];
extern s8 D_800F7806;
#define D_1F800020 (*(u8**)SP(0x20))
#define func_80030ECC (*(void (*)(void*)) & func_80030ECC)

void func_800F2590(void* arg0) {
    void* child;
    void* q;
    s32 i;
    s16 angle;
    s32 a;
    s32 b;
    s32 c;
    u8* base;

    ((void (*)(void*))apply_object_motion)(arg0);
    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    M2C_FIELD(arg0, s8*, 7) = check_enemy_hits(arg0);
    if (M2C_FIELD(arg0, s8*, 7) < 0) {
        D_800F77E8 = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 1;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x8A) = 0;
        M2C_FIELD(arg0, s8*, 5) = 10;
    } else {
        if (M2C_FIELD(arg0, s16*, 0x8A) != 0) {
            if (--M2C_FIELD(arg0, s16*, 0x8A) != 0) {
                // !FAKE: goto skips the reset block from three tests; one ternary test moved bytes
                goto block_skip;
            }
            D_800F77E8 = 0;
        } else {
            M2C_FIELD(arg0, u32*, 0x98) += D_800F7806;
            if (M2C_FIELD(arg0, u32*, 0x98) < 0x10) {
                // !FAKE: goto skips the reset block from three tests; one ternary test moved bytes
                goto block_skip;
            }
            if (M2C_FIELD(arg0, s8*, 5) >= 11) {
                // !FAKE: goto skips the reset block from three tests; one ternary test moved bytes
                goto block_skip;
            }
            D_800F77E8 = 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        M2C_FIELD(arg0, void**, 0x50) = 0;
        M2C_FIELD(arg0, void**, 0x54) = 0;
        M2C_FIELD(arg0, s16*, 0x88) = 0x3C;
        M2C_FIELD(arg0, s8*, 5) = 0x14;
    }
block_skip:
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 12) {
            M2C_FIELD(arg0, void**, 0x50) = D_800F76A4;
            M2C_FIELD(arg0, void**, 0x54) = D_800F76A8;
            if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            {
                s32 px = g_Player.x_pos.i.hi;
                s32 py;
                M2C_FIELD(arg0, s32*, 0x90) = px;
                py = g_Player.y_pos.i.hi;
                M2C_FIELD(arg0, s32*, 0x94) = py;
                angle = ratan2(py - M2C_FIELD(arg0, s16*, 0xE),
                               px - M2C_FIELD(arg0, s16*, 0xA));
            }
            M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) * 48;
            M2C_FIELD(arg0, s32*, 0x24) = -rsin(angle) * 48;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(arg0, u32*, 0x90)) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, u32*, 0x90);
            }
        } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xA) > M2C_FIELD(arg0, u32*, 0x90)) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, u32*, 0x90);
            }
        }
        if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xE) > M2C_FIELD(arg0, u32*, 0x94)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, u32*, 0x94);
            }
        } else if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xE) < M2C_FIELD(arg0, u32*, 0x94)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, u32*, 0x94);
            }
        }
        if ((M2C_FIELD(arg0, s32*, 0x20) == 0) &&
            (M2C_FIELD(arg0, s32*, 0x24) == 0)) {
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(child, u8*, 1) = 0x1A;
                M2C_FIELD(child, u8*, 2) = 0xB;
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
            M2C_FIELD(arg0, s32**, 0x58) = D_8007573C;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s32*, 0x90) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 2:
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 60) {
            {
                void* p = D_800F7800;
                M2C_FIELD(arg0, u16*, 0x40) = 0x140;
                a = func_8002A47C(M2C_FIELD(p, s8*, 1));
            }
            b = func_8002A47C(M2C_FIELD(D_800F7800, s8*, 1));
            c = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            q = D_800F7800;
            M2C_FIELD(arg0, u16*, 0x42) = c;
            b = func_8002A47C(M2C_FIELD(q, s8*, 1));
            base = D_1F800020;
            M2C_FIELD(arg0, u8**, 0x3C) = base + ((s32*)base)[b];
            ((void (*)(void*, s32))set_animation)(arg0, 0x17);
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            D_800F77E8 = 1;
            M2C_FIELD(arg0, s16*, 0x8A) = 0xB4;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 3:
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        break;
    case 10:
        if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
            ((void (*)(s32, s32, s32))play_sound)(2, 0x8B, (s32)arg0);
            ((void (*)(void*))func_80049E50)(arg0);
            for (i = 0; i < 6; i++) {
                child = func_8002C458();
                if (child != 0) {
                    M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                    M2C_FIELD(child, u8*, 1) = 0x1A;
                    M2C_FIELD(child, u8*, 2) = i + 5;
                    M2C_FIELD(child, u8*, 7) = M2C_FIELD(arg0, u8*, 2);
                    M2C_FIELD(child, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
                    M2C_FIELD(child, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
                    M2C_FIELD(child, void**, 0x7C) = arg0;
                }
            }
            M2C_FIELD(arg0, u8*, 4)++;
        }
        break;
    case 20:
        if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
            M2C_FIELD(arg0, u8*, 3) = 0;
            M2C_FIELD(arg0, u8*, 4)++;
        } else if (M2C_FIELD(arg0, s16*, 0x88) & 1) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        } else {
            M2C_FIELD(arg0, u8*, 3) = 0;
        }
        break;
    }
    if (((M2C_FIELD(arg0, s8*, 5) != 10) && (M2C_FIELD(arg0, s8*, 5) != 20)) ||
        (M2C_FIELD(arg0, s32*, 0x8C) & 1)) {
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
    }
    ((void (*)(void*))animate_object)(arg0);
}
#undef func_80030ECC
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F77EC;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F2B5C(struct X4_MainObj* arg0) {
    s32 a;
    s32 b;
    struct X4_MainObj* p;

    p = D_800F7800;
    arg0->animation_table = p->animation_table;
    arg0->bg_offset = p->bg_offset;
    arg0->unk16 = 4;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = &D_8007433C;
    arg0->unk15 = D_800F7800->unk15;
    arg0->unk40 = 0x140;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 0x1A);
    if (arg0->unk15 == 0) {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi - 0x18;
    } else {
        arg0->x_pos.i.hi = D_800F7800->x_pos.i.hi + 0x18;
    }
    arg0->y_pos.i.hi = D_800F7800->y_pos.i.hi - 0xE;
    arg0->contact_damage = 4;
    arg0->hp = 8;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->ext.raw[3] = 0;
    D_800F77EC += 1;
    D_800F77F4 = 1;
    *(s16*)((u8*)arg0 + 0x8A) = 0;
    arg0->action = 0;
    arg0->state++;
}
#undef D_800F7800

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*, s16);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_8007573C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800970AA;
extern s32 D_800F76A4[];
extern s32 D_800F76A8[];
extern s8 D_800F7806;
#define D_1F800020 (*(u8**)SP(0x20))
#define func_80030ECC (*(void (*)(void*)) & func_80030ECC)

void func_800F2D24(void* arg0) {
    void* child;
    void* q;
    s32 i;
    s16 angle;
    s32 a;
    s32 b;
    s32 c;
    u8* base;

    ((void (*)(void*))apply_object_motion)(arg0);
    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    M2C_FIELD(arg0, s8*, 7) = check_enemy_hits(arg0);
    if (M2C_FIELD(arg0, s8*, 7) < 0) {
        M2C_FIELD(arg0, s32*, 0x8C) = 1;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s16*, 0x8A) = 0;
        M2C_FIELD(arg0, s8*, 5) = 10;
    } else {
        if (M2C_FIELD(arg0, s16*, 0x8A) != 0) {
            if (--M2C_FIELD(arg0, s16*, 0x8A) != 0) {
                // !FAKE: goto skips the reset block from three tests; one ternary test moved bytes
                goto block_skip;
            }
        } else {
            M2C_FIELD(arg0, u32*, 0x98) += D_800F7806;
            if (M2C_FIELD(arg0, u32*, 0x98) < 0x10) {
                // !FAKE: goto skips the reset block from three tests; one ternary test moved bytes
                goto block_skip;
            }
            if (M2C_FIELD(arg0, s8*, 5) >= 11) {
                // !FAKE: goto skips the reset block from three tests; one ternary test moved bytes
                goto block_skip;
            }
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        M2C_FIELD(arg0, void**, 0x50) = 0;
        M2C_FIELD(arg0, void**, 0x54) = 0;
        M2C_FIELD(arg0, s16*, 0x88) = 0x3C;
        M2C_FIELD(arg0, s8*, 5) = 0x14;
    }
block_skip:
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 12) {
            M2C_FIELD(arg0, void**, 0x50) = D_800F76A4;
            M2C_FIELD(arg0, void**, 0x54) = D_800F76A8;
            if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            {
                s32 px = g_Player.x_pos.i.hi;
                s32 py;
                M2C_FIELD(arg0, s32*, 0x90) = px;
                py = g_Player.y_pos.i.hi;
                M2C_FIELD(arg0, s32*, 0x94) = py;
                angle = ratan2(py - M2C_FIELD(arg0, s16*, 0xE),
                               px - M2C_FIELD(arg0, s16*, 0xA));
            }
            M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) * 48;
            M2C_FIELD(arg0, s32*, 0x24) = -rsin(angle) * 48;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(arg0, u32*, 0x90)) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, u32*, 0x90);
            }
        } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xA) > M2C_FIELD(arg0, u32*, 0x90)) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(arg0, u32*, 0x90);
            }
        }
        if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xE) > M2C_FIELD(arg0, u32*, 0x94)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, u32*, 0x94);
            }
        } else if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
            if ((u32)M2C_FIELD(arg0, s16*, 0xE) < M2C_FIELD(arg0, u32*, 0x94)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(arg0, u32*, 0x94);
            }
        }
        if ((M2C_FIELD(arg0, s32*, 0x20) == 0) &&
            (M2C_FIELD(arg0, s32*, 0x24) == 0)) {
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(child, u8*, 1) = 0x1A;
                M2C_FIELD(child, u8*, 2) = 0xB;
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
            M2C_FIELD(arg0, s32**, 0x58) = D_8007573C;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s32*, 0x90) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 2:
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 60) {
            {
                void* p = D_800F7800;
                M2C_FIELD(arg0, u16*, 0x40) = 0x140;
                a = func_8002A47C(M2C_FIELD(p, s8*, 1));
            }
            b = func_8002A47C(M2C_FIELD(D_800F7800, s8*, 1));
            c = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            q = D_800F7800;
            M2C_FIELD(arg0, u16*, 0x42) = c;
            b = func_8002A47C(M2C_FIELD(q, s8*, 1));
            base = D_1F800020;
            M2C_FIELD(arg0, u8**, 0x3C) = base + ((s32*)base)[b];
            ((void (*)(void*, s32))set_animation)(arg0, 0x1B);
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s16*, 0x8A) = 0xB4;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 3:
        if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        if (g_Player.hp != 0) {
            if (g_Player.x_pos.val > M2C_FIELD(arg0, s32*, 8)) {
                g_Player.x_pos.val -= 0xC000;
                if (g_Player.x_pos.val < M2C_FIELD(arg0, s32*, 8)) {
                    g_Player.x_pos.val = M2C_FIELD(arg0, s32*, 8);
                }
            } else if (g_Player.x_pos.val < M2C_FIELD(arg0, s32*, 8)) {
                g_Player.x_pos.val += 0xC000;
                if (M2C_FIELD(arg0, s32*, 8) < g_Player.x_pos.val) {
                    g_Player.x_pos.val = M2C_FIELD(arg0, s32*, 8);
                }
            }
        }
        break;
    case 10:
        if (--M2C_FIELD(arg0, s32*, 0x8C) == 0) {
            ((void (*)(s32, s32, s32))play_sound)(2, 0x8B, (s32)arg0);
            ((void (*)(void*))func_80049E50)(arg0);
            for (i = 0; i < 6; i++) {
                child = func_8002C458();
                if (child != 0) {
                    M2C_FIELD(child, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
                    M2C_FIELD(child, u8*, 1) = 0x1A;
                    M2C_FIELD(child, u8*, 2) = i + 5;
                    M2C_FIELD(child, u8*, 7) = M2C_FIELD(arg0, u8*, 2);
                    M2C_FIELD(child, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
                    M2C_FIELD(child, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
                    M2C_FIELD(child, void**, 0x7C) = arg0;
                }
            }
            M2C_FIELD(arg0, u8*, 4)++;
        }
        break;
    case 20:
        if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
            M2C_FIELD(arg0, u8*, 3) = 0;
            M2C_FIELD(arg0, u8*, 4)++;
        } else if (M2C_FIELD(arg0, s16*, 0x88) & 1) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        } else {
            M2C_FIELD(arg0, u8*, 3) = 0;
        }
        break;
    }
    if (((M2C_FIELD(arg0, s8*, 5) != 10) && (M2C_FIELD(arg0, s8*, 5) != 20)) ||
        (M2C_FIELD(arg0, s32*, 0x8C) & 1)) {
        ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
    }
    ((void (*)(void*))animate_object)(arg0);
}
#undef func_80030ECC
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800F3348);
// clang-format on

#include "common.h"
#include "mmx6/rock_24.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);                  /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */
M2C_UNK func_80030ECC(void*, s16);              /* extern */
s32 check_enemy_hits(void*);                    /* extern */
M2C_UNK func_80049E50(void*);                   /* extern */

void func_800F3660(void* arg0) {
    s16 temp_a0;
    s16 temp_a0_2;
    s16 var_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s8 temp_v1;
    u32 temp_v0_3;
    u32 temp_v0_4;

    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (((u32)M2C_FIELD(arg0, u32*, 0x8C) >= 5U) &&
        (check_enemy_hits(arg0) < 0)) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    temp_a0 = M2C_FIELD(arg0, s16*, 0xA);
    var_a1 = M2C_FIELD(D_800F7800, s16*, 0xA);
    temp_v0 = var_a1 - temp_a0;
    if (temp_v0 >= 0) {
        if (temp_v0 >= 0x18) {

        } else {
            // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
            goto block_10;
        }
    } else if ((temp_a0 - var_a1) < 0x18) {
    block_10:
        temp_a0_2 = M2C_FIELD(arg0, s16*, 0xE);
        var_a1 = M2C_FIELD(D_800F7800, s16*, 0xE);
        temp_v0_2 = var_a1 - temp_a0_2;
        if (temp_v0_2 >= 0) {
            if (temp_v0_2 >= 0x20) {

            } else {
                // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
                goto block_14;
            }
        } else if ((temp_a0_2 - var_a1) < 0x20) {
        block_14:
            if (M2C_FIELD(D_800F7800, s8*, 5) != 7) {
                D_800F77DC = 1;
                M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
            }
        }
    }
    func_80030ECC(arg0, var_a1);
    temp_v1 = M2C_FIELD(arg0, s8*, 5);
    switch (temp_v1) { /* irregular */
    case 0:
        temp_v0_3 = M2C_FIELD(arg0, u32*, 0x8C) + 1;
        M2C_FIELD(arg0, u32*, 0x8C) = temp_v0_3;
        if (temp_v0_3 == 0x3C) {
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        }
        break;
    case 1:
        temp_v0_4 = M2C_FIELD(arg0, u32*, 0x8C) + 1;
        M2C_FIELD(arg0, u32*, 0x8C) = temp_v0_4;
        if (temp_v0_4 == 0x50) {
            M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        }
        break;
    }
    if ((M2C_FIELD(arg0, s8*, 5) != 1) || (M2C_FIELD(arg0, u32*, 0x8C) & 1)) {
        func_8002CCB0(arg0, 0x20, 0x20);
    }
    animate_object(arg0);
    apply_object_motion(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F3854(struct X4_MainObj* arg0) {
    struct X4_MainObj* p;
    s32 a;
    s32 b;

    p = *(struct X4_MainObj**)((u8*)arg0 + 0x7C);
    arg0->unk15 = p->unk15;
    arg0->x_pos.i.hi = p->x_pos.i.hi;
    arg0->y_pos.i.hi = p->y_pos.i.hi;
    if (p->state == 2) {
        arg0->state++;
        return;
    }
    switch (arg0->action) {
    case 0:
        if (p->unk7 > 0) {
            arg0->unk40 = 0x140;
            a = func_8002A47C(D_800F7800->id);
            b = func_8002A47C(D_800F7800->id);
            arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            arg0->sprite_frames =
                (const u8*)(SPAD20 + *(s32*)(func_8002A47C(D_800F7800->id) * 4 +
                                             SPAD20));
            ((void (*)(void*, s32))set_animation)(arg0, 0x1E);
            func_8002CCB0(arg0, 0x20, 0x20);
            animate_object(arg0);
            {
                // !FAKE: depin: dropping it breaks the match (107/110)
                register s32 t asm("$2") = (u8)arg0->action + 1;

                arg0->action = t;
            }
        }
        break;
    case 1:
        if (arg0->animation_step.fields.relative_step == 0) {
            arg0->action--;
        }
        func_8002CCB0(arg0, 0x20, 0x20);
        animate_object(arg0);
        break;
    }
    apply_object_motion(arg0);
}
#undef D_800F7800

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_8007573C[];
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern M2C_UNK D_800F76B8;
extern M2C_UNK D_800F76BC;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F3A0C(struct X4_MainObj* arg0) {
    struct X4_MainObj* p;
    struct X4_MainObj* q;
    u8 bg;
    s32 a;
    s32 b;
    s16 angle;

    p = D_800F7800;
    arg0->animation_table = p->animation_table;
    bg = p->bg_offset;
    {
        s32 k = 3;

        arg0->unk16 = k;
    }
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->attack_box = &D_800F76B8;
    arg0->hurt_box = &D_800F76BC;
    arg0->collision_data = D_8007573C;
    arg0->bg_offset = bg;
    arg0->terrain_box = 0;
    arg0->unk40 = 0x140;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20));
    ((void (*)(void*, s32))set_animation)(arg0, 0xD);
    q = *(struct X4_MainObj**)((u8*)arg0 + 0x7C);
    arg0->x_pos.i.hi = q->x_pos.i.hi;
    arg0->y_pos.i.hi = q->y_pos.i.hi;
    angle = ratan2(g_Player.y_pos.i.hi - arg0->y_pos.i.hi,
                   g_Player.x_pos.i.hi - arg0->x_pos.i.hi);
    arg0->x_speed = rcos(angle) << 6;
    arg0->y_speed = -rsin(angle) << 6;
    if (arg0->x_speed < 0) {
        arg0->unk15 = 0;
    } else {
        arg0->unk15 = 0x40;
    }
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->hp = 1;
    arg0->contact_damage = 4;
    arg0->ext.raw[3] = 0;
    ((void (*)(s32, s32, void*))play_sound)(2, 0x8C, arg0);
    arg0->action = 0;
    {
        // !FAKE: depin: dropping it breaks the match (121/124)
        register s32 t asm("$3") = (u8)arg0->state + 1;

        arg0->state = t;
    }
}
#undef D_800F7800
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_8007573C[];
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F3BFC(struct X4_MainObj* arg0) {
    struct X4_MainObj* p;
    struct X4_MainObj* q;
    u8 bg;
    s32 a;
    s32 b;

    p = D_800F7800;
    arg0->animation_table = p->animation_table;
    bg = p->bg_offset;
    arg0->unk16 = 3;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->collision_data = D_8007573C;
    arg0->bg_offset = bg;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->unk40 = 0x540;
    a = func_8002A47C(D_800F7800->id);
    b = func_8002A47C(D_800F7800->id);
    arg0->unk42 = (((a + 1) * 4 + 0x20) % 16) | (((b + 9) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 + SPAD20 + 4));
    ((void (*)(void*, s32))set_animation)(arg0, 0x1F);
    q = *(struct X4_MainObj**)((u8*)arg0 + 0x7C);
    arg0->unk15 = q->unk15;
    arg0->x_pos.i.hi = q->x_pos.i.hi;
    arg0->y_pos.i.hi = q->y_pos.i.hi - 0xC;
    arg0->hp = 2;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->contact_damage = 4;
    arg0->ext.raw[3] = 0;
    arg0->action = 0;
    arg0->state++;
}
#undef D_800F7800

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object(void*);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*, s16);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_800970AA;
extern s32 D_800F76C0[];
extern s32 D_800F76C4[];
#define D_1F800020 (*(u8**)SP(0x20))

void func_800F3D74(void* arg0) {
    s32 a;
    s32 b;
    // !FAKE: depin: dropping it breaks the match (189/194)
    register s32 t asm("$3");
    u8* base;
    u8 st;
    s32 c;
    void* q;

    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    if ((check_enemy_hits(arg0) < 0) ||
        (((s32(*)(void*))func_80030ECC)(arg0) != 0)) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x1E) {
            {
                void* p = D_800F7800;
                M2C_FIELD(arg0, u16*, 0x40) = 0x540;
                a = func_8002A47C(M2C_FIELD(p, s8*, 1));
            }
            b = func_8002A47C(M2C_FIELD(D_800F7800, s8*, 1));
            c = (((a + 1) * 4 + 0x20) % 16) | (((b + 9) / 4 + 0x1E0) << 6);
            q = D_800F7800;
            M2C_FIELD(arg0, u16*, 0x42) = c;
            b = func_8002A47C(M2C_FIELD(q, s8*, 1));
            base = D_1F800020;
            M2C_FIELD(arg0, u8**, 0x3C) = base + ((s32*)base)[b + 1];
            set_animation(arg0, 0x20);
            {
                // !FAKE: depin: dropping it breaks the match (190/194)
                register void* t0 asm("$2") = D_800F76C0;
                // !FAKE: depin: dropping it breaks the match (188/194)
                register void* t1 asm("$3") = D_800F76C4;
                M2C_FIELD(arg0, void**, 0x50) = t0;
                M2C_FIELD(arg0, void**, 0x54) = t1;
            }
            if (M2C_FIELD(arg0, s16*, 0xA) < D_800970AA) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
                M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
            }
            M2C_FIELD(arg0, s8*, 6) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s16*, 0xE) < g_Player.y_pos.i.hi) {
            M2C_FIELD(arg0, s16*, 0xE)++;
        } else if (g_Player.y_pos.i.hi < M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE)--;
        }
        st = M2C_FIELD(arg0, u8*, 6);
        switch (M2C_FIELD(arg0, s8*, 6)) {
        case 0:
            if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
                t = M2C_FIELD(arg0, s16*, 0xA);
                t = t < g_Player.x_pos.i.hi;
            } else {
                t = M2C_FIELD(arg0, s16*, 0xA) > g_Player.x_pos.i.hi;
            }
            if (t != 0) {
                M2C_FIELD(arg0, s32*, 0x8C) = 0;
                M2C_FIELD(arg0, u8*, 6) = st + 1;
            }
            break;
        case 1:
            if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x1E) {
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    M2C_FIELD(arg0, u8*, 0x15) = 0;
                } else {
                    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                }
                M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
                M2C_FIELD(arg0, u8*, 6)--;
            }
            break;
        }
        break;
    }
    if ((M2C_FIELD(arg0, s8*, 5) > 0) || (M2C_FIELD(arg0, s32*, 0x8C) & 1)) {
        func_8002CCB0(arg0, 0x40, 0x40);
    }
    animate_object(arg0);
    apply_object_motion(arg0);
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_8007573C[];
#define D_1F800020 (*(u8**)SP(0x20))

void func_800F407C(void* arg0) {
    s32 a;
    s32 b;
    u8* base;
    u8 st;
    s32 c;
    void* q;

    {
        void* p = D_800F7800;
        u8 sb;
        M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
        sb = M2C_FIELD(p, u8*, 0x14);
        M2C_FIELD(arg0, u8*, 0x16) = 2;
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, s32**, 0x58) = D_8007573C;
        M2C_FIELD(arg0, u8*, 0x14) = sb;
    }
    {
        void* p = D_800F7800;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, u16*, 0x40) = 0x140;
        a = func_8002A47C(M2C_FIELD(p, s8*, 1));
    }
    b = func_8002A47C(M2C_FIELD(D_800F7800, s8*, 1));
    c = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    q = D_800F7800;
    M2C_FIELD(arg0, u16*, 0x42) = c;
    b = func_8002A47C(M2C_FIELD(q, s8*, 1));
    base = D_1F800020;
    M2C_FIELD(arg0, u8**, 0x3C) = base + ((s32*)base)[b];
    set_animation(arg0, 5);
    st = M2C_FIELD(D_800F7800, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x15) = st;
    if (st == 0) {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(D_800F7800, u16*, 0xA) - 0x28;
    } else {
        M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(D_800F7800, u16*, 0xA) + 0x28;
    }
    M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(D_800F7800, u16*, 0xE);
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    play_sound(2, 0x8D, arg0);
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 4)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK animate_object(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC (*(void (*)(void*)) & func_80030ECC)
extern s32 D_800F76C8;
extern s16 D_800F77F8;
extern s16 D_800F77FA;
extern s16 D_800F77FC;

void func_800F4240(void* arg0) {
    if ((D_800F77D8 != 0) || (D_800F77DC != 0)) {
        D_800F77F8 = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (M2C_FIELD(arg0, s32*, 0x8C) == 5) {
            start_pad_vibration(3);
        }
        if (M2C_FIELD(arg0, s32*, 0x8C) == 0xA) {
            D_800F77F8 = 1;
            D_800F77FA = ((struct X4_ObjectHeader*)arg0)->x_pos.u.hi;
            D_800F77FC = ((struct X4_ObjectHeader*)arg0)->y_pos.u.hi;
            M2C_FIELD(arg0, s32**, 0x50) = &D_800F76C8;
            M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s32*, 0x8C) == 0x34) {
            D_800F77F8 = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s8*, 5) = (s8)((u8)M2C_FIELD(arg0, s8*, 5) + 1);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        }
        break;
    }
    M2C_FIELD(arg0, s32*, 0x8C) = M2C_FIELD(arg0, s32*, 0x8C) + 1;
    func_8002CCB0(arg0, 0x20, 0xC0);
    animate_object(arg0);
    apply_object_motion(arg0);
}
#undef func_80030ECC

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#define SPAD20_800F43B8 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
void func_80027BA0(s32, s32, s32, void*);
s32 func_8002A47C(s32);
extern u8 D_800F7518[];
extern u16 D_800F7768[];
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F43B8(struct X4_MainObj* arg0) {
    s32 i;

    {
        struct X4_MainObj* p = D_800F7800;
        s32 b;
        arg0->animation_table = p->animation_table;
        b = (u8)p->bg_offset;
        arg0->unk16 = 6;
        arg0->air_state = 0;
        arg0->on_screen = 0;
        arg0->unk15 = 0;
        arg0->bg_offset = b;
    }
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = 0;
    arg0->unk40 = 0x540;
    arg0->unk42 = (((func_8002A47C(D_800F7800->id) + 1) * 4 + 0x20) % 16) |
                  (((func_8002A47C(D_800F7800->id) + 9) / 4 + 0x1E0) << 6);
    arg0->sprite_frames =
        (const u8*)(SPAD20_800F43B8 +
                    *(s32*)(func_8002A47C(D_800F7800->id) * 4 +
                            SPAD20_800F43B8 + 4));
    set_animation(arg0, 0x21);
    i = arg0->unk2 - 0xF;
    arg0->x_pos.u.hi = D_800F7768[i * 2];
    arg0->y_pos.u.hi = D_800F7768[i * 2 + 1];
    func_80027BA0(0, (s16)arg0->x_pos.u.hi - 0x10, (s16)arg0->y_pos.u.hi - 0x18,
                  D_800F7518 + arg0->unk2 * 8);
    {
        // !FAKE: depin: dropping it breaks the match (103/106)
        register u8 s asm("$3") = arg0->state;
        arg0->x_speed = 0;
        arg0->y_speed = 0;
        arg0->x_accel = 0;
        arg0->gravity = 0;
        arg0->hp = 0;
        arg0->contact_damage = 0;
        arg0->ext.raw[3] = 0;
        arg0->action = 0;
        arg0->state = s + 1;
    }
}

#undef D_800F7800
#undef SPAD20_800F43B8

#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK animate_object(void*);
void func_80027BA0(s32, s32, s32, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80049E50(void*);
extern s8 D_80097244;
extern u8 D_800F7518[];
extern u8 D_800F7548[];
extern s16 D_800F77F8;
extern s16 D_800F77FA;
extern s16 D_800F77FC;

void func_800F4560(void* arg0) {
    s32 d;

    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (D_800F77F8 != 0) {
            d = D_800F77FA - M2C_FIELD(arg0, s16*, 0xA);
            if (d >= 0) {
                if (d < 0x18) {
                    // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
                    goto near_x;
                }
            } else if ((M2C_FIELD(arg0, s16*, 0xA) - D_800F77FA) < 0x18) {
            near_x:
                d = D_800F77FC - M2C_FIELD(arg0, s16*, 0xE);
                if (d >= 0) {
                    if (d < 0x60) {
                        // !FAKE: range test needs per-sign compares jumping to one shared block (C0144); abs() form folds to a negate
                        goto near_y;
                    }
                } else if ((M2C_FIELD(arg0, s16*, 0xE) - D_800F77FC) < 0x60) {
                near_y:
                    func_80049E50(arg0);
                    M2C_FIELD(arg0, s32*, 0x8C) = 0;
                    M2C_FIELD(arg0, s8*, 5)++;
                }
            }
        }
    draw:
        func_8002CCB0(arg0, 0x40, 0x20);
        break;
    case 1:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x14) {
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            ((s32(*)(s32, s32, s32, void*))func_80027BA0)(
                0, M2C_FIELD(arg0, s16*, 0xA) - 0x10,
                M2C_FIELD(arg0, s16*, 0xE) - 0x18,
                D_800F7548 + M2C_FIELD(arg0, s8*, 2) * 8);
            D_80097244 = 1;
            M2C_FIELD(arg0, s8*, 5)++;
        }
        if (M2C_FIELD(arg0, s32*, 0x8C) & 1) {
            func_8002CCB0(arg0, 0x40, 0x20);
        }
        break;
    case 2:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0xB4) {
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s8*, 5)++;
        }
        break;
    case 3:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x3C) {
            ((s32(*)(s32, s32, s32, void*))func_80027BA0)(
                0, M2C_FIELD(arg0, s16*, 0xA) - 0x10,
                M2C_FIELD(arg0, s16*, 0xE) - 0x18,
                D_800F7518 + M2C_FIELD(arg0, s8*, 2) * 8);
            D_80097244 = 1;
            M2C_FIELD(arg0, s8*, 5) = 0;
        }
        if (M2C_FIELD(arg0, s32*, 0x8C) & 1) {
            func_8002CCB0(arg0, 0x40, 0x20);
        }
        break;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/rock_24.h"

#define SPAD20_800F4790 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800F7780[];
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F4790(struct X4_MainObj* arg0) {
    u16 y;
    s32 xv;
    u8 s;

    arg0->animation_table = D_800F7800->animation_table;
    arg0->bg_offset = D_800F7800->bg_offset;
    arg0->unk16 = 2;
    arg0->air_state = 0;
    arg0->on_screen = 0;
    arg0->terrain_box = 0;
    arg0->attack_box = 0;
    arg0->hurt_box = 0;
    arg0->collision_data = 0;
    if (D_800F7780[arg0->unk2 - 0x1E] < 0x1F) {
        arg0->unk40 = 0x140;
        arg0->unk42 = ((func_8002A47C(D_800F7800->id) * 4 + 0x20) % 16) |
                      (((func_8002A47C(D_800F7800->id) + 8) / 4 + 0x1E0) << 6);
        arg0->sprite_frames =
            (const u8*)(SPAD20_800F4790 +
                        *(s32*)(func_8002A47C(D_800F7800->id) * 4 +
                                SPAD20_800F4790));
    } else {
        arg0->unk40 = 0x540;
        arg0->unk42 = (((func_8002A47C(D_800F7800->id) + 1) * 4 + 0x20) % 16) |
                      (((func_8002A47C(D_800F7800->id) + 9) / 4 + 0x1E0) << 6);
        arg0->sprite_frames =
            (const u8*)(SPAD20_800F4790 +
                        *(s32*)(func_8002A47C(D_800F7800->id) * 4 +
                                SPAD20_800F4790 + 4));
    }
    set_animation(arg0, D_800F7780[arg0->unk2 - 0x1E]);
    do {
        // !FAKE: depin: dropping it breaks the match (144/152)
        register u8 c asm("$2") = D_800F7800->unk15;
        arg0->unk15 = c;
        xv = D_800F7800->x_pos.u.hi;
    } while (0);
    *(u16*)((u8*)arg0 + 0xA) = xv;
    s = arg0->state;
    y = D_800F7800->y_pos.u.hi;
    arg0->x_speed = 0;
    arg0->y_speed = 0;
    arg0->x_accel = 0;
    arg0->gravity = 0;
    arg0->hp = 0;
    arg0->contact_damage = 0;
    arg0->ext.raw[3] = 0;
    arg0->state = s + 1;
    arg0->action = 0;
    arg0->y_pos.u.hi = y;
}

#undef D_800F7800
#undef SPAD20_800F4790
