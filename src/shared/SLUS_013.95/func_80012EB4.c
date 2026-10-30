#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32

extern s32 D_8006D894;
extern s32 D_8006D9A4;
extern s8 D_8006D9A8;
extern s32 D_8008EC0C;
extern s16 D_8009741A;
extern s8 D_80097424;
extern u16 g_pad1_buttons[];
extern u8 D_800E4188;

M2C_UNK end_task_slot(M2C_UNK);
void func_80016B3C();
void func_8001D218();
void func_8001D25C(void);
void func_8002C1DC();

void func_80012EB4(void) {
    if (D_8008EC0C != 0 && D_80097424 == 0) {
        if ((g_pad1_buttons[0] & 0x900) == 0x900) {
            if (--D_8009741A == 0) {
                D_8006D894 = 0;
                D_8006D9A4 = 0;
                D_8006D9A8 = 0;
                D_8008EC0C = 0;
                D_800E4188 = 0;
                SetDispMask(0);
                end_task_slot(0);
                end_task_slot(1);
                end_task_slot(2);
                end_task_slot(3);
                D_8009741A = 0x3C;
                func_8001D218();
                func_80016B3C();
                func_8002C1DC();
                func_8001D25C();
            }
        } else {
            D_8009741A = 0x3C;
        }
    }
}
