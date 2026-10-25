#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);

extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F6F30[];
extern u16 D_800F700C[][2];

#define U8(o) M2C_FIELD(self, u8*, o)
#define U16(o) M2C_FIELD(self, u16*, o)
#define S16(o) M2C_FIELD(self, s16*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

void func_800F1810(void* self) {
    s16 y;
    s16 x;
    s32 t;
    u16 i;
    s32 dy;

    PTR(0x68) = D_800F6F30;
    if (!(func_8002D2D4() & 1)) {
        y = background_objects[0].unk26 +
            ((((u32)func_8002D2D4() % 5) & 0xFF) << 5) - 0x20;
        U16(0x8C) = func_8002D2D4() & 1;
        if (!(func_8002D2D4() & 1)) {
            PTR(0x68) = D_800F6F30 + 1;
            U8(0x6) = 3;
            x = background_objects[0].unk2A + 0x20;
        } else {
            U8(0x6) = 4;
            x = background_objects[0].unk2A + 0xC0;
        }
        t = func_80065B74(x - S16(0xE), y - S16(0xA));
        S32(0x20) = func_80065A14(t) << 6;
        S32(0x24) = -func_80065944(t) << 6;
    } else {
        i = ((u32)func_8002D2D4() % 15) & 0xFF;
        U16(0x8C) = i;
        y = background_objects[0].unk26 + (D_800F700C[i][0] + 0x20);
        dy = y - S16(0xA);
        x = background_objects[0].unk2A + (D_800F700C[i][1] + 0x30);
        t = func_80065B74(x - S16(0xE), dy);
        S32(0x20) = func_80065A14(t) << 6;
        S32(0x24) = -func_80065944(t) << 6;
        {
            s16 m = S16(0x8C) % 3;
            u16 b = background_objects[0].unk26;
            U8(0x6)++;
            U16(0x8C) = b + m * 0x30 + 0x20;
        }
    }
    U8(0x7) = 1;
}
