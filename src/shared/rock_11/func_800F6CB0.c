// rolefeed (3.1 T4): func_800F6CB0 of src/rock_11/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
void func_800FA31C(void* arg0);
s32 func_800FA584(s16* arg0, s16 arg1, s16 arg2, s16 arg3);
extern u8 D_800FD45C[];

void func_800F6CB0(void* arg0) {
    u16 t;

    if (M2C_FIELD(arg0, s8*, 0x8A) != 0) {
        M2C_FIELD(arg0, s8*, 0x8A) = 0;
        M2C_FIELD(arg0, u16*, 0x88) += 0x20;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        if ((M2C_FIELD(arg0, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0x88)) <
            (D_8009721E + 0x10)) {
            M2C_FIELD(arg0, u16*, 0x88) =
                (u16)(M2C_FIELD(arg0, u16*, 0xA) - 0x10) - (u16)D_8009721E;
        }
    } else if ((M2C_FIELD(arg0, s16*, 0xA) + M2C_FIELD(arg0, s16*, 0x88)) >
               (D_8009721E + 0x140)) {
        M2C_FIELD(arg0, u16*, 0x88) =
            (u16)D_8009721E - (u16)(M2C_FIELD(arg0, u16*, 0xA) - 0x140);
    }
    func_800FA584((s8*)arg0 + 0x86, M2C_FIELD(arg0, s16*, 0x88), 4, 1);
    func_800FA31C(arg0);
    if (M2C_FIELD(arg0, u16*, 0x84) & 0xF) {
        t = M2C_FIELD(arg0, u16*, 0x86);
        if (!(t & 0xF)) {
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                func_80027BA0(0, (M2C_FIELD(arg0, s16*, 0xA) - (s16)t) & 0xFFF0,
                              M2C_FIELD(arg0, s16*, 0xE) & 0xFFF0, D_800FD45C);
            } else {
                func_80027BA0(
                    0, ((M2C_FIELD(arg0, s16*, 0xA) + (s16)t) & 0xFFF0) - 0x10,
                    M2C_FIELD(arg0, s16*, 0xE) & 0xFFF0, D_800FD45C);
            }
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, u16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
    M2C_FIELD(arg0, u16*, 0x84) = M2C_FIELD(arg0, u16*, 0x86);
}
