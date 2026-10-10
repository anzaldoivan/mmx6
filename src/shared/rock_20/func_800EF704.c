/* Adapted from sozud/mmx4 @29b62af src/main/engine.c:func_8001F9DC, AGPL-3.0; proven shared with X6 by exact signature 8d45f66608cd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s8 D_80097424[];
void func_8001D218();

void func_800EF704(struct X4_EngineObj* arg0) {
    if (*D_80097424 == 0) {
        func_8001D218();
        arg0->unk2++;
    }
}
