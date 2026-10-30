/* Adapted from sozud/mmx4 @807a01b src/main/player_common.c:player_spawn_wall_slide_dust, AGPL-3.0; proven shared with X6 by exact signature 8e04af3111c5 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
struct X4_VisualObj* func_8002C398(void);

// 0x8003D2BC spawn_dust: dust animation start.
// basis: community tweaks-index.tsv:186
// callers: func_8003B548
void spawn_dust(struct X4_PlayerObj* self) {
    struct X4_VisualObj* visual_obj;

    visual_obj = func_8002C398();
    if (visual_obj != NULL) {
        visual_obj->active = 0x21;
        visual_obj->id = 0;
        visual_obj->bg_offset = self->bg_offset;
        visual_obj->state = 0;
        visual_obj->unk5 = 0;
        visual_obj->unk6 = 0;
    }
}
