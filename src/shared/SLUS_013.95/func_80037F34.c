/* Adapted from sozud/mmx4 @29b62af src/main/player_special.c:player_zero_ryuenjin_rise, AGPL-3.0; proven shared with X6 by exact signature dff51a405822 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 func_8003A628(void*);
M2C_UNK func_8002D5D0(void*);

void func_80037F34(struct X4_PlayerObj* self) {
    if (func_8003A628(self) == 0) {
        func_8002D5D0(self);
        func_80017A04(self);
    }
}
