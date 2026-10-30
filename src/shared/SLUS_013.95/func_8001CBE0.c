#include "common.h"
#include "psyq/libgpu.h"

#define M2C_UNK s32

void set_resolution(s32 arg0); /* extern */
void func_8001A9B0(void);      /* extern */
extern M2C_UNK func_80012FE4;

void func_8001CBE0(void) {
    set_resolution(0);
    func_8001A9B0();
    SetDispMask(0);
    DrawSyncCallback(&func_80012FE4);
}
