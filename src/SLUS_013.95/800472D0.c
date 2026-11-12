// prog SLUS_013.95 | system movement | range 0x800472D0-0x8004745C
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/engine_state.h"
#include "mmx6/globals.h"

// 0x800472D0 func_800472D0: object init: speed and timer by stage, difficulty and checkpoint.
// basis: none
// callers: none known
void func_800472D0(struct X4_MainObj* arg0) {
    s16 var_v0_3;

    arg0->unk1C.val = 0;
    arg0->unk18.val = 0x20000;
    if (g_playthrough_state.stage >= 0x13) {
        *(s16*)&arg0->unk16 = 0x10;
        *(s16*)&arg0->bg_offset = 0;
        arg0->action = 0;
    } else if (g_playthrough_state.stage == 4) {
        *(s16*)&arg0->unk16 = 8;
        *(s16*)&arg0->bg_offset = 0;
        arg0->action = 0;
    } else {
        background_objects[1].unk4 = 9;
        background_objects[1].unk4C = 1;
        if (g_playthrough_state.unk68 >= 2U) {
            arg0->unk18.val = 0xFFFEC000;
        } else {
            arg0->unk18.val = 0xFFFF0000;
        }
        var_v0_3 = 0x32;
        if (g_playthrough_state.checkpoint == 0) {
            var_v0_3 = 0x78;
        }
        *(s16*)&arg0->bg_offset = var_v0_3;
        arg0->action = 1;
        *(s16*)&arg0->unk16 = 0;
    }
    (*(u8*)&arg0->state)++;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

// 0x80047394 func_80047394: object step: runs the D_800762C8 action handler unless 0x80097180 is 2.
// basis: none
// callers: none known
void func_80047394(struct X4_MainObj* arg0) {
    D_800CCEF7 = 0;
    if (D_80097180 != 2) {
        D_800762C8[arg0->action](arg0);
    }
}

// 0x800473EC func_800473EC: object action: adds speed while the player acts, resets by difficulty.
// basis: none
// callers: none known
void func_800473EC(Probe800473EC* arg0) {
    if (D_800970A5 != 0) {
        arg0->unk1C += arg0->unk18;
        if (--arg0->unk16 == 0) {
            if (D_800CCF38 < 2) {
                arg0->unk18 = 0x10000;
            } else {
                arg0->unk18 = 0x14000;
            }
            arg0->unk14 = 0xB4;
            arg0->unk5++;
        }
    }
}
