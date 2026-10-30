#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8001D218();
M2C_UNK reset_level();
void func_800E9FB4();
void func_800E9FDC(void);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_80097424;

void func_800FA63C(s8* arg0) {
    s32 i;
    s8* p;

    if (D_80097424 == 0) {
        func_800E9FB4();
        func_800E9FDC();
        func_8001D218();
        background_objects[0].unk3 = 0;
        background_objects[1].unk3 = 0;
        background_objects[2].unk3 = 0;
        reset_level();
        i = 0xF;
        p = arg0 + 0x35;
        do {
            *p = 0;
            i--;
            p--;
        } while (i >= 0);
        *arg0 = 0x15;
    }
}
