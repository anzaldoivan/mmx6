#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
void func_800F0434(s8* self, u32 arg1);

void func_800F30F8(s8* arg0) {
    if (D_8008EAFC == 0) {
        func_800F0434(arg0, 7);
        *(s16*)(arg0 + 0x7C) = 0;
        *(u8*)(arg0 + 6) += 1;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}
