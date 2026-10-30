#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D5D0(void*);
M2C_UNK end_dash(s32);
M2C_UNK func_8003B9AC(void*);
M2C_UNK func_8003CD9C();

void func_801EC754(u8* arg0) {
    s32 done;
    s32 bits;

    func_8002D5D0(arg0);
    arg0[0x85]--;
    if (((s8*)arg0)[0x85] < 8) {
        arg0[0x7A] = 0;
    }
    done = ((s8*)arg0)[0x85] == 0;
    if (M2C_FIELD(arg0, s32*, 0x24) > 0) {
        bits = arg0[0x89] & 4;
    } else if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
        bits = arg0[0x89] & 8;
    } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
        bits = arg0[0x89] & 1;
    } else {
        bits = arg0[0x89] & 2;
    }
    if (bits != 0) {
        done = 1;
    }
    if (done != 0) {
        play_sound(1, 6, arg0);
        arg0[0x7A] = 0;
        if (M2C_FIELD(arg0, s32*, 0x24) < 0 && (arg0[0x89] & 8) &&
            (M2C_FIELD(arg0, u16*, 0x7C) & 8)) {
            arg0[0x67] = 0;
            arg0[0x86] = 0;
            func_8003CD9C(arg0);
            func_8003B9AC(arg0);
            return;
        }
        end_dash((s32)arg0);
    }
}
