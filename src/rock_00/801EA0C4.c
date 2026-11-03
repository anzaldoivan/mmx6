// clang-format off
INCLUDE_ASM("asm/rock_00/nonmatchings/1EA000", func_801EA0C4);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_spawn_weapon(M2C_UNK, s8, M2C_UNK, void*);
struct X4_VisualObj* find_free_visual_obj(void);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern s8 D_801F4DD8;
extern u8 D_801F4DD9;
extern s32 D_801F4DE8[];

void func_801EA2B8(u8* arg0) {
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 kind;
    struct X4_PlayerObj* player;
    u16 t;
    u8* obj;

    if (--arg0[0xE1] == 0) {
        arg0[0xE1] = (random_byte() % 3) + 3;
        player_spawn_weapon(1, 0x31, D_801F4DD8, 0);
        D_801F4DD8 ^= 1;
    }
    if ((s8)++arg0[7] >= 0x79) {
        arg0[6]++;
        if (arg0[0x17] >= 0xB1) {
            player_set_animation(arg0, 0xB3);
        } else {
            player_set_animation(arg0, 0xB0);
        }
    }
    if (++D_801F4DD9 == 2) {
        for (i = 0; i < 16; i++) {
            D_80090C90[i + 16] = D_801F4DE8[i];
        }
        {
            s8* p0 = &D_80090D56;
            s8* p1 = &D_8009742C;
            s8* p2 = &D_800CF850;
            p0[1] = 1;
            p1[1] = 1;
            p2[1] = 1;
        }
        player = &g_Player;
        kind = 0;
        if (player->character != 0) {
            a = 0x53;
            b = 0x54;
        } else {
            a = 0x55;
            b = 0x56;
        }
        j = 0;
        do {
            j++;
            obj = (u8*)find_free_visual_obj();
            if (obj != 0) {
                // !FAKE: depin: dropping it breaks the match (3/186)
                register s32 x asm("$2") = 0x80;
                // !FAKE: depin: dropping it breaks the match (177/186)
                register s32 y asm("$3") = j << 6;
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = a;
                M2C_FIELD(obj, s16*, 0xA) = x;
                M2C_FIELD(obj, s16*, 0xE) = y;
                obj[5] = player->action;
            }
            obj = (u8*)find_free_visual_obj();
            if (obj != 0) {
                // !FAKE: depin: dropping it breaks the match (3/186)
                register s32 x asm("$2") = 0x180;
                // !FAKE: depin: dropping it breaks the match (177/186)
                register s32 y asm("$3") = j << 6;
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = b;
                M2C_FIELD(obj, s16*, 0xA) = x;
                M2C_FIELD(obj, s16*, 0xE) = y;
                obj[5] = player->action;
            }
        } while (j < 5);
    }
    if (((s8*)arg0)[7] >= 0x73) {
        u16* q0 = (u16*)&D_800CF854;
        t = q0[1];
        if (t != 0) {
            u16* q1;
            u16* q2;
            q0[1] = t - 8;
            q1 = (u16*)&D_80097430;
            q2 = (u16*)&D_80090D5C;
            q1[1] -= 0x100;
            q2[1] -= 0x2000;
            if ((u16)(t - 8) < 8) {
                q2[1] = 0;
                q1[1] = 0;
                q0[1] = 0;
                arg0[0xE4] &= 0xFE;
                D_800C4560 |= 1;
            }
        }
    }
}
#undef g_Player

// clang-format off
INCLUDE_ASM("asm/rock_00/nonmatchings/1EA000", func_801EA5A0);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void animate_object(struct X4_AnimatedObj*);
void* func_8002C32C();
struct X4_VisualObj* find_free_visual_obj(void);
void func_801EC6D0(void*, s32);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern u8 D_801F4DD9;
extern s32 D_801F4DE8[];

