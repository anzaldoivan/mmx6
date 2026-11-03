#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK func_8003CDF0();
void func_8003F000(void* arg0);
M2C_UNK refresh_weapon_state(void*);

void func_800E9B40(void* arg0) {
    s8 state = M2C_FIELD(arg0, s8*, 6);

    if (state == 0) {
        player_set_animation(arg0, 0x51);
        func_8003CDF0(arg0);
        refresh_weapon_state(arg0);
        func_8003F000(arg0);
        // !FAKE: shared counter increment block
        goto inc;
    }
    if (state == 1) {
        ((void (*)())animate_object)(arg0);
        if (D_800CCEDF != 0) {
        inc:
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    } else {
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 5) = 0;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800E9BDC);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800E9D70);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800E9F18);
// clang-format on

#define func_800EB924 func_800EA0B0
#include "../shared/rock_02/func_800EB924.c"
#undef func_800EB924

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EA218);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EA3B0);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EA424(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA444(void) {
    func_8002CA54();
}

#define func_800EBCD8 func_800EA464
#define D_8009719C D_8009719C
#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK animate_object();
extern s32 D_8009719C;

void func_800EA464(void* arg0) {
    s32 temp_v0;
    s32 var_v0;

    M2C_FIELD(arg0, s32*, 0x8) += M2C_FIELD(arg0, s32*, 0x20);
    M2C_FIELD(arg0, s32*, 0xC) =
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg0, s32*, 0x24);
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) += M2C_FIELD(arg0, s32*, 0x28);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) -= M2C_FIELD(arg0, s32*, 0x28);
    }
    temp_v0 = M2C_FIELD(arg0, s32*, 0x24) - M2C_FIELD(arg0, s32*, 0x2C);
    M2C_FIELD(arg0, s32*, 0x24) = temp_v0;
    if (temp_v0 < D_8009719C) {
        M2C_FIELD(arg0, s32*, 0x24) = D_8009719C;
    }
    animate_object(arg0);
    var_v0 = M2C_FIELD(arg0, s8*, 7);
    if (var_v0 == 0) {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 1;
    } else {
        var_v0 = M2C_FIELD(arg0, u8*, 0x70) & 2;
    }
    if (var_v0 != 0) {
        play_sound(2, 4, arg0);
        M2C_FIELD(arg0, s16*, 0x8) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
#undef func_800EBCD8
#undef D_8009719C

#define func_800EBDC8 func_800EA554
#define D_8009719C D_8009719C
#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK animate_object();
extern s32 D_8009719C;

void func_800EA554(void* arg0) {
    s32 temp_v0;
    // !FAKE: inherited from src/shared/rock_02/func_800EBDC8.c
    register s32 flag asm("$2");

    animate_object();
    flag = M2C_FIELD(arg0, u8*, 0x70) & 8;
    if (flag != 0) {
        play_sound(2, 4, arg0);
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = -0xC00;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        return;
    }
    M2C_FIELD(arg0, s32*, 0x8) += M2C_FIELD(arg0, s32*, 0x20);
    M2C_FIELD(arg0, s32*, 0xC) =
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg0, s32*, 0x24);
    if (M2C_FIELD(arg0, s8*, 7) != 0) {
        M2C_FIELD(arg0, s32*, 0x20) =
            M2C_FIELD(arg0, s32*, 0x20) + M2C_FIELD(arg0, s32*, 0x28);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) =
            M2C_FIELD(arg0, s32*, 0x20) - M2C_FIELD(arg0, s32*, 0x28);
    }
    temp_v0 = M2C_FIELD(arg0, s32*, 0x24) - M2C_FIELD(arg0, s32*, 0x2C);
    M2C_FIELD(arg0, s32*, 0x24) = temp_v0;
    if (temp_v0 < D_8009719C) {
        M2C_FIELD(arg0, s32*, 0x24) = D_8009719C;
    }
}
#undef func_800EBDC8
#undef D_8009719C

