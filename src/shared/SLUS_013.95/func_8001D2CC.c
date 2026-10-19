#include "common.h"

void func_8001750C(u8, u8);
void func_800186A8();
void func_80025F84();
void func_8002B838(void);
void func_8002C2B8();
extern s8 D_80097424;

void func_8001D2CC(u8* arg0) {
    if (D_80097424 == 0) {
        arg0[0xD] = 1;
        func_80025F84();
        func_800186A8();
        func_8001750C(0xFF, 0);
        func_8002B838();
        func_8002C2B8();
        arg0[1] = 0;
        arg0[0] = arg0[0] + 1;
    }
}
