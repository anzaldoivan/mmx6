#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80039C40(void*);
s32 func_80039CFC(void*);
s32 func_8003A3DC(void*);
s32 func_8003A628(void*);
void func_8003AD18(void* arg0);
M2C_UNK func_8003AE8C(void*);
s32 func_801EA560(void*);
s32 func_801EBE04(void*);
s32 func_801EBE54(void*);
s32 func_801EBEDC(void*);
s32 func_801EC86C(void*);

void func_80036800(void* arg0) {
    if ((func_8003A628(arg0) == 0) && (func_8003A3DC(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (func_80039C40(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0)))) {
        if (func_80039CFC(arg0) != 0) {
            func_8003AE8C(arg0);
            return;
        }
        ((void (*)())func_80017A04)(arg0);
        if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
            func_8003AD18(arg0);
        }
    }
}
