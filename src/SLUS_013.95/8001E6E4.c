#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern void (*g_playthrough_state_handlers[])(struct X4_EngineObj*);
void task_yield(s32);

void func_8001E6E4(void) {
    while (1) {
        s32 i = g_playthrough_state.state;
        g_playthrough_state_handlers[i](&g_playthrough_state);
        task_yield(1);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
struct X4_EffectObj* alloc_class3_slot(void);

void func_8001E730(void) {
    struct X4_EffectObj* effect;

    if (g_playthrough_state.unk1E == 0) {
        effect = alloc_class3_slot();
        if (effect != 0) {
            effect->active = 1;
            effect->id = 0x1B;
            return;
        }
        g_playthrough_state.unk1E = 1;
    }
}

extern u8 D_800CCEDC;
void play_stage_bgm(void);

void func_8001E78C(void) {
    if ((u32)(D_800CCEDC - 9) >= 2) {
        play_stage_bgm();
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_EngineObj g_playthrough_state;
void set_resolution(s32 arg0);
M2C_UNK func_80013DE8();

void func_8001E7C0(u8* arg0) {
    arg0[0] = 6;
    g_playthrough_state.character_state.bytes[0] = arg0[0xC];
    g_playthrough_state.character_state.bytes[1] = arg0[0xD];
    arg0[0xC] = 0xD;
    arg0[0xD] = 1;
    arg0[0x36] = g_playthrough_state.character_state.bytes[0];
    func_80013DE8();
    set_resolution(1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0); /* extern */
M2C_UNK func_80013DE8();       /* extern */

void func_8001E81C(void* arg0) {
    s8* p;
    u32 i;

    M2C_FIELD(arg0, s8*, 0) = 0xC;
    i = 0;
    p = (s8*)arg0 + 0x26;
    do {
        p[i] = 0;
        i++;
    } while (i < 0x10);
    M2C_FIELD(arg0, s8*, 0xC) = 0xF;
    M2C_FIELD(arg0, s8*, 0xD) = 0;
    M2C_FIELD(arg0, s8*, 0x1D) = 0;
    M2C_FIELD(arg0, s8*, 0x1F) = 0;
    M2C_FIELD(arg0, s8*, 0x24) = 0;
    func_80013DE8();
    set_resolution(1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0); /* extern */
M2C_UNK load_player_files();   /* extern */
void reset_level(void);        /* extern */

void func_8001E880(void* arg0) {
    set_resolution(0);
    reset_level();
    load_player_files();
    M2C_FIELD(arg0, s8*, 0) = 8;
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 2) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0); /* extern */
M2C_UNK func_80013DE8();       /* extern */

void func_8001E8CC(void* arg0) {
    M2C_FIELD(arg0, s8*, 0) = 4;
    M2C_FIELD(arg0, s8*, 0xC) = 0xD;
    M2C_FIELD(arg0, s8*, 0xD) = 0;
    M2C_FIELD(arg0, s8*, 0x1D) = 0;
    func_80013DE8();
    set_resolution(1);
}

#include "common.h"

void func_8001E908(s8* arg0) {
    *arg0 = 3;
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80013DE8(); /* extern */
extern u16 D_800E3142;

void func_8001E914(void* arg0) {
    s32* var_a0;
    s32* var_v1;
    s32 var_a1;
    u8* tblD2;
    u8* tbl168;

    func_80013DE8();
    M2C_FIELD(arg0, s8*, 0x1D) = 0;
    M2C_FIELD(arg0, s8*, 0x1E) = 0;
    D_800CC868 = 0;
    D_800E3142 = 0;
    if ((M2C_FIELD(arg0, s8*, 0xC) < 0x13) &&
        (M2C_FIELD(arg0, s8*, 0xD) == 0)) {
        tblD2 = (u8*)arg0 + 0xD2;
        tbl168 = (u8*)arg0 + 0x168;
        var_a0 = (s32*)((u8*)arg0 + 0x118);
        var_v1 = (s32*)((u8*)arg0 + 0xD8);
        var_a1 = 0xF;
        M2C_FIELD(arg0, s32*, 0x90) = 0;
        M2C_FIELD(arg0, s32*, 0x460) = 0;
        M2C_FIELD(arg0, s32*, 0x94) = 0;
        M2C_FIELD(arg0, s32*, 0x98) = 0;
        M2C_FIELD(arg0, s16*, 0x9C) = 0;
        M2C_FIELD(arg0, s32*, 0x43C) = 0;
        M2C_FIELD(arg0, u8*, 0xC8) = M2C_FIELD(arg0, u8*, 0x69);
        do {
            *var_a0++ = *var_v1++;
            var_a1 -= 1;
        } while (var_a1 >= 0);
        {
            s32 off = M2C_FIELD(arg0, s8*, 0x38) * 2;
            M2C_FIELD(arg0, u16*, 0xD6) = *(u16*)(tblD2 + off);
        }
        M2C_FIELD(arg0, u8*, 0x43A) = tbl168[M2C_FIELD(arg0, s8*, 0xC)];
    }
    M2C_FIELD(arg0, s8*, 0) = 9;
}

#define func_80041AB8 func_8001E9EC
#define D_80075FD8 D_80071184
#define FAMILY_FIELD 1
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
#include "mmx6/state.h"
#include "mmx6/globals.h"
extern u16 D_800C4570;

void func_80013008(void);
s32 func_800139F4(s32);
void func_80020C40(void);
void func_80025FB0();
void func_8002B29C(void);
s32 random_byte();

void func_8001EA28(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x1C) == 0) {
        if (D_80097420.transition.active == 0 &&
            ((D_800C4570 & 0x800) ||
             (D_80097420.transition.suspended == 0 && D_800CF920[0] == 0xFF)) &&
            M2C_FIELD(arg0, s8*, 0x10) == 0 && M2C_FIELD(arg0, s8*, 0xF) == 0) {
            func_80013008();
            M2C_FIELD(arg0, u8*, 1) = 2;
            func_80025FB0();
            return;
        }
    }
    if (g_Player.state == 3) {
        M2C_FIELD(arg0, u8*, 1) = M2C_FIELD(arg0, u8*, 1) + 1;
        ((void (*)(s32))func_800139F4)(8);
    }
    random_byte();
    func_80020C40();
    if (M2C_FIELD(&g_Player, u8*, 0xE4) != 0) {
        func_8002B29C();
    }
    func_80025FB0();
}
#undef g_Player

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80013008(void);
void silence_sound(u8, u8);
void stop_cd_audio();
void exit_stage_by_clear(void* arg0);
void func_80020C40(void);
void func_80025FB0();
void func_8002B29C(void);

extern u8 D_80097184;
extern struct X4_EngineObj g_playthrough_state;

void func_8001EB48(void* arg0) {
    struct X4_EngineObj* e;

    if (D_80097420.transition.active != 0) {
        func_80020C40();
        if (D_80097184 != 0) {
            func_8002B29C();
        }
        func_80025FB0();
        return;
    }
    exit_stage_by_clear(arg0);
    D_800C4560 = 1;
    silence_sound(0xFF, 0);
    if (((u8*)arg0)[0x1B] == 0) {
        stop_cd_audio();
    }
    func_80013008();
    D_8008EC0C = 0;
    e = &g_playthrough_state;
    e->unk10 = 0;
    e->unk11 = 0;
    e->unk14 = 0;
    e->unk16 = 0;
    e->unk17 = 0;
}

#include "common.h"
#define M2C_UNK s32

s32 func_8001EC0C(void* arg0) {
    s8* p = arg0;
    s8 temp_a0;

    if (p[0xC] != 0xC) {
        return 0;
    }
    temp_a0 = p[0x1D];
    if (temp_a0 < 2) {
        return 0;
    }
    return temp_a0 < 0xA;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80034830();     /* extern */
M2C_UNK read_player_input(); /* extern */

void func_8001EC40(void) {
    read_player_input();
    func_80034830();
}

#include "common.h"
#include "psyq/libgpu.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_str_movie(s32); /* extern */
extern M2C_UNK D_8007119C;
extern M2C_UNK D_800711A4;

void func_8001EC68(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 1) == 0) {
        MoveImage(&D_8007119C, 0x240, 0);
        DrawSync(0);
        if ((M2C_FIELD(arg0, s8*, 0xC) == 0xB) &&
            (M2C_FIELD(arg0, s8*, 0x38) != 0)) {
            play_str_movie(8);
        }
        if (M2C_FIELD(arg0, s8*, 0xC) == 0xC) {
            if (M2C_FIELD(arg0, s8*, 0x38) != 0) {
                play_str_movie(9);
            }
        }
        MoveImage(&D_800711A4, 0x140, 0xB0);
        DrawSync(0);
        M2C_FIELD(arg0, s8*, 1) = (s8)((u8)M2C_FIELD(arg0, s8*, 1) + 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    M2C_FIELD(arg0, s8*, 0) = 8;
    M2C_FIELD(arg0, s8*, 1) = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0); /* extern */
M2C_UNK func_80013DE8();       /* extern */

void func_8001ED44(void* arg0) {
    M2C_FIELD(arg0, s8*, 0) = 0x11;
    M2C_FIELD(arg0, s8*, 0xC) = 0xF;
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 0x1D) = 0;
    func_80013DE8();
    set_resolution(1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0); /* extern */
M2C_UNK func_80013DE8();       /* extern */

void func_8001ED88(void* arg0) {
    D_80097420.character_mode = 0;
    M2C_FIELD(arg0, s8*, 0) = 0x14;
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 2) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 0x1F) = 0;
    M2C_FIELD(arg0, s8*, 0x24) = 0;
    M2C_FIELD(arg0, s8*, 0xC) = 0xB;
    M2C_FIELD(arg0, s8*, 0xD) = 0;
    func_80013DE8();
    set_resolution(1);
}

#include "common.h"

void func_8001EDDC(u8* arg0) {
    s32 i;
    u8* arr;
    u8* next;
    s32 t;

    i = 0;
    if (arg0[0x158] != (s8)arg0[0x1D]) {
        arr = arg0 + 0x158;
        do {
            i++;
        } while (i < 0x10 && arr[i] != (s8)arg0[0x1D]);
    }
    if (i == 0x10 ||
        (t = i + (s32)arg0, next = (u8*)t + 0x159, t = 0, *next == 0xFF)) {
        arg0[0] = 3;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
        arg0[0x158] = arg0[0x1D];
        return;
    }
    arg0[0] = 0x13;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[0x1D] = *next;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(s8);
void func_8001D218(void);
void func_8001FE74(void);
void* alloc_sprite_slot();
extern u8 D_800711AC;
extern u8 D_800711B8;

void func_8001EE7C(void* arg) {
    void* arg0 = arg;
    u8* p;
    u8* obj;
    u8 i;
    // !FAKE: depin: dropping it breaks the match (133/147)
    register s32 one asm("$19");

    func_8001D218();
    D_80097420.transition.selection = 0;
    M2C_FIELD(arg0, u8*, 0x1F) = 0;
    M2C_FIELD(arg0, u8*, 0x24) = 0;
    M2C_FIELD(arg0, s16*, 4) = 0x78;
    ((void (*)(s8))func_800139A0)(8);
    if (M2C_FIELD(arg0, s8*, 0xC) == 0) {
        p = &D_800711AC;
        i = 0;
        one = 1;
        if (*p != 0) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = one;
                obj[1] = 0x20;
                M2C_FIELD(obj, u8**, 0x50) = p;
                p++;
                M2C_FIELD(obj, s16*, 0xA) = D_800711AC;
                obj[0x55] = one;
            }
        } else {
            p++;
        }
        while (*p != 0xFF) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x1F;
                obj[2] = *p++;
                obj[7] = i++;
                M2C_FIELD(obj, s16*, 0xE) = *p++;
                M2C_FIELD(obj, s16*, 0xA) = *p++;
                obj[0x55] = one;
            }
        }
        func_8001FE74();
        M2C_FIELD(arg0, s16*, 8) = p[1];
        M2C_FIELD(arg0, u8*, 1) += 3;
    } else {
        p = &D_800711B8;
        i = 0;
        one = 1;
        if (*p != 0) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = one;
                obj[1] = 0x20;
                M2C_FIELD(obj, u8**, 0x50) = p;
                p++;
                M2C_FIELD(obj, s16*, 0xA) = D_800711B8;
                obj[0x55] = one;
            }
        } else {
            p++;
        }
        while (*p != 0xFF) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x1F;
                obj[2] = *p++;
                obj[7] = i++;
                M2C_FIELD(obj, s16*, 0xE) = *p++;
                M2C_FIELD(obj, s16*, 0xA) = *p++;
                obj[0x55] = one;
            }
        }
        func_8001FE74();
        M2C_FIELD(arg0, s16*, 8) = p[1];
        M2C_FIELD(arg0, u8*, 1) += 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800CCF3A;
