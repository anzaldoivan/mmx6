#include "common.h"
#include "mmx6/x4.h"

s32 func_80016C48(s32, X4_arg_u8, void*);
void func_800139F4(s32);
extern u8 D_8006D5F7;
extern u16 D_8006D600[];
extern u8 D_8007360C[];
extern u16 D_80073610[];
extern u16 D_80073620[];
extern s32 D_80097420;
extern u16 D_800C456C[];
extern u8 D_800E4188;

#define D_80097420 (*(struct X4_EngineObj*)&D_80097420)
#define MODE ((s8)D_80097420.unk4)
#define CUR ((u8)D_80097420.unk7)

void func_8002A76C(void) {
    u8 i;
    u8 j;
    u8 sel;
    u16 btn;
    u16 tmp;

    if (MODE == 0) {
        if ((D_800C456C[2] & 0x800) || ((D_800C456C[2] & 0x40) && CUR == 0xB)) {
            func_80016C48(0, 0x22, 0);
            func_800139F4(0x20);
            D_800E4188++;
            return;
        }
        if (D_800C456C[2] & 0x1000) {
            func_80016C48(0, 0xC, 0);
            if (CUR == 0) {
                D_80097420.unk7 = 0xB;
            } else {
                D_80097420.unk7--;
            }
        }
        if (D_800C456C[2] & 0x4000) {
            func_80016C48(0, 0xC, 0);
            if (CUR == 0xB) {
                D_80097420.unk7 = 0;
            } else {
                D_80097420.unk7++;
            }
        }
        sel = 0xFF;
        if (CUR < 7) {
            for (i = 4; i < 0x10; i++) {
                if ((1 << i) == D_80073610[CUR]) {
                    sel = i;
                    break;
                }
            }
            if (sel != 0xFF) {
                btn = D_800C456C[2];
                for (i = 0; i < 8; i++) {
                    if (btn == D_80073620[i]) {
                        func_80016C48(0, 0x22, 0);
                        tmp = D_8006D600[sel];
                        D_8006D600[sel] = D_80073620[i];
                        for (j = 0; D_8006D600[j] != 0; j++) {
                            if (j != sel && D_8006D600[j] == D_80073620[i]) {
                                D_8006D600[j] = tmp;
                            }
                        }
                        return;
                    }
                }
            }
        } else if (CUR < 0xB && (D_800C456C[2] & 0x40)) {
            func_80016C48(0, 0x22, 0);
            D_8006D5F7 ^= D_8007360C[CUR - 7];
        }
    }
}
#undef D_80097420
