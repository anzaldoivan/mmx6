#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

struct X4_VisualObj* func_8002C398(void);
s32 func_8002D30C();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern struct X4_EngineObj g_playthrough_state;
extern M2C_UNK D_800F55DC;

void func_800EAEF8(void* arg0) {
    void* v;
    s32 r;
    s32 t;
    s16 y;
    struct X4_EngineObj* f;
    struct X4_EngineObj* e;

    if (FX(arg0, s8, 0x5C) <= 0) {
        if (FX(arg0, s16, 0x80) != 0) {
            FX(arg0, s16, 0x80)--;
            if (!(FX(arg0, u8, 0x80) & 7)) {
                v = func_8002C398();
                if (v != 0) {
                    FX(v, u8, 0x0) = 0x21;
                    FX(v, u8, 0x1) = 4;
                    FX(v, u8, 0x2) = 0;
                    FX(v, u8, 0x4) = 0;
                    FX(v, u8, 0x5) = 0;
                    FX(v, u8, 0x6) = 0;
                    t = func_8002D30C() % 16 - 0x10;
                    FX(v, s16, 0xA) = FX(arg0, s16, 0xA) + t;
                    r = func_8002D30C() % 128 - 0x40;
                    FX(v, s16, 0xE) = FX(arg0, s16, 0xE) + r;
                    FX(v, u8, 0x15) = 0;
                    FX(v, u8, 0x14) = 0;
                    FX(v, u8, 0x16) = 1;
                }
                if (!(FX(arg0, u8, 0x80) & 0x1F)) {
                    func_800477E4(4, &D_800F55DC, arg0);
                }
            }
        } else {
            FX(arg0, u8, 0x3) = 0;
            FX(arg0, u8, 0x4) = 3;
            func_8004E654(arg0, 0x15);
            e = &g_playthrough_state;
            if (e->stage == 5) {
                y = FX(arg0, s16, 0xE);
                if (y == 0x150 || y == 0x240 || y == 0x420 || y == 0x510) {
                    f = &g_playthrough_state;
                    FX(f, u8, 0x2F)++;
                }
            }
        }
    } else {
        FX(arg0, s16, 0x80) = 0x78;
    }
}
