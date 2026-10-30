#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
void stop_cd_audio();
void func_8002048C(void);
void func_800206C0(void);
void func_800207D4(void);
void func_80020D18(void);
void func_8002ACA8();
void func_80025FB0();
extern s8 D_80097424;
extern u16 D_800C4570;
extern void (*D_800FA398[])(void*);

void func_800FA004(s8* arg0) {
    if ((D_800C4570 & 0x800) && D_80097424 == 0 && arg0[1] >= 2 &&
        arg0[1] != 5) {
        func_800139F4(8);
        stop_cd_audio();
        arg0[1] = 5;
    }
    D_800FA398[arg0[1]](arg0);
    func_8002048C();
    func_800206C0();
    func_800207D4();
    func_80020D18();
    func_8002ACA8();
    func_80025FB0();
}
