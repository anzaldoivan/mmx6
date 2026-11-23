// rolefeed (3.1 T4): func_800FA120 of src/rock_48/FA000.c
// clang-format off

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
void stop_cd_audio();
void func_8002048C(void);
void func_800206C0(void);
void func_800207D4(void);
void run_text_box(void);
void func_80025FB0();
void func_8002ACA8();
#include "mmx6/state.h"
extern u16 D_800C4570;
extern void (*D_800FA5F8[])(void*);

void func_800FA120(s8* arg0) {
    if ((D_800C4570 & 0x800) && D_80097420.transition.active == 0 &&
        arg0[1] >= 2 && arg0[1] != 9) {
        func_800139F4(8);
        stop_cd_audio();
        arg0[1] = 9;
    }
    D_800FA5F8[arg0[1]](arg0);
    func_8002048C();
    func_800206C0();
    func_800207D4();
    run_text_box();
    func_8002ACA8();
    func_80025FB0();
}
