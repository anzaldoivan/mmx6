#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
extern void (*func_801EE39C[])(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

// 0x801EC614 update_rekkoha: Rekkoha state handler: animates, plays its sound on flag 0x45 and runs the substate table.
// basis: xref start_rekkoha (docs/leads/derived.tsv:30)
// callers: start_rekkoha
M2C_UNK update_rekkoha(void* arg0) {
    ((void (*)())animate_object)(arg0);
    if (F_S8(arg0, 0x45) & 0x80) {
        play_sound(1, 0x1B, arg0);
        F_U8(arg0, 0x45) &= 0x7F;
    }
    func_801EE39C[F_S8(arg0, 0x6)](arg0);
}
