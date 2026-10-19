#include "common.h"

extern void (*D_800F1068[])(u8*);
void func_8002048C(void);
void func_800207D4(void);
void func_80020378(void);
void func_800206C0(void);
void func_80020D18(void);
void func_8002ACA8();
void func_80025FB0();

void func_800EC858(u8* arg0) {
    D_800F1068[*(s8*)(arg0 + 1)](arg0);
    func_8002048C();
    func_800207D4();
    func_80020378();
    func_800206C0();
    func_80020D18();
    func_8002ACA8();
    func_80025FB0();
}
