#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ABS(x) ((x) < 0 ? -(x) : (x))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D2B0(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F1B50(void* arg0) {
    s32 ang;
    u8 t;
    s32 v;
    s32 d;

    ang = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) -
                            (D_800971F8[0].unk2A + M2C_FIELD(arg0, s16*, 0x86)),
                        (D_800971F8[0].unk26 + M2C_FIELD(arg0, s16*, 0x84)) -
                            M2C_FIELD(arg0, s16*, 0xA));
    {
        s32 w = func_80065A14(ang);
        s32 e = w << 4;
        M2C_FIELD(arg0, s32*, 0x20) = ((w << 5) + e) << 1;
    }
    v = func_80065944(ang);
    d = v << 4;
    M2C_FIELD(arg0, volatile s32*, 0x24) = ((v << 5) + d) << 1;
    {
        register s32 x asm("$2") = M2C_FIELD(arg0, volatile s32*, 0x20);
        if (x >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    func_8002D2B0(arg0);
    {
        s32 x = M2C_FIELD(arg0, s16*, 0xA);
        x -= D_800971F8[0].unk26;
        if (ABS(M2C_FIELD(arg0, s16*, 0x84) - x) < 6 &&
            ABS(M2C_FIELD(arg0, s16*, 0x86) -
                (M2C_FIELD(arg0, s16*, 0xE) - D_800971F8[0].unk2A)) < 6) {
            goto hit;
        }
    }
    {
        register s32 f asm("$2") = M2C_FIELD(arg0, u8*, 0x15);
        register u8 t asm("$3") = f;
        if (f == 0 && (M2C_FIELD(arg0, u8*, 0x70) & 2)) {
            goto hit;
        }
        if (t == 0x40 && (M2C_FIELD(arg0, u8*, 0x70) & 1)) {
        hit:
            func_80016C48(2, 0x12, arg0);
            func_80012D9C(8);
            {
                register s32 c asm("$2") = M2C_FIELD(arg0, u8*, 0x6);
                M2C_FIELD(arg0, u8*, 0x6) = c + 1;
            }
        }
    }
}
