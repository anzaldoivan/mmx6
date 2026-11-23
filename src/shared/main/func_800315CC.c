#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_8009716D;

void func_800319EC(HitSelf* arg0, s32 arg1);

s32 func_800315CC(void* arg0, void* arg1) {
    u8* self = arg0;
    u8* p = arg1;
    s8 id = *(s8*)(p + 1);
    u8* tbl;
    u8* e;
    s8 dmg;
    s32 hp;
    s32 t;

    if (*(s8*)(p + 0x64) != 0) {
        if (*(s8*)(p + 0x64) == *(s8*)(self + 0x65)) {
            return 0x7E;
        }
        self[0x65] = p[0x64];
    } else {
        self[0x65] = 0;
    }
    tbl = *(u8**)(self + 0x58);
    if ((*(s8*)(self + 0x63) = tbl[id * 2]) == 2) {
        return 0;
    }
    switch (id) {
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 35:
    case 46:
    case 51:
    case 57:
    case 61:
    case 62:
        if (*(s8*)(self + 0x63) != 7) {
            D_8009716D = 1;
        }
        break;
    }
    if (*(s8*)(self + 0x63) == 8) {
        p[0x98] = 1;
        return 0x7F;
    }
    if (*(s8*)(self + 0x63) == -1) {
        func_800319EC(p, -1);
        return 0x7F;
    }
    if (*(s8*)(self + 0x63) == 7) {
        p[0x70] |= 0xF;
        return 0x7F;
    }
    dmg = *(s8*)(tbl + id * 2 + 1);
    if (dmg != 0 && dmg != 0x7F) {
        u8* pl = (u8*)&g_Player;
        if (*(s32*)(pl + 0x144) == 2) {
            dmg = (s8)(dmg + 1);
        }
        if (id == 0x20) {
            s32 sum = dmg + p[6];
            dmg = sum;
        }
        if (*(s32*)(pl + 0xEC) & 0x80) {
            switch (id) {
            case 0:
            case 9:
            case 18:
            case 19:
            case 20:
            case 45:
            case 46:
            case 58:
                dmg = (s8)(dmg + 1);
                break;
            }
        } else if ((*(s32*)(pl + 0xEC) & 0x400000) ||
                   (*(s8*)(pl + 2) != 0 &&
                    (e = (u8*)&g_playthrough_state, e[0x5F] & 0x20))) {
            if (id >= 0x18) {
                if (id < 0x20) {
                    dmg = (s8)(dmg + 1);
                } else if (id < 0x2A) {
                    if (id >= 0x25) {
                        dmg = (s8)(dmg + 1);
                    }
                }
            }
        }
        {
            u8* pl = (u8*)&g_Player;
            if (*(s32*)(pl + 0xEC) & 0x2000000) {
                switch (id) {
                case 1:
                case 4:
                case 33:
                case 34:
                case 35:
                case 36:
                case 42:
                case 44:
                case 52:
                case 53:
                case 54:
                    dmg = (s8)(dmg + 1);
                    break;
                }
            }
        }
        {
            u8* pl = (u8*)&g_Player;
            if (*(s32*)(pl + 0xEC) & 0x200000) {
                switch (id) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 52:
                case 53:
                case 54:
                    dmg = (s8)(dmg + 1);
                    break;
                }
            }
        }
        {
            u8* e = (u8*)&g_playthrough_state;
            if (e[0x68] == 0) {
                s16 h = dmg;
                h += (s8)(dmg / 4);
                if (h >= 0x80) {
                    h = 0x7F;
                }
                dmg = h;
            }
        }
    }
    e = (u8*)&g_playthrough_state;
    if (*(s16*)(e + 0x9C) < dmg) {
        *(s16*)(e + 0x9C) = dmg;
    }
    hp = self[0x5C] - dmg;
    self[0x5C] = hp;
    if (*(s8*)(self + 1) == 0x3B) {
        func_800319EC(p, -1);
        return 0x7F;
    }
    *(u16*)(self + 0x42) |= 0x8000;
    if ((s8)hp <= 0) {
        self[0x5C] = 0;
        if (*(s8*)(self + 0x63) == 9) {
            p[0x70] |= 0xF;
            func_800319EC(p, 2);
        } else {
            func_800319EC(p, 1);
        }
        return ~id;
    }
    if (*(s8*)(self + 1) != 0x20) {
        if (id == 0x2B && (s8)hp >= 0x10) {
            p[7] = 1;
        }
        if (*(s8*)(self + 0x63) == 9) {
            p[0x70] |= 0xF;
            func_800319EC(p, 2);
        } else {
            func_800319EC(p, 0);
        }
    }
    return (s8)(id + 1);
}
