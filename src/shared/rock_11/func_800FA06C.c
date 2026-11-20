// rolefeed (3.1 T4): func_800FA06C of src/rock_11/E9860.c
#include "common.h"
#include "mmx6/rock_11.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"

void* enemy_slot_alloc();
extern u16 D_800FDA7E;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800FA06C(void* arg0, u8 arg1) {
    void* obj;

    obj = enemy_slot_alloc();
    if (obj != 0) {
        UB(obj, 0) = 0x41;
        UB(obj, 1) = 0x3A;
        UB(obj, 0x15) = UB(arg0, 0x15);
        UB(obj, 2) = arg1;
        UH(obj, 0xA) = UH(arg0, 0xA);
        UH(obj, 8) = 0;
        UH(obj, 0xE) = UH(arg0, 0xE);
        UH(obj, 0xC) = 0;
        UH(obj, 0x42) = UH(arg0, 0x42) & 0x7FFF;
        W(obj, 0x30) = W(arg0, 0x30);
        W(obj, 0x3C) = W(arg0, 0x3C);
        UH(obj, 0x40) = UH(arg0, 0x40);
        UB(obj, 0x14) = UB(arg0, 0x14);
        if (SB(arg0, 2) == 0) {
            P(obj, 0x80) = arg0;
        } else {
            P(obj, 0x80) = P(arg0, 0x80);
        }
        D_800FDA7E += 1;
    }
}
