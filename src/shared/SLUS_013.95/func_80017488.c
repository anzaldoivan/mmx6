#include "common.h"

#define M2C_UNK s32

M2C_UNK SsSetSerialAttr(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SsSetMVol(M2C_UNK, M2C_UNK);          /* extern */
M2C_UNK SsStart();                          /* extern */
M2C_UNK SsSetSerialVol(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_80017488(void) {
    SsStart();
    SsSetMVol(0x7F, 0x7F);
    SsSetSerialAttr(0, 0, 0);
    SsSetSerialVol(0, 0x7F, 0x7F);
}
