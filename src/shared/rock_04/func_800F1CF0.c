// rolefeed (3.1 T4): func_800F1CF0 of src/rock_04/E9860.c
#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/rock_04.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
void func_800F4FD8(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F7518[])(void*);

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
s32 random_byte();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F5360(void*, s32);
extern struct X4_PlayerObj g_Player;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F1CF0(void* arg0) {
    move_object(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (110/112)
        register s32 f asm("$2") = UB(arg0, 0x15);
        if (f == 0) {
            if (g_Player.x_pos.i.hi >= SH(arg0, 0xA) || (UB(arg0, 0x70) & 2)) {
                set_animation(arg0, 0x17);
                {
                    // !FAKE: depin: dropping it breaks the match (24/112)
                    register s32 k asm("$2") = 0xFFFA0000;
                    W(arg0, 0x20) = k;
                }
                UH(arg0, 0x7C) = 8;
                {
                    // !FAKE: depin: dropping it breaks the match (26/112)
                    register s32 c asm("$3") = UB(arg0, 6);
                    UB(arg0, 6) = c + 1;
                }
                return;
            }
            if (SH(arg0, 0x84) >= SH(arg0, 0xA)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) - ((random_byte() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x10);
            }
        } else {
            if (g_Player.x_pos.i.hi <= SH(arg0, 0xA) || (UB(arg0, 0x70) & 1)) {
                set_animation(arg0, 0x17);
                {
                    // !FAKE: depin: dropping it breaks the match (25/112)
                    register s32 k asm("$2") = 0x60000;
                    W(arg0, 0x20) = k;
                }
                UH(arg0, 0x7C) = 8;
                {
                    // !FAKE: depin: dropping it breaks the match (27/112)
                    register s32 c asm("$3") = UB(arg0, 6);
                    UB(arg0, 6) = c + 1;
                }
                return;
            }
            if (SH(arg0, 0xA) >= SH(arg0, 0x84)) {
                SH(arg0, 0x84) =
                    UH(arg0, 0xA) + ((random_byte() & 0x1F) | 0x20);
                func_800F513C(arg0, 0x10);
            }
        }
    }
    if (g_Player.action == 9 || g_Player.action == 0xB ||
        g_Player.action == 0x34) {
        SB(arg0, 5) = 9;
        SB(arg0, 6) = 0;
        return;
    }
    if (--SH(arg0, 0x7C) == 0) {
        UH(arg0, 0x7C) = 8;
        func_800F5360(arg0, 1);
    }
}
