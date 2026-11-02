// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800E9B90);
// clang-format on

#include "../shared/rock_11/func_800E9D68.c"

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object();
void func_800EAB04(void*);
extern s8 D_800970A2;

#define AIM(dir, ang)                                                          \
    set_animation(self, (dir));                                                \
    M2C_FIELD(self, s32*, 0x20) = rcos((ang)) << 5;                            \
    M2C_FIELD(self, s32*, 0x24) = rsin((ang)) << 5;                            \
    break;

void func_800E9F28(struct X4_BaseObj* self) {
    if (self->unk15 == 0) {
        if (D_800970A2 == 0) {
            switch (self->unk2) {
            case 16:
                AIM(1, 0x600)
            case 17:
                AIM(2, 0xA00)
            case 18:
                AIM(1, 0x400)
            case 19:
                AIM(2, 0xC00)
            }
        } else {
            switch (self->unk2) {
            case 16:
                AIM(2, 0xA00)
            case 17:
                AIM(1, 0x600)
            case 18:
                AIM(2, 0xC00)
            case 19:
                AIM(1, 0x400)
            }
        }
    } else {
        if (D_800970A2 == 0) {
            switch (self->unk2) {
            case 16:
                AIM(1, 0x200)
            case 17:
                AIM(2, 0xE00)
            case 18:
                AIM(1, 0x400)
            case 19:
                AIM(2, 0xC00)
            }
        } else {
            switch (self->unk2) {
            case 16:
                AIM(2, 0xE00)
            case 17:
                AIM(1, 0x200)
            case 18:
                AIM(2, 0xC00)
            case 19:
                AIM(1, 0x400)
            }
        }
    }
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    func_800EAB04(self);
    ((void (*)(void*))move_object)(self);
    self->unk6++;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object();
void func_800EAB04(void*);
extern s16 D_800970AA;
extern u16 D_80097202;
#define D_80097202 (*(s16*)&D_80097202)
extern u8 D_800FB26C[];

void func_800EA220(void* self) {
    ((void (**)(void*))(D_800FB26C + 0xB94))[M2C_FIELD(self, s8*, 0x6)](self);
    move_object(self);
    {
        // !FAKE: depin: dropping it breaks the match (72/76)
        register u8* p asm("$2") = SPAD;
        if (p[0x88] == 0) {
            if ((M2C_FIELD(self, u8*, 0x15) == 0 &&
                 M2C_FIELD(self, s16*, 0xA) < D_80097202 + 0xA0) ||
                (M2C_FIELD(self, u8*, 0x15) == 0x40 &&
                 D_80097202 + 0xA0 < M2C_FIELD(self, s16*, 0xA))) {
                SPAD[0x88] = 1;
                func_800EAB04(self);
                M2C_FIELD(self, u8*, 0x5) = 2;
                M2C_FIELD(self, u8*, 0x6) = 0;
            }
        }
    }
    if ((M2C_FIELD(self, u8*, 0x15) == 0 &&
         D_800970AA > M2C_FIELD(self, s16*, 0xA)) ||
        (M2C_FIELD(self, u8*, 0x15) == 0x40 &&
         D_800970AA < M2C_FIELD(self, s16*, 0xA))) {
        M2C_FIELD(self, u8*, 0x5) = 2;
        M2C_FIELD(self, u8*, 0x6) = 0;
    }
}
#undef D_80097202

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800EA350);
// clang-format on

#define func_80041AB8 func_800EA488
#define D_80075FD8 D_800FBDB8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EA4C4
#define D_80075FD8 D_800FBE14
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800EA500);
// clang-format on

#include "../shared/rock_11/func_800EA5F0.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EA610(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EA630(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object();
void func_800EAB04(void*);
extern u16 D_80097202;
#define D_80097202 (*(s16*)&D_80097202)
extern u8 D_800FB26C[];

void func_800EA650(void* self) {
    ((void (**)(void*))(D_800FB26C + 0xB7C))[M2C_FIELD(self, s8*, 0x6)](self);
    move_object(self);
    {
        // !FAKE: depin: dropping it breaks the match (47/51)
        register u8* p asm("$2") = SPAD;
        if (p[0x88] == 0) {
            if ((M2C_FIELD(self, u8*, 0x15) == 0 &&
                 M2C_FIELD(self, s16*, 0xA) < D_80097202 + 0xA0) ||
                (M2C_FIELD(self, u8*, 0x15) == 0x40 &&
                 D_80097202 + 0xA0 < M2C_FIELD(self, s16*, 0xA))) {
                SPAD[0x88] = 1;
                func_800EAB04(self);
            }
        }
    }
}
#undef D_80097202

#include "../shared/rock_11/func_800EA71C.c"

#include "../shared/rock_11/func_800EA750.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

extern u8 D_800FB26C[];

