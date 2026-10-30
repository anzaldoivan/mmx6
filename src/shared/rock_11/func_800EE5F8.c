#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800EE5F8 (*(s32**)0x1F800020)

s32 func_80013AA4(s8 arg0);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
s32 func_8002B2F8(s32);
s32 random_byte();
void func_800478F0(s32, void*, void*, u16, s32, s32);
void func_800F4664(s16 arg0, s16 arg1);
extern u32* D_80095098;
extern s8 D_800970A5;
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800C4560;
extern s8 D_800CCEF4;
extern u8 D_800FC9A4[];
extern u8 D_800FC9D0[];

#define F(type, off) M2C_FIELD(self, type*, off)

// str 0x800FC9A4 sha1=6d053fc8f29c0bf2185d6a1e0f2776be21a6d66d = "printable byte run: a table, not text"
void func_800EE5F8(void* self) {
    s32 i;
    s32 row;
    s16 x;
    s16 y;

    if (D_800970A5 == 0x14) {
        D_800CCEF4 = 0;
        func_80027BA0(1, 0x1140, 0x2F0, D_800FC9D0);
        i = 0;
        do {
            row = i << 5;
            func_800F4664(background_objects[0].x_pos.u.hi + 0xF8 +
                              (random_byte() & 0x1F),
                          (s16)(background_objects[0].y_pos.i.hi - 0x10) +
                              (row + (s16)((random_byte() & 0x1F) + 8)));
            i++;
            func_800F4664(background_objects[0].x_pos.u.hi + 0x118 +
                              (random_byte() & 0x1F),
                          (s16)(background_objects[0].y_pos.i.hi - 0x10) +
                              (row + (s16)((random_byte() & 0x1F) + 8)));
        } while (i < 8);
        x = F(s16, 0xA);
        y = F(s16, 0xE);
        F(s8, 0x3) = 1;
        F(s8, 0x14) = 0;
        F(u16, 0x40) += 0x400;
        F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1)) + 1] >> 7;
        F(s16, 0x42) = (((func_8002A47C(F(s8, 1)) + 1) * 4 + 0x20) % 16) |
                       (((func_8002A47C(F(s8, 1)) + 1 + 8) / 4 + 0x1E0) << 6);
        F(u8*, 0x3C) =
            (u8*)SPAD20_800EE5F8 + SPAD20_800EE5F8[func_8002A47C(F(s8, 1)) + 1];
        F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x120;
        F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0x60;
        func_800478F0(5, D_800FC9A4, self, F(u16, 0x42), 0, 0);
        F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x120;
        F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0x20;
        func_800478F0(4, D_800FC9A4, self, F(u16, 0x42), 0, 0);
        F(s16, 0xA) = background_objects[0].x_pos.i.hi + 0x110;
        F(s16, 0xE) = background_objects[0].y_pos.i.hi + 0xD0;
        func_800478F0(4, D_800FC9A4, self, F(u16, 0x42), 0, 0);
        F(s8, 0x3) = 0;
        F(s8, 0x14) = -1;
        F(s16, 0xA) = x;
        F(s16, 0xE) = y;
        F(u16, 0x40) -= 0x400;
        F(u16, 0x40) = D_80095098[func_8002A47C(F(s8, 1))] >> 7;
        F(s16, 0x42) = (((func_8002A47C(F(s8, 1))) * 4 + 0x20) % 16) |
                       (((func_8002A47C(F(s8, 1)) + 8) / 4 + 0x1E0) << 6);
        F(u8*, 0x3C) =
            (u8*)SPAD20_800EE5F8 + SPAD20_800EE5F8[func_8002A47C(F(s8, 1))];
        background_objects[1].unk4C = 1;
        func_8002B2F8(0);
        D_800C4560 |= 1;
        func_80013AA4(0x3C);
        F(u8, 0x6)++;
    }
}

#undef F
#undef SPAD20_800EE5F8
