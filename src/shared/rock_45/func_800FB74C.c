#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
s32 random_byte();                            /* extern */
extern s8 D_800CCF5C;
extern s32 D_800FCA84;

void func_800FB74C(void* arg0) {
    u32 r;
    u8* p;
    s32 t;
    s32 x;
    u8 v;

    r = random_byte() & 0xF;
    M2C_FIELD(arg0, u8*, 0x8B) = 0;
    if (D_800CCF5C / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
        if (r < 0xA) {
            M2C_FIELD(arg0, u8*, 0x8A) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x8A) = 1;
        }
    } else if (r < 6) {
        M2C_FIELD(arg0, u8*, 0x8A) = 2;
    } else {
        M2C_FIELD(arg0, u8*, 0x8A) = 3;
    }
    p = ((u8*)&D_800FCA84 + 0x28C);
    t = (u8)M2C_FIELD(arg0, u8*, 0x8B)++;
    x = M2C_FIELD(arg0, u8*, 0x8A) * 6;
    v = p[t + x];
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = v;
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
