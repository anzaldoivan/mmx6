#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D2B0();
M2C_UNK func_8002F288(M2C_UNK*);

void func_800F3E6C(u8* arg0) {
    func_8002D2B0((s32)arg0);
    func_8002F288((M2C_UNK*)arg0);
    {
        // !FAKE: test byte lands in the first return register
        register s32 t asm("$2") = arg0[0x70];
        if (t != 0) {
            arg0[5] = 2;
            arg0[6] = 0;
        }
    }
}
