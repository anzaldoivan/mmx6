/* func_80042F20: table lookup by stage/substage. TU 32208. Our own C. */
#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80075FE8[];
extern struct X4_EngineObj g_playthrough_state;

u8 func_80042F20(void) {
    return D_80075FE8[g_playthrough_state.substage +
                      g_playthrough_state.stage * 2];
}
