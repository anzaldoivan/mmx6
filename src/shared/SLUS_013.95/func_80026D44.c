#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800B91C0[];

void func_800269F4(u8 arg0);
void func_80026E20(s32 arg0);
void func_80026ECC(s32 arg0);
void func_800270D0(s32 arg0);
void func_800273E4(void);

#define SP_PRIM_PTR (*(u8**)SP(0x108))
#define SP_PRIM_COUNT (*(s32*)SP(0x11C))
#define SP_BUF (*(s32*)SP(0x0))

void func_80026D44(void) {
    struct X4_BackgroundObj* bg;
    u32 i;

    i = 0;
    SP_PRIM_COUNT = 0;
    do {
        if (background_objects[i].unk4C != 0 ||
            background_objects[i].pad51[1] >= 0) {
            func_800269F4(i & 0xFF);
        }
        i++;
    } while (i < 3);
    bg = background_objects;
    func_800273E4();
    i = 0;
    SP_PRIM_PTR = (SP_BUF << 14) + D_800B91C0;
    do {
        if (bg->unk3 != 0) {
            func_80026E20(i);
            func_800270D0(i);
            func_80026ECC(i);
        }
        i++;
        bg++;
    } while (i < 3);
}
