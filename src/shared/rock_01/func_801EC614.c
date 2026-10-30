#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern void (*func_801EE39C[])(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK func_801EC614(void* arg0) {
    ((void (*)())func_80017A04)(arg0);
    if (F_S8(arg0, 0x45) & 0x80) {
        play_sound(1, 0x1B, arg0);
        F_U8(arg0, 0x45) &= 0x7F;
    }
    func_801EE39C[F_S8(arg0, 0x6)](arg0);
}
