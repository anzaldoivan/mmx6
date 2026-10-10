#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
void* func_8002BBF4();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s32 D_800F7950;
extern s16 D_800F7DC4;
extern u16* D_800F7DF0;
extern s16 D_800F7E0C;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F42D8(void* arg0) {
    s32 i;
    void* p;

    if (P(arg0, 0x68) == 0 && H(arg0, 0xE) >= D_800F7DC4 - 0x80) {
        P(arg0, 0x68) = &D_800F7950;
    }
    i = 0;
    if (UB(arg0, 0x70) & 8) {
        register u16* q asm("$4") = D_800F7DF0;
        register s32 n asm("$3") = *(s16*)q;
        D_800F7E0C = 0;
        if (n > 0) {
            do {
                p = func_8002BBF4();
                if (p != 0) {
                    u8 b;
                    UB(p, 0x0) = UB(arg0, 0x0);
                    b = UB(arg0, 0x1);
                    UB(p, 0x2) = 1;
                    UB(p, 0x5) = 0;
                    P(p, 0x80) = arg0;
                    UB(p, 0x1) = b;
                }
                i++;
            } while (i < *(s16*)D_800F7DF0);
        }
        W(arg0, 0x24) = 0;
        UB(arg0, 0x6)++;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
