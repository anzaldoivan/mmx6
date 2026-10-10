#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s8 func_8001C1AC(u8);
s32 func_8001C384(s32, u8, s32);
s32 func_8001C4C0(u8, void*, void*);
s32 func_8001C5EC(u8);
s32 func_8001C8C4(void*);
M2C_UNK func_8002B838();
void* func_8002C530();
void func_800ED45C();
void func_800F02A0(u8, s8, s32, s16);
M2C_UNK func_800F0324(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
void func_800F07B4(void*);
extern u8 D_8006D620;
extern struct X4_EngineObj D_80097420;
extern u8 D_80097427;
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800E2FA0[];
extern u8 D_800E9860[];

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800EB2D4(u8* arg0) {
    s32 ret;
    register s32 done asm("$2");
    u32 sel;
    u32 i;
    u8* obj;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2] = D_800E2F90.x_pos.bytes[2] - 1;
        return;
    }
    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        register s32 one asm("$4") = 1;
        register s32 two asm("$3") = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097427 = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    sel = func_8001C1AC(D_800E2F90.unk6);
    D_80097420.unk7 = 0;
    switch (sel) {
    case 1:
        arg0[1] = 0x15;
        D_800E2F90.x_pos.bytes[0] = sel;
        arg0[3] = sel;
        return;
    case 2:
        arg0[2] = 0;
        arg0[1] = arg0[1] + 1;
        return;
    case 3:
        arg0[1] = 0x15;
        D_800E2F90.x_pos.bytes[0] = 2;
        arg0[3] = 0x12;
        return;
    case 0: {
        register u8* addr asm("$6") = D_800E9860 + 4;

        if (func_8001C4C0(D_800E2F90.unk6, D_800E2FA0, addr) == 0) {
            if (F32(D_800E2FA0, 0x14C) == 0x1E000) {
                if (func_8001C4C0(D_800E2F90.unk6, D_800E2FA0,
                                  D_800E9860 + 8) == 0) {
                    if (F8(D_800E2FA0, 0x14A) != 0) {
                        if (func_8001C384(*(s32*)&D_800E2F90, D_800E2F90.unk6,
                                          0x2000) == 0) {
                            func_8001C8C4(((u8*)D_800E2F90.y_pos.val));
                            goto block_29;
                        }
                    } else {
                        arg0[1] = 0x15;
                        D_800E2F90.x_pos.bytes[0] = 3;
                        D_80097420.unk7 = 0;
                        arg0[3] = 5;
                        return;
                    }
                }
            } else if (func_8001C4C0(D_800E2F90.unk6, D_800E2FA0,
                                     D_800E9860 + 8) == 0) {
                if (F8(D_800E2FA0, 0x14A) != 0) {
                    if (func_8001C384(*(s32*)&D_800E2F90, D_800E2F90.unk6,
                                      0x2000) != 0) {
                        return;
                    }
                    ((void (*)(void*))func_8001C8C4)(
                        ((u8*)D_800E2F90.y_pos.val));
                } else {
                    register s32 ff asm("$5") = 0xFF;

                    ((u8*)D_800E2F90.y_pos.val)[0] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0x3BC] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0x778] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0xB34] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0xEF0] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0x12AC] = ff;
                    ((u8*)D_800E2F90.y_pos.val)[0x1668] = ff;
                    {
                        register u8* p asm("$4") = (u8*)D_800E2F90.y_pos.val;

                        p[0x1A24] = ff;
                    }
                }
            block_29:
                arg0[1] = arg0[1] + 2;
                ((void (*)())func_8002B838)();
                F16(arg0, 4) = 1;
                do {
                    func_800F07B4(arg0);
                } while (0);
                do {
                    func_800F02A0(0x9F, 0, 0x130, 0x1B);
                } while (0);
                i = 0;
                do {
                    func_800F0324((u8)(i + 0xA0), 0, 0xB0, (s16)(i * 16 + 0x30),
                                  (u8)i);
                    i++;
                } while (i < 8);
                obj = func_8002C530();
                if (obj != 0) {
                    obj[0] = 1;
                    F16(obj, 0xA) = 0xE0;
                    F16(obj, 0xE) = 0xC8;
                    obj[1] = 0x2E;
                    ((s8*)obj)[2] = -0x10;
                }
                obj = func_8002C530();
                if (obj != 0) {
                    obj[0] = 1;
                    obj[1] = 0x2D;
                    ((s8*)obj)[2] = -0x40;
                }
                arg0[3] = 8;
                D_80097420.unk7 = D_8006D620;
                for (i = 0; i < (u8)D_80097420.unk7; i++) {
                    D_800E2F90.y_pos.val += 0x3BC;
                }
                func_800ED45C();
            }
        }
        break;
    }
    }
}