#define func_8003744C func_800EA62C
#define D_80073C1C D_800F666C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA668(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800EBEF4 func_800EA680
#include "../shared/rock_02/func_800EBEF4.c"
#undef func_800EBEF4

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA6B4(void* arg0) {
    if ((M2C_FIELD(arg0, s8*, 0x67) == 0) &&
        !(M2C_FIELD(arg0, u8*, 0x70) & 8)) {
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = -1;
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EA0B0(void*, void*); /* extern */

void func_800EA6F4(void* arg0) {
    u32 var_s0;

    var_s0 = arg0 + 0x9C;
    if (var_s0 < (u32)&D_80090C88) {
        do {
            if ((M2C_FIELD(var_s0, s8*, 0) != 0) &&
                (M2C_FIELD(arg0, s8*, 1) == M2C_FIELD(var_s0, s8*, 1))) {
                func_800EA0B0((void*)var_s0, arg0);
            }
            var_s0 += 0x9C;
        } while (var_s0 < (u32)&D_80090C88);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EA218(); /* extern */
M2C_UNK func_800EA7D0(); /* extern */
M2C_UNK func_800EA810(); /* extern */

void func_800EA778(void* arg0) {
    s8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 4);
    if (temp_v1 == 0) {
        func_800EA7D0();
        return;
    }
    if (temp_v1 == 1) {
        func_800EA218();
        return;
    }
    func_800EA810();
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EA7D0);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EA810);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define F(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))
#define SPAD_4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
void func_800EB76C(void*, s32);
void func_800EB8B8(void*);

extern s32 D_800F669C;
extern s32 D_800F66A0;
extern s32 D_800F6728;

void func_800EA8A8(void* self) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 byte;

    F(self, u8, 0x60) = 4;
    F(self, u8, 0x5C) = 4;
    F(self, u8, 0x61) = 0;
    F(self, u8, 0x3) = 0;
    F(self, void*, 0x30) = &D_800F6728;
    byte = D_800970B4;
    F(self, u8, 0x16) = 7;
    d = F(self, s32, 0x8);
    c = F(self, s32, 0xC);
    F(self, u8, 0x67) = 0;
    F(self, void*, 0x58) = &D_800743DC;
    F(self, s32, 0x20) = 0;
    F(self, s32, 0x24) = 0;
    F(self, s32, 0x28) = 0;
    F(self, s32, 0x2C) = 0;
    F(self, u8, 0x15) = 0;
    F(self, u8, 0x14) = byte;
    F(self, s32, 0x18) = d;
    F(self, s32, 0x1C) = c;
    ((void (*)(void*, s32, s32, u8))set_animation)(self, 0, c, byte);
    F(self, u8, 0x3) = 0;
    F(self, s32, 0x68) = 0;
    F(self, void*, 0x50) = &D_800F669C;
    F(self, void*, 0x54) = &D_800F66A0;
    if (F(self, s8, 0x2) == 0) {
        func_800EB8B8(self);
        SPAD_4C[0x88] = 0;
        if (F(self, u8, 0x15) == 0) {
            F(self, s16, 0xA) += 0x20;
        } else {
            F(self, s16, 0xA) -= 0x20;
        }
        func_800EB76C(self, 0x10);
        func_800EB76C(self, 0x11);
        func_800EB76C(self, 0x12);
        func_800EB76C(self, 0x13);
        if (D_800CCF38 >= 2) {
            F(self, u8, 0x5) = 6;
        } else {
            F(self, u8, 0x5) = 2;
        }
    } else {
        F(self, u8, 0x5) = 3;
        a = func_8002A47C(F(self, s8, 0x1));
        b = func_8002A47C(F(self, s8, 0x1));
        F(self, s16, 0x42) =
            ((a * 4 + 0x21) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    }
    func_800EB8B8(self);
    F(self, u8, 0x4) = 1;
    F(self, u8, 0x6) = 0;
}

#undef SPAD_4C
#undef F

#define func_800E9D68 func_800EAA7C
#include "../shared/rock_11/func_800E9D68.c"
#undef func_800E9D68

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EAC3C);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EAF34);
// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK g_Player;
extern s32 D_800F679C;
extern s32 D_800F67A0;

void func_800EB064(void* arg0) {
    s32 angle;
    s32 t;
    s32 v;
    s32 px;
    s32 py;

    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32**, 0x58) = &D_8007429C;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    set_animation(arg0, 3);
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32**, 0x50) = &D_800F679C;
    M2C_FIELD(arg0, s32**, 0x54) = &D_800F67A0;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    px = ((struct X4_PlayerObj*)&g_Player)->x_pos.i.hi;
    py = ((struct X4_PlayerObj*)&g_Player)->y_pos.i.hi;
    angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                   px - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    t = rcos(angle);
    v = t * 16;
    M2C_FIELD(arg0, s32*, 0x20) = (t * 64 + v) >> 1;
    t = rsin(angle);
    v = t * 16;
    M2C_FIELD(arg0, s32*, 0x24) = (t * 64 + v) >> 1;
    play_sound(2, 0x3B, arg0);
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
    } else {
        M2C_FIELD(arg0, u8*, 4)++;
    }
}

