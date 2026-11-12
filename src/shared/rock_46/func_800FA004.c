#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_800186A8(void);
M2C_UNK func_8002048C();
M2C_UNK func_800206C0();
M2C_UNK func_800207D4();
M2C_UNK func_80020D18();
M2C_UNK func_8002ACA8();
void func_80025FB0();
extern s8 D_80097424;
extern u16 D_800C4570;
extern void (*D_800FACD0[])(void*);

void func_800FA004(s8* arg0) {
    if ((D_800C4570 & 0x800) && D_80097424 == 0 && arg0[1] >= 2 &&
        arg0[1] != 0x13) {
        func_800139F4(8);
        func_800186A8();
        func_80016C48(0, 8, 0);
        arg0[1] = 0x13;
    }
    D_800FACD0[arg0[1]](arg0);
    func_8002048C();
    func_800206C0();
    func_800207D4();
    func_80020D18();
    func_8002ACA8();
    func_80025FB0();
}
