#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_800C1220[];
extern u8 D_800F6C40[];

void func_800EDF3C(void* arg0) {
    u32 i;
    s8 z;

    if (D_800970A0.x_pos.i.hi >= 0x1741 && D_800970A0.y_pos.i.hi < 0x4DC) {
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, s16*, 0x18) = 0;
        M2C_FIELD(arg0, s8*, 0x1A) = 0;
        M2C_FIELD(arg0, u8*, 4)++;
        func_80027BA0(0, 0x1740, 0x4F0, D_800F6C40);
        z = 0;
        D_800971F8[0].unk4C = 1;
        D_800971F8[0].unk28 = 0x430;
        D_800971F8[0].unk2A = 0x140;
        for (i = 0; i < 0x50; i++) {
            s8* p = (s8*)&D_800C1220[i * 41];
            if (p[1] == 7) {
                s8* q = p;
                s32 n = 0xA3;
                do {
                    *q++ = z;
                } while (n-- != 0);
            }
        }
    }
}