void func_801EA724(u8* arg0) {
    s32 i;
    s32 j;
    s32 kind;
    u16 t;
    u8* obj;
    struct X4_PlayerObj* player;

    if (D_801F4DD9 != 0) {
        if (--D_801F4DD9 != 0) {
            return;
        }
        for (i = 0; i < 16; i++) {
            D_80090C90[i + 16] = D_801F4DE8[i];
        }
        player = &g_Player;
        {
            s8* p0 = &D_80090D56;
            s8* p1 = &D_8009742C;
            s8* p2 = &D_800CF850;
            p0[1] = 1;
            p1[1] = 1;
            p2[1] = 1;
        }
        kind = 1;
        if (player->facing != 0) {
            kind = 2;
        }
        for (j = 0; j < 5; j++) {
            obj = (u8*)find_free_visual_obj();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = 0x55;
                M2C_FIELD(obj, s16*, 0xA) = j << 6;
                M2C_FIELD(obj, s16*, 0xE) = 0x80;
                obj[5] = player->action;
            }
        }
        obj = (u8*)find_free_visual_obj();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x11;
            obj[2] = kind;
            obj[0x47] = 0x55;
            if (kind == 1) {
                M2C_FIELD(obj, s16*, 0xA) = 0x140;
            } else {
                M2C_FIELD(obj, s16*, 0xA) = -0x40;
            }
            M2C_FIELD(obj, s16*, 0xE) = 0x80;
            obj[5] = player->action;
        }
        arg0[0xE1] = 0;
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2F;
            obj[2] = 0;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
        }
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2F;
            obj[2] = 1;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
        }
        if (D_801F4DD9 != 0) {
            return;
        }
    }
    animate_object((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[7] == 0) {
        func_801EC6D0(arg0, 0x32);
    } else {
        func_801EC6D0(arg0, 0x33);
    }
    if (++arg0[0xE1] >= 0x95) {
        arg0[6]++;
    }
    if (arg0[0xE1] >= 0x8F) {
        u16* q0 = (u16*)&D_800CF854;
        t = q0[1];
        if (t != 0) {
            u16* q1;
            u16* q2;
            q0[1] = t - 8;
            q1 = (u16*)&D_80097430;
            q2 = (u16*)&D_80090D5C;
            q1[1] -= 0x100;
            q2[1] -= 0x2000;
            if ((u16)(t - 8) < 8) {
                q2[1] = 0;
                q1[1] = 0;
                q0[1] = 0;
                arg0[0xE4] &= 0xFE;
                D_800C4560 |= 1;
            }
        }
    }
}
#undef g_Player

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void animate_object(struct X4_AnimatedObj*);
void* func_8002C32C();
s32 select_air_dash(void*);
s32 try_enter_wall_cling(void*);
M2C_UNK end_dash(s32);
M2C_UNK player_set_animation(void*, M2C_UNK);

