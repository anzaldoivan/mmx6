#include "common.h"

void silence_sound(u8, u8);
void stop_cd_audio();
void func_80025F84();
void reset_level(void);
void func_8002C2B8();
extern s8 D_80097424;

void func_8001D2CC(u8* arg0) {
    if (D_80097424 == 0) {
        arg0[0xD] = 1;
        func_80025F84();
        stop_cd_audio();
        silence_sound(0xFF, 0);
        reset_level();
        func_8002C2B8();
        arg0[1] = 0;
        arg0[0] = arg0[0] + 1;
    }
}
