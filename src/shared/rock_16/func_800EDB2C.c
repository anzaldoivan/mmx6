#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CB50();
extern struct X4_EngineObj D_800CCED0;
extern u16 D_800F111C[][2];

#define SEL (D_800CCED0.character_state.bytes[1])
#define E66 ((u8)D_800CCED0.character_state.bytes[0x40])

static inline s32 chr_idx_800EDB2C(s32 x) {
    if (x == 8) {
        if (E66 == 3) {
            return 8;
        }
        if (E66 == 4) {
            return 9;
        }
        return 10;
    }
    return x;
}

void func_800EDB2C(void* arg0) {
    s32 i;
    s32 y;

    if (SEL == 8) {
        y = 8;
        if (E66 != 3) {
            y = 10;
            if (E66 == 4) {
                y = 9;
            }
        }
        i = y;
    } else {
        i = SEL;
    }
    *(u16*)((u8*)arg0 + 0xA) = D_800F111C[i][0];
    *(u16*)((u8*)arg0 + 0xE) = D_800F111C[chr_idx_800EDB2C(SEL)][1];
    ((void (*)())func_8002CB50)(arg0);
}

#undef SEL
#undef E66
