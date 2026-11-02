/* Adapted from sozud/mmx4 @807a01b src/main/object_update.c:update_layer_objects, AGPL-3.0; proven shared with X6 by exact signature 00a3e13855ef (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_LayerObj D_800C4778[4];
extern void (*D_8007136C[])(struct X4_LayerObj*);

// The scratchpad cursor of the layer object loop (beside SP_CUR_MAIN_OBJ at SP(0x04C), include/mmx6/x4.h).
#define SP_CUR_LAYER_OBJ (*(struct X4_LayerObj**)SP(0x06C))

void update_layer_objects(void) {

    for (SP_CUR_LAYER_OBJ = D_800C4778;
         SP_CUR_LAYER_OBJ <
         &D_800C4778[(sizeof(D_800C4778) / sizeof(D_800C4778[0]))];
         SP_CUR_LAYER_OBJ++) {
        if (g_playthrough_state.unk19 == 0 &&
            SP_CUR_LAYER_OBJ->active) {
            D_8007136C[SP_CUR_LAYER_OBJ->id](
                SP_CUR_LAYER_OBJ);
        } else if (g_playthrough_state.unk19 &&
                   SP_CUR_LAYER_OBJ->active &
                       8) {
            D_8007136C[SP_CUR_LAYER_OBJ->id](
                SP_CUR_LAYER_OBJ);
        }
    }
}
