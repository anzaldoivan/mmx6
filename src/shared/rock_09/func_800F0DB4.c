#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 func_8002D2D4();
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F6924[];

void func_800F0DB4(void* arg0) {
    u32 r;
    u8 i;
    s32 v;
    u8* e;

    r = func_8002D2D4() & 0xF;
    e = (u8*)&D_800CCED0;
    M2C_FIELD(arg0, u8*, 0x87) = 0;
    if (M2C_FIELD(e, u8*, 0x68) == 2) {
        if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C)) {
            if (r < 8) {
                M2C_FIELD(arg0, u8*, 0x86) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x86) = 1;
            }
        } else if (r < 8) {
            M2C_FIELD(arg0, u8*, 0x86) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x86) = M2C_FIELD(e, u8*, 0x68);
        }
    } else if (M2C_FIELD(e, s8*, 0x8C) / 2 < M2C_FIELD(arg0, s8*, 0x5C) ||
               r < 8) {
        M2C_FIELD(arg0, u8*, 0x86) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x86) = 1;
    }
    i = M2C_FIELD(arg0, u8*, 0x87)++;
    v = D_800F6924[i + M2C_FIELD(arg0, u8*, 0x86) * 6];
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 5) = v;
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}