#define func_80041AB8 func_800EB19C
#define D_80075FD8 D_800F6748
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EB1D8
#define D_80075FD8 D_800F67A4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((M2C_UNK(*)(void*))func_80030ECC)
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern M2C_UNK D_800F6744;
extern void (*D_800F675C[])(s8*);

void func_800EB214(s8* arg0) {
    ((s32*)arg0)[6] = ((s32*)arg0)[2];
    ((s32*)arg0)[7] = ((s32*)arg0)[3];
    animate_object();
    D_800F675C[arg0[5]](arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_800477E4(3, &D_800F6744, arg0);
        func_80049E50(arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x12);
        if (arg0[2] != 0) {
            arg0[4] = 4;
        } else {
            arg0[4] = 2;
        }
        return;
    }
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0xA0, 0xA0) == 0) {
        func_8002CCB0(arg0, 0x30, 0x30);
        return;
    }
    if (arg0[2] != 0) {
        arg0[4] = 4;
    } else {
        arg0[4] = 3;
    }
}
#undef func_80030ECC

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EB304(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EB324(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB344(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EB364);
// clang-format on

#define func_800EA71C func_800EB430
#include "../shared/rock_11/func_800EA71C.c"
#undef func_800EA71C

#include "common.h"

void func_800EB464(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EB46C);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EB504(void) {
    move_object();
}

#define func_8003744C func_800EB524
#define D_80073C1C D_800F6788
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EB560);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EB638(void) {
    move_object();
}

#define func_800EA944 func_800EB658
#include "../shared/rock_11/func_800EA944.c"
#undef func_800EA944

#define func_800EA980 func_800EB694
#include "../shared/rock_11/func_800EA980.c"
#undef func_800EA980

#define func_800EA9B4 func_800EB6C8
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EB6C8(void* arg0) {
    s32 d = g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE);

    if (d >= 0) {
        if (d < 2) {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
        } else {
            // !FAKE: inherited from src/shared/rock_11/func_800EA9B4.c
            goto far;
        }
    } else if (M2C_FIELD(arg0, s16*, 0xE) - g_Player.y_pos.i.hi >= 2) {
    far:
        if (g_Player.y_pos.i.hi >= M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s32*, 0x24) = -0x18000;
        } else {
            M2C_FIELD(arg0, s32*, 0x24) = 0x18000;
        }
    } else {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 10;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
#undef g_Player
#undef func_800EA9B4
#undef g_Player

#include "common.h"

void func_800EB764(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EB76C);
// clang-format on

#define func_800EAB04 func_800EB818
#include "../shared/rock_11/func_800EAB04.c"
#undef func_800EAB04

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EB8B8);
// clang-format on

#define func_800EABD4 func_800EB8E8
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((M2C_UNK(*)(void*))func_80030ECC)
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

void func_800EB8E8(struct X4_BaseObj* self) {
    animate_object();
    move_object(self);
    if (check_enemy_hits(self) < 0) {
        ((void (*)(void*))func_80049E50)(self);
        self->state++;
    } else {
        M2C_FIELD(self, u16*, 0x42) &= 0x7FFF;
    }
    func_80030ECC(self);
    if (is_off_screen(self, 0x20, 0x20) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
        return;
    }
    self->state++;
}
#undef func_80030ECC
#undef func_800EABD4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EB994(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EB9B4);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EBB40);
// clang-format on

#define func_800EA178 func_800EBDC8
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object();
M2C_UNK func_8002EE10(void*);
M2C_UNK func_8002F288(M2C_UNK*);
#define func_8002F288 ((M2C_UNK(*)(void*))func_8002F288)
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((s32(*)(void*))func_80030ECC)
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

#define FLAGS self->collision_flags
#define XPOS self->y_pos.i.hi

