#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_8001C5EC(u8);
M2C_UNK reset_level();
void func_800EFC74(u8** arg0);
s32 func_800EE95C(u8*, u8, s32);
#include "mmx6/state.h"
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E9860[];

void func_800EE878(struct X4_MiscObj* arg0) {
    s32 i;
    u8 id;
    u8* p;
    u8* buf;

    buf = *(u8**)arg0;
    id = arg0->unk6;
    p = buf;
    for (i = 0x1FF; i >= 0; i--) {
        *p++ = 0;
    }
    __builtin_memcpy(*(u8**)arg0, D_800E9860 + 0x18, 3);
    (*(u8**)arg0)[2] = 0x13;
    if ((arg0->x_pos.bytes[0] = func_8001C5EC(id)) != 0 ||
        (func_800EFC74((u8**)arg0),
         (arg0->x_pos.bytes[0] = func_800EE95C(buf, id, 0x2000)) != 0)) {
        g_playthrough_state.unk1 = 0x15;
        ((void (*)())reset_level)();
        D_80097420.transition.selection = 0;
        g_playthrough_state.unk3 = 0xD;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800EE95C);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800EE97C);
// clang-format on

#define func_80041AB8 func_800EE9E0
#define D_80075FD8 D_800F38C4
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80025F34();
s32 func_800280F4();
void init_checkpoint_positions(void);
M2C_UNK reset_level();
void func_8002C2B8();
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E3140;
extern u8 D_800E3141;
extern u8 D_800F366C[];

void func_800EEA1C(u8* arg0) {
    struct X4_EngineObj* e = &g_playthrough_state;
    u8 a = D_800E3141;
    u8 b = D_800E3140;

    e->character_state.bytes[0] = a;
    e->character_state.bytes[1] = b;
    *(u8*)(D_800F366C + 0x128A) = *(u8*)&e->controlled_player;
    do {
        reset_level(arg0, a, b);
    } while (0);
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    e->character_state.bytes[2] = 0;
    {
        struct X4_PlayerObj* pl = &g_Player;
        ((u8*)pl)[0xC9] = arg0[0x60];
        pl->unk2 = *(u8*)(D_800F366C + 0x128A);
    }
    arg0[2]++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK); /* extern */

