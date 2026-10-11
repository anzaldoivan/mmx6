#include "common.h"

#define M2C_UNK s32

s32 func_8001C824(void);
void func_8001C938(s32);
int func_80060964(int mode);
s32 func_800698E4(s32);
M2C_UNK func_80069E44(s32);
extern s32 D_800E2F70;
extern s32 D_800E2F74;
extern s32 D_800E2F78;
extern s32 D_800E2F7C;

static inline s32 func_8001C1AC_try(s32 port) {
    s32 i = 3;
    s32 r;

    func_80069E44(D_800E2F70);
    func_80069E44(D_800E2F74);
    func_80069E44(D_800E2F78);
    func_80069E44(D_800E2F7C);
    do {
        if (func_800698E4(port << 4) != 0) {
            r = func_8001C824();
            if (r == 0) {
                return 0;
            }
        }
    } while (--i != 0);
    return r;
}

s32 func_8001C1AC(s32 arg0) {
    s32 r;

    r = func_8001C1AC_try(arg0);
    if (r != 2) {
        return r;
    }
    func_8001C938(arg0);
    func_80060964(300);
    r = func_8001C1AC_try(arg0);
    if (r != 2) {
        return r;
    }
    func_8001C938(arg0);
    func_80060964(300);
    r = func_8001C1AC_try(arg0);
    return r;
}