extern s8 D_800E3140;
extern u8 D_800E3141;

void func_8001F0C8(u8* self) {
    if (D_80097420.transition.active == 0) {
        switch ((u8)D_80097420.transition.selection) {
        case 0: {
            self[0x1E] = 0;
            if (D_800CCF3A & 0x8000) {
                self[0x39] = 4;
            } else {
                self[0x39] = 2;
            }
            self[0] = 9;
            self[1] = 0;
            self[2] = 0;
            self[3] = 0;
            return;
        }
        case 1: {
            s8* e = (s8*)&g_playthrough_state;
            D_800E3140 = D_80097420.transition.selection;
            D_800E3141 = e[0xC];
            self[0] = 0xB;
            self[1] = 0;
            self[2] = 0;
            self[3] = 0;
            if ((u8)e[0x66] < 3U) {
                s8* q = e + 0xD2;
                if (*(s16*)(q + e[0x38] * 2) >= 0xBB8) {
                    g_playthrough_state.state = 0x13;
                    e[0x1D] = 5;
                    e[1] = 0;
                    e[2] = 0;
                    e[3] = 0;
                    return;
                }
            }
            break;
        }
        case 2:
        default:
            self[1] = 5;
            break;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(s8);
void func_8001D218(void);
void func_8001FE74(void);
void* alloc_sprite_slot();
extern u8 D_800711C8;

void func_8001F1C8(void* arg0) {
    u8* p;
    u8* obj;
    u8 i;
    s32 one;

    func_8001D218();
    D_80097420.transition.selection = 1;
    M2C_FIELD(arg0, u8*, 0x1F) = 0;
    M2C_FIELD(arg0, u8*, 0x24) = 0;
    ((void (*)(s8))func_800139A0)(8);
    p = &D_800711C8;
    i = 0;
    one = 1;
    if (*p != 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = one;
            obj[1] = 0x20;
            M2C_FIELD(obj, u8**, 0x50) = p;
            p++;
            M2C_FIELD(obj, s16*, 0xA) = D_800711C8;
            obj[0x55] = one;
        }
    } else {
        p++;
    }
    while (*p != 0xFF) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x1F;
            obj[2] = *p++;
            obj[7] = i++;
            M2C_FIELD(obj, s16*, 0xE) = *p++;
            M2C_FIELD(obj, s16*, 0xA) = *p++;
            obj[0x55] = one;
        }
    }
    func_8001FE74();
    M2C_FIELD(arg0, s16*, 8) = p[1];
    M2C_FIELD(arg0, u8*, 1) += 1;
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800133A0();
M2C_UNK func_800139A0(s8);
void func_8001D218(void);
void func_8001D25C(void);
void func_8001FE74(void);
void* alloc_sprite_slot();
extern u8 D_800711AC;
extern u8 D_800711B8;

void func_8001F320(void* arg) {
    void* arg0 = arg;
    u8* p;
    u8* obj;
    u8 i;
    // !FAKE: depin: dropping it breaks the match (146/160)
    register s32 one asm("$19");
    if (D_80097420.transition.active == 0) {
        if (D_80097420.transition.selection == 0) {
            func_8001D25C();
            func_800133A0();
            return;
        }
        M2C_FIELD(arg0, u8*, 1) = 0;
        func_8001D218();
        D_80097420.transition.selection = 0;
        M2C_FIELD(arg0, s16*, 4) = 0x78;
        ((void (*)(s8))func_800139A0)(8);
        if (M2C_FIELD(arg0, s8*, 0xC) == 0) {
            p = &D_800711AC;
            i = 0;
            one = 1;
            if (*p != 0) {
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    obj[0] = one;
                    obj[1] = 0x20;
                    M2C_FIELD(obj, u8**, 0x50) = p;
                    p++;
                    M2C_FIELD(obj, s16*, 0xA) = D_800711AC;
                    obj[0x55] = one;
                }
            } else {
                p++;
            }
            while (*p != 0xFF) {
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    obj[0] = 1;
                    obj[1] = 0x1F;
                    obj[2] = *p++;
                    obj[7] = i++;
                    M2C_FIELD(obj, s16*, 0xE) = *p++;
                    M2C_FIELD(obj, s16*, 0xA) = *p++;
                    obj[0x55] = one;
                }
            }
            func_8001FE74();
            M2C_FIELD(arg0, s16*, 8) = p[1];
            M2C_FIELD(arg0, u8*, 1) += 3;
        } else {
            p = &D_800711B8;
            i = 0;
            one = 1;
            if (*p != 0) {
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    obj[0] = one;
                    obj[1] = 0x20;
                    M2C_FIELD(obj, u8**, 0x50) = p;
                    p++;
                    M2C_FIELD(obj, s16*, 0xA) = D_800711B8;
                    obj[0x55] = one;
                }
            } else {
                p++;
            }
            while (*p != 0xFF) {
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    obj[0] = 1;
                    obj[1] = 0x1F;
                    obj[2] = *p++;
                    obj[7] = i++;
                    M2C_FIELD(obj, s16*, 0xE) = *p++;
                    M2C_FIELD(obj, s16*, 0xA) = *p++;
                    obj[0x55] = one;
                }
            }
            func_8001FE74();
            M2C_FIELD(arg0, s16*, 8) = p[1];
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);

