#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800970A5;
extern struct X4_EngineObj g_playthrough_state;

// 0x800F2390 init_illumina: Illumina sub-boss start.
// basis: community tweaks-index.tsv:183
// callers: none known
void init_illumina(void* arg0) {
    if (D_800970A5 == 0x14) {
        s8* e = (s8*)&g_playthrough_state;
        M2C_FIELD(e, u8*, 0x24) = 0;
        M2C_FIELD(e, u8*, 0x25) = 0;
        M2C_FIELD(e, void**, 0x20) = arg0;
        M2C_FIELD(e, u8*, 0x8C) = 0x40;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
