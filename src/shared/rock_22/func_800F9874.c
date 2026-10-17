#include "common.h"
#define M2C_UNK s32

#define R22_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define R22_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define R22_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define R22_S32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_80017A04();
s32 func_8002D2D4();
extern u16 D_800FD5A4;

void func_800F9874(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x84);
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (61/66)
        register s32 m asm("$2") = 0xFF00FF00;
        s32 k = 0xA00;
        if ((R22_S32(p, 4) & m) == k) {
            switch (R22_S8(p, 6)) {
            case 0:
                break;
            case 1:
                if (R22_S16(p, 0x7C) != 0) {
                    R22_U8(arg0, 0x8E) = 0x28;
                }
                {
                    s32 t = D_800FD5A4;
                    R22_S16(arg0, 0x7E) = 0;
                    R22_S16(arg0, 0x7C) = t;
                }
                R22_U8(arg0, 0x93) = ((func_8002D2D4() & 3) << 4) + 0x60;
                R22_U8(arg0, 5) = 6;
                R22_U8(arg0, 6) = 0;
                return;
            case 2:
                R22_S16(arg0, 0x7C) = 0;
                R22_S16(arg0, 0x7E) = 0;
                R22_U8(arg0, 5) = 8;
                R22_U8(arg0, 6) = 0;
                return;
            case 3:
                R22_U8(arg0, 5) = 9;
                R22_S16(arg0, 0x7C) = 0;
                R22_S16(arg0, 0x7E) = 0;
                R22_U8(arg0, 6) = 0;
                R22_U8(arg0, 7) = 0;
                if (R22_U8(p, 0x8D) == R22_S8(arg0, 2) + 2) {
                    R22_U8(arg0, 5) = 7;
                }
                break;
            }
        }
    }
}
