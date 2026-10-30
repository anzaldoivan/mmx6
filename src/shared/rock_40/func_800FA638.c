#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
void func_800FE2FC(void* arg0);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007569C;
extern M2C_UNK D_800FF668;

void func_800FA638(void* arg0) {
    s32 r;

    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 4) != 1) {
        M2C_FIELD(arg0, u8*, 4) = 6;
        M2C_FIELD(arg0, u8*, 3) = 0;
        return;
    }
    func_80017A04(arg0);
    (*(void (**)(void*))((s8*)&D_800FF668 + 0x5EC +
                         (M2C_FIELD(arg0, s8*, 5) << 2)))(arg0);
    func_800FE2FC(arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        // !FAKE: shared kill block inside the switch arm, as retail's one copy
        goto block_kill;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, s16*, 0x84) = 0x14;
        switch (r) {
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 38:
        case 40:
        case 51:
        case 52:
            if (M2C_FIELD(&D_800FF668, s16*, 0x7B8) >= 2) {
                if (++M2C_FIELD(arg0, s8*, 0x8D) == 4) {
                block_kill:
                    func_80049E50(arg0);
                    M2C_FIELD(arg0, u8*, 4) = 6;
                    M2C_FIELD(arg0, u8*, 3) = 0;
                    return;
                }
            }
            break;
        }
    }
    if (M2C_FIELD(arg0, s16*, 0x84) != 0) {
        if (M2C_FIELD(arg0, s16*, 0x84)-- & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007569C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}
