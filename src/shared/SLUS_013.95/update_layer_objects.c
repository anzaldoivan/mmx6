/* Adapted from sozud/mmx4 @6a6b455 src/main/object_update.c:update_layer_objects, AGPL-3.0; proven shared with X6 by exact signature 00a3e13855ef (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_EngineObj D_800CCED0;
extern struct X4_LayerObj D_800C4778[4];
extern void (*D_8007136C[])(struct X4_LayerObj*);

void update_layer_objects(void) {

    for ((*(struct X4_LayerObj**)(0x1F800000 + (0x06C))) = D_800C4778;
         (*(struct X4_LayerObj**)(0x1F800000 + (0x06C))) <
         &D_800C4778[(sizeof(D_800C4778) / sizeof(D_800C4778[0]))];
         (*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))++) {
        if (D_800CCED0.unk19 == 0 &&
            (*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))->active) {
            D_8007136C[(*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))->id](
                (*(struct X4_LayerObj**)(0x1F800000 + (0x06C))));
        } else if (D_800CCED0.unk19 &&
                   (*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))->active &
                       8) {
            D_8007136C[(*(struct X4_LayerObj**)(0x1F800000 + (0x06C)))->id](
                (*(struct X4_LayerObj**)(0x1F800000 + (0x06C))));
        }
    }
}
