/* Adapted from sozud/mmx4 @29b62af src/main/game_info.c:func_8001D6DC, AGPL-3.0; proven shared with X6 by exact signature 07619b425e9d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s8 D_80097424;
#define D_80097424 (*(s8(*)[]) & D_80097424)
void func_80025FB0();

#define M2C_UNK s32
void func_80022960(void);
void func_8001D930(struct X4_GameInfo* arg0) {
    if (D_80097424[0] == 0) {
        if (arg0->unkE == 1) {
            arg0->unk0 = 6;
        } else {
            arg0->unk0 = 1;
        }
        return;
    }

    switch (arg0->unkE) {
    case 0:
        break;
    case 1:
        func_800206C0();
        func_80025FB0();
        break;
    case 2:
        func_80025FB0();
        break;
    case 3:
        func_800206C0();
        func_80022960();
        break;
    }
}
#undef D_80097424
