#define func_800E9D04 func_800E9E88
#include "../shared/rock_17/func_800E9D04.c"
#undef func_800E9D04

// clang-format off
INCLUDE_ASM("asm/rock_17/nonmatchings/E9860", func_800E9EBC);
// clang-format on

#include "common.h"
#include "mmx6/x4.h"

void func_8001D218();
#include "mmx6/state.h"
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CD40C;

void func_800E9EF0(u8* arg0) {
    s32 i;
    u8* p;
    u8* e;

    if ((D_800CD40C == 0) && (D_80097420.transition.active == 0)) {
        func_8001D218();
        i = 0xF;
        e = (u8*)&g_playthrough_state;
        p = arg0 + 0x35;
        arg0[0xC] = e[0x26];
        arg0[0xD] = e[0x27];
        arg0[0] = 7;
        arg0[1] = 0;
        arg0[2] = 0;
        arg0[3] = 0;
        do {
            *p = 0;
            i -= 1;
            p -= 1;
        } while (i >= 0);
    }
}

#include "common.h"
#include "mmx6/rock_17.h"

void func_800E9F7C(u8* arg0) {
    ((void (**)(u8*)) & D_800EA2C8[0x154])[(s8)arg0[5]](arg0);
    arg0[3] = D_800EAACC;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800E9FCC(void) {
    clear_object_slot();
}

#define func_8003744C func_800E9FEC
#define D_80073C1C D_800EA578
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA028(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x3C) += 0x20000;
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (M2C_FIELD(arg0, s16*, 0x3E) >= 0xF0) {
        M2C_FIELD(arg0, s16*, 0x3E) = 0xF0;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    M2C_FIELD(arg0, s16*, 0x16) =
        M2C_FIELD(arg0, s16*, 0x42) - M2C_FIELD(arg0, s16*, 0x4A);
    M2C_FIELD(arg0, s16*, 0x1A) = M2C_FIELD(arg0, s16*, 0x46);
    M2C_FIELD(arg0, s16*, 0x1E) =
        M2C_FIELD(arg0, s16*, 0x42) + M2C_FIELD(arg0, s16*, 0x4A);
    M2C_FIELD(arg0, s16*, 0x22) = M2C_FIELD(arg0, s16*, 0x46);
    M2C_FIELD(arg0, s16*, 0x26) =
        M2C_FIELD(arg0, s16*, 0x3A) + M2C_FIELD(arg0, s16*, 0x4A);
    M2C_FIELD(arg0, s16*, 0x2A) = M2C_FIELD(arg0, s16*, 0x3E);
    M2C_FIELD(arg0, s16*, 0x2E) =
        M2C_FIELD(arg0, s16*, 0x3A) - M2C_FIELD(arg0, s16*, 0x4A);
    M2C_FIELD(arg0, s16*, 0x32) = M2C_FIELD(arg0, s16*, 0x3E);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA0AC(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x5C), s8*, 1) >= 5) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

void func_800EA0E0(u8* arg0) {
    *(s32*)(arg0 + 0x48) += 0x51EB;
    if (*(s16*)(arg0 + 0x4A) >= 0x28) {
        *(s16*)(arg0 + 0x4A) = 0x28;
        arg0[6]++;
    }
    *(s16*)(arg0 + 0x16) = *(s16*)(arg0 + 0x42) - *(s16*)(arg0 + 0x4A);
    *(s16*)(arg0 + 0x1A) = *(s16*)(arg0 + 0x46);
    *(s16*)(arg0 + 0x1E) = *(s16*)(arg0 + 0x42) + *(s16*)(arg0 + 0x4A);
    *(s16*)(arg0 + 0x22) = *(s16*)(arg0 + 0x46);
    *(s16*)(arg0 + 0x26) = *(s16*)(arg0 + 0x3A) + *(s16*)(arg0 + 0x4A);
    *(s16*)(arg0 + 0x2A) = *(s16*)(arg0 + 0x3E);
    *(s16*)(arg0 + 0x2E) = *(s16*)(arg0 + 0x3A) - *(s16*)(arg0 + 0x4A);
    *(s16*)(arg0 + 0x32) = *(s16*)(arg0 + 0x3E);
}

#include "common.h"

void func_800EA160(void) {
}

#define func_8003744C func_800EA168
#define D_80073C1C D_800EA588
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EA1A4(void* arg0) {
    s32 y;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    s32 e;

    M2C_FIELD(arg0, s32*, 0x44) += 0xFFFE7AE2;
    y = M2C_FIELD(arg0, s8*, 2) * 2 + 0xA4;
    if (y >= M2C_FIELD(arg0, s16*, 0x46)) {
        M2C_FIELD(arg0, s16*, 0x46) = y;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    a = M2C_FIELD(arg0, u16*, 0x46);
    b = M2C_FIELD(arg0, u16*, 0x42);
    c = M2C_FIELD(arg0, u16*, 0x4A);
    d = M2C_FIELD(arg0, u16*, 0x3A);
    e = a + 2;
    M2C_FIELD(arg0, s16*, 0x3E) = e;
    M2C_FIELD(arg0, s16*, 0x16) = b - c;
    M2C_FIELD(arg0, s16*, 0x1A) = a;
    M2C_FIELD(arg0, s16*, 0x1E) = b + c;
    M2C_FIELD(arg0, s16*, 0x22) = a;
    M2C_FIELD(arg0, s16*, 0x26) = d + c;
    M2C_FIELD(arg0, s16*, 0x2A) = e;
    M2C_FIELD(arg0, s16*, 0x2E) = d - c;
    M2C_FIELD(arg0, s16*, 0x32) = e;
}

#include "common.h"

void func_800EA234(void) {
}

#define func_80041AB8 func_800EA23C
#define D_80075FD8 D_800EA564
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/rock_17.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* alloc_class6_slot(void);

void func_800EA278(u8* arg0, s32 arg1) {
    u8 b = arg1;
    void* obj;

    obj = alloc_class6_slot();
    {
        s32 one = 1;
        if (obj != 0) {
            s32 id = 0xC;
            M2C_FIELD(obj, u8*, 0) = one;
            M2C_FIELD(obj, u8*, 1) = id;
            M2C_FIELD(obj, u8*, 2) = b;
            M2C_FIELD(obj, u8**, 0x5C) = arg0;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_17/nonmatchings/E9860", D_800EA2C8);
// clang-format on
