#include "common.h"
#include "psyq/libgpu.h"

#define M2C_UNK s32

void func_80012890(s32 arg0); /* extern */
void func_8001A9B0(void);     /* extern */
extern M2C_UNK func_80012FE4;

void func_8001CBE0(void) {
    func_80012890(0);
    func_8001A9B0();
    SetDispMask(0);
    DrawSyncCallback(&func_80012FE4);
}
