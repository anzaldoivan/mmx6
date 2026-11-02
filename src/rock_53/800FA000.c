// clang-format off
INCLUDE_ASM("asm/rock_53/nonmatchings/FA000", D_800FA000);
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
extern void (*D_800FA398[])(void*);

void func_800FA004(s8* arg0) {
    if ((D_800C4570 & 0x800) && D_80097420.transition.active == 0 &&
        arg0[1] >= 2 && arg0[1] != 5) {
        func_800139F4(8);
        stop_cd_audio();
        arg0[1] = 5;
    }
    D_800FA398[arg0[1]](arg0);
    func_8002048C();
    func_800206C0();
    func_800207D4();
    run_text_box();
    func_8002ACA8();
    func_80025FB0();
}

// clang-format off
INCLUDE_ASM("asm/rock_53/nonmatchings/FA000", func_800FA0D8);
// clang-format on

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800E9F7C(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA1AC(u8* arg0) {
    ((void (*)(s32))SetDispMask)(1);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 1;
    background_objects[2].x_pos.val = 0;
    background_objects[2].y_pos.val = 0;
    func_800E9F7C();
    {
        s32 v = arg0[1];
        s32 c = 0x152;
        *(s16*)(arg0 + 8) = c;
        c = 1;
        *(s16*)(arg0 + 0xA) = c;
        arg0[1] = v + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA214(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].unk3 = 1;
        background_objects[2].y_pos.i.hi = 0x100;
        background_objects[2].unk4C = 1;
        *(s16*)(arg0 + 8) = 0x153;
        *(s16*)(arg0 + 0xA) = 9;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_800EA480(s8* arg0);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA274(u8* arg0) {
    if (func_800EA480((s8*)arg0) != 0) {
        background_objects[2].unk3 = 1;
        background_objects[2].y_pos.i.hi = 0x200;
        background_objects[2].unk4C = 1;
        *(s16*)(arg0 + 8) = 0x15C;
        *(s16*)(arg0 + 0xA) = 0xE;
        arg0[1]++;
    }
}

#define func_800FA4D0 func_800FA2D4
#include "../shared/rock_48/func_800FA4D0.c"
#undef func_800FA4D0

#define func_800FA63C func_800FA318
#include "../shared/rock_47/func_800FA63C.c"
#undef func_800FA63C

// clang-format off
INCLUDE_ASM("asm/rock_53/nonmatchings/FA000", func_800FA394);
// clang-format on
