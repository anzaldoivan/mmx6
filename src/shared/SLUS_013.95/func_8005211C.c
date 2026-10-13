#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
M2C_UNK func_8002CA14();
s32 func_8002CAB4(struct X4_BaseObj*);
extern s8 D_8008EAB0;
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

void func_8005211C(void* arg0) {
    u16* r;
    u16 v;

    if (func_8002CAB4(arg0) == 0) {
        r = M2C_FIELD(arg0, u16**, 0x18);
        if (D_800970A0.x_pos.i.hi <= r[1] && r[0] <= D_800970A0.x_pos.i.hi &&
            D_800970A0.y_pos.i.hi <= r[3] && r[2] <= D_800970A0.y_pos.i.hi) {
            D_800971F8[0].unk47 = 2;
            v = M2C_FIELD(arg0, u16**, 0x18)[4];
            if (v != 0xFFFF) {
                D_800971F8[0].unk26 = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[5];
            if (v != 0xFFFF) {
                D_800971F8[0].unk24 = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[6];
            if (v != 0xFFFF) {
                D_800971F8[0].unk2A = v;
            }
            v = M2C_FIELD(arg0, u16**, 0x18)[7];
            if (v != 0xFFFF) {
                D_800971F8[0].unk28 = v;
            }
            if (M2C_FIELD(arg0, s8*, 2) & 0x80) {
                D_8008EAB0 = 1;
                func_8002C9B0(arg0, &D_800970A0);
            }
        }
    } else {
        func_8002CA14(arg0);
    }
}
