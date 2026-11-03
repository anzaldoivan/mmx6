#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern s32 D_800F7CC0;

void func_800F5358(u8* arg0) {
    void (*fn)(u8*);

    if (arg0[0x84] < 0xF) {
        arg0[0x84] = 0x1E;
    }
    fn = ((void (**)(u8*)) & D_800F7CC0)[(s8)arg0[6]];
    fn(arg0);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
