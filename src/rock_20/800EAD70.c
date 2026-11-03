#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
#include "mmx6/state.h"

void func_800EAD70(u8* arg0) {
    u8 v;
    u8 cur;
    u8* obj = arg0;
    // !FAKE: depin: dropping it breaks the match (66/74)
    register s32 two asm("$17") = 2;

    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        cur = D_80097420.transition.selection;
        if (cur == 0) {
            D_80097420.transition.selection = two;
        } else {
            D_80097420.transition.selection = cur - 1;
        }
    } else if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        cur = D_80097420.transition.selection;
        if (cur == two) {
            D_80097420.transition.selection = 0;
        } else {
            D_80097420.transition.selection = cur + 1;
        }
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        switch (D_80097420.transition.selection) {
        case 0:
            v = 6;
            break;
        case 1:
            v = 7;
            break;
        case 2:
            v = 9;
            break;
        default:
            return;
        }
        obj[1] = v;
        obj[2] = 0;
    }
}

#include "common.h"
#include "mmx6/x4.h"

void func_8001D218();
void func_80025F34();
s32 func_800280F4();
void init_checkpoint_positions(void);
void func_800F02A0(u8, s8, s32, s16);
void func_800F0784(s32);
extern struct X4_EngineObj g_playthrough_state;
#define ENG ((u8*)&g_playthrough_state)

void func_800EAE98(u8* arg0) {
    u8* eng;
    func_8001D218();
    init_checkpoint_positions();
    eng = ENG;
    func_800280F4();
    func_80025F34();
    eng[0x28] = 1;
    func_800F02A0(0x91, 1, 0x187, 0x18);
    arg0[3] = 4;
    func_800F0784(4);
    func_800F02A0(0x8C, 1, 0x108, 0x9E);
    func_800F02A0(0x8D, 1, 0x108, 0xB0);
    func_800F02A0(0xDB, 1, 0x1F2, 0xB0);
    func_800F02A0(0x8E, 1, 0x108, 0xBE);
    func_800F02A0(0x8F, 1, 0x108, 0xCC);
    func_800F02A0(0x90, 1, 0, 0);
    D_80097420.transition.selection = 0;
    if ((u32)(eng[0x26] - 1) < 8U) {
        func_800F02A0(0xF8, 1, 0x140, 0x3C);
    } else {
        func_800F02A0(0xF9, 1, 0x140, 0x3C);
    }
    arg0[2]++;
}
#undef ENG

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800EAFD4(u8* arg0) {
    u8 cur;
    struct MainBssState* eng = &D_80097420;
    s32 one;

    if (eng->transition.active != 0) {
        return;
    }
    one = 1;
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        cur = eng->transition.selection;
        if (cur == 0) {
            eng->transition.selection = one;
        } else {
            eng->transition.selection = cur - 1;
        }
    } else if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        cur = eng->transition.selection;
        if (cur == one) {
            eng->transition.selection = 0;
        } else {
            eng->transition.selection = cur + 1;
        }
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        arg0[2]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800EB0CC(u8* arg0) {
    u8 cur;
    struct MainBssState* eng = &D_80097420;
    s32 one;

    if (eng->transition.active != 0) {
        return;
    }
    one = 1;
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        cur = eng->transition.selection;
        if (cur == 0) {
            eng->transition.selection = one;
        } else {
            eng->transition.selection = cur - 1;
        }
    } else if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        cur = eng->transition.selection;
        if (cur == one) {
            eng->transition.selection = 0;
        } else {
            eng->transition.selection = cur + 1;
        }
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        func_800139F4(8);
        {
            // !FAKE: increment temp in the first return register
            register s32 t asm("$2") = arg0[2] + 1;
            arg0[2] = t;
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
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK* D_800B91B8;

void func_800EB1CC(u8* arg0) {
    u8* bg;
    s32 k;
    struct X4_QuadObj* q;
    s8* obj;

    reset_level();
    {
        s32 base;

        bg = (u8*)background_objects;
        *(s16*)(bg + 0xB2) = 0x200;
        base = (s32)D_800B91B8;
        bg[0xF4] = 1;
        *(s32*)&D_800E2F90 = base;
        D_800E2F90.y_pos.val = base + 0x200;
        func_80013BD0(base, base + 0x1FFC);
    }
    D_80097420.transition.selection = 0;
    D_800E2F90.x_pos.bytes[1] = 1;
    func_800F03B8(0x24, 0, 0x130, 0x30);
    k = 0x10;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = k;
        q->unk2 = k;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        *(s16*)(obj + 0xA) = 0xE0;
        *(s16*)(obj + 0xE) = 0x58;
        obj[0] = 1;
        obj[1] = 0x2E;
        obj[2] = -0x10;
    }
    arg0[3] = 0;
    D_800E2F90.unk6 = 0;
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
void func_800ED45C();
void func_800F02A0(u8, s8, s32, s16);
M2C_UNK func_800F0324(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
void func_800F07B4(void*);
extern u8 D_800E9860[];

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(u8**)((u8*)(p) + (o)))

// str 0x800E9868 "BASLUS-01395" = "save file name (product code)"
void func_800EB2D4(u8* arg0) {
    s32 ret;
    s32 done;
    u32 sel;
    u32 i;
    u8* obj;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2] = D_800E2F90.x_pos.bytes[2] - 1;
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
    sel = func_8001C1AC(D_800E2F90.unk6);
    D_80097420.transition.selection = 0;
    switch (sel) {
    case 1:
        arg0[1] = 0x15;
        D_800E2F90.x_pos.bytes[0] = sel;
        arg0[3] = sel;
        return;
    case 2:
        arg0[2] = 0;
        arg0[1] = arg0[1] + 1;
        return;
    case 3:
        arg0[1] = 0x15;
        D_800E2F90.x_pos.bytes[0] = 2;
        arg0[3] = 0x12;
        return;
    case 0: {
        // !FAKE: depin: dropping it breaks the match (111/242)
        register u8* addr asm("$6") = D_800E9860 + 4;

        if (memcard_list_files(D_800E2F90.unk6, D_800E2FA0, addr) == 0) {
            if (F32(D_800E2FA0, 0x14C) == 0x1E000) {
                if (memcard_list_files(D_800E2F90.unk6, D_800E2FA0,
                                       D_800E9860 + 8) == 0) {
                    if (F8(D_800E2FA0, 0x14A) != 0) {
                        if (memcard_read_save_file(*(s32*)&D_800E2F90,
                                                   D_800E2F90.unk6,
                                                   0x2000) == 0) {
                            func_8001C8C4(((u8*)D_800E2F90.y_pos.val));
                            // !FAKE: goto shares reset tail; copy moved bytes
                            goto block_29;
                        }
                    } else {
                        arg0[1] = 0x15;
                        D_800E2F90.x_pos.bytes[0] = 3;
                        D_80097420.transition.selection = 0;
                        arg0[3] = 5;
                        return;
                    }
                }
            } else if (memcard_list_files(D_800E2F90.unk6, D_800E2FA0,
                                          D_800E9860 + 8) == 0) {
                if (F8(D_800E2FA0, 0x14A) != 0) {
                    if (memcard_read_save_file(*(s32*)&D_800E2F90,
                                               D_800E2F90.unk6, 0x2000) != 0) {
                        return;
                    }
                    ((void (*)(void*))func_8001C8C4)(
                        ((u8*)D_800E2F90.y_pos.val));
                } else {
                    s32 ff = 0xFF;

                    ((u8*)D_800E2F90.y_pos.val)[0] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0x3BC] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0x778] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0xB34] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0xEF0] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0x12AC] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0x1668] = ff;
                    {
                        // !FAKE: depin: dropping it breaks the match (232/242)
                        register u8* p asm("$4") = (u8*)D_800E2F90.y_pos.val;

                        p[0x1A24] = ff;
                    }
                }
            block_29:
                arg0[1] = arg0[1] + 2;
                ((void (*)())reset_level)();
                F16(arg0, 4) = 1;
                do {
                    func_800F07B4(arg0);
                } while (0);
                do {
                    func_800F02A0(0x9F, 0, 0x130, 0x1B);
                } while (0);
                i = 0;
                do {
                    func_800F0324((u8)(i + 0xA0), 0, 0xB0, (s16)(i * 16 + 0x30),
                                  (u8)i);
                    i++;
                } while (i < 8);
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    obj[0] = 1;
                    F16(obj, 0xA) = 0xE0;
                    F16(obj, 0xE) = 0xC8;
                    obj[1] = 0x2E;
                    ((s8*)obj)[2] = -0x10;
                }
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    obj[0] = 1;
                    obj[1] = 0x2D;
                    ((s8*)obj)[2] = -0x40;
                }
                arg0[3] = 8;
                D_80097420.transition.selection = D_8006D620;
                for (i = 0; i < (u8)D_80097420.transition.selection; i++) {
                    D_800E2F90.y_pos.val += 0x3BC;
                }
                func_800ED45C();
            }
        }
        break;
    }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_20.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
