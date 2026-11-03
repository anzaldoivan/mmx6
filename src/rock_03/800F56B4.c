#include "../shared/commander_yammark/func_800F56B4.c"

#include "common.h"
#include "mmx6/rock_03.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);

void func_800F56F8(void* arg0) {
    if (D_800F7DE4 != 0 || D_800F7DE8 != 0 || D_800F7E30 != 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    } else if (M2C_FIELD(arg0, u8*, 0x70) != 0 || check_enemy_hits(arg0) < 0 ||
               func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4) = 2;
    } else {
        animate_object(arg0);
        apply_object_motion(arg0);
        func_8002CCB0(arg0, 0x10, 0x10);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F57BC(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800F7D6C;
void func_800F7D70(void);

void func_800F57DC(void* arg0) {
    void* p;
    void* q;

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(p, u8*, 0x14);
    M2C_FIELD(arg0, u8*, 0x16) = 3;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F7D6C;
    M2C_FIELD(arg0, void**, 0x50) = func_800F7D70;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    ((void (*)(void*, s32))set_animation)(arg0, 0x12);
    q = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(q, u8*, 0x15);
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(q, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(q, u16*, 0xE);
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 2;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F58C8(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "../shared/commander_yammark/func_800F58E8.c"

#include "common.h"
#include "mmx6/rock_03.h"
#define M2C_UNK s32

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
M2C_UNK func_80049E50(void*);

void func_800F59A8(u8* arg0) {
    if (D_800F7DE4 != 0) {
        // !FAKE: goto shares the set2 and call blocks across the switch; merged tests with copied stores moved bytes
        goto set2;
    }
    if (D_800F7DE8 != 0 || D_800F7E30 != 0) {
        // !FAKE: goto shares the set2 and call blocks across the switch; merged tests with copied stores moved bytes
        goto set2;
    }
    switch (*(s8*)(arg0 + 5)) {
    case 0:
        if ((--arg0[7] << 24) == 0) {
            func_80049E50(arg0);
            arg0[5]++;
        }
        break;
    case 1:
        if ((s8)++arg0[7] != 0x1E) {
            // !FAKE: goto shares the set2 and call blocks across the switch; merged tests with copied stores moved bytes
            goto call;
        }
    set2:
        arg0[4] = 2;
        break;
    call:
        func_80030ECC(arg0);
        func_8002CCB0(arg0, 0x10, 0x10);
        break;
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5A98(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "../shared/commander_yammark/func_800F5AB8.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5B70(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "../shared/commander_yammark/func_800F5B90.c"

#include "common.h"
#include "mmx6/rock_03.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800F5C78(u8* arg0) {
    if (*(s8*)(arg0 + 0x46) == 0) {
        // !FAKE: goto keeps the 0x46 test as its own branch to set2; one merged || test moved bytes
        goto set2;
    }
    if (D_800F7DE4 != 0 || D_800F7DE8 != 0 || D_800F7E30 != 0) {
    set2:
        arg0[4] = 2;
        return;
    }
    if ((s8)++arg0[6] == 0x16) {
        play_sound(2, 0x31, arg0);
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x60, 0x60);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5D38(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "../shared/commander_yammark/func_800F5D58.c"

#include "../shared/commander_yammark/func_800F5E0C.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5EA4(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

// clang-format off
INCLUDE_ASM("asm/rock_03/nonmatchings/E9860", D_800F5EC4);
// clang-format on
