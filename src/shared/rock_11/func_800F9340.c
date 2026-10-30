#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 random_byte();
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800FA06C(void* arg0, u8 arg1);
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E9B88[];
extern u16 D_800FDA7E;
#define D_800FDA7E (*(s16*)&D_800FDA7E)

void func_800F9340(void* arg0) {
    s8 buf[4];
    s16 i;
    // !FAKE: depin: dropping it breaks the match (81/83)
    register s32 n asm("$4");
    // !FAKE: depin: dropping it breaks the match (77/83)
    register s32 v asm("$2");
    s8 t;

    __builtin_memcpy(buf, D_800E9B88, 4);
    t = *(s8*)((u8*)arg0 + 0x45);

    if (t == 1) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x4D, arg0);
        if (buf[(u8)g_playthrough_state.player_initial_data[0x46]] > 0) {
            i = 0;
            do {
                if (D_800FDA7E >= 10) {
                    break;
                }
                func_800FA06C(arg0, 0x10);
                i++;
                v = i;
                n = v < buf[(u8)g_playthrough_state.player_initial_data[0x46]];
            } while (n);
        }
    } else if (t == 2) {
        *((u8*)arg0 + 6) += 1;
    }
}
#undef D_800FDA7E