void func_8001F5A0(void* arg0, s32 arg1) {
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        if (*(s8*)arg0 == 0) {
            *(s8*)arg0 = arg1;
        } else {
            *(s8*)arg0 = *(s8*)arg0 - 1;
        }
    }
    if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        if (*(s8*)arg0 == arg1) {
            *(s8*)arg0 = 0;
            return;
        }
        *(s8*)arg0 = *(s8*)arg0 + 1;
    }
}

#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001FE74(void);
void* alloc_sprite_slot();

u8 func_8001F65C(u8* arg0, s32 arg1) {
    u8* p;
    u8* obj;
    u8 i;
    u8 b;

    p = arg0;
    i = 0;
    b = arg1;
    if (*p != 0) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x20;
            M2C_FIELD(obj, u8**, 0x50) = p;
            M2C_FIELD(obj, s16*, 0xA) = *p++;
            obj[0x55] = b;
        }
    } else {
        p++;
    }
    while (*p != 0xFF) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x1F;
            obj[2] = *p++;
            obj[7] = i++;
            M2C_FIELD(obj, s16*, 0xE) = *p++;
            M2C_FIELD(obj, s16*, 0xA) = *p++;
            obj[0x55] = b;
        }
    }
    func_8001FE74();
    return p[1];
}

#include "../shared/stage/func_8001F778.c"

