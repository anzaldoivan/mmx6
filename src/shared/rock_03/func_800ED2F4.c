#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);

#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800ED2F4(void* arg0) {
    void* t;
    s16 x;
    s16 y;
    s16 b;
    s32 ang;
    s32 v;
    s32 m;

    t = *(void**)((u8*)arg0 + 0x7C);
    b = F16(t, 0xA);
    x = FU8(arg0, 0x15) != 0 ? b + 0x10 : b - 0x10;
    y = F16(t, 0xE);
    ang = func_80065B74(y - F16(arg0, 0xE), x - F16(arg0, 0xA));
    m = func_80065A14(ang) * 0x10;
    F32(arg0, 0x20) = m * 2 + m;
    m = -func_80065944(ang) * 0x10;
    F32(arg0, 0x24) = m * 2 + m;
    func_80017A04(arg0);
    move_object((s32)arg0);
    if (ABS(x - F16(arg0, 0xA)) < 0x10 && ABS(y - F16(arg0, 0xE)) < 0x10) {
        FU8(t, 0x7) = 1;
        FU8(arg0, 0x4) = 2;
    }
}
