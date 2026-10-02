#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D5D0(void*);          /* extern */
s32 func_80039C40(void*);              /* extern */
s32 func_80039C9C(void*);              /* extern */
s32 func_80039D7C(void*);              /* extern */
s32 func_8003A3DC(void*);              /* extern */
s32 func_8003A628();                   /* extern */
s32 func_8003A870(void*);              /* extern */
M2C_UNK func_8003ADB4(void*);          /* extern */
s32 func_8003F13C(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA254(void*);              /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EBE04(void*);              /* extern */
s32 func_801EBE54(void*);              /* extern */
s32 func_801EBEDC(void*);              /* extern */
s32 func_801EC86C(void*);              /* extern */

void func_800354E8(void* arg0) {
    if ((((s32(*)())func_8003A628)() == 0) && (func_8003A3DC(arg0) == 0) &&
        (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (func_8003A870(arg0) == 0) && (func_80039C40(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) &&
          ((func_801EA254(arg0) != 0) || (func_801EBEDC(arg0) == 0)))) &&
        (func_80039C9C(arg0) == 0)) {
        if (func_80039D7C(arg0) != 0) {
            func_80017A04(arg0);
            func_8002D5D0(arg0);
            func_8003F508(arg0, 8);
            return;
        }
        func_8003ADB4(arg0);
    }
}
