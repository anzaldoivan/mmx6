#include "common.h"

void func_800F4A50(void) {
}

#define func_8003744C func_800F4A58
#define D_80073C1C D_800F7620
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/globals.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();               /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F4A94(void* arg0) {
    void* temp_v0;

    if (D_800970A5 == 0x14) {
        D_8009723F = 2;
        func_8003D308(0x1D, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x18;
            M2C_FIELD(temp_v0, u16*, 0xA) = (u16)M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = (u16)M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern struct X4_EngineObj g_playthrough_state;

void func_800F4B2C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        open_text_box(1, 0xFF, g_playthrough_state.character_state.bytes[9]);
        g_playthrough_state.character_state.bytes[9] = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK animate_object(void*);
void func_80027BA0(s32, s32, s32, void*);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern u8 D_800F7588;

void func_800F4BB0(u8* arg0) {
    s32 i;
    u8* obj;

    if (D_8008EAFC == 0) {
        func_80027BA0(0, 0xC80, 0x470, &D_800F7588);
        i = 0;
        do {
            obj = func_8002C458();
            if (obj != 0) {
                s32 b = arg0[0];

                obj[1] = 0x1A;
                obj[2] = i + 0xF;
                *(u8**)(obj + 0x7C) = arg0;
                obj[0] = b;
            }
            i++;
        } while (i < 6);
        *(s16*)(arg0 + 0x7C) = 2;
        arg0[6]++;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_8003D330();
s32 func_80040498();
extern s8 D_800CCF5C;

void func_800F4C74(s8* arg0) {
    if (func_80040498() == 0) {
        // !FAKE: counter read lands in v1 as retail
        register s32 cnt asm("$3") = arg0[0x5C];
        if (cnt < D_800CCF5C) {
            if (--*(s16*)(arg0 + 0x7C) == 0) {
                play_sound(0, 0xE, 0);
                *(u16*)(arg0 + 0x7C) = 3;
            }
            arg0[0x5C]++;
            animate_object(arg0);
            func_8002CCB0(arg0, 0x30, 0x40);
            return;
        } else {
            // !FAKE: places the limit arm after the shared tail as retail does
            goto limit;
        }
    }
    animate_object(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
    return;
limit:
    func_8003D330(D_800CCF5C);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
    *(u16*)(arg0 + 0x7C) = 0;
    arg0[5] = 4;
    arg0[6] = 0;
}

#include "../shared/rock_24/func_800F4D54.c"

#include "common.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4DB8(void* arg0) {
    s16 n;

    n = ++M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0x64) {
        M2C_FIELD(arg0, u8*, 5) = D_800F7528[M2C_FIELD(arg0, u8*, 0x87)++ +
                                             M2C_FIELD(arg0, u8*, 0x86) * 6];
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern void (*D_800F7648[])(struct X4_MainObj*);

void func_800F4E1C(struct X4_MainObj* self) {
    apply_object_motion(self);
    D_800F7648[self->action_phase](self);
    animate_object(self);
    func_8002CCB0(self, 0x30, 0x40);
}

#define func_800F4D54 func_800F4E7C
#define D_800F7640 D_800F7654
#include "../shared/rock_24/func_800F4D54.c"
#undef func_800F4D54
#undef D_800F7640

#define func_800F4D54 func_800F4EE0
#define D_800F7640 D_800F765C
#include "../shared/rock_24/func_800F4D54.c"
#undef func_800F4D54
#undef D_800F7640

#include "common.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();

void func_800F4F44(void* arg0) {
    void* child;
    s16 n;

    n = ++M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0x17) {
        child = func_8002C458();
        if (child != 0) {
            u8 k = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(child, u8*, 1) = 0x1A;
            M2C_FIELD(child, u8*, 2) = 0xE;
            M2C_FIELD(child, void**, 0x7C) = arg0;
            M2C_FIELD(child, u8*, 0) = k;
        }
    } else if (n == 0x5A) {
        M2C_FIELD(arg0, u8*, 5) = D_800F7528[M2C_FIELD(arg0, u8*, 0x87)++ +
                                             M2C_FIELD(arg0, u8*, 0x86) * 6];
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern void (*D_800F7664[])(void*);

void func_800F4FF4(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x84) < 0x50) {
        M2C_FIELD(arg0, u8*, 0x84) = 0x64;
    }
    D_800F7664[M2C_FIELD(arg0, s8*, 0x6)](arg0);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}

#include "common.h"
#include "mmx6/rock_24.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F5070(void* arg0) {
    s16 n;

    n = ++M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0x5A) {
        M2C_FIELD(arg0, u8*, 0x84) = 0x28;
        D_800F77DC = 0;
        M2C_FIELD(arg0, u8*, 5) = D_800F7528[M2C_FIELD(arg0, u8*, 0x87)++ +
                                             M2C_FIELD(arg0, u8*, 0x86) * 6];
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}

#define func_80041AB8 func_800F50E4
#define D_80075FD8 D_800F768C
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002B6B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_800CCEE0;

void func_800F5120(struct X4_MainObj* arg0) {
    // !FAKE: keeps 0x19 in the call's argument register for the stores
    register s32 k asm("$4");

    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x30, 0x40);
    if (g_Player.hp != 0 && g_Player.nova_strike_active == 0) {
        g_Player.spike_immune = 1;
        g_Player.terrain_box = 0;
        ((M2C_UNK(*)())play_sound)(2, 0x20, arg0, &g_Player);
        k = 0x19;
        arg0->unk7C = 0x7F;
        arg0->unk7E = k;
        arg0->invincibility_timer = k;
        arg0->unk42 &= 0x7FFF;
        arg0->action++;
        D_800CCEE0 = 1;
        func_8002B6B0(k);
    }
}

#undef g_Player

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();                      /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */

void func_800F51CC(void* arg0) {
    void* temp_v0;
    s16 v;
    s32 t;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        temp_v0 = alloc_class3_slot();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x1A;
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(arg0, void**, 0x80) = temp_v0;
        }
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    if ((s16)--M2C_FIELD(arg0, u16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        M2C_FIELD(arg0, u8*, 0x61) -= 5;
        if (M2C_FIELD(arg0, s8*, 0x61) >= 0x1A) {
            M2C_FIELD(arg0, u8*, 0x61) = 0;
        }
        t = M2C_FIELD(arg0, s8*, 0x61);
        if (t >= 6) {
            v = t;
        } else {
            v = 5;
        }
        M2C_FIELD(arg0, u16*, 0x7E) = v;
    }
    func_8002CCB0(arg0, 0x30, 0x40);
}

#include "common.h"
#define M2C_UNK s32

#define F(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800F52CC(void* arg0) {
    s32 temp_v0;

    temp_v0 = F(arg0, u16*, 0x7C) + 1;
    F(arg0, u16*, 0x7C) = temp_v0;
    if ((s16)temp_v0 == 0x78) {
        F(arg0, u16*, 0x7C) = 0;
        F(arg0, u16*, 0x88) = F(arg0, u16*, 0xA);
        F(arg0, u8*, 0x5) = F(arg0, u8*, 0x5) + 1;
    }
    if (F(arg0, s16*, 0x7C) < 0x3C || (F(arg0, u16*, 0x7C) & 1)) {
        func_8002CCB0(arg0, 0x30, 0x40);
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
extern u16 D_800F766C[];

void func_800F5344(void* arg0) {
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x88) +
                                 D_800F766C[0xF - M2C_FIELD(arg0, s16*, 0x7C)];
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x10) {
        M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
    }
    func_8002CCB0(arg0, 0x30, 0x40);
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F53C8(void) {
    D_800CCEDF = 1;
    clear_object_slot();
}

#include "../shared/rock_24/func_800F53F0.c"

#define func_800F53F0 func_800F5454
#define D_800F77EC D_800F77EC
#include "../shared/rock_24/func_800F53F0.c"
#undef func_800F53F0
#undef D_800F77EC

#define func_800F53F0 func_800F54B8
#define D_800F77EC D_800F77EC
#include "../shared/rock_24/func_800F53F0.c"
#undef func_800F53F0
#undef D_800F77EC

#include "common.h"
#include "mmx6/rock_24.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800F77EC;

void func_800F551C(void* arg0) {
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u32*, 0x8C) + 1;
    M2C_FIELD(arg0, u32*, 0x8C) = temp_v1;
    if (temp_v1 < 0x14U) {
        if (temp_v1 & 1) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        }
    } else {
        D_800F77E8 = 0;
        D_800F77F0 = 0;
        D_800F77EC -= 1;
        ((void (*)())clear_object_slot)(arg0);
    }
}

#include "common.h"
#include "mmx6/rock_24.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800F77EC;

void func_800F558C(void* arg0) {
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u32*, 0x8C) + 1;
    M2C_FIELD(arg0, u32*, 0x8C) = temp_v1;
    if (temp_v1 < 0x14U) {
        if (temp_v1 & 1) {
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x20, 0x20);
        }
    } else {
        D_800F77F4 = 0;
        D_800F77EC -= 1;
        ((void (*)())clear_object_slot)(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F55F4(void) {
    clear_object_slot();
}

#include "common.h"
#include "mmx6/rock_24.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F5614(void* arg0) {
    void* p;
    u8 t;

    p = D_800F7800;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t = M2C_FIELD(p, u8*, 0x14);
    M2C_FIELD(arg0, u8*, 0x16) = 2;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    M2C_FIELD(arg0, u8*, 0x14) = t;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5684(void) {
    clear_object_slot();
}

#include "common.h"
#include "mmx6/rock_24.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((M2C_UNK(*)(void*))func_80030ECC)
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

void func_800F56A4(s8* arg0) {
    if (D_800F77D8 != 0 || D_800F77DC != 0) {
        arg0[4]++;
        return;
    }
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        arg0[4]++;
        return;
    }
    if (++((s32*)arg0)[0x23] == 0x96) {
        arg0[4]++;
        return;
    }
    if (func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        arg0[4]++;
        return;
    }
    func_8002CCB0(arg0, 0x10, 0x10);
    animate_object(arg0);
    apply_object_motion(arg0);
}
#undef func_80030ECC

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5764(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5784(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F57A4(void) {
    clear_object_slot();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F57C4(void) {
    clear_object_slot();
}

#include "common.h"
#include "mmx6/rock_24.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object(void*);                  /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK apply_object_motion(void*);             /* extern */

void func_800F57E4(void* arg0) {
    // !FAKE: register pin for the parent pointer
    register void* temp_a1 asm("$5");
    s32 temp_v0;
    s32 g;

    temp_a1 = M2C_FIELD(arg0, void**, 0x7C);
    g = D_800F77D8;
    {
        // !FAKE: register pin for the copied halfword
        register s32 v asm("$2");
        v = M2C_FIELD(temp_a1, u16*, 0xA);
        M2C_FIELD(arg0, u16*, 0xA) = v;
        v = M2C_FIELD(temp_a1, u16*, 0xE);
        M2C_FIELD(arg0, u16*, 0xE) = v;
    }
    if ((g != 0) || (D_800F77DC != 0)) {
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s32*, 0x8C) + 1;
    M2C_FIELD(arg0, s32*, 0x8C) = temp_v0;
    if (temp_v0 == 0x32) {
        M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
    }
    apply_object_motion(arg0);
    animate_object(arg0);
    func_8002CCB0(arg0, 0x20, 0x20);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5894(void) {
    clear_object_slot();
}

// clang-format off
INCLUDE_ASM("asm/rock_24/nonmatchings/E9860", D_800F58B4);
// clang-format on
