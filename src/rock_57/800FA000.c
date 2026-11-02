// clang-format off
INCLUDE_ASM("asm/rock_57/nonmatchings/FA000", D_800FA000);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
void stop_cd_audio();
void func_8002048C(void);
void func_800206C0(void);
void func_800207D4(void);
void run_text_box(void);
void func_8002ACA8();
void func_80025FB0();
#include "mmx6/state.h"
extern u16 D_800C4570;
extern void (*D_800FA4F4[])(void*);

void func_800FA004(s8* arg0) {
    if ((D_800C4570 & 0x800) && D_80097420.transition.active == 0 &&
        arg0[1] >= 2 && arg0[1] != 8) {
        func_800139F4(8);
        stop_cd_audio();
        arg0[1] = 8;
    }
    D_800FA4F4[arg0[1]](arg0);
    func_8002048C();
    func_800206C0();
    func_800207D4();
    run_text_box();
    func_8002ACA8();
    func_80025FB0();
}

// clang-format off
INCLUDE_ASM("asm/rock_57/nonmatchings/FA000", func_800FA0D8);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

void func_800E9F7C(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA1C0(struct X4_BackgroundObj* arg0) {
    if (D_80097420.transition.active == 0) {
        background_objects[2].unk3 = 1;
        background_objects[1].unk3 = 1;
        background_objects[1].x_pos.i.hi = 0x120;
        func_800E9F7C();
        {
            s32 t = arg0->unk1;
            s32 c;
            c = 0x1F5;
            arg0->x_pos.i.lo = c;
            c = 7;
            arg0->x_pos.i.hi = c;
            arg0->unk1 = t + 1;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA228(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[1].x_pos.i.hi -= 0x10;
        if (background_objects[1].x_pos.i.hi <= 0) {
            background_objects[1].y_pos.i.hi = 0;
            *(s16*)(arg0 + 8) = 0x1FC;
            *(s16*)(arg0 + 0xA) = 1;
            ((u8*)arg0)[1]++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA290(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        background_objects[0].unk3 = 1;
        background_objects[0].unk4C = 1;
        ((u8*)arg0)[1]++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA2DC(struct X4_BackgroundObj* arg0) {
    s32 temp_v0;

    temp_v0 = background_objects[0].x_pos.u.hi + 0x10;
    background_objects[0].x_pos.u.hi = temp_v0;
    if ((s16)temp_v0 >= 0x120) {
        background_objects[0].x_pos.u.hi = 0x120;
        background_objects[2].unk3 = 0;
        arg0->x_pos.i.lo = 0x1FD;
        arg0->x_pos.i.hi = 5;
        arg0->unk1++;
    }
}

#include "common.h"

s32 func_800EA480(s8* arg0);
extern u8 D_800EA510[];
extern u8 D_800FA4EC[];

void func_800FA334(u8* arg0) {
    s32 i;

    if (func_800EA480((s8*)arg0) != 0) {
        for (i = 0; i < 4; i++) {
            D_800EA510[i] = D_800FA4EC[i];
        }
        *(s16*)(arg0 + 8) = 0x202;
        *(s16*)(arg0 + 0xA) = 7;
        arg0[1]++;
    }
}

#include "common.h"

s32 func_800EA480(s8* arg0);
extern u8 D_800EA510[];
extern u8 D_800FA4F0[];

void func_800FA3A8(u8* arg0) {
    s32 i;

    if (func_800EA480((s8*)arg0) != 0) {
        i = 0;
        do {
            D_800EA510[i] = D_800FA4F0[i];
            i++;
        } while (i < 4);
        *(s16*)(arg0 + 8) = 0x209;
        *(s16*)(arg0 + 0xA) = 3;
        arg0[1]++;
    }
}

#define func_800FA4D0 func_800FA41C
#include "../shared/rock_48/func_800FA4D0.c"
#undef func_800FA4D0

#define func_800FA4C4 func_800FA460
#include "../shared/rock_56/func_800FA4C4.c"
#undef func_800FA4C4

// clang-format off
INCLUDE_ASM("asm/rock_57/nonmatchings/FA000", func_800FA4E8);
// clang-format on
