#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_80097430;
extern s32 D_800C1220[];
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800CF854;

void func_800F05F4(u8* arg0) {
    u32 i;
    s32 n;
    u8* p;
    u8* q;
    u8* r;
    u8* e;
    u8 z;

    *(s16*)(arg0 + 0x7C) += 1;
    if ((s16)(*(s16*)(arg0 + 0x7C) % 5) == 0) {
        D_800CF854++;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        if ((u16)D_800CF854 == 0x1F) {
            z = 0;
            for (i = 0; i < 0x50; i++) {
                e = (u8*)D_800C1220 + i * 0xA4;
                if ((s8)e[1] == 8) {
                    p = e;
                    n = 0xA3;
                    do {
                        *p++ = z;
                    } while (n-- != 0);
                }
            }
            q = (u8*)background_objects;
            q[0x57] = 0;
            q[0xAB] = 0;
            *(s16*)(arg0 + 0x7C) = 0x78;
            *(s16*)(arg0 + 0x7E) = 0;
            arg0[6]++;
            r = (u8*)&D_800CCED0;
            ((void (*)(s32, s32, s32))func_80021760)(1, 0xFF, r[0x2F]);
            r[0x2F] = 1;
        }
    }
}
