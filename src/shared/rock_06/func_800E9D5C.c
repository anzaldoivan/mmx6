#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_80030ECC();
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800E9D5C(u8* self) {
    *(s16*)(self + 0xE) =
        *(s16*)(self + 0x86) +
        (background_objects[0].y_pos.i.hi - background_objects[1].y_pos.i.hi);
    if (g_playthrough_state.stage == 4) {
        if (g_playthrough_state.substage == 0) {
            if (*(s8*)(self + 2) == 0) {
                if (g_playthrough_state.checkpoint <= 0) {
                    return;
                }
            } else if (g_playthrough_state.checkpoint < 2) {
                return;
            }
        } else {
            if (*(s8*)(self + 2) == 0x70 && (self[0x72] & 4)) {
                func_80030ECC(self);
            }
            if (D_800970AA < 0x1180 && g_playthrough_state.checkpoint <= 0) {
                return;
            }
        }
        clear_object_slot(self);
    } else if (g_playthrough_state.stage >= 0x13 &&
               g_playthrough_state.checkpoint > 0) {
        clear_object_slot(self);
    }
}
