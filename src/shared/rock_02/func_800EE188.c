#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 random_byte();
extern s16 D_800970AA;
extern u8 D_800CCF5C;
#define D_800CCF5C (*(s8*)&D_800CCF5C)

void func_800EE188(void* arg0) {
    u32 r;

    r = random_byte() & 0xF;
    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x3C) {
        if (M2C_FIELD(arg0, s8*, 6) == 0) {
            if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                if (r < 8) {
                    M2C_FIELD(arg0, u8*, 5) = 9;
                } else {
                    M2C_FIELD(arg0, u8*, 5) = 8;
                }
            } else if (r < 6) {
                M2C_FIELD(arg0, u8*, 5) = 9;
            } else {
                M2C_FIELD(arg0, u8*, 5) = 7;
            }
        } else {
            if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
                if (r < 8) {
                    M2C_FIELD(arg0, u8*, 5) = 5;
                } else {
                    M2C_FIELD(arg0, u8*, 5) = 8;
                }
            } else if (r < 6) {
                M2C_FIELD(arg0, u8*, 5) = 8;
            } else {
                M2C_FIELD(arg0, u8*, 5) = 7;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
#undef D_800CCF5C
