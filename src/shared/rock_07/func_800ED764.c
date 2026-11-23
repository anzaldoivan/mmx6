// rolefeed (3.1 T4): func_800ED764 of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#include "mmx6/psyq_api.h"

#include "mmx6/state.h"
#include "mmx6/globals.h"
extern X4_RECT D_800F981C[];

#define SCR_0C (*(s32**)0x1F80000C)
#define ROW(n) ((u16*)((u8*)D_800F981C + ((n) << 3)))

void func_800ED764(void) {
    s32 buf[24];
    s32 i;
    s32 j;

    if ((u32)D_80097420.frame_counter % 5 == 0) {
        for (i = 0; i < 8; i++) {
            if (i == 0) {
                for (j = 0; j < 4; j++) {
                    buf[j] = SCR_0C[ROW(0)[j]];
                }
            } else {
                for (j = 0; j < 4; j++) {
                    s32 v = SCR_0C[ROW(i)[j]];
                    SCR_0C[ROW(i - 1)[j]] = v;
                }
            }
        }
        for (j = 28; j < 32; j++) {
            SCR_0C[((u16*)D_800F981C)[j]] = buf[j - 28];
        }
        D_800E3142++;
    }
}