#define func_8001F778 func_8001F894
#define D_80097420 D_80097420
#include "../shared/stage/func_8001F778.c"
#undef func_8001F778
#undef D_80097420

#include "common.h"

extern u16 D_800CCF3A;

void func_8001F9B0(u8* arg0) {
    s32 v;

    if (D_80097420.transition.active == 0) {
        if (D_80097420.transition.selection == 0) {
            arg0[0x1E] = 0;
            v = D_800CCF3A & 0x8000;
            if (v != 0) {
                v = 4;
            } else {
                v = 2;
            }
            arg0[0x39] = v;
            do {
            } while (0);
            arg0[0] = 9;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            return;
        }
        arg0[1] = 5;
    }
}

#define func_8001F778 func_8001FA20
#define D_80097420 D_80097420
#include "../shared/stage/func_8001F778.c"
#undef func_8001F778
#undef D_80097420

// clang-format off
#define func_8001D9CC func_8001FB3C
#define D_800710D0 D_800711D4
#define func_80025FB0 func_80022960
#define func_8002ACA8 func_800210E8
#include "../shared/save_file/func_8001D9CC.c"
#undef func_8001D9CC
#undef D_800710D0
#undef func_80025FB0
#undef func_8002ACA8
// clang-format on

#include "common.h"
#include "mmx6/globals.h"

