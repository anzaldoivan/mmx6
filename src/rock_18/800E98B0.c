#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_800139A0(M2C_UNK);
M2C_UNK reset_level();
void func_800EA3F0(s32, s32, s32, s32);
void func_800EA470(s32, s32, s32, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
#include "mmx6/state.h"

void func_800E98B0(u8* arg0) {
    reset_level();
    func_800EA3F0(0x10, 0, 0x150, 0x20);
    func_800EA470(0x11, 0, 0xD0, 0x40, 0);
    func_800EA3F0(0xF0, 0, 0x1B8, 0x40);
    func_800EA470(0x12, 0, 0xD0, 0x58, 1);
    func_800EA3F0(0xF1, 0, 0x1B8, 0x58);
    func_800EA470(0x13, 0, 0xD0, 0x70, 2);
    func_800EA470(0x14, 0, 0xD0, 0x88, 3);
    func_800EA3F0(0xF2, 0, 0x1B8, 0x88);
    func_800EA470(0x15, 0, 0xD0, 0xA0, 4);
    func_800EA3F0(0xF3, 0, 0x1B8, 0xA0);
    func_800EA3F0(0xF4, 0, 0x1C8, 0xA0);
    func_800EA470(0x26, 0, 0xD0, 0xB8, 5);
    func_800EA3F0(0x33, 0, 0xF0, 0xD3);
    arg0[3] = 0;
    D_80097420.transition.selection = 0;
    func_800EA3F0(1, 0, 0, 0);
    background_objects[0].unk3 = 1;
    background_objects[0].x_pos.i.hi = 0x200;
    background_objects[0].y_pos.i.hi = 0;
    background_objects[0].unk4C = 1;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 0;
    ((void (*)(s32))func_800139A0)(8);
    arg0[1]++;
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
void func_800174D4(u8 arg0);
M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);
void stop_cd_audio();
extern s8 D_800CC869;
extern s8 D_800CD3F8[];
extern u8 func_800F08CC[];

#define OPT_B(o) ((u8)D_800CD3F8[o])
#define OPT_SB(o) (D_800CD3F8[o])

void func_800E9A64(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (7/248)
    register u8* self asm("$17") = arg0;
    s32 five = 5;
    u8 prev;
    u8 old;

    if (D_80097420.transition.active != 0) {
        return;
    }
    if (g_pad1_buttons[2] & 0x800) {
        if (D_80097420.transition.selection == 4) {
            stop_cd_audio();
        }
        func_800139F4(8);
        D_80097420.transition.selection = five;
        // !FAKE: goto shares the self[1]++ exit block; a copied increment per arm moved bytes
        goto inc;
    }
    if ((g_pad1_buttons[2] & 0x10) && D_80097420.transition.selection != 4) {
        ((void (*)(s32))func_800139F4)(8);
        D_80097420.transition.selection = five;
        // !FAKE: goto shares the self[1]++ exit block; a copied increment per arm moved bytes
        goto inc;
    }
    if ((g_pad1_buttons[2] & 0x40) && (D_80097420.transition.selection == 2 ||
                                       D_80097420.transition.selection == 5)) {
        play_sound(0, 0x22, 0);
        func_800139F4(8);
    inc:
        self[1]++;
        return;
    }
    {
        // !FAKE: depin: dropping it breaks the match (241/248)
        register u8* eng asm("$16") = (u8*)&D_80097420;
        prev = eng[7];
        if (g_pad1_buttons[2] & 0x1000) {
            play_sound(0, 0xC, 0);
            if (eng[7] == 0) {
                eng[7] = five;
            } else {
                eng[7] = eng[7] - 1;
            }
        } else if (g_pad1_buttons[2] & 0x4000) {
            play_sound(0, 0xC, 0);
            if (eng[7] == five) {
                eng[7] = 0;
            } else {
                eng[7] = eng[7] + 1;
            }
        }
    }
    if (g_pad1_buttons[2] & 0xA040) {
        if (D_80097420.transition.selection == 3) {
            play_sound(0, 0xC, 0);
            D_800CC869 ^= 1;
            func_800174D4(D_800CC869);
        }
        if ((g_pad1_buttons[2] & 0xA040) &&
            D_80097420.transition.selection == 1) {
            play_sound(0, 0xC, 0);
            D_8006D5F9 ^= 1;
        }
    }
    if ((g_pad1_buttons[2] & 0xA000) && D_80097420.transition.selection == 0) {
        if (g_pad1_buttons[2] & 0x8000) {
            play_sound(0, 0xC, 0);
            if (default_options != 0) {
                default_options--;
            } else {
                default_options = 2;
            }
        } else if (g_pad1_buttons[2] & 0x2000) {
            play_sound(0, 0xC, 0);
            if (default_options < 2) {
                default_options++;
            } else {
                default_options = 0;
            }
        }
    }
    if (g_pad1_buttons[2] & 0xA050) {
        if (D_80097420.transition.selection != 4) {
            // !FAKE: goto jumps into the prev == 4 check; a merged && test moved bytes
            goto check;
        }
        old = OPT_B(3);
        if (g_pad1_buttons[2] & 0x8000) {
            if (old != 0) {
                D_800CD3F8[3] = old - 1;
            }
        } else if ((g_pad1_buttons[2] & 0x2000) && (s8)old < 0x17) {
            D_800CD3F8[3] = old + 1;
        }
        if (old != OPT_SB(3)) {
            play_sound(0, 0xC, 0);
        }
        if (g_pad1_buttons[2] & 0x10) {
            stop_cd_audio();
        } else if (g_pad1_buttons[2] & 0x40) {
            stop_cd_audio();
            {
                // !FAKE: depin: dropping it breaks the match (243/248)
                register s32 i asm("$2") = OPT_SB(3);
                play_bgm_xa_track(func_800F08CC[i], 0x7F);
            }
        }
    }
    if (D_80097420.transition.selection != 4) {
    check:
        if (prev == 4) {
            stop_cd_audio();
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139A0(M2C_UNK);
M2C_UNK reset_level();
void func_800EA3F0(s32, s32, s32, s32);
void func_800EA470(s32, s32, s32, s32, s32);

void func_800E9E44(u8* arg0) {
    reset_level();
    func_800EA3F0(0x27, 0, 0x114, 0x20);
    func_800EA470(0x28, 0, 0xF0, 0x32, 0);
    func_800EA3F0(0xE0, 0, 0xC0, 0x32);
    func_800EA470(0x29, 0, 0xF0, 0x3F, 1);
    func_800EA3F0(0xE1, 0, 0xC0, 0x3F);
    func_800EA470(0x2A, 0, 0xF0, 0x4C, 2);
    func_800EA3F0(0xE2, 0, 0xC0, 0x4C);
    func_800EA470(0x2B, 0, 0xF0, 0x59, 3);
    func_800EA3F0(0xE3, 0, 0xC0, 0x59);
    func_800EA470(0x2C, 0, 0xF0, 0x66, 4);
    func_800EA3F0(0xE4, 0, 0xC0, 0x66);
    func_800EA470(0x2D, 0, 0xF0, 0x73, 5);
    func_800EA3F0(0xE5, 0, 0xC0, 0x73);
    func_800EA470(0x2E, 0, 0xF0, 0x80, 6);
    func_800EA3F0(0xE6, 0, 0xC0, 0x80);
    func_800EA470(0x2F, 0, 0xF0, 0x8D, 7);
    func_800EA3F0(0xD0, 0, 0x1E0, 0x8D);
    func_800EA470(0x30, 0, 0xF0, 0x9A, 8);
    func_800EA3F0(0xD1, 0, 0x1E0, 0x9A);
    func_800EA470(0x31, 0, 0xF0, 0xA7, 9);
    func_800EA3F0(0xD2, 0, 0x1E0, 0xA7);
    func_800EA470(0x34, 0, 0xF0, 0xB4, 0xA);
    func_800EA3F0(0xD3, 0, 0x1E0, 0xB4);
    func_800EA470(0x32, 0, 0xF0, 0xC1, 0xB);
    func_800EA3F0(0x33, 0, 0xF0, 0xD3);
    func_800EA3F0(2, 0, 0, 0);
    D_80097420.transition.selection = 0;
    ((void (*)(s32))func_800139A0)(8);
    arg0[1]++;
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 option_values[];

void func_800EA0E8(u8* arg0) {
    u8 sel;
    u8 i;
    u8 k;
    u16 key;
    u16 old;

    if (D_80097420.transition.active != 0) {
        return;
    }
    if (g_pad1_buttons[2] & 0x800) {
        // !FAKE: goto shares the hit block between both button tests; one merged || test moved bytes
        goto hit;
    }
    if ((g_pad1_buttons[2] & 0x40) && D_80097420.transition.selection == 0xB) {
    hit:
        play_sound(0, 0x22, 0);
        ((void (*)(s32))func_800139F4)(8);
        arg0[1]++;
        return;
    }
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        if (D_80097420.transition.selection == 0) {
            D_80097420.transition.selection = 0xB;
        } else {
            D_80097420.transition.selection =
                D_80097420.transition.selection - 1;
        }
    }
    if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        if (D_80097420.transition.selection == 0xB) {
            D_80097420.transition.selection = 0;
        } else {
            D_80097420.transition.selection =
                D_80097420.transition.selection + 1;
        }
    }
    sel = 0xFF;
    if (D_80097420.transition.selection < 7) {
        i = 4;
        {
            s32 c16 = 0x10;

            if (D_80073610[D_80097420.transition.selection] == c16) {
                sel = 4;
            } else {
            next:
                i++;
                if (i < 0x10) {
                    // !FAKE: depin: dropping it breaks the match (189/194)
                    register s32 one asm("$5") = 1;

                    if ((one << i) ==
                        D_80073610[D_80097420.transition.selection]) {
                        do {
                            sel = i;
                        } while (0);
                    } else {
                        // !FAKE: goto loop; for and for(;;) forms moved bytes
                        goto next;
                    }
                }
            }
        }
        if (sel == 0xFF) {
            return;
        }
        key = g_pad1_buttons[2];
        for (i = 0; i < 8; i++) {
            if (key == D_80073620[i]) {
                play_sound(0, 0x22, 0);
                old = button_map[sel];
                button_map[sel] = D_80073620[i];
                for (k = 0; button_map[k] != 0; k++) {
                    if (k != sel && button_map[k] == D_80073620[i]) {
                        button_map[k] = old;
                    }
                }
                return;
            }
        }
    } else if (D_80097420.transition.selection < 0xB &&
               (g_pad1_buttons[2] & 0x40)) {
        play_sound(0, 0x22, 0);
        g_temp_options ^= option_values[D_80097420.transition.selection - 7];
    }
}

#include "../shared/rock_18/func_800EA3F0.c"

#include "common.h"

void* alloc_sprite_slot();

void func_800EA470(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 id = arg0;
    s8 b = arg1;
    s16 x = arg2;
    s16 y = arg3;
    u8 n = arg4;
    u8* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2F;
        obj[2] = id;
        obj[0x54] = b;
        obj[0x57] = n + 1;
        *(s16*)(obj + 0xA) = x;
        *(s16*)(obj + 0xE) = y;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800EA500(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        if ((u8)D_80097420.transition.selection == 2) {
            arg0[1]++;
            return;
        }
        background_objects[0].x_pos.i.hi = 0;
        background_objects[0].y_pos.i.hi = 0;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 1;
        arg0[0] = 6;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002AA74();

void func_800EA570(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        if (D_80097420.character_mode != 0) {
            arg0[0] = 8;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
        }
        func_8002AA74();
    }
}

// clang-format off
#include "../shared/rock_18/func_800EA5C8.c"
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_800139A0(M2C_UNK);
M2C_UNK reset_level();
void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3);
void func_800ED58C(u8, s8, s16, s16, u8);
void func_800ED61C(s32, s32, s32, s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800EA62C(u8* arg0) {
    ((void (*)())reset_level)();
    if (*(u8*)D_80070CC4 != 0xFF) {
        D_80097420.transition.selection = 0;
        func_800ED58C(0x1F, 0, 0x108, 0x80, 0);
        arg0[1] += 1;
    } else {
        D_80097420.transition.selection = 1;
        func_800ED58C(0x28, 0, 0x108, 0x80, 0);
        arg0[1] += 2;
    }
    func_800ED50C(0x1C, 0, 0x130, 0x30);
    func_800ED50C(0x1E, 0, 0x108, 0x54);
    func_800ED58C(0x20, 0, 0x108, 0xA8, 1);
    func_800ED50C(0x1B, 0, 0xE0, 0xD0);
    func_800ED50C(0x1D, 0, 0x180, 0xD0);
    func_800ED61C(0, 1, 0, 0);
    background_objects[0].unk3 = 1;
    background_objects[0].x_pos.i.hi = 0x200;
    background_objects[0].y_pos.i.hi = 0;
    background_objects[0].unk4C = 1;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 0;
    ((void (*)(s32))func_800139A0)(8);
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800EA76C(u8* arg0) {
    u8 v;

    if (D_80097420.transition.active == 0) {
        s32 one = 1;
        if (g_pad1_buttons[2] & 0x1000) {
            play_sound(0, 0xC, 0);
            v = D_80097420.transition.selection;
            if (v == 0) {
                D_80097420.transition.selection = one;
            } else {
                D_80097420.transition.selection = v - 1;
            }
        } else if (g_pad1_buttons[2] & 0x4000) {
            play_sound(0, 0xC, 0);
            v = D_80097420.transition.selection;
            if (v == one) {
                D_80097420.transition.selection = 0;
            } else {
                D_80097420.transition.selection = v + 1;
            }
        }
        if (g_pad1_buttons[2] & 0x40) {
            play_sound(0, 0x22, 0);
            if (D_80097420.transition.selection != 1) {
                func_800139F4(8);
            }
            arg0[1] += 2;
            *(s16*)(arg0 + 0xA) = D_80097420.transition.selection;
            return;
        }
        if (g_pad1_buttons[2] & 0x10) {
            func_800139F4(8);
            {
                // !FAKE: depin: dropping it breaks the match (80/85)
                register s32 b asm("$2") = arg0[1];
                *(s16*)(arg0 + 0xA) = 2;
                arg0[1] = b + 2;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK create_task(M2C_UNK, M2C_UNK*);
M2C_UNK func_800133A0();
void func_8001BA1C(u8* arg0);
M2C_UNK reset_level();
extern s32 D_8001E6E4;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define ENG(o) (((u8*)&g_playthrough_state)[o])

void func_800EA8C0(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        switch (*(s16*)(arg0 + 0xA)) {
        case 0:
            func_8001BA1C((u8*)D_80070CC4);
            {
                struct X4_EngineObj* e = &g_playthrough_state;
                u8 v = ((u8*)e)[0x158];
                if (v == 0xFF) {
                    g_playthrough_state.state = 3;
                    e->unk1 = 0;
                    e->unk2 = 0;
                    e->unk3 = 0;
                } else {
                    g_playthrough_state.state = 0x13;
                    e->unk1 = 0;
                    e->unk2 = 0;
                    e->unk3 = 0;
                    e->checkpoint = v;
                }
            }
            create_task(1, &D_8001E6E4);
            func_800133A0();
            return;
        case 1:
            reset_level();
            arg0[1] = 5;
            g_playthrough_state.unk1 = 0;
            g_playthrough_state.unk2 = 0;
            g_playthrough_state.unk3 = 0;
            return;
        case 2:
        default:
            background_objects[0].x_pos.i.hi = 0;
            background_objects[0].y_pos.i.hi = 0;
            background_objects[0].unk4C = 1;
            background_objects[0].unk3 = 1;
            arg0[0] = 6;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            break;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80013BD0(s32, s32);
M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3);
extern M2C_UNK* D_800B91B8;

void func_800EA9D0(u8* arg0) {
    s32 k;
    struct X4_QuadObj* q;
    s8* obj;

    ((void (*)())reset_level)();
    {
        s32 b;

        b = (s32)D_800B91B8;
        *(s32*)&D_800E2F90 = b;
        D_800E2F90.y_pos.val = b + 0x200;
        func_80013BD0(b, b + 0x1FFC);
    }
    D_80097420.transition.selection = 0;
    D_800E2F90.x_pos.bytes[1] = 0;
    D_800E2F90.unk6 = 0;
    func_800ED50C(0x24, 0, 0x130, 0x30);
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
    arg0[3] = 0;
    D_800E2F90.x_pos.bytes[2] = 3;
    arg0[1] = arg0[1] + 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

s8 func_8001C1AC(u8);
s32 memcard_read_save_file(s32, u8, s32);
s32 memcard_list_files(u8, void*, void*);
s32 func_8001C5EC(u8);
s32 func_8001C8C4(void*);
M2C_UNK reset_level();
void* alloc_sprite_slot();
void func_800EC114(void);
void func_800ED3F4(s32, s32, s32, s32);
void func_800ED478(u8 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4);
void func_800ED6D4(void*);
extern u8 D_800E9864[];

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define AB_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define AB_SB(p, o) (*(s8*)((u8*)(p) + (o)))

// str 0x800E9864 "BASLUS-01395" = "save file name (product code)"
void func_800EAAC0(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (147/183)
    register u8* self asm("$17") = arg0;
    u32 r;
    s32 t;
    s32 f;
    s16 i;
    u8* obj;

    arg0 = 0;
    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    t = func_8001C5EC((u8)D_800E2F90.unk6);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            AB_B(self, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            AB_B(self, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        AB_B(self, 3) = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        f = 1;
    } else {
        f = 0;
    }
    if (f != 0) {
        return;
    }
    r = func_8001C1AC((u8)D_800E2F90.unk6);
    switch (r) {
    case 1:
        AB_B(self, 1) = 5;
        D_800E2F90.x_pos.bytes[0] = 0;
        AB_B(self, 3) = 1;
        return;
    case 2:
        AB_B(self, 1) = 5;
        D_800E2F90.x_pos.bytes[0] = 1;
        AB_B(self, 3) = r;
        return;
    case 3:
        AB_B(self, 1) = 5;
        D_800E2F90.x_pos.bytes[0] = 1;
        AB_B(self, 3) = 0x12;
        return;
    case 0:
        if (memcard_list_files((u8)D_800E2F90.unk6, D_800E2FA0, D_800E9864) !=
            0) {
            return;
        }
        if (D_800E2FA0[0x14A] != 0) {
            if (memcard_read_save_file(*(s32*)&D_800E2F90, (u8)D_800E2F90.unk6,
                                       0x2000) == 0) {
                func_8001C8C4((void*)D_800E2F90.y_pos.val);
                reset_level();
                AB_H(self, 4) = 1;
                func_800ED6D4(self);
                func_800ED3F4(0x9F, 0, 0x130, 0x1B);
                for (i = 0; i < 8; i++) {
                    func_800ED478(i - 0x60, 0, 0xB0, i * 16 + 0x30, i);
                }
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    AB_B(obj, 0) = 1;
                    AB_H(obj, 0xA) = 0xE0;
                    AB_H(obj, 0xE) = 0xC8;
                    AB_B(obj, 1) = 0x2E;
                    AB_SB(obj, 2) = -0x10;
                }
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    AB_B(obj, 0) = 1;
                    AB_B(obj, 1) = 0x2D;
                    AB_SB(obj, 2) = -0x40;
                }
                AB_B(self, 3) = 3;
                D_80097420.transition.selection = D_8006D620;
                for (i = 0; i < D_80097420.transition.selection; i++) {
                    D_800E2F90.y_pos.val += 0x3BC;
                }
                AB_B(self, 1)++;
                func_800EC114();
            }
        } else {
            AB_B(self, 3) = 2;
            D_800E2F90.x_pos.bytes[0] = 0;
            AB_B(self, 1) = 5;
        }
        break;
    }
}

#undef AB_B
#undef AB_H
#undef AB_SB

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
M2C_UNK reset_level();
void* alloc_sprite_slot();
void func_800EC114(void);
extern s8 D_800CD3F9;
extern void* D_800F1744;

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define AB_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define AB_SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800EAD9C(u8* arg0) {
    s32 t;
    s32 f;
    s32 i;
    u8* obj;

    t = func_8001C5EC((u8)D_800E2F90.unk6);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            AB_B(arg0, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            AB_B(arg0, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        AB_B(arg0, 3) = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        f = 1;
    } else {
        f = 0;
    }
    if (f != 0) {
        return;
    }
    if (g_pad1_buttons[2] & 0x1000) {
        if (D_80097420.transition.selection == 0) {
            for (i = 0; i < 7; i++) {
                D_800E2F90.y_pos.val += 0x3BC;
            }
            { D_80097420.transition.selection = 7; }
        } else {
            s32 y = D_800E2F90.y_pos.val;
            D_80097420.transition.selection--;
            D_800E2F90.y_pos.val = y - 0x3BC;
        }
        func_800EC114();
    }
    if (g_pad1_buttons[2] & 0x4000) {
        if (D_80097420.transition.selection == 7) {
            for (i = 0; i < 7; i++) {
                D_800E2F90.y_pos.val -= 0x3BC;
            }
            { D_80097420.transition.selection = 0; }
        } else {
            s32 y = D_800E2F90.y_pos.val;
            D_80097420.transition.selection++;
            D_800E2F90.y_pos.val = y + 0x3BC;
        }
        func_800EC114();
    }
    if (g_pad1_buttons[2] & 0x10) {
        play_sound(0, 0x22, 0);
        reset_level();
        D_800CD3F9 = 4;
        return;
    }
    if ((g_pad1_buttons[2] & 0x40) && *(u8*)D_800E2F90.y_pos.val != 0xFF) {
        play_sound(0, 0x22, 0);
        D_800E2F90.unk7 = D_80097420.transition.selection;
        obj = alloc_sprite_slot();
        if (obj != 0) {
            AB_B(obj, 0) = 1;
            AB_B(obj, 1) = 0x2D;
            AB_SB(obj, 2) = -0x41;
        }
        D_800F1744 = obj;
        D_800E2F90.x_pos.bytes[2] = 3;
        AB_H(arg0, 0xA) = 1;
        AB_B(arg0, 3) = 4;
        AB_B(arg0, 1)++;
        func_800EC114();
    }
}

#undef AB_B
#undef AB_H
#undef AB_SB

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
void func_800EC114(void);
void func_800ECE54(void);
extern struct X4_EngineObj g_playthrough_state;
extern void* D_800F1744;

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800EAFF0(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (71/91)
    register u8* self asm("$17") = arg0;
    s32 t;
    s32 f;
    u8* p;
    s32 n;

    arg0 = 0;
    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    t = func_8001C5EC((u8)D_800E2F90.unk6);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            AB_B(self, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            AB_B(self, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        AB_B(self, 3) = one;
        do {
            D_80097420.transition.selection = 0;
        } while (0);
        f = 1;
    } else {
        f = 0;
    }
    if (f != 0) {
        return;
    }
    if (g_pad1_buttons[2] & 0xA000) {
        play_sound(0, 0xC, 0);
        g_playthrough_state.unkA ^= 1;
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        p = D_800F1744;
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (g_playthrough_state.unkA == 0) {
            AB_B(self, 1)++;
            func_800ECE54();
            func_800139F4(8);
            return;
        }
        AB_B(self, 3) = 3;
        AB_B(self, 1)--;
        func_800EC114();
    }
}

#undef AB_B

#include "../shared/rock_18/func_800EB15C.c"

#include "common.h"
#include "mmx6/x4.h"

void* alloc_sprite_slot();
s32 func_800ED69C(u8 arg0);
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F0B30[];

static inline void spawn_7b8(u8 spr, s16 x, s16 y) {
    u8* obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2D;
        obj[2] = spr;
        *(s16*)(obj + 0xA) = x;
        *(s16*)(obj + 0xE) = y;
        obj[0x58] = 1;
        obj[0x59] = g_playthrough_state.unk1;
        obj[0x5A] = D_80097420.transition.selection;
    }
}

void func_800EB7B8(s32 a0, s32 a1) {
    s16 arg0 = a0;
    s16 arg1 = a1;
    s32 t;
    s32 i;
    s32 d0;
    s32 d1;
    s32 d2;

    t = 0;
    i = 0;
    do {
        if (func_800ED69C(i & 0xFF) != 0) {
            t++;
        }
        i++;
    } while (i < 0x80);
    if (t >= 999) {
        spawn_7b8(0xB7, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        spawn_7b8(0xB7, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        spawn_7b8(0xB7, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
    } else if (t <= 0) {
        spawn_7b8(0xAE, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
    } else {
        d0 = t / 100;
        d1 = t - d0 * 100;
        d2 = t % 10;
        d1 /= 10;
        if (d0 != 0) {
            spawn_7b8(d0 - 0x52, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        }
        if (d1 != 0 || d0 != 0) {
            spawn_7b8(d1 - 0x52, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        }
        spawn_7b8(d2 - 0x52, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
    }
}

#include "common.h"
#include "mmx6/x4.h"

void* alloc_sprite_slot();
extern struct X4_EngineObj g_playthrough_state;
extern void* D_800E2F9C;
extern s16 D_800F0B30[];

static inline void spawn_bc8(u8 spr, s16 x, s16 y) {
    u8* obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2D;
        obj[2] = spr;
        *(s16*)(obj + 0xA) = x;
        *(s16*)(obj + 0xE) = y;
        obj[0x58] = 1;
        obj[0x59] = g_playthrough_state.unk1;
        obj[0x5A] = D_80097420.transition.selection;
    }
}

void func_800EBBC8(s32 a0, s32 a1, s32 a2) {
    s16 arg0 = a0;
    s16 arg1 = a1;
    s32 t;
    s32 i;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;
    u16* p;

    i = a2 & 1;
    p = (u16*)((u8*)D_800E2F9C + 0xB8);
    i *= 2;
    t = (s16) * (u16*)((u8*)p + i);
    if (t >= 9999) {
        spawn_bc8(0xB7, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        spawn_bc8(0xB7, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        spawn_bc8(0xB7, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
        spawn_bc8(0xB7, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
    } else if (t <= 0) {
        spawn_bc8(0xAE, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
    } else {
        d0 = t / 1000;
        d1 = t % 1000;
        d1 /= 100;
        d2 = t % 1000 - d1 * 100;
        d2 /= 10;
        d3 = t % 10;
        if (d0 != 0) {
            spawn_bc8(d0 - 0x52, D_800F0B30[0] + arg0, D_800F0B30[1] + arg1);
        }
        if (d1 != 0 || d0 != 0) {
            spawn_bc8(d1 - 0x52, D_800F0B30[2] + arg0, D_800F0B30[3] + arg1);
        }
        if (d2 != 0 || d1 != 0 || d0 != 0) {
            spawn_bc8(d2 - 0x52, D_800F0B30[4] + arg0, D_800F0B30[5] + arg1);
        }
        spawn_bc8(d3 - 0x52, D_800F0B30[6] + arg0, D_800F0B30[7] + arg1);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void* alloc_sprite_slot();
void func_800EB15C(s32, s32);
void func_800EB7B8(s32, s32);
void func_800EBBC8(s32, s32, s32);
extern struct X4_EngineObj g_playthrough_state;
extern void* D_800E2F9C;
extern u8 D_800F0930[];
extern u8 D_800F0990[];
extern u8 D_800F09F0[];
extern u8 D_800F0A10[][0xC];

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define T(t, b, i, sz, o) (*(t*)((u8*)(b) + (o) + (i) * (sz)))
#define SAVE ((u8*)D_800E2F90.y_pos.val)

static inline void spawnA(u8 spr, s16 x, s16 y) {
    u8* obj = alloc_sprite_slot();
    if (obj != NULL) {
        B(obj, 0) = 1;
        B(obj, 1) = 0x2D;
        B(obj, 2) = spr;
        H(obj, 0xA) = x;
        H(obj, 0xE) = y;
        B(obj, 0x58) = 1;
        B(obj, 0x59) = g_playthrough_state.unk1;
        B(obj, 0x5A) = D_80097420.transition.selection;
    }
}

static inline void spawnB(u8 spr, s16 x, s16 y) {
    u8* obj = alloc_sprite_slot();
    if (obj != NULL) {
        B(obj, 0) = 1;
        B(obj, 1) = 0x2D;
        B(obj, 2) = spr;
        H(obj, 0xA) = x;
        H(obj, 0xE) = y;
        B(obj, 0x58) = 1;
        B(obj, 0x59) = g_playthrough_state.unk1;
        B(obj, 0x5A) = D_80097420.transition.selection;
    }
}

void func_800EC114(void) {
    u32 i;
    u8 j;
    u8 count;
    u8 id;
    s16 x;
    s16 y;
    u8* e;
    s8* p;
    s32 n;
    s8 z = 0;

    for (i = 0; i < 0x60; i++) {
        e = (u8*)&g_displayed_sprites[i];
        if (SB(e, 1) == 0x2D && SB(e, 0x58) != 0) {
            s8* q = (s8*)e;
            s32 k = 0x60;
            while (k--) {
                *q++ = z;
            }
        }
    }
    g_playthrough_state.unk4 = 2;
    if (UB(SAVE, 0) == 0xFF) {
        {
            u8* obj = alloc_sprite_slot();
            if (obj != NULL) {
                B(obj, 0) = 1;
                B(obj, 1) = 0x2E;
                B(obj, 2) = 0x27;
                H(obj, 0xA) = 0x158;
                H(obj, 0xE) = 0x68;
                B(obj, 0x58) = 1;
                B(obj, 0x59) = g_playthrough_state.unk1;
                B(obj, 0x5A) = D_80097420.transition.selection;
            }
        }
        g_playthrough_state.unk4 = 1;
        return;
    }
    spawnA(0xA8, 0x108, 0x2E);
    for (j = 0; j < 8; j++) {
        if ((UB(SAVE, 0x3A) >> j) & 1) {
            if ((s8)(s32)g_playthrough_state.controlled_player == 0) {
                n = j;
                spawnB(T(u8, D_800F0930, n, 6, 0),
                       T(s16, D_800F0930, n, 6, 2) + 0xA,
                       T(s16, D_800F0930, n, 6, 4) + 4);
            } else {
                n = j + 8;
                spawnB(T(u8, D_800F0930, n, 6, 0),
                       T(s16, D_800F0930, n, 6, 2) + 0xA,
                       T(s16, D_800F0930, n, 6, 4) + 4);
            }
        }
    }
    spawnA(0xA9, 0x172, 0x2E);
    for (j = 0; j < 8; j++) {
        if ((UB(SAVE, 0x3C) >> j) & 1) {
            spawnB(T(u8, D_800F0990, j, 6, 0),
                   T(s16, D_800F0990, j, 6, 2) + 0xA,
                   T(s16, D_800F0990, j, 6, 4) + 4);
        }
    }
    spawnA(0xAA, 0x1DC, 0x2E);
    for (j = 0; j < 4; j++) {
        if (UH(SAVE, 0x14) & T(u16, D_800F09F0, j, 8, 0)) {
            spawnB(T(u8, D_800F09F0, j, 8, 2), T(s16, D_800F09F0, j, 8, 4) - 2,
                   T(u16, D_800F09F0, j, 8, 6) + 0xFFFC);
        }
    }
    spawnA(0x7A, 0x92, 0x5E);
    spawnA(0xAC, 0xAA, 0x60);
    count = 0;
    for (j = 0; j < 0x10; j++) {
        if (*(u32*)((u8*)D_800E2F9C + 0x10) & (1 << j)) {
            count++;
        }
    }
    spawnA(count / 10 + 0xAE, 0xBE, 0x60);
    spawnA(count % 10 + 0xAE, 0xD2, 0x60);
    spawnA(0x7B, 0xFC, 0x5E);
    spawnA(0xAC, 0x114, 0x60);
    count = 0;
    for (; j < 0x20; j++) {
        if (*(u32*)((u8*)D_800E2F9C + 0x10) & (1 << j)) {
            count++;
        }
    }
    spawnA(count / 10 + 0xAE, 0x128, 0x60);
    spawnA(count % 10 + 0xAE, 0x13C, 0x60);
    for (j = 0; j < 0x18; j++) {
        if (W(SAVE, 4) & *(s32*)&D_800F0A10[j][0]) {
            u8* r = D_800F0A10[j];
            spawnB(B(r, 4), H(r, 6) + 0xC, H(r, 8) + 4);
        }
    }
    spawnA(0xAB, 0x108, 0x86);
    spawnA(0x9D, 0x92, 0x93);
    id = UB(SAVE, 0x3D) + 0x84;
    spawnA(id, 0xB4, 0x95);
    spawnA(0xAD, 0xD2, 0x95);
    spawnA(0x9A, 0xE5, 0x93);
    func_800EBBC8(0xFE, 0x96, 0);
    if (UB(SAVE, 0x3B) & 0x10) {
        g_playthrough_state.unk4 = 0;
        spawnA(0x9E, 0x92, 0xA3);
        id = UB(SAVE, 0x3E) + 0x84;
        spawnA(id, 0xB4, 0xA5);
        spawnA(0xAD, 0xD2, 0xA5);
        spawnA(0x9A, 0xE5, 0xA3);
        func_800EBBC8(0xFE, 0xA6, 1);
    }
    spawnA(0x9B, 0x168, 0x8F);
    func_800EB7B8(0x180, 0x91);
    spawnA(0x9C, 0x168, 0xA3);
    func_800EB15C(0x184, 0xA5);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_800122A4();
M2C_UNK func_8001BD40();

extern struct X4_EngineObj g_playthrough_state;
extern void* D_800E2F9C;

void func_800ECE54(void) {
    u8* src;
    u8* dst;
    u8 i;
    u8 j;
    s8 v;

    src = D_800E2F9C;
    dst = (u8*)&g_playthrough_state;
    dst[0x66] = src[1];
    dst[0x68] = src[2];
    *(s32*)(dst + 0x70) = *(s32*)(src + 4);
    for (i = 0; i < 2; i++) {
        {
            u8* d = dst + 0x74;
            u8* s = src + 8;
            s32 o = i << 2;
            *(s32*)(d + o) = *(s32*)(s + o);
        }
    }
    *(s32*)(dst + 0x6C) = *(s32*)(src + 0x10);
    *(u16*)(dst + 0x6A) = *(u16*)(src + 0x14);
    for (i = 0; i < 16; i++) {
        u16* d = button_map;
        u8* s = src + 0x16;
        s32 o = i << 1;
        d[i] = *(u16*)(s + o);
    }
    dst[0x61] = src[0x38];
    dst[0x62] = src[0x39];
    dst[0x5B] = src[0x36];
    dst[0x5C] = src[0x37];
    dst[0x60] = src[0x3A];
    dst[0x5F] = src[0x3B];
    dst[0x69] = src[0x3C];
    v = 2;
    if (*(u16*)(src + 0x14) & D_80071080[3]) {
        v = 4;
    }
    dst[0x39] = v;
    dst[0x63] = 0;
    dst[0x64] = 0;
    dst[0x65] = 0;
    dst[0x8D] = src[0x3D];
    dst[0x8E] = src[0x3E];
    *(s32*)(dst + 0xCC) = *(s32*)(src + 0x40);
    dst[0x43B] = src[0x3F];
    dst[0xC9] = src[0xCC];
    g_temp_options = src[0xCC];
    for (i = 0; i < 16; i++) {
        if (i < 8) {
            {
                u8* d = dst + 0x158;
                u8* s = src + 0xAE;
                s32 o = i;
                *(u8*)(d + o) = *(u8*)(s + o);
            }
        }
        {
            u8* d = dst + 0xD8;
            u8* s = src + 0x44;
            s32 o = i << 2;
            *(s32*)(d + o) = *(s32*)(s + o);
        }
        {
            u8* d = dst + 0x168;
            u8* s = src + 0xBC;
            s32 o = i;
            *(u8*)(d + o) = *(u8*)(s + o);
        }
    }
    for (i = 0; i < 21; i++) {
        {
            u8* d = dst + 0x9E;
            u8* s = src + 0x84;
            s32 o = i << 1;
            *(u16*)(d + o) = *(u16*)(s + o);
        }
    }
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 32; j++) {
            u8* d = dst + 0x178;
            u8* s = src + 0xCE;
            s32 o = j + (i << 5);
            *(u8*)(d + o) = *(u8*)(s + o);
        }
    }
    dst[0xD0] = src[0xB6];
    dst[0xD1] = src[0xB7];
    *(u16*)(dst + 0xD2) = *(u16*)(src + 0xB8);
    *(u16*)(dst + 0xD4) = *(u16*)(src + 0xBA);
    dst[0x438] = src[0xCD];
    for (i = 0; i < 9; i++) {
        {
            u8* d = dst + 0x43C;
            u8* s = src + 0x390;
            s32 o = i << 2;
            *(s32*)(d + o) = *(s32*)(s + o);
        }
    }
    dst[0x38] = 0;
    dst[0x465] = src[0x3B4];
    dst[0x466] = src[0x3B5];
    dst[0x467] = src[0x3B6];
    func_800122A4(((s8*)dst)[0xD0], ((s8*)dst)[0xD1]);
    func_8001BD40();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 D_800C4570;

void func_800ED188(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        if (D_800C4570 & 0x40) {
            play_sound(0, 0x22, 0);
            arg0[1] = arg0[1] + 1;
            *(s16*)(arg0 + 0xA) = (u8)D_80097420.transition.selection;
            return;
        }
        if (D_800C4570 & 0x10) {
            ((void (*)(s32))func_800139F4)(8);
            *(s16*)(arg0 + 0xA) = 2;
            arg0[1] = arg0[1] + 1;
        }
    }
}

#include "common.h"
#include "mmx6/globals.h"

void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3);
void func_800ED58C(u8 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4);
void func_800ED61C(s32, s32, s32, s32);

void func_800ED22C(u8* arg0) {
    if (*(u8*)D_80070CC4 != 0xFF) {
        D_80097420.transition.selection = 0;
        func_800ED58C(0x1F, 0, 0x108, 0x80, 0);
        arg0[1] = 1;
    } else {
        D_80097420.transition.selection = 1;
        func_800ED58C(0x28, 0, 0x108, 0x80, 0);
        arg0[1] = 2;
    }
    func_800ED50C(0x1C, 0, 0x130, 0x30);
    func_800ED50C(0x1E, 0, 0x108, 0x54);
    func_800ED58C(0x20, 0, 0x108, 0xA8, 1);
    func_800ED50C(0x1B, 0, 0xE0, 0xD0);
    func_800ED50C(0x1D, 0, 0x180, 0xD0);
    func_800ED61C(0, 1, 0, 0);
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/game_info.c:func_8001DAD0, AGPL-3.0; proven shared with X6 by exact signature b05a02ff1ea5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EngineObj g_playthrough_state;

void func_800ED330(struct X4_GameInfo* arg0) {
    func_800ED354(&g_playthrough_state);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
extern u16 D_800C4570;
extern void (*D_800F0914[])(struct X4_EngineObj*);

void func_800ED354(struct X4_EngineObj* arg0) {
    u8 var_s0;

    if (D_800CCED1 != 0) {
        struct MainBssState* e = &D_80097420;
        var_s0 = e->transition.selection;
    } else {
        var_s0 = 0;
    }
    D_800F0914[arg0->unk1](arg0);
    {
        struct MainBssState* e = &D_80097420;
        if ((e->transition.selection != var_s0) && !(D_800C4570 & 0x50)) {
            play_sound(0, 0xC, 0);
        }
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();

void func_800ED3F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 a = arg0;
    s8 b = arg1;
    s16 c = arg2;
    s16 d = arg3;
    void* obj = alloc_sprite_slot();

    if (obj != 0) {
        M2C_FIELD(obj, s8*, 0) = 1;
        M2C_FIELD(obj, s8*, 1) = 0x2D;
        M2C_FIELD(obj, s8*, 2) = a;
        M2C_FIELD(obj, s8*, 0x54) = b;
        M2C_FIELD(obj, s8*, 0x57) = 0;
        M2C_FIELD(obj, s8*, 0x58) = 0;
        M2C_FIELD(obj, s16*, 0xA) = c;
        M2C_FIELD(obj, s16*, 0xE) = d;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();

void func_800ED478(u8 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4) {
    void* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 1;
        M2C_FIELD(obj, u8*, 1) = 0x2D;
        M2C_FIELD(obj, u8*, 2) = arg0;
        M2C_FIELD(obj, s8*, 0x54) = arg1;
        M2C_FIELD(obj, u8*, 0x57) = arg4 + 1;
        M2C_FIELD(obj, u8*, 0x58) = 0;
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
    }
}

#include "common.h"

void* alloc_sprite_slot();

void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3) {
    u8* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2E;
        obj[2] = arg0;
        obj[0x54] = arg1;
        obj[0x57] = 0;
        *(s16*)(obj + 0xA) = arg2;
        *(s16*)(obj + 0xE) = arg3;
    }
}

#include "common.h"

void* alloc_sprite_slot();

void func_800ED58C(u8 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4) {
    u8* obj;

    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2E;
        obj[2] = arg0;
        obj[0x54] = arg1;
        obj[0x57] = arg4 + 1;
        *(s16*)(obj + 0xA) = arg2;
        *(s16*)(obj + 0xE) = arg3;
    }
}

#define func_800EA3F0 func_800ED61C
#include "../shared/rock_18/func_800EA3F0.c"
#undef func_800EA3F0

#include "../shared/rock_18/func_800ED69C.c"

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800ED6D4);

#include "../shared/rock_18/func_800ED760.c"
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK create_task(M2C_UNK, M2C_UNK*);
M2C_UNK func_800133A0();
M2C_UNK reset_level();
extern s32 D_8001E6E4;
extern struct X4_EngineObj g_playthrough_state;

void func_800ED7C4(u8* arg0) {
    if (D_80097420.transition.active == 0) {
        reset_level();
        D_8006D620 = D_80097420.transition.selection;
        if (arg0[0x158] == 0xFF) {
            g_playthrough_state.state = 3;
            g_playthrough_state.unk1 = 0;
            g_playthrough_state.unk2 = 0;
            g_playthrough_state.unk3 = 0;
        } else {
            g_playthrough_state.state = 0x13;
            g_playthrough_state.unk1 = 0;
            g_playthrough_state.unk2 = 0;
            g_playthrough_state.unk3 = 0;
            ((u8*)&g_playthrough_state)[0x1D] =
                ((u8*)&g_playthrough_state)[0x158];
        }
        create_task(1, &D_8001E6E4);
        func_800133A0();
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
void func_800ED50C(u8 arg0, s8 arg1, s16 arg2, s16 arg3);

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define AB_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define AB_SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800ED87C(void* arg0) {
    struct X4_QuadObj* q;
    void* obj;
    s32 k;

    reset_level();
    func_800ED50C(0x25, 0, 0x130, 0x30);
    k = 0x10;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = k;
        q->unk2 = k;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        AB_B(obj, 0) = 1;
        AB_H(obj, 0xA) = 0xE0;
        AB_H(obj, 0xE) = 0x58;
        AB_B(obj, 1) = 0x2E;
        AB_SB(obj, 2) = -0x10;
    }
    AB_B(arg0, 1)++;
}

#undef AB_B
#undef AB_H
#undef AB_SB

#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK reset_level();                         /* extern */
extern u16 D_800C4570;
extern s8 D_800CD3F9;

void func_800ED920(void) {
    if (D_800C4570 & 0x40) {
        play_sound(0, 0x22, 0);
        reset_level();
        D_800CD3F9 = 4;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50();
extern u8 D_800F0B44[];
extern s32 D_800F0BF0;

#define SPAD20 (*(s32**)0x1F800020)
#define F_S16(o) M2C_FIELD(self, s16*, (o))
#define F_S32(o) M2C_FIELD(self, s32*, (o))
#define F_U8(o) M2C_FIELD(self, u8*, (o))
#define F_PTR(o) M2C_FIELD(self, void**, (o))

void func_800ED96C(struct X4_BaseObj* self) {
    s32 off;
    u8* e;
    u8 v;
    u8* t;

    F_PTR(0x30) = &D_800F0BF0;
    self->bg_offset = -1;
    self->unk16 = 3;
    self->unk15 = 0;
    F_S16(0x40) = 0x1800;
    self->state++;
    F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[0];
    t = D_800F0B44;
    off = (u8)self->unk2 * 6;
    e = off + t;
    v = e[5];
    F_S16(0x42) = (v & 0xF) | (((v >> 4) + 0x1E0) << 6);
    F_S32(8) = *(s16*)e << 16;
    F_S32(0xC) = ((s16*)(D_800F0B44 + off))[1] << 16;
    F_U8(0x47) = e[4];
    func_8002CB50(self);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CB50();
extern s8 D_800CD3F8[];
extern u8 D_800F0B48;
extern u8 D_800F0B4E;
extern u8 D_800F0B54;
extern u8 D_800F0B5A;

void func_800EDA38(s8* arg0) {
    u8 s;

    if (arg0[2] == 6) {
        arg0[0x16] = 2;
        *(s16*)(arg0 + 0xE) = ((s8)(D_800CD3F8[2] % 4) << 4) + 0x8E;
        switch (D_800CD3F8[2]) {
        case 0:
            arg0[0x47] = D_800F0B48;
            break;
        case 1:
            arg0[0x47] = D_800F0B4E;
            break;
        case 2:
            arg0[0x47] = D_800F0B54;
            break;
        default:
            arg0[0x47] = D_800F0B5A;
            break;
        }
    }
    s = arg0[2];
    if ((u32)(s - 4) < 2U || (s8)s == 7) {
        arg0[3] = 0;
        if (D_80097420.frame_counter & 0x10) {
            func_8002CB50(arg0);
        }
    } else {
        arg0[3] = 1;
        func_8002CB50(arg0);
    }
}

#define func_80041AB8 func_800EDB6C
#define D_80075FD8 D_800F0BF8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
#include "../shared/rock_18/func_800EDBA8.c"
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800CCEDC;
extern u8 D_800F0C04[][3];
extern void (*D_800F0BF8[])(s8*);

#define SPAD20 (*(s32**)0x1F800020)
#define F_U8(o) M2C_FIELD(self, u8*, (o))
#define F_S8(o) M2C_FIELD(self, s8*, (o))
#define F_S16(o) M2C_FIELD(self, s16*, (o))
#define F_PTR(o) M2C_FIELD(self, void**, (o))

void func_800EDBC8(struct X4_BaseObj* self) {
    u8* tmp;
    // !FAKE: depin: dropping it breaks the match (116/123)
    register s32 t asm("$4");

    self->on_screen = 0;
    self->unk15 = 0;
    self->active = 1;
    if (*(s8*)&D_800CCEDC == 0xF) {
        F_S16(0x40) = 0x1800;
        F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[0];
    } else {
        F_S16(0x40) = 0x1900;
        F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[1];
    }
    t = self->unk2;
    F_PTR(0x30) = &D_800F0BF8[3];
    self->bg_offset = -1;
    self->unk16 = 4;
    self->state = 1;
    F_U8(0x47) = 0;
    self->action_phase = 0;
    if ((t & 0xF0) == 0xF0) {
        switch ((u8)self->unk2 & 0xF) {
        case 0:
            self->action = 1;
            break;
        case 1:
            self->action = 2;
            break;
        case 2:
            self->action = 3;
            break;
        case 3:
            self->action = 6;
            break;
        case 4:
            self->action = 4;
            break;
        case 5:
            F_U8(0x47) = F_U8(0x55);
            tmp = (u8*)SPAD20 + SPAD20[1];
            self->action = 0;
            F_S16(0x42) = 0x7844;
            F_PTR(0x3C) = tmp;
            break;
        case 7:
            self->action = 8;
            break;
        case 8:
            self->action = 0x12;
            break;
        case 9:
            self->action = 0x13;
            break;
        }
    } else {
        F_S16(0x42) = (D_800F0C04[(u8)self->unk2][1] & 0xF) |
                      (((D_800F0C04[(u8)self->unk2][1] >> 4) + 0x1E0) << 6);
        F_U8(0x47) = D_800F0C04[(u8)self->unk2][2];
        if (F_U8(0x58) == 0) {
            self->action = D_800F0C04[(u8)self->unk2][0];
        } else {
            self->action = 0x10;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBFC(void*, u8, s16, s16);
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F0E98[];

#define DIGIT(c, n)                                                            \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0E98[(n)],               \
                  self->y_pos.i.hi + D_800F0E98[(n) + 1])

#define PAIR(v, n)                                                             \
    {                                                                          \
        hi_ = (v) / 10;                                                        \
        lo_ = (v) % 10;                                                        \
        DIGIT(hi_ + 0x3F, (n));                                                \
        DIGIT(lo_ + 0x3F, (n) + 2);                                            \
    }

void func_800EDDB4(struct X4_BaseObj* self) {
    s32 time;
    s32 lo_;
    s32 hi_;
    s32 hours;
    s32 minutes;
    s32 seconds;

    if ((u32)((u8)g_playthrough_state.character_state.bytes[0] - 1) < 8U) {
        time = ((s32*)&g_playthrough_state)[0x43C / 4];
    } else {
        time = ((s32*)&g_playthrough_state)[0x90 / 4];
    }
    DIGIT(0x49, 4);
    DIGIT(0x4A, 10);
    if (time > 0x57E3F) {
        DIGIT(0x48, 0);
        DIGIT(0x48, 2);
        DIGIT(0x44, 6);
        DIGIT(0x48, 8);
        DIGIT(0x48, 12);
        DIGIT(0x48, 14);
    } else if (time <= 0) {
        DIGIT(0x3F, 0);
        DIGIT(0x3F, 2);
        DIGIT(0x3F, 6);
        DIGIT(0x3F, 8);
        DIGIT(0x3F, 12);
        DIGIT(0x3F, 14);
    } else {
        hours = time / 3600;
        minutes = time / 60;
        minutes -= hours * 60;
        seconds = time % 60;
        if (hours >= 100) {
            hours = 99;
        }
        PAIR(hours, 0);
        PAIR(minutes, 6);
        seconds = seconds * 100 / 60;
        PAIR(seconds, 12);
    }
    self->state = 2;
}

#include "common.h"
#include "mmx6/x4.h"

void func_800EFBFC(void*, u8, s16, s16);
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F0EB8[];

#define TIME(e, i) (((s32*)(e))[0x43C / 4 + (i)])
#define TIMEP(e, i) (*(s32*)((u8*)(e) + (i) * 4 + 0x43C))
#define TIMES(e) ((s32*)((u8*)(e) + 0x43C))

#define DIGIT(c, n)                                                            \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0EB8[(n)],               \
                  self->y_pos.i.hi + D_800F0EB8[(n) + 1])

#define PAIR(v, n)                                                             \
    {                                                                          \
        hi_ = (v) / 10;                                                        \
        lo_ = (v) % 10;                                                        \
        DIGIT(hi_ + base, (n));                                                \
        DIGIT(lo_ + base, (n) + 2);                                            \
    }

void func_800EE368(struct X4_BaseObj* self) {
    struct X4_EngineObj* e = &g_playthrough_state;
    s32* best;
    s32* times;
    s32 time;
    s32 base;
    s32 lo_;
    s32 hi_;
    s32 hours;
    s32 minutes;
    s32 seconds;

    if (TIME(e, 0) == 0 || e->character_state.bytes[1] != 0) {
        time = TIME(&g_playthrough_state,
                    g_playthrough_state.character_state.bytes[0]);
        base = 0xCE;
    } else {
        times = TIMES(e);
        best = &times[e->character_state.bytes[0]];
        if (TIME(e, 0) < *best) {
            *best = TIME(e, 0);
            base = 0xC2;
        } else {
            base = 0xCE;
        }
        time = TIME(&g_playthrough_state,
                    g_playthrough_state.character_state.bytes[0]);
    }
    DIGIT(base + 0xA, 4);
    DIGIT(base + 0xB, 10);
    if (time > 0x57E3F) {
        DIGIT(base + 9, 0);
        DIGIT(base + 9, 2);
        DIGIT(base + 5, 6);
        DIGIT(base + 9, 8);
        DIGIT(base + 9, 12);
        DIGIT(base + 9, 14);
    } else if (time <= 0) {
        DIGIT(base, 0);
        DIGIT(base, 2);
        DIGIT(base, 6);
        DIGIT(base, 8);
        DIGIT(base, 12);
        DIGIT(base, 14);
    } else {
        hours = time / 3600;
        minutes = time / 60;
        minutes -= hours * 60;
        seconds = time % 60;
        if (hours >= 100) {
            hours = 99;
        }
        PAIR(hours, 0);
        PAIR(minutes, 6);
        seconds = seconds * 100 / 60;
        PAIR(seconds, 12);
    }
    self->state = 2;
}

#include "common.h"
#include "mmx6/x4.h"

void func_800EFBFC(void*, u8, s16, s16);
extern s16 D_800F0E98[];

#define PART(c, n, dx, dy)                                                     \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0E98[(n)] + (dx),        \
                  self->y_pos.i.hi + D_800F0E98[(n) + 1] + (dy))

void func_800EE900(struct X4_BaseObj* self) {
    PART(0x49, 4, 0, 0);
    PART(0x4A, 10, 0, 0);
    PART(0x92, 0, 0x74, 4);
    PART(0x92, 2, 0x74, 4);
    PART(0x92, 6, 0x74, 4);
    PART(0x92, 8, 0x74, 4);
    PART(0x92, 12, 0x74, 4);
    PART(0x92, 14, 0x74, 4);
    self->state = 2;
}

#include "common.h"
#include "mmx6/x4.h"

void func_800EFBFC(void*, u8, s16, s16);
extern s16 D_800F0EB8[];

#define PART(c, n, dx, dy)                                                     \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0EB8[(n)] + (dx),        \
                  self->y_pos.i.hi + D_800F0EB8[(n) + 1] + (dy))

void func_800EEB0C(struct X4_BaseObj* self) {
    PART(0xD8, 4, 0, 0);
    PART(0xD9, 10, 0, 0);
    PART(0xDA, 0, 0x74, 4);
    PART(0xDA, 2, 0x74, 4);
    PART(0xDA, 6, 0x74, 4);
    PART(0xDA, 8, 0x74, 4);
    PART(0xDA, 12, 0x74, 4);
    PART(0xDA, 14, 0x74, 4);
    self->state = 2;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBFC(void*, u8, s16, s16);
extern s32 D_800CCF64;
extern s16 D_800F0ED8[];

#define DIGIT(self, c, i)                                                      \
    func_800EFBFC((self), (c),                                                 \
                  M2C_FIELD(self, s16*, 0xA) + D_800F0ED8[(i) * 2],            \
                  M2C_FIELD(self, s16*, 0xE) + D_800F0ED8[(i) * 2 + 1])

void func_800EED18(void* self) {
    s32 h;
    s32 t;
    s32 o;

    if (D_800CCF64 >= 999) {
        DIGIT(self, 0x48, 0);
        DIGIT(self, 0x48, 1);
        DIGIT(self, 0x48, 2);
    } else if (D_800CCF64 <= 0) {
        DIGIT(self, 0x3F, 2);
    } else {
        h = D_800CCF64 / 100;
        t = D_800CCF64 - h * 100;
        o = D_800CCF64 % 10;
        t /= 10;
        if (h != 0) {
            DIGIT(self, h + 0x3F, 0);
        }
        if (t != 0 || h != 0) {
            DIGIT(self, t + 0x3F, 1);
        }
        DIGIT(self, o + 0x3F, 2);
    }
    M2C_FIELD(self, u8*, 4) = 2;
}

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800EEF88);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBFC(void*, u8, s16, s16);
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800F0EF0[];

#define DIGIT(c, n)                                                            \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0EF0[(n) * 2],           \
                  self->y_pos.i.hi + D_800F0EF0[(n) * 2 + 1])

void func_800EF1F8(struct X4_BaseObj* self) {
    u8* e = (u8*)&g_playthrough_state;
    s32 v;
    s32 th;
    s32 h;
    s32 t;
    s32 o;

    v = ((s16*)&g_playthrough_state)[M2C_FIELD(e, s8*, 0x38) + 0xD2 / 2] -
        M2C_FIELD(e, s16*, 0xD6);
    if (v >= 9999) {
        DIGIT(0x48, 0);
        DIGIT(0x48, 1);
        DIGIT(0x48, 2);
        DIGIT(0x48, 3);
    } else if (v <= 0) {
        DIGIT(0x3F, 3);
    } else {
        th = v / 1000;
        h = v % 1000;
        h /= 100;
        t = v % 1000 - h * 100;
        o = v % 10;
        t /= 10;
        if (th != 0) {
            DIGIT(th + 0x3F, 0);
        }
        if (h != 0 || th != 0) {
            DIGIT(h + 0x3F, 1);
        }
        if (t != 0 || h != 0 || th != 0) {
            DIGIT(t + 0x3F, 2);
        }
        DIGIT(o + 0x3F, 3);
    }
    self->state = 2;
}

#undef DIGIT
#undef M2C_FIELD

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBFC(void*, u8, s16, s16);
extern s16 D_8006D624[];
extern struct X4_EngineObj g_playthrough_state;

void func_800EF548(struct X4_BaseObj* self) {
    u8* e = (u8*)&g_playthrough_state;
    s16 i;
    s16 v = ((s16*)&g_playthrough_state)[M2C_FIELD(e, s8*, 0x38) + 0x69];

    for (i = 0; i < 8; i++) {
        if (v >= D_8006D624[i]) {
            u8* f = (u8*)&g_playthrough_state;
            *(M2C_FIELD(f, s8*, 0x38) + ((u8*)&g_playthrough_state + 0x8D)) = i;
            if (i < 4) {
                func_800EFBFC(self, i - 0x7C, self->x_pos.i.hi - 4,
                              self->y_pos.i.hi);
            } else {
                func_800EFBFC(self, i - 0x7C, self->x_pos.i.hi,
                              self->y_pos.i.hi);
            }
            self->state = 2;
            return;
        }
    }
    self->state = 2;
}

#define func_80041AB8 func_800EF62C
#define D_80075FD8 D_800F0F00
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800EF668
#define D_80075FD8 D_800F0F0C
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800EF6A4);
// clang-format on

#define func_8001A5F8 func_800EF6C4
#include "../shared/stage/func_8001A5F8.c"
#undef func_8001A5F8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCEF8;

void func_800EF6D0(void* arg0) {
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

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCEF8;

void func_800EF72C(void* arg0) {
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

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCEF8;

void func_800EF788(void* arg0) {
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

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCEF8;
extern u16 D_800F0F6C[][2];

void func_800EF7E4(void* arg0) {
    if (D_800CCEF8 == 0x7F) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800CCEF8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
    M2C_FIELD(arg0, u16*, 0xA) =
        D_800F0F6C[(u8)D_80097420.transition.selection][0];
    M2C_FIELD(arg0, u16*, 0xE) =
        D_800F0F6C[(u8)D_80097420.transition.selection][1];
}

#include "../shared/rock_18/func_800EF878.c"

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800EF8D0);

INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800EF964);
// clang-format on

#include "../shared/rock_18/func_800EF9F8.c"

#include "../shared/rock_18/func_800EFA40.c"

#include "common.h"

extern u8 D_800F0C04[][3];

void func_800EFA6C(u8* arg0) {
    u8 v;
    u8 w;

    v = arg0[0x57];
    arg0[3] = 1;
    if (v != 0) {
        if ((v - 1) == D_80097420.transition.selection) {
            *(s16*)(arg0 + 0x42) = 0x784C;
            return;
        }
        w = D_800F0C04[arg0[2]][1];
        *(s16*)(arg0 + 0x42) = (w & 0xF) | (((w >> 4) + 0x1E0) << 6);
    }
}

#include "../shared/rock_18/func_800EFADC.c"

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCEF8;

void func_800EFB44(void* arg0) {
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

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800EFBFC);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800CCEDC;
extern u8 D_800F0F88[][3];
extern void (*D_800F0F80[])(s8*);
void func_800F02F4(void*, s32, s32, s32, s32);

#define SPAD20 (*(s32**)0x1F800020)
#define F_U8(o) M2C_FIELD(self, u8*, (o))
#define F_S16(o) M2C_FIELD(self, s16*, (o))
#define F_PTR(o) M2C_FIELD(self, void**, (o))

void func_800EFC78(struct X4_BaseObj* self) {
    s32 t;

    self->on_screen = 0;
    self->unk15 = 0;
    self->active = 1;
    if (*(s8*)&D_800CCEDC == 0xF) {
        F_S16(0x40) = 0x1800;
        F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[2];
    } else {
        F_S16(0x40) = 0x1900;
        F_PTR(0x3C) = (u8*)SPAD20 + SPAD20[2];
    }
    F_PTR(0x30) = &D_800F0F80[2];
    t = self->unk2;
    F_U8(0x47) = 0;
    self->bg_offset = -1;
    self->unk16 = 0;
    self->state = 1;
    self->action_phase = 0;
    switch (t & 0xF0) {
    case 0xF0:
        F_S16(0x42) = 0x7844;
        F_U8(0x47) = 0;
        self->action = 1;
        if (t < 0x14) {
            func_800F02F4(self, 0xE0, 0, 0, 0);
        }
        break;
    case 0xE0:
        F_S16(0x42) = 0x7844;
        F_U8(0x47) = 0;
        self->action = 2;
        break;
    default:
        F_S16(0x42) = (D_800F0F88[(u8)self->unk2][1] & 0xF) |
                      (((D_800F0F88[(u8)self->unk2][1] >> 4) + 0x1E0) << 6);
        F_U8(0x47) = D_800F0F88[(u8)self->unk2][2];
        if (F_U8(0x58) == 0) {
            self->action = D_800F0F88[(u8)self->unk2][0];
        } else {
            self->action = 3;
        }
        break;
    }
}

// clang-format off
#include "../shared/rock_18/func_800EFDE4.c"
// clang-format on

#include "../shared/rock_18/func_800EFFD4.c"

#define func_80041AB8 func_800F007C
#define D_80075FD8 D_800F1008
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#define func_80041AB8 func_800F00B8
#define D_80075FD8 D_800F1014
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800F00F4);

INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800F0114);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F0F88[][3];

void func_800F0184(u8* arg0) {
    u8 v;
    u8 w;

    v = arg0[0x57];
    arg0[3] = 1;
    if (v != 0) {
        if ((v - 1) == D_80097420.transition.selection) {
            *(s16*)(arg0 + 0x42) = 0x784C;
        } else {
            w = D_800F0F88[arg0[2]][1];
            *(s16*)(arg0 + 0x42) = (w & 0xF) | (((w >> 4) + 0x1E0) << 6);
        }
    }
    if (arg0[0x47] != g_playthrough_state.unk3) {
        arg0[3] = 0;
    }
    arg0[0x47] = g_playthrough_state.unk3;
}

#include "../shared/rock_18/func_800F0218.c"

#define func_800EFADC func_800F028C
#include "../shared/rock_18/func_800EFADC.c"
#undef func_800EFADC

#include "../shared/rock_18/func_800F02F4.c"

#define func_80041AB8 func_800F0388
#define D_80075FD8 D_800F10D0
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800F03C4);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_800F10F8[][2];

void func_800F03E4(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, u16*, 0xA) =
        D_800F10F8[(u8)D_80097420.transition.selection][0];
    M2C_FIELD(arg0, s16*, 0xE) =
        D_800F10F8[(u8)D_80097420.transition.selection][1] - 3;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F1024[][3];

void func_800F0438(void* arg0) {
    u8 v;
    u8 b;

    v = M2C_FIELD(arg0, u8*, 0x57);
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (v != 0) {
        if ((v - 1) == D_80097420.transition.selection) {
            M2C_FIELD(arg0, s16*, 0x42) = 0x78C6;
            return;
        }
        b = D_800F1024[M2C_FIELD(arg0, u8*, 2)][1];
        M2C_FIELD(arg0, s16*, 0x42) = (b & 0xF) | (((b >> 4) + 0x1E0) << 6);
    }
}

#include "../shared/rock_18/func_800F04A8.c"

#include "../shared/rock_18/func_800F04C8.c"

#include "../shared/rock_18/func_800F04F8.c"

#include "../shared/rock_18/func_800F0528.c"

// clang-format off
#include "../shared/rock_18/func_800F05C4.c"

#include "../shared/rock_18/func_800F0618.c"
// clang-format on

#include "common.h"
#include "mmx6/globals.h"

extern u8 D_800F1148[];

// str 0x800F1148 sha1=359bbf181e646fd64258495a1d1ebdd3523de68b = "printable byte run: data, not text"
void func_800F066C(u8* arg0) {
    u8 i;
    u8 sel;
    u16 key;

    i = 0;
    arg0[3] = 1;
    {
        s32 c1 = 1;

        if (D_80073610[arg0[2] & 0xF] == c1) {
            do {
                sel = 0;
            } while (0);
        } else {
        next:
            i++;
            if (i < 0x10) {
                // !FAKE: depin: dropping it breaks the match (61/65)
                register s32 one asm("$4") = 1;

                if ((one << i) == D_80073610[arg0[2] & 0xF]) {
                    sel = i;
                } else {
                    // !FAKE: goto loop; for and for(;;) forms moved bytes
                    goto next;
                }
            }
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (61/65)
        register u16* tbl asm("$2") = button_map;

        key = tbl[sel];
    }
    i = 0;
    do {
        if (key == D_80073620[0]) {
            arg0[0x47] = D_800F1148[0];
            return;
        }
    } while (0);
next2:
    i++;
    if (i < 8) {
        if (key == D_80073620[i]) {
            arg0[0x47] = D_800F1148[i];
        } else {
            // !FAKE: goto loop; for and for(;;) forms moved bytes
            goto next2;
        }
    }
}

#include "../shared/rock_18/func_800F0770.c"

#define func_80041AB8 func_800F07C0
#define D_80075FD8 D_800F10C4
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "../shared/rock_18/func_800F07FC.c"

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800F0870);
// clang-format on

#define func_80041AB8 func_800F0890
#define D_80075FD8 D_800F11FC
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_18/nonmatchings/E9860", func_800F08CC);
// clang-format on
