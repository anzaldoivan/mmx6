#include "common.h"
#include "psyq/libcd.h"

#define M2C_UNK s32

void func_800187A0(s32 arg0);                       /* extern */
M2C_UNK SsSetSerialAttr(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s8 D_800CD40C;
extern u8 D_800E2E14;
extern s32 D_800E2E18;
extern s16 D_800E2E48;
extern s32 D_800E2E4C;
extern s8 D_800E2E50;
extern s32 D_800E2E5C;

// 0x800186A8 stop_cd_audio: pauses CD audio playback and turns off the serial audio input.
// basis: code src/shared/SLUS_013.95/stop_cd_audio.c:33 via=SsSetSerialAttr
// callers: exit_stage_from_menu, func_80018290, func_800185B4
void stop_cd_audio(void) {
    s32 temp_s0;

    temp_s0 = D_800E2E5C;
    if (temp_s0 == 2) {
        D_800E2E14 = 0;
        func_800187A0(0);
        if (D_800E2E4C == temp_s0) {
            if (D_800E2E48 != 0) {
                do {

                } while (CdControlB(9, 0, 0) == 0);
            }
        }
        SsSetSerialAttr(0, 0, 0);
        D_800E2E4C = 0;
        D_800E2E50 = 1;
        D_800CD40C = 0;
        D_800E2E18 = 0;
    }
}
