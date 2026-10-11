#include "common.h"
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);
extern s32 D_801F3968[];

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801EF618(void* arg0) {
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        F_S8(arg0, 3) = 1;
        func_80017A04(arg0);
        if (F_S8(arg0, 6) == 0) {
            if (F_S8(arg0, 0x45) & 0x80) {
                F_S8(arg0, 6)++;
                F_PTR(arg0, 0x50) = &D_801F3968[F_S8(arg0, 2)];
                switch (F_S8(arg0, 2)) {
                case 1:
                    F_U16(arg0, 0xE) -= 0x10;
                    break;
                case 2:
                    F_U16(arg0, 0xE) += 0x10;
                    break;
                case 3:
                    F_U16(arg0, 0xA) -= 0x10;
                    break;
                case 4:
                    F_U16(arg0, 0xA) += 0x10;
                    break;
                }
            }
        } else {
            switch (F_S8(arg0, 2)) {
            case 1:
                F_S32(arg0, 0xC) -= F_S32(arg0, 0x24);
                break;
            case 2:
                F_S32(arg0, 0xC) += F_S32(arg0, 0x24);
                break;
            case 3:
                F_S32(arg0, 0x8) -= F_S32(arg0, 0x20);
                break;
            case 4:
                F_S32(arg0, 0x8) += F_S32(arg0, 0x20);
                break;
            }
            F_S32(arg0, 0x20) += 0x10000;
            if (F_S32(arg0, 0x20) > 0x60000) {
                F_S32(arg0, 0x20) = 0x60000;
            }
            F_S32(arg0, 0x24) += 0x10000;
            if (F_S32(arg0, 0x24) > 0x60000) {
                F_S32(arg0, 0x24) = 0x60000;
            }
        }
    } else {
        F_S8(arg0, 3) = 0;
        F_S8(arg0, 4) = 3;
    }
}
