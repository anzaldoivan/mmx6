#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_BASE (*(u8**)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);        /* extern */
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16); /* extern */
extern struct X4_EngineObj g_playthrough_state;
extern u8* D_800F4E7C[];
extern u8 D_800F4E8C[];
extern M2C_UNK D_800F62F0;
extern M2C_UNK D_800F66F0;

void func_800EA08C(void* arg0) {
    u8 t;
    s32 i;
    u8* p;
    struct X4_EngineObj* e;

    t = M2C_FIELD(arg0, u8*, 2);
    if (M2C_FIELD(arg0, s8*, 2) == 4) {
        M2C_FIELD(arg0, u16*, 0x14) = 0x20;
        M2C_FIELD(arg0, s16*, 0x16) = 0;
        e = &g_playthrough_state;
        if (M2C_FIELD(e, s8*, 0x32) == 0) {
            M2C_FIELD(e, s8*, 0x32) = 1;
            __builtin_memcpy(SCRATCH_BASE + 0x3800, SCRATCH_BASE + 0x1260,
                             0x400);
        }
        __builtin_memcpy((u8*)&D_800F62F0, SCRATCH_BASE + 0x3800, 0x400);
        func_8002B54C(&D_800F66F0, &D_800F62F0, 0x200,
                      M2C_FIELD(arg0, u16*, 0x14));
        load_palette(0x93, &D_800F66F0, 0x20);
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(arg0, u8*, 5) = 0;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x15) = t & 0x80;
    M2C_FIELD(arg0, u8*, 2) = t & 0x7F;
    i = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 0x14) = D_800F4E8C[i * 6];
    p = D_800F4E7C[i];
    M2C_FIELD(arg0, u8**, 0x1C) = p;
    M2C_FIELD(arg0, u8*, 0x18) = p[0];
    M2C_FIELD(arg0, u8*, 0x19) = p[1];
    M2C_FIELD(arg0, u8*, 0x1A) = p[2];
    M2C_FIELD(arg0, u8*, 0x1B) = p[3];
    M2C_FIELD(arg0, u8*, 4) = 1;
}
