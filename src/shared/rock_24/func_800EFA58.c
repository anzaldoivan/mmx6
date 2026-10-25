#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EFA58 (*(s32**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
s32 func_8002A47C(s32);
s32 func_8002B2F8(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

void func_800EFA58(void* arg0) {
    s32 c;

    if ((s16)--M2C_FIELD(arg0, u16*, 0x7C) == -1) {
        M2C_FIELD(arg0, u16*, 0x7C) = 2;
        c = (u16)D_800CF854 - 1;
        D_800CF854 = c;
        D_80097430 -= 0x20;
        D_80090D5C -= 0x400;
        D_800C4560 |= 1;
        if ((u16)c == 0) {
            func_8002B2F8(0);
            M2C_FIELD(arg0, s16*, 0x40) = 0x140;
            M2C_FIELD(arg0, s16*, 0x42) =
                ((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 8) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(arg0, u8**, 0x3C) =
                (u8*)SPAD20_800EFA58 +
                SPAD20_800EFA58[func_8002A47C(M2C_FIELD(arg0, s8*, 1))];
            func_800179A4(arg0, 2);
            {
                // !FAKE: depin: dropping it breaks the match (84/87)
                register s32 n asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
                M2C_FIELD(arg0, u8*, 6) = n;
            }
        }
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}
