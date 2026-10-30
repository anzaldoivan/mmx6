#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80013008(void);
void silence_sound(u8, u8);
void stop_cd_audio();
void exit_stage_by_clear(void* arg0);
void func_80020C40(void);
void func_80025FB0();
void func_8002B29C(void);

extern s32 D_8008EC0C;
extern u8 D_80097184;
extern s8 D_80097424;
extern u8 D_800C4560;
extern struct X4_EngineObj g_playthrough_state;

void func_8001EB48(void* arg0) {
    struct X4_EngineObj* e;

    if (D_80097424 != 0) {
        func_80020C40();
        if (D_80097184 != 0) {
            func_8002B29C();
        }
        func_80025FB0();
        return;
    }
    exit_stage_by_clear(arg0);
    D_800C4560 = 1;
    silence_sound(0xFF, 0);
    if (((u8*)arg0)[0x1B] == 0) {
        stop_cd_audio();
    }
    func_80013008();
    D_8008EC0C = 0;
    e = &g_playthrough_state;
    e->unk10 = 0;
    e->unk11 = 0;
    e->unk14 = 0;
    e->unk16 = 0;
    e->unk17 = 0;
}
