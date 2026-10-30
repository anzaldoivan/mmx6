#include "common.h"
#include "mmx6/x4.h"

extern s32* D_80073680[][2];
// !FAKE: flat alias of the TU's D_80090C90[][16]; the 2-D type changes %lo offset folding
extern s32 D_80090C90_flat[];
#define D_80090C90 D_80090C90_flat
extern s16 D_80090D5C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800CF854;
static inline void func_8002ABA8_clear3(void) {
    s16* c = &D_800CF854;
    s16* b = &D_80097430;
    s16* a = &D_80090D5C;
    a[1] = 0;
    b[1] = 0;
    c[1] = 0;
}

void func_8002ABA8(void) {
    s32* src;
    s32 i;
    s32 j;

    func_8002ABA8_clear3();
    for (i = 0; i < 16; i++) {
        D_80090C90[i + 16] = 0;
    }
    src = D_80073680[g_playthrough_state.stage][g_playthrough_state.substage];
    D_800C4560 |= 1;
    if (src == 0) {
        for (j = 19; j < 31; j++) {
            D_80090C90[j] = -1;
        }
    } else {
        for (j = 0; j < 16; j++) {
            D_80090C90[j + 16] = *src++;
        }
    }
    func_8002ABA8_clear3();
}
#undef D_80090C90
