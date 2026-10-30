#include "common.h"
#include "psyq/libetc.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800C4568;
extern u8 D_800CCF37;
extern u8 D_80073A1C[];
extern u8 D_80073A6C[];
extern void (*g_player_state_handlers[])(struct X4_PlayerObj*);

#define PB(o) (*(s8*)((u8*)p + (o)))
#define PH(o) (*(s16*)((u8*)p + (o)))
#define PW(o) (*(s32*)((u8*)p + (o)))
#define EW(o) (*(s32*)((u8*)e + (o)))

void func_80034DCC(void) {
    struct X4_PlayerObj* p = &g_Player;

    if (PB(0xCD) != 0) {
        PB(0xCC) = 5;
        PB(0xCD) = 0;
        return;
    }
    if (PB(0xCC) == 0 || --PB(0xCC) == 0) {
        p->unk18.val = p->x_pos.val;
        p->unk1C.val = p->y_pos.val;
        PW(0x13C) = p->x_pos.val;
        PW(0x140) = p->y_pos.val;
        if (D_800C4568 != 0) {
            if (p->input.buttons.held & 2) {
                p->x_pos.u.hi -= 8;
            }
            if (p->input.buttons.held & 1) {
                p->x_pos.u.hi += 8;
            }
            if (p->input.buttons.held & 4) {
                p->y_pos.u.hi -= 8;
            }
            if (p->input.buttons.held & 8) {
                p->y_pos.u.hi += 8;
            }
        } else {
            if (D_80073A1C[p->unk5 & 0x3F] != 0 && D_800CCF37 != 0) {
                if (D_80097420 & 1) {
                    VSync(0);
                }
            }
            if (D_80073A6C[p->unk5 & 0x3F] != 0) {
                struct X4_EngineObj* e = &g_playthrough_state;
                EW(0x90)++;
                EW(0xCC)++;
                if (PH(0x148) == 0 || --PH(0x148) == 0) {
                    PW(0x144) = 0;
                }
            }
            PW(0x138) = 0;
            g_player_state_handlers[p->state](p);
        }
    }
}
