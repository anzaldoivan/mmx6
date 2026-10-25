#include "common.h"

#define M2C_UNK s32

void func_800297D8(u8* arg0);                      /* extern */
M2C_UNK func_800297F8();                           /* extern */
void func_80029818(struct X4_BackgroundObj* arg0); /* extern */

void func_8002974C(s32 arg0) {
    func_800297F8();
    func_800297D8(arg0);
    func_80029818(arg0);
}
