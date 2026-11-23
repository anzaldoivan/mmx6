#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D654(s8*, u8*);
s32 scale_damage(u8* arg0, s8 arg1);
#define D_80093C98 ((u8*)g_projectiles)
/* as collision/solid_object.c:11, same TU 30234 */
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern u8 D_800C4568;
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_RideArmorObj D_800CD340;

#define ENG_98 M2C_FIELD(e, s32*, 0x98)
#define ENGP struct X4_EngineObj* e = &g_playthrough_state
#define ENGQ ((struct X4_EngineObj*)&g_playthrough_state)

s32 func_80030ECC(s8* arg0) {
    u8* p;
    struct X4_RideArmorObj* ra;
    s32 r;
    s32 t;
    s32 t2;

    if (D_800C4568 != 0) {
        return 0;
    }
    p = (u8*)&g_Player;
    if (M2C_FIELD(p, s8*, 0x7A) == 1 ||
        (M2C_FIELD(p, s8*, 0x7A) == 2 &&
         ((u32)arg0 < (u32)D_80093C98 ||
          (u32)arg0 >= (u32)(D_80093C98 + 0x1400)))) {
        return 0;
    }
    if (M2C_FIELD(p, s32*, 0x144) == 1 && (u32)arg0 >= (u32)D_80093C98 &&
        (u32)arg0 < (u32)(D_80093C98 + 0x1400)) {
        return 0;
    }
    if (M2C_FIELD(p, s8*, 0xD5) < 0) {
        ra = &D_800CD340;
        if (ra->hp & 0x80) {
            return 0;
        }
        if (ra->unk85 != 0) {
            return 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x60) < 0) {
            return 0;
        }
        if (func_8002D654(arg0, (u8*)ra) == 0) {
            return 0;
        }
        ra->unk63 = 0;
        ra->unk86 = 0;
        if (M2C_FIELD(arg0, s8*, 0x60) < 5) {
            ra->unk63 = 1;
        } else {
            ra->unk63 = 2;
        }
        t = (u8)ra->hp - M2C_FIELD(arg0, u8*, 0x60);
        {
            ENGP;
            ra->hp = t;
            ENG_98 += M2C_FIELD(arg0, s8*, 0x60);
            if ((t << 24) > 0) {
                ra->hp = t | 0x80;
            } else {
                e->gameplay_locked = 1;
                ra->hp = -0x80;
            }
        }
        if (ra->x_pos.i.hi >= M2C_FIELD(arg0, s16*, 0xA)) {
            ra->unk84 = 0;
        } else {
            ra->unk84 = 0x40;
        }
        return 1;
    }
    if (M2C_FIELD(p, s8*, 0x5C) & 0x80) {
        return 0;
    }
    if (M2C_FIELD(p, s8*, 0xA4) != 0) {
        return 0;
    }
    if (func_8002D654(arg0, p) == 0) {
        return 0;
    }
    if (M2C_FIELD(p, s8*, 0x7A) == 2) {
        M2C_FIELD(p, s8*, 0x7A) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x60) >= 0) {
        {
            u8 v = M2C_FIELD(arg0, u8*, 0x62);
            M2C_FIELD(p, s8*, 0xCA) = 0;
            M2C_FIELD(p, u8*, 0x63) = v;
        }
        switch (M2C_FIELD(arg0, s8*, 0x62)) {
        case 0:
            t2 = M2C_FIELD(p, u8*, 0xE7);
            if (t2 >= 1 && t2 <= 4) {
                M2C_FIELD(p, u8*, 0x63) = 4;
            } else if ((u8)t2 == 5 && (M2C_FIELD(p, s32*, 0xEC) & 0x200)) {
                M2C_FIELD(p, u8*, 0x63) = 4;
            } else if (M2C_FIELD(p, s8*, 2) != 0 && (ENGQ->unk5F & 0x20)) {
                M2C_FIELD(p, u8*, 0x63) = 4;
            } else if (M2C_FIELD(arg0, s8*, 0x60) < 5) {
                M2C_FIELD(p, u8*, 0x63) = 1;
            } else {
                M2C_FIELD(p, u8*, 0x63) = 2;
            }
            break;
        case 3:
            M2C_FIELD(p, s8*, 0xCA) = 1;
            break;
        case 5:
            M2C_FIELD(p, u8*, 0x63) = 5;
            break;
        }
    }
    r = scale_damage(p, M2C_FIELD(arg0, s8*, 0x60));
    if (r == 0x7F) {
        ENGP;
        ENG_98 += M2C_FIELD(p, s8*, 0x5C);
    } else {
        ENGP;
        ENG_98 += r;
    }
    t2 = M2C_FIELD(p, u8*, 0x5C) - r;
    M2C_FIELD(p, u8*, 0x5C) = t2;
    if ((t2 << 24) > 0) {
        M2C_FIELD(p, u8*, 0x5C) = t2 | 0x80;
    } else {
        ENGP;
        e->gameplay_locked = 1;
        M2C_FIELD(p, s8*, 0x5C) = -0x80;
    }
    if (M2C_FIELD(arg0, s8*, 0x62) != 3) {
        if (M2C_FIELD(arg0, s8*, 0x62) == 0) {
            if ((M2C_FIELD(p, s32*, 0xEC) & 0x200) ||
                (M2C_FIELD(p, s8*, 2) != 0 && (ENGQ->unk5F & 0x20))) {
                M2C_FIELD(p, u8*, 0xA5) = M2C_FIELD(p, u8*, 0x15);
            } else if (M2C_FIELD(p, s16*, 0xA) >= M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(p, u8*, 0xA5) = 0;
            } else {
                M2C_FIELD(p, u8*, 0xA5) = 0x40;
            }
        } else if (M2C_FIELD(p, s16*, 0xA) >= M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(p, u8*, 0xA5) = 0;
        } else {
            M2C_FIELD(p, u8*, 0xA5) = 0x40;
        }
    }
    return 1;
}

#undef ENGQ
#undef ENGP
#undef ENG_98
#undef M2C_FIELD
#undef D_80093C98
#undef g_Player
