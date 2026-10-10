#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);

extern struct X4_PlayerObj D_800970A0;
extern u16 D_800C4570;
extern struct X4_EngineObj D_800CCED0;

void func_80034288(struct X4_PlayerObj* self) {
    s8 old;
    s8 i;
    u16 n;
    s32 j;
    s32 found;

    old = self->bg_offset;
    switch (D_800C4570) {
    case 0x800:
        self->state = 2;
        self->unk5 = 0;
        break;
    case 0x40: {
        s8* e = (s8*)&D_800CCED0;
        if (e[0x464] != 0) {
            return;
        }
        switch (((u8*)self)[0x2D]) {
        case 4: {
            struct X4_PlayerObj* pl = &D_800970A0;
            if ((pl->hp & 0x7F) < ((s8*)&D_800CCED0 + pl->unk2)[0x5B]) {
                self->unk5 = 9;
            }
            break;
        }
        case 5: {
            j = 0;
            found = 0;
            for (; j < 9; j++) {
                u8* pl = (u8*)&D_800970A0;
                if (*(s16*)((u8*)&D_800970A0 + j * 2 + 0xA8) <
                    *(s16*)(pl + 0x14A)) {
                    found = 1;
                    break;
                }
            }
            if (found != 0) {
                self->unk5 = 0xA;
            }
            break;
        }
        default: {
            {
                s8* e2 = (s8*)&D_800CCED0;
                e2[0x464] = 1;
            }
            func_80016C48(0, 0x22, 0);
            if (((u8*)self)[0x2D] == 6) {
                u8* pl = (u8*)&D_800970A0;
                *(s16*)(pl + 0x148) = 0x1E0;
            } else {
                u8* pl = (u8*)&D_800970A0;
                *(s16*)(pl + 0x148) = 0x12C;
            }
            {
                u8* pl = (u8*)&D_800970A0;
                *(s32*)(pl + 0x144) = ((u8*)self)[0x2D];
            }
            break;
        }
        }
        break;
    }
    case 0x1000:
        for (i = 9; i >= 0; i--) {
            u8* p = &self->unk16;
            if (p[i] != 0) {
                break;
            }
        }
        self->bg_offset = i;
        self->unk5 = 0;
        break;
    case 0x4000:
        i = 13;
        for (n = 0; n < 4; n++, i++) {
            if (*((u8*)self + i + 0x16) != 0) {
                self->unk5 = 2;
                break;
            }
        }
        self->bg_offset = i;
        break;
    case 0x2000:
        do {
            i = 10;
            for (n = 0; n < 3; n++, i++) {
                u8* p = &self->unk16;
                if (p[i] != 0) {
                    self->unk5 = 1;
                    break;
                }
            }
            if (n == 3) {
                i = self->bg_offset;
                break;
            }
            if (self->bg_offset == i) {
                break;
            }
            {
                u8* q = &self->unk16;
                if (q[i] != 0) {
                    break;
                }
            }
        } while (1);
        self->bg_offset = i;
        break;
    }
    if (self->bg_offset != old) {
        func_80016C48(0, 0xC, 0);
    }
}
