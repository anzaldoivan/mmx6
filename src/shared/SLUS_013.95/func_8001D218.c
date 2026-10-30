/* Adapted from sozud/mmx4 @807a01b src/main/game_info.c:func_8001D134, AGPL-3.0; proven shared with X6 by exact signature 6643b2ef34c8 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
void reset_level(void);
void silence_sound(u8, u8);
void stop_cd_audio();
void func_80025F84();
void func_8002C2B8();

void func_8001D218(void) {
    func_80025F84();
    stop_cd_audio();
    silence_sound(0xFF, 0);
    reset_level();
    func_8002C2B8();
}
