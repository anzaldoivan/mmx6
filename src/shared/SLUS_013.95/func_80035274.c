#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039C40(void*);     /* extern */
s32 func_80039C9C(void*);     /* extern */
s32 func_80039CFC(void*);     /* extern */
s32 func_8003A3DC(void*);     /* extern */
s32 func_8003A628(void*);     /* extern */
s32 func_8003A870(void*);     /* extern */
M2C_UNK func_8003AE8C(void*); /* extern */
M2C_UNK func_8003CCBC();      /* extern */
s32 func_8003F13C(void*);     /* extern */
s32 func_801EA254(void*);     /* extern */
s32 func_801EA560(void*);     /* extern */
M2C_UNK func_801EB61C(void*); /* extern */
s32 func_801EBE04(void*);     /* extern */
s32 func_801EBE54(void*);     /* extern */
s32 func_801EBEDC(void*);     /* extern */
s32 func_801EC86C(void*);     /* extern */
M2C_UNK func_801EC9C4(void*); /* extern */

void func_80035274(void* arg0) {
    func_8003CCBC();
    if ((func_8003A628(arg0) == 0) && (func_8003A3DC(arg0) == 0) &&
        (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (func_8003A870(arg0) == 0) && (func_80039C40(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) &&
          ((func_801EA254(arg0) != 0) || (func_801EBEDC(arg0) == 0)))) &&
        (func_80039C9C(arg0) == 0)) {
        if (func_80039CFC(arg0) != 0) {
            func_8003AE8C(arg0);
            return;
        }
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_801EB61C(arg0);
            return;
        }
        func_801EC9C4(arg0);
    }
}
