#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_8002D2D4();
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_800FA06C(void* arg0, u8 arg1);
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800E9B88[];
extern u16 D_800FDA7E;
#define D_800FDA7E (*(s16*)&D_800FDA7E)

void func_800F9340(void* arg0) {
    s8 buf[4];
    s16 i;
    register s32 n asm("$4");
    register s32 v asm("$2");
    s8 t;

    __builtin_memcpy(buf, D_800E9B88, 4);
    t = *(s8*)((u8*)arg0 + 0x45);

    if (t == 1) {
        if (func_8002D2D4() & 1) {
            func_80016C48(2, 0x22, arg0);
        } else {
            func_80016C48(2, 0x23, arg0);
        }
        func_80016C48(2, 0x4D, arg0);
        if (buf[(u8)D_800CCED0.player_initial_data[0x46]] > 0) {
            i = 0;
            do {
                if (D_800FDA7E >= 10) {
                    break;
                }
                func_800FA06C(arg0, 0x10);
                i++;
                v = i;
                n = v < buf[(u8)D_800CCED0.player_initial_data[0x46]];
            } while (n);
        }
    } else if (t == 2) {
        *((u8*)arg0 + 6) += 1;
    }
}
#undef D_800FDA7E