s8* func_8002C590(void);
extern s32 D_8007120C;

void func_8001FB90(u8* t, s16 arg1) {
    s8* p;

    if (*t != 0xFF) {
        do {
            p = func_8002C590();
            if (p != 0) {
                p[0] = 1;
                p[1] = 1;
                p[2] = t[0];
                *(s16*)(p + 0xE) = t[1];
                p[7] = t[2];
            }
            t += 3;
        } while (*t != 0xFF);
    }
    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0;
        p[2] = -1;
        *(s32**)(p + 0x50) = &D_8007120C;
        *(s16*)(p + 0xA) = arg1;
    }
    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 1;
        p[2] = -1;
        p[0x47] = 0x54;
        if (D_800CCF08 != 0) {
            p[0x47] = 0x51;
        }
        *(s16*)(p + 0xA) = 0x120;
        *(s16*)(p + 0xE) = 0x80;
    }
    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 1;
        p[2] = -1;
        p[0x47] = 0x53;
        if (D_800CCF08 != 0) {
            p[0x47] = 0x52;
        }
        *(s16*)(p + 0xA) = 0x80;
        *(s16*)(p + 0xE) = 0x80;
    }
}

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

void func_800133A0();
s32 func_800139F4(s32);
void func_80016B3C();
s32 play_sound(s32 a0, s32 a1, void* arg2);
void func_8001D218();
void func_8001D25C(void);
void func_8001F5A0(void*, s32);
void func_8001FB90(u8* t, s16 arg1);
void func_8002AA74(void);
void func_8002C1DC();
extern M2C_UNK D_800711F4;
extern s32 D_80071200;
extern u16 D_800C4570;

