/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_80019100, AGPL-3.0; proven shared with X6 by exact signature f2a2862257fa (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_800663FC(M2C_UNK*, M2C_UNK*);
void func_80062674(void);
extern void func_80069088(X4_u_long* buf, int size);
extern s32 D_800E2ED0;
extern volatile s32 D_800E2F2C;
extern s32 D_800E2F0C;
extern X4_RECT D_800E2F10;
extern u32* D_800E2F18;
extern s32 D_800E2F1C;
extern s32 D_800E2F20;
extern u32 D_800E2F24;
extern u32 D_800E2F28;
extern s32 D_800E584C;

void func_8001B428(void) {
    u32* temp_a0;

    D_800E2F24 += 1;
    if (D_800E584C != 0) {
        func_80062674();
        D_800E584C = 0;
    }
    if (D_800E2F0C == 0) {
        func_800663FC(&D_800E2F10, D_800E2F18);
    }
    if ((u32)D_800E2F24 < (u32)D_800E2F28) {
        D_800E2F10.x += (D_800E2ED0 ? 0x18 : 0x10);
        temp_a0 = &D_800E2F18[D_800E2F1C];
        D_800E2F18 = temp_a0;
        func_80069088(temp_a0, D_800E2F20);
        D_800E2F2C = 1;
        return;
    }
    D_800E2F2C = 0;
}
