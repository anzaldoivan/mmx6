#include "common.h"
#include "psyq/libcard.h"
#define M2C_UNK s32

#include "psyq/libapi.h"
#include "mmx6/globals.h"

s32 func_8001C718(s32 arg0) {
    s32 tries;
    s32 ret;
    s32 n;

    tries = 10;
    ret = 2;
    TestEvent(D_800E2F80);
    TestEvent(D_800E2F84);
    TestEvent(D_800E2F88);
    do {
        if (_card_clear(arg0 * 0x10) != 0) {
            n = 0x3D08F;
            while (1) {
                if (TestEvent(D_800E2F80) != 0) {
                    ret = 0;
                    break;
                }
                if (TestEvent(D_800E2F84) != 0) {
                    ret = 1;
                    break;
                }
                if (TestEvent(D_800E2F88) != 0) {
                    ret = 2;
                    break;
                }
                if (--n == 0) {
                    ret = 3;
                    break;
                }
            }
            if (ret == 0) {
                break;
            }
        }
    } while (--tries != 0);
    return ret;
}

/* Adapted from sozud/mmx4 @807a01b src/main/memcard.c:func_8001CEDC, AGPL-3.0; proven shared with X6 by exact signature a1a1bb6682a3 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "psyq/libapi.h"
#include "mmx6/globals.h"

s32 func_8001C824(void) {
    const long MAX_LOOPS = 250000;
    long var_s0;

    for (var_s0 = MAX_LOOPS - 1; var_s0 != 0; var_s0--) {
        if (TestEvent(D_800E2F70)) {
            return 0;
        }
        if (TestEvent(D_800E2F74)) {
            return 1;
        }
        if (TestEvent(D_800E2F78)) {
            return 2;
        }
        if (TestEvent(D_800E2F7C)) {
            return 3;
        }
    }
    return 3;
}

#include "common.h"

void func_8001C8C4(u8* arg0) {
    s32 i;
    s32 j;
    s32 sum;
    u8* p;
    u8* e;
    s32 n;

    i = 0;
    do {
        if (arg0[0] != 0xFF) {
            p = arg0;
            sum = 0;
            e = arg0 + 0x3B8;
            n = e - p;
            for (j = 0; j < n; j++) {
                sum = (sum + *p++) & 0xFFFF;
            }
            sum = (sum + 0x55) & 0xFFFF;
            if (*(u16*)(arg0 + 0x3B8) != sum) {
                arg0[0] = 0xFF;
            }
        }
        i++;
        arg0 += 0x3BC;
    } while (i < 8);
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_8001C938);
// clang-format on

#include "common.h"

#define M2C_UNK s32

#include "psyq/libapi.h"
#include "mmx6/globals.h"

void func_8001CA0C(void) {
    TestEvent(D_800E2F70);
    TestEvent(D_800E2F74);
    TestEvent(D_800E2F78);
    TestEvent(D_800E2F7C);
}

#include "common.h"

#define M2C_UNK s32

#include "psyq/libapi.h"
#include "mmx6/globals.h"

void func_8001CA64(void) {
    TestEvent(D_800E2F80);
    TestEvent(D_800E2F84);
    TestEvent(D_800E2F88);
}

#include "common.h"

#define M2C_UNK s32

#include "psyq/libapi.h"
#include "mmx6/globals.h"

s32 func_8001CAAC(void) {
    s32 i;

    for (i = 0x3D08F; i != 0; i--) {
        if (TestEvent(D_800E2F80) != 0) {
            return 0;
        }
        if (TestEvent(D_800E2F84) != 0) {
            return 1;
        }
        if (TestEvent(D_800E2F88) != 0) {
            return 2;
        }
    }
    return 3;
}

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001447C(void);
void func_80017488(void);
void func_8001CBE0(void);
M2C_UNK func_80013DE8();
void func_8001344C();
void func_8001D0E4(void);
extern struct X4_EngineObj g_playthrough_state;
extern M2C_UNK D_800CD3F8;

void func_8001CB3C(void) {
    s8* p;
    s32 i;
    s32 z;

    SetDispMask(0);
    func_8001447C();
    func_80017488();
    func_8001CBE0();
    z = 0;
    p = (s8*)&D_800CD3F8;
    i = 15;
    do {
        *p++ = z;
    } while (i-- != 0);
    D_8008EC0C = 0;
    g_playthrough_state.stage = 0xE;
    g_playthrough_state.substage = 0;
    func_80013DE8();
    M2C_FIELD(&D_800CD3F8, s8*, 0) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 1) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 2) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 3) = 0;
    func_8001344C(func_8001D0E4);
}

#include "common.h"
#include "psyq/libgpu.h"

#define M2C_UNK s32

void set_resolution(s32 arg0); /* extern */
void func_8001A9B0(void);      /* extern */
extern M2C_UNK func_80012FE4;

