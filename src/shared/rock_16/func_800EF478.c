#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800F0E74[];

#define EF478_ENG_2A (D_800CCED0.character_state.bytes[4])
#define EF478_ENG_70 (*(s32*)((u8*)&D_800CCED0 + 0x70))
#define EF478_U8(o) (*(u8*)((s8*)arg0 + (o)))

void func_800EF478(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (51/54)
    register s32 t asm("$2");
    func_800179D0(arg0, 4, EF478_ENG_2A);
    t = D_800CCED0.unk5F;
    if (t & 0x10) {
        if (D_800CCED0.unk1 == 5) {
            EF478_U8(3) = 0;
        }
        if (D_800CCED0.unk1 == 6) {
            func_8002CCB0(arg0, 0x60, 0x10);
        }
    } else {
        func_8002CCB0(arg0, 0x60, 0x10);
    }
    if (!(D_800F0E74[EF478_ENG_2A] & EF478_ENG_70)) {
        EF478_U8(3) = 0;
    }
}

#undef EF478_ENG_2A
#undef EF478_ENG_70
#undef EF478_U8