void func_800EBDC8(struct X4_MainObj* self) {
    s32 r;
    u8 flags;
    s16 f;
    s16 t;
    void* p;
    u16 g;

    self->unk42 &= 0x7FFF;
    if (self->action_phase != 0) {
        self->action_phase--;
        return;
    }
    animate_object(self);
    move_object(self);
    r = check_enemy_hits(self);
    if (self->unk2 == 0) {
        flags = FLAGS;
        self->on_screen = 1;
        func_8002F288(self);
        func_80030ECC(self);
        if (*(volatile u8*)&FLAGS == 0) {
            func_8002EE10(self);
        }
        f = FLAGS;
        if (flags & 8) {
            if (f & 8) {
                self->y_speed = 0;
                self->gravity = 0;
            }
            f = g = FLAGS;
            if (!(g & 8)) {
                // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
                goto set2;
            }
        }
        if ((f & 2) || (f & 1)) {
            // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
            goto set2;
        }
        if (is_off_screen(self, 0x20, 0x20) != 0) {
            self->state = 2;
            return;
        }
        // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
        goto approach;
    } else if (self->unk2 == 1) {
        t = M2C_FIELD(self, s16*, 0x8C);
        self->on_screen = 1;
        if (t != 0) {
            M2C_FIELD(self, s16*, 0x8C)--;
            if (t < 0x28) {
                if (D_800970AE > XPOS + 8) {
                    XPOS += 2;
                } else if (D_800970AE < XPOS - 8) {
                    XPOS -= 2;
                }
            }
        }
        if (func_80030ECC(self) != 0) {
        turn:
            func_80049E50(self);
            // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
            goto set2;
        }
        if (r < 0 || FLAGS != 0) {
            // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
            goto turn;
        }
        func_8002EE10(self);
        if (FLAGS != 0) {
            // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
            goto turn;
        }
        if (is_off_screen(self, 0x20, 0x20) != 0) {
            // !FAKE: inherited from src/shared/rock_09/func_800EA178.c
            goto set2;
        }
    approach:
        func_8002CCB0(self, 0x10, 0x10);
        return;
    } else {
        self->on_screen = 0;
        func_80030ECC(self);
        p = M2C_FIELD(self, void**, 0x7C);
        if (M2C_FIELD(p, s8*, 0x45) == 3 || M2C_FIELD(p, s8*, 4) == 2 ||
            M2C_FIELD(p, s8*, 4) == 3) {
        set2:
            self->state = 2;
            return;
        }
        if (is_off_screen(self, 0x20, 0x20) == 1) {
            self->state = 2;
        }
    }
}
#undef func_8002F288
#undef func_80030ECC
#undef func_800EA178

#define func_800EA1D8 func_800EC020
#define D_800FAA64 D_800F68AC
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EC06C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800EC164(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14();
        return;
    }
    func_8002CA54();
}

#define func_800EA554 func_800EC1A4
#include "../shared/rock_09/func_800EA554.c"
#undef func_800EA554

#define func_800EA5FC func_800EC24C
#include "../shared/rock_09/func_800EA5FC.c"
#undef func_800EA5FC

#define func_800EA708 func_800EC358
#include "../shared/rock_09/func_800EA708.c"
#undef func_800EA708

#define func_800EA750 func_800EC3A0
#include "../shared/rock_09/func_800EA750.c"
#undef func_800EA750

#define func_800EA7CC func_800EC41C
#include "../shared/rock_09/func_800EA7CC.c"
#undef func_800EA7CC

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EC464(void) {
    clear_object_slot();
}

#define func_80048DC8 func_800EC484
#define D_80077BC0 D_800F68F4
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EC4D0);

INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800EC688);
// clang-format on

#define func_800E9D5C func_800EC9B4
#define background_objects background_objects
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((M2C_UNK(*)())func_80030ECC)
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800EC9B4(u8* self) {
    *(s16*)(self + 0xE) =
        *(s16*)(self + 0x86) +
        (background_objects[0].y_pos.i.hi - background_objects[1].y_pos.i.hi);
    if (g_playthrough_state.stage == 4) {
        if (g_playthrough_state.substage == 0) {
            if (*(s8*)(self + 2) == 0) {
                if (g_playthrough_state.checkpoint <= 0) {
                    return;
                }
            } else if (g_playthrough_state.checkpoint < 2) {
                return;
            }
        } else {
            if (*(s8*)(self + 2) == 0x70 && (self[0x72] & 4)) {
                func_80030ECC(self);
            }
            if (D_800970AA < 0x1180 && g_playthrough_state.checkpoint <= 0) {
                return;
            }
        }
        clear_object_slot(self);
    } else if (g_playthrough_state.stage >= 0x13 &&
               g_playthrough_state.checkpoint > 0) {
        clear_object_slot(self);
    }
}
#undef func_80030ECC
#undef func_800E9D5C
#undef background_objects

#define func_80048DC8 func_800ECAF0
#define D_80077BC0 D_800F69A4
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800ECB3C(void) {
    func_8002CA14();
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800ECB5C);
// clang-format on