void func_8001FD10(u8* arg0) {
    s8 v;

    if (D_80097420.transition.active != 0) {
        return;
    }
    if (*(s32*)(arg0 + 0x34) == 0) {
        func_8001F5A0(&D_80097420.transition.selection, 1);
        if (D_800C4570 & 0x40) {
            play_sound(0, 0x22, 0);
            if (D_80097420.transition.selection == 0) {
                ((void (*)(s32))func_800139F4)(0x20);
                v = 2;
                // !FAKE: goto keeps the arg0[7] store block after the else arm; if/else inversion moved bytes
                goto set;
            }
            *(s32*)(arg0 + 0x34) = 1;
            func_8002AA74();
            D_80097420.transition.selection = 1;
            func_8001FB90((u8*)&D_80071200, 0x78);
        }
    } else {
        func_8001F5A0(&D_80097420.transition.selection, 1);
        if (D_800C4570 & 0x40) {
            play_sound(0, 0x22, 0);
            *(s32*)(arg0 + 0x34) = 0;
            if (D_80097420.transition.selection == 0) {
                arg0[7] = 0;
                SetDispMask(0);
                func_8001D218();
                func_80016B3C();
                func_8002C1DC();
                func_8001D25C();
                func_800133A0();
                return;
            }
            func_8002AA74();
            D_80097420.transition.selection = 0;
            func_8001FB90((u8*)&D_800711F4, 0x78);
            arg0[7] = 1;
            return;
        set:
            arg0[7] = v;
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"

s8* func_8002C590(void);

void func_8001FE74(void) {
    s8* p;

    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 1;
        p[2] = -1;
        p[0x47] = 0x54;
        if (D_800CCF08 != 0) {
            p[0x47] = 0x51;
        }
        *(s16*)(p + 0xA) = 0x120;
        *(s16*)(p + 0xE) = 0x80;
    }
    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 1;
        p[2] = -1;
        p[0x47] = 0x53;
        if (D_800CCF08 != 0) {
            p[0x47] = 0x52;
        }
        *(s16*)(p + 0xA) = 0x80;
        *(s16*)(p + 0xE) = 0x80;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(s8);           /* extern */
void func_8001FB90(u8* t, s16 arg1); /* extern */
void func_8002AA74(void);            /* extern */
extern M2C_UNK D_800711F4;

void func_8001FF30(void* arg0) {
    M2C_FIELD(arg0, s8*, 7) = 1;
    M2C_FIELD(arg0, s32*, 0x34) = 0;
    func_8002AA74();
    D_80097420.transition.selection = 0;
    func_8001FB90(&D_800711F4, 0x78);
    func_800139A0(0x20);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002AA74(void); /* extern */

void func_8001FF78(void* arg0) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_8002AA74();
        M2C_FIELD(arg0, s8*, 7) = 0;
        M2C_FIELD(arg0, s32*, 0x34) = 0;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern void (*D_80071214[])(struct X4_EngineObj*);
void func_800210E8();
void func_80025E1C();

void func_8001FFC0(struct X4_EngineObj* arg0) {
    D_80071214[arg0->unk7](arg0);
    func_800210E8();
    func_80025E1C();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define SPAD (*(s8**)0x1F80004C)
#define SPAD_TBL (*(void (***)(s8*))0x1F800080)

M2C_UNK func_8002CD6C(void*);
extern M2C_UNK g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_8002000C(void) {
    s8* p;
    u8 flags;
    s8* pl = (s8*)&g_Player;

    if (pl[0xCC] == 0) {
        for (SPAD = g_enemies; SPAD < g_enemies + 0x1D40; SPAD += 0x9C) {
            p = SPAD;
            flags = p[0];
            if (p[0] != 0) {
                s8* pl2 = (s8*)&g_Player;
                if (pl2[0xCC] != 0 ||
                    (g_playthrough_state.unk12 != 0 && !(flags & 8))) {
                    if (p[3] != 0) {
                        ((void (*)(void*, u8))func_8002CD6C)(p, flags);
                    }
                } else {
                    SPAD_TBL[p[1]](p);
                }
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(s8**)0x1F800050)

M2C_UNK func_8002CD6C(void*);
extern void (*D_80071220[])(s8*, u8);
extern s8 D_800950A0[];
extern M2C_UNK g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_8002012C(void) {
    s8* p;
    u8 flags;
    s8* pl = (s8*)&g_Player;

    if (pl[0xCC] == 0) {
        for (SPAD = D_800950A0; SPAD < D_800950A0 + 0x1400; SPAD += 0xA0) {
            p = SPAD;
            flags = p[0];
            if (p[0] != 0) {
                s8* pl2 = (s8*)&g_Player;
                if (pl2[0xCC] != 0 ||
                    (g_playthrough_state.unk11 != 0 && !(flags & 8))) {
                    if (p[3] != 0) {
                        ((void (*)(void*, u8))func_8002CD6C)(p, flags);
                    }
                } else {
                    D_80071220[p[1]](p, flags);
                }
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(s8**)0x1F800050)
#define SPAD_TBL (*(void (***)(s8*))0x1F800084)

M2C_UNK func_8002CD6C(void*);
#include "mmx6/projectile.h"
extern M2C_UNK g_Player;
extern struct X4_EngineObj g_playthrough_state;

void func_80020258(void) {
    s8* p;
    u8 flags;
    s8* pl = (s8*)&g_Player;

    if (pl[0xCC] == 0) {
        for (SPAD = (s8*)g_projectiles; SPAD < (s8*)g_projectiles + 0x1400;
             SPAD += 0xA0) {
            p = SPAD;
            flags = p[0];
            if (p[0] != 0) {
                s8* pl2 = (s8*)&g_Player;
                if (pl2[0xCC] != 0 ||
                    (g_playthrough_state.unk13 != 0 && !(flags & 8))) {
                    if (p[3] != 0) {
                        ((void (*)(void*, u8))func_8002CD6C)(p, flags);
                    }
                } else {
                    SPAD_TBL[p[1]](p);
                }
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_8002CD6C(void*);
extern struct X4_EngineObj g_playthrough_state;

#define CUR (*(s8**)SP(0x54))
#define FTBL (*(void (***)(s8*))SP(0x88))

void func_80020378(void) {
    s8* p;

    for (CUR = (s8*)D_80091298; CUR < (s8*)(D_80091298 + 0x2A00); CUR += 0x70) {
        if (g_playthrough_state.unk14 == 0) {
            p = CUR;
            if (p[0] == 0) {
                continue;
            }
            FTBL[p[1]](p);
        } else {
            p = CUR;
            if (p[0] != 0) {
                if ((u8)p[0] & 8) {
                    FTBL[p[1]](p);
                } else if (p[3] != 0) {
                    func_8002CD6C(p);
                }
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_EngineObj g_playthrough_state;

#define SPAD5C (*(s8**)0x1F80005C)
#define SPAD8C (*(s32*)0x1F80008C)

void func_8002048C(void) {
    s8* p;

    for (SPAD5C = (s8*)g_class3_slots; SPAD5C < (s8*)&g_class3_slots[0x60];
         SPAD5C += 0x30) {
        if (g_playthrough_state.unk15 == 0) {
            p = SPAD5C;
            if (p[0] != 0) {
                void* fn = *(void**)((p[1] << 2) + SPAD8C);
                ((void (*)())fn)(p);
            }
        } else {
            p = SPAD5C;
            if ((u8)p[0] & 8) {
                void* fn = *(void**)((p[1] << 2) + SPAD8C);
                ((void (*)())fn)(p);
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern M2C_UNK g_Player;
extern struct X4_EngineObj g_playthrough_state;
M2C_UNK func_8002CD6C(void*);

#define SP_OBJ_CUR (*(u8**)SP(0x060))
#define SP_OBJ_FUNCS (*(void (***)())SP(0x094))

void func_800205A0(void) {
    u8* obj;
    u8 flags;

    s8* pl0 = (s8*)&g_Player;
    if (pl0[0xCC] == 0) {
        SP_OBJ_CUR = (u8*)g_class4_slots;
        if ((u8*)g_class4_slots < (u8*)g_class4_slots + 0x3340) {
            do {
                obj = SP_OBJ_CUR;
                flags = obj[0];
                if (((s8*)obj)[0] != 0) {
                    s8* pl = (s8*)&g_Player;
                    if (pl[0xCC] != 0 ||
                        (g_playthrough_state.unk16 != 0 && !(flags & 8))) {
                        if (((s8*)obj)[3] != 0) {
                            ((void (*)())func_8002CD6C)(obj, flags);
                        }
                    } else {
                        SP_OBJ_FUNCS[((s8*)obj)[1]](obj);
                    }
                }
                SP_OBJ_CUR += 0xA4;
            } while (SP_OBJ_CUR < (u8*)g_class4_slots + 0x3340);
        }
    }
}

#undef SP_OBJ_CUR
#undef SP_OBJ_FUNCS

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define CUR (*(struct X4_MiscObj**)0x1F800064)
#define FTBL (*(void (***)(struct X4_MiscObj*))0x1F800090)

extern struct X4_EngineObj g_playthrough_state;

M2C_UNK func_8002CD6C(void*);

void func_800206C0(void) {
    struct X4_MiscObj* p;

    for (CUR = g_displayed_sprites; CUR < g_displayed_sprites + 0x60; CUR++) {
        if (g_playthrough_state.unk17 == 0) {
            p = CUR;
            if (p->active == 0) {
                continue;
            }
            FTBL[p->id](p);
        } else {
            p = CUR;
            if (p->active != 0) {
                if ((u8)p->active & 8) {
                    FTBL[p->id](p);
                } else if (p->on_screen != 0) {
                    func_8002CD6C(p);
                }
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_EngineObj g_playthrough_state;

#define SP_OBJ_CUR (*(s8**)SP(0x068))
#define SP_OBJ_FUNCS (*(void (***)())SP(0x098))

void func_800207D4(void) {
    for (SP_OBJ_CUR = (s8*)g_class6_slots;
         SP_OBJ_CUR < (s8*)g_class6_slots + 0x1800; SP_OBJ_CUR += 0x60) {
        if (g_playthrough_state.unk18 == 0) {
            if (SP_OBJ_CUR[0]) {
                SP_OBJ_FUNCS[SP_OBJ_CUR[1]](SP_OBJ_CUR);
            }
        } else if (SP_OBJ_CUR[0] && (u8)SP_OBJ_CUR[0] & 8) {
            SP_OBJ_FUNCS[SP_OBJ_CUR[1]](SP_OBJ_CUR);
        }
    }
}

#undef SP_OBJ_CUR
#undef SP_OBJ_FUNCS
