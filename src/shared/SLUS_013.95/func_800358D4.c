#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039FFC(void*);              /* extern */
s32 func_8003A870(void*);              /* extern */
M2C_UNK func_8003AF1C(void*);          /* extern */
M2C_UNK func_8003B218(void*);          /* extern */
M2C_UNK func_8003C7D8(void*);          /* extern */
M2C_UNK func_8003CCBC();               /* extern */
M2C_UNK func_8003CD00(void*);          /* extern */
M2C_UNK func_8003D26C(void*);          /* extern */
s32 func_8003F13C(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA254(void*);              /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EBE04(void*);              /* extern */
s32 func_801EBE54(void*);              /* extern */
s32 func_801EBEDC(void*);              /* extern */
s32 func_801EC86C(void*);              /* extern */

void func_800358D4(void* arg0) {
    u8 temp_v1;

    func_8003CCBC();
    if ((func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0) &&
          ((func_801EA254(arg0) != 0) || (func_801EBEDC(arg0) == 0)))) &&
        (func_8003A870(arg0) == 0)) {
        if (M2C_FIELD(arg0, u16*, 0x80) & 0x80) {
            func_8003AF1C(arg0);
            return;
        }
        if ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE54(arg0) == 0)) {
            if (func_80039FFC(arg0) != 0) {
                func_8003B218(arg0);
                return;
            }
            temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
            if (temp_v1 & 0x40) {
                M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0xF);
                func_8003D26C(arg0);
            }
            if (!(M2C_FIELD(arg0, u8*, 0x85) & 3)) {
                func_8003C7D8(arg0);
            }
            func_8003F508(arg0, 0x10);
            func_8003CD00(arg0);
        }
    }
}
