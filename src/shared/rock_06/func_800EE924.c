#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002DCF4(void*, void*);

extern M2C_UNK D_800970A0;
#define PLAYER (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_EngineObj D_800CCED0;
extern struct X4_RideArmorObj D_800CD340;
extern s32 D_800F3A44;
extern s32 D_800F3A48;

void func_800EE924(struct X4_BaseObj* self) {
    struct X4_PlayerObj* pl;
    struct X4_EngineObj* en;
    register void* saved asm("$19");
    s8 v;

    if (M2C_FIELD(self, s8*, 0x6) == 0) {
        M2C_FIELD(self, s8*, 0x6) = 1;
        M2C_FIELD(self, void**, 0x68) = &D_800F3A44;
        M2C_FIELD(self, u8*, 0x8C) = 0;
        func_800179A4(self, 0x11);
        return;
    }
    if (!(M2C_FIELD(self, u8*, 0xA8) & 8)) {
        M2C_FIELD(self, u8*, 0x5) = 0xC;
        M2C_FIELD(self, u8*, 0x6) = 0;
        return;
    }
    pl = &PLAYER;
    if (M2C_FIELD(pl, s8*, 0xD0) != 0) {
        return;
    }
    en = &D_800CCED0;
    if (M2C_FIELD(en, s8*, 0xF) == 0 &&
        (M2C_FIELD(pl, s8*, 0x2) == 0 || M2C_FIELD(pl, s8*, 0x8E) == 0) &&
        M2C_FIELD(pl, s8*, 0x7A) == 0 && M2C_FIELD(pl, s8*, 0xE0) == 0 &&
        !(M2C_FIELD(self, u16*, 0x96) & 0x8200)) {
        saved = M2C_FIELD(self, void**, 0x68);
        M2C_FIELD(self, void**, 0x68) = &D_800F3A48;
        if (func_8002DCF4(pl, self) != 0 && M2C_FIELD(en, s8*, 0xF) == 0 &&
            M2C_FIELD(pl, s8*, 0x5C) > 0 && M2C_FIELD(pl, s8*, 0xA4) == 0 &&
            M2C_FIELD(pl, s8*, 0x79) == 0) {
            M2C_FIELD(self, u8*, 0x5) = 0xA;
            M2C_FIELD(self, u8*, 0x6) = 0;
            func_800179A4(self, 0x12);
            {
                struct X4_BaseObj* r;
                do {
                    r = (struct X4_BaseObj*)&D_800CD340;
                    M2C_FIELD(self, u8*, 0x97) |= 0x40;
                } while (0);
                v = 2;
                if (self == r) {
                    v = 1;
                }
            }
            M2C_FIELD(pl, s8*, 0xD5) = v;
        }
        M2C_FIELD(self, void**, 0x68) = saved;
    }
}
