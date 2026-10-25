#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F8834(void* arg0) {
    u8 flags;

    func_80017A04();
    move_object((s32)arg0);
    if (F_S32(arg0, 0x20) > 0) {
        flags = F_U8(arg0, 0x70);
        if (flags & 1) {
            if (flags & 4) {
                F_S32(arg0, 0x24) = -0x40000;
                ((void (*)(void*, s32))func_800179A4)(arg0, 0x25);
            } else {
                F_S32(arg0, 0x24) = 0x40000;
                ((void (*)(void*, s32))func_800179A4)(arg0, 0x21);
            }
            F_U8(arg0, 0x15) = 0x40;
            F_S32(arg0, 0x20) = 0;
            F_U8(arg0, 0x6)++;
        }
    } else if (F_S32(arg0, 0x20) < 0) {
        flags = F_U8(arg0, 0x70);
        if (flags & 2) {
            if (flags & 4) {
                F_S32(arg0, 0x24) = -0x40000;
                ((void (*)(void*, s32))func_800179A4)(arg0, 0x25);
            } else {
                F_S32(arg0, 0x24) = 0x40000;
                ((void (*)(void*, s32))func_800179A4)(arg0, 0x21);
            }
            F_U8(arg0, 0x15) = 0;
            F_S32(arg0, 0x20) = 0;
            F_U8(arg0, 0x6)++;
        }
    } else if (F_S32(arg0, 0x24) > 0) {
        flags = F_U8(arg0, 0x70);
        if (flags & 4) {
            if (flags & 2) {
                F_U8(arg0, 0x15) = 0x40;
                F_S32(arg0, 0x20) = 0x40000;
            } else {
                F_U8(arg0, 0x15) = 0;
                F_S32(arg0, 0x20) = -0x40000;
            }
            ((void (*)(void*, s32))func_800179A4)(arg0, 0x27);
            F_S32(arg0, 0x24) = 0;
            F_U8(arg0, 0x6)++;
        }
    } else if (F_S32(arg0, 0x24) < 0) {
        flags = F_U8(arg0, 0x70);
        if (flags & 8) {
            if (flags & 2) {
                F_U8(arg0, 0x15) = 0x40;
                F_S32(arg0, 0x20) = 0x40000;
            } else {
                F_U8(arg0, 0x15) = 0;
                F_S32(arg0, 0x20) = -0x40000;
            }
            F_S32(arg0, 0x24) = 0;
            ((void (*)(void*, s32))func_800179A4)(arg0, 0x20);
            F_U8(arg0, 0x6)++;
        }
    }
}
