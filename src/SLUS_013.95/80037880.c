#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80037A60(void* arg0);
void end_dash(s32 arg0);
void func_8003C4EC(struct X4_PlayerObj* self);
void func_8003CF54(struct X4_PlayerObj*, s32);
void check_low_health(void* arg0);

void func_80037880(void* arg0) {
    s8* p = arg0;

    func_80037A60(p);
    if (p[2] == 0) {
        if (((u8*)p)[0x47] == 0xD0) {
            func_8003CF54((struct X4_PlayerObj*)p, 0x52);
        } else {
            func_8003C4EC((struct X4_PlayerObj*)p);
        }
    }
    if (p[0x61] == 0x3C) {
        ((void (*)(s32))end_dash)((s32)p);
        if (p[0xD3] != 0) {
            p[0xA4] = 0;
            p[0x61] = 0;
            return;
        }
        check_low_health(p);
        p[0xA4] = -1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80037B10(void* arg0);    /* extern */
M2C_UNK func_8003AFF4(s32);        /* extern */
void check_low_health(void* arg0); /* extern */
void func_8003D394(void* arg0);    /* extern */

void func_80037920(void* arg0) {
    func_80037B10(arg0);
    func_8003D394(arg0);
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x61) == 0x3C) {
        ((void (*)(s32))func_8003AFF4)((s32)arg0);
        if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
            M2C_FIELD(arg0, u8*, 0xA4) = 0;
            M2C_FIELD(arg0, u8*, 0x61) = 0;
            return;
        }
        check_low_health(arg0);
        M2C_FIELD(arg0, s8*, 0xA4) = -1;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void end_dash(s32 arg0);               /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */

void func_800379AC(void* arg0) {
    s8 v;
    s8 r;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    v = M2C_FIELD(arg0, s8*, 0xCA);
    if (v > 0) {
        return;
    }
    if (v == 0) {
        M2C_FIELD(arg0, u8*, 0xA4) = 0;
        end_dash((s32)arg0);
    } else {
        if (v == -1) {
            func_8003BA04(arg0, 0x25);
            r = -2;
        } else {
            if (M2C_FIELD(arg0, s8*, 0x46) >= 0) {
                return;
            }
            func_8003BA04(arg0, 0x24);
            r = 1;
        }
        M2C_FIELD(arg0, s8*, 0xCA) = r;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CFB0(void* arg); /* extern */

void func_80037A60(void* arg0) {
    s32 temp_v0;
    s32 var_v1;

    if (M2C_FIELD(arg0, s8*, 0xD4) == 0) {
        temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
        if (temp_v0 != 0) {
            var_v1 = 2;
            if (temp_v0 > 0) {
                var_v1 = 1;
            }
            if (M2C_FIELD(arg0, u8*, 0x89) & var_v1) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x28) = 0;
            }
        }
        func_8002CFB0(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                goto block_11;
            }
        } else if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
        block_11:
            M2C_FIELD(arg0, s32*, 0x28) = 0;
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CFB0(void* arg); /* extern */

void func_80037B10(void* arg0) {
    s32 temp_v0;
    s32 var_v1;

    if (M2C_FIELD(arg0, s8*, 0xD4) == 0) {
        temp_v0 = M2C_FIELD(arg0, s32*, 0x20);
        if (temp_v0 != 0) {
            var_v1 = 2;
            if (temp_v0 > 0) {
                var_v1 = 1;
            }
            if (M2C_FIELD(arg0, u8*, 0x89) & var_v1) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s32*, 0x28) = 0;
            }
        }
        func_8002CFB0(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                goto block_11;
            }
        } else if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
        block_11:
            M2C_FIELD(arg0, s32*, 0x28) = 0;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8003AF1C(void*);
void func_8003B870(struct X4_PlayerObj* self);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CCBC();
extern struct X4_EngineObj g_playthrough_state;

void func_80037BC4(void* arg0) {
    struct X4_EngineObj* e = &g_playthrough_state;

    if (e->unkF != 0) {
        ((void (*)())func_8003B870)();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0xD5) == 0) {
        func_8003CCBC(arg0);
        ((void (*)(void*))func_8003AF1C)(arg0);
        M2C_FIELD(arg0, u8*, 0x86) = 1;
        e->gameplay_locked = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x6) == 0) {
        ((void (*)(void*, s32))func_8003BA04)(arg0, M2C_FIELD(arg0, u8*, 0xD8));
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
    func_80017A04(arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80037CB4();    /* extern */
M2C_UNK func_80037D68(); /* extern */

void func_80037C74(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        func_80037CB4();
        return;
    }
    func_80037D68();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
void func_8003ADB4(void* arg0);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CCBC();

void func_80037CB4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD4) == 0) {
        ((void (*)())func_8003CCBC)();
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            do {
                func_8003ADB4(arg0);
            } while (0);
            M2C_FIELD(arg0, u8*, 0x84) = 0;
        } else {
            func_8003BA04(arg0, 0xB);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s8*, 0x67) = -1;
            M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x100);
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            do {
            } while (0);
            M2C_FIELD(arg0, u8*, 0x84) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x86) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x67) == 0) {
        func_80017A04(arg0);
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80037D68);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*); /* extern */
s32 func_8003A628(void*);     /* extern */
M2C_UNK func_8003CCBC();      /* extern */

void func_80037DC4(void* arg0) {
    func_8003CCBC();
    if (func_8003A628(arg0) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xD0) == 0) {
            M2C_FIELD(arg0, s8*, 5) = 2;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        func_80017A04(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s8 D_800CCEDF;

void func_80037E1C(s8* arg0) {
    if (arg0[6] == 0) {
        ((void (*)())func_80017A04)();
        if (D_800CCEDF != 0) {
            arg0[6] = (u8)arg0[6] + 1;
        }
    } else {
        arg0[4] = 3;
        arg0[5] = 0;
        arg0[6] = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002D5D0(void*);
void func_8003A678(void* arg0);
void func_8003B870(struct X4_PlayerObj* self);
extern s8 D_800CCEDF;

void func_80037E88(void* arg0) {
    u8* p = arg0;

    if (D_800CCEDF != 0) {
        func_8003B870(arg0);
        return;
    }
    if (*(s8*)(p + 0x45) == 0) {
        *(s32*)(p + 0x20) = *(s32*)(p + 0xF0);
    } else {
        *(s32*)(p + 0x20) = *(s32*)(p + 0xF4);
    }
    if (*(u8*)(p + 0x15) == 0) {
        *(s32*)(p + 0x20) = -*(s32*)(p + 0x20);
    }
    func_8002D5D0(arg0);
    ((void (*)(void*))func_80017A04)(arg0);
    if (*(u8*)(p + 0xD2) == 0) {
        func_8003A678(arg0);
    }
}

/* Adapted from sozud/mmx4 @807a01b src/main/player_special.c:player_zero_ryuenjin_rise, AGPL-3.0; proven shared with X6 by exact signature dff51a405822 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 func_8003A628(void*);
M2C_UNK func_8002D5D0(void*);

void func_80037F34(struct X4_PlayerObj* self) {
    if (func_8003A628(self) == 0) {
        func_8002D5D0(self);
        func_80017A04(self);
    }
}
