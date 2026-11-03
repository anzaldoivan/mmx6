#include "common.h"

extern s32 g_class4_slots[];

void func_80042D98(s8* arg0) {
    s8* p;
    s32 dx;
    s32 dy;
    s32 d;
    s32 best;

    *(s8**)(arg0 + 0x80) = 0;
    best = 1000000;
    for (p = (s8*)g_class4_slots; p < (s8*)g_class4_slots + 0x3340; p += 0xA4) {
        if (p[0] != 0 && p[1] == 4 && p[3] != 0 && p[7] == 1) {
            dx = *(s16*)(arg0 + 0xA) - *(s16*)(p + 0xA);
            dy = *(s16*)(arg0 + 0xE) - *(s16*)(p + 0xE);
            d = dx * dx + dy * dy;
            if (d < best) {
                best = d;
                *(s8**)(arg0 + 0x80) = p;
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80042E68(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 0) != 0) {
        var_v0 = 0;
        if (M2C_FIELD(arg0, s8*, 1) != 4) {
            return var_v0;
        }
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            var_v0 = 1;
            if (M2C_FIELD(arg0, s8*, 7) == 1) {
                return var_v0;
            }
        }
    }
    return 0;
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* alloc_class6_slot(void);

void func_80042EB4(void* arg0, u8 arg1, s32 arg2) {
    struct X4_QuadObj* q;

    q = alloc_class6_slot();
    if (q != 0) {
        M2C_FIELD(q, u8*, 0) = 1;
        M2C_FIELD(q, u8*, 1) = 0xD;
        M2C_FIELD(q, u8*, 2) = arg1;
        M2C_FIELD(q, void**, 0x5C) = arg0;
        M2C_FIELD(q, s16*, 0x46) = arg2;
        M2C_FIELD(q, u8*, 7) = M2C_FIELD(arg0, u8*, 6);
    }
}

/* func_80042F20: table lookup by stage/substage. TU 32208. Our own C. */
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_EngineObj g_playthrough_state;

u8 func_80042F20(void) {
    return D_80075FE8[g_playthrough_state.substage +
                      g_playthrough_state.stage * 2];
}

#include "common.h"
#include "mmx6/globals.h"

u8 func_80042F50(s8 stage, s8 substage) {
    return D_80075FE8[substage + stage * 2];
}

#include "common.h"

void func_80042F7C(s8 arg0, s8* arg1, s8* arg2) {
    s32 temp_a0;

    temp_a0 = arg0 - 1;
    *arg1 = (temp_a0 / 2) + 0x13;
    *arg2 = temp_a0 & 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                                           /* extern */
s32 is_off_screen(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2); /* extern */
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);    /* extern */
M2C_UNK move_object(void*);                                         /* extern */
M2C_UNK func_80030ECC(void*);                                       /* extern */

void func_80042FA8(void* arg0) {
    ((M2C_UNK(*)())animate_object)();
    move_object(arg0);
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80043018(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */

void func_80043038(void* arg0) {
    s32 temp_v1;

    M2C_FIELD(arg0, s8*, 3) = 0;
    temp_v1 = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    M2C_FIELD(arg0, s8*, 0x16) = 3;
    switch (temp_v1) { /* irregular */
    case 0:
        set_animation(arg0, 0);
        M2C_FIELD(arg0, s8*, 5) = 0;
        break;
    case 16:
        M2C_FIELD(arg0, s8*, 0x16) = 1;
        set_animation(arg0, 3);
        M2C_FIELD(arg0, s8*, 5) = 1;
        break;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s8*, 4) = 1;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();                                        /* extern */
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2); /* extern */
extern void (*D_800760E0[])(void*);

void func_800430D0(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s8*, 4) != 1) {
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    func_8002CCB0(arg0, 0x10, 0x10);
    D_800760E0[M2C_FIELD(arg0, s8*, 5)](arg0);
    ((void (*)())animate_object)(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_80043154(void) {
    clear_object_slot();
}

#include "common.h"

#include "mmx6/state.h"
extern void (*D_800760E8[])(void*);

void func_80043174(u8* arg0) {
    arg0[3] = (*(u8*)&D_80097420 + arg0[2]) & 1;
    D_800760E8[((s8*)arg0)[6]](arg0);
}

#include "common.h"

#define SCRATCH_OBJ (*(u8**)0x1F800064)

void func_800431C8(u8* arg0) {
    *(u16*)(SCRATCH_OBJ + 0x54) = *(u16*)(arg0 + 0xA);
    if (!(arg0[2] & 0xF)) {
        *(s32*)(arg0 + 0x20) = 0x40000;
        *(u16*)(arg0 + 0xA) -= 0x20;
    } else {
        *(s32*)(arg0 + 0x20) = -0x40000;
        *(u16*)(arg0 + 0xA) += 0x20;
    }
    arg0[6]++;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object(void*);

#define SP64_322C (*(u8**)0x1F800064)

void func_8004322C(u8* arg0) {
    ((void (*)(void*))move_object)(arg0);
    if (!(arg0[2] & 0xF)) {
        u8* temp_v0 = SP64_322C;
        if (*(s16*)(arg0 + 0xA) >= *(s16*)(temp_v0 + 0x54)) {
            *(s16*)(arg0 + 0xA) = *(s16*)(temp_v0 + 0x54);
            arg0[6]++;
        }
    } else {
        // !FAKE: retail keeps this arm's pointer in the first argument register
        register u8* temp_a0 asm("$4") = SP64_322C;
        if (*(s16*)(temp_a0 + 0x54) >= *(s16*)(arg0 + 0xA)) {
            *(s16*)(arg0 + 0xA) = *(s16*)(temp_a0 + 0x54);
            arg0[6]++;
        }
    }
}

#undef SP64_322C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800432C8(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(temp_a1, u8*, 7) = (u8)(M2C_FIELD(temp_a1, u8*, 7) - 1);
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800432F4(void* arg0) {
    void* temp_a1;

    temp_a1 = M2C_FIELD(arg0, void**, 0x50);
    if (M2C_FIELD(temp_a1, s8*, 7) != 0) {
        M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a1, u16*, 0xE);
        M2C_FIELD(arg0, u8*, 3) = (u8)M2C_FIELD(temp_a1, u8*, 3);
        M2C_FIELD(arg0, u16*, 0x42) = (u16)M2C_FIELD(temp_a1, u16*, 0x42);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0U;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();

void func_80043350(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x36) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    M2C_FIELD(arg0, u8*, 0x2) = random_byte() & 1;
    M2C_FIELD(arg0, u8*, 0x0) = 3;
    M2C_FIELD(arg0, s16*, 0x34) = (random_byte() & 1) + 0x1A;
    M2C_FIELD(arg0, s8*, 0x37) = -1;
    M2C_FIELD(arg0, s16*, 0xA) = 0;
    M2C_FIELD(arg0, s16*, 0xE) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, s16*, 0x48) =
        M2C_FIELD(arg0, s16*, 0x46) - ((random_byte() % 60) + 0x78) * 0xB;
    M2C_FIELD(arg0, s16*, 0x4A) = ((random_byte() & 3) + 3) * 0xB;
    M2C_FIELD(arg0, s16*, 0x4E) = random_byte() % 3;
}

#define func_80041AB8 func_80043460
#define D_80075FD8 D_80076100
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_8004349C(void) {
    clear_object_slot();
}

#include "common.h"

s16 func_800434BC(s16 arg0, s16 arg1) {
    s32 t = arg1;
    s32 h = arg0 >> 1;
    t += 1;
    return h + t;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK react_to_weapon_change(void*);
void player_reset_charge();
extern struct X4_PlayerObj g_Player;
extern void (*D_80076118[])(void*);

#define B(o) (*(s8*)((u8*)p + (o)))
#define UB(o) (*(u8*)((u8*)p + (o)))
#define UH(o) (*(u16*)((u8*)p + (o)))
#define SB(o) (*(s8*)((u8*)self + (o)))

void func_800434E0(void* self) {
    struct X4_PlayerObj* p = &g_Player;
    s32 f;

    f = B(0xD3) != 0;
    if (B(0xD4) != 0) {
        f = 1;
    }
    if (B(0x2) == 1 && B(0xA6) != B(0x2)) {
        f = 1;
    }
    if (UB(0x2) == 0 && B(0x93) != 1) {
        f = 1;
    }
    if (B(0xD5) != 0) {
        f = 1;
    }
    if (B(0x5C) == 0) {
        f = 1;
    }
    if (f == 0) {
        if (SB(0x2) == 0 && UB(0x2) == 0 && SB(0x8C) == 3) {
            s32 a = UH(0x7C) & 0x600;
            s32 m = UH(0x80) & 0x600;
            if (a == 0x600 || m == 0x600) {
                UB(0x93) = 0;
                player_reset_charge(p);
                play_sound(0, 0xC, 0);
                react_to_weapon_change(p);
                f = 1;
            }
        }
    }
    if (f != 0) {
        SB(0x4) = 2;
    }
    D_80076118[SB(0x4)](self);
}
