#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();
s32 random_byte();

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define PW(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F1D4C(void* arg0) {
    u32 r;
    // !FAKE: depin: dropping it breaks the match (8/69)
    register u32 q asm("$5");
    s32 sel;
    s32 mode;
    void* obj;

    r = random_byte();
    q = r / 3;
    sel = (u8)(r - q * 3);
    ((M2C_UNK(*)())func_80017A04)(arg0, q);
    mode = SB(arg0, 0x45);
    if (mode == 1) {
        obj = func_8002C458();
        if (obj != 0) {
            UB(obj, 0) = 0x41;
            UB(obj, 1) = 0x12;
            UB(obj, 2) = 0;
            UB(obj, 0x14) = UB(arg0, 0x14);
            UH(obj, 0xA) = UH(arg0, 0xA);
            UH(obj, 0xE) = UH(arg0, 0xE);
            UB(obj, 0x15) = UB(arg0, 0x15);
            PW(obj, 0x7C) = arg0;
            ((void (*)(s32, s32, void*, void*))play_sound)(2, 0xE, arg0, obj);
            if (sel == 0) {
                ((void (*)(s32, s32, void*))play_sound)(2, 0x25, arg0);
            } else if (sel == mode) {
                ((void (*)(s32, s32, void*))play_sound)(2, 0x26, arg0);
            } else {
                ((void (*)(s32, s32, void*))play_sound)(2, 0x27, arg0);
            }
        }
        UB(arg0, 6) = UB(arg0, 6) + 1;
    }
}
