#include "common.h"
#define M2C_UNK s32

s32 func_8003015C();
M2C_UNK func_8003AFF4(s32);

s32 func_8003A5D8(u8* arg0) {
    if (func_8003015C(arg0) == 0x20 && !(*(u16*)(arg0 + 0x80) & 0x80)) {
        return 0;
    }
    func_8003AFF4((s32)arg0);
    return 1;
}
