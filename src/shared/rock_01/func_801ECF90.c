#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D5D0(void*);
M2C_UNK end_dash(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_801ECD54(void*, M2C_UNK);
extern u16 D_800CCEDC;

void func_801ECF90(void* arg0) {
    s32 var_v1;

    ((void (*)())func_80017A04)();
    ((void (*)())func_801ECD54)(arg0, 0x24);
    var_v1 = 0xA;
    if (((u8*)arg0)[0x15] != 0) {
        var_v1 = 9;
    }
    if (((u8*)arg0)[0x89] & var_v1) {
        ((void (*)())play_sound)(1, 0x1A, arg0);
        var_v1 = ((s8*)arg0)[0xD3];
        if (var_v1 == 0) {
            ((u8*)arg0)[0x7A] = 0;
        }
        if (((u8*)arg0)[0x89] & 8) {
            if (D_800CCEDC == 0x104) {
                ((void (*)())func_80029478)(0x1E, 2, 1);
            } else {
                ((void (*)())func_8002943C)(0x1E, 2, 1);
            }
            ((void (*)())func_8003BA04)(arg0, 0x66);
            ((u8*)arg0)[0xCB] = 1;
            ((void (*)())func_801ECD54)(arg0, 0x24);
            ((u8*)arg0)[0x67] = 0;
            ((u8*)arg0)[0x6]++;
            return;
        }
        ((u8*)arg0)[0x67] = 0;
        ((u8*)arg0)[0x8E] = 0;
        ((void (*)())end_dash)((s32)arg0);
        return;
    }
    ((void (*)())func_8002D5D0)(arg0);
}
