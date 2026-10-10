#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
M2C_UNK func_8002CB50();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80031DA8();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern struct X4_PlayerObj D_800970A0;
extern M2C_UNK D_800F6B8C;
extern void (*D_800F6BD8[])(s8*);
extern M2C_UNK D_800F76EC;

void func_800EBF18(s8* arg0) {
    s8* s2;
    s32 d;

    s2 = M2C_FIELD(arg0, s8**, 0x7C);
    D_800F6BD8[arg0[6]](arg0);
    if (arg0[6] == 4 || arg0[6] >= 8) {
        arg0[3] = 0;
        return;
    }
    if (arg0[6] == 5) {
        arg0[3] ^= 1;
        return;
    }
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    func_80032B34((struct X4_PlayerObj*)arg0);
    if (func_8002CBFC(arg0, 0x80, 0x80) == 0) {
        func_8002CB50(arg0);
    }
    if (arg0[2] == 0xC) {
        func_80031F4C((struct X4_PlayerObj*)arg0);
    }
    func_80032BE8((struct X4_PlayerObj*)arg0);
    func_8003208C(arg0);
    {
        struct X4_PlayerObj* p = &D_800970A0;
        if (((u8*)p)[0xE5] == 0) {
            d = p->x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
            if (d >= 0) {
                if (d < 0x30) {
                    goto call;
                }
            } else if (M2C_FIELD(arg0, s16*, 0xA) - p->x_pos.i.hi < 0x30) {
            call:
                func_80031DA8(arg0);
            }
        }
    }
    if (arg0[2] == 0xA) {
        if (s2[7] == 4) {
            func_800477E4(2, &D_800F6B8C, arg0);
            func_8002C9B0(arg0);
            return;
        }
        if (arg0[0x72] & 4) {
            __builtin_memcpy(&D_800F76EC, (s32*)&D_800970A0, 0x154);
            ((void (*)(M2C_UNK*))func_8002F288)(&D_800F76EC);
            if (((u8*)&D_800F76EC)[0x70] & 8) {
                s2[7] = 4;
            }
        }
    } else if ((arg0[0x72] & 4) && arg0[6] == 6) {
        __builtin_memcpy(&D_800F76EC, (s32*)&D_800970A0, 0x154);
        ((void (*)(M2C_UNK*))func_8002F288)(&D_800F76EC);
        if (((u8*)&D_800F76EC)[0x70] & 8) {
            func_800477E4(3, &D_800F6B8C, arg0);
            s2[7]--;
            {
                u8* q = (u8*)s2 + 0x86;
                q += arg0[7];
                *q -= 1;
            }
            arg0[4] = 4;
        }
    }
}