void func_800EEAC4(void* arg0) {
    play_bgm_xa_track(6, 0x7F);
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139A0(M2C_UNK);
extern u8 D_800CD40C;

void func_800EEAFC(u8* arg0) {
    if (D_800CD40C == 2) {
        ((void (*)(s32))func_800139A0)(8);
        arg0[2]++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EEB44(void* arg0) {
    M2C_FIELD(arg0, s8*, 1) = 1;
    M2C_FIELD(arg0, s8*, 2) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
}

#define func_80041AB8 func_800EEB58
#define D_80075FD8 D_800F38D4
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

extern u8 D_800F366C[];

void func_800EEB94(u8* arg0) {
    u16* p;
    u16* t;
    u16 v;
    if (D_80097420.transition.active == 0) {
        p = (u16*)(D_800F366C + 0x1282);
        *p = 0;
        p = 0;
        t = (u16*)(D_800F366C + 0x44);
        v = t[(D_80097420.transition.active << 24) >> 31];
        t = 0;
        *(u16*)(D_800F366C + 0x1280) = v;
        arg0[2]++;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800EEBE8);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800EEC9C(u8* arg0) {
    ((void (*)(s32, s32, s32))open_text_box)(0, 0xFF, 0);
    arg0[2]++;
}

#include "../shared/rock_20/func_800EECD8.c"

#include "common.h"

extern s8 D_800CCEF6;

void func_800EED04(u8* arg0) {
    if ((u32)((u8)D_800CCEF6 - 1) < 8U) {
        arg0[1] = 2;
    } else {
        arg0[1] = 3;
    }
    arg0[2] = 0;
}

#define func_80041AB8 func_800EED30
#define D_80075FD8 D_800F38F0
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

s32 func_800F054C(void);

void func_800EED6C(u8* arg0) {
    if (func_800F054C() != 0) {
        arg0[2]++;
    } else {
        arg0[2] = 0xB;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800EEDAC);
// clang-format on

#include "../shared/rock_20/func_800EEE70.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_800CCEF6;
extern u8 D_800F366C[];

void func_800EEE9C(u8* arg0) {
    s32 i;
    u8* t = D_800F366C + 4;
    i = D_800CCEF6 - 1;
    ((void (*)(s32, s32, s32))open_text_box)(*(u16*)(t + i * 6), 0xFF, 0);
    arg0[2]++;
}

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_8008EAFC;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F366C[];

void func_800EEEFC(u8* arg0) {
    if (D_8008EAFC == 0) {
        u8* e = (u8*)&g_playthrough_state;
        e[0x28] = 0x5F;
        if (arg0[0x5F] & 0x10) {
            u8* t = D_800F366C + 4;
            s32 i = ((s8*)e)[0x26] - 1;
            t -= -(i * 6);
            if (*(u16*)(t + 4) != 0) {
                arg0[2]++;
                return;
            }
        }
        arg0[2] = 0xB;
    }
}

#include "common.h"
#include "mmx6/x4.h"

void func_800F02A0(u8, s8, s32, s16);
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F366C[];

void func_800EEF84(u8* arg0) {
    u8* p;
    s8* e;
    s32 i;

    p = D_800F366C + 0x70;
    e = (s8*)&g_playthrough_state;
    i = e[0x26] + 7;
    func_800F02A0(p[i * 3], 2, 0x48, 0x9A);
    func_800F02A0((p - -((e[0x26] + 7) * 3))[1], 2, 0xDC, 0x9A);
    p = 0;
    *(s16*)(D_800F366C + 0x1284) = 2;
    e[0x28] = 1;
    arg0[2]++;
}

#define func_800EEE70 func_800EF034
#include "../shared/rock_20/func_800EEE70.c"
#undef func_800EEE70

#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern s8 D_800CCEF6;
extern u8 D_800F366C[];

void func_800EF060(u8* arg0) {
    s32 i;
    u8* t = D_800F366C + 4;
    u8* p;
    i = D_800CCEF6 - 1;
    p = t;
    p -= -(i * 6);
    ((void (*)(s32, s32, s32))open_text_box)(*(u16*)(p + 2), 0xFF, 0);
    arg0[2]++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u8 D_8008EAFC;
extern s8 D_800CCEF8;

void func_800EF0C0(void* arg0) {
    if (D_8008EAFC == 0) {
        play_sound(0, 0x22, 0);
        D_800CCEF8 = 0x5F;
        M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCEF8;

void func_800EF118(void* arg0) {
    D_800CCEF8 = 0x5F;
    M2C_FIELD(arg0, s8*, 1) = 3;
    M2C_FIELD(arg0, s8*, 2) = 0;
}

#define func_80041AB8 func_800EF134
#define D_80075FD8 D_800F392C
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

extern u8 D_800F48F2;
extern u8 D_800F48F3;
extern u8 D_800F48F5;
extern u8 D_800F48F7;

void func_800EF170(u8* arg0) {
    D_800F48F2 = 0;
    D_800F48F3 = 0;
    D_800F48F5 = 0;
    D_800F48F7 = 0;
    arg0[2]++;
}

#include "common.h"

extern u16 D_800C4570;
extern s8 D_800CCEF8;
extern u8 D_800F48F2;
#define D_800F48F2 (*(s8*)&D_800F48F2)
extern u8 D_800F48F3;
extern u8 D_800F48F5;
#define D_800F48F5 (*(s8*)&D_800F48F5)

void func_800EF1A4(u8* arg0) {
    if (D_800F48F5 != 0) {
        if (D_800C4570 & 0x8FF) {
            if (D_800F48F2 >= 0) {
                D_800CCEF8 = 0x5F;
                D_800F48F5 = 0;
                D_800F48F3 = (D_800F48F3 + 1) & 3;
                arg0[2] = 1;
                return;
            }
            // !FAKE: m2c control flow, jump to the shared tail
            goto block_5;
        }
    } else {
    block_5:
        D_800CCEF8 = 0x6F;
        arg0[2] = arg0[2] + 1;
    }
}
#undef D_800F48F2
#undef D_800F48F5

#include "common.h"

extern s8 D_800CCEF8;

void func_800EF230(u8* arg0) {
    D_800CCEF8 = 0x6F;
    arg0[1] = 0xA;
    arg0[2] = 0;
}

#define func_80041AB8 func_800EF24C
#define D_80075FD8 D_800F3940
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F48F2;
extern u8 D_800F48F3;
extern u8 D_800F48F4;
extern u8 D_800F48F5;
extern u8 D_800F48F8;

void func_800EF288(u8* arg0) {
    u8* e = (u8*)&g_playthrough_state;
    if (e[0x69] != e[0xC8]) {
        D_800F48F4 = 1;
    } else {
        D_800F48F4 = 0;
    }
    D_800F48F2 = 0;
    D_800F48F3 = 0;
    D_800F48F5 = 0;
    D_800F48F8 = 0;
    arg0[2]++;
}

#include "common.h"

extern u16 D_800C4570;
extern s8 D_800CCEF8;
extern u8 D_800F48F2;
#define D_800F48F2 (*(s8*)&D_800F48F2)
extern u8 D_800F48F3;
extern u8 D_800F48F4;
#define D_800F48F4 (*(s8*)&D_800F48F4)
extern u8 D_800F48F5;
#define D_800F48F5 (*(s8*)&D_800F48F5)

void func_800EF2EC(u8* arg0) {
    if (D_800F48F5 != 0) {
        if (D_800C4570 & 0x8FF) {
            if (D_800F48F2 >= 0 || D_800F48F4 == 1) {
                D_800CCEF8 = 0x5F;
                D_800F48F5 = 0;
                D_800F48F3 = (D_800F48F3 + 1) & 3;
                arg0[2] = 1;
                return;
            }
            // !FAKE: m2c control flow, jump to the shared tail
            goto block_6;
        }
    } else {
    block_6:
        D_800CCEF8 = 0x6F;
        arg0[2] = arg0[2] + 1;
    }
}
#undef D_800F48F2
#undef D_800F48F4
#undef D_800F48F5

#include "common.h"

s32 func_800F0668(void);
extern u8 D_800F366C[];

void func_800EF38C(u8* arg0) {
    s32 t = func_800F0668();
    D_800F366C[0x128D] = t;
    if (t & 0xFF) {
        arg0[2] = arg0[2] + 1;
    } else {
        arg0[2] = 8;
    }
}

#include "common.h"

void func_800F02A0(u8, s8, s32, s16);
extern s8 D_800CCEF8;
extern u16 D_800F36CC;
extern u8 D_800F3844[];
extern u16 D_800F48EC;
extern s16 D_800F48EE;
extern s16 D_800F48F0;
extern u8 D_800F48F9;

void func_800EF3D8(u8* arg0) {
    u8* p;

    p = D_800F3844;
    func_800F02A0((p - -((D_800F48F9 + 7) * 3))[1], 2, 0x48, 0xAF);
    func_800F02A0((p - -((D_800F48F9 + 7) * 3))[2], 2, 0xDC, 0xAF);
    D_800F48F0 = 2;
    D_800F48EE = 0;
    D_800CCEF8 = 1;
    D_800F48EC = D_800F36CC;
    arg0[2]++;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800C4570;
extern s8 D_800CCEF8;

void func_800EF4A0(void* arg0) {
    if (D_800C4570 & 0x8FF) {
        D_800CCEF8 = 0x6F;
        M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    }
}

#include "common.h"

extern s8 D_800CCEF8;

void func_800EF4DC(void* arg0) {
    D_800CCEF8 = 0x5F;
    ((u8*)arg0)[1] = 4;
    ((u8*)arg0)[2] = 0;
}

#define func_80041AB8 func_800EF4F8
#define D_80075FD8 D_800F3964
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800F0784(s32);
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_80097169;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F366C[];

#define ENG37 ((u8*)&g_playthrough_state)

void func_800EF534(u8* arg0) {
    u8* e = ENG37;
    u8 c = e[0x26];
    // !FAKE: regalloc pin, the joined result lives in the first return register
    register s32 v asm("$2");

    if ((u32)(c - 1) < 8U) {
        if (*(s8*)(e + 0x27) != 0) {
            v = 2;
            arg0[2] = v;
            return;
        }
        {
            if (!((D_80097169 >> ((s8)c - 1)) & 1)) {
                arg0[3] = 3;
                func_800F0784(3);
                {
                    u16* t = (u16*)(D_800F366C + 0x34);
                    s32 i;
                    e[0x28] = 1;
                    i = *(s8*)(e + 0x26) - 1;
                    open_text_box(t[i], 0xFF, 0);
                }
                v = arg0[2] + 1;
                arg0[2] = v;
                return;
            } else {
                // !FAKE: shared else block reached from the inner bit test
                goto block_4;
            }
        }
    } else {
    block_4:
        v = 2;
    }
    arg0[2] = v;
}

#undef ENG37

#define func_800EECD8 func_800EF5FC
#include "../shared/rock_20/func_800EECD8.c"
#undef func_800EECD8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF628(void* arg0) {
    M2C_FIELD(arg0, s8*, 1) = 5;
    M2C_FIELD(arg0, s8*, 2) = 0;
}

#define func_80041AB8 func_800EF638
#define D_80075FD8 D_800F3970
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF674(void* arg0) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, s8*, 2) = 1;
    }
}

#define func_80041AB8 func_800EF694
#define D_80075FD8 D_800F3988
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/rock_20/func_800EF6D0.c"

/* Adapted from sozud/mmx4 @807a01b src/main/engine.c:func_8001F9DC, AGPL-3.0; proven shared with X6 by exact signature 8d45f66608cd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
/* siblings in the same TU declare it as struct X4_EngineObj; view it as the upstream state block */
void func_8001D218();

void func_800EF704(struct X4_EngineObj* arg0) {
    if (D_80097420.transition.active == 0) {
        func_8001D218();
        arg0->unk2++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(M2C_UNK);
void func_8001D218();
void func_80025F34();
s32 func_800280F4();
void init_checkpoint_positions(void);
void func_800F02A0(u8, s8, s32, s16);
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800F0438(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800EF748(struct X4_EngineObj* arg0) {
    func_8001D218();
    D_80097420.transition.selection = 0;
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    background_objects[2].x_pos.i.hi = 0x200;
    background_objects[2].unk4C = 1;
    func_800F03B8(0x22, 1, 0x130, 0x30);
    func_800F0438(0x21, 1, 0xF4, 0x7A, 0);
    func_800F0438(0x29, 1, 0x1EC, 0x7A, 0);
    func_800F0438(0x23, 1, 0xF4, 0xAC, 1);
    func_800F02A0(0xBD, 1, 0, 0);
    arg0->unk1F = 0;
    arg0->enable_boss = 0;
    ((void (*)(s32))func_800139A0)(8);
    arg0->unk8 = 1;
    arg0->unk2++;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);

void func_800EF838(u8* arg0) {
    switch (D_80097420.transition.selection) {
    case 0:
    default:
        arg0[1] = 0xB;
        arg0[2] = 0;
        arg0[3] = 0;
        break;
    case 1:
        ((void (*)(s32))func_800139F4)(8);
        arg0[2]++;
        break;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EF89C(void* arg0) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, s8*, 1) = 5;
        M2C_FIELD(arg0, s8*, 2) = 2;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F02A0(u8, s8, s32, s16);                           /* extern */
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK func_800F0438(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

void func_800EF8C4(void* arg0) {
    D_80097420.transition.selection = 0;
    func_800F03B8(0x22, 1, 0x130, 0x30);
    func_800F0438(0x21, 1, 0xF4, 0x7A, 0);
    func_800F0438(0x29, 1, 0x1EC, 0x7A, 0);
    func_800F0438(0x23, 1, 0xF4, 0xAC, 1);
    func_800F02A0(0xBD, 1, 0, 0);
    M2C_FIELD(arg0, s8*, 2) = 3;
}

#define func_80041AB8 func_800EF968
#define D_80075FD8 D_800F39A4
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800EF6D0 func_800EF9A4
#include "../shared/rock_20/func_800EF6D0.c"
#undef func_800EF6D0

#include "common.h"

void func_800EF9D8(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        arg0[2] = arg0[2] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(M2C_UNK);
void func_8001D218();
void func_80025F34();
s32 func_800280F4();
void init_checkpoint_positions(void);
void func_800F02A0(u8, s8, s32, s16);
M2C_UNK func_800F0324(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800EFA04(struct X4_EngineObj* arg0) {
    func_8001D218();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    background_objects[2].x_pos.i.hi = 0x200;
    background_objects[2].unk4C = 1;
    func_800F02A0(0x95, 1, 0x11C, 0x40);
    func_800F0324(0xBC, 1, 0x16C, 0x80, 0);
    func_800F0324(0xC1, 1, 0x16C, 0xA0, 1);
    func_800F02A0(0xB9, 1, 0, 0);
    D_80097420.transition.selection = 1;
    arg0->unk1F = 0;
    arg0->enable_boss = 0;
    ((void (*)(s32))func_800139A0)(8);
    arg0->unk8 = 1;
    arg0->unk2++;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800133A0(); /* extern */
M2C_UNK func_8001D25C(); /* extern */

void func_800EFAE0(s8* arg0) {
    if (D_80097420.transition.active == 0) {
        if (D_80097420.transition.selection == 0) {
            func_8001D25C();
            func_800133A0();
            return;
        }
        arg0[1] = 5;
        arg0[2] = 2;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
void func_8001D218();

void func_800EFB44(struct X4_EngineObj* arg0) {
    s8 v = arg0->unk2;

    if (v == 0) {
        ((void (*)(s32))func_800139F4)(8);
        arg0->unk2++;
    } else if (v == 1) {
        if (D_80097420.transition.active == 0) {
            func_8001D218();
            arg0->unk2++;
        }
    } else if (v == 2) {
        arg0->unk1 = 8;
        arg0->unk2 = 0;
    }
}

#define func_80041AB8 func_800EFBCC
#define D_80075FD8 D_800F39B8
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFC08(void* arg0) {
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
}

#include "common.h"

void func_800EFC1C(u8* arg0) {
    u8 v = arg0[0x158];
    u32 i;
    if (v == 0xFF) {
        arg0[0] = 3;
    } else {
        arg0[0] = 0x13;
        arg0[0x1D] = v;
    }
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    do {
        i = 0;
    } while (0);
    arg0 += 0x26;
    do {
        arg0[i] = 0;
    } while (++i < 0x10);
}

/* Adapted from sozud/mmx4 @807a01b src/main/menu.c:func_8001C5A8, AGPL-3.0; proven shared with X6 by exact signature e4a5fdbaa049 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern u8 D_800F3C00[32];
extern struct X4_MenuTextureData D_800F3C20;

void func_800EFC74(u8** arg0) {
    __builtin_memcpy(*arg0 + 0x60, D_800F3C00, 0x20);
    __builtin_memcpy(*arg0 + 0x80, D_800F3C20.texture, 0x180);
}

#define func_80041AB8 func_800EFDA8
#define D_80075FD8 D_800F39C0
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK reset_level();
extern u16 D_800C4570;

void func_800EFDE4(u8* arg0) {
    if (D_800C4570 & 0x40) {
        play_sound(0, 0x22, 0);
        ((void (*)())reset_level)();
        D_80097420.transition.selection = 0;
        arg0[1] = 0x14;
        arg0[2] = 0;
    }
}

#define func_800EA750 func_800EFE40
#include "../shared/rock_11/func_800EA750.c"
#undef func_800EA750

#define func_80041AB8 func_800EFE48
#define D_80075FD8 D_800F39DC
#define FAMILY_FIELD 2
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800EFE84);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK reset_level();                         /* extern */
extern u16 D_800C4570;

void func_800EFF28(s8* arg0) {
    if (D_800C4570 & 0x40) {
        play_sound(0, 0x22, 0);
        ((void (*)())reset_level)();
        arg0[1] = 6;
        arg0[2] = 6;
        arg0[3] = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_800EFF80(u8* arg0) {
    s32 k;
    struct X4_QuadObj* q;
    s8* obj;

    arg0[2] = arg0[2] + 1;
    reset_level();
    func_800F03B8(0x25, 0, 0x130, 0x30);
    k = 0x10;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = k;
        q->unk2 = k;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        *(s16*)(obj + 0xA) = 0xE0;
        *(s16*)(obj + 0xE) = 0x58;
        obj[1] = 0x2E;
        obj[2] = -0x10;
    }
    arg0[3] = 6;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
extern u16 D_800C4570;
extern struct X4_MiscObj D_800E2F90;

void func_800F0030(u8* arg0_) {
    u8* arg0 = arg0_;
    s32 ret;
    s32 done;

    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done == 0 && (D_800C4570 & 0x40)) {
        play_sound(0, 0x22, 0);
        arg0[3] = 0xB;
        arg0[2] = arg0[2] + 1;
        D_800E2F90.x_pos.bytes[2] = 3;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_8001C5EC(u8);
void func_800EE19C(void);
void func_800EE878(struct X4_MiscObj*);
extern struct X4_MiscObj D_800E2F90;

void func_800F0100(u8* arg0) {
    s32 ret;
    s32 done;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    func_800EE19C();
    func_800EE878(&D_800E2F90);
    if ((s8)arg0[1] != 0x15) {
        arg0[3] = 0xC;
        arg0[2] = arg0[2] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
M2C_UNK reset_level();
extern u16 D_800C4570;
extern struct X4_MiscObj D_800E2F90;

void func_800F01DC(u8* arg0) {
    s32 ret;
    s32 done;

    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done == 0 && (D_800C4570 & 0x40)) {
        play_sound(0, 0x22, 0);
        ((void (*)())reset_level)();
        D_80097420.transition.selection = 0;
        arg0[1] = 0x14;
        arg0[2] = 0;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F02A0);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F0324);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F03B8);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F0438);
// clang-format on

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();

void func_800F04C8(void* arg0, u8 arg1, s8 arg2, s32 arg3, s32 arg4) {
    s16 y = arg3;
    s16 z = arg4;
    void* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 1;
        M2C_FIELD(obj, u8*, 1) = 0x2D;
        M2C_FIELD(obj, s8*, 2) = -0xB;
        M2C_FIELD(obj, s8*, 0x54) = arg2;
        M2C_FIELD(obj, u8*, 0x55) = arg1;
        M2C_FIELD(obj, u8*, 0x58) = 0;
        M2C_FIELD(obj, s16*, 0xA) = y;
        M2C_FIELD(obj, s16*, 0xE) = z;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80097169;
extern struct X4_EngineObj g_playthrough_state;

#define ENG48 ((u8*)&g_playthrough_state)

s32 func_800F054C(void) {
    u8* e = ENG48;
    u8 c = e[0x26];

    if ((u32)(c - 1) < 8U) {
        if (*(s8*)(e + 0x27) == 0) {
            if (!((D_80097169 >> ((s8)c - 1)) & 1)) {
                return 1;
            }
        }
    }
    return 0;
}

#include "common.h"

extern u8 D_800F366C[];

s32 func_800F05AC(s32 arg0) {
    s32 i;
    u8* p;

    i = 0;
    p = D_800F366C + 0xA0;
    for (; i < 0x1A; i++, p += 0xC) {
        if (arg0 == *(s32*)p) {
            return (u8)i;
        }
    }
    return 0;
}

#include "common.h"

s32 get_reploid_status(s32);
s32 func_800F06F4(s32);

s32 func_800F05E8(u8 arg0) {
    s32 ret;

    if (func_800F06F4(arg0) == 0) {
        ret = get_reploid_status(arg0) == 2;
    } else {
        ret = 0;
    }
    return ret;
}

#define func_800ED69C func_800F0630
#define D_800E2F9C D_800E2F9C
#include "../shared/rock_18/func_800ED69C.c"
#undef func_800ED69C
#undef D_800E2F9C

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

s32 func_800F0668(void) {
    {
        u8* p = (u8*)&g_playthrough_state;
        s32 a = p[0x69] & 0xF;
        if (a == 0xF && (p[0xC8] & 0xF) != a) {
            p[0x5F] |= 4;
            return 1;
        }
    }
    {
        u8* p = (u8*)&g_playthrough_state;
        s32 b = p[0x69] & 0xF0;
        if (b == 0xF0 && (p[0xC8] & 0xF0) != b) {
            p[0x5F] |= 2;
            return 2;
        }
    }
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

s32 func_800F06F4(s32 arg0) {
    u8 a = arg0;
    u32 s = a & 7;
    // !FAKE: base pin schedules the table address before the index shift
    register u8* b asm("$3") = (u8*)&g_playthrough_state;

    b -= -((a >> 3) * 4);
    return (*(u32*)(b + 0x118) >> (s * 4)) & 0xF;
}

#include "common.h"

extern s32 D_8006D674[];

s32 func_800F0724(u8 arg0, s32 arg1) {
    u8 i;
    u8 n;

    n = 0;
    i = 0;
    do {
        if (D_8006D674[i] & arg1) {
            n++;
        }
        i++;
    } while (i <= arg0);
    if (n >= 9) {
        n = 8;
    }
    return n;
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800F366C[];

void func_800F0784(s32 arg0) {
    arg0 &= 0xFF;
    background_objects[1].unk4C = 1;
    background_objects[1].y_pos.i.hi = *(u16*)(D_800F366C + 0x734 + arg0 * 2);
}

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F07B4);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F02A0(u8, s8, s32, s16);                           /* extern */
M2C_UNK func_800F0324(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

void func_800F0840(void* arg0) {
    func_800F02A0(0x94, 0, 0x11C, 0x38);
    func_800F0324(0xBC, 1, 0x16C, 0x80, 0);
    func_800F0324(0xC1, 1, 0x16C, 0xA0, 1);
    func_800F02A0(0xB9, 1, 0, 0);
    D_80097420.transition.selection = 0;
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800133A0(); /* extern */
M2C_UNK func_8001D25C(); /* extern */

void func_800F08D0(void* arg0) {
    s32 var_v0;
    s8* var_a0;
    u8 temp_v1;

    if (D_80097420.transition.active == 0) {
        if (M2C_FIELD(arg0, s8*, 3) == 0) {
            temp_v1 = M2C_FIELD(arg0, u8*, 0x158);
            if (temp_v1 == 0xFF) {
                M2C_FIELD(arg0, s8*, 0) = 3;
            } else {
                M2C_FIELD(arg0, s8*, 0) = 0x13;
                M2C_FIELD(arg0, u8*, 0x1D) = temp_v1;
            }
            M2C_FIELD(arg0, s8*, 1) = 0;
            M2C_FIELD(arg0, s8*, 2) = 0;
            M2C_FIELD(arg0, s8*, 3) = 0;
        } else {
            func_8001D25C();
            func_800133A0();
        }
        var_v0 = 0xF;
        var_a0 = arg0 + 0x35;
        do {
            *var_a0 = 0;
            var_v0 -= 1;
            var_a0 -= 1;
        } while (var_v0 >= 0);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F0968);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F0B54);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F1108);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F16A0);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F18AC);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F1AB8);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F1D28);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F1F98);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F22E8);
// clang-format on

#define func_80041AB8 func_800F23CC
#define D_80075FD8 D_800F40A8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800F2408
#define D_80075FD8 D_800F40B4
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2444);
// clang-format on

#define func_8001A5F8 func_800F2464
#include "../shared/stage/func_8001A5F8.c"
#undef func_8001A5F8

#define func_800EF6D0 func_800F2470
#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCEF8;

void func_800F2470(void* arg0) {
    if ((u8)D_800CCEF8 >= 0x5FU) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800CCEF8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
}
#undef func_800EF6D0

#define func_800EF72C func_800F24CC
#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCEF8;

void func_800F24CC(void* arg0) {
    if ((u8)D_800CCEF8 >= 0x6FU) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800CCEF8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
}
#undef func_800EF72C

#define func_800EF788 func_800F2528
#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCEF8;

void func_800F2528(void* arg0) {
    if ((u8)D_800CCEF8 >= 0x7FU) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800CCEF8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
}
#undef func_800EF788

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2584);
// clang-format on

#define func_800EF878 func_800F2618
#define D_800F0F60 D_800F4108
#include "../shared/rock_18/func_800EF878.c"
#undef func_800EF878
#undef D_800F0F60

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2670);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2704);
// clang-format on

#define func_800EF9F8 func_800F2798
#include "../shared/rock_18/func_800EF9F8.c"
#undef func_800EF9F8

#define func_800EFA40 func_800F27E0
#include "../shared/rock_18/func_800EFA40.c"
#undef func_800EFA40

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F280C);
// clang-format on

#define func_800EFADC func_800F287C
#include "../shared/rock_18/func_800EFADC.c"
#undef func_800EFADC

#define func_800EFB44 func_800F28E4
#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCEF8;
#define D_800CCEF8 (*(u8*)&D_800CCEF8)

void func_800F28E4(void* arg0) {
    if (D_800CCEF8 >= 0x7F) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800CCEF8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
    if (M2C_FIELD(arg0, s8*, 3) != 0) {
        switch ((u32)(D_80097420.frame_counter & 3)) {
        case 0:
        case 1:
        case 2:
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
            break;
        case 3:
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
            break;
        }
    }
}
#undef D_800CCEF8
#undef func_800EFB44

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F299C);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2A18);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2B84);
// clang-format on

#define func_800EFFD4 func_800F2D74
#define D_800F1150 D_800F42F8
#include "../shared/rock_18/func_800EFFD4.c"
#undef func_800EFFD4
#undef D_800F1150

#define func_80041AB8 func_800F2E1C
#define D_80075FD8 D_800F41B0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800F2E58
#define D_80075FD8 D_800F41BC
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2E94);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2EB4);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F2F24);
// clang-format on

#define func_800F0218 func_800F2FB8
#include "../shared/rock_18/func_800F0218.c"
#undef func_800F0218

#define func_800EFADC func_800F302C
#include "../shared/rock_18/func_800EFADC.c"
#undef func_800EFADC

#define func_800F02F4 func_800F3094
#include "../shared/rock_18/func_800F02F4.c"
#undef func_800F02F4

#define func_80041AB8 func_800F3128
#define D_80075FD8 D_800F4278
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F3164);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F3184);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F31D8);
// clang-format on

#define func_800F04A8 func_800F3248
#include "../shared/rock_18/func_800F04A8.c"
#undef func_800F04A8

#define func_800F04C8 func_800F3268
#include "../shared/rock_18/func_800F04C8.c"
#undef func_800F04C8

#define func_800F04F8 func_800F3298
#include "../shared/rock_18/func_800F04F8.c"
#undef func_800F04F8

#define func_800F0528 func_800F32C8
#include "../shared/rock_18/func_800F0528.c"
#undef func_800F0528

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F3364);

INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F33B8);

// str 0x800F42F0 sha1=359bbf181e646fd64258495a1d1ebdd3523de68b = "printable byte run: data, not text"
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F340C);
// clang-format on

#define func_800F0770 func_800F3510
#define option_values option_values
#include "../shared/rock_18/func_800F0770.c"
#undef func_800F0770
#undef option_values

#define func_80041AB8 func_800F3560
#define D_80075FD8 D_800F426C
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_800F07FC func_800F359C
#include "../shared/rock_18/func_800F07FC.c"
#undef func_800F07FC

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", func_800F3610);
// clang-format on

#define func_80041AB8 func_800F3630
#define D_80075FD8 D_800F43A4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_20/nonmatchings/E9860", D_800F366C);
// clang-format on
