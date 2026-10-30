#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
void* alloc_class3_slot();

void func_80053578(u8* arg0) {
    u8* temp_v0;

    if (((u32)((u8)g_playthrough_state.stage - 1) < 8U) &&
        ((g_playthrough_state.unk60 >> (g_playthrough_state.stage - 1)) & 1)) {
        g_playthrough_state.unkF = 1;
        return;
    }
    temp_v0 = ((u8 * (*)()) alloc_class3_slot)();
    if (temp_v0 != 0) {
        temp_v0[0] = 1;
        temp_v0[1] = 4;
        *(u8**)(arg0 + 0x14) = temp_v0;
    }
    *(s16*)(arg0 + 0x18) = 0;
    arg0[0x1A] = 5;
    arg0[0x1B] = 0;
    arg0[0x1C] = 0;
    arg0[4]++;
}