void func_8001CBE0(void) {
    set_resolution(0);
    func_8001A9B0();
    SetDispMask(0);
    DrawSyncCallback(&func_80012FE4);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_1C_W (*(s32*)0x1F80001C)

M2C_UNK func_800139A0(s8);
void func_800139A0_2p(s32, void*); /* link-only second name */
void* alloc_sprite_slot();
extern u8 D_80071088;

void func_8001CC1C(void* arg0) {
    u8* obj;
    s32 c80;
    s32 one;
    s32 t;
    s32 k;
    // !FAKE: depin: dropping it breaks the match (75/80)
    register s32 one1 asm("$3");

    if (--M2C_FIELD(arg0, s16*, 4) == 0) {
        c80 = 0x80;
        obj = alloc_sprite_slot();
        one1 = 1;
        if (obj != 0) {
            k = 0x15;
            obj[1] = k;
            k = -1;
            obj[0x14] = k;
            obj[0] = one1;
            obj[0x47] = 0;
            obj[2] = one1;
            M2C_FIELD(obj, s16*, 0xA) = c80;
            M2C_FIELD(obj, s16*, 0xE) = c80;
            obj[3] = one1;
            M2C_FIELD(obj, s32*, 0x38) = 0;
            t = SCRATCH_1C_W;
            M2C_FIELD(obj, s32*, 0x30) = 0;
            M2C_FIELD(obj, s16*, 0x40) = 0x1880;
            M2C_FIELD(obj, s16*, 0x42) = 0x7807;
            obj[0x15] = 0;
            obj[0x16] = 0;
            M2C_FIELD(obj, s32*, 0x3C) = t;
        }
        one = 1;
        obj = alloc_sprite_slot();
        if (obj != 0) {
            k = 0x15;
            obj[1] = k;
            k = 0x180;
            M2C_FIELD(obj, s16*, 0xA) = k;
            k = -1;
            obj[0x14] = k;
            obj[0] = one;
            obj[0x47] = one;
            obj[2] = one;
            M2C_FIELD(obj, s16*, 0xE) = c80;
            obj[3] = one;
            M2C_FIELD(obj, s32*, 0x38) = 0;
            t = SCRATCH_1C_W;
            M2C_FIELD(obj, s32*, 0x30) = 0;
            M2C_FIELD(obj, s16*, 0x40) = 0x1880;
            M2C_FIELD(obj, s16*, 0x42) = 0x7807;
            obj[0x15] = 0;
            obj[0x16] = 0;
            M2C_FIELD(obj, s32*, 0x3C) = t;
        }
        M2C_FIELD(arg0, s16*, 4) = 0x258;
        func_800139A0_2p(8, obj);
        M2C_FIELD(arg0, u8*, 1) += 1;
        D_80071088 = one;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);

void func_8001CD5C(struct X4_EngineObj* arg0) {
    switch (D_800E3130[0]) {
    case 0:
    case 1:
    case 2:
        if (g_pad1_buttons[2] & 0x8000) {
            D_800E3130[0]++;
        } else if (g_pad1_buttons[2] & 0x2000) {
            D_800E3130[0] = 0;
        }
        break;
    case 3:
        if (g_pad1_buttons[2] & 0x2000) {
            play_sound(0, 0x22, 0);
            D_800E3130[1] = 0;
            D_800E3130[0]++;
        } else if (g_pad1_buttons[2] & 0x8000) {
            D_800E3130[0] = 0;
        }
        break;
    }
    if (g_pad1_buttons[2] & 0x5000) {
        D_800E3130[0] = 0;
    }
    if (arg0->unk2 != 0) {
        D_800E3130[0] = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);

void func_8001CE68(struct X4_EngineObj* arg0) {
    switch (D_800E3130[1]) {
    case 0:
    case 1:
    case 2:
        if (g_pad1_buttons[2] & 4) {
            D_800E3130[1]++;
        } else if (g_pad1_buttons[2] & 8) {
            D_800E3130[1] = 0;
        }
        break;
    case 3:
        if (g_pad1_buttons[2] & 2) {
            play_sound(0, 0x22, 0);
            D_800E3130[0] = 0;
            D_800E3130[1]++;
        } else if (g_pad1_buttons[2] & 4) {
            D_800E3130[1] = 0;
        }
        break;
    }
    if (g_pad1_buttons[2] & 0x5000) {
        D_800E3130[1] = 0;
    }
    if (arg0->unk2 != 0) {
        D_800E3130[1] = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800139F4(s32);
s32 play_sound(s32 a0, s32 a1, void* arg2);
void stop_cd_audio(void);
void func_8001CD5C(struct X4_EngineObj*);
void func_8001CE68(struct X4_EngineObj*);
#include "mmx6/state.h"
#include "mmx6/globals.h"

void func_8001CF78(struct X4_EngineObj* arg0) {
    if (D_80097420.transition.active == 0) {
        if (g_pad1_buttons[2] & 0x1000) {
            play_sound(0, 0xC, 0);
            if (arg0->unk2 == 0) {
                arg0->unk2 = 2;
            } else {
                arg0->unk2--;
            }
        }
        if (g_pad1_buttons[2] & 0x4000) {
            play_sound(0, 0xC, 0);
            if (arg0->unk2 == 2) {
                arg0->unk2 = 0;
            } else {
                arg0->unk2++;
            }
        }
        func_8001CD5C(arg0);
        func_8001CE68(arg0);
        if (g_pad1_buttons[2] & 0x840) {
            play_sound(0, 0x22, 0);
            func_800139F4(8);
            stop_cd_audio();
            {
                // !FAKE: depin: dropping it breaks the match (88/91)
                register s32 t asm("$3") = (u8)arg0->unk1 + 1;
                arg0->unk1 = t;
            }
        }
        if (g_pad1_buttons[2] == 0) {
            if (++arg0->unk4 > 0x4650) {
                stop_cd_audio();
                func_800139F4(8);
                arg0->unk4 = 0;
                {
                    s32 t = (u8)arg0->unk1 + 2;
                    arg0->unk1 = t;
                }
            }
        } else {
            arg0->unk4 = 0;
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void task_yield(s32);
M2C_UNK end_task_slot(M2C_UNK);
s32 play_sound(s32 a0, s32 a1, void* arg2);
void silence_sound(u8, u8);
void stop_cd_audio(void);
void func_80025F84(void);
void reset_level(void);
void func_8002C2B8();
extern void (*D_800710E8[])(void*);
extern M2C_UNK D_800CD3F8;
void func_800139F4(s32);
void func_8001D0E4(void) {
    s32 mask;

    {
        s8* st = (s8*)&D_800CD3F8;
        st[0xD] = 1;
        D_80097420.transition.suspended = 0;
        D_80097420.character_mode = 1;
    }
    func_80025F84();
    stop_cd_audio();
    silence_sound(0xFF, 0);
    reset_level();
    func_8002C2B8();
    while (1) {
        {
            void* a = &D_800CD3F8;
            D_800710E8[M2C_FIELD(&D_800CD3F8, s8*, 0)](a);
        }
        if (M2C_FIELD(&D_800CD3F8, s8*, 0xD) == 0) {
            mask = 0x800;
            if (M2C_FIELD(&D_800CD3F8, s8*, 0) != 1) {
                mask = 0x8F0;
            }
            if (g_pad1_buttons[2] & mask) {
                // !FAKE: depin: dropping it breaks the match (74/77)
                register s8* g asm("$2");
                play_sound(0, 0x22, 0);
                M2C_FIELD(&D_800CD3F8, s8*, 0xD) = 1;
                M2C_FIELD(&D_800CD3F8, u8*, 0xE) =
                    M2C_FIELD(&D_800CD3F8, u8*, 0);
                end_task_slot(1);
                g = (s8*)&D_80097420;
                if (g[4] == 0) {
                    ((M2C_UNK(*)())func_800139F4)(8);
                }
                M2C_FIELD(&D_800CD3F8, s8*, 0) = 5;
                M2C_FIELD(&D_800CD3F8, s8*, 1) = 0;
                M2C_FIELD(&D_800CD3F8, s8*, 2) = 0;
                M2C_FIELD(&D_800CD3F8, s8*, 3) = 0;
            }
        }
        task_yield(1);
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/game_info.c:func_8001D134, AGPL-3.0; proven shared with X6 by exact signature 6643b2ef34c8 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
void reset_level(void);
void silence_sound(u8, u8);
void stop_cd_audio();
void func_80025F84();
void func_8002C2B8();

void func_8001D218(void) {
    func_80025F84();
    stop_cd_audio();
    silence_sound(0xFF, 0);
    reset_level();
    func_8002C2B8();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
extern M2C_UNK D_800CD3F8;
void func_8001D0E4(void);

void func_8001D25C(void) {
    M2C_FIELD(&D_800CD3F8, s8*, 0) = 1;
    M2C_FIELD(&D_800CD3F8, s8*, 1) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 2) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 3) = 0;
    create_task(0, &func_8001D0E4);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001D2A0(void* arg0) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, s8*, 0xD) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#include "common.h"

void silence_sound(u8, u8);
void stop_cd_audio();
void func_80025F84();
void reset_level(void);
void func_8002C2B8();

void func_8001D2CC(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        arg0[0xD] = 1;
        func_80025F84();
        stop_cd_audio();
        silence_sound(0xFF, 0);
        reset_level();
        func_8002C2B8();
        arg0[1] = 0;
        arg0[0] = arg0[0] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u8 D_80071088;
#define D_80071088 (*(s8*)&D_80071088)
extern void (*D_8007108C[])(struct X4_GameInfo* arg0);
void func_80022960(void);

void func_8001D338(struct X4_GameInfo* arg0) {
    if (arg0->mode == 0) {
        if (D_80071088 != 0) {
            arg0->mode = 6;
        }
    }
    D_8007108C[arg0->mode](arg0);
    if (arg0->mode < 6) {
        func_80022960();
    }
}
#undef D_80071088

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0);
s32 play_str_movie(s32 arg0);
extern s32 D_800CD408;

void func_8001D3C0(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    D_800CD408 = 0x80103000;
    set_resolution(0);
    ((void (*)(s32))play_str_movie)(1);
    M2C_FIELD(arg0, u8*, 0x1) += 1;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001D414(struct ObjectHeader* arg0) {
    arg0->active = 1;
    arg0->id = 0;
}

#define func_80041AB8 func_8001D424
#define D_80075FD8 D_800710AC
#define FAMILY_FIELD 1
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0);
M2C_UNK load_player_files(void);
M2C_UNK func_80013DE8();
void pump_file_loads(void);
void read_dat_file(s32 arg0, s32* arg1, u8* arg2);
void silence_sound(u8 arg0, u8 arg1);
void stop_cd_audio(void);
void func_80021400(void);
void func_80025F84(void);
void reset_level(void);
void func_8002C1DC();
void func_8002C2B8();
extern u8 D_800710BC[];

void func_8001D460(void* arg0) {
    set_resolution(0);
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    D_80097420.transition.suspended = 1;
    func_80025F84();
    stop_cd_audio();
    silence_sound(0xFF, 0);
    reset_level();
    func_8002C2B8();
    func_8002C1DC();
    ((void (*)())read_dat_file)(D_800710BC[M2C_FIELD(arg0, s8*, 0xC)],
                                0x801F6000);
    pump_file_loads();
    func_80021400();
    load_player_files();
    func_80013DE8();
    M2C_FIELD(arg0, s16*, 0x4) = 0x960;
    M2C_FIELD(arg0, u8*, 0x1) += 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139A0(s8);
void func_80017E24(void);
void func_8001E730(void);
void func_8001E78C(void);
void func_80021434(void);
void func_80025F34();
void func_800280F4(void);
void func_8002927C(void);
void func_8002935C(void);
M2C_UNK func_800293CC();
void init_checkpoint_positions(void);
void func_8002A33C(void);
void func_8002A3E8(void);
void reset_level(void);
void func_8002C2B8();
void* alloc_sprite_slot();
void func_8003BD24(void);

void func_8001D51C(u8* arg0) {
    u32 i;
    u8* obj;

    reset_level();
    func_8002C2B8();
    func_80017E24();
    func_80021434();
    func_800280F4();
    init_checkpoint_positions();
    func_8002927C();
    func_8002935C();
    func_800293CC();
    func_8003BD24();
    func_8002A33C();
    func_8002A3E8();
    func_80025F34();
    func_8001E730();
    for (i = 2; i < 5; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x12;
            obj[2] = i;
        }
    }
    func_8001E78C();
    arg0[2] = 0;
    arg0[1]++;
    ((void (*)(s8))func_800139A0)(8);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800139F4(s32);
void func_80021500(void);
void func_8002163C(void);
void func_80025FB0();
void func_8002B29C(void);
s32 random_byte();

void func_8001D60C(struct X4_EngineObj* arg0) {
    if (D_80097420.transition.active == 0) {
        arg0->substage = 0;
    }
    if (--arg0->unk4 == 0 || g_Player.active == 0 || g_Player.state == 3) {
        func_800139F4(8);
        func_8002163C();
        {
            // !FAKE: increment temp lives in the second return register in retail
            register s32 t asm("$3") = (u8)arg0->unk1 + 1;
            arg0->unk1 = t;
        }
    } else {
        random_byte();
        func_80021500();
    }
    if ((u8)g_Player.pad4B[0xE4 - 0x4B] != 0) {
        func_8002B29C();
    }
    func_80025FB0();
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
void silence_sound(u8, u8);
void stop_cd_audio();
void func_80025F84(void);
void func_80025FB0();
void reset_level(void);
void func_8002C1DC();
void func_8002C2B8();

void func_8001D6D8(struct X4_GameInfo* arg0) {
    if (D_80097420.transition.active == 0) {
        arg0->unkD = 1;
        D_80097420.transition.suspended = 0;
        func_80025F84();
        stop_cd_audio();
        silence_sound(0xFF, 0);
        reset_level();
        func_8002C2B8();
        func_8002C1DC();
        arg0->unk0 = 3;
        arg0->mode = 0;
        return;
    }
    func_80025FB0();
}

/* Adapted from sozud/mmx4 @807a01b src/main/game_info.c:func_8001D57C, AGPL-3.0; proven shared with X6 by exact signature 57aab085cb3c (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_800710C0[])(struct X4_GameInfo* arg0);
void func_80022960(void);

void func_8001D760(struct X4_GameInfo* arg0) {
    D_800710C0[arg0->mode](arg0);
    func_800206C0();
    func_80022960();
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0);
M2C_UNK func_800139A0(s8);
void func_800144AC(void);
void silence_sound(u8, u8);
void func_80017E6C(void);
void stop_cd_audio(void);
void func_80025F84(void);
void reset_level(void);
void func_8002C2B8();
void* alloc_sprite_slot();

void func_8001D7AC(void* arg0) {
    u8* obj;

    set_resolution(1);
    M2C_FIELD(arg0, u8*, 0xD) = 1;
    func_80025F84();
    stop_cd_audio();
    silence_sound(0xFF, 0);
    reset_level();
    func_8002C2B8();
    func_800144AC();
    func_80017E6C();
    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[1] = 0x15;
        obj[0] = 1;
        obj[0x47] = 0;
        obj[2] = 0;
        M2C_FIELD(obj, s16*, 0xA) = 0x80;
        M2C_FIELD(obj, s16*, 0xE) = 0x78;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[1] = 0x15;
        obj[0] = 1;
        obj[0x47] = 1;
        obj[2] = 0;
        M2C_FIELD(obj, s16*, 0xA) = 0x180;
        M2C_FIELD(obj, s16*, 0xE) = 0x78;
    }
    M2C_FIELD(arg0, s16*, 4) = 0x12C;
    ((void (*)(s8))func_800139A0)(8);
    M2C_FIELD(arg0, u8*, 1) += 1;
}

/* Adapted from sozud/mmx4 @807a01b src/main/game_info.c:func_8001D64C, AGPL-3.0; proven shared with X6 by exact signature 370ee8910a36 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800139F4(s32);

void func_8001D8A0(struct X4_GameInfo* arg0) {
    if (--arg0->unk4 == 0) {
        arg0->mode++;
        func_800139F4(8);
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/game_info.c:func_8001D698, AGPL-3.0; proven shared with X6 by exact signature 08f62733c4aa (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_8001D8EC(struct X4_GameInfo* arg0) {
    arg0->unkD = 1;
    arg0->unk0 = 0;
    arg0->mode = 0;
    arg0->unk2 = 0;
    arg0->unk3 = 0;
    arg0->unkC++;
    if (arg0->unkC == 4) {
        arg0->unkC = 0;
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/game_info.c:func_8001D6DC, AGPL-3.0; proven shared with X6 by exact signature 07619b425e9d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
/* siblings in the same TU declare it as s32; view it as the upstream state block */
void func_80025FB0();

#define M2C_UNK s32
void func_80022960(void);
void func_8001D930(struct X4_GameInfo* arg0) {
    if (D_80097420.transition.active == 0) {
        if (arg0->unkE == 1) {
            arg0->unk0 = 6;
        } else {
            arg0->unk0 = 1;
        }
        return;
    }

    switch (arg0->unkE) {
    case 0:
        break;
    case 1:
        func_800206C0();
        func_80025FB0();
        break;
    case 2:
        func_80025FB0();
        break;
    case 3:
        func_800206C0();
        func_80022960();
        break;
    }
}

#include "../shared/save_file/func_8001D9CC.c"

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(s8);
void stop_cd_audio();
s32 func_8002B2F8(s32);
void reset_level(void);
void* alloc_sprite_slot();
extern u8 D_800710E0[];

void func_8001DA20(void* arg0) {
    u8* obj;
    u8 i;

    D_80097420.transition.suspended = 0;
    stop_cd_audio();
    func_8002B2F8(0);
    i = 0;
    reset_level();
    do {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x13;
            obj[2] = D_800710E0[i];
        }
        i++;
    } while (i < 6);
    ((void (*)(s8))func_800139A0)(8);
    M2C_FIELD(arg0, s16*, 4) = 0;
    M2C_FIELD(arg0, u8*, 1) += 1;
    D_800E3130[0] = 0;
    D_800E3130[1] = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
M2C_UNK func_800133A0();                /* extern */
void func_8002C1DC();
extern struct X4_EngineObj g_playthrough_state;
void func_8001E6E4(void);

void func_8001DAF8(s8* arg0) {
    s8 var_v0;

    if (D_80097420.transition.active == 0) {
        switch (arg0[2]) {
        case 0:
            func_8002C1DC();
            g_playthrough_state.state = 0;
            g_playthrough_state.unk1 = 0;
            g_playthrough_state.unk2 = 0;
            g_playthrough_state.unk3 = 0;
            create_task(1, &func_8001E6E4);
            func_800133A0();
            break;
        case 1:
            var_v0 = 7;
            // !FAKE: case 1 joins the shared store block
            goto block_9;
        case 2:
            var_v0 = 8;
        block_9:
            arg0[0] = var_v0;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            break;
        }
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001DBAC(void* arg0) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, s8*, 0) = 3;
        M2C_FIELD(arg0, s8*, 1) = 0;
        M2C_FIELD(arg0, s8*, 2) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
    }
}

#include "../shared/save_file/func_8001DBD8.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void silence_sound(u8, u8); /* extern */
void stop_cd_audio();       /* extern */
void func_80025F84();       /* extern */
void reset_level(void);     /* extern */
void func_8002C2B8();       /* extern */

void func_8001DC04(void* arg0) {
    if (D_80097420.transition.active == 0) {
        func_80025F84();
        stop_cd_audio();
        silence_sound(0xFF, 0);
        reset_level();
        func_8002C2B8();
        M2C_FIELD(arg0, s16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0);                    /* extern */
M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void pump_file_loads(void);                       /* extern */
void reset_level(void);                           /* extern */

void silence_sound(u8, u8);
void func_80017E6C(void);
void stop_cd_audio(void);
void func_80025F84();
void func_8002C2B8();
void func_8001DC6C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    ((M2C_UNK(*)())func_80025F84)();
    ((M2C_UNK(*)())stop_cd_audio)();
    silence_sound(0xFF, 0);
    reset_level();
    ((M2C_UNK(*)())func_8002C2B8)();
    func_80014F70(0xA2, 0, 0);
    pump_file_loads();
    set_resolution(1);
    ((M2C_UNK(*)())func_80017E6C)();
    M2C_FIELD(arg0, s16*, 4) = 4;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}

#include "common.h"
#define M2C_UNK s32

void func_800139F4(s32);
extern u16 D_800C4570;

void func_8001DCF8(u8* arg0) {
    s32 flag;
    s16 t;

    t = --*(s16*)(arg0 + 4);
    flag = 0;
    if (t < 0x12D) {
        flag = (D_800C4570 & 0x8F0) != 0;
    }
    if (t <= 0) {
        flag = 1;
    }
    if (flag != 0) {
        arg0[1]++;
        ((void (*)(s32))func_800139F4)(8);
    }
}

#include "common.h"

void func_8001DD74(u8* arg0) {
    s32 v;

    v = *(u16*)(arg0 + 4) + 1;
    *(u16*)(arg0 + 4) = v;
    if ((s16)v >= 3) {
        arg0[1]++;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
M2C_UNK func_800133A0();                /* extern */
void func_8001E6E4(void);

void func_8001DDB0(void) {
    create_task(1, &func_8001E6E4);
    func_800133A0();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
M2C_UNK func_800133A0();                /* extern */
void func_8001E6E4(void);

void func_8001DDE0(void) {
    create_task(1, &func_8001E6E4);
    func_800133A0();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void set_resolution(s32 arg0);
M2C_UNK func_80013DE8();
void func_80017E24(void);
void func_8001D218();
void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
void reset_level(void);
void func_8002C1DC();
void func_8002C2B8();

void func_8001DE10(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 2;
    func_8001D218();
    func_8002C1DC();
    g_playthrough_state.stage = 0xE;
    g_playthrough_state.substage = 0;
    func_80013DE8();
    set_resolution(1);
    func_80017E24();
    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    background_objects[0].unk3 = 1;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 0;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}
