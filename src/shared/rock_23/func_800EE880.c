#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_800139F4(M2C_UNK);
s32 func_8002D2D4();
M2C_UNK func_80027BA0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK*);

extern s16 D_800970AA;
extern u8 D_80097244;
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F91B4[][4];
extern M2C_UNK D_800F9214;
extern M2C_UNK D_800F921C;
extern M2C_UNK D_800F9224;
extern M2C_UNK D_800F922C;
extern M2C_UNK D_800F9234;
extern M2C_UNK D_800F923C;
extern M2C_UNK D_800F9244;
extern M2C_UNK D_800F924C;
extern M2C_UNK D_800F9254;
extern M2C_UNK D_800F925C;
extern M2C_UNK D_800F9264;
extern M2C_UNK D_800F926C;
extern M2C_UNK D_800F9274;
extern M2C_UNK D_800F927C;
extern M2C_UNK D_800F9284;
extern M2C_UNK D_800F928C;
extern M2C_UNK D_800F9294;
extern M2C_UNK D_800F929C;
extern M2C_UNK D_800F92A4;
extern M2C_UNK D_800F92AC;
extern M2C_UNK D_800F92B4;
extern M2C_UNK D_800F92BC;

#define SPAWN(x, y, p)                                                         \
    if (!(func_8002D2D4() & 1)) {                                              \
        func_80027BA0(0, (x), (y), &(p));                                      \
    }

void func_800EE880(void* arg0) {
    M2C_FIELD(arg0, u16*, 0x80) += 1;
    M2C_FIELD(arg0, u16*, 0x82) += 1;
    M2C_FIELD(arg0, u16*, 0x84) -= 1;
    if (!(D_80097420 & 1)) {
        D_800970AA = M2C_FIELD(arg0, u16*, 0x82);
    } else {
        D_800970AA = M2C_FIELD(arg0, u16*, 0x84);
    }
    if (M2C_FIELD(arg0, s16*, 0x80) >= 0x1D) {
        if (M2C_FIELD(arg0, s8*, 2) == 1) {
            if (D_800CCED0.character_state.bytes[0xB] == 0) {
                D_800CCED0.character_state.bytes[0xA] =
                    (u32)func_8002D2D4() % 12;
                D_800CCED0.character_state.bytes[0xB] = 1;
            }
        } else if (M2C_FIELD(arg0, s8*, 2) == 3) {
            if (D_800CCED0.character_state.bytes[0xB] == 1) {
                D_800CCED0.character_state.bytes[0xA] =
                    (u32)func_8002D2D4() % 12;
                D_800CCED0.character_state.bytes[0xB] = 2;
            }
        }
        func_800139F4(8);
        M2C_FIELD(arg0, u8*, 7) += 1;
        switch (D_800F91B4[D_800CCED0.character_state.bytes[0xA]]
                          [M2C_FIELD(arg0, s8*, 2) - 1]) {
        case 0:
            SPAWN(0x200, 0x6B0, D_800F925C);
            SPAWN(0x280, 0x670, D_800F925C);
            SPAWN(0x440, 0x6B0, D_800F925C);
            SPAWN(0x480, 0x690, D_800F925C);
            SPAWN(0x360, 0x600, D_800F9264);
            SPAWN(0x400, 0x630, D_800F926C);
            SPAWN(0x540, 0x640, D_800F9274);
            break;
        case 1:
            SPAWN(0x140, 0x9E0, D_800F925C);
            SPAWN(0x260, 0x9E0, D_800F925C);
            SPAWN(0xC0, 0x9A0, D_800F926C);
            SPAWN(0x300, 0x9A0, D_800F926C);
            SPAWN(0x520, 0x9E0, D_800F926C);
            SPAWN(0x380, 0x970, D_800F9274);
            SPAWN(0x220, 0x9B0, D_800F927C);
            SPAWN(0x520, 0x950, D_800F927C);
            SPAWN(0x5C0, 0x9B0, D_800F927C);
            SPAWN(0x660, 0x950, D_800F927C);
            break;
        case 2:
            SPAWN(0x6E0, 0x30, D_800F9214);
            SPAWN(0x760, 0xF0, D_800F9214);
            SPAWN(0x680, 0x110, D_800F9214);
            SPAWN(0x6A0, 0x1D0, D_800F9214);
            SPAWN(0x760, 0x1F0, D_800F9214);
            SPAWN(0x680, 0x250, D_800F9214);
            break;
        case 3:
            SPAWN(0x9C0, 0x1D0, D_800F9214);
            SPAWN(0x8E0, 0x250, D_800F9214);
            SPAWN(0x920, 0x140, D_800F921C);
            break;
        case 4:
            SPAWN(0x200, 0xB80, D_800F9284);
            SPAWN(0x2C0, 0xBB0, D_800F928C);
            SPAWN(0x420, 0xC60, D_800F928C);
            SPAWN(0x380, 0xC10, D_800F9294);
            SPAWN(0x290, 0xC20, D_800F929C);
            SPAWN(0x410, 0xCD0, D_800F92A4);
            break;
        case 5:
            SPAWN(0xB60, 0xB80, D_800F9284);
            SPAWN(0xD10, 0xAD0, D_800F9284);
            SPAWN(0x8C0, 0xCB0, D_800F92AC);
            SPAWN(0x960, 0xC50, D_800F92B4);
            SPAWN(0x9C0, 0xC20, D_800F92B4);
            SPAWN(0xA60, 0xBD0, D_800F92B4);
            SPAWN(0xC00, 0xB00, D_800F92B4);
            SPAWN(0xDC0, 0xA40, D_800F92BC);
            break;
        case 6:
            SPAWN(0xBE0, 0x90, D_800F9224);
            SPAWN(0xD00, 0x90, D_800F9224);
            SPAWN(0xBE0, 0x1B0, D_800F9224);
            SPAWN(0xD00, 0x1B0, D_800F9224);
            SPAWN(0xB60, 0xC0, D_800F922C);
            SPAWN(0xD60, 0xC0, D_800F922C);
            SPAWN(0xC00, 0x140, D_800F922C);
            SPAWN(0xD60, 0x140, D_800F922C);
            SPAWN(0xC20, 0x220, D_800F922C);
            SPAWN(0xCA0, 0x220, D_800F922C);
            SPAWN(0xC60, 0x110, D_800F9234);
            break;
        case 7:
            SPAWN(0xC60, 0x420, D_800F923C);
            SPAWN(0xDA0, 0x420, D_800F923C);
            SPAWN(0xCA0, 0x600, D_800F923C);
            SPAWN(0xD00, 0x460, D_800F9244);
            SPAWN(0xDE0, 0x440, D_800F9244);
            SPAWN(0xDE0, 0x5D0, D_800F924C);
            SPAWN(0xD00, 0x3D0, D_800F9254);
            break;
        }
        D_80097244 = 1;
    }
}
