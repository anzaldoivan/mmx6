#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F(T, o) (*(T*)((u8*)arg0 + (o)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CA54();
s32 func_8002CAB4(struct X4_BaseObj*);
s32 func_8002CB50(struct X4_BaseObj*);
M2C_UNK func_8002D230(void*);
void func_8002F288(struct X4_PlayerObj*);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_8004E26C(void*);
extern s32 D_80097420;

void func_8004DA7C(void* arg0) {
    s32 var_v1;
    u8 temp_a0;
    u8* temp_a1;

    temp_a0 = F(u8, 0x70);
    if (((temp_a0 & 0xC) == 0xC) || ((temp_a0 & 3) == 3)) {
        F(u8, 0x85) = 1;
        F(s8, 0x67) = 0;
        F(s32, 0x24) = 0;
        F(s32, 0x2C) = 0;
        func_8002F288(arg0);
        F(void*, 0x68) = 0;
        if (F(u16, 0x80) >= 0x3D) {
            F(u16, 0x80) = 0x3C;
        }
    }
    if (F(u8, 0x85) == 0) {
        if (F(s8, 0x67) != 0) {
            if (F(u8, 0x70) & 8) {
                if (F(s8, 0x6) == 0) {
                    var_v1 = F(s32, 0x24);
                    F(s8, 0x6) = 1;
                    F(s32, 0x2C) = 0x8000;
                    F(s32, 0x24) = (var_v1 < 0 ? -var_v1 : var_v1) >> 1;
                    ((void (*)(void*))func_8002D230)(arg0);
                } else {
                    F(s8, 0x6) = 0;
                    F(s8, 0x67) = 0;
                }
            } else {
                func_8002D230(arg0);
            }
        } else {
            if (!(F(u8, 0x70) & 8)) {
                F(s8, 0x6) = 0;
                F(s32, 0x24) = 0;
                F(s32, 0x2C) = 0x8000;
                F(s8, 0x67) = 1;
            }
            func_80017A04(arg0);
        }
    } else {
        func_80017A04(arg0);
    }
    if (F(s32, 0x10) == 0) {
        if (--F(u16, 0x80) == 0) {
            F(u8, 0x4) = 3;
            return;
        }
    }
    func_8004E26C(arg0);
    if (func_8002CAB4(arg0) != 0) {
        if (F(s32, 0x10) != 0) {
            func_8002CA54(arg0);
        } else {
            F(u8, 0x4) = 3;
            F(u8, 0x5) = 0;
        }
    } else {
        F(u8, 0x3) = 0;
        if ((F(u16, 0x80) < 0x3C) && (D_80097420 & 1)) {
            return;
        }
        ((s32 (*)())func_8002CB50)(arg0);
    }
    temp_a1 = F(u8*, 0x68);
    if ((((s32(*)(void*, s16, s32))func_80030234)(
             arg0, F(s16, 0xA), F(s16, 0xE) + temp_a1[3] + (s8)temp_a1[1]) &
         0xFF) == 0x3A) {
        F(s16, 0xA)--;
    }
}

#undef F
