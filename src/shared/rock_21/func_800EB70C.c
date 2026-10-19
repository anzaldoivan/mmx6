#include "common.h"

extern s16 D_800ED230;
extern void (*func_800ECBE8[])(u8*);
void func_800206C0(void);
void func_80025FB0();

void func_800EB70C(u8* arg0) {
    D_800ED230 = 1;
    func_800ECBE8[*(s8*)(arg0 + 1)](arg0);
    func_800206C0();
    func_80025FB0();
}
