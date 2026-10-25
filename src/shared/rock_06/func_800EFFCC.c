#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230(void*);
M2C_UNK func_8003CCBC();
extern M2C_UNK g_Player;
extern s32 D_800F3A44;

void func_800EFFCC(void* arg0) {
    u8 f97;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s8*, 0x61) = 1;
        M2C_FIELD(arg0, s32**, 0x68) = &D_800F3A44;
        M2C_FIELD(arg0, u8*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, s16*, 0xA6) = 0;
        if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x4000;
        }
        f97 = M2C_FIELD(arg0, u8*, 0x97);
        if (f97 & 0x40) {
            void* pl;
            if (!(f97 & 2)) {
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s32*, 0x2C) = 0;
            }
            pl = &g_Player;
            M2C_FIELD(pl, u8*, 0xD5) = 0;
            M2C_FIELD(arg0, u8*, 0x97) ^= 0x40;
            func_8003CCBC(pl);
        }
        if (!(M2C_FIELD(arg0, u8*, 0xA8) & 8)) {
            M2C_FIELD(arg0, s8*, 5) = 0xC;
            M2C_FIELD(arg0, s8*, 6) = 0;
        } else {
            func_800179A4(arg0, 0x13);
        }
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    }
    if (M2C_FIELD(arg0, u8*, 0xA8) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 5) = 0;
        M2C_FIELD(arg0, u8*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, s16*, 0xA6) = 0;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        func_8002D230(arg0);
    }
    func_80017A04(arg0);
}
