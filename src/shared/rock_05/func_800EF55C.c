#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

void* enemy_slot_alloc();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F4490;

void func_800EF55C(struct X4_MainObj* self) {
    s8* p;
    s8* obj;
    // !FAKE: depin: dropping it breaks the match (84/93)
    register s32 y asm("$5");

    self->on_screen = 0;
    p = *(s8**)(SCRATCH_4C + 0x80);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--self->unk7E == -1) {
                self->unk7E = 5;
                self->unk42 ^= 0x8000;
            }
            func_8002CCB0(self, 0x60, 0x60);
        }
    } else {
        if (g_playthrough_state.stage != 0xC) {
            if ((u32)D_800F4490 < 0x1519) {
                obj = enemy_slot_alloc();
                if (obj != 0) {
                    obj[0] = 0x41;
                    obj[1] = 0xF;
                    obj[2] = 0x10;
                }
            } else {
                obj = enemy_slot_alloc();
                if (obj != 0) {
                    obj[0] = 0x41;
                    obj[1] = 0xF;
                    obj[2] = 0x11;
                }
            }
        } else {
            g_playthrough_state.unkF = -0x80;
            g_playthrough_state.character_state
                .bytes[g_playthrough_state.checkpoint + 6] = 1;
            g_playthrough_state.checkpoint += 8;
        }
        g_playthrough_state.enable_boss = 0;
        g_playthrough_state.boss_ptr = 0;
        y = background_objects[0].y_pos.u.hi;
        background_objects[0].unk2A = y;
        clear_object_slot(self, y);
    }
}
