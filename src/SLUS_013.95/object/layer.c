/* Adapted from sozud/mmx4 @4e16dfc src/main/object_update.c:update_layer_objects, AGPL-3.0; proven shared with X6 by exact signature 00a3e13855ef (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "mmx6/engine_state.h"

// The scratchpad cursor of the layer object loop (beside SP_CUR_MAIN_OBJ at SP(0x04C), include/mmx6/x4.h).
#define SP_CUR_LAYER_OBJ (*(struct X4_LayerObj**)SP(0x06C))

void update_layer_objects(void) {

    for ((*(struct X4_LayerObj**)(0x1F800000 + (0x06C))) = g_class7_slots;
         (*(struct X4_LayerObj**)(0x1F800000 + (0x06C))) <
         &g_class7_slots[(sizeof(g_class7_slots) / sizeof(g_class7_slots[0]))];
         (*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))++) {
        if (g_playthrough_state.unk19 == 0 &&
            (*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))->active) {
            D_8007136C[(*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))->id](
                (*(struct X4_LayerObj**)(0x1F800000 + (0x06C))));
        } else if (g_playthrough_state.unk19 &&
                   (*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))->active &
                       8) {
            D_8007136C[(*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))->id](
                (*(struct X4_LayerObj**)(0x1F800000 + (0x06C))));
        }
    }
}
