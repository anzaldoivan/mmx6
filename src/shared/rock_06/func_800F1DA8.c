#include "common.h"
#include "mmx6/x4.h"

extern s8 D_800970FC;
extern struct X4_BackgroundObj D_800971F8[3];

#define F1DA8_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F1DA8_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F1DA8_S16(p, o) (*(s16*)((u8*)(p) + (o)))

s32 func_800F1DA8(void* arg0, s32 arg1, s32 arg2) {
    s16 temp;

    if (F1DA8_U8(arg0, 0x97) & 0x40) {
        temp = D_800971F8[F1DA8_S8(arg0, 0x14)].unk1C + 0x140;
        if (F1DA8_S16(arg0, 0xA) + 0x20 >= temp) {
            F1DA8_S16(arg0, 0xA) = temp - 0x20;
        }
        temp = D_800971F8[F1DA8_S8(arg0, 0x14)].unk1E;
        if (F1DA8_S16(arg0, 0xA) - 0x20 < temp && !(F1DA8_U8(arg0, 0xA8) & 1)) {
            F1DA8_S16(arg0, 0xA) = temp + 0x20;
        }
    }
    temp = D_800971F8[F1DA8_S8(arg0, 0x14)].unk20 + 0xF0;
    if (F1DA8_S16(arg0, 0xE) - 0x20 >= temp) {
        F1DA8_S8(arg0, 0x4) = 2;
        if (F1DA8_U8(arg0, 0x97) & 0x40) {
            D_800970FC = -0x80;
        }
    }
}

#undef F1DA8_S8
#undef F1DA8_U8
#undef F1DA8_S16