void* alloc_sprite_slot();
extern u16 D_800C4570;

void func_800EB69C(u8* arg0) {
    s32 ret;
    s32 done;
    u8* obj;

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
    if (D_800C4570 & 0x40) {
        play_sound(0, 0x22, 0);
        arg0[3] = 7;
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2D;
            ((s8*)obj)[2] = -0x42;
        }
        *(u8**)(D_800F366C + 0x1290) = obj;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[2] = arg0[2] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/rock_20.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800EB78C(u8* arg0) {
    s32 ret;
    s32 done;
    s32 n;
    u8* p;
    u8* obj;
    struct X4_QuadObj* q;

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
    if (g_pad1_buttons[2] & 0xA000) {
        play_sound(0, 0xC, 0);
        g_playthrough_state.unkA ^= 1;
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        p = *(u8**)(D_800F366C + 0x1290);
        n = 0x5F;
        do {
            *p = 0;
            p++;
        } while (n--);
        if (g_playthrough_state.unkA == 0) {
            s32 k = 0x10;

            ((void (*)())reset_level)();
            func_800F03B8(0x26, 0, 0x130, 0x30);
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
                ((s8*)obj)[2] = -0x10;
            }
            arg0[3] = 0xE;
            D_800E2F90.x_pos.bytes[2] = 3;
            arg0[2] = arg0[2] + 1;
            return;
        }
        ((void (*)())reset_level)();
        arg0[1] = 6;
        arg0[2] = 6;
        arg0[3] = 0;
    }
}
