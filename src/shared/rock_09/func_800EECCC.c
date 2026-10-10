#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002BBF4();
s32 func_8002D2D4();
extern s32 D_800970A0;
extern s16 D_800970AA;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define PL ((struct X4_BaseObj*)&D_800970A0)

void func_800EECCC(void* arg0) {
    s32 flag;
    void* obj;

    flag = 0;
    switch (SB(arg0, 2)) {
    case 0:
        if ((u32)((u16)D_800970AA - 0x141) < 0x8BF) {
            flag = 1;
        }
        break;
    case 1:
        if ((u32)((u16)D_800970AA - 0xC81) < 0x3BF) {
            flag = 1;
        }
        break;
    case 2:
        if ((u32)((u16)D_800970AA - 0x4E1) < 0x17F) {
            flag = 1;
        }
        break;
    case 3:
        if ((u32)((u16)D_800970AA - 0x1361) < 0x92F) {
            flag = 1;
        }
        break;
    case 4:
        if ((u32)((u16)D_800970AA - 1) < 0x41F) {
            flag = 1;
        }
        break;
    case 5:
        if ((u32)(PL->x_pos.u.hi - 0x141) < 0x71F && PL->y_pos.i.hi < 0x430) {
            flag = 1;
        }
        break;
    }
    if (flag == 0) {
        return;
    }
    if (H(arg0, 0x7C) == 0) {
        obj = func_8002BBF4();
        if (obj != 0) {
            UB(obj, 0) = 0x41;
            UB(obj, 1) = 0x1A;
            UB(obj, 0x15) = UB(arg0, 0x15);
            if (PL->unk2 == 0) {
                UB(obj, 2) = 0xA;
            } else {
                UB(obj, 2) = 0xB;
            }
            if (PL->unk15 != 0) {
                UH(obj, 0xA) = PL->x_pos.u.hi + 0x20;
            } else {
                UH(obj, 0xA) = PL->x_pos.u.hi - 0x20;
            }
            UH(obj, 0xE) = PL->y_pos.u.hi;
            UH(obj, 0x42) = UH(arg0, 0x42) & 0x7FFF;
            W(obj, 0x30) = W(arg0, 0x30);
            W(obj, 0x3C) = W(arg0, 0x3C);
            UH(obj, 0x40) = UH(arg0, 0x40);
            UB(obj, 0x14) = UB(arg0, 0x14);
        }
        H(arg0, 0x7C) = (func_8002D2D4() % 3 + 1) * 100 + 200;
    } else {
        H(arg0, 0x7C)--;
    }
}
