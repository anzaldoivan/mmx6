#include "common.h"
#include "mmx6/x4.h"

void func_80017F6C(void);
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CD40C;

u8 func_80040498(void) {
    if (D_800CD40C == 0) {
        g_playthrough_state.unkE = 0;
        func_80017F6C();
    }
    return g_playthrough_state.unkE;
}
