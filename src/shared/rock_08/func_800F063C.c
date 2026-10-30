#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

void* enemy_slot_alloc();
M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F6AF4;

void func_800F063C(void* arg0) {
    s8* p;
    s8* t;

    t = FLD(arg0, s8*, 0x8C);
    FLD(arg0, s8, 0x3) = 0;
    if (t[0] != 0) {
        if (t[7] == 0) {
            if (--FLD(arg0, s16, 0x7E) == -1) {
                FLD(arg0, s16, 0x7E) = 5;
                FLD(arg0, u16, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        FLD(arg0, s32, 0x80) = 0;
        FLD(arg0, s32, 0x84) = 0;
        FLD(arg0, s32, 0x88) = 0;
        FLD(arg0, s32, 0x8C) = 0;
        FLD(arg0, s32, 0x90) = 0;
        FLD(arg0, s32, 0x94) = 0;
        g_playthrough_state.enable_boss = 0;
        g_playthrough_state.boss_ptr = 0;
        if (g_playthrough_state.stage != 0xC) {
            if ((u32)D_800F6AF4 < 0x1519) {
                p = enemy_slot_alloc();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0xF;
                    p[2] = 0x10;
                }
            } else {
                p = enemy_slot_alloc();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0xF;
                    p[2] = 0x11;
                }
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
