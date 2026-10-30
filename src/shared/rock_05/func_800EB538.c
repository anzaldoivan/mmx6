#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();
s32 random_byte();
extern s8 D_800970A2;
extern s32 D_80097420;
extern struct X4_EngineObj g_playthrough_state;

void func_800EB538(void* arg0) {
    u8* e;
    void* p;
    void* o;
    s32 v;

    e = (u8*)&g_playthrough_state;
    p = M2C_FIELD(arg0, void**, 0x80);
    if (M2C_FIELD(e, u8*, 0x68) != 0 && M2C_FIELD(p, s8*, 5) < 8 &&
        M2C_FIELD(p, s8*, 0x8D) != 0 &&
        (u32)D_80097420 == ((u32)D_80097420 / 120) * 120) {
        o = func_8002C458();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x1D;
            if (M2C_FIELD(e, u8*, 0x68) != 1 && D_800970A2 == 0) {
                v = (random_byte() & 1) + 4;
            } else {
                v = 4;
            }
            M2C_FIELD(o, u8*, 2) = v;
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(o, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(o, void**, 0x7C) = arg0;
            play_sound(2, 0x1F, arg0);
        }
    }
    func_80017A04(arg0);
}