#define func_800EE150 func_800ECC70
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
struct X4_VisualObj* find_free_visual_obj(void);
M2C_UNK func_8004E78C(M2C_UNK);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_800ECC70(void* self) {
    struct X4_VisualObj* obj;

    if (g_Player.action == 0x14) {
        ((void (*)(s32))func_8004E78C)(1);
        M2C_FIELD(self, s8*, 0) |= 8;
        if ((g_Player.hp & 0x7F) >=
            ((struct X4_EngineObj*)((s8*)&g_playthrough_state -
                                    -g_Player.character))
                ->sub_tanks[-1]) {
            ((void (*)(void*, s32))set_animation)(self, 2);
            M2C_FIELD(self, s8*, 6) += 1;
            return;
        }
        ((void (*)(s32, s32, void*))play_sound)(2, 0x55, self);
        ((void (*)(void*, s32))set_animation)(self, 1);
        M2C_FIELD(self, s16*, 0x7C) = 0x1F;
        M2C_FIELD(self, s8*, 6) += 2;
        obj = find_free_visual_obj();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0xE;
            obj->unk2 = 0;
            obj->unk16 = 1;
            obj->unk15 = 0;
            obj->unk50 = self;
        }
        obj = find_free_visual_obj();
        if (obj != 0) {
            obj->active = 0x49;
            obj->id = 0xE;
            obj->unk2 = 1;
            obj->unk16 = 6;
            obj->unk15 = 0;
            obj->unk50 = self;
        }
    }
}
#undef g_Player
#undef func_800EE150
#undef g_Player

#define func_800EE27C func_800ECD9C
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_EngineObj g_playthrough_state;

void func_800ECD9C(void* self) {
    s8 hi;
    struct X4_EngineObj* e;

    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        M2C_FIELD(self, s16*, 0x7C) = 2;
        hi = g_Player.hp & 0x80;
        e = (struct X4_EngineObj*)((s8*)&g_playthrough_state -
                                   -g_Player.character);
        if ((g_Player.hp & 0x7F) >= e->sub_tanks[-1]) {
            g_Player.hp = hi | e->sub_tanks[-1];
            M2C_FIELD(self, s16*, 0x7C) = 0x1B;
            M2C_FIELD(self, s8*, 6) += 1;
        } else {
            g_Player.hp = hi | (g_Player.hp + 1);
        }
        ((void (*)(s32, s32, s32, void*))play_sound)(0, 0xD, 0, self);
    }
}
#undef g_Player
#undef func_800EE27C
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800ECE50);
// clang-format on

#define func_80048DC8 func_800ECF5C
#define D_80077BC0 D_800F6B58
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800ECFA8
#define D_80075FD8 D_800F6B90
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EE4C4 func_800ECFE4
#define D_800F62F0 D_800F6B64
#include "../shared/rock_09/func_800EE4C4.c"
#undef func_800EE4C4
#undef D_800F62F0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ED054(void) {
    clear_object_slot();
}

#define func_800EE554 func_800ED074
#define D_800F62F8 D_800F6B6C
#include "../shared/rock_09/func_800EE554.c"
#undef func_800EE554
#undef D_800F62F8

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", func_800ED0C8);
// clang-format on

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_8003D330();               /* extern */
M2C_UNK func_8004E78C(M2C_UNK);        /* extern */

void func_800ED148(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_8003D330();
        D_800CCEF7 = 0;
        set_animation(arg0, 0);
        func_8004E78C(0);
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) & 0xF7);
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}

#define func_800EE698 func_800ED1B8
#include "../shared/rock_09/func_800EE698.c"
#undef func_800EE698

#define func_800EE6CC func_800ED1EC
#include "../shared/rock_09/func_800EE6CC.c"
#undef func_800EE6CC

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50();                         /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*); /* extern */
s32 func_800ECE50(void*, M2C_UNK*);              /* extern */
extern M2C_UNK g_Player;
extern M2C_UNK D_800F6B54;

void func_800ED268(void* arg0) {
    func_8002CB50();
    if (M2C_FIELD(arg0, s8*, 2) == 1) {
        func_800477E4(3, &D_800F6B54, arg0);
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (func_800ECE50(arg0, &g_Player) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) - 1);
    }
}

#define func_800EE7C8 func_800ED2E8
#include "../shared/rock_09/func_800EE7C8.c"
#undef func_800EE7C8

#define func_800EE880 func_800ED3A0
#include "../shared/rock_09/func_800EE880.c"
#undef func_800EE880

#define func_800EE8D4 func_800ED3F4
#include "../shared/rock_09/func_800EE8D4.c"
#undef func_800EE8D4