void func_801EAA38(u8* arg0) {
    s32 flag;
    u8 bits;
    u8* obj;
    s8 st;

    flag = 0;
    if (((s8*)arg0)[0xD3] != 0) {
        end_dash((s32)arg0);
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        end_dash((s32)arg0);
        return;
    }
    if (((s8*)arg0)[0x93] != 0) {
        if (((s8*)arg0)[6] == 0) {
            arg0[6]++;
            return;
        }
        animate_object((struct X4_AnimatedObj*)arg0);
        if (((s8*)arg0)[0x45] & 0x80) {
            arg0[0x45] &= 0x7F;
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x33;
                obj[0x14] = arg0[0x14];
                M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                obj[0x15] = arg0[0x15];
            }
        }
        if (((s8*)arg0)[0x46] != 0) {
            return;
        }
        end_dash((s32)arg0);
        return;
    }
    bits = arg0[0x89];
    if (bits & 8) {
        end_dash((s32)arg0);
        return;
    }
    if ((bits & 4) && M2C_FIELD(arg0, s32*, 0x24) > 0) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (((s8*)arg0)[6] == 0) {
        arg0[6]++;
    } else {
        animate_object((struct X4_AnimatedObj*)arg0);
        if (((s8*)arg0)[0x45] & 0x80) {
            arg0[0x45] &= 0x7F;
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x33;
                obj[0x14] = arg0[0x14];
                M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                obj[0x15] = arg0[0x15];
            }
        }
        if (((s8*)arg0)[0x46] == 0) {
            flag = 1;
        }
    }
    if (arg0[0x45] & 0x40) {
        if (try_enter_wall_cling(arg0) != 0) {
            return;
        }
        if (select_air_dash(arg0) != 0) {
            return;
        }
    }
    set_air_x_velocity(arg0);
    func_8003D394(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (152/154)
        register s32 t asm("$3") = ((s8*)arg0)[0x67];
        if (t > 0 && M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            ((s8*)arg0)[0x67] = -1;
        }
    }
    if (flag != 0) {
        if (((s8*)arg0)[0x67] > 0) {
            player_set_animation(arg0, 0xA);
            st = 6;
        } else {
            player_set_animation(arg0, 0xB);
            st = 7;
        }
        arg0[5] = st;
        arg0[6] = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void animate_object(struct X4_AnimatedObj*);
void* func_8002C32C();
M2C_UNK end_dash(s32);
M2C_UNK player_set_animation(void*, M2C_UNK);

void func_801EACA0(u8* arg0) {
    u8* obj;
    s32 bits;
    s32 flag;

    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        ((void (*)())end_dash)();
        return;
    }
    if (((s8*)arg0)[0x93] != 0) {
        if (((s8*)arg0)[6] == 0) {
            arg0[6]++;
        } else {
            animate_object((struct X4_AnimatedObj*)arg0);
        }
        if (((s8*)arg0)[0x45] & 0x80) {
            arg0[0x45] &= 0x7F;
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x33;
                obj[0x14] = arg0[0x14];
                M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                obj[0x15] = arg0[0x15];
            }
        }
        if (((s8*)arg0)[0x46] == 0) {
            ((void (*)(void*, s32))player_set_animation)(arg0, 0xF);
            arg0[5] = 0xB;
            arg0[6] = 0;
        }
    } else {
        bits = arg0[0x89];
        if (bits & 8) {
            end_dash((s32)arg0);
            return;
        }
        flag = ((s8*)arg0)[0xD3] != 0;
        if (!(bits & 3)) {
            flag = 1;
        }
        if (flag != 0) {
            func_8003AFF4((s32)arg0);
            return;
        }
        if (try_wall_jump(arg0) == 0) {
            if (is_pressing_into_wall(arg0) != 0) {
                if (((s8*)arg0)[6] == 0) {
                    arg0[6]++;
                } else {
                    animate_object((struct X4_AnimatedObj*)arg0);
                }
                if (((s8*)arg0)[0x45] & 0x80) {
                    arg0[0x45] &= 0x7F;
                    obj = func_8002C32C();
                    if (obj != 0) {
                        obj[0] = 1;
                        obj[1] = 0x33;
                        obj[0x14] = arg0[0x14];
                        M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                        obj[0x15] = arg0[0x15];
                    }
                }
                if (!(arg0[0x45] & 0x40) || try_shoot_in_air(arg0) == 0) {
                    move_by_velocity(arg0);
                    func_8003D394(arg0);
                    bits = ((s8*)arg0)[0x46];
                    if (bits == 0) {
                        ((void (*)(void*, s32))player_set_animation)(arg0, 0xF);
                        arg0[5] = 0xB;
                        arg0[6] = 0;
                    }
                }
            } else {
                func_8003B5B8(arg0);
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_spawn_visual(M2C_UNK, M2C_UNK, s8, M2C_UNK);

void func_801EAECC(u8* arg0) {
    s32 v;
    u16 flags;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        arg0[0x15] = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        arg0[0x15] = 0x40;
    }
    if (((s8*)arg0)[0x46] != 0) {
        return;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 0x180) {
        if (++arg0[0xD9] < 0x78) {
            return;
        }
    }
    play_sound(1, 5, arg0);
    flags = M2C_FIELD(arg0, u16*, 0x7C);
    if (flags & 4) {
        player_set_animation(arg0, 0xBE);
        v = M2C_FIELD(arg0, s32*, 0x108);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = v * 2;
    } else if (flags & 8) {
        player_set_animation(arg0, 0xBF);
        v = M2C_FIELD(arg0, s32*, 0x108);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = -v * 2;
    } else {
        player_set_animation(arg0, 0xC0);
        {
            // !FAKE: depin: dropping it breaks the match (86/88)
            register s32 t asm("$2") = arg0[0x15];
            if (t != 0) {
                v = M2C_FIELD(arg0, s32*, 0x108) * 2;
            } else {
                v = -M2C_FIELD(arg0, s32*, 0x108) * 2;
            }
        }
        M2C_FIELD(arg0, s32*, 0x20) = v;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    arg0[0x8C] = 1;
    arg0[0x7A] = 1;
    arg0[6]++;
    player_spawn_visual(0x21, 0x19, 0, 0);
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void animate_object(struct X4_AnimatedObj*);
void* func_8002C32C();
M2C_UNK end_dash(s32);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK player_spawn_weapon(M2C_UNK, s8, M2C_UNK, void*);

void func_801EB02C(u8* arg0) {
    u8* obj;
    s32 kind;
    // !FAKE: depin: dropping it breaks the match (81/87)
    register s32 one asm("$2");

    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        end_dash((s32)arg0);
        return;
    }
    if (((s8*)arg0)[6] == 0) {
        arg0[6]++;
    } else {
        animate_object((struct X4_AnimatedObj*)arg0);
    }
    if (((s8*)arg0)[0x45] & 0x80) {
        player_spawn_weapon(1, 0x38, 0, 0);
    }
    if (arg0[0x17] == 0xB7) {
        if (((s8*)arg0)[0x45] & 0x80) {
            arg0[0x45] &= 0x7F;
            obj = func_8002C32C();
            if (obj != 0) {
                one = 1;
                kind = 0x32;
                obj[0] = one;
                obj[1] = kind;
                obj[0x14] = arg0[0x14];
                M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                obj[0x15] = arg0[0x15];
            }
        }
    } else if (((s8*)arg0)[0x45] & 0x80) {
        arg0[0x45] &= 0x7F;
        obj = func_8002C32C();
        if (obj != 0) {
            one = 1;
            kind = 0x33;
            obj[0] = one;
            obj[1] = kind;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
            obj[0x15] = arg0[0x15];
        }
    }
    if (((s8*)arg0)[0x46] == 0) {
        if (((s8*)arg0)[7] == 2) {
            ((void (*)(void*, s32))player_set_animation)(arg0, 0xF);
            arg0[5] = 0xB;
            arg0[6] = 0;
            return;
        }
        end_dash((s32)arg0);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_00/nonmatchings/1EA000", func_801EB188);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void animate_object(struct X4_AnimatedObj*);
void* func_8002C32C();
struct X4_VisualObj* find_free_visual_obj(void);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern u8 D_801F4DD9;
extern s32 D_801F4DE8[];

void func_801EB31C(u8* arg0) {
    s32 i;
    s32 j;
    s32 kind;
    u16 t;
    u8* obj;
    struct X4_PlayerObj* player;

    if (D_801F4DD9 != 0) {
        if (--D_801F4DD9 != 0) {
            return;
        }
        for (i = 0; i < 16; i++) {
            D_80090C90[i + 16] = D_801F4DE8[i];
        }
        {
            s8* p0 = &D_80090D56;
            s8* p1 = &D_8009742C;
            s8* p2 = &D_800CF850;
            p0[1] = 1;
            p1[1] = 1;
            player = &g_Player;
            p2[1] = 1;
        }
        arg0[0xE1] = 0;
        kind = 1;
        if (player->facing != 0) {
            kind = 2;
        }
        for (j = 0; j < 5; j++) {
            obj = (u8*)find_free_visual_obj();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = 0x55;
                M2C_FIELD(obj, s16*, 0xA) = j << 6;
                M2C_FIELD(obj, s16*, 0xE) = 0x80;
                obj[5] = player->action;
            }
        }
        obj = (u8*)find_free_visual_obj();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x11;
            obj[2] = kind;
            obj[0x47] = 0x55;
            if (kind == 1) {
                M2C_FIELD(obj, s16*, 0xA) = 0x140;
            } else {
                M2C_FIELD(obj, s16*, 0xA) = -0x40;
            }
            M2C_FIELD(obj, s16*, 0xE) = 0x80;
            obj[5] = player->action;
        }
        if (D_801F4DD9 != 0) {
            return;
        }
    }
    animate_object((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[7] == 0) {
        if (((s8*)arg0)[0x45] & 0x80) {
            arg0[0x45] &= 0x7F;
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x32;
                obj[0x14] = arg0[0x14];
                M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                obj[0x15] = arg0[0x15];
            }
        }
    } else {
        if (((s8*)arg0)[0x45] & 0x80) {
            arg0[0x45] &= 0x7F;
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x33;
                obj[0x14] = arg0[0x14];
                M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                obj[0x15] = arg0[0x15];
            }
        }
    }
    if (arg0[0xE1] == 2 && ((s8*)arg0)[0x46] == 0) {
        u16* q0 = (u16*)&D_800CF854;
        t = q0[1];
        if (t != 0) {
            u16* q1;
            u16* q2;
            q0[1] = t - 8;
            q1 = (u16*)&D_80097430;
            q2 = (u16*)&D_80090D5C;
            q1[1] -= 0x100;
            q2[1] -= 0x2000;
            if ((u16)(t - 8) < 8) {
                q2[1] = 0;
                q1[1] = 0;
                q0[1] = 0;
                arg0[0xE4] &= 0xFE;
                D_800C4560 |= 1;
                arg0[6]++;
            }
        }
    }
}
#undef g_Player

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

void animate_object(struct X4_AnimatedObj*);
M2C_UNK player_set_animation(void*, M2C_UNK);
M2C_UNK set_stand_animation_by_hp(void*);
M2C_UNK func_801EBF28();
extern struct X4_EngineObj g_playthrough_state;

void update_x_stand_animation(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
        func_801EBF28(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x90) != 0) {
        set_stand_animation_by_hp(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x17) == 6) {
        struct X4_EngineObj* e =
            (struct X4_EngineObj*)((s8*)&g_playthrough_state -
                                   -M2C_FIELD(arg0, s8*, 2));
        if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)(M2C_FIELD(e, s8*, 0x5B) / 3)) {
            player_set_animation(arg0, 5);
            return;
        }
    }
    animate_object(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_801EBF5C(); /* extern */

void player_enter_ladder_shoot(void* arg0) {
    func_801EBF5C();
    M2C_FIELD(arg0, s16*, 8) = 0;
    M2C_FIELD(arg0, s16*, 0xC) = 0;
    M2C_FIELD(arg0, s8*, 5) = 0x20;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, u16*, 0xA) =
        (u16)((M2C_FIELD(arg0, u16*, 0xA) & 0xFFF0) + 8);
}
