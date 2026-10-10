#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK);
void func_8005FD74(s32);
int func_80060964(int mode);
s32 func_80064804(s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
s32 func_80064B44(M2C_UNK, M2C_UNK, u8*);
extern u16 D_8007A0E0[];
extern u8 D_8008EC08;
extern s8 D_80090D50[6];
extern u8 D_8009509C;
extern s32 D_80097760;
extern s32 D_8009776C;
extern s32 D_800B91B8;
extern u8 D_800CC868;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEDC;
extern u8 D_800CD40C;
extern u32 D_800E4488;
extern s32 D_800E448C;
extern s32 D_800E4490;

#define ENG_43B (*(u8*)((u8*)&D_800CCED0 + 0x43B))

void func_800528F4(struct X4_BaseObj* self) {
    u8 sp10;
    s8 state;

    sp10 = 0xA0;
    state = self->unk5;
    switch (state) {
    case 0:
        if (D_800CD40C == 0) {
            register u16* p asm("$3") = D_8007A0E0;
            p += D_800CCED0.stage;

            if (*p == 0) {
                goto set3;
            }
            if (D_800CCED0.stage >= 0x13) {
                if (ENG_43B == 0) {
                    *p = 0x8A;
                } else if (ENG_43B == 1) {
                    *p = 0x8B;
                } else {
                    *p = 0x8C;
                }
            } else if (D_800CCED0.stage == 0) {
                if (D_800CCED0.character_state.bytes[0] != 0) {
                    D_800CC868 = 0;
                    D_8007A0E0[0] = 0x7C;
                } else {
                    D_8007A0E0[0] = 0x7B;
                }
            }
            {
                struct X4_EngineObj* e = &D_800CCED0;

                if (e->stage == 0xC && e->substage != 0) {
                    s8 cur = e->character_state.bytes[0xB];

                    if (cur == e->character_state.bytes[0xC] &&
                        D_800CC868 != 0) {
                    set3:
                        self->unk5 = 3;
                        return;
                    }
                    if (cur == 1) {
                        D_8007A0E0[e->stage] = 0x85;
                    } else {
                        D_8007A0E0[e->stage] = 0x86;
                    }
                    D_800CC868 = 0;
                    D_800CCED0.character_state.bytes[0xC] =
                        D_800CCED0.character_state.bytes[0xB];
                }
            }
            if (D_800CC868 == 0) {
                self->unk5++;
            } else {
                self->unk5 = 3;
            }
        }
        if (self->unk5 == 1) {
            if (D_80090D50[5] != -1) {
                func_8005FD74(D_80090D50[5]);
                D_80090D50[5] = -1;
                D_800E4490 = D_8009776C;
            } else {
                D_800E4490 = D_80097760;
            }
        }
        break;
    case 1:
        D_800E448C = D_800B91B8;
        func_80014F70(D_8007A0E0[D_800CCEDC], 4, D_800E4490);
        D_800E4488 = 0;
        self->unk5++;
        break;
    case 2:
        if (D_8009509C == state && D_8008EC08 == 0) {
            D_800CC868 = 1;
            self->unk5++;
            if (D_800CCED0.stage == 0xC && D_800CCED0.substage != 0) {
                D_800B91B8 = D_800E448C;
            }
        } else if (D_8009509C & 0xC0) {
            func_80014F70(D_8007A0E0[D_800CCEDC], 4, D_800E4490);
            D_800E4488 = 0;
        } else if (++D_800E4488 >= 0x259) {
            func_800648B4(0);
            while (func_80064804(0) == 0) {
            }
            while (func_80064B44(0xE, (s32)&sp10, 0) == 0) {
            }
            func_80060964(3);
            D_8009509C = 0xC0;
        }
        break;
    case 3:
        self->state++;
        break;
    }
}
