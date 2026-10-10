#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s16 D_800970AA;
extern s16 D_800F6AFA;

void func_800F15E8(void* arg0) {
    s32 angle;
    s32 t;

    switch (M2C_FIELD(arg0, s8*, 0x2)) {
    case 1: {
        s32 x = D_800F6AFA;
        s32 e = M2C_FIELD(arg0, s16*, 0xE) - 0x52B;
        angle = func_80065B74(x - e, D_800970AA - M2C_FIELD(arg0, s16*, 0xA));
    } break;
    case 2: {
        s32 x = D_800F6AFA;
        s32 e = M2C_FIELD(arg0, s16*, 0xE) - 0x51B;
        angle = func_80065B74(x - e, D_800970AA - M2C_FIELD(arg0, s16*, 0xA));
    } break;
    case 3: {
        s32 x = D_800F6AFA;
        s32 e = M2C_FIELD(arg0, s16*, 0xE) - 0x50B;
        angle = func_80065B74(x - e, D_800970AA - M2C_FIELD(arg0, s16*, 0xA));
    } break;
    case 4: {
        s32 x = D_800F6AFA;
        s32 e = M2C_FIELD(arg0, s16*, 0xE) - 0x4FB;
        angle = func_80065B74(x - e, D_800970AA - M2C_FIELD(arg0, s16*, 0xA));
    } break;
    }
    t = func_80065A14(angle) * 16;
    M2C_FIELD(arg0, s32*, 0x20) = t * 3;
    t = -func_80065944(angle) * 16;
    M2C_FIELD(arg0, s32*, 0x24) = t * 3;
    func_80016C48(2, 0x35, arg0);
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}
