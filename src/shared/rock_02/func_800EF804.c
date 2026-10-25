#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80030ECC(void*);
extern s32 D_800FB290;
extern s32 D_800FBC70;
extern s32 D_800FBC74;
extern void* D_800FBC78;

#define SET_ANIM2(obj, id, src)                                                \
    {                                                                          \
        s32 idx = func_8002A47C(M2C_FIELD(src, s8*, 1));                       \
        s32 base = SPAD20;                                                     \
        register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);              \
        M2C_FIELD(obj, s32*, 0x3C) = base + off;                               \
        ((void (*)(void*, s32, s32))func_800179A4)(obj, id, off);              \
    }

#define SET_ANIM(obj, id) SET_ANIM2(obj, id, D_800FBC78)

void func_800EF804(void* arg0) {
    void* p;
    void* q;

    if (D_800FBC70 != 0 || D_800FBC74 != 0) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            func_80016C48(2, 0, arg0);
            func_80012D9C(5);
            {
                s32 t = M2C_FIELD(arg0, u16*, 0xE);
                q = D_800FBC78;
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s32*, 0x2C) = 0;
                M2C_FIELD(arg0, s16*, 0xE) = t - 0x4E;
            }
            // !FAKE: depin: macro pin; drop breaks match (59/150)
            SET_ANIM2(arg0, 0x14, q);
            p = func_8002C458();
            if (p != 0) {
                u8 o = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(p, s8*, 1) = 1;
                M2C_FIELD(p, s8*, 2) = 3;
                M2C_FIELD(p, void**, 0x7C) = arg0;
                M2C_FIELD(p, u8*, 0) = o;
            }
            M2C_FIELD(arg0, s8*, 5)++;
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            // !FAKE: depin: macro pin; drop breaks match (59/150)
            SET_ANIM(arg0, 0x15);
            M2C_FIELD(arg0, void**, 0x50) = &D_800FB290;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, s8*, 5)++;
        }
        break;
    case 2:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x32) {
            // !FAKE: depin: macro pin; drop breaks match (59/150)
            SET_ANIM(arg0, 0x16);
            M2C_FIELD(arg0, void**, 0x50) = 0;
            M2C_FIELD(arg0, s8*, 5)++;
        }
        break;
    case 3:
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            M2C_FIELD(arg0, s8*, 4) = 2;
        }
        break;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
}
