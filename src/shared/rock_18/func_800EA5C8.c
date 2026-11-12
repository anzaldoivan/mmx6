#include "common.h"

void func_800206C0(void);
void func_800207D4(void);
void func_80020D18(void);
void func_8002ACA8(void);
void func_80025FB0(void);
extern void (*D_800F08E4[])(s8*);

void func_800EA5C8(s8* arg0) {
    D_800F08E4[arg0[1]](arg0);
    func_800206C0();
    func_800207D4();
    func_80020D18();
    func_8002ACA8();
    func_80025FB0();
}