void func_800EA758(void* self) {
    u8* s1 = M2C_FIELD(SPAD, u8**, 0x80);

    if (M2C_FIELD(s1, s8*, 0x4) == 2) {
        M2C_FIELD(self, u8*, 0x5) = 5;
        M2C_FIELD(self, u8*, 0x6) = 0;
        return;
    }
    ((void (**)(void*))(D_800FB26C + 0xB84))[M2C_FIELD(self, s8*, 0x6)](self);
    if (M2C_FIELD(s1, s8*, 0x4) == 3) {
        M2C_FIELD(self, u8*, 0x5) = 5;
        M2C_FIELD(self, u8*, 0x6) = 1;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EA7F0(void) {
    move_object();
}

#define func_8003744C func_800EA810
#define D_80073C1C D_800FBDF8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object();
void func_800EABA4(struct X4_MainObj*);
extern struct X4_PlayerObj g_Player;

void func_800EA84C(void* arg0) {
    s32 angle;
    s32 v;
    s32 t;

    s16 px = g_Player.x_pos.i.hi;
    s16 py = g_Player.y_pos.i.hi;
    angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                   px - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    v = rcos(angle);
    t = v * 16;
    M2C_FIELD(arg0, s32*, 0x20) = v * 32 + t;
    v = rsin(angle);
    t = v * 16;
    M2C_FIELD(arg0, s32*, 0x24) = v * 32 + t;
    move_object(arg0);
    v = M2C_FIELD(arg0, s32*, 0x24);
    if (v > 0) {
        set_animation(arg0, 1);
    } else {
        set_animation(arg0, 2);
    }
    func_800EABA4(arg0);
    M2C_FIELD(SPAD, s32*, 0x84) = angle;
    M2C_FIELD(arg0, u8*, 0x6)++;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800EA924(void) {
    move_object();
}

#include "../shared/rock_11/func_800EA944.c"

#include "../shared/rock_11/func_800EA980.c"

#include "../shared/rock_11/func_800EA9B4.c"

#include "common.h"

void func_800EAA50(void) {
}

#include "../shared/rock_11/func_800EAA58.c"

#include "../shared/rock_11/func_800EAB04.c"

#define func_80042C18 func_800EABA4
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#include "../shared/rock_11/func_800EABD4.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EAC80(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_800EC728(s8* arg0);
extern s32 D_800741FC[];
extern u8 D_800970B4;
extern u8 D_800FB26C[];
extern u8 D_800FBEF8[];
extern u8 D_800FBF2C[];
extern u8 D_800FBF34[];

void func_800EACA0(void* self) {
    M2C_FIELD(self, u8*, 0x3) = 0;
    if (func_800EC728(self) != 0) {
        M2C_FIELD(self, u8*, 0x4) = 3;
        return;
    }
    M2C_FIELD(SPAD, s16*, 0x84) = 0;
    if ((M2C_FIELD(self, s8*, 0x2) & 0xF0) == 0x10) {
        M2C_FIELD(SPAD, s16*, 0x84) = 0x3C;
    }
    M2C_FIELD(self, void**, 0x30) = D_800FBEF8;
    M2C_FIELD(self, u8*, 0x14) = D_800970B4;
    M2C_FIELD(self, u8*, 0x5C) = 8;
    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, void**, 0x50) = D_800FBF2C;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, void**, 0x68) = SPAD + 0x86;
    __builtin_memcpy(SPAD + 0x86, D_800FBF34, 4);
    SPAD[0x8A] = 0;
    M2C_FIELD(self, void**, 0x58) = D_800741FC;
    M2C_FIELD(self, u8*, 0x70) = 0;
    M2C_FIELD(self, u8*, 0x16) = 5;
    set_animation(self, 0);
    M2C_FIELD(self, s32*, 0x24) = 0xFFFE0000;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    M2C_FIELD(self, u8*, 0x67) = 1;
    M2C_FIELD(self, u8*, 0x4) = 1;
    play_sound(2, 0x3C, self);
    M2C_FIELD(self, u8*, 0x5) = 2;
    M2C_FIELD(self, u8*, 0x6) = 0;
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800EADE0);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EAF90(struct X4_BaseObj* self) {
    u8 flags;
    s32 i;
    s16 x;

    flags = M2C_FIELD(self, u8*, 0x70);
    if (flags & 1) {
        M2C_FIELD(self, s32*, 0x20) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0x38000;
        self->unk5 = 6;
        self->unk15 = 0x40;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 8)) {
            M2C_FIELD(self, s32*, 0x20) = 0;
            do {
                if (self->unk15 != 0) {
                    x = self->x_pos.u.hi - (s8)SPAD[0x86] - SPAD[0x88];
                } else {
                    x = self->x_pos.u.hi + (s8)SPAD[0x86] - SPAD[0x88];
                }
                if (func_80030CCC(self, x - i,
                                  (s16)(SPAD[0x89] +
                                        (self->y_pos.u.hi + (s8)SPAD[0x87])) +
                                      1,
                                  x) &
                    0xFF) {
                    if (i != 0) {
                        SPAD[0x88] += i - 1;
                    }
                    M2C_FIELD(self, s32*, 0x24) = 0xFFFC8000;
                    self->unk5 = 4;
                    SPAD[0x8A] |= 1;
                    self->unk15 = 0;
                    break;
                }
                if ((u8)i == 4) {
                    self->unk5 = 2;
                    M2C_FIELD(self, s32*, 0x28) = 0;
                    M2C_FIELD(self, s32*, 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
                i++;
            } while (i < 5);
            func_800EC7A0(self);
        } else if (SPAD[0x8A] & 1) {
            SPAD[0x88] = D_800FB26C[0xCCA];
            SPAD[0x8A] &= 0xFE;
        }
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EB1B8(struct X4_BaseObj* self) {
    s32 i;
    s16 x;
    u8 flags;

    flags = *((u8*)self + 0x70);
    if (flags & 8) {
        *(s32*)((u8*)self + 0x20) = 0x38000;
        *(s32*)((u8*)self + 0x24) = 0;
        self->unk5 = 3;
        self->unk15 = 0x40;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 2)) {
            *(s32*)((u8*)self + 0x24) = 0;
            for (; i < 5; i++) {
                if (self->unk15 != 0) {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi - (s8)sp[0x86] - sp[0x88];
                } else {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi + (s8)sp[0x86] - sp[0x88];
                }
                {
                    u8* sp = SPAD;
                    if (func_80030CCC(
                            self, x - 1,
                            (s16)(self->y_pos.i.hi + (s8)sp[0x87] - sp[0x89]) -
                                i - 1,
                            x) &
                        0xFF) {
                        u8* p = SPAD;
                        u8* q;
                        p[0x89] += i;
                        *(s32*)((u8*)self + 0x20) = 0xFFFC8000;
                        self->unk5 = 5;
                        q = SPAD;
                        q[0x8A] |= 0x10;
                        self->unk15 = 0;
                        break;
                    }
                }
                if ((i & 0xFF) == 4) {
                    self->unk5 = 2;
                    *(s32*)((u8*)self + 0x28) = 0;
                    *(s32*)((u8*)self + 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
            }
            func_800EC7A0(self);
        } else {
            u8* p = SPAD;
            if (p[0x8A] & 0x10) {
                u8* q;
                p[0x89] = D_800FB26C[0xCCB];
                q = SPAD;
                q[0x8A] &= 0xEF;
            }
        }
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EB3D4(struct X4_BaseObj* self) {
    s32 i;
    s16 x;
    u8 flags;

    flags = *((u8*)self + 0x70);
    if (flags & 2) {
        *(s32*)((u8*)self + 0x20) = 0;
        *(s32*)((u8*)self + 0x24) = 0xFFFC8000;
        self->unk5 = 4;
        self->unk15 = 0;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 4)) {
            *(s32*)((u8*)self + 0x20) = 0;
            for (; i < 5; i++) {
                if (self->unk15 != 0) {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi - (s8)sp[0x86] + sp[0x88];
                } else {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi + (s8)sp[0x86] + sp[0x88];
                }
                {
                    u8* sp = SPAD;
                    if (func_80030CCC(
                            self, x + i,
                            (s16)(self->y_pos.i.hi + (s8)sp[0x87] - sp[0x89]) -
                                1,
                            x) &
                        0xFF) {
                        u8* p = SPAD;
                        u8* q;
                        p[0x88] += i;
                        *(s32*)((u8*)self + 0x24) = 0x38000;
                        self->unk5 = 6;
                        q = SPAD;
                        q[0x8A] |= 1;
                        self->unk15 = 0x40;
                        break;
                    }
                }
                if ((i & 0xFF) == 4) {
                    self->unk5 = 2;
                    *(s32*)((u8*)self + 0x28) = 0;
                    *(s32*)((u8*)self + 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
            }
            func_800EC7A0(self);
        } else {
            u8* p = SPAD;
            if (p[0x8A] & 1) {
                u8* q;
                p[0x88] = D_800FB26C[0xCCA];
                q = SPAD;
                q[0x8A] &= 0xFE;
            }
        }
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EB5E8(struct X4_BaseObj* self) {
    s32 i;
    s16 x;
    u8 flags;

    flags = *((u8*)self + 0x70);
    if (flags & 4) {
        *(s32*)((u8*)self + 0x20) = 0xFFFC8000;
        *(s32*)((u8*)self + 0x24) = 0;
        self->unk5 = 5;
        self->unk15 = 0;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 1)) {
            *(s32*)((u8*)self + 0x24) = 0;
            for (; i < 5; i++) {
                if (self->unk15 != 0) {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi - (s8)sp[0x86] + sp[0x88];
                } else {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi + (s8)sp[0x86] + sp[0x88];
                }
                {
                    u8* sp = SPAD;
                    if (func_80030CCC(
                            self, x + 1,
                            (s16)(self->y_pos.i.hi + (s8)sp[0x87] + sp[0x89]) +
                                i,
                            x) &
                        0xFF) {
                        u8* p = SPAD;
                        u8* q;
                        p[0x89] += i;
                        *(s32*)((u8*)self + 0x20) = 0x38000;
                        self->unk5 = 3;
                        q = SPAD;
                        q[0x8A] |= 0x10;
                        self->unk15 = 0x40;
                        break;
                    }
                }
                if ((i & 0xFF) == 4) {
                    self->unk5 = 2;
                    *(s32*)((u8*)self + 0x28) = 0;
                    *(s32*)((u8*)self + 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
            }
            func_800EC7A0(self);
        } else {
            u8* p = SPAD;
            if (p[0x8A] & 0x10) {
                u8* q;
                p[0x89] = D_800FB26C[0xCCB];
                q = SPAD;
                q[0x8A] &= 0xEF;
            }
        }
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EB7FC(struct X4_BaseObj* self) {
    s32 i;
    s16 x;
    u8 flags;

    flags = *((u8*)self + 0x70);
    if (flags & 2) {
        *(s32*)((u8*)self + 0x20) = 0;
        *(s32*)((u8*)self + 0x24) = 0x38000;
        self->unk5 = 0xA;
        self->unk15 = 0;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 8)) {
            *(s32*)((u8*)self + 0x20) = 0;
            for (; i < 5; i++) {
                if (self->unk15 != 0) {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi - (s8)sp[0x86] + sp[0x88];
                } else {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi + (s8)sp[0x86] + sp[0x88];
                }
                {
                    u8* sp = SPAD;
                    if (func_80030CCC(
                            self, x + i,
                            (s16)(self->y_pos.i.hi + (s8)sp[0x87] + sp[0x89]) +
                                1,
                            x) &
                        0xFF) {
                        u8* p = SPAD;
                        u8* q;
                        p[0x88] += i;
                        *(s32*)((u8*)self + 0x24) = 0xFFFC8000;
                        self->unk5 = 8;
                        q = SPAD;
                        q[0x8A] |= 1;
                        self->unk15 = 0x40;
                        break;
                    }
                }
                if ((i & 0xFF) == 4) {
                    self->unk5 = 2;
                    *(s32*)((u8*)self + 0x28) = 0;
                    *(s32*)((u8*)self + 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
            }
            func_800EC7A0(self);
        } else {
            u8* p = SPAD;
            if (p[0x8A] & 1) {
                u8* q;
                p[0x88] = D_800FB26C[0xCCA];
                q = SPAD;
                q[0x8A] &= 0xFE;
            }
        }
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EBA10(struct X4_BaseObj* self) {
    s32 i;
    s16 x;
    u8 flags;

    flags = *((u8*)self + 0x70);
    if (flags & 8) {
        *(s32*)((u8*)self + 0x20) = 0xFFFC8000;
        *(s32*)((u8*)self + 0x24) = 0;
        self->unk5 = 7;
        self->unk15 = 0;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 1)) {
            *(s32*)((u8*)self + 0x24) = 0;
            for (; i < 5; i++) {
                if (self->unk15 != 0) {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi - (s8)sp[0x86] + sp[0x88];
                } else {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi + (s8)sp[0x86] + sp[0x88];
                }
                {
                    u8* sp = SPAD;
                    if (func_80030CCC(
                            self, x + 1,
                            (s16)(self->y_pos.i.hi + (s8)sp[0x87] - sp[0x89]) -
                                i - 1,
                            x) &
                        0xFF) {
                        u8* p = SPAD;
                        u8* q;
                        p[0x89] += i;
                        *(s32*)((u8*)self + 0x20) = 0x38000;
                        self->unk5 = 9;
                        q = SPAD;
                        q[0x8A] |= 0x10;
                        self->unk15 = 0;
                        break;
                    }
                }
                if ((i & 0xFF) == 4) {
                    self->unk5 = 2;
                    *(s32*)((u8*)self + 0x28) = 0;
                    *(s32*)((u8*)self + 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
            }
            func_800EC7A0(self);
        } else {
            u8* p = SPAD;
            if (p[0x8A] & 0x10) {
                u8* q;
                p[0x89] = D_800FB26C[0xCCB];
                q = SPAD;
                q[0x8A] &= 0xEF;
            }
        }
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EBC28(struct X4_BaseObj* self) {
    u8 flags;
    s32 i;
    s16 x;

    flags = M2C_FIELD(self, u8*, 0x70);
    if (flags & 1) {
        M2C_FIELD(self, s32*, 0x20) = 0;
        M2C_FIELD(self, s32*, 0x24) = 0xFFFC8000;
        self->unk5 = 8;
        self->unk15 = 0x40;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 4)) {
            M2C_FIELD(self, s32*, 0x20) = 0;
            do {
                if (self->unk15 != 0) {
                    x = self->x_pos.u.hi - (s8)SPAD[0x86] - SPAD[0x88];
                } else {
                    x = self->x_pos.u.hi + (s8)SPAD[0x86] - SPAD[0x88];
                }
                if (func_80030CCC(
                        self, x - i,
                        (s16)(self->y_pos.u.hi + (s8)SPAD[0x87] - SPAD[0x89]) -
                            1,
                        x) &
                    0xFF) {
                    if (i != 0) {
                        SPAD[0x88] += i - 1;
                    }
                    M2C_FIELD(self, s32*, 0x24) = 0x38000;
                    self->unk5 = 0xA;
                    SPAD[0x8A] |= 1;
                    self->unk15 = 0;
                    break;
                }
                if ((u8)i == 4) {
                    self->unk5 = 2;
                    M2C_FIELD(self, s32*, 0x28) = 0;
                    M2C_FIELD(self, s32*, 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
                i++;
            } while (i < 5);
            func_800EC7A0(self);
        } else if (SPAD[0x8A] & 1) {
            SPAD[0x88] = D_800FB26C[0xCCA];
            SPAD[0x8A] &= 0xFE;
        }
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object(void*);
s32 func_80030CCC(void*, s32, s32, s16);
void func_800EC7A0(void*);
extern u8 D_800FB26C[];

void func_800EBE50(struct X4_BaseObj* self) {
    s32 i;
    s16 x;
    u8 flags;

    flags = *((u8*)self + 0x70);
    if (flags & 4) {
        *(s32*)((u8*)self + 0x20) = 0x38000;
        *(s32*)((u8*)self + 0x24) = 0;
        self->unk5 = 9;
        self->unk15 = 0x40;
        func_800EC7A0(self);
    } else {
        i = 0;
        if (!(flags & 2)) {
            *(s32*)((u8*)self + 0x24) = 0;
            for (; i < 5; i++) {
                if (self->unk15 != 0) {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi - (s8)sp[0x86] - sp[0x88];
                } else {
                    u8* sp = SPAD;
                    x = self->x_pos.i.hi + (s8)sp[0x86] - sp[0x88];
                }
                {
                    u8* sp = SPAD;
                    if (func_80030CCC(
                            self, x - 1,
                            (s16)(self->y_pos.i.hi + (s8)sp[0x87] + sp[0x89]) +
                                i,
                            x) &
                        0xFF) {
                        u8* p = SPAD;
                        u8* q;
                        p[0x89] += i;
                        *(s32*)((u8*)self + 0x20) = 0xFFFC8000;
                        self->unk5 = 7;
                        q = SPAD;
                        q[0x8A] |= 0x10;
                        self->unk15 = 0;
                        break;
                    }
                }
                if ((i & 0xFF) == 4) {
                    self->unk5 = 2;
                    *(s32*)((u8*)self + 0x28) = 0;
                    *(s32*)((u8*)self + 0x2C) = 0x1000;
                    __builtin_memcpy(SPAD + 0x86, D_800FB26C + 0xCC8, 4);
                }
            }
            func_800EC7A0(self);
        } else {
            u8* p = SPAD;
            if (p[0x8A] & 0x10) {
                u8* q;
                p[0x89] = D_800FB26C[0xCCB];
                q = SPAD;
                q[0x8A] &= 0xEF;
            }
        }
    }
    move_object(self);
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EC830(void*, s32, s32);
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF38;

void func_800EC068(struct X4_BaseObj* self) {
    s8 state = *(s8*)((u8*)self + 0x45);
    s32 v;

    if (state == 1) {
        if (*(s16*)((u8*)self + 0x7C) == 0) {
            s16 px = g_Player.x_pos.i.hi;
            s16 py = g_Player.y_pos.i.hi;
            *(s32*)(SPAD + 0x80) =
                ratan2(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
            func_800EC830(self, 0, *(s32*)(SPAD + 0x80));
        } else {
            func_800EC830(self, 1, *(s32*)(SPAD + 0x80));
        }
    } else if (state == 2) {
        if (D_800CCF38 >= 2 && ++*(s16*)((u8*)self + 0x7C) < 2) {
            v = *(u8*)((u8*)self + 6) - 1;
        } else {
            set_animation(self, 2);
            v = *(u8*)((u8*)self + 6);
            v += 1;
        }
        self->unk6 = v;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 random_byte();

extern u8 D_800FBF9C[];
extern u8 D_800FBFA0[];

void func_800EC180(void* self) {
    s32 a;
    s32 r;
    s32 t;

    M2C_FIELD(self, u8*, 0x60) = 4;
    M2C_FIELD(self, u8*, 0x5C) = 1;
    M2C_FIELD(self, u8*, 0x16) = 4;
    M2C_FIELD(self, u8*, 0x67) = 1;
    set_animation(self, 8);
    M2C_FIELD(self, void**, 0x68) = D_800FBF9C;
    M2C_FIELD(self, void**, 0x50) = D_800FBFA0;
    M2C_FIELD(self, s32*, 0x54) = 0;
    M2C_FIELD(self, u8*, 0x4) = 1;
    M2C_FIELD(self, u8*, 0x5) = 0;
    M2C_FIELD(self, u8*, 0x6) = 0;
    M2C_FIELD(self, u8*, 0x7) = 0;
    play_sound(2, 0, self);
    switch (M2C_FIELD(self, s16*, 0x88)) {
    case 3:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) -= 12;
            M2C_FIELD(self, s16*, 0xE) -= 1;
        } else {
            M2C_FIELD(self, s16*, 0xA) += 12;
            M2C_FIELD(self, s16*, 0xE) -= 1;
        }
        break;
    case 4:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) -= 9;
            M2C_FIELD(self, s16*, 0xE) -= 11;
        } else {
            M2C_FIELD(self, s16*, 0xA) += 9;
            M2C_FIELD(self, s16*, 0xE) -= 11;
        }
        break;
    case 5:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) -= 9;
            M2C_FIELD(self, s16*, 0xE) += 7;
        } else {
            M2C_FIELD(self, s16*, 0xA) += 9;
            M2C_FIELD(self, s16*, 0xE) += 7;
        }
        break;
    case 6:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) += 1;
            M2C_FIELD(self, s16*, 0xE) -= 13;
        } else {
            M2C_FIELD(self, s16*, 0xA) -= 1;
            M2C_FIELD(self, s16*, 0xE) -= 13;
        }
        break;
    case 7:
        if (M2C_FIELD(self, u8*, 0x15) == 0) {
            M2C_FIELD(self, s16*, 0xA) -= 1;
            M2C_FIELD(self, s16*, 0xE) += 13;
        } else {
            M2C_FIELD(self, s16*, 0xA) += 1;
            M2C_FIELD(self, s16*, 0xE) += 13;
        }
        break;
    }
    a = M2C_FIELD(self, s32*, 0x84);
    if (M2C_FIELD(self, s8*, 0x2) != 0) {
        if (random_byte() & 1) {
            a += 0xAA;
        } else {
            a -= 0xAA;
        }
    }
    r = rcos(a);
    t = r * 16;
    M2C_FIELD(self, s32*, 0x20) = r * 32 + t;
    r = rsin(a);
    t = r * 16;
    M2C_FIELD(self, s32*, 0x24) = r * 32 + t;
    M2C_FIELD(self, s32*, 0x28) = 0;
    M2C_FIELD(self, s32*, 0x2C) = 0;
    if (func_8002CBFC(self, 0x18, 0x18) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
    } else {
        M2C_FIELD(self, u8*, 0x4)++;
    }
}

#define func_80041AB8 func_800EC3FC
#define D_80075FD8 D_800FBF38
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EC438
#define D_80075FD8 D_800FBFA8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EC474(void) {
    func_8002CA14();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EC494(void) {
    func_8002CA54();
}

#include "../shared/rock_11/func_800EC4B4.c"

#define func_8003744C func_800EC53C
#define D_80073C1C D_800FBF8C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EC800();

void func_800EC578(u8* arg0) {
    func_800EC800(arg0);
    ((void (*)(void*, s32))set_animation)(arg0, 1);
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800EC5B8);
// clang-format on

#include "../shared/rock_11/func_800EC6AC.c"

#include "common.h"

void func_800EC720(void) {
}

#include "../shared/rock_11/func_800EC728.c"

#include "../shared/rock_11/func_800EC7A0.c"

#define func_80042C18 func_800EC800
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800EC830);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object(void*);                     /* extern */
M2C_UNK func_8002EE10(void*);                   /* extern */
M2C_UNK func_80030ECC(void*);                   /* extern */
M2C_UNK func_80049D90(void*);                   /* extern */

void func_800EC900(void* arg0) {
    func_80017A04();
    move_object(arg0);
    func_80030ECC(arg0);
    if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    if (func_8002CBFC(arg0, 0x18, 0x18) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800EC9B0(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800EC9D0);

INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800ECB58);

INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800ECCF0);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800ECD6C(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800ECD8C(void* arg0) {
    s32 var_s0;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x42) = (u16)(M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v1 + 1);
    if ((s16)temp_v1 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0U;
    var_s0 = 3;
    do {
        func_80049EBC(arg0, 1, 0x10, 0x10);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    func_8002CA14(arg0);
}

#define func_800EAA18 func_800ECE20
#include "../shared/rock_05/func_800EAA18.c"
#undef func_800EAA18

#define func_800EAAA4 func_800ECEAC
#include "../shared/rock_05/func_800EAAA4.c"
#undef func_800EAAA4

#define func_800EAADC func_800ECEE4
#include "../shared/rock_05/func_800EAADC.c"
#undef func_800EAADC

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800ECF30);
// clang-format on

#define func_800EF160 func_800ED1F0
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_04/func_800EF160.c"
#undef func_800EF160
#undef g_playthrough_state

#define func_80041AB8 func_800ED624
#define D_80075FD8 D_800FC07C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800EF5D0 func_800ED660
#define D_800F6D84 D_800FC0A4
#include "../shared/rock_04/func_800EF5D0.c"
#undef func_800EF5D0
#undef D_800F6D84

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800ED728(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800ED748(void* arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 < 0x3C) {
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) ^ 1);
        return;
    }
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04(); /* extern */
M2C_UNK move_object();   /* extern */

void func_800ED79C(s32 arg0) {
    func_80017A04();
    move_object(arg0);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800ED7C8 (*(s32**)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 random_byte();
extern s32 D_8007483C;
extern u32* D_80095098;
extern u8 D_800970B4;
extern s16 D_8009721C;
extern u8 D_800FB26C[];
extern s32 D_800FC84C;
extern void* D_800FD510;
extern s8 D_800FD514;
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51A;
extern s8 D_800FD51B;
extern s8 D_800FD51D;
extern s8 D_800FD51F;
extern s8 D_800FD520;
extern s8 D_800FD521;
extern s16 D_800FD526;

#define F(type, off) M2C_FIELD(self, type*, off)

#define SETUP_GFX()                                                            \
    {                                                                          \
        s32 a;                                                                 \
        s32 b;                                                                 \
        F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;           \
        a = func_8002A47C(F(s8, 1));                                           \
        b = func_8002A47C(F(s8, 1)) + 1;                                       \
        a = (a + 1) * 4;                                                       \
        F(s16, 0x42) = ((a + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);       \
        F(u8*, 0x3C) = (u8*)SPAD20_800ED7C8 +                                  \
                       SPAD20_800ED7C8[func_8002A47C(F(s8, 1)) + 1];           \
    }

void func_800ED7C8(void* self) {
    s32 type;
    s32 sub;

    F(s16, 0x7C) = 0;
    F(s8, 0x60) = 0;
    F(s8, 0x5C) = 0;
    F(s8, 0x61) = 0;
    F(s8, 0x3) = 0;
    F(u8, 0x14) = D_800970B4;
    F(u8, 0x16) = 5;
    F(void*, 0x30) = &D_800FC84C;
    F(s32, 0x68) = 0;
    F(void*, 0x54) = 0;
    F(s32, 0x50) = 0;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x15) = 0;
    F(s8, 0x67) = 0;
    F(void*, 0x58) = &D_8007483C;
    type = F(s8, 2) & 0xF0;
    if (type != 0 && D_800FD51D != 0) {
        F(s8, 4) = 3;
        F(s8, 3) = 0;
        return;
    }
    if (type == 0) {
        D_800FD510 = self;
        D_800FD514 = 0;
        D_800FD516 = 0;
        D_800FD518 = 0;
        D_800FD51B = 0;
        D_800FD51D = 0;
        D_800FD51F = 0;
        D_800FD520 = 0;
        D_800FD521 = 0;
        D_800FD51A = 0;
        D_800FD526 = 0;
        F(s8, 0x87) = 0;
        F(s8, 0x85) = random_byte() & 0xF;
        F(s8, 0x84) = 0x78;
        F(s8, 0x86) = 0;
        F(s8, 0x89) = 0;
        F(s8, 0x5C) = 0;
        F(s8, 0x60) = 4;
        F(s8, 0x14) = -1;
        F(s8, 4) = 1;
        F(s8, 5) = 2;
        D_8009721C = 0x800;
    } else {
        if (type == 0x10) {
            F(s8, 0x14) = -1;
            F(s8, 3) = 1;
            F(s16, 0xA) = 0xA0;
            F(s16, 0xE) = 0x48;
            F(s8, 4) = 2;
            F(s16, 0x7E) = random_byte() * 16;
            F(void*, 0x54) = &D_800FB26C[0x1058];
            F(s8, 0x5C) = type;
            if (F(u8, 2) & 0xF) {
                F(u16, 0x40) += 0x400;
                SETUP_GFX();
            }
            sub = F(u8, 2) & 0xF;
            switch (sub) {
            case 0:
                F(u8, 0x16) = 0x30;
                set_animation(self, 0x50);
                F(s32, 0x50) = 0;
                F(void*, 0x54) = 0;
                F(s8, 0x5C) = 0x28;
                F(s8, 5) = 2;
                break;
            case 1:
                ((void (*)(void*, s32))set_animation)(self, 0x21);
                F(s8, 5) = 3;
                break;
            case 2:
                ((void (*)(void*, s32))set_animation)(self, 0x25);
                F(s8, 5) = 3;
                break;
            case 3:
                set_animation(self, 0x25);
                F(s8, 5) = sub;
                break;
            }
        } else if (type == 0x20) {
            F(u8, 0x16) = 2;
            F(s8, 0x14) = -1;
            F(s8, 3) = 0;
            F(s8, 4) = 2;
            F(u16, 0x40) += 0x400;
            SETUP_GFX();
            set_animation(self, 0x35);
            F(s8, 5) = 5;
        } else if (type == 0x30) {
            F(s8, 0x14) = 0;
            F(s8, 3) = 1;
            F(s8, 4) = 2;
            F(u16, 0x40) += 0x400;
            SETUP_GFX();
            ((void (*)(void*, s32))set_animation)(self, 0x37);
            if ((F(s8, 2) & 0xF) < 5) {
                F(u8, 0x15) = 0x40;
            } else {
                F(u8, 0x15) = 0;
            }
            F(s8, 0x5C) = 0x14;
            F(s8, 5) = 6;
        } else if (type == 0x40) {
            play_sound(2, 0x38, self);
            D_800FD520 = 1;
            F(s8, 0x14) = -1;
            F(s8, 4) = 2;
            F(s8, 0x5C) = 1;
            F(s8, 5) = 7;
        }
    }
    F(s8, 6) = 0;
    F(s32, 0x18) = F(s32, 8);
    F(s32, 0x1C) = F(s32, 0xC);
}

#undef F
#undef SETUP_GFX

#include "common.h"
#define M2C_UNK s32
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern s8 D_800CCEEC;
extern u8 D_800E9878[];
extern M2C_UNK D_800FD530;
extern M2C_UNK D_800FD930;
extern M2C_UNK D_800FD9D0;
extern s16 D_800FDA70;

void func_800EDD28(u8* arg0) {
    u8 buf[4];

    __builtin_memcpy(buf, D_800E9878, 4);
    D_800CCEEC = 1;
    __builtin_memcpy((u8*)&D_800FD530, (u8*)(SPAD28 + 0x780), 0x200);
    __builtin_memcpy((u8*)&D_800FD930, (u8*)(SPAD28 + 0xC00), 0xA0);
    D_800FDA70 = 0;
    func_8002B410(&D_800FD9D0, &D_800FD930, 0x50, 0, 0x60);
    load_palette(0x60, &D_800FD9D0, 5);
    *(s16*)(arg0 + 0x7C) = 3;
    arg0[7] = 0;
    arg0[6]++;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800FD530;
extern M2C_UNK D_800FD730;
extern M2C_UNK D_800FD930;
extern M2C_UNK D_800FD9D0;
extern s16 D_800FDA70;

void func_800EDF24(u8* arg0) {
    func_8002B410(&D_800FD730, &D_800FD530, 0x100, --D_800FDA70, 0x60);
    load_palette(0x3C, &D_800FD730, 0x10);
    func_8002B410(&D_800FD9D0, &D_800FD930, 0x50, D_800FDA70, 0x60);
    load_palette(0x60, &D_800FD9D0, 5);
    if (D_800FDA70 == 0) {
        load_palette(0x3C, &D_800FD530, 0x10);
        load_palette(0x60, &D_800FD930, 5);
        arg0[7] = 4;
        arg0[6]++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F1A90(void* self, u8 arg1);
void func_800F3E10(void* arg0, s32 arg1);
extern s8 D_800FD514;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EE034(void* self) {
    s16 t;

    F(u8, 7) = 0;
    t = --F(s16, 0x7C);
    if (t == 0) {
        if (D_800FD514 == 0) {
            F(s16, 0x7C) = 0x5A;
            func_800F3E10(self, 0x29);
            return;
        }
        if (D_800FD514 == 1) {
            F(s16, 0x7C) = 0x2D;
            func_800F3E10(self, 0x2A);
            return;
        }
        if (--F(s16, 0x7E) == -1) {
            F(u8, 7) = 6;
            func_800F3E10(self, 0x25);
            func_800F3E10(self, 0x26);
            func_800F3E10(self, 0x27);
            func_800F3E10(self, 0x28);
            {
                s32 n = F(u8, 6) + 1;
                F(s16, 0x7C) = 0x3C;
                F(u8, 6) = n;
            }
            return;
        }
        F(s16, 0x7C) = 0x5A;
    block_8:
        func_800F3E10(self, 0x29);
        return;
    }
    if (D_800FD514 == 1) {
        if (t == 0x16) {
            func_800F1A90(self, 0);
        }
    } else if (t == 0x1E) {
        func_800F1A90(self, 0);
    }
}

#undef F

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EE178 (*(s32**)0x1F800020)

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
s32 func_8002B2F8(s32);
s32 random_byte();
void func_800478F0(s32, void*, void*, u16, s32, s32);
void func_800F4664(s16 arg0, s16 arg1);
extern u32* D_80095098;
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800C4560;
extern s8 D_800CCEF4;
extern u8 D_800FC9A4[];
extern u8 D_800FC9D0[];

#define F(type, off) M2C_FIELD(self, type*, off)

// str 0x800FC9A4 sha1=6d053fc8f29c0bf2185d6a1e0f2776be21a6d66d = "printable byte run: a table, not text"
void func_800EE178(void* self) {
    s32 i;
    s32 row;
    s16 x;
    s16 y;

    D_800CCEF4 = 0;
    func_80027BA0(1, 0x8C0, 0x170, D_800FC9D0);
    i = 0;
    do {
        row = i << 5;
        func_800F4664(background_objects[0].x_pos.u.hi + 0xF8 +
                          (random_byte() & 0x1F),
                      (s16)(background_objects[0].y_pos.i.hi - 0x10) +
                          (row + (s16)((random_byte() & 0x1F) + 8)));
        i++;
        func_800F4664(background_objects[0].x_pos.u.hi + 0x118 +
                          (random_byte() & 0x1F),
                      (s16)(background_objects[0].y_pos.i.hi - 0x10) +
                          (row + (s16)((random_byte() & 0x1F) + 8)));
    } while (i < 8);
    x = F(s16, 0xA);
    y = F(s16, 0xE);
    F(s8, 0x3) = 1;
    F(s8, 0x14) = 0;
    F(u16, 0x40) += 0x400;
    F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;
    F(s16, 0x42) = (((func_8002A47C(F(s8, 1)) + 1) * 4 + 0x20) % 16) |
                   (((func_8002A47C(F(s8, 1)) + 1 + 8) / 4 + 0x1E0) << 6);
    F(u8*, 0x3C) =
        (u8*)SPAD20_800EE178 + SPAD20_800EE178[func_8002A47C(F(s8, 1)) + 1];
    F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x120;
    F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0x60;
    func_800478F0(5, D_800FC9A4, self, F(u16, 0x42), 0, 0);
    F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x120;
    F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0x20;
    func_800478F0(4, D_800FC9A4, self, F(u16, 0x42), 0, 0);
    F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x110;
    F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0xD0;
    func_800478F0(4, D_800FC9A4, self, F(u16, 0x42), 0, 0);
    F(s8, 0x3) = 0;
    F(s8, 0x14) = -1;
    F(s16, 0xA) = x;
    F(s16, 0xE) = y;
    F(u16, 0x40) -= 0x400;
    F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1))] >> 7;
    F(s16, 0x42) = (((func_8002A47C(F(s8, 1))) * 4 + 0x20) % 16) |
                   (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
    F(u8*, 0x3C) =
        (u8*)SPAD20_800EE178 + SPAD20_800EE178[func_8002A47C(F(s8, 1))];
    background_objects[1].unk4C = 1;
    func_8002B2F8(0);
    D_800C4560 |= 1;
    F(u8, 0x6)++;
}

#undef F
#undef SPAD20_800EE178

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern s16 D_80090D5C;
#include "mmx6/state.h"
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EE4F4(void* self) {
    s32 t;

    if (--F(s16, 0x7E) == 0) {
        F(u16, 0x7E) = 0x3C;
    }
    if (--F(s16, 0x7C) == -1) {
        F(u16, 0x7C) = 3;
        t = (u16)D_800CF854 + 1;
        D_800CF854 = t;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        D_800C4560 |= 1;
        if ((u16)t >= 0x1F) {
            F(u8, 0x6)++;
        }
    }
    if (!(D_80097420.frame_counter & 3)) {
        func_8002943C(2, 5, 2);
    }
    if (!(D_80097420.frame_counter & 0x1F)) {
        func_80012D9C(3);
    }
}

#undef F

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EE5F8 (*(s32**)0x1F800020)

s32 func_80013AA4(s8 arg0);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
s32 func_8002B2F8(s32);
s32 random_byte();
void func_800478F0(s32, void*, void*, u16, s32, s32);
void func_800F4664(s16 arg0, s16 arg1);
extern u32* D_80095098;
extern s8 D_800970A5;
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800C4560;
extern s8 D_800CCEF4;
extern u8 D_800FC9A4[];
extern u8 D_800FC9D0[];

#define F(type, off) M2C_FIELD(self, type*, off)

// str 0x800FC9A4 sha1=6d053fc8f29c0bf2185d6a1e0f2776be21a6d66d = "printable byte run: a table, not text"
void func_800EE5F8(void* self) {
    s32 i;
    s32 row;
    s16 x;
    s16 y;

    if (D_800970A5 == 0x14) {
        D_800CCEF4 = 0;
        func_80027BA0(1, 0x1140, 0x2F0, D_800FC9D0);
        i = 0;
        do {
            row = i << 5;
            func_800F4664(background_objects[0].x_pos.u.hi + 0xF8 +
                              (random_byte() & 0x1F),
                          (s16)(background_objects[0].y_pos.i.hi - 0x10) +
                              (row + (s16)((random_byte() & 0x1F) + 8)));
            i++;
            func_800F4664(background_objects[0].x_pos.u.hi + 0x118 +
                              (random_byte() & 0x1F),
                          (s16)(background_objects[0].y_pos.i.hi - 0x10) +
                              (row + (s16)((random_byte() & 0x1F) + 8)));
        } while (i < 8);
        x = F(s16, 0xA);
        y = F(s16, 0xE);
        F(s8, 0x3) = 1;
        F(s8, 0x14) = 0;
        F(u16, 0x40) += 0x400;
        F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;
        F(s16, 0x42) = (((func_8002A47C(F(s8, 1)) + 1) * 4 + 0x20) % 16) |
                       (((func_8002A47C(F(s8, 1)) + 1 + 8) / 4 + 0x1E0) << 6);
        F(u8*, 0x3C) =
            (u8*)SPAD20_800EE5F8 + SPAD20_800EE5F8[func_8002A47C(F(s8, 1)) + 1];
        F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x120;
        F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0x60;
        func_800478F0(5, D_800FC9A4, self, F(u16, 0x42), 0, 0);
        F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x120;
        F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0x20;
        func_800478F0(4, D_800FC9A4, self, F(u16, 0x42), 0, 0);
        F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x110;
        F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0xD0;
        func_800478F0(4, D_800FC9A4, self, F(u16, 0x42), 0, 0);
        F(s8, 0x3) = 0;
        F(s8, 0x14) = -1;
        F(s16, 0xA) = x;
        F(s16, 0xE) = y;
        F(u16, 0x40) -= 0x400;
        F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1))] >> 7;
        F(s16, 0x42) = (((func_8002A47C(F(s8, 1))) * 4 + 0x20) % 16) |
                       (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
        F(u8*, 0x3C) =
            (u8*)SPAD20_800EE5F8 + SPAD20_800EE5F8[func_8002A47C(F(s8, 1))];
        background_objects[1].unk4C = 1;
        func_8002B2F8(0);
        D_800C4560 |= 1;
        func_80013AA4(0x3C);
        F(u8, 0x6)++;
    }
}

#undef F
#undef SPAD20_800EE5F8

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
s32 random_byte();
void func_800F1FBC();
void func_800F3EC4(void* arg0, u8 arg1, s16 arg2, s16 arg3);
void func_800F4664(s16 arg0, s16 arg1);
extern struct X4_BackgroundObj background_objects[3];

void func_800EE990(u8* self) {
    s32 x;
    s32 y;

    if (D_80097420.frame_counter & 3) {
        x = (s16)(random_byte() % 150);
        y = (s16)(random_byte() % 120);
        if (random_byte() & 1) {
            x = (s16)-x;
        }
        if (random_byte() & 1) {
            y = (s16)-y;
        }
        func_800F4664(x + (background_objects[0].x_pos.u.hi + 0x96),
                      y + (background_objects[0].y_pos.u.hi + 0x78));
    }
    if (D_80097420.frame_counter & 7) {
        x = (s16)(random_byte() % 150);
        if (random_byte() & 1) {
            x = (s16)-x;
        }
        func_800F3EC4(self, 0x60, x + (background_objects[0].x_pos.u.hi + 0x96),
                      background_objects[0].y_pos.u.hi - 0xA);
    }
    if (!(D_80097420.frame_counter & 0x1F)) {
        func_80012D9C(3);
    }
    if (D_80097420.transition.fade_amount == 0) {
        func_800F1FBC();
        ((s8*)self)[7] = -1;
        *(s16*)(self + 0x7C) = 0x3C;
        self[6]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FB26C[];
extern u8 D_800FC9D8[];
extern u8 D_800FC9E0[];
extern s8 D_800FD514;

#define TB (D_800FB26C + 0xE44)
#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EEBBC(void* self) {
    s32 r;

    F(u8, 0x7) = 0;
    if ((s16)(F(s16, 0x7C) % 12) == 0) {
        func_80027BA0(1, background_objects[0].x_pos.i.hi + 0xC0,
                      background_objects[0].y_pos.i.hi - 0x10,
                      &D_800FC9E0[F(s16, 0x7E) * 8]);
        background_objects[1].unk4C = 1;
        if (++F(s16, 0x7E) == 4) {
            F(s16, 0x7E) = 0;
        }
    }
    if (--F(s16, 0x7C) == 0) {
        func_80027BA0(1, background_objects[0].x_pos.i.hi + 0xC0,
                      background_objects[0].y_pos.i.hi - 0x10, D_800FC9D8);
        background_objects[1].unk4C = 1;
        F(s8, 0x87) = D_800FD514;
        r = random_byte() & 0xF;
        F(s8, 0x85) = r;
        F(s8, 0x86) = 0;
        F(u8, 0x5) = TB[F(s8, 0x87) * 128 + r * 8];
        F(s8, 0x6) = 0;
    }
}

#undef F
#undef TB

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 random_byte();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_800F4664(s16 arg0, s16 arg1);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FC99C;
extern s32 D_800FC9A0;
extern u8 D_800FC9C0[];
extern void (*D_800FCAF4[])(void*);
extern s8 D_800FD51C;
extern s8 D_800FD51D;
extern s8 D_800FD51E;
extern s8 D_800FD51F;
extern s8 D_800FD520;
extern s8 D_800FD521;
extern u8 D_800FD522;

// str 0x800FC99C sha1=0eac54faaac158f6d801fad2ace88d48fcfa11f5 = "printable byte run: a table, not text"
// str 0x800FC9A0 sha1=44c6d6c2ecd801e25abad8013bf897c534962379 = "tail of the same byte run"
void func_800EED14(void* arg0) {
    s32 i;
    s32 y;
    s16 x;
    s16 dy;
    s32 t;
    s32 tx;

    if (D_800FD51D != 0) {
        if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x40) {
            D_800FD520 = 0;
            D_800FD51C = 0;
            for (i = 0; i < D_800FD51F / 2 + 1; i++) {
                y = i << 5;
                x = 0x10 - (random_byte() & 0x1F);
                dy = 0x10 - (random_byte() & 0x1F);
                t = dy + 8;
                tx = background_objects[0].x_pos.u.hi + 0x10;
                func_800F4664(x + tx,
                              background_objects[0].y_pos.i.hi + (y + t));
                x = 0x10 - (random_byte() & 0x1F);
                dy = 0x10 - (random_byte() & 0x1F);
                t = dy + 8;
                tx = background_objects[0].x_pos.u.hi + 0x130;
                func_800F4664(x + tx,
                              background_objects[0].y_pos.i.hi + (y + t));
            }
            func_80027BA0(0, background_objects[0].x_pos.i.hi,
                          background_objects[0].y_pos.i.hi, D_800FC9C0);
            func_80027BA0(0, background_objects[0].x_pos.i.hi + 0x120,
                          background_objects[0].y_pos.i.hi, &D_800FC9C0[8]);
            D_800FD51F = 0;
            background_objects[0].unk4C = 1;
            D_800FD521 = 0;
        }
        goto block_14;
    }
    switch (M2C_FIELD(arg0, s8*, 2)) {
    case 0x11:
    case 0x12:
    case 0x13:
        if (D_800FD51E == 0) {
            break;
        }
        M2C_FIELD(arg0, u16*, 0xA) =
            background_objects[0].x_pos.u.hi + M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) =
            background_objects[0].y_pos.u.hi + M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(arg0, s8*, 3) = 0;
        ((void (*)(void*))func_80049E50)(arg0);
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        ((void (*)(s32, void*, void*))func_800477E4)(4, &D_800FC99C, arg0);
        goto block_14;
    case 0x20:
        if (D_800FD51E == 0) {
            break;
        }
    block_14:
        M2C_FIELD(arg0, s8*, 4) = 3;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    ((void (*)(void*))func_80017A04)(arg0);
    D_800FCAF4[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (check_enemy_hits(arg0) < 0) {
        switch (M2C_FIELD(arg0, s8*, 2) & 0xF0) {
        case 0x10:
            D_800FD522 -= 1;
            M2C_FIELD(arg0, u16*, 0xA) =
                background_objects[0].x_pos.u.hi + M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(arg0, u16*, 0xE) =
                background_objects[0].y_pos.u.hi + M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, s8*, 3) = 0;
            ((void (*)(void*))func_80049E50)(arg0);
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            ((void (*)(s32, void*, void*))func_800477E4)(4, &D_800FC99C, arg0);
            M2C_FIELD(arg0, s8*, 4) = 3;
            return;
        case 0x30:
            ((void (*)(void*, s32))set_animation)(arg0, 0x41);
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            ((void (*)(void*))func_80049E50)(arg0);
            ((void (*)(s32, void*, void*))func_800477E4)(4, &D_800FC9A0, arg0);
            M2C_FIELD(arg0, s8*, 6) = 4;
            D_800FD521 -= 1;
            return;
        }
    }
    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) != 0x20) {
        ((void (*)(void*))func_80030ECC)(arg0);
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
void func_800F4254(void* arg0, u8 arg1);
M2C_UNK func_800F4534(void*, M2C_UNK);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF0EC(void* arg0) {
    s32 angle;
    s32 t;
    s32 d;
    s32 x;

    x = 0xA0;
    angle = ratan2(F(s16, 0xE) - 0x20, x - F(s16, 0xA));
    F(s32, 0x20) = rcos(angle) << 5;
    F(s32, 0x24) = rsin(angle) << 5;
    move_object(arg0);
    t = F(s16, 0xA);
    d = x - t;
    if (d >= 0) {
        if (d < 3) {
            goto L1;
        }
        return;
    }
    if (t - 0xA0 < 3) {
    L1:
        t = F(s16, 0xE);
        d = 0x20 - t;
        if (d >= 0) {
            if (d < 3) {
                goto L2;
            }
            return;
        }
        if (t - 0x20 < 3) {
        L2:
            func_800F4254(arg0, 0x20);
            func_800F4534(arg0, 0);
            {
                // !FAKE: depin: dropping it breaks the match (62/70)
                register s32 b asm("$4") = F(u8, 0x6);
                F(s16, 0xA) = 0xA0;
                F(s16, 0xE) = 0x20;
                F(s16, 0x8A) = 0x168;
                F(u8, 0x7) = 0;
                F(u8, 0x6) = b + 1;
            }
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800FD514;
extern s8 D_800FD51B;
extern s8 D_800FD51E;
extern u8 D_800FD522;
#define D_800FD522 (*(s8*)&D_800FD522)
extern s16 D_800FD526;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF204(void* arg0) {
    s32 m;

    F(s16, 0xE) = ((-rsin(F(s16, 0x7E)) * 6) >> 12) + 0x20;
    F(s16, 0x7E) += 0x14;
    m = D_800FD514;
    if (m == 3 && (--F(s16, 0x8A) == 0 || (u16)D_800FD526 < 0xB)) {
        D_800FD51B = 0;
        D_800FD51E = 1;
        F(s8, 0x6) = m;
        return;
    }
    if (D_800FD522 == 0) {
        D_800FD51B = 0;
        D_800FD51E = 1;
        F(s8, 0x6) = 3;
        return;
    }
    if (D_800FD51B == -1) {
        F(s16, 0x7C) = 0x3C;
        F(u8, 0x6) += 1;
    }
}

#undef D_800FD522

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern s8 D_800FD51B;
extern s8 D_800FD51E;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF304(void* arg0) {
    s32 angle;
    s32 t;
    s32 d;
    s32 x;

    x = 0xA0;
    angle = ratan2(F(s16, 0xE) - 0x48, x - F(s16, 0xA));
    F(s32, 0x20) = rcos(angle) << 5;
    F(s32, 0x24) = rsin(angle) << 5;
    move_object(arg0);
    t = F(s16, 0xA);
    d = x - t;
    if (d >= 0) {
        if (d < 3) {
            // !FAKE: goto: matched twin func_800EF0EC block order
            goto L1;
        }
        return;
    }
    if (t - 0xA0 < 3) {
    L1:
        t = F(s16, 0xE);
        d = 0x48 - t;
        if (d >= 0) {
            if (d < 3) {
                // !FAKE: goto: matched twin func_800EF0EC block order
                goto L2;
            }
            return;
        }
        if (t - 0x48 < 3) {
        L2:
            F(s16, 0xA) = 0xA0;
            F(s16, 0xE) = 0x48;
            D_800FD51E = 0;
            D_800FD51B = -3;
            F(u8, 0x4) = 3;
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern u8 D_800E9884[];

#define F(type, off) M2C_FIELD(arg0, type*, off)

// str 0x800E9884 sha1=cc02398329fa039d76fae5aa30b17ad91bc6c29c = "rising byte ramp: a table, not text"
void func_800EF408(void* arg0) {
    s8 a[16];
    s32 angle;
    s32 v;
    s32 t;
    s32 x;
    s32 y;
    s32 d;

    __builtin_memcpy(a, D_800E9884, 16);
    switch (F(u8, 0x2) & 0xF) {
    case 1:
        x = 0x120;
        y = 0x60;
        break;
    case 2:
        x = 0x20;
        y = 0x20;
        break;
    case 3:
        x = 0x50;
        y = 0xB0;
        break;
    }
    angle = ratan2(F(s16, 0xE) - y, x - F(s16, 0xA));
    v = rcos(angle) * 16;
    F(s32, 0x20) = v * 2 + v;
    v = rsin(angle) * 16;
    F(s32, 0x24) = v * 2 + v;
    move_object(arg0);
    t = F(s16, 0xA);
    d = x - t;
    if (d >= 0) {
        if (d < 4) {
            goto L1;
        }
        return;
    }
    if (t - x < 4) {
    L1:
        t = F(s16, 0xE);
        d = y - t;
        if (d >= 0) {
            if (d < 4) {
                goto L2;
            }
            return;
        }
        if (t - y < 4) {
        L2:
            F(s16, 0xA) = x;
            F(s16, 0xE) = y;
            F(u8, 0x6)++;
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_800F1A90(void* self, u8 arg1);
M2C_UNK func_800F4534(void*, M2C_UNK);
extern u8 D_800E9884[];
extern u8 D_800E9894[];
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51B;

#define F(type, off) M2C_FIELD(arg0, type*, off)

// str 0x800E9884 sha1=cc02398329fa039d76fae5aa30b17ad91bc6c29c = "rising byte ramp: a table, not text"
// str 0x800E9894 sha1=2d16eed36913e36e5b0f303d1c288f5e234839b2 = "tail of the same byte ramp"
void func_800EF5B8(void* arg0) {
    s8 a[16];
    s8 b[16];
    u16 ang;
    s16 y;
    s32 t;
    s16 px;
    s16 py;

    __builtin_memcpy(a, D_800E9884, 16);
    __builtin_memcpy(b, D_800E9894, 16);
    px = D_800FD516;
    py = D_800FD518;
    ang = ratan2(F(s16, 0xE) - py, px - F(s16, 0xA)) & 0xFFF;
    F(s16, 0x88) = ang;
    ((void (*)(void*, s32, s32))set_animation_frame)(
        arg0, a[ang >> 8], D_80097420.frame_counter & 1);
    t = F(u8, 0x2) & 0xF;
    switch (t) {
    case 1:
        y = ((-rsin(F(s16, 0x7E)) * 8) >> 12) + 0x60;
        F(s16, 0xE) = y;
        break;
    case 2:
        y = ((-rsin(F(s16, 0x7E)) * 8) >> 12) + 0x20;
        F(s16, 0xE) = y;
        break;
    case 3:
        y = ((-rsin(F(s16, 0x7E)) * 8) >> 12) + 0xB0;
        F(s16, 0xE) = y;
        break;
    }
    F(s16, 0x7E) += 0x1E;
    if (D_800FD51B == 2) {
        set_animation(arg0, b[F(s16, 0x88) >> 8]);
        func_800F1A90(arg0, 0x10);
        func_800F4534(arg0, 0x10);
        func_800F4534(arg0, 0x11);
        func_800F4534(arg0, 0x12);
        func_800F4534(arg0, 0x13);
        {
            // !FAKE: depin: dropping it breaks the match (140/145)
            register s32 n asm("$2") = F(u8, 0x6);
            F(s16, 0x7C) = 0x32;
            F(u8, 0x6) = n + 1;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
void func_800F41D0(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FC9B0[];
extern s8 D_800FD51C;
extern s8 D_800FD51F;
extern s8 D_800FD521;

#define F(type, off) M2C_FIELD(self, type*, off)
#define G(type, off) (*(type*)(p + (off)))

void func_800EF7FC(void* self) {
    s16 v;
    u8* p;

    if (--F(s16, 0x7C) == 0) {
        D_800FD51F++;
        F(s16, 0x7C) = 3;
        func_800F41D0(self, 0x20, background_objects[0].x_pos.u.hi + 0x10,
                      background_objects[0].y_pos.u.hi + 8 + D_800FD51F * 0x10);
        func_800F41D0(self, 0x20, background_objects[0].x_pos.u.hi + 0x130,
                      background_objects[0].y_pos.u.hi + 8 + D_800FD51F * 0x10);
        p = D_800FC9B0;
        v = 0x3B0 - (D_800FD51F - 1) * 0x10;
        G(s16, 0x2) = v;
        G(s16, 0xA) = v;
        G(s16, 0x6) = D_800FD51F;
        G(s16, 0xE) = D_800FD51F;
        func_80027BA0(0, background_objects[0].x_pos.i.hi,
                      background_objects[0].y_pos.i.hi, p);
        func_80027BA0(0, background_objects[0].x_pos.i.hi + 0x120,
                      background_objects[0].y_pos.i.hi, p + 8);
        background_objects[0].unk4C = 1;
        if (D_800FD51F == 0xF) {
            func_80012D9C(5);
            play_sound(2, 0x35, self);
            D_800FD51C = 1;
            F(s16, 0x7C) = 0;
            F(s16, 0x7E) = 0;
            F(s8, 0x88) = 0;
            D_800FD521 = 0;
            F(u8, 0x6)++;
        }
    }
}

#undef F
#undef G

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
void func_800F4328(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800E98A4[];

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800EF98C(void* arg0) {
    s16 t[8][2];
    s32 i;

    __builtin_memcpy(t, D_800E98A4, 32);
    if (!(F(u16, 0x7C) & 7)) {
        i = F(s16, 0x7C) >> 3;
        func_800F4328(arg0, (i + 0x31) & 0xFF,
                      background_objects[0].x_pos.i.hi + t[i][0],
                      background_objects[0].y_pos.i.hi + t[i][1]);
    }
    if (++F(s16, 0x7C) == 0x39) {
        F(s8, 0x8C) = random_byte() & 3;
        F(u8, 0x8D) = 0;
        F(s16, 0x7C) = 0x5A;
        F(u8, 0x6)++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 random_byte();
void func_800F4664(s16 arg0, s16 arg1);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FC9C0[];
extern s8 D_800FD51C;
extern s8 D_800FD51F;
extern s8 D_800FD520;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EFAE4(void* self) {
    s32 i;
    s32 row;
    s16 x;
    s32 y;

    i = 0;
    D_800FD520 = 0;
    D_800FD51C = 0;
    for (; i < D_800FD51F / 2 + 1;) {
        row = i << 5;
        x = 0x10 - (random_byte() & 0x1F);
        y = (s16)(0x10 - (random_byte() & 0x1F)) + 8;
        func_800F4664(x + (s16)(background_objects[0].x_pos.u.hi + 0x10),
                      background_objects[0].y_pos.i.hi + (row + y));
        i++;
        x = 0x10 - (random_byte() & 0x1F);
        y = (s16)(0x10 - (random_byte() & 0x1F)) + 8;
        func_800F4664(x + (s16)(background_objects[0].x_pos.u.hi + 0x130),
                      background_objects[0].y_pos.i.hi + (row + y));
    }
    func_80027BA0(0, background_objects[0].x_pos.i.hi,
                  background_objects[0].y_pos.i.hi, D_800FC9C0);
    func_80027BA0(0, background_objects[0].x_pos.i.hi + 0x120,
                  background_objects[0].y_pos.i.hi, D_800FC9C0 + 8);
    D_800FD51F = 0;
    background_objects[0].unk4C = 1;
    F(s16, 0x7C) = 0x42;
    F(u8, 0x6)++;
}

#undef F

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
s32 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800F402C(void*, s32);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51A;
extern s8 D_800FD51B;

#define F(type, off) M2C_FIELD(self, type*, off)

static inline u8 tile_hit_800EFCC0(s32 c) {
    if (c == 0) {
        return 0;
    }
    if (c >= 0) {
        if (c < 0x30) {
            if (c >= 0x25) {
                return 0;
            }
            return 1;
        }
    }
    return 1;
}

void func_800EFCC0(struct X4_PlayerObj* self) {
    s32 n;
    s32 c;
    u8 hit;
    s32 d;
    s32 x;
    s32 y;
    s16 t;

    n = 0;
    self->bg_offset = 0;
    self->x_pos.u.hi = F(u16, 0x84);
    self->y_pos.u.hi = F(u16, 0x86);
    self->x_pos.u.hi = background_objects[0].x_pos.u.hi + self->x_pos.u.hi;
    self->y_pos.u.hi = background_objects[0].y_pos.u.hi + self->y_pos.u.hi;
    self->x_vel.val = rcos(F(s16, 0x7C)) << 7;
    self->y_vel.val = rsin(F(s16, 0x7C)) << 7;
    do {
        move_object(self);
        c = func_80030234(self, self->x_pos.i.hi, self->y_pos.i.hi) & 0xFF;
        hit = tile_hit_800EFCC0(c);
        if (hit) {
            n = 1000;
        }
        if ((u32)(self->x_pos.i.hi - background_objects[0].x_pos.i.hi + 0x10) >=
                0x161 ||
            (d = self->y_pos.i.hi - background_objects[0].y_pos.i.hi,
             d < -0x10) ||
            d > 0x100) {
            n = 1000;
        }
        n++;
    } while (n < 0x46);
    self->bg_offset = -1;
    x = self->x_pos.u.hi - background_objects[0].x_pos.u.hi;
    self->x_pos.u.hi = x;
    t = F(s16, 0x7E);
    y = self->y_pos.u.hi - background_objects[0].y_pos.u.hi;
    self->y_pos.u.hi = y;
    D_800FD516 = x;
    D_800FD518 = y;
    if (t != 0) {
        F(s16, 0x7C) -= 0x14;
        if (F(s16, 0x7C) < 0xA01) {
            F(s16, 0x7E) = 0;
            return;
        }
    } else {
        F(s16, 0x7C) += 0x14;
        if (F(s16, 0x7C) >= 0xE00) {
            F(s16, 0x7E) = 1;
        }
    }
    if (D_800FD51B == 0) {
        self->on_screen = 1;
        func_800F402C(self, 4);
    } else if (D_800FD51B == 1) {
        u16 v;
        self->bg_offset = -1;
        D_800FD516 = v = g_Player.x_pos.u.hi - background_objects[0].x_pos.u.hi;
        D_800FD518 = g_Player.y_pos.u.hi - background_objects[0].y_pos.u.hi;
        self->x_pos.u.hi = v;
        self->y_pos.u.hi =
            g_Player.y_pos.u.hi - background_objects[0].y_pos.u.hi;
        func_800F402C(self, 4);
        F(s16, 0x7C) = 0x3C;
        self->unk6++;
    }
    D_800FD51A = self->on_screen;
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800EFF50);

INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F0050);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern struct X4_PlayerObj g_Player;
extern s32 D_800FCBA4;
extern s32 D_800FCBA8;
extern s8 D_800FD51D;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F013C(void* arg0) {
    s32 t;
    u16 x;

    F(u8, 0x5C) = 0;
    F(u8, 0x3) = 0;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x16) = 4;
    F(u8, 0x67) = 1;
    F(void*, 0x50) = 0;
    F(s32, 0x54) = 0;
    F(s32, 0x68) = 0;
    if (D_800FD51D != 0) {
        F(u8, 0x3) = 0;
        F(u8, 0x4)++;
        return;
    }
    t = F(s8, 0x2) & 0xF0;
    switch (t) {
    case 0:
        F(u8, 0x60) = 4;
        F(u8, 0x16) = 4;
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, 0x20, 0xA);
        F(s8, 0x14) = -1;
        F(s16, 0x88) = 0;
        F(s16, 0xA) = 0xA0;
        F(s16, 0xE) = 0x38;
        {
            s32 py;
            struct X4_PlayerObj* pl = &g_Player;
            F(s16, 0x8C) = pl->x_pos.u.hi;
            py = pl->y_pos.u.hi;
            F(u8, 0x5) = 0;
            F(s16, 0x8E) = py;
        }
        ((void (*)(s32, s32, void*))play_sound)(2, 0x30, arg0);
        break;
    case 0x10:
        F(u8, 0x60) = 6;
        F(u8, 0x3) = 0;
        F(s16, 0x88) = 3;
        F(u8, 0x5) = 1;
        break;
    case 0x20:
        F(void*, 0x50) = &D_800FCBA4;
        F(u8, 0x62) = 5;
        F(u8, 0x3) = 0;
        F(u8, 0x60) = 4;
        F(s16, 0x88) = 6;
        F(u8, 0x5) = 2;
        break;
    case 0x30:
        ((void (*)(s32, s32, void*))play_sound)(2, 0x3A, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0x3E);
        x = F(u16, 0xA);
        F(u8, 0x16) = 0x22;
        F(u16, 0x8C) = x;
        if (F(u8, 0x15) == 0) {
            F(u16, 0xA) = x + 0x80;
        } else {
            F(u16, 0xA) = x - 0x80;
        }
        F(u8, 0x3) = 1;
        F(u8, 0x60) = 4;
        F(void*, 0x50) = &D_800FCBA8;
        F(s16, 0x88) = 6;
        F(u8, 0x5) = 3;
        break;
    }
    F(u8, 0x4) = 1;
    F(u8, 0x6) = 0;
    F(u8, 0x7) = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
void func_800F40F4(u8* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FCB9C;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F0330(void* arg0) {
    s32 x;
    s32 y;
    s16 i;
    s16 j;

    F(u8, 0x3) = 1;
    x = ((s16)(F(u16, 0x8C) - background_objects[0].x_pos.u.hi) - 0xA0) *
            F(s16, 0x88) / 39 +
        0xA0;
    y = ((s16)(F(u16, 0x8E) - background_objects[0].y_pos.u.hi) - 0x38) *
            F(s16, 0x88) / 39 +
        0x38;
    F(s16, 0xA) = x;
    F(s16, 0xE) = y;
    ((void (*)(void*, s32, s16))set_animation_frame)(arg0, 0x20, F(s16, 0x88) / 3);
    j = F(s16, 0x88);
    for (i = 0; i < 5; i++) {
        j -= 2;
        if (j >= 0) {
            func_800F40F4(arg0, 3, j, 1);
        }
    }
    if (F(s16, 0x88) == 0x27) {
        F(void*, 0x50) = &D_800FCB9C;
        F(s16, 0x88) = 0;
        F(u8, 0x14) = 0;
        F(s16, 0xA) = F(s16, 0x8C);
        F(s16, 0xE) = F(s16, 0x8E);
        F(u8, 0x6)++;
        return;
    }
    F(s16, 0x88)++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);

void func_800F04E0(struct X4_BaseObj* self) {
    struct X4_BaseObj* parent;
    s32 v;
    s8 step;

    parent = *(struct X4_BaseObj**)((u8*)self + 0x7C);
    if (parent->on_screen != 0 && *(s32*)((u8*)parent + 0x54) != 0) {
        step = self->unk6;
        if (step == 0) {
            v = self->unk15;
            if (v != 0) {
                v = 0xC0000;
            } else {
                v = 0xFFF40000;
            }
            *(s32*)((u8*)self + 0x20) = v;
            goto next;
        } else if (step == 1) {
            if (self->unk15 == 0) {
                if (*(s16*)((u8*)self + 0x8C) - 0x84 >= self->x_pos.i.hi) {
                    self->x_pos.i.hi = *(s16*)((u8*)self + 0x8C) - 0x84;
                } else {
                    move_object(self);
                }
            } else if (self->x_pos.i.hi >= *(s16*)((u8*)self + 0x8C) + 0x84) {
                self->x_pos.i.hi = *(s16*)((u8*)self + 0x8C) + 0x84;
            } else {
                move_object(self);
            }
            if (parent->unk6 == 1) {
                set_animation(self, 0x3F);
            next:
                self->unk6++;
            }
            return;
        } else if (step == 2) {
            if (*(s8*)((u8*)self + 0x45) == 1) {
                goto off;
            }
        }
        return;
    }
off:
    self->on_screen = 0;
    self->state++;
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F062C);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002A47C(s32);

void func_800F0DE0(void* arg0) {
    void* p;

    p = M2C_FIELD(arg0, void**, 0x50);
    if (M2C_FIELD(p, u8*, 7) & 1) {
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) += 1;
        return;
    }
    M2C_FIELD(arg0, s16*, 0xA) =
        M2C_FIELD(p, s16*, 0xA) + M2C_FIELD(arg0, s16*, 8);
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(p, s16*, 0xE) + M2C_FIELD(arg0, s16*, 0xC);
    switch (M2C_FIELD(arg0, s8*, 0x45)) {
    case 1:
        M2C_FIELD(arg0, s16*, 0x42) =
            (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 2) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 10) / 4 + 0x1E0) << 6);
        break;
    case 2:
        M2C_FIELD(arg0, s16*, 0x42) =
            (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 3) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 11) / 4 + 0x1E0) << 6);
        break;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F0F30);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F1048(void* arg0) {
    struct X4_BackgroundObj* bg;
    s16 k;
    s32 x;
    s32 y;

    bg = background_objects;
    F(s8, 0x3) = 1;
    x = (s16)(F(s16, 0x8) - bg->x_pos.i.hi) - 0xA0;
    k = F(s16, 0x54);
    x *= k;
    y = ((s16)(F(s16, 0xC) - bg->y_pos.i.hi) - 0x38) * k;
    F(s16, 0xA) = x / 39 + 0xA0;
    F(s16, 0xE) = y / 39 + 0x38;
    ((void (*)(void*, s32, s16))set_animation_frame)(arg0, 0x20, F(s16, 0x54) / 3);
    if (F(s16, 0x56) == 0) {
        F(u8, 0x4)++;
    } else {
        F(s16, 0x56)--;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F4588(void* arg0, s32 arg1);
extern s16 D_800971EC;
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51A;
extern s8 D_800FD51B;

#define F(type, off) M2C_FIELD(arg0, type*, off)
#define SH(off) (((X4_f32*)arg0)[((off) - 2) / 4].i.hi)
#define PF(off) M2C_FIELD(parent, s16*, off)

void func_800F116C(void* arg0) {
    void* parent;
    s8 t;

    parent = F(void*, 0x5C);
    if (D_800971EC != 0) {
        play_sound(2, 0x32, arg0);
    }
    SH(0x16) = PF(0xA) - 2;
    SH(0x1A) = PF(0xE) - 0xE;
    SH(0x1E) = PF(0xA) + 2;
    SH(0x22) = PF(0xE) - 0xE;
    SH(0x26) = D_800FD516 - 2;
    SH(0x2A) = D_800FD518;
    SH(0x2E) = D_800FD516 + 2;
    SH(0x32) = D_800FD518;
    t = D_800FD51B;
    if (t == 0) {
        // !FAKE: keeps the two equality tests apart instead of a range test
        goto on;
    }
    if (t == 1) {
    on:
        F(s8, 0x3) = D_800FD51A;
        if (F(s8, 0x3) != 0) {
            func_800F4588(arg0, 1);
        }
    } else {
        F(u8, 0x3) = 0;
        F(u8, 0x4) += 1;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800E99B4[];

void func_800F1264(void* self) {
    s16 tbl[16][2];
    X4_f32 px;
    X4_f32 py;
    void* parent;
    void* q;
    s32 ang;
    s32 a;
    s32 dx;
    s32 dy;
    s32 i;
    s32 ox;
    s32 oy;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;

    __builtin_memcpy(tbl, D_800E99B4, 0x40);
    parent = M2C_FIELD(self, void**, 0x5C);
    ang = (s16)M2C_FIELD(parent, u16*, 0x88);
    x0 = M2C_FIELD(parent, u16*, 0xA) + tbl[ang >> 8][0];
    y0 = M2C_FIELD(parent, u16*, 0xE) + tbl[ang >> 8][1];
    px.i.hi = x0;
    py.i.hi = y0;
    dx = rcos(ang) << 8;
    dy = -rsin(ang) << 8;
    i = 0;
    do {
        px.val += dx;
        py.val += dy;
        if ((u16)(px.i.hi + 0x10) >= 0x161 || py.i.hi < -0x10 ||
            py.i.hi >= 0x101) {
            i = 1000;
        }
        i++;
    } while (i < 50);
    x1 = px.i.hi;
    y1 = py.i.hi;

    switch (M2C_FIELD(self, u8*, 0x2) & 0xF) {
    case 0:
        a = ang - 0x400;
        a &= 0xFFF;
        ox = (rcos(a) * 0x60) >> 16;
        oy = (-rsin(a) * 0x60) >> 16;
        M2C_FIELD(self, s16*, 0x16) = x0 + ox;
        M2C_FIELD(self, s16*, 0x1A) = y0 + oy;
        M2C_FIELD(self, s16*, 0x1E) = x0;
        M2C_FIELD(self, s16*, 0x22) = y0;
        M2C_FIELD(self, s16*, 0x26) = x1;
        M2C_FIELD(self, s16*, 0x2A) = y1;
        M2C_FIELD(self, s16*, 0x2E) = x1 + ox;
        M2C_FIELD(self, s16*, 0x32) = y1 + oy;
        break;
    case 1:
        a = ang + 0x400;
        a &= 0xFFF;
        ox = (rcos(a) * 0x60) >> 16;
        oy = (-rsin(a) * 0x60) >> 16;
        M2C_FIELD(self, s16*, 0x1E) = x0 + ox;
        M2C_FIELD(self, s16*, 0x22) = y0 + oy;
        M2C_FIELD(self, s16*, 0x16) = x0;
        M2C_FIELD(self, s16*, 0x1A) = y0;
        M2C_FIELD(self, s16*, 0x26) = x1 + ox;
        M2C_FIELD(self, s16*, 0x2A) = y1 + oy;
        M2C_FIELD(self, s16*, 0x2E) = x1;
        M2C_FIELD(self, s16*, 0x32) = y1;
        break;
    case 2:
        a = ang - 0x400;
        a &= 0xFFF;
        ox = (rcos(a) * 0x80) >> 16;
        oy = (-rsin(a) * 0x80) >> 16;
        M2C_FIELD(self, s16*, 0x16) = x0 + ox;
        M2C_FIELD(self, s16*, 0x1A) = y0 + oy;
        M2C_FIELD(self, s16*, 0x1E) = x0;
        M2C_FIELD(self, s16*, 0x22) = y0;
        M2C_FIELD(self, s16*, 0x26) = x1;
        M2C_FIELD(self, s16*, 0x2A) = y1;
        M2C_FIELD(self, s16*, 0x2E) = x1 + ox;
        M2C_FIELD(self, s16*, 0x32) = y1 + oy;
        break;
    case 3:
        a = ang + 0x400;
        a &= 0xFFF;
        ox = (rcos(a) * 0x80) >> 16;
        oy = (-rsin(a) * 0x80) >> 16;
        M2C_FIELD(self, s16*, 0x1E) = x0 + ox;
        M2C_FIELD(self, s16*, 0x22) = y0 + oy;
        M2C_FIELD(self, s16*, 0x16) = x0;
        M2C_FIELD(self, s16*, 0x1A) = y0;
        M2C_FIELD(self, s16*, 0x26) = x1 + ox;
        M2C_FIELD(self, s16*, 0x2A) = y1 + oy;
        M2C_FIELD(self, s16*, 0x2E) = x1;
        M2C_FIELD(self, s16*, 0x32) = y1;
        break;
    }

    switch ((u32)D_80097420.frame_counter % 3) {
    case 0:
        M2C_FIELD(self, u8*, 0x3) = 1;
        M2C_FIELD(self, u8*, 0x0) = 3;
        break;
    case 1:
        M2C_FIELD(self, u8*, 0x3) = 0;
        break;
    case 2:
        M2C_FIELD(self, u8*, 0x3) = 1;
        M2C_FIELD(self, u8*, 0x0) = 0x13;
        break;
    }

    q = (s8*)self + 0x38;
    if ((M2C_FIELD(q, s16*, 0x10) = M2C_FIELD(self, u16*, 0x48) - 1) == 0) {
        M2C_FIELD(self, u16*, 0x48) = 0;
        M2C_FIELD(self, u8*, 0x6)++;
    }
    M2C_FIELD(self, s16*, 0x44) = x0;
    M2C_FIELD(self, s16*, 0x46) = y0;
    M2C_FIELD(self, s16*, 0x40) = x1;
    M2C_FIELD(self, s16*, 0x42) = y1;
}

#include "common.h"
#include "psyq/libgte.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800E99F4[];

void func_800F166C(void* self) {
    s8 tbl[20][2];
    s16 s;
    s32 c;
    s16 t;
    s32 m;
    s16 x40;
    s16 x42;
    s16 x44;
    s16 x46;
    s32 v;

    __builtin_memcpy(tbl, D_800E99F4, sizeof(tbl));
    switch (M2C_FIELD(self, u8*, 2) & 0xF) {
    case 0:
        s = (rcos((M2C_FIELD(self, s32*, 0x3C) - 0x400) & 0xFFF) *
             tbl[M2C_FIELD(self, s16*, 0x48)][0] * 16) >>
            16;
        c = rsin((M2C_FIELD(self, s32*, 0x3C) - 0x400) & 0xFFF);
        M2C_FIELD(self, s16*, 0x16) = s + M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x1E) = M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x22) = M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x2A) = M2C_FIELD(self, s16*, 0x42);
        M2C_FIELD(self, s16*, 0x26) = M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x2E) = s + M2C_FIELD(self, s16*, 0x40);
        t = (-c * tbl[M2C_FIELD(self, s16*, 0x48)][0] * 16) >> 16;
        M2C_FIELD(self, s16*, 0x1A) = t + M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x32) = t + M2C_FIELD(self, s16*, 0x42);
        break;
    case 1:
        s = (rcos((M2C_FIELD(self, s32*, 0x3C) + 0x400) & 0xFFF) *
             tbl[M2C_FIELD(self, s16*, 0x48)][0] * 16) >>
            16;
        c = rsin((M2C_FIELD(self, s32*, 0x3C) + 0x400) & 0xFFF);
        t = (-c * tbl[M2C_FIELD(self, s16*, 0x48)][0] * 16) >> 16;
        M2C_FIELD(self, s16*, 0x1A) = M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x16) = M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x1E) = s + M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x26) = s + M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x2E) = M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x22) = t + M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x2A) = t + M2C_FIELD(self, s16*, 0x42);
        M2C_FIELD(self, s16*, 0x32) = M2C_FIELD(self, s16*, 0x42);
        break;
    case 2:
        s = (rcos((M2C_FIELD(self, s32*, 0x3C) - 0x400) & 0xFFF) *
             tbl[M2C_FIELD(self, s16*, 0x48)][1] * 16) >>
            16;
        c = rsin((M2C_FIELD(self, s32*, 0x3C) - 0x400) & 0xFFF);
        M2C_FIELD(self, s16*, 0x16) = s + M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x1E) = M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x22) = M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x2A) = M2C_FIELD(self, s16*, 0x42);
        M2C_FIELD(self, s16*, 0x26) = M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x2E) = s + M2C_FIELD(self, s16*, 0x40);
        t = (-c * tbl[M2C_FIELD(self, s16*, 0x48)][1] * 16) >> 16;
        M2C_FIELD(self, s16*, 0x1A) = t + M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x32) = t + M2C_FIELD(self, s16*, 0x42);
        break;
    case 3:
        s = (rcos((M2C_FIELD(self, s32*, 0x3C) + 0x400) & 0xFFF) *
             tbl[M2C_FIELD(self, s16*, 0x48)][1] * 16) >>
            16;
        c = rsin((M2C_FIELD(self, s32*, 0x3C) + 0x400) & 0xFFF);
        t = (-c * tbl[M2C_FIELD(self, s16*, 0x48)][1] * 16) >> 16;
        M2C_FIELD(self, s16*, 0x1A) = M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x16) = M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x1E) = s + M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x26) = s + M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x2E) = M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x22) = t + M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x2A) = t + M2C_FIELD(self, s16*, 0x42);
        M2C_FIELD(self, s16*, 0x32) = M2C_FIELD(self, s16*, 0x42);
        break;
    }
    switch ((u32)D_80097420.frame_counter % 3) {
    case 0:
        M2C_FIELD(self, u8*, 3) = 1;
        M2C_FIELD(self, u8*, 0) = 3;
        break;
    case 1:
        M2C_FIELD(self, u8*, 3) = 0;
        break;
    case 2:
        M2C_FIELD(self, u8*, 3) = 1;
        M2C_FIELD(self, u8*, 0) = 0x13;
        break;
    }
    if (++M2C_FIELD(self, s16*, 0x48) >= 21) {
        M2C_FIELD(self, u8*, 3) = 0;
        M2C_FIELD(self, u8*, 4)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F1A90 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002C458();
extern u32* D_80095098;

#define F(type, off) M2C_FIELD(self, type*, off)
#define G(type, off) M2C_FIELD(obj, type*, off)

M2C_UNK func_800F1A90(void* self, u8 arg1) {
    s32 a;
    s32 b;
    void* obj;
    s32 k;
    // !FAKE: depin: dropping it breaks the match (84/86)
    register s32 t asm("$4");

    obj = func_8002C458();
    {
        // !FAKE: depin: dropping it breaks the match (84/86)
        register s32 k2 asm("$2") = 0x41;
        if (obj != 0) {
            // !FAKE: depin: dropping it breaks the match (83/86)
            register s32 k3 asm("$3") = 0x1C;
            G(u8, 0) = k2;
            G(u8, 1) = k3;
            t = F(u8, 0x15);
            G(void*, 0x7C) = self;
            G(u8, 2) = arg1;
            G(u8, 0x15) = t;
            G(u16, 0xA) = F(u16, 0xA);
            G(u16, 8) = 0;
            G(u16, 0xE) = F(u16, 0xE);
            G(u16, 0xC) = 0;
            G(s32, 0x30) = F(s32, 0x30);
            G(u8, 0x14) = F(u8, 0x14);
            G(u16, 0x40) = F(u16, 0x40) + 0x400;
            G(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;
            a = func_8002A47C(F(s8, 1));
            b = func_8002A47C(F(s8, 1));
            a = (a + 1) * 4;
            G(s16, 0x42) = ((a + 0x20) % 16) | (((b + 9) / 4 + 0x1E0) << 6);
            G(u8*, 0x3C) = (u8*)SPAD20_800F1A90 +
                           SPAD20_800F1A90[func_8002A47C(F(s8, 1)) + 1];
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1DC4(void* arg0, s32 arg1);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEED;
extern void* D_800FD510;
extern s8 D_800FD514;
extern s8 D_800FD51D;
extern s16 D_800FD526;
extern s16 D_800FD52A;

void func_800F1BE8(void* arg0) {
    switch (D_800FD514) {
    case 0:
        if (background_objects[0].x_pos.i.hi >= 0x800) {
            D_800FD514++;
            background_objects[0].unk26 = 0x800;
            D_800FD52A = background_objects[0].unk28;
            background_objects[0].unk2A = 0x180;
            background_objects[0].unk28 = 0x180;
            M2C_FIELD(arg0, s8*, 0x89) = 1;
            M2C_FIELD(arg0, s8*, 0x5C) = 1;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
        } else if (M2C_FIELD(arg0, s8*, 0x5) != 2) {
            func_800F1DC4(arg0, 0);
        }
        break;
    case 1:
        if (M2C_FIELD(D_800FD510, s8*, 0x5C) == 0) {
            D_800FD514++;
            D_800FD51D = 1;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s8*, 0x5) = 8;
            M2C_FIELD(arg0, s8*, 0x6) = 0;
        }
        func_800F1DC4(arg0, 1);
        break;
    case 2:
        if (background_objects[0].x_pos.i.hi >= 0x1080) {
            D_800FD514++;
            D_800FD526 = 0;
            background_objects[0].unk26 = 0x1080;
            D_800FD52A = background_objects[0].unk28;
            background_objects[0].unk2A = 0x300;
            background_objects[0].unk28 = 0x300;
            M2C_FIELD(arg0, s8*, 0x89) = 1;
            M2C_FIELD(arg0, s8*, 0x5C) = 1;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
        }
        func_800F1DC4(arg0, 0);
        break;
    case 3:
        D_800FD526++;
        if (M2C_FIELD(D_800FD510, s8*, 0x5C) == 0) {
            D_800CCEED = 2;
            D_800FD514++;
            D_800FD51D = 1;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s8*, 0x5) = 9;
            M2C_FIELD(arg0, s8*, 0x6) = 0;
        }
        break;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F1DC4 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* enemy_slot_alloc();
s32 random_byte();
extern s8 g_enemies[];
extern u32* D_80095098;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800E9A1C[];

void func_800F1DC4(void* arg0, s32 arg1) {
    s16 offs[2][2];
    s32 sel;
    u8 t;
    void* obj;
    s8* p;

    __builtin_memcpy(offs, D_800E9A1C, 8);
    if ((s8)arg1 == 0) {
        sel = 1;
    } else {
        sel = random_byte() & 1;
    }
    t = M2C_FIELD(arg0, u8*, 0x84);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x84) = --t;
        if (t == 0) {
            obj = enemy_slot_alloc();
            if (obj != 0) {
                M2C_FIELD(obj, u8*, 0) = 0x41;
                M2C_FIELD(obj, u8*, 1) = 8;
                M2C_FIELD(obj, u8*, 2) = 0;
                M2C_FIELD(obj, s16*, 0xA) =
                    background_objects[0].x_pos.i.hi + offs[sel][0];
                M2C_FIELD(obj, s16*, 8) = 0;
                M2C_FIELD(obj, s16*, 0xE) =
                    background_objects[0].y_pos.i.hi + offs[sel][1];
                M2C_FIELD(obj, s16*, 0xC) = 0;
                M2C_FIELD(obj, u16*, 0x40) = D_80095098[func_8002A47C(8)] >> 7;
                M2C_FIELD(obj, s16*, 0x42) =
                    ((func_8002A47C(M2C_FIELD(obj, s8*, 1)) * 4 + 0x20) % 16) |
                    (((func_8002A47C(M2C_FIELD(obj, s8*, 1)) + 8) / 4 + 0x1E0)
                     << 6);
                M2C_FIELD(obj, u8**, 0x3C) =
                    (u8*)SPAD20_800F1DC4 +
                    SPAD20_800F1DC4[func_8002A47C(M2C_FIELD(obj, s8*, 1))];
                M2C_FIELD(arg0, u8*, 0x84) = 0;
            }
        }
    } else {
        for (p = g_enemies; p < g_enemies + 0x1D40; p += 0x9C) {
            if (p[0] != 0 && p[1] == 8) {
                return;
            }
        }
        M2C_FIELD(arg0, u8*, 0x84) = 0x78;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F1FBC (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* enemy_slot_alloc();
extern u32* D_80095098;
extern s16 D_800FD526;

void func_800F1FBC(void) {
    void* obj;

    if ((u16)D_800FD526 < 0x1519U) {
        obj = enemy_slot_alloc();
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0) = 0x41;
            M2C_FIELD(obj, u8*, 1) = 0x1C;
            M2C_FIELD(obj, u8*, 2) = 1;
            M2C_FIELD(obj, s16*, 0xA) = 0x1120;
            M2C_FIELD(obj, s16*, 8) = 0;
            M2C_FIELD(obj, s16*, 0xE) = 0x360;
            M2C_FIELD(obj, s16*, 0xC) = 0;
            M2C_FIELD(obj, u16*, 0x40) = D_80095098[func_8002A47C(0x1C)] >> 7;
            M2C_FIELD(obj, s16*, 0x42) =
                ((func_8002A47C(M2C_FIELD(obj, s8*, 1)) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(obj, s8*, 1)) + 8) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(obj, u8**, 0x3C) =
                (u8*)SPAD20_800F1FBC +
                SPAD20_800F1FBC[func_8002A47C(M2C_FIELD(obj, s8*, 1))];
        }
    }
}

#define func_80048DC8 func_800F20D4
#define D_80077BC0 D_800FCA00
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#define func_80041AB8 func_800F2120
#define D_80075FD8 D_800FCBAC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009716C;
extern void (*D_800FCBE8[])(void*);

void func_800F215C(void* arg0) {
    if (D_8009716C == 0) {
        D_800FCBE8[M2C_FIELD(arg0, s8*, 0x4)](arg0);
        if (M2C_FIELD(arg0, s8*, 0x45) == -1) {
            M2C_FIELD(arg0, s8*, 0x3) = 0;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F21C0);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800F1BE8(void* arg0);
void func_800F3D24(u8* self);
extern void (*D_800FCA14[])(void*);
extern s8 D_800FD51D;

void func_800F2208(void* arg0) {
    s32 r;

    M2C_FIELD(arg0, s16*, 0xA) = 0xA0;
    M2C_FIELD(arg0, s16*, 0xE) = 0x88;
    func_80017A04();
    D_800FCA14[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800F3D24(arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        M2C_FIELD(arg0, s8*, 0x5C) = 0;
    } else if (r > 0 && r != 0x7F) {
        if (r == 7 || r == 0x10 || r == 0x2B) {
            if (M2C_FIELD(arg0, s8*, 5) != 0xA) {
                D_800FD51D = 1;
                M2C_FIELD(arg0, s8*, 5) = 0xA;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        }
    }
    func_80030ECC(arg0);
    func_800F1BE8(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F22DC(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800F22FC(void) {
    func_8002CA54();
}

#define func_8003744C func_800F231C
#define D_80073C1C D_800FCA40
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F2358(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
