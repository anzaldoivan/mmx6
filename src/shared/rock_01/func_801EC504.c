#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK end_dash(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_801ECD90(void*, M2C_UNK);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_801EC504(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        F_S8(arg0, 0x8E) = 0;
        end_dash((s32)arg0);
        return;
    }
    if (F_S8(arg0, 0x6) == 0) {
        F_S8(arg0, 0x6) = F_U8(arg0, 0x6) + 1;
    } else {
        ((void (*)())func_80017A04)(arg0);
        if (!(F_U8(arg0, 0x71) & 8) && (F_U8(arg0, 0x45) & 0x40)) {
            if (F_S8(arg0, 0x7A) != 0) {
                F_S8(arg0, 0x7A) = 0;
            }
            if ((F_U16(arg0, 0x7C) & 8) && (F_U16(arg0, 0x80) & 0x20) &&
                (F_S8(arg0, 0xCB) < 2)) {
                F_S8(arg0, 0xCB) = F_U8(arg0, 0xCB) + 1;
                func_8003BA04(arg0, 0x67);
                func_801ECD90(arg0, 0x2A);
            }
        }
    }
    if (F_S8(arg0, 0x46) == 0) {
        F_S8(arg0, 0x8E) = 0;
        F_S8(arg0, 0x7A) = 0;
        end_dash((s32)arg0);
    }
}
