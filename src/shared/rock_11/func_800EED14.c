#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002D2D4();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_800F4664(s16 arg0, s16 arg1);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FC99C;
extern s32 D_800FC9A0;
extern u8 D_800FC9C0[];
extern void (*D_800FCAF4[])(void*);
extern s8 D_800FD51C;
extern s8 D_800FD51D;
extern s8 D_800FD51E;
extern s8 D_800FD51F;
extern s8 D_800FD520;
extern s8 D_800FD521;
extern u8 D_800FD522;

void func_800EED14(void* arg0) {
    s32 i;
    s32 y;
    s16 x;
    s16 dy;
    s32 t;
    s32 tx;

    if (D_800FD51D != 0) {
        if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x40) {
            D_800FD520 = 0;
            D_800FD51C = 0;
            for (i = 0; i < D_800FD51F / 2 + 1; i++) {
                y = i << 5;
                x = 0x10 - (func_8002D2D4() & 0x1F);
                dy = 0x10 - (func_8002D2D4() & 0x1F);
                t = dy + 8;
                tx = background_objects[0].x_pos.u.hi + 0x10;
                func_800F4664(x + tx,
                              background_objects[0].y_pos.i.hi + (y + t));
                x = 0x10 - (func_8002D2D4() & 0x1F);
                dy = 0x10 - (func_8002D2D4() & 0x1F);
                t = dy + 8;
                tx = background_objects[0].x_pos.u.hi + 0x130;
                func_800F4664(x + tx,
                              background_objects[0].y_pos.i.hi + (y + t));
            }
            func_80027BA0(0, background_objects[0].x_pos.i.hi,
                          background_objects[0].y_pos.i.hi, D_800FC9C0);
            func_80027BA0(0, background_objects[0].x_pos.i.hi + 0x120,
                          background_objects[0].y_pos.i.hi, &D_800FC9C0[8]);
            D_800FD51F = 0;
            background_objects[0].unk4C = 1;
            D_800FD521 = 0;
        }
        goto block_14;
    }
    switch (M2C_FIELD(arg0, s8*, 2)) {
    case 0x11:
    case 0x12:
    case 0x13:
        if (D_800FD51E == 0) {
            break;
        }
        M2C_FIELD(arg0, u16*, 0xA) =
            background_objects[0].x_pos.u.hi + M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) =
            background_objects[0].y_pos.u.hi + M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(arg0, s8*, 3) = 0;
        ((void (*)(void*))func_80049E50)(arg0);
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        ((void (*)(s32, void*, void*))func_800477E4)(4, &D_800FC99C, arg0);
        goto block_14;
    case 0x20:
        if (D_800FD51E == 0) {
            break;
        }
    block_14:
        M2C_FIELD(arg0, s8*, 4) = 3;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    ((void (*)(void*))func_80017A04)(arg0);
    D_800FCAF4[M2C_FIELD(arg0, s8*, 5)](arg0);
    if (func_80031474(arg0) < 0) {
        switch (M2C_FIELD(arg0, s8*, 2) & 0xF0) {
        case 0x10:
            D_800FD522 -= 1;
            M2C_FIELD(arg0, u16*, 0xA) =
                background_objects[0].x_pos.u.hi + M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(arg0, u16*, 0xE) =
                background_objects[0].y_pos.u.hi + M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, s8*, 3) = 0;
            ((void (*)(void*))func_80049E50)(arg0);
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            ((void (*)(s32, void*, void*))func_800477E4)(4, &D_800FC99C, arg0);
            M2C_FIELD(arg0, s8*, 4) = 3;
            return;
        case 0x30:
            ((void (*)(void*, s32))func_800179A4)(arg0, 0x41);
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            ((void (*)(void*))func_80049E50)(arg0);
            ((void (*)(s32, void*, void*))func_800477E4)(4, &D_800FC9A0, arg0);
            M2C_FIELD(arg0, s8*, 6) = 4;
            D_800FD521 -= 1;
            return;
        }
    }
    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) != 0x20) {
        ((void (*)(void*))func_80030ECC)(arg0);
    }
}
