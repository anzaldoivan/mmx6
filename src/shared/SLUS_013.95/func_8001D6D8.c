#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern s32 D_80097420;
void silence_sound(u8, u8);
void stop_cd_audio();
void func_80025F84(void);
void func_80025FB0();
void reset_level(void);
void func_8002C1DC();
void func_8002C2B8();

void func_8001D6D8(struct X4_GameInfo* arg0) {
    s8* p = (s8*)&D_80097420;

    if (p[4] == 0) {
        arg0->unkD = 1;
        p[6] = 0;
        func_80025F84();
        stop_cd_audio();
        silence_sound(0xFF, 0);
        reset_level();
        func_8002C2B8();
        func_8002C1DC();
        arg0->unk0 = 3;
        arg0->mode = 0;
        return;
    }
    func_80025FB0();
}
