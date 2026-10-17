#include "common.h"

void* func_8002BBF4();
extern u8 D_800FD522;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F4254(void* arg0, u8 arg1) {
    void* obj;
    u8 b;
    u16 h;

    obj = func_8002BBF4();
    if (obj != 0) {
        UB(obj, 0) = 0x41;
        UB(obj, 1) = 0x18;
        b = UB(arg0, 0x15);
        P(obj, 0x80) = arg0;
        UB(obj, 2) = arg1;
        UB(obj, 0x15) = b;
        h = UH(arg0, 0xA);
        UH(obj, 8) = 0;
        UH(obj, 0xA) = h;
        h = UH(arg0, 0xE);
        UH(obj, 0xC) = 0;
        UH(obj, 0xE) = h;
        UH(obj, 0x42) = UH(arg0, 0x42) & 0x7FFF;
        W(obj, 0x30) = W(arg0, 0x30);
        W(obj, 0x3C) = W(arg0, 0x3C);
        UH(obj, 0x40) = UH(arg0, 0x40);
        UB(obj, 0x14) = UB(arg0, 0x14);
        if ((arg1 & 0xF0) == 0x10 && (arg1 & 0xF)) {
            D_800FD522 += 1;
        }
    }
}
