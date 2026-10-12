#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002B36C(M2C_UNK);
struct X4_VisualObj* func_8002C398(void);
s32 func_8002D30C();
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_8009742C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_800EBBF4(void* arg0) {
    struct X4_VisualObj* obj;
    s32 r;
    s32 t;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8002B36C(0);
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        D_80090D5C = 0;
        D_80097430 = 0;
        D_800CF854 = 0;
        D_800C4560 |= 1;
        M2C_FIELD(arg0, u8*, 6)++;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x7C) & 7)) {
        obj = func_8002C398();
        if (obj != 0) {
            obj->active = 0x21;
            obj->id = 4;
            obj->unk2 = 0;
            obj->state = 0;
            obj->unk5 = 0;
            obj->unk6 = 0;
            if (M2C_FIELD(arg0, s8*, 2) == 0) {
                r = func_8002D30C() % 64 - 0x20;
                obj->x_pos.i.hi = M2C_FIELD(arg0, s16*, 0xA) + r;
            } else {
                r = func_8002D30C() % 64 - 0x20;
                obj->x_pos.i.hi = M2C_FIELD(arg0, s16*, 0xA) - r;
            }
            r = func_8002D30C() % 64 - 0x20;
            obj->y_pos.i.hi = M2C_FIELD(arg0, s16*, 0xE) + r;
            t = M2C_FIELD(arg0, u8*, 0x14);
            obj->unk16 = 0x13;
            obj->bg_offset = t;
        }
    }
    D_800971F8[1].unk3 ^= 1;
}
