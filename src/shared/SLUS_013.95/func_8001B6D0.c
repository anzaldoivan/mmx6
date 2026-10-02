/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_80018AD0, AGPL-3.0; proven shared with X6 by exact signature fae0caed2311 (see THIRD_PARTY.md). */
#include "common.h"
s32 func_80016548(s32 arg0, s32* arg1);
extern void func_8001AE44(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_8001B6D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    s32 local;

    func_8001AE44(func_80016548(arg0, &local), arg1, arg2, arg3, arg4, arg5,
                  arg6, arg7, arg8, arg9);
}
