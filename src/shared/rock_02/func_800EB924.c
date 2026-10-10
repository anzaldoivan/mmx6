#include "common.h"
#define M2C_UNK s32

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define P68(p) (*(u8**)((u8*)(p) + 0x68))

M2C_UNK func_800EB924(void* arg0, void* arg1) {
    u8* t;
    s16 d;
    s16 a;
    s16 b;
    s32 x;
    s32 y;

    if (P68(arg0) != 0 && (t = P68(arg1)) != 0) {
        a = H(arg0, 0xA);
        b = H(arg1, 0xA);
        x = a - b;
        y = b - a;
        d = (x >= 0) ? x : y;
        if (d < UB(P68(arg0), 2) + UB(t, 2)) {
            a = H(arg0, 0xE);
            b = H(arg1, 0xE);
            x = a - b;
            y = b - a;
            d = (x >= 0) ? x : y;
            if (d < UB(P68(arg0), 3) + UB(t, 3)) {
                if (B(arg1, 0x67) != 0) {
                    if (B(arg0, 0x67) == 0) {
                        UB(arg0, 0x70) |= 4;
                    }
                } else if (B(arg0, 0x67) != 0) {
                    UB(arg1, 0x70) |= 4;
                }
                if (H(arg1, 0xA) < H(arg0, 0xA)) {
                    UB(arg1, 0x70) |= 1;
                    UB(arg0, 0x70) |= 2;
                    return;
                }
                UB(arg1, 0x70) |= 2;
                UB(arg0, 0x70) |= 1;
            }
        }
    }
}
