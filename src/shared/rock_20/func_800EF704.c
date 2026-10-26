/* Adapted from sozud/mmx4 @807a01b src/main/engine.c:func_8001F9DC, AGPL-3.0; proven shared with X6 by exact signature 8d45f66608cd (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
/* siblings in the same TU declare it as struct X4_EngineObj; view it as the upstream state block */
extern struct X4_EngineObj D_80097420;
#define D_80097420 (*(struct X4_MainBssState*)&D_80097420)
void func_8001D218();

void func_800EF704(struct X4_EngineObj* arg0) {
    if (D_80097420.transition.active == 0) {
        func_8001D218();
        arg0->unk2++;
    }
}
#undef D_80097420
