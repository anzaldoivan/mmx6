// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80034830);
// clang-format on

#define func_80041AB8 func_80034874
#define D_80075FD8 D_800739A4
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80026028();
extern void (*D_800739B0[])(s8*);
extern u16 D_800C4570;

void func_800348B0(s8* arg0) {
    s8 st;
    s8 t;

    if ((D_800C4570 & 0x100) && ((t = arg0[5]) < 3 || t == 8)) {
        *(s32*)(arg0 + 0x30) = t;
        arg0[5] = 6;
        arg0[6] = 0;
    }
    st = arg0[5];
    D_800739B0[st](arg0);
    if (st != 7) {
        if (arg0[5] < 5) {
            func_80026028();
        }
        if (arg0[5] == 7) {
            func_80026028();
        }
    }
    if (arg0[5] >= 8) {
        func_80026028();
    }
}

#define func_80041AB8 func_8003499C
#define D_80075FD8 D_80073A0C
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK); /* extern */
void silence_sound(u8, u8);     /* extern */
M2C_UNK func_80025FB0();        /* extern */
extern s16 D_800971EC;

void func_800349D8(void* arg0) {
    silence_sound(0xFF, 0);
    func_800139F4(0x20);
    func_80025FB0();
    M2C_FIELD(arg0, s8*, 5) = 1;
    D_800971EC = 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80026028();
#include "mmx6/state.h"

void func_80034A28(u8* arg0) {
    s8 temp_v1;

    if (D_80097420.transition.active == 0) {
        temp_v1 = ((s8*)arg0)[0x14];
        arg0[4] = 1;
        arg0[5] = 0;
        if (temp_v1 >= 0xD) {
            arg0[5] = 2;
        } else if (temp_v1 >= 0xA) {
            arg0[5] = 1;
        }
    }
    func_80026028();
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139A0(s8);
M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK func_80026028();
M2C_UNK func_8002AB58();

void func_80034A88(s8* arg0) {
    switch (arg0[6]) {
    case 0:
        func_800139F4(0x20);
        arg0[6]++;
        func_80026028();
        break;
    case 1:
        if (D_80097420.transition.active == 0) {
            arg0[6]++;
        }
        func_80026028();
        break;
    case 2:
        func_8002AB58(arg0);
        break;
    case 3:
        func_800139A0(0x20);
        arg0[6]++;
        func_80026028();
        break;
    case 4:
        if (D_80097420.transition.active == 0) {
            arg0[5] = 2;
            arg0[6] = 0;
        } else {
            func_80026028();
        }
        break;
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80034B70);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK); /* extern */
M2C_UNK func_80026028();        /* extern */

void func_80034C5C(void* arg0) {
    func_800139F4(0x20);
    func_80026028();
    M2C_FIELD(arg0, s8*, 5) = 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80026028(); /* extern */

void func_80034C94(void* arg0) {
    if (D_80097420.transition.active != 0) {
        func_80026028();
        return;
    }
    M2C_FIELD(arg0, s8*, 5) = 2;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
void func_80020C40(void);
M2C_UNK func_8003DF58(void*);
M2C_UNK func_8003F0BC(void*);
M2C_UNK func_8003F480();
M2C_UNK func_8003F58C();
M2C_UNK func_801ECBE8();

extern struct X4_PlayerObj g_Player;
extern u8 D_800C4560;
extern u8 D_800E4430;
#define D_800E4430 (*(s8*)&D_800E4430)

void func_80034CD0(u8* arg0) {
    struct X4_PlayerObj* pl;

    pl = &g_Player;
    if (*(void**)(arg0 + 0x38) == 0) {
        if (pl->unk2 == 0) {
            func_8003F58C();
            if (D_800E4430 != pl->weapon) {
                *(s16*)((u8*)pl + 0x14C) = 2;
                func_8003F480(pl);
            }
            func_8003DF58(pl);
            if (D_800E4430 != pl->weapon) {
                func_8003F0BC(pl);
            }
        } else if (pl->weapon == 4) {
            func_801ECBE8(pl);
        }
        D_800C4560 |= 1;
        func_80020C40();
        {
            struct X4_PlayerObj* p = &g_Player;
            *(s16*)((u8*)p + 0x14C) = 0;
        }
        func_800139A0(0x20);
    }
    arg0[5] = 3;
}
#undef D_800E4430

#include "common.h"
#include "psyq/libetc.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
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
                if (D_80097420.frame_counter & 1) {
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
