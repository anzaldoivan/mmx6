#define func_80041AB8 func_800FBD04
#define D_80075FD8 D_800FD900
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#define func_800F1CD8 func_800FBD40
#define g_Player g_Player
#include "common.h"

#define M2C_UNK s32

#include "mmx6/x4.h"
#include "mmx6/globals.h"

void set_animation(void*, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;

void func_800FBD40(s8* arg0) {
    struct X4_PlayerObj* pl = &g_Player;

    *(u8*)((s32)pl + 0xCA) = 0;
    func_8003D308(0x14, pl->facing);
    arg0[5] = 1;
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    set_animation(arg0, 5);
    *(s16*)(arg0 + 0x7C) = 0x7F;
    *(s16*)(arg0 + 0x7E) = 0x19;
    arg0[0x61] = 0x19;
    func_8002CCB0(arg0, 0x60, 0x60);
}
#undef func_800F1CD8
#undef g_Player

#define func_800F1D54 func_800FBDBC
#include "../shared/rock_08/func_800F1D54.c"
#undef func_800F1D54

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FBEB0);
// clang-format on

#define func_800F1ED8 func_800FBF40
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_animation(void*, M2C_UNK);

void func_800FBF40(void* arg0) {
    s8 n;

    set_animation(arg0, 1);
    n = M2C_FIELD(arg0, s8*, 0x9A);
    if (n < 2) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
    } else if (n < 3) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x28000;
    } else if (n < 4) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = 0x18000;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
#undef func_800F1ED8

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FBFCC);
// clang-format on

#include "common.h"

void func_800FC054(void) {
}

#include "common.h"

void func_800FC05C(void) {
}

#define func_8003744C func_800FC064
#define D_80073C1C D_800FD91C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FC0A0(void* arg0) {
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_80074C9C;
    if (M2C_FIELD(arg0, s8*, 0x87) < 0xA) {
        M2C_FIELD(arg0, s8*, 0x87) = (s8)((u8)M2C_FIELD(arg0, s8*, 0x87) + 1);
    }
    M2C_FIELD(arg0, s8*, 0x8B) = 0;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)(M2C_FIELD(arg0, s8*, 0x88) * 0xA);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FC0F4);
// clang-format on

#define func_800F1ED8 func_800FC184
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_animation(void*, M2C_UNK);

void func_800FC184(void* arg0) {
    s8 n;

    set_animation(arg0, 1);
    n = M2C_FIELD(arg0, s8*, 0x9A);
    if (n < 2) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
    } else if (n < 3) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x28000;
    } else if (n < 4) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = 0x18000;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
#undef func_800F1ED8

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FC210);
// clang-format on

#define func_800F2244 func_800FC2AC
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK move_object(void*);
s32 random_byte();

void func_800FC2AC(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 r;

    r = random_byte() & 0xF;
    ((void (*)(void*))animate_object)(arg0);
    if (r < 5) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        self->action = 5;
        self->action_phase = 0;
        return;
    }
    if (r < 0xA) {
        self->action = 6;
        self->action_phase = 0;
        self->input.buttons.held = 0x5A;
        return;
    }
    ((void (*)(void*))move_object)(arg0);
    self->action = 2;
    self->action_phase = 1;
}
#undef func_800F2244

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FC340);
// clang-format on

#define func_800F2334 func_800FC39C
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800FC39C(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    ((void (*)(void*))animate_object)(arg0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
#undef func_800F2334

#define func_800F2378 func_800FC3E0
#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(u16*)((u8*)(p) + (o)))

void set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800FC3E0(void* arg0) {
    // !FAKE: inherited from src/shared/rock_08/func_800F2378.c
    register s32 t asm("$2");

    animate_object();
    t = OH(arg0, 0x7C) - 1;
    OH(arg0, 0x7C) = t;
    if ((s16)t == 0) {
        if (D_800CCF5F < 2) {
            OUB(arg0, 0x89) = 0;
        } else if (D_800CCF5F == 2) {
            OUB(arg0, 0x89) = 1;
        } else {
            OUB(arg0, 0x89) = 2;
        }
        set_animation(arg0, 2);
        t = OUB(arg0, 6) + 1;
        OUB(arg0, 6) = t;
    }
}
#undef func_800F2378

#define func_800F2404 func_800FC46C
#include "../shared/rock_08/func_800F2404.c"
#undef func_800F2404

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FC558);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FC5DC);
// clang-format on

#include "common.h"
#define M2C_UNK s32

void set_animation(void*, M2C_UNK);

void func_800FC638(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}

#define D_800F6AF0 D_800FDC80
#define func_800F2604 func_800FC66C
#include "../shared/rock_08/func_800F2604.c"
#undef func_800F2604
#undef D_800F6AF0

