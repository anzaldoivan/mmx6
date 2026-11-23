// rolefeed (3.1 T4): func_800F18C4 of src/rock_04/E9860.c
#include "common.h"
#include "mmx6/globals.h"
extern u32 D_800F7840;
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 func_80030ECC();
s32 check_enemy_hits(void*);
void func_800F4FD8(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F7518[])(void*);

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u32 D_800F7840;

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F54B8(s32, void*);
extern struct X4_EngineObj g_playthrough_state;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F18C4(void* arg0) {
    void* parent;

    parent = P(arg0, 0x80);
    UB(arg0, 3) = 0;
    if (SB(parent, 0) != 0) {
        if (SB(parent, 7) == 0) {
            if ((s16)--UH(arg0, 0x7E) == -1) {
                UH(arg0, 0x7E) = 5;
                UH(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        P(arg0, 0x80) = NULL;
        W(arg0, 0x84) = 0;
        W(arg0, 0x88) = 0;
        W(arg0, 0x8C) = 0;
        W(arg0, 0x90) = 0;
        W(arg0, 0x94) = 0;
        g_playthrough_state.enable_boss = 0;
        g_playthrough_state.boss_ptr = NULL;
        if (g_playthrough_state.stage != 0xC) {
            if (D_800F7840 < 0x1519) {
                func_800F54B8(0x10, &g_playthrough_state);
            } else {
                func_800F54B8(0x11, &g_playthrough_state);
            }
        } else {
            g_playthrough_state.unkF = -0x80;
            g_playthrough_state.character_state
                .bytes[g_playthrough_state.checkpoint + 6] = 1;
            g_playthrough_state.checkpoint += 8;
        }
        clear_object_slot(arg0);
    }
}
