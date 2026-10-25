#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

u8 func_80030234(struct X4_PlayerObj*, s16, s16);
extern struct X4_PlayerObj g_Player;
extern void (*D_800F6C28[])(void*);

#define PL_104 M2C_FIELD(&g_Player, s32*, 0x104)
#define PL_13C M2C_FIELD(&g_Player, s32*, 0x13C)

#define LOWER(v, lo) ((v) > (lo) ? (v) : (lo))
#define UPPER(v, hi) ((v) < (hi) ? (v) : (hi))
#define ABS(v) ((v) < 0 ? -(v) : (v))

#define TILE(dy)                                                               \
    ({                                                                         \
        struct X4_PlayerObj* p_ = &g_Player;                                   \
        struct X4_Unk_unk68* u_ = p_->unk68;                                   \
        s16 y_ = u_->unk1 + (p_->y_pos.u.hi + u_->unk3) + (dy);                \
        s16 x_ = p_->x_pos.i.hi;                                               \
        u8 t_;                                                                 \
        if (u_ == NULL) {                                                      \
            t_ = 0;                                                            \
        } else {                                                               \
            t_ = func_80030234(p_, x_, y_);                                    \
        }                                                                      \
        t_;                                                                    \
    })

void func_800ED3A4(void* self) {
    s32 dx;
    s32 d;

    M2C_FIELD(self, u8*, 0x21) = M2C_FIELD(self, u8*, 0x20);
    M2C_FIELD(self, u8*, 0x20) = TILE(0);
    dx = g_Player.x_pos.val - PL_13C;
    if (g_Player.state == 1) {
    loop:
        switch (M2C_FIELD(self, u8*, 0x20)) {
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
            M2C_FIELD(self, s8*, 4) = 1;
            if (M2C_FIELD(self, u8*, 0x21) == 0x3C && g_Player.unk15 != 0 &&
                g_Player.unk5 != 0xC) {
                g_Player.x_pos.val = PL_13C;
            } else {
                g_Player.x_pos.val = PL_13C + LOWER(dx - 0x38000, -PL_104);
                g_Player.y_pos.val += ABS(LOWER(dx - 0x38000, -PL_104));
            }
            break;
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
            M2C_FIELD(self, s8*, 4) = 1;
            if (M2C_FIELD(self, u8*, 0x21) == 0x3C && g_Player.unk15 == 0 &&
                g_Player.unk5 != 0xC) {
                g_Player.x_pos.val = PL_13C;
            } else {
                d = dx + 0x38000;
                g_Player.x_pos.val = PL_13C + UPPER(d, PL_104);
                g_Player.y_pos.val += ABS(UPPER(d, PL_104));
            }
            break;
        case 0x19:
        case 0x1A:
            M2C_FIELD(self, s8*, 4) = 1;
            if (M2C_FIELD(self, u8*, 0x21) == 0x3C && g_Player.unk15 != 0 &&
                g_Player.unk5 != 0xC) {
                g_Player.x_pos.val = PL_13C;
            } else {
                g_Player.x_pos.val = PL_13C + LOWER(dx - 0x38000, -PL_104);
                g_Player.y_pos.val += ABS(LOWER(dx - 0x38000, -PL_104));
            }
            break;
        case 0x1B:
        case 0x1C:
            M2C_FIELD(self, s8*, 4) = 1;
            if (M2C_FIELD(self, u8*, 0x21) == 0x3C && g_Player.unk15 == 0 &&
                g_Player.unk5 != 0xC) {
                g_Player.x_pos.val = PL_13C;
            } else {
                d = dx + 0x38000;
                g_Player.x_pos.val = PL_13C + UPPER(d, PL_104);
                g_Player.y_pos.val += ABS(UPPER(d, PL_104));
            }
            break;
        case 0x10:
            M2C_FIELD(self, u8*, 0x20) = TILE(-0x10);
            goto loop;
        case 0:
            if (g_Player.unk88.bytes.collision_flags & 8) {
                goto call;
            }
            if (M2C_FIELD(self, s8*, 4) == 2) {
                D_800F6C28[M2C_FIELD(self, s8*, 4)](self);
            }
            M2C_FIELD(self, u8*, 0x1C) = g_Player.unk5;
            goto end;
        case 0x3C:
            goto call;
        default:
            M2C_FIELD(self, s8*, 4) = 1;
            M2C_FIELD(self, u8*, 0x1C) = g_Player.unk5;
            goto end;
        }
        M2C_FIELD(self, u8*, 0x20) = TILE(0);
        switch (M2C_FIELD(self, u8*, 0x20)) {
        case 0:
            if (M2C_FIELD(self, s8*, 4) != 2) {
                D_800F6C28[M2C_FIELD(self, s8*, 4)](self);
            }
            M2C_FIELD(self, u8*, 0x1C) = g_Player.unk5;
            break;
        default:
        call:
            D_800F6C28[M2C_FIELD(self, s8*, 4)](self);
            M2C_FIELD(self, u8*, 0x1C) = g_Player.unk5;
            break;
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x38:
            break;
        }
    }
end:
    if (g_Player.x_pos.val != PL_13C) {
        M2C_FIELD(self, u8*, 0x1E) = (g_Player.x_pos.val >= PL_13C) << 6;
    }
}
