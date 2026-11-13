#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003CCBC();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;

void func_800F0884(struct X4_MainObj* arg0) {
    s8* p;
    s32 a;
    s32 b;

    p = M2C_FIELD(arg0, s8**, 0x80);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 5;
                arg0->unk42 ^= 0x8000;
            }
        } else if (D_800CCED0.unk10 != 0) {
            struct X4_PlayerObj* pl = &D_800970A0;

            pl->unkE4 = 0;
            pl->x_pos.i.hi = 0xCC0;
            pl->y_pos.i.hi = 0x450;
            pl->facing = 0x40;
            D_800CCED0.unk10 = 0;
            func_8003CCBC(pl);
            func_8003D308(0x14, pl->facing);
            arg0->unk15 = 0;
            arg0->x_pos.i.hi = 0xD10;
            arg0->y_pos.i.hi = 0x480;
            arg0->unk40 = 0x140;
            a = func_8002A47C(arg0->id);
            b = func_8002A47C(arg0->id);
            arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            arg0->sprite_frames =
                (const u8*)(SPAD20 +
                            *(s32*)(func_8002A47C(arg0->id) * 4 + SPAD20));
            ((void (*)(void*, s32))func_800179A4)(arg0, 8);
        }
    } else {
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        arg0->action++;
    }
    func_8002CCB0(arg0, 0x30, 0x40);
}
