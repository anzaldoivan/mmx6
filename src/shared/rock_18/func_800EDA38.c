#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CB50();
extern struct X4_EngineObj D_80097420;
extern s8 D_800CD3F8[];
extern u8 D_800F0B48;
extern u8 D_800F0B4E;
extern u8 D_800F0B54;
extern u8 D_800F0B5A;

#define ENG_W (*(s32*)&D_80097420)

void func_800EDA38(s8* arg0) {
    u8 s;

    if (arg0[2] == 6) {
        arg0[0x16] = 2;
        *(s16*)(arg0 + 0xE) = ((s8)(D_800CD3F8[2] % 4) << 4) + 0x8E;
        switch (D_800CD3F8[2]) {
        case 0:
            arg0[0x47] = D_800F0B48;
            break;
        case 1:
            arg0[0x47] = D_800F0B4E;
            break;
        case 2:
            arg0[0x47] = D_800F0B54;
            break;
        default:
            arg0[0x47] = D_800F0B5A;
            break;
        }
    }
    s = arg0[2];
    if ((u32)(s - 4) < 2U || (s8)s == 7) {
        arg0[3] = 0;
        if (ENG_W & 0x10) {
            func_8002CB50(arg0);
        }
    } else {
        arg0[3] = 1;
        func_8002CB50(arg0);
    }
}
