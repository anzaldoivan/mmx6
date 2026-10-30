#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800757DC;
extern s32 D_8007587C;
extern struct X4_PlayerObj g_Player;
extern void (*D_800FCF68[])(void*);

#define F(type, off) M2C_FIELD(self, type*, off)
#define O(type, off) M2C_FIELD(other, type*, off)
#define PL(type, off) M2C_FIELD(&g_Player, type*, off)

void func_800F5F50(void* self) {
    void* other;
    s32 r;

    struct X4_PlayerObj* pl = &g_Player;

    if (M2C_FIELD(pl, s8*, 0xE0) == 0) {
        D_800FCF68[F(s8, 5)](self);
    } else if (F(s8, 2) != 0) {
        func_80017A04(self);
    }
    func_80030ECC(self);
    r = check_enemy_hits(self);
    if (F(s8, 2) == 0) {
        if (F(u8, 0x8D) == 7) {
            struct X4_PlayerObj* pl = &g_Player;
            M2C_FIELD(pl, u8*, 0x7A) = 1;
            F(u8, 4) = 2;
            goto end;
        }
        if (F(s8, 5) != 2) {
            F(u8, 0x5C) = 0;
        }
        F(u8, 3) = 0;
        return;
    }
    if ((u8)(F(u8, 2) - 3) < 2) {
        other = F(void*, 0x88);
        if (O(s8, 5) != 2) {
            O(u8, 0x5C) = O(u8, 0x5C) + F(u8, 0x5C);
            if (O(s8, 0x5C) == -0x80) {
                O(u8, 0x5C) = 0x7F;
            }
        }
        if (r < 0) {
            O(u8, 0x8D) = O(u8, 0x8D) + F(u8, 2);
            ((void (*)(void*))func_80049E50)(self);
            F(u8, 4) = 3;
        end:
            F(u8, 5) = 0;
            F(u8, 6) = 0;
            return;
        }
        if (F(u8, 0x8C) == 0) {
            if (r != 0 && r != 0x7F) {
                F(void*, 0x58) = &D_8007433C;
                F(u8, 0x8C) = 0x1E;
                F(u16, 0x42) = F(u16, 0x42) | 0x8000;
            }
        } else {
            if (--F(u8, 0x8C) == 0) {
                F(void*, 0x58) = &D_800757DC;
                F(u16, 0x42) = F(u16, 0x42) & 0x7FFF;
                return;
            }
            if (!(F(volatile u8, 0x8C) & 1)) {
                F(u16, 0x42) = F(u16, 0x42) | 0x8000;
            } else {
                F(u16, 0x42) = F(u16, 0x42) & 0x7FFF;
            }
        }
    } else {
        other = F(void*, 0x84);
        if (O(s8, 4) == 2) {
            F(s32, 0x8) = F(s32, 0x18);
            F(s32, 0xC) = F(s32, 0x1C);
            F(u16, 0x42) = O(u16, 0x42);
            F(u8, 3) = O(u8, 3);
            return;
        }
        if (F(s8, 5) == 6 && O(u8, 0x8E) == 0 && F(u8, 0x8C) == 0) {
            F(void*, 0x58) = &D_8007587C;
        } else {
            F(void*, 0x58) = &D_8007433C;
        }
        {
            // !FAKE: depin: dropping it breaks the match (187/193)
            register void* a asm("$4") = &D_8007433C;
            F(void*, 0x58) = a;
        }
        if (O(u8, 0x8D) == F(s8, 2) + 2) {
            F(u16, 0x42) = F(u16, 0x42) & 0x7FFF;
        }
        if (F(u8, 0x8C) != 0) {
            if (--F(u8, 0x8C) != 0 && !(F(volatile u8, 0x8C) & 1)) {
                F(u16, 0x42) = F(u16, 0x42) | 0x8000;
            } else {
                F(u16, 0x42) = F(u16, 0x42) & 0x7FFF;
            }
        }
    }
}
