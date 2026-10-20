#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002B6B0();
M2C_UNK func_8003C4EC();
M2C_UNK func_8003CDF0();
M2C_UNK func_8003CE30(void*);
M2C_UNK func_8003F3DC(void*);
extern s32 D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;

void func_800EF9F4(void* arg0) {
    void* p;
    s32 v;

    if (M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (s16)((u16)M2C_FIELD(arg0, s16*, 0x7C) - 1);
        return;
    }
    func_80016C48(1, 1, arg0);
    p = &D_800970A0;
    D_800971F8[0].unk44 = 0;
    D_800971F8[1].unk44 = 0;
    D_800971F8[2].unk44 = 0;
    v = 2;
    D_800CCED0.unk10 = v;
    D_800CCED0.unk11 = v;
    D_800CCED0.unk12 = v;
    D_800CCED0.unk13 = v;
    D_800CCED0.unk14 = v;
    D_800CCED0.unk15 = v;
    D_800CCED0.unk16 = v;
    D_800CCED0.unk17 = v;
    D_800CCED0.unk19 = v;
    M2C_FIELD(arg0, u8*, 0) |= 8;
    M2C_FIELD(arg0, s32*, 0x88) = M2C_FIELD(p, s32*, 0x68);
    M2C_FIELD(p, s32*, 0x68) = 0;
    M2C_FIELD(p, s8*, 5) = 2;
    func_8003F3DC(p);
    func_8003CDF0(p);
    func_8003CE30(p);
    func_8003C4EC(p);
    func_8002B6B0();
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x82) = M2C_FIELD(arg0, s16*, 0x80) =
        M2C_FIELD(p, s16*, 0xA);
    M2C_FIELD(arg0, u8*, 6) += 1;
}
