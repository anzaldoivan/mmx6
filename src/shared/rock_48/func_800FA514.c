#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK func_8002B838();
void func_800E9FB4();
void func_800E9FDC(void);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_80097424;
extern s8 D_800CCEF7;

void func_800FA514(u8* arg0) {
    s32 i;
    u8* p;

    if (D_80097424 == 0) {
        func_800E9FB4();
        func_800E9FDC();
        func_8001D218();
        background_objects[0].unk3 = 0;
        background_objects[1].unk3 = 0;
        background_objects[2].unk3 = 0;
        func_8002B838();
        i = 0xF;
        p = arg0 + 0x35;
        do {
            *p = 0;
            i--;
            p--;
        } while (i >= 0);
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
        if (arg0[0x66] < 3) {
            if (*(s16*)(arg0 + 0xD2) >= 0xBB8 ||
                *(s16*)(arg0 + 0xD4) >= 0xBB8) {
                arg0[0] = 0x13;
                arg0[0x1D] = 5;
                return;
            }
        }
        arg0[0xC] = 0x13;
        arg0[0xD] = 0;
        D_800CCEF7 = 0;
        arg0[0] = 0xB;
    }
}