#define func_8003744C func_800FC6C8
#define D_80073C1C D_800FD948
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define D_800F6AF8 D_800FDC88
#define set_animation func_800179A4_r08
#define func_800F269C func_800FC704
#include "../shared/rock_08/func_800F269C.c"
#undef func_800F269C
#undef D_800F6AF8
#undef set_animation

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FC770);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FC820);
// clang-format on

#define func_800F2814 func_800FC87C
#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define M2C_UNK s32
void set_animation(void*, M2C_UNK);

void func_800FC87C(void* arg0) {
    s8 t;

    set_animation(arg0, 4);
    t = M2C_FIELD(arg0, s8*, 0x88);
    if (t == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x200000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 6;
    } else if (t == 2) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x400000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 6;
    } else if (t == 3) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            0x600000 / ABS(M2C_FIELD(arg0, s32*, 0x20));
    } else {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x800000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) - 6;
    }
    if (M2C_FIELD(arg0, s8*, 0x8B) == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) =
            (0x200000 / ABS(M2C_FIELD(arg0, s32*, 0x20))) + 8;
    }
    M2C_FIELD(arg0, u8*, 0x6)++;
}
#undef func_800F2814

#define func_800F2970 func_800FC9D8
#include "../shared/rock_08/func_800F2970.c"
#undef func_800F2970

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FCA30(void* arg0) {
    if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, s8*, 5) = 6;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
}

#include "common.h"

void func_800FCA64(void) {
}

#include "common.h"

void func_800FCA6C(void) {
}

#include "common.h"

void func_800FCA74(void) {
}

#define func_8003744C func_800FCA7C
#define D_80073C1C D_800FD968
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800FCAB8(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FCAF0);
// clang-format on

#define func_800F2B78 func_800FCBE0
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_08/func_800F2B78.c"
#undef func_800F2B78
#undef g_playthrough_state

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FCC8C);
// clang-format on

#define D_800F6AF8 D_800FDC88
#define func_800F2C74 func_800FCCDC
#define background_objects background_objects
#include "../shared/rock_08/func_800F2C74.c"
#undef func_800F2C74
#undef background_objects
#undef D_800F6AF8

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FCD44);
// clang-format on

#include "common.h"

void func_800FCDDC(void) {
}

#define func_8003744C func_800FCDE4
#define D_80073C1C D_800FD988
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define set_animation func_800179A4_r08
#define func_800F2DB8 func_800FCE20
#define D_8007433C D_8007433C
#include "../shared/rock_08/func_800F2DB8.c"
#undef func_800F2DB8
#undef D_8007433C
#undef set_animation

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FCE78);
// clang-format on

#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object(); /* extern */

void func_800FCF6C(void) {
    animate_object();
}

#define func_800F2F24 func_800FCF8C
#include "../shared/rock_08/func_800F2F24.c"
#undef func_800F2F24

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FD008);

INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FD0B0);
// clang-format on

#define func_800F1ED8 func_800FD10C
#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_animation(void*, M2C_UNK);

void func_800FD10C(void* arg0) {
    s8 n;

    set_animation(arg0, 1);
    n = M2C_FIELD(arg0, s8*, 0x9A);
    if (n < 2) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
    } else if (n < 3) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x28000;
    } else if (n < 4) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = 0x18000;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0x20);
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
#undef func_800F1ED8

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FD198);
// clang-format on

#define func_800F31A8 func_800FD210
#include "../shared/rock_08/func_800F31A8.c"
#undef func_800F31A8

#define func_800F3230 func_800FD298
#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800FD298(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 3) {
        M2C_FIELD(arg0, s8*, 7) = 0;
        set_animation(arg0, 3);
        if (!(random_byte() & 1)) {
            play_sound(2, 0x27, arg0);
        } else {
            play_sound(2, 0x28, arg0);
        }
        M2C_FIELD(arg0, s8*, 6) = 2;
    }
}
#undef func_800F3230

#define func_800F32A8 func_800FD310
#include "../shared/rock_08/func_800F32A8.c"
#undef func_800F32A8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FD340(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 3;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_80048DC8 func_800FD350
#define D_80077BC0 D_800FDC3C
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FD39C(void) {
    clear_object_slot();
}

#define func_800F3354 func_800FD3BC
#include "../shared/rock_08/func_800F3354.c"
#undef func_800F3354

#define func_8003744C func_800FD448
#define D_80073C1C D_800FDC48
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FD484);
// clang-format on

#define func_8003744C func_800FD52C
#define D_80073C1C D_800FDC50
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F3500 func_800FD568
#include "../shared/rock_08/func_800F3500.c"
#undef func_800F3500

#define func_8003744C func_800FD5E8
#define D_80073C1C D_800FDC58
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F35BC func_800FD624
#include "../shared/rock_08/func_800F35BC.c"
#undef func_800F35BC

#define func_800F3678 func_800FD6E0
#include "../shared/rock_08/func_800F3678.c"
#undef func_800F3678

// clang-format off
INCLUDE_ASM("asm/rock_37/nonmatchings/FA000", func_800FD778);
// clang-format on
