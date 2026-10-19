#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
void func_80049854(struct X4_ShotObj* arg0);
void func_80049950(struct X4_VisualObj* arg0);
void func_800499A0(void* arg0);

M2C_UNK func_80049800(void* arg0, void* arg1) {
    ((M2C_UNK(*)())func_80017A04)();
    func_800499A0(arg0);
    if (((s8*)arg0)[5] == 0) {
        func_80049854(arg0);
    } else {
        func_80049950(arg0);
    }
}
