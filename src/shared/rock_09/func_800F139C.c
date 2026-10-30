#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* enemy_slot_alloc();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern u32 D_800F6C0C;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F139C(void* arg0) {
    void* parent;
    s8* p;

    parent = P(arg0, 0x80);
    if (SB(parent, 0) != 0) {
        if (SB(parent, 7) == 0) {
            if ((s16)--UH(arg0, 0x7E) == -1) {
                UH(arg0, 0x7E) = 5;
                UH(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x80, 0x80);
        }
    } else {
        if (g_playthrough_state.stage != 0xC) {
            if (D_800F6C0C < 0x1519) {
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
