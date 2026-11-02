#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

void func_800EB87C(void* arg0) {
    struct X4_BackgroundObj* bg = background_objects;

    bg[1].y_pos.u.hi -= 8;
    if (bg[1].y_pos.i.hi < 0x339) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x44, arg0);
        ((void (*)(s32))func_80012D9C)(5);
        ((void (*)(s32, s32, s32))func_80029478)(6, 0xA, 2);
        bg[1].y_pos.i.hi = 0x338;
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);      /* extern */
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_800EB910(void* arg0) {
    if (!(M2C_FIELD(arg0, s16*, 0x7C) & 7)) {
        func_80029478(6, (s8)((M2C_FIELD(arg0, s16*, 0x7C) / 30) + 1), 2);
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        play_sound(2, 0x43, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800EB9B8(u8* arg0) {
    s32 t;

    t = background_objects[1].y_pos.u.hi + 8;
    background_objects[1].y_pos.u.hi = t;
    if ((s16)t >= 0x368) {
        background_objects[1].y_pos.u.hi = 0x368;
        *(s16*)(arg0 + 0x7E) = 3;
        arg0[6] = arg0[6] + 1;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8003D330();                     /* extern */
M2C_UNK func_800EA860(void*);

void func_800EBA04(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7E) == 0) {
        play_sound(0, 0xE, 0);
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
    }
    if (++M2C_FIELD(arg0, s8*, 0x5C) == 0x30) {
        func_8003D330();
        func_800EA860(arg0);
    }
}

#define func_8003744C func_800EBA84
#define D_80073C1C D_800F86F4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EBAC0(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EBAD8);
// clang-format on

#include "common.h"

extern s8 D_80097180;
extern void (*D_800F86FC[])(s8*);

void func_800EBB14(s8* arg0) {
    if (D_80097180 != 2 || arg0[6] < 2) {
        D_800F86FC[arg0[6]](arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EBB78(void* arg0) {
    play_sound(2, 0x45, arg0);
    M2C_FIELD(arg0, s8*, 0x90) = 1;
    M2C_FIELD(arg0, s16*, 0x7C) = 0x14;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_80041FB0 func_800EBBC4
#include "../shared/SLUS_013.95/func_80041FB0.c"
#undef func_80041FB0

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];

void func_800EBBF8(struct X4_MainObj* arg0) {
    background_objects[1].y_pos.val += 0xFFFF3334;
    if (background_objects[1].y_pos.i.hi < 0x321) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x44, arg0);
        ((void (*)(s32))func_80012D9C)(5);
        background_objects[1].y_pos.i.hi = 0x320;
        arg0->unk7C = 0x3C;
        arg0->unk6++;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 random_byte();

void func_800EBC80(void* arg0) {
    s16 n;

    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
        func_80029478(2, (random_byte() & 3) + 1, 2);
    }
    n = --M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0) {
        play_sound(2, 0x43, arg0);
        M2C_FIELD(arg0, u16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
extern struct X4_BackgroundObj background_objects[3];

void func_800EBD0C(void* arg0) {
    struct X4_BackgroundObj* bg = background_objects;

    M2C_FIELD(bg, s32*, 0x60) = (s32)(M2C_FIELD(bg, s32*, 0x60) + 0x18000);
    if (M2C_FIELD(bg, s16*, 0x62) >= 0x368) {
        M2C_FIELD(bg, s16*, 0x62) = 0x368;
        play_sound(2, 0x45, arg0);
        M2C_FIELD(arg0, u8*, 0x90) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x14;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EBD88);
// clang-format on

#define func_8003744C func_800EBDC4
#define D_80073C1C D_800F8714
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EBE00(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

s32 random_byte();

void func_800EBE14(u8* arg0) {
    s32 r;

    r = random_byte();
    arg0[6]++;
    *(s16*)(arg0 + 0x7C) = r % 40 + 50;
}

#include "common.h"
#define M2C_UNK s32

void func_800EAA2C();

#define F7_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F7_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800EBE78(void* arg0) {
    if (--F7_S16(arg0, 0x7C) == 0) {
        func_800EAA2C(arg0, 0);
        if (++F7_S16(arg0, 0x7E) < 4) {
            F7_U8(arg0, 6)--;
        } else {
            F7_U8(arg0, 6)++;
        }
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800EA860(void*); /* extern */

void func_800EBEFC(void* arg0) {
    func_800EA860(arg0);
}

#define func_8003744C func_800EBF1C
#define D_80073C1C D_800F8724
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EBF58(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x82) = 0xA0;
    M2C_FIELD(arg0, s16*, 0x86) = -0x40;
    play_sound(2, 0x45, arg0);
    M2C_FIELD(arg0, s8*, 0x8F) = 2;
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800EBFB8(void* arg0) {
    if (func_800ECD7C(arg0 + 0x86, 0x38, 2) != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
extern s8 D_800970A2;
extern u8 D_800CCF38;

void func_800EC000(void* arg0) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        if (D_800970A2 == 0) {
            if (D_800CCF38 >= 2) {
                temp_v0 = M2C_FIELD(arg0, u16*, 0x7E) + 1;
                M2C_FIELD(arg0, u16*, 0x7E) = temp_v0;
                temp_v0 = (s16)temp_v0 < 3;
            } else {
                temp_v0 = M2C_FIELD(arg0, u16*, 0x7E) + 1;
                M2C_FIELD(arg0, u16*, 0x7E) = temp_v0;
                temp_v0 = (s16)temp_v0 < 2;
            }
        } else {
            temp_v0 = M2C_FIELD(arg0, u16*, 0x7E) + 1;
            M2C_FIELD(arg0, u16*, 0x7E) = temp_v0;
            temp_v0 = (s16)temp_v0 < 4;
        }
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
            return;
        }
        M2C_FIELD(arg0, u8*, 0x91) = 1;
        play_sound(2, 0x45, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EA860(void*);             /* extern */
s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800EC0F0(void* arg0) {
    if (func_800ECD7C(arg0 + 0x86, -0x40, 2) != 0) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 0x91) = 0;
        M2C_FIELD(arg0, s8*, 0x8F) = 0;
        func_800EA860(arg0);
    }
}

#define func_8003744C func_800EC138
#define D_80073C1C D_800F8738
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC174(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x82) = 0x30;
    M2C_FIELD(arg0, s16*, 0x86) = -0x40;
    play_sound(2, 0x45, arg0);
    M2C_FIELD(arg0, s8*, 0x8F) = 2;
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800EC1D0(void* arg0) {
    if (func_800ECD7C(arg0 + 0x86, 0x38, 2) != 0) {
        M2C_FIELD(arg0, s8*, 7) = 4;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC218(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC240(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x80) = (s32)(M2C_FIELD(arg0, s32*, 0x80) + 0x18000);
    if (M2C_FIELD(arg0, s16*, 0x82) >= 0xD0) {
        play_sound(2, 0x48, arg0);
        M2C_FIELD(arg0, s16*, 0x82) = 0xD0;
        M2C_FIELD(arg0, s8*, 7) = 4;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC2B0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC2D8(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s8*, 0x91) = 1;
        play_sound(2, 0x45, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EA860(void*);             /* extern */
s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800EC338(void* arg0) {
    if (func_800ECD7C(arg0 + 0x86, -0x40, 2) != 0) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 0x91) = 0;
        M2C_FIELD(arg0, s8*, 0x8F) = 0;
        func_800EA860(arg0);
    }
}

#define func_8003744C func_800EC380
#define D_80073C1C D_800F8754
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC3BC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x82) = 0xA0;
    M2C_FIELD(arg0, s16*, 0x86) = -0x40;
    play_sound(2, 0x45, arg0);
    M2C_FIELD(arg0, s8*, 0x8F) = 2;
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800EC418(void* arg0) {
    if (func_800ECD7C(arg0 + 0x86, 0x38, 2) != 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;

void func_800EC460(struct X4_PlayerObj* arg0) {
    if (arg0->x_pos.i.hi < g_Player.x_pos.i.hi) {
        arg0->unk7 = 6;
    } else if (arg0->y_pos.i.hi < g_Player.y_pos.i.hi) {
        arg0->unk7 = 7;
    } else {
        arg0->unk7 = 5;
    }
    arg0->unk6++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */

void func_800EC4B4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, s8*, 0x91) = 1;
        play_sound(2, 0x45, arg0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EA860(void*);             /* extern */
s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800EC508(void* arg0) {
    if (func_800ECD7C(arg0 + 0x86, -0x40, 2) != 0) {
        M2C_FIELD(arg0, s8*, 0x91) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 0x8F) = 0;
        func_800EA860(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */
extern void (*D_800F8768[])(void*);

void func_800EC550(void* arg0) {
    D_800F8768[M2C_FIELD(arg0, s8*, 6)](arg0);
    M2C_FIELD(arg0, s8*, 0x90) = 2;
    func_800ECD7C(arg0 + 0x86, -0x40, 4);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s8 D_80097180;
extern struct X4_BackgroundObj background_objects[3];

void func_800EC5AC(void* arg0) {
    struct X4_BackgroundObj* bg;

    if (D_80097180 != 2) {
        bg = background_objects;
        bg[1].y_pos.val += 0xFFFC0000;
        if (bg[1].y_pos.i.hi < 0x309) {
            ((void (*)(s32, s32, void*))play_sound)(2, 0x44, arg0);
            ((void (*)(s32))func_80012D9C)(5);
            bg[1].y_pos.i.hi = 0x308;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 random_byte();

void func_800EC640(void* arg0) {
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 7)) {
        func_80029478(6, (random_byte() & 3) | 4, 2);
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

void func_800EC6BC(void) {
}

#define func_8003744C func_800EC6C4
#define D_80073C1C D_800F8784
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define B(p, o) M2C_FIELD(p, u8*, o)

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EC700(void* arg0) {
    s32 cur;
    // !FAKE: retail holds the compare constant in the first return register
    register s32 want asm("$2");
    s8 temp_s0;

    temp_s0 = SB(M2C_FIELD(arg0, void**, 0x80), 7);
    if (temp_s0 == 0) {
        return;
    }
    switch (temp_s0) {
    case 1:
        cur = SB(arg0, 2);
        want = 0x20;
        // !FAKE: shared compare block reached from cases 1-3
        goto block_11;
    case 2:
        cur = SB(arg0, 2);
        want = 0x21;
        // !FAKE: shared compare block reached from cases 1-3
        goto block_11;
    case 3:
        cur = SB(arg0, 2);
        want = 0x22;
    // !FAKE: shared compare block reached from cases 1-3
    block_11:
        if (cur == want) {
            set_animation(arg0, 4);
            {
                // !FAKE: retail increments the byte in the first return register
                register s32 n asm("$2") = B(arg0, 6) + 1;
                B(arg0, 6) = n;
            }
        }
        break;
    case 4:
        if (SB(arg0, 2) == 0x22) {
            set_animation(arg0, 2);
            SB(arg0, 6) = temp_s0;
        }
        break;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC7DC(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32

void func_800EAA2C();
extern s8 D_800970A2;

#define F7_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F7_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F7_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800EC7F4(void* arg0) {
    if (--F7_S16(arg0, 0x7C) == 0) {
        if (D_800970A2 == 0) {
            switch (F7_S8(arg0, 2)) {
            case 32:
                func_800EAA2C(arg0, 0x10);
                break;
            case 33:
                func_800EAA2C(arg0, 0x11);
                break;
            case 34:
                func_800EAA2C(arg0, 0x12);
                break;
            }
        } else {
            switch (F7_S8(arg0, 2)) {
            case 32:
                func_800EAA2C(arg0, 0x20);
                break;
            case 33:
                func_800EAA2C(arg0, 0x21);
                break;
            case 34:
                func_800EAA2C(arg0, 0x22);
                break;
            }
        }
        F7_U8(arg0, 6)++;
    }
}

#undef F7_S8
#undef F7_U8
#undef F7_S16

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

M2C_UNK set_animation(void*, M2C_UNK);

void func_800EC928(void* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 1);
    B(W(arg0, 0x80), 0x7) = 0;
    B(arg0, 0x6) = 0;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
extern u8 D_800F79D0[];

void func_800EC95C(void* arg0) {
    s8 temp_v1 = M2C_FIELD(arg0, s8*, 0x45);
    void* temp_a0 = M2C_FIELD(arg0, void**, 0x80);

    if (temp_v1 == 1) {
        M2C_FIELD(arg0, void**, 0x50) = D_800F79D0 + 0xB60;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(temp_a0, u8*, 7) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    } else if (temp_v1 == 2) {
        play_sound(2, 0x46, arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */

void func_800EC9C8(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 0x7) == 4) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x47, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 3);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800ECA28(void* arg0) {
    s8* p;

    p = M2C_FIELD(arg0, s8**, 0x80);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s8*, 0x60) = 0;
        p[7] = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800ECA7C
#define D_80073C1C D_800F87A0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800ECAB8(u8* arg0) {
    s8 t = *(s8*)(*(u8**)(arg0 + 0x80) + 7);

    if (t == 0) {
        return;
    }
    switch (t) {
    case 5:
        if (*(s8*)(arg0 + 2) == 0x10) {
            ((void (*)(void*, s32))set_animation)(arg0, 6);
            arg0[6]++;
        }
        break;
    case 6:
        if (*(s8*)(arg0 + 2) == 0x11) {
            ((void (*)(void*, s32))set_animation)(arg0, 6);
            arg0[6]++;
        }
        break;
    case 7:
        if (*(s8*)(arg0 + 2) == 0x12) {
            ((void (*)(void*, s32))set_animation)(arg0, 6);
            arg0[6]++;
        }
        break;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800EAA2C();

void func_800ECB64(void* arg0) {
    s8 t = M2C_FIELD(arg0, s8*, 0x45);

    if (t == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_800EAA2C(arg0, 0x30);
    } else if (t == 2) {
        play_sound(2, 0x49, arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */

void func_800ECBC4(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 7);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "common.h"

void func_800ECC18(u8* arg0) {
    u8* p = *(u8**)(arg0 + 0x80);
    if (*(s8*)(arg0 + 0x45) == 1) {
        p[7] = 0;
        arg0[6] = 0;
    }
}

#include "common.h"

void func_800ECC3C(void) {
}

#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002BCCC(void*, s32);

void func_800ECC44(void* arg0, s32 arg1) {
    void* p;
    u8 b = arg1;

    p = func_8002BCCC(arg0, 0);
    if (p != 0) {
        M2C_FIELD(p, u8*, 0) = 0x41;
        M2C_FIELD(p, u8*, 1) = 0x10;
        M2C_FIELD(p, u8*, 0x15) = 0;
        M2C_FIELD(p, u8*, 2) = b;
        M2C_FIELD(p, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(p, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(p, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        {
            s32 t = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(p, void**, 0x80) = arg0;
            M2C_FIELD(p, u8*, 0x14) = t;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class4_slot();

void func_800ECCD8(void* arg0, s32 arg1) {
    void* e;
    u8 b = arg1;
    s32 y;

    e = alloc_class4_slot();
    if (e != 0) {
        M2C_FIELD(e, u8*, 0) = 0x41;
        M2C_FIELD(e, u8*, 1) = 0xA;
        M2C_FIELD(e, u8*, 2) = b;
        M2C_FIELD(e, s32*, 8) = M2C_FIELD(arg0, s16*, 0xA);
        y = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(e, void**, 0x7C) = arg0;
        M2C_FIELD(e, s32*, 0xC) = y;
        M2C_FIELD(e, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(e, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(e, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(e, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(e, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
    }
}

#include "common.h"
#define M2C_UNK s32

s32 func_800ECD7C(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s16* p = (s16*)arg0;
    s16 tgt = arg1;
    s16 step = arg2;
    s32 d;

    d = *p - tgt;
    if (d >= 0 ? (d <= step) : (tgt - *p <= step)) {
        *p = tgt;
        return 1;
    }
    if (tgt < *p) {
        *p -= step;
    } else if (*p < tgt) {
        *p += step;
    }
    return 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK clear_object_slot(void*);                /* extern */

void func_800ECDF8(void* arg0) {
    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x30) {
        play_sound(2, 0x14, arg0);
    }
    clear_object_slot(arg0);
}

#define func_80041AB8 func_800ECE40
#define D_80075FD8 D_800F8878
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002EE10(void*);

void func_800ECE7C(struct X4_PlayerObj* self) {
    ((void (*)(void*))func_8002D230)(self);
    if (self->y_vel.val <= -0x40000) {
        self->y_vel.val = -0x40000;
    }
    if (self->unk70 != 0 || (func_8002EE10(self), self->unk70 != 0)) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x4D, self);
        self->x_vel.val = -0x10000;
        self->y_vel.val = 0x15555;
        self->unk70 = 0;
        self->unk2C = 0xB60;
        self->unk7++;
        func_8002D230(self);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002EE10(void*);

void func_800ECF20(struct X4_PlayerObj* self) {
    ((void (*)(void*))func_8002D230)(self);
    if (self->unk70 != 0 || (func_8002EE10(self), self->unk70 != 0)) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x4D, self);
        self->x_vel.val = -0x10000;
        self->attack_pose_timer = 1;
        self->y_vel.val = 0;
        M2C_FIELD(self, s16*, 0x88) = 0x3C;
        self->unk7++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object();

void func_800ECFA0(void* arg0) {
    ((void (*)(void*))move_object)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
        M2C_FIELD(arg0, u8*, 7) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80049E50(void*);
extern s32 D_800F8848;

void func_800ECFF0(u8* arg0) {
    *(s32**)(arg0 + 0x50) = &D_800F8848;
    ((void (*)(void*))func_80049E50)(arg0);
    arg0[0x92] = 1;
    *(s16*)(arg0 + 0x88) = 0x1E;
    arg0[7] = arg0[7] + 1;
}

#include "common.h"

void func_800ED03C(u8* arg0) {
    if (--*(s16*)(arg0 + 0x88) == 0) {
        arg0[4] = 2;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002EE10(void*);
M2C_UNK func_80049D90(void*);
extern void (*D_800F888C[])(void*);

void func_800ED064(void* arg0) {
    D_800F888C[M2C_FIELD(arg0, s8*, 7)](arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
        func_8002EE10(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) == 0) {
            return;
        }
    }
    if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
        func_80049D90(arg0);
    }
    M2C_FIELD(arg0, u8*, 4) = 2;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK move_object();

void func_800ED0F0(u8* arg0) {
    ((void (*)(void*))move_object)(arg0);
    arg0[7] = arg0[7] + 1;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800ED120(void) {
    move_object();
}

#define func_80041AB8 func_800ED140
#define D_80075FD8 D_800F8894
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800ED17C(void) {
    move_object();
}

#define func_80041AB8 func_800ED19C
#define D_80075FD8 D_800F889C
#define FAMILY_FIELD 7
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED1D8(void* arg0) {
    void* parent;
    s32 v;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) - 0xA4;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(parent, s16*, 0xA) + 0xA4;
    }
    M2C_FIELD(arg0, u8*, 0x3) = 1;
    v = M2C_FIELD(arg0, s8*, 0x45) * 0x10;
    M2C_FIELD(arg0, s8*, 0x8C) = 0x7F - v;
    M2C_FIELD(arg0, s8*, 0x8E) = v;
    if (M2C_FIELD(arg0, s32*, 0x84) != M2C_FIELD(parent, s8*, 0x6)) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x7) = M2C_FIELD(arg0, u8*, 0x7) + 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED258(struct ObjectHeader* arg0) {
    arg0->state = 2;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);

extern u8 D_800F79D0[];

void func_800ED264(u8* arg0) {
    s8 state;
    s16* t;

    state = arg0[5];
    if (state == 0) {
        if (!(*(s8*)(arg0 + 2) & 0xF0)) {
            s32 next;
            // !FAKE: pin keeps the constants in the first return register
            register s32 k asm("$2");

            func_800477E4(4, (M2C_UNK*)(D_800F79D0 + 0xCB8), arg0);
            next = arg0[5];
            k = 0x3C;
            *(s16*)(arg0 + 0x88) = k;
            k = 5;
            *(s16*)(arg0 + 0x8A) = k;
            arg0[5] = next + 1;
            return;
        }
        arg0[5] = 2;
    } else if (state == 1) {
        t = (s16*)(arg0 + 0x7C);
        if ((t[6] = *(s16*)(arg0 + 0x88) - 1) == 0) {
            arg0[5]++;
            return;
        }
        if ((t[7] = *(s16*)(arg0 + 0x8A) - 1) == 0) {
            func_80049EBC(arg0, 1, 0x10, 0x40);
            *(s16*)(arg0 + 0x8A) = 5;
        }
    } else if (state == 2) {
        clear_object_slot(arg0);
    }
}

#define func_8003744C func_800ED364
#define D_80073C1C D_800F88D8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */

void func_800ED3A0(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    switch (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 0x90)) {
    case 0:
        func_800ECD7C(arg0 + 0x86, 0x40, 2);
        break;
    case 1:
        func_800ECD7C(arg0 + 0x86, -0x40, 2);
        break;
    case 2:
        func_800ECD7C(arg0 + 0x86, -0x40, 4);
        break;
    }
}

#include "common.h"

void func_800ED42C(void) {
}

#define func_8003744C func_800ED434
#define D_80073C1C D_800F88E0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800ED470(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

void func_800ED484(void) {
}

#include "common.h"

void func_800ED48C(void) {
}

#define func_80041AB8 func_800ED494
#define D_80075FD8 D_800F88C0
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"
#include "mmx6/psyq_api.h"

s32 func_80028078(s32, s32, u32);
extern u16 D_800F8C08[][2];
extern X4_RECT D_800F981C[];

#define SCR_08 (*(u16(**)[16][16])0x1F800008)
#define TILE(fld, dx, dy)                                                      \
    {                                                                          \
        s32 x, y, v, c, rw;                                                    \
        u16 t;                                                                 \
        x = D_800F8C08[i][0] + (dx);                                           \
        y = D_800F8C08[i][1] + (dy);                                           \
        v = func_80028078(0, x / 256, y / 256) & 0xFF;                         \
        c = (x & 0xF0) / 16;                                                   \
        rw = (y & 0xF0) / 16;                                                  \
        t = SCR_08[v][rw][c] & 0x3FFF;                                         \
        D_800F981C[i].fld = t;                                                 \
    }

void func_800ED4D0(void) {
    s32 i;

    i = 0;
    do {
        TILE(x, 0, 0);
        TILE(y, 16, 0);
        TILE(w, 0, 16);
        TILE(h, 16, 16);
        i++;
    } while (i < 8);
}

#include "common.h"
#include "mmx6/psyq_api.h"

#include "mmx6/state.h"
extern u16 D_800E3142;
extern X4_RECT D_800F981C[];

#define SCR_0C (*(s32**)0x1F80000C)
#define ROW(n) ((u16*)((u8*)D_800F981C + ((n) << 3)))

void func_800ED764(void) {
    s32 buf[24];
    s32 i;
    s32 j;

    if ((u32)D_80097420.frame_counter % 5 == 0) {
        for (i = 0; i < 8; i++) {
            if (i == 0) {
                for (j = 0; j < 4; j++) {
                    buf[j] = SCR_0C[ROW(0)[j]];
                }
            } else {
                for (j = 0; j < 4; j++) {
                    s32 v = SCR_0C[ROW(i)[j]];
                    SCR_0C[ROW(i - 1)[j]] = v;
                }
            }
        }
        for (j = 28; j < 32; j++) {
            SCR_0C[((u16*)D_800F981C)[j]] = buf[j - 28];
        }
        D_800E3142++;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800F88E8[][4];
extern u16 D_800F8988[][8][2];
extern u16 D_800F985C;

void func_800ED8AC(void) {
    u16 buf[4];
    s32 i;

    i = 0;
    D_800F985C &= 7;
    do {
        buf[0] = D_800F8988[i][(s16)D_800F985C][0];
        buf[1] = D_800F8988[i][(s16)D_800F985C][1];
        buf[2] = D_800F88E8[i][2];
        buf[3] = D_800F88E8[i][3];
        ((void (*)(s32, s32, s32, u8*))func_80027BA0)(
            0, D_800F88E8[i][0], D_800F88E8[i][1], (u8*)buf);
        i++;
    } while (i < 20);
    background_objects[0].unk4C = 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK clear_object_slot();
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800ED4D0(void);
void func_800ED764(void);
void func_800ED8AC(void);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u16 D_800E3142;
extern u16 D_800F985C;

#define PL_14C (*(s16*)((u8*)&g_Player + 0x14C))

void func_800ED998(s8* arg0) {
    s8 temp_s1;

    if (arg0[4] == 0) {
        D_800F985C = D_800E3142;
        func_800ED4D0();
        func_800ED8AC();
        arg0[4]++;
    }
    if (g_Player.nova_strike_active != 2) {
        temp_s1 = g_Player.state;
        if (temp_s1 == 1 && g_Player.hp != 0) {
            if (g_Player.unk5 == 0x14) {
                if (arg0[0x14] != 0) {
                    play_sound(5, 3, 0);
                    arg0[0x14] = 0;
                }
            } else if (g_Player.unk5 != 0 && g_Player.unk5 != 0x14) {
                if (g_playthrough_state.checkpoint == 0) {
                    background_objects[0].unk26 =
                        background_objects[0].x_pos.i.hi;
                    background_objects[0].unk1E =
                        background_objects[0].x_pos.i.hi;
                }
                if (g_Player.unk68 != 0) {
                    if (g_playthrough_state.checkpoint >= 2) {
                        play_sound(5, 3, 0);
                        clear_object_slot(arg0);
                        return;
                    }
                    if (arg0[0x14] == 0 || PL_14C != 0) {
                        play_sound(5, 6, 0);
                        arg0[0x14] = temp_s1;
                    }
                    func_800ED764();
                    if ((u32)D_80097420.frame_counter % 5 == 0) {
                        D_800F985C++;
                        func_800ED8AC();
                    }
                    if (func_80030234(&g_Player, g_Player.x_pos.i.hi,
                                      g_Player.unk68->unk1 +
                                          (g_Player.y_pos.i.hi +
                                           g_Player.unk68->unk3)) == 0x3A) {
                        g_Player.x_pos.i.hi--;
                    }
                }
            }
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80029F38();
M2C_UNK clear_object_slot();
extern s8 D_8008EAB0;
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEED;

void func_800EDBB8(s32 arg0) {
    u16 oy;
    u16 ox;

    if (g_Player.unk5 == 0x14) {
        D_8008EAB0 = 1;
        oy = background_objects[0].y_pos.i.hi;
        ox = background_objects[0].x_pos.i.hi;
        background_objects[1].unk4 = 5;
        background_objects[0].y_pos.i.hi = 0x3B0;
        background_objects[1].y_pos.i.hi = 0x3C0;
        background_objects[2].y_pos.i.hi = 0x3B0;
        background_objects[0].unk24 = 0x17C0;
        background_objects[0].unk1C = 0x17C0;
        background_objects[1].x_pos.i.hi = 0;
        background_objects[0].unk4C = 1;
        background_objects[1].unk4C = 1;
        background_objects[2].unk4C = 1;
        background_objects[0].unk26 = 0;
        background_objects[0].unk1E = 0;
        background_objects[0].unk2A = 0x3B0;
        background_objects[0].unk22 = 0x3B0;
        background_objects[0].unk28 = 0x3B0;
        background_objects[0].unk20 = 0x3B0;
        D_800CCEED = 1;
        background_objects[0].x_pos.i.hi = ox - 0x1240;
        background_objects[2].x_pos.i.hi = background_objects[0].x_pos.i.hi / 2;
        {
            s16 d = g_Player.x_pos.i.hi - ox;
            g_Player.x_pos.i.hi = d + background_objects[0].x_pos.i.hi;
        }
        {
            s16 d = g_Player.y_pos.i.hi - oy;
            g_Player.y_pos.i.hi = d + background_objects[0].y_pos.i.hi;
        }
        {
            s16 d = g_Player.unk18.i.hi - ox;
            g_Player.unk18.i.hi = d + background_objects[0].x_pos.i.hi;
        }
        {
            s16 d = g_Player.unk1C.i.hi - oy;
            g_Player.unk1C.i.hi = d + background_objects[0].y_pos.i.hi;
        }
        func_80029F38(background_objects[0].x_pos.i.hi - 0x30,
                      background_objects[0].x_pos.i.hi + 0x170, 0x380, 0x4D0,
                      0);
        clear_object_slot(arg0);
    }
}

#define func_80041AB8 func_800EDD00
#define D_80075FD8 D_800F8C28
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
extern s8 D_800CCEED;

void func_800EDD3C(void* arg0) {
    if (D_800CCEED == 0) {
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern s16 D_80097202;

void func_800EDD7C(struct X4_MainObj* arg0) {
    if (D_80097202 >= 0x1240) {
        g_Player.x_pos.i.hi = 0x12E0;
        func_8003D308(0x14, g_Player.unk15);
        arg0->state++;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EDDD8);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EDF90);
// clang-format on

#define func_800E9D5C func_800EE2BC
#define background_objects background_objects
#include "../shared/rock_06/func_800E9D5C.c"
#undef func_800E9D5C
#undef background_objects

#define func_80048DC8 func_800EE3F8
#define D_80077BC0 D_800F8CD8
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800EE444(void) {
    func_8002CA14();
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EE464);
// clang-format on

#define func_800EA0EC func_800EE64C
#define D_800C1220 D_800C1220
#include "../shared/rock_06/func_800EA0EC.c"
#undef func_800EA0EC
#undef D_800C1220

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EE790);
// clang-format on

#define func_80048DC8 func_800EEA90
#define D_80077BC0 D_800F8D40
#include "../shared/d1000/func_80048DC8.c"
#undef func_80048DC8
#undef D_80077BC0

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800EEADC(void) {
    func_8002CA54();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002C9D4(); /* extern */

void func_800EEAFC(void) {
    func_8002C9D4();
}

#define func_800ECAB8 func_800EEB1C
#define D_800C1220 D_800C1220
#include "../shared/rock_06/func_800ECAB8.c"
#undef func_800ECAB8
#undef D_800C1220

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EEC50);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EEED8);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EF100);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EFB14);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800EFD00);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F00B4);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(void*);                            /* extern */
M2C_UNK func_80030ECC();                                 /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);         /* extern */
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_800F8D84;

void func_800F0114(void* arg0) {
    u8 temp_v0;

    M2C_FIELD(arg0, s8*, 3) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        func_80030ECC();
        if (!(M2C_FIELD(arg0, u8*, 0x85) & 3)) {
            func_80049EBC(arg0, 1, 0x20, 0x20);
        }
        if (!(M2C_FIELD(arg0, u8*, 0x85) & 7)) {
            func_800477E4(3, &D_800F8D84, arg0);
        }
        temp_v0 = M2C_FIELD(arg0, u8*, 0x85);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, u8*, 0x85) = (u8)(temp_v0 - 1);
            return;
        }
        goto block_7;
    }
block_7:
    func_8002CA14(arg0);
}

#include "common.h"

void func_800F01B4(void) {
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F01BC);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern s8 D_80097244;
extern s32 D_800F8DD8;

void func_800F036C(void* arg0) {
    s16 rect[4];
    s8 state;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, u8*, 0) |= 0x10;
    func_80017A04(arg0);
    if (check_enemy_hits(arg0) < 0) {
        M2C_FIELD(arg0, u8*, 3) = 0;
        rect[0] = M2C_FIELD(arg0, u16*, 0xA) - 0x10;
        rect[1] = M2C_FIELD(arg0, u16*, 0xE) + 0x1F0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            rect[2] = 2;
        } else {
            rect[2] = 1;
        }
        rect[3] = 1;
        func_80027BA0(0, M2C_FIELD(arg0, s16*, 0xA) - 0x10,
                      M2C_FIELD(arg0, s16*, 0xE) - 0x10, (u8*)rect);
        D_80097244 = 1;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_800477E4(5, &D_800F8DD8, arg0);
        } else {
            M2C_FIELD(arg0, u16*, 0xA) -= 8;
            func_800477E4(3, &D_800F8DD8, arg0);
        }
        state = 2;
    } else {
        if (func_8002CBFC(arg0, 0x30, 0x30) == 0) {
            func_8002CCB0(arg0, 0x20, 0x20);
            return;
        }
        state = 3;
    }
    M2C_FIELD(arg0, u8*, 4) = state;
}

#define func_800EA1D8 func_800F04A4
#define D_800FAA64 D_800F8DE0
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA14(); /* extern */

void func_800F04F0(void) {
    ((M2C_UNK(*)())func_8002CA14)();
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54(); /* extern */

void func_800F0510(void) {
    func_8002CA54();
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F0530);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F0994);
// clang-format on

#include "../shared/rock_07/func_800F0CF4.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F10A8(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x1C) = 0;
    M2C_FIELD(arg0, s8*, 0x1E) = 0;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#define func_800EA704 func_800F10C8
#define g_Player g_Player
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

extern struct X4_PlayerObj g_Player;
#define PLAYER (*(struct X4_PlayerObj*)&g_Player)

void func_800F10C8(struct X4_BaseObj* self) {
    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x80) & 3) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x83) != 0) {
        M2C_FIELD(self, u8*, 0x83)--;
        return;
    }
    if ((self->y_pos.i.hi - PLAYER.y_pos.i.hi >= 0
             ? self->y_pos.i.hi - PLAYER.y_pos.i.hi
             : PLAYER.y_pos.i.hi - self->y_pos.i.hi) < 0x28) {
        if (self->unk15 != 0) {
            if (PLAYER.x_pos.i.hi < self->x_pos.i.hi + 0x50) {
                M2C_FIELD(self, u8*, 0x81)++;
            } else {
                M2C_FIELD(self, u8*, 0x81) = 0;
            }
        } else {
            if (self->x_pos.i.hi - 0x50 < PLAYER.x_pos.i.hi) {
                M2C_FIELD(self, u8*, 0x81)++;
            } else {
                M2C_FIELD(self, u8*, 0x81) = 0;
            }
        }
        if (M2C_FIELD(self, u8*, 0x81) >= 0x3D) {
            self->unk5 = 4;
            self->unk6 = 0;
            set_animation(self, 7);
            M2C_FIELD(self, u8*, 0x81) = 0;
            M2C_FIELD(self, u8*, 0x80) |= 2;
        }
    } else {
        M2C_FIELD(self, u8*, 0x81) = 0;
    }
}
#undef func_800EA704
#undef g_Player

#define func_800EA840 func_800F1204
#include "../shared/rock_06/func_800EA840.c"
#undef func_800EA840

#define func_800EA9E0 func_800F13A4
#define D_800950A0 D_800950A0
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

extern s8 D_800950A0[];
extern struct X4_PlayerObj g_Player;

#define ABS(v) ((v) < 0 ? -(v) : (v))
#define OBJ(p) ((struct X4_BaseObj*)(p))

void func_800F13A4(struct X4_BaseObj* self) {
    s8* p;

    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x80) & 1) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x82) != 0) {
        M2C_FIELD(self, u8*, 0x82)--;
        return;
    }
    for (p = D_800950A0; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (OBJ(p)->active == 0 || OBJ(p)->id != 0) {
            continue;
        }
        if (self->unk15 != 0) {
            struct X4_PlayerObj* pl = &g_Player;
            if (pl->unk15 == 0 && self->x_pos.val < pl->x_pos.val &&
                ABS(OBJ(p)->y_pos.i.hi - self->y_pos.i.hi) < 0x18 &&
                OBJ(p)->x_pos.i.hi < self->x_pos.i.hi + 0x80) {
                M2C_FIELD(self, u8*, 0x80) |= 1;
            }
        } else {
            struct X4_PlayerObj* pl = &g_Player;
            if (pl->unk15 != 0 && self->x_pos.val > pl->x_pos.val &&
                ABS(OBJ(p)->y_pos.i.hi - self->y_pos.i.hi) < 0x18 &&
                self->x_pos.i.hi - 0x80 < OBJ(p)->x_pos.i.hi) {
                M2C_FIELD(self, u8*, 0x80) |= 1;
            }
        }
        if (M2C_FIELD(self, u8*, 0x80) & 1) {
            self->unk5 = 3;
            self->unk6 = 0;
            set_animation(self, 5);
            return;
        }
    }
}
#undef func_800EA9E0
#undef D_800950A0

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F1590);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F16CC);

INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F180C);
// clang-format on

#define func_80041AB8 func_800F1958
#define D_80075FD8 D_800F8F54
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F1994);
// clang-format on

#define func_800EB070 func_800F1A34
#include "../shared/rock_06/func_800EB070.c"
#undef func_800EB070

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D230(void*);          /* extern */
extern M2C_UNK D_800743DC;

void func_800F1AD0(void* arg0) {
    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_800743DC;
        func_8002D230(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            set_animation(arg0, 4);
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 0;
    }
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
void* func_8002C458();                       /* extern */

void func_800F1B78(void* arg0) {
    void* temp_v0;

    func_80017A04();
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        temp_v0 = func_8002C458();
        if (temp_v0 != NULL) {
            play_sound(2, 0x2E, arg0);
            M2C_FIELD(temp_v0, s8*, 0) = 0x41;
            M2C_FIELD(temp_v0, s8*, 1) = 0x20;
            M2C_FIELD(temp_v0, s32*, 8) = (s32)M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(temp_v0, s32*, 0xC) = (s32)M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(temp_v0, s32*, 0x3C) = (s32)M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(temp_v0, u16*, 0x40) = (u16)M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(temp_v0, u16*, 0x42) = (u16)M2C_FIELD(arg0, u16*, 0x42);
            M2C_FIELD(temp_v0, u8*, 0x14) = (u8)M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(temp_v0, s32*, 0x30) = (s32)M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(temp_v0, u8*, 0x15) = (u8)M2C_FIELD(arg0, u8*, 0x15);
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        set_animation(arg0, 1);
        M2C_FIELD(arg0, s8*, 0x83) = 0x78;
        M2C_FIELD(arg0, u8*, 0x80) = (u8)(M2C_FIELD(arg0, u8*, 0x80) & 0xFD);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F1C7C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800F1D64(struct ObjectHeader* arg0) {
    if (arg0->state == 4) {
        func_8002CA54();
        return;
    }
    ((M2C_UNK(*)())func_8002CA14)();
}

#define func_80041AB8 func_800F1DA4
#define D_80075FD8 D_800F8F70
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F1DE0);
// clang-format on

#define func_800EB4D4 func_800F1E98
#include "../shared/rock_06/func_800EB4D4.c"
#undef func_800EB4D4

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F1F60(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007555C;
extern u8 D_800970B4;
extern u16 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)
extern M2C_UNK D_800F908C;
extern M2C_UNK D_800F952C;
extern s16 D_800F9868;
extern s16 D_800F986A;
extern s32 D_800F9874;
extern M2C_UNK func_800F9088;

#define SP_9C (*(s32**)0x1F80009C)

void func_800F1F80(void* arg0) {
    s32* p;
    s32 t;
    s8 st;

    if (D_800CCEDC == 0xC) {
        p = SP_9C;
        t = *p;
        M2C_FIELD(arg0, s16*, 0x42) = 0x7948;
        M2C_FIELD(arg0, void**, 0x3C) = (s8*)p + t;
    }
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007555C;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F952C;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, void**, 0x50) = 0;
    M2C_FIELD(arg0, void**, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    set_animation(arg0, 2);
    st = M2C_FIELD(arg0, s8*, 2);
    if (st == 0) {
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 0x8A) = -1;
        M2C_FIELD(arg0, u8*, 0x8B) = 0;
        M2C_FIELD(arg0, u8*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        D_800F9874 = 0;
        M2C_FIELD(arg0, void**, 0x50) = &func_800F9088;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F908C;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        D_800F9868 = 0;
        D_800F986A = 0;
        M2C_FIELD(arg0, u8*, 4) = 1;
        M2C_FIELD(arg0, u8*, 5) = 2;
    } else if (st == 1) {
        M2C_FIELD(arg0, u8*, 0x5C) = 0x18;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 5) = 2;
    } else if (st == 2) {
        M2C_FIELD(arg0, u8*, 0x5C) = 0x18;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 5) = 3;
    } else if (st == 3) {
        M2C_FIELD(arg0, u8*, 0x5C) = 0x18;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 4) = st;
        M2C_FIELD(arg0, u8*, 5) = 4;
    }
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
}
#undef D_800CCEDC

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_80030ECC();
s32 check_enemy_hits(void*);
void func_800F66FC(void*);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_8007555C;
extern s8 D_8009711A;
extern void (*D_800F95E0[])(void*);
extern s32 D_800F9874;

void func_800F213C(void* arg0) {
    s32 r;
    s8 st;
    u16 t;

    func_80017A04();
    D_800F95E0[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800F66FC(arg0);
    if (M2C_FIELD(arg0, s8*, 5) != 2 && M2C_FIELD(arg0, s8*, 2) == 0) {
        D_800F9874++;
    }
    r = check_enemy_hits(arg0);
    if (r < 0) {
        D_8009711A = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if ((u32)(r - 0x19) < 2) {
            M2C_FIELD(arg0, s16*, 0x88) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x88) = 0x1E;
        }
        st = M2C_FIELD(arg0, s8*, 5);
        if (st == 8) {
            if (r == 7 || r == 0x10 || r == 0x2B) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, s16*, 0x88) = 0x78;
            }
        } else if (st == 7) {
            if (r == 7 || r == 0x10 || r == 0x2B) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, s16*, 0x88) = 0x78;
            } else if (M2C_FIELD(arg0, s8*, 0x8D) == 1 && r == 0x24) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, s16*, 0x88) = 0x2710;
                M2C_FIELD(arg0, s8*, 5) = 9;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        } else if (r == 7 || r == 0x10 || r == 0x2B) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, s16*, 0x88) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 3;
            M2C_FIELD(arg0, s8*, 6) = 0;
        }
    }
    t = M2C_FIELD(arg0, u16*, 0x88);
    if (M2C_FIELD(arg0, s16*, 0x88) != 0) {
        M2C_FIELD(arg0, s16*, 0x88) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x88) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007555C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F2340);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern s16 D_800970AA;
extern M2C_UNK D_800F907C;
extern s32 D_800F986C;
extern s32 D_800F9870;

void func_800F2468(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 m;
    u16 x;

    move_object(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (96/98)
        register s32 f asm("$2") = self->unk15;
        if (f == 0) {
            x = self->x_pos.u.hi;
            if (D_800970AA < self->x_pos.i.hi) {
                m = self->unk70 & 2;
                goto check;
            }
        } else {
            x = self->x_pos.u.hi;
            if (D_800970AA <= self->x_pos.i.hi) {
                goto set;
            }
            m = self->unk70 & 1;
        check:
            if (m == 0) {
                goto body;
            }
        }
    }
set:
    ((void (*)(void*, s32, u16))set_animation)(arg0, 0x27, x);
    self->input.buttons.held = 0x5A;
    self->attacking = 0;
    self->unk68 = (void*)&D_800F907C;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_pos.u.hi -= 0x1C;
    self->y_vel.val = D_800F986C;
    self->unk2C = D_800F9870;
    self->unk6 += 1;
    return;
body:
    if (!(D_80097420.frame_counter & 7)) {
        if (self->unk15 == 0) {
            func_800F6880(arg0, 0x15, x - 0x1E, self->y_pos.u.hi + 0xC);
        } else {
            func_800F6880(arg0, 0x14, x + 0x1E, self->y_pos.u.hi + 0xC);
        }
    }
    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        self->input.buttons.held = 0x32;
        play_sound(2, 0x5F, arg0);
    }
}

#include "../shared/rock_07/func_800F25F0.c"

#include "../shared/rock_07/func_800F2738.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK move_object(void*);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
void func_800F6E48(struct X4_MainObj*);

void func_800F2884(void* arg0) {
    s16 n;

    n = --M2C_FIELD(arg0, u16*, 0x7E);
    if (n == 0) {
        play_sound(2, 0x5E, arg0);
        func_80012D9C(5);
        set_animation_frame(arg0, 0x21, 4);
        M2C_FIELD(arg0, u8*, 0x60) = 4;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x20;
        M2C_FIELD(arg0, s16*, 0x86) = M2C_FIELD(arg0, s16*, 0xE) - 0x48;
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x11, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x12, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        M2C_FIELD(arg0, u8*, 6) += 2;
        return;
    }
    n = --M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0) {
        M2C_FIELD(arg0, u8*, 3) = 1;
        func_800F6E48((struct X4_MainObj*)arg0);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x50000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x50000;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    move_object(arg0);
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK move_object(void*);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern s16 D_800970AA;

void func_800F2A04(void* arg0) {
    s16 n;
    s32 v;

    n = --M2C_FIELD(arg0, u16*, 0x7E);
    if (n == 0) {
        play_sound(2, 0x5E, arg0);
        func_80012D9C(5);
        set_animation_frame(arg0, 0x21, 4);
        M2C_FIELD(arg0, u8*, 0x60) = 4;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x20;
        M2C_FIELD(arg0, s16*, 0x86) = M2C_FIELD(arg0, s16*, 0xE) - 0x48;
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x20);
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x20);
        func_800F6880(arg0, 0x11, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x20);
        func_800F6880(arg0, 0x12, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x20);
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    if (n == 0x1B || n == 0x57) {
        play_sound(2, 0x5F, arg0);
    }
    {
        ((void (*)(void*))move_object)(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            if (D_800970AA < M2C_FIELD(arg0, s16*, 0xA)) {
                v = M2C_FIELD(arg0, u8*, 0x70) & 2;
            } else {
                goto back;
            }
        } else if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            v = M2C_FIELD(arg0, u8*, 0x70) & 1;
        } else {
            goto back;
        }
        if (v != 0) {
        back:
            M2C_FIELD(arg0, s16*, 0x7C) = 4;
            M2C_FIELD(arg0, u8*, 6) -= 1;
            return;
        }
        if (!(D_80097420.frame_counter & 3)) {
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                func_800F6880(arg0, 0x15, M2C_FIELD(arg0, s16*, 0xA) - 8,
                              M2C_FIELD(arg0, s16*, 0xE) + 8);
            } else {
                func_800F6880(arg0, 0x14, M2C_FIELD(arg0, s16*, 0xA) + 8,
                              M2C_FIELD(arg0, s16*, 0xE) + 8);
            }
        }
    }
}

#include "../shared/rock_07/func_800F2C38.c"

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];

void func_800F2D98(void* arg0) {
    s32 n;
    s32 d;

    if (!(--M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
        func_800F6880(arg0, 0x10, background_objects[0].unk26 + 0xF0,
                      background_objects[0].unk2A + 0xE0);
    }
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 0xF)) {
        play_sound(2, 0x5E, arg0);
        func_80012D9C(5);
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) < 0x3D) {
        if (!(M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
            func_8002943C(2, 4, 2);
        }
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            set_animation(arg0, 0);
            n = 0xB00000;
            d = 0xC80;
            M2C_FIELD(arg0, u8*, 3) = 1;
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xF0;
            M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk2A + 0x110;
            M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
            M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(arg0, s32*, 0x2C) = n / d;
            M2C_FIELD(arg0, s32*, 0x24) = 0x46640;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, u8*, 6) += 1;
        }
    }
}

#include "../shared/rock_07/func_800F2EE4.c"

#include "common.h"
#include "mmx6/x4.h"

void func_800F6948(struct X4_AnimatedObj* self, s32 arg1, s32 arg2);
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

void func_800F3014(struct X4_AnimatedObj* self) {
    s16 x;
    u16 t = D_800970AA;

    self->x_pos.i.hi = t;
    self->y_pos.i.hi = background_objects[0].unk2A + 0x80;
    if ((s16)t > background_objects[0].unk26 + 0xB0) {
        self->unk15 = 0x40;
        self->x_pos.i.hi = t - 0x70;
    } else {
        self->unk15 = 0;
        self->x_pos.i.hi = t + 0x70;
    }
    x = self->x_pos.i.hi;
    if (x < background_objects[0].unk26 + 0x28) {
        self->x_pos.i.hi = background_objects[0].unk26 + 0x28;
    } else if (background_objects[0].unk26 + 0x138 < x) {
        self->x_pos.i.hi = background_objects[0].unk26 + 0x138;
    }
    if (self->y_pos.i.hi < background_objects[0].unk2A + 0x20) {
        self->y_pos.i.hi = background_objects[0].unk2A + 0x20;
    }
    func_800F6948(self, 0x20, 0xA00);
    func_800F6948(self, 0x20, 0);
    func_800F6948(self, 0x20, 0x600);
    func_800F6948(self, 0x20, 0xAC8);
    func_800F6948(self, 0x20, 0xC8);
    func_800F6948(self, 0x20, 0x6C8);
    func_800F6948(self, 0x20, 0xB90);
    func_800F6948(self, 0x20, 0x190);
    func_800F6948(self, 0x20, 0x790);
    self->unk6++;
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F6C70(void*, s16, s16, s16);
extern struct X4_PlayerObj g_Player;

void func_800F3180(void* arg0) {
    s16 x;
    s16 y;
    s32 ang;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        x = M2C_FIELD(arg0, s16*, 0xA);
        y = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            x -= 0x10;
        } else {
            x += 0x10;
        }
        y += 0x34;
        do {
            ang = ratan2(y - g_Player.y_pos.i.hi, g_Player.x_pos.i.hi - x);
            play_sound(2, 0x63, arg0);
        } while (0);
        {
            // !FAKE: depin: dropping it breaks the match (66/68)
            register void* a asm("$4") = arg0;
            func_800F6C70(a, ang - 0x1C7, x, y);
        }
        func_800F6C70(arg0, ang, x, y);
        func_800F6C70(arg0, ang + 0x1C7, x, y);
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800F6D4C(void*, s32);
extern u8 D_800CCF5F;
extern u8 D_800E9A7C[];
extern s16 D_800F986A;

void func_800F3290(void* arg0) {
    s8 tbl[4];
    s8 n;
    s32 step;
    s16 ang;
    s16 i;

    __builtin_memcpy((u8*)tbl, (u8*)D_800E9A7C, 4);
    if (M2C_FIELD(arg0, s16*, 0x7E) != 0) {
        M2C_FIELD(arg0, s16*, 0x7E)--;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        n = tbl[D_800CCF5F];
        M2C_FIELD(arg0, u8*, 7) = 0;
        D_800F986A = 0;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            ang = 0xBE2;
            step = -0x3C4 / (n - 1);
        } else {
            ang = 0xC1E;
            step = 0x3C4 / (n - 1);
        }
        play_sound(2, 0x64, arg0);
        for (i = 0; i < n; i++) {
            func_800F6D4C(arg0, ang);
            ang += step;
        }
        M2C_FIELD(arg0, s16*, 0x86) = D_800F986A;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F33F8);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
s32 random_byte();                   /* extern */
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern s32 D_800F9788;
extern void* D_800F9878;

void func_800F35A8(void* arg0) {
    s32 type;
    s8 sub;
    s8 one;
    s32 r;

    one = M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 4);
    if (one != 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    sub = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s8*, 0x60) = 0;
    M2C_FIELD(arg0, s8*, 0x5C) = one;
    M2C_FIELD(arg0, s8*, 0x16) = 4;
    M2C_FIELD(arg0, s8*, 0x67) = one;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = one;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s8*, 0x94) = 0;
    type = sub & 0xF0;
    M2C_FIELD(arg0, s8*, 0x96) = 0;
    if (type == 0) {
        set_animation(arg0, 9);
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        {
            // !FAKE: depin: dropping it breaks the match (139/141)
            register s32 dir asm("$2");
            dir = M2C_FIELD(arg0, u8*, 0x15);
            if (dir == 0) {
                M2C_FIELD(arg0, u16*, 0xA) -= 0x20;
            } else {
                M2C_FIELD(arg0, u16*, 0xA) += 0x20;
            }
        }
        M2C_FIELD(arg0, s8*, 5) = 1;
    } else if (type == 0x10) {
        M2C_FIELD(arg0, s8*, 0x60) = 0;
        M2C_FIELD(arg0, s8*, 0x5C) = one;
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 5) = 0;
    } else if (type == 0x20) {
        M2C_FIELD(arg0, s8*, 0x60) = 0;
        M2C_FIELD(arg0, s8*, 0x5C) = one;
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 5) = 2;
    } else if (type == 0x30) {
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        if (sub == type) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x17);
            D_800F9878 = arg0;
            M2C_FIELD(arg0, s8*, 0x16) = 4;
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                M2C_FIELD(arg0, u16*, 0xA) -= 0x90;
                M2C_FIELD(arg0, u16*, 0xE) += 0x2D;
            } else {
                M2C_FIELD(arg0, u16*, 0xA) += 0x90;
                M2C_FIELD(arg0, u16*, 0xE) += 0x2D;
            }
            M2C_FIELD(arg0, s8*, 5) = 3;
        } else {
            M2C_FIELD(arg0, s32**, 0x50) = &D_800F9788;
            M2C_FIELD(arg0, s8*, 5) = 4;
        }
    } else if (type == 0x40) {
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        set_animation(arg0, 0x14);
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        M2C_FIELD(arg0, s8*, 5) = 5;
    } else if (type == 0x50) {
        M2C_FIELD(arg0, s8*, 0x96) = one;
        set_animation(arg0, 0x1B);
        r = random_byte();
        M2C_FIELD(arg0, s32**, 0x58) = D_800741FC;
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        M2C_FIELD(arg0, s8*, 0x5C) = one;
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        M2C_FIELD(arg0, s8*, 5) = 6;
        M2C_FIELD(arg0, s8*, 2) = (u8)M2C_FIELD(arg0, s8*, 2) + (r & 3);
    }
}

#include "../shared/rock_07/func_800F37DC.c"

#include "../shared/rock_07/func_800F3988.c"

#include "../shared/rock_07/func_800F3B9C.c"

#include "common.h"

void func_800F6B94(u8* arg0, u8 arg1, s16 arg2, s16 arg3);

void func_800F3C80(u8* self) {
    u8* parent = *(u8**)(self + 0x8C);

    if (*(s8*)(parent + 4) != 3) {
        self[4] = 2;
        self[3] = 0;
        return;
    }
    self[3] = parent[3];
    if (*(u16*)(parent + 0x42) & 0x8000) {
        *(u16*)(self + 0x42) |= 0x8000;
    } else {
        *(u16*)(self + 0x42) &= 0x7FFF;
    }
    if (self[0x15] == 0) {
        switch (*(s8*)(self + 0x45)) {
        case 1:
            func_800F6B94(self, 0x31, *(s16*)(self + 0xA) + 0x70,
                          *(s16*)(self + 0xE) - 0x38);
            break;
        case 2:
            func_800F6B94(self, 0x32, *(s16*)(self + 0xA) + 0x50,
                          *(s16*)(self + 0xE) - 0x28);
            break;
        case 3:
            func_800F6B94(self, 0x33, *(s16*)(self + 0xA) + 0x30,
                          *(s16*)(self + 0xE) - 0x18);
            break;
        case 4:
            func_800F6B94(self, 0x34, *(s16*)(self + 0xA) + 0x10,
                          *(s16*)(self + 0xE) - 0x8);
            break;
        case 5:
            func_800F6B94(self, 0x35, *(s16*)(self + 0xA) - 0x10,
                          *(s16*)(self + 0xE) + 0x8);
            break;
        case 6:
            func_800F6B94(self, 0x36, *(s16*)(self + 0xA) - 0x30,
                          *(s16*)(self + 0xE) + 0x18);
            break;
        case 7:
            func_800F6B94(self, 0x37, *(s16*)(self + 0xA) - 0x50,
                          *(s16*)(self + 0xE) + 0x28);
            break;
        case 16:
            *(s16*)(self + 0x88) = 0x3C;
            self[6]++;
            break;
        }
    } else {
        switch (*(s8*)(self + 0x45)) {
        case 1:
            func_800F6B94(self, 0x31, *(s16*)(self + 0xA) - 0x70,
                          *(s16*)(self + 0xE) - 0x38);
            break;
        case 2:
            func_800F6B94(self, 0x32, *(s16*)(self + 0xA) - 0x50,
                          *(s16*)(self + 0xE) - 0x28);
            break;
        case 3:
            func_800F6B94(self, 0x33, *(s16*)(self + 0xA) - 0x30,
                          *(s16*)(self + 0xE) - 0x18);
            break;
        case 4:
            func_800F6B94(self, 0x34, *(s16*)(self + 0xA) - 0x10,
                          *(s16*)(self + 0xE) - 0x8);
            break;
        case 5:
            func_800F6B94(self, 0x35, *(s16*)(self + 0xA) + 0x10,
                          *(s16*)(self + 0xE) + 0x8);
            break;
        case 6:
            func_800F6B94(self, 0x36, *(s16*)(self + 0xA) + 0x30,
                          *(s16*)(self + 0xE) + 0x18);
            break;
        case 7:
            func_800F6B94(self, 0x37, *(s16*)(self + 0xA) + 0x50,
                          *(s16*)(self + 0xE) + 0x28);
            break;
        case 16:
            *(s16*)(self + 0x88) = 0x3C;
            self[6]++;
            break;
        }
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern struct X4_PlayerObj g_Player;
extern s32 D_800F97A0;

void func_800F3F94(void* arg0) {
    struct X4_PlayerObj* p;
    s32 ang;
    s32 t;
    s32 pad[4];

    if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F97A0;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s16*, 0x88) = 0x22;
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    }
    p = &g_Player;
    {
        s32 px = p->x_pos.i.hi;
        s32 py = p->y_pos.i.hi;
        ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                     px - M2C_FIELD(arg0, s16*, 0xA));
    }
    switch (M2C_FIELD(arg0, u8*, 0x2) & 0xF) {
    case 0:
        M2C_FIELD(arg0, s32*, 0x20) = (rcos(ang) * 16) >> 1;
        M2C_FIELD(arg0, s32*, 0x24) = (rsin(ang) * 16) >> 1;
        break;
    case 1:
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x24) = rsin(ang) * 16;
        break;
    case 2:
        t = rcos(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x20) = ((t << 1) + t) >> 1;
        t = rsin(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x24) = ((t << 1) + t) >> 1;
        break;
    case 3:
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) * 32;
        M2C_FIELD(arg0, s32*, 0x24) = rsin(ang) * 32;
        break;
    }
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    move_object(arg0);
}

#include "../shared/rock_07/func_800F4144.c"

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F4230);
// clang-format on

#define func_80041AB8 func_800F428C
#define D_80075FD8 D_800F9608
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/rock_07/func_800F42C8.c"

#define func_800F2FB0 func_800F4360
#include "../shared/rock_04/func_800F2FB0.c"
#undef func_800F2FB0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800F4454(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 7) = 0;
    }
    ((M2C_UNK(*)())clear_object_slot)();
}

#define func_8003744C func_800F4490
#define D_80073C1C D_800F96A8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F44CC(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F4948 func_800F4504
#define g_playthrough_state g_playthrough_state
#include "../shared/rock_04/func_800F4948.c"
#undef func_800F4948
#undef g_playthrough_state

#include "../shared/rock_07/func_800F45A0.c"

#include "../shared/rock_07/func_800F4674.c"

#include "../shared/rock_07/func_800F46CC.c"

#include "../shared/rock_07/func_800F472C.c"

#define func_800F4BA8 func_800F47C8
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800F480C(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4D48 func_800F4848
#include "../shared/rock_04/func_800F4D48.c"
#undef func_800F4D48

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800F33F8(s32); /* extern */

void func_800F48CC(s32 arg0) {
    func_8003D330();
    func_800F33F8(arg0);
}

#define func_8003744C func_800F48F8
#define D_80073C1C D_800F96D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK silence_sound(M2C_UNK, M2C_UNK);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F4144(void* arg0);
extern M2C_UNK D_800F907C;

void func_800F4934(u8* arg0) {
    s32 t;
    // !FAKE: depin: dropping it breaks the match (36/41)
    register s32 v asm("$2");

    silence_sound(2, 0x14);
    play_sound(2, 0x21, arg0);
    play_sound(2, 0x77, arg0);
    func_800F4144(arg0);
    set_animation(arg0, 0x25);
    t = *(s8*)(arg0 + 0x8E);
    v = 4;
    arg0[0x60] = v;
    v = 1;
    if (t == v) {
        arg0[0x8E] = 0;
        *(s32**)(arg0 + 0x68) = &D_800F907C;
        *(u16*)(arg0 + 0xE) -= 0x1C;
    }
    *(s16*)(arg0 + 0x7C) = 0x5A;
    arg0[6]++;
}

#include "../shared/rock_07/func_800F49D8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_800F6E78(void*);

void func_800F4A18(struct X4_MainObj* self) {
    if (self->collision_flags & 8) {
        play_sound(2, 0x14, self);
        play_sound(2, 0x5C, self);
        func_800F6E78(self);
        set_animation(self, 2);
        {
            // !FAKE: increment temp register
            register s32 t asm("$2") = (u8)self->unk6 + 1;
            self->unk7C = 0x32;
            self->unk6 = t;
        }
        return;
    }
    func_8002D230(self);
}

#include "../shared/rock_07/func_800F4A9C.c"

#define func_8003744C func_800F4AD8
#define D_80073C1C D_800F96E4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_07/func_800F4B14.c"

#include "../shared/rock_07/func_800F4BE4.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002D230(void*);                /* extern */

void func_800F4C28(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        play_sound(2, 0x5C, arg0);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    func_8002D230(arg0);
}

#define func_800F4A9C func_800F4C88
#include "../shared/rock_07/func_800F4A9C.c"
#undef func_800F4A9C

#define func_8003744C func_800F4CC4
#define D_80073C1C D_800F9614
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 random_byte();
void func_800F6E48(struct X4_MainObj*);

void func_800F4D00(struct X4_MainObj* arg0) {
    s32 v;
    s32 g;

    set_animation(arg0, 0xD);
    func_800F6E48(arg0);
    v = (u8)((u32)random_byte() % 15) + 0xA;
    g = 0x460000 / ((v * v) >> 1);
    arg0->gravity = g;
    arg0->x_speed = 0;
    arg0->x_accel = 0;
    arg0->y_speed = g * v;
    func_8002D230(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (41/44)
        register s32 t asm("$2") = (u8)arg0->unk6 + 1;
        arg0->unk6 = t;
    }
}

#include "../shared/rock_07/func_800F4DB0.c"

#include "../shared/rock_07/func_800F4DFC.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern M2C_UNK D_800F9080;

void func_800F4E4C(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 v;

    if (M2C_FIELD(self, s8*, 0x45) != 0) {
        play_sound(2, 0x5F, arg0);
        v = 0x40000;
        if (self->unk15 == 0) {
            v = 0xFFFC0000;
        }
        self->x_vel.val = v;
        self->unk68 = (void*)&D_800F9080;
        {
            s32 t = 1;
            self->attacking = t;
            t = 0x32;
            self->input.buttons.held = t;
        }
        self->unk28 = 0;
        self->y_vel.val = 0;
        self->unk2C = 0;
        self->y_pos.u.hi += 0x1C;
        self->unk6 += 1;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F4EE0);
// clang-format on

#define func_8003744C func_800F4F1C
#define D_80073C1C D_800F962C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E48(struct X4_MainObj*);

void func_800F4F58(struct X4_MainObj* arg0) {
    play_sound(2, 0x5B, arg0);
    set_animation(arg0, 3);
    func_800F6E48(arg0);
    *((u8*)arg0 + 6) = *((u8*)arg0 + 6) + 1;
}

#include "../shared/rock_07/func_800F4FA8.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_800F6E48(struct X4_MainObj*);

void func_800F5094(void* arg0) {
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
        func_800F6E48(arg0);
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 8);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F6A1C(void* arg0, s32 arg1);

void func_800F50EC(void* arg0) {
    s8 mode = ((s8*)arg0)[0x45];
    u8 r;

    if (mode == 1) {
        r = (u32)random_byte() % 3;
        if (r != mode) {
            switch (r) {
            case 0:
                play_sound(2, 0x22, arg0);
                break;
            case 1:
                break;
            case 2:
                goto two;
            }
        } else {
            play_sound(2, 0x23, arg0);
            if (0) {
            two:
                play_sound(2, 0x24, arg0);
            }
        }
        play_sound(2, 0x5D, arg0);
        func_800F6A1C(arg0, 0);
    } else if (mode == 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 6);
        ((u8*)arg0)[6]++;
    }
}

#include "../shared/rock_07/func_800F51F0.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F33F8(); /* extern */

void func_800F5254(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((M2C_UNK(*)())func_800F33F8)();
    }
}

#define func_8003744C func_800F5284
#define D_80073C1C D_800F9644
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E48(struct X4_MainObj*);

void func_800F52C0(void* arg0) {
    set_animation(arg0, 0xA);
    func_800F6E48(arg0);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}

#include "../shared/rock_07/func_800F52FC.c"

#include "../shared/rock_07/func_800F53C8.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F5430(void* arg0) {
    if (F(u8, 0x70) & 8) {
        play_sound(2, 0x5E, arg0);
        func_80012D9C(5);
        func_8002943C(0x32, 3, 2);
        set_animation(arg0, 0xC);
        func_800F6880(arg0, 0x10, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x10, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x11, F(s16, 0xA), F(s16, 0xE) + 0x20);
        func_800F6880(arg0, 0x12, F(s16, 0xA), F(s16, 0xE) + 0x20);
        F(u8, 6)++;
        return;
    }
    move_object(arg0);
}

#undef F

#include "../shared/rock_07/func_800F5530.c"

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F5580);
// clang-format on

#define func_8003744C func_800F55BC
#define D_80073C1C D_800F9660
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E48(struct X4_MainObj*);

void func_800F55F8(struct X4_MainObj* arg0) {
    play_sound(2, 0x5B, arg0);
    set_animation(arg0, 0xF);
    func_800F6E48(arg0);
    *((u8*)arg0 + 6) = *((u8*)arg0 + 6) + 1;
}

#include "../shared/rock_07/func_800F5648.c"

#include "../shared/rock_07/func_800F56F0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
void func_800F9084();

void func_800F5764(struct X4_MainObj* self) {
    s8 t;
    s32 v;
    s32 w;

    if (!(D_80097420.frame_counter & 3)) {
        func_800F6880(self, 0x10, self->x_pos.i.hi, self->y_pos.u.hi + 0x30);
    }
    t = self->animation_step.fields.event;
    if (t == 1) {
        set_animation(self, 0x21);
        v = 4;
        self->contact_damage = v;
        v = 0xB4;
        self->unk7E = v;
        v = (s32)func_800F9084;
        self->terrain_box = (void*)v;
        v = self->y_pos.u.hi;
        w = 0x5A;
        self->unk7C = w;
        w = (u8)self->unk6;
        self->on_screen = 0;
        *((u8*)self + 0x8D) = t;
        self->y_pos.u.hi = v + 0x20;
        self->unk6 = w + 1;
    }
}

#include "../shared/rock_07/func_800F5814.c"

#define func_800F51F0 func_800F5884
#include "../shared/rock_07/func_800F51F0.c"
#undef func_800F51F0

#include "../shared/rock_07/func_800F58E8.c"

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F5934);
// clang-format on

#define func_8003744C func_800F5970
#define D_80073C1C D_800F968C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_07/func_800F59AC.c"

#include "../shared/rock_07/func_800F5A1C.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
void func_800F67D0(void*, s32);
extern s8 D_800970A2;
extern u8 D_800CCF38;

void func_800F5AA8(u8* arg0) {
    s8 state = *(s8*)(arg0 + 0x45);

    if (state == 1) {
        if (D_800CCF38 >= 2 && (random_byte() & 1)) {
            play_sound(2, 0x29, arg0);
            func_800F67D0(arg0, 3);
        } else if (D_800970A2 == 0) {
            play_sound(2, 0x28, arg0);
            func_800F67D0(arg0, 2);
        } else {
            play_sound(2, 0x27, arg0);
            func_800F67D0(arg0, 1);
        }
        arg0[7] = 1;
        arg0[6]++;
    } else if (state == 2) {
        play_sound(2, 0x60, arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK silence_sound(M2C_UNK, M2C_UNK); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);   /* extern */

void func_800F5B9C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        silence_sound(2, 0x14);
        set_animation(arg0, 4);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x105D;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F51F0 func_800F5C00
#include "../shared/rock_07/func_800F51F0.c"
#undef func_800F51F0

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F33F8(); /* extern */

void func_800F5C64(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((M2C_UNK(*)())func_800F33F8)();
    }
}

#include "common.h"

void func_800F5C94(void) {
}

#define func_8003744C func_800F5C9C
#define D_80073C1C D_800F9708
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_07/func_800F5CD8.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F5D28(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
void func_800F4144(void* arg0);
extern s16 D_800F9868;

void func_800F5D3C(void* arg0) {
    if (D_800F9868 == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x61, arg0);
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        func_800F4144(arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0x23);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E78(void*);

void func_800F5DA4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_800F6E78(arg0);
        set_animation(arg0, 0x15);
        {
            // !FAKE: depin: dropping it breaks the match (18/21)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}

#include "../shared/rock_07/func_800F5DF8.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
void func_800F6AD0(u8* arg0, u8 arg1);

#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800F5E48(void* arg0) {
    if (--F16(arg0, 0x7C) == 0) {
        play_sound(2, 0x62, arg0);
        set_animation_frame(arg0, 0x16, 1);
        func_800F6AD0(arg0, 0x30);
        F8(arg0, 6) += 1;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F5EBC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "../shared/rock_07/func_800F5EEC.c"

#define func_8003744C func_800F5F7C
#define D_80073C1C D_800F972C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800F5CD8 func_800F5FB8
#define D_800E9A70 D_800E9A70
#include "../shared/rock_07/func_800F5CD8.c"
#undef func_800F5CD8
#undef D_800E9A70

#include "common.h"
#include "mmx6/x4.h"

void func_800F6948(struct X4_AnimatedObj* self, s32 arg1, s32 arg2);
extern struct X4_BackgroundObj background_objects[3];

void func_800F6008(struct X4_AnimatedObj* self) {
    if (background_objects[0].unk26 + 0xB0 < self->x_pos.i.hi) {
        self->x_pos.i.hi = background_objects[0].unk26 + 0x50;
        self->unk15 = 0x40;
    } else {
        self->x_pos.i.hi = background_objects[0].unk26 + 0x110;
        self->unk15 = 0;
    }
    self->y_pos.i.hi = background_objects[0].unk2A + 0x10;
    func_800F6948(self, 0x20, 0xA00);
    func_800F6948(self, 0x20, 0);
    func_800F6948(self, 0x20, 0x600);
    func_800F6948(self, 0x20, 0xAC8);
    func_800F6948(self, 0x20, 0xC8);
    func_800F6948(self, 0x20, 0x6C8);
    func_800F6948(self, 0x20, 0xB90);
    func_800F6948(self, 0x20, 0x190);
    func_800F6948(self, 0x20, 0x790);
    self->unk6++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
void func_800F4144(void* arg0);
extern s16 D_800F9868;

void func_800F6118(void* arg0) {
    if (D_800F9868 == 0) {
        play_sound(2, 0x61, arg0);
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        func_800F4144(arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0x22);
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E78(void*);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F6180(void* arg0) {
    if (F(s8, arg0, 0x45) == 1) {
        ((void (*)())func_800F6E78)();
        set_animation(arg0, 0x12);
        {
            // !FAKE: depin: dropping it breaks the match (18/21)
            register s32 v asm("$2") = F(u8, arg0, 6) + 1;
            F(u8, arg0, 6) = v;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F90C0;
extern s32 D_800F90C4;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F61D4(void* arg0) {
    set_animation(arg0, 0x13);
    {
        // !FAKE: depin: dropping it breaks the match (15/19)
        register s32* a asm("$2") = &D_800F90C0;
        F(s32*, arg0, 0x50) = a;
    }
    {
        // !FAKE: depin: dropping it breaks the match (12/19)
        register s32* b asm("$3") = &D_800F90C4;
        F(s32*, arg0, 0x54) = b;
    }
    F(u8, arg0, 6)++;
}

#include "../shared/rock_07/func_800F6220.c"

#include "../shared/rock_07/func_800F62AC.c"

#define func_8003744C func_800F6318
#define D_80073C1C D_800F974C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_07/func_800F6354.c"

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
void func_800F6948(struct X4_AnimatedObj* self, s32 arg1, s32 arg2);

void func_800F63AC(struct X4_AnimatedObj* self) {
    if (background_objects[0].unk26 + 0xB0 < self->x_pos.i.hi) {
        self->x_pos.i.hi = background_objects[0].unk26 + 0x40;
        self->unk15 = 0x40;
    } else {
        self->x_pos.i.hi = background_objects[0].unk26 + 0x120;
        self->unk15 = 0;
    }
    self->y_pos.i.hi = background_objects[0].unk2A + 0x40;
    func_800F6948(self, 0x20, 0xA00);
    func_800F6948(self, 0x20, 0);
    func_800F6948(self, 0x20, 0x600);
    func_800F6948(self, 0x20, 0xAC8);
    func_800F6948(self, 0x20, 0xC8);
    func_800F6948(self, 0x20, 0x6C8);
    func_800F6948(self, 0x20, 0xB90);
    func_800F6948(self, 0x20, 0x190);
    func_800F6948(self, 0x20, 0x790);
    self->unk6++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
void func_800F4144(void* arg0);
extern s16 D_800F9868;

void func_800F64BC(void* arg0) {
    if (D_800F9868 == 0) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x61, arg0);
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        func_800F4144(arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0x24);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F6E78(void*);

void func_800F6524(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((void (*)())func_800F6E78)();
        ((void (*)(void*, s32))set_animation)(arg0, 0x19);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F90C8;
extern s32 D_800F90CC;

void func_800F6578(u8* arg0) {
    ((void (*)(void*, s32))set_animation)(arg0, 0x1A);
    *(s32**)(arg0 + 0x50) = &D_800F90C8;
    *(s32**)(arg0 + 0x54) = &D_800F90CC;
    arg0[6]++;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define F(p, type, off) M2C_FIELD(p, type*, off)

extern s16 D_800F986A;

void func_800F65C4(void* arg0) {
    s16 v;
    s16 q;

    if (F(arg0, s16, 0x7E) == 0 || --F(arg0, s16, 0x7E) == 0) {
        // !FAKE: depin: dropping it breaks the match (43/50)
        register s32 b asm("$3") = F(arg0, u8, 0x6);
        F(arg0, s16, 0x7C) = 0x1E;
        F(arg0, s32, 0x50) = 0;
        F(arg0, s32, 0x54) = 0;
        F(arg0, u8, 0x7) = 1;
        F(arg0, u8, 0x6) = b + 1;
        return;
    }
    v = F(arg0, u16, 0x86);
    q = v / 3;
    if (v % 3 != 0) {
        q++;
    }
    if (v - D_800F986A >= q) {
        F(arg0, u8, 0x7) = 1;
        F(arg0, u8, 0x6) -= 2;
    }
}

#undef F
#undef M2C_FIELD

#include "../shared/rock_07/func_800F668C.c"

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", func_800F66FC);
// clang-format on

#include "../shared/rock_07/func_800F67D0.c"

#include "../shared/rock_07/func_800F6880.c"

#include "common.h"
#include "mmx6/x4.h"

#define F32_AT(p, off) (*(X4_f32*)((u8*)(p) + (off)))

void* func_8002C458();
extern s16 D_800F9868;

void func_800F6948(struct X4_AnimatedObj* self, s32 arg1, s32 arg2) {
    struct X4_AnimatedObj* obj;
    u8 id = arg1;

    obj = func_8002C458();
    if (obj != 0) {
        obj->active = 0x41;
        obj->id = 0x16;
        obj->unk2 = id;
        obj->unk42 = self->unk42 & 0x7FFF;
        obj->animation_table = self->animation_table;
        obj->unk3C = self->unk3C;
        obj->unk40 = self->unk40;
        obj->unk15 = self->unk15;
        obj->bg_offset = self->bg_offset;
        F32_AT(obj, 0x84).val = arg2;
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->x_pos.i.lo = 0;
        obj->y_pos.i.hi = self->y_pos.i.hi;
        obj->y_pos.i.lo = 0;
        F32_AT(obj, 0x7C).val = F32_AT(self, 0x80).val;
        D_800F9868 += 1;
    }
}

#include "../shared/rock_07/func_800F6A1C.c"

#include "../shared/rock_07/func_800F6AD0.c"

#include "../shared/rock_07/func_800F6B94.c"

#include "../shared/rock_07/func_800F6C70.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();
extern s16 D_800F986A;

void func_800F6D4C(void* arg0, s32 arg1) {
    void* obj;
    s16 ang;
    u16 cnt;
    s32 t;

    ang = arg1;
    obj = func_8002C458();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0x0) = 0x41;
        M2C_FIELD(obj, u8*, 0x1) = 0x16;
        M2C_FIELD(obj, u8*, 0x2) = 0x50;
        M2C_FIELD(obj, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(obj, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(obj, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(obj, s32*, 0x84) = ang;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(obj, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x24;
        } else {
            M2C_FIELD(obj, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x24;
        }
        M2C_FIELD(obj, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE) - 0xC;
        M2C_FIELD(obj, s16*, 0x8) = 0;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        t = M2C_FIELD(arg0, s32*, 0x80);
        cnt = D_800F986A;
        M2C_FIELD(obj, void**, 0x8C) = arg0;
        M2C_FIELD(obj, s32*, 0x7C) = t;
        D_800F986A = cnt + 1;
    }
}

#define func_80042C18 func_800F6E48
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002A47C(s32);
extern u16 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)

#define SP_20 (*(s8**)0x1F800020)
#define SP_9C (*(s8**)0x1F80009C)

void func_800F6E78(void* arg0) {
    s32 a;
    s32 b;
    s32 c;
    s8* p;

    M2C_FIELD(arg0, s16*, 0x40) = 0x140;
    if (D_800CCEDC != 0xC) {
        a = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        b = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        M2C_FIELD(arg0, s16*, 0x42) =
            ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
        c = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        M2C_FIELD(arg0, s8**, 0x3C) = SP_20 + ((s32*)SP_20)[c];
    } else {
        p = SP_9C;
        c = ((s32*)p)[0];
        M2C_FIELD(arg0, s16*, 0x42) = 0x7948;
        M2C_FIELD(arg0, s8**, 0x3C) = p + c;
    }
}

#undef D_800CCEDC

#define func_800F54B8 func_800F6F60
#include "../shared/rock_04/func_800F54B8.c"
#undef func_800F54B8

#include "../shared/rock_07/func_800F6FA0.c"

#include "common.h"
#define M2C_UNK s32

extern M2C_UNK clear_object_slot();
extern s16 D_800F9868;
extern s16 D_800F986A;

void func_800F7024(u8* arg0) {
    s32 kind;

    kind = *(s8*)(arg0 + 2) & 0xF0;
    if (kind == 0x20) {
        D_800F9868--;
    } else if (kind == 0x50 && arg0[0x96] == 1) {
        D_800F986A--;
    }
    ((M2C_UNK(*)())clear_object_slot)(arg0, kind);
}

#define func_8003744C func_800F7098
#define D_80073C1C D_800F97CC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002D230(); /* extern */

void func_800F70D4(void) {
    ((M2C_UNK(*)())func_8002D230)();
}

#define func_8003744C func_800F70F4
#define D_80073C1C D_800F97D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))
#define OP(p, o) (*(void**)((u8*)(p) + (o)))

extern struct X4_PlayerObj g_Player;
extern s32 D_800F977C;
extern s32 D_800F9780;
extern s32 D_800F9784;

void func_800F7130(void* arg0) {
    s32 angle;
    s32 dx;
    s32 dy;

    OP(arg0, 0x54) = &D_800F977C;
    OP(arg0, 0x50) = &D_800F9780;
    OP(arg0, 0x68) = &D_800F9784;
    dx = g_Player.x_pos.i.hi;
    dy = g_Player.y_pos.i.hi;
    angle = ratan2(OH(arg0, 0xE) - dy, dx - OH(arg0, 0xA));
    OW(arg0, 0x20) = rcos(angle) << 6;
    OW(arg0, 0x24) = rsin(angle) << 6;
    OW(arg0, 0x28) = 0;
    OW(arg0, 0x2C) = 0;
    OUB(arg0, 0x6) = OUB(arg0, 0x6) + 1;
}

#include "../shared/rock_07/func_800F71D8.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F6E48(struct X4_MainObj*);

void func_800F7224(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
        func_800F6E48(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFEB852;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x147AE;
        }
        M2C_FIELD(arg0, s32*, 0x2C) = 0x4189;
        M2C_FIELD(arg0, s32*, 0x24) = 0x66666;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s16*, 0x88) = 9;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "../shared/rock_07/func_800F72BC.c"

#define func_8003744C func_800F73B4
#define D_80073C1C D_800F97E4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_07/func_800F73F0.c"

#define func_8003744C func_800F74C4
#define D_80073C1C D_800F97EC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_07/func_800F7500.c"

#include "../shared/rock_07/func_800F7554.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void* D_800F9878;

void func_800F75D8(void* arg0) {
    if ((M2C_FIELD(M2C_FIELD(arg0, void**, 0x8C), s8*, 4) != 3) ||
        (M2C_FIELD(D_800F9878, s8*, 0x45) < (M2C_FIELD(arg0, u8*, 2) & 0xF))) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_8003744C func_800F7620
#define D_80073C1C D_800F97F8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "psyq/libgte.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

extern s32 D_800F978C;
extern s32 D_800F9790;

void func_800F765C(void* arg0) {
    s32 m;

    B(arg0, 0x3) = 1;
    W(arg0, 0x50) = (s32)&D_800F978C;
    W(arg0, 0x68) = (s32)&D_800F9790;
    m = rcos(W(arg0, 0x84)) * 0x10;
    W(arg0, 0x20) = (m * 2 + m) * 2;
    m = rsin(W(arg0, 0x84)) * 0x10;
    W(arg0, 0x24) = (m * 2 + m) * 2;
    B(arg0, 0x6)++;
}

#include "../shared/rock_07/func_800F76E0.c"

#include "../shared/rock_07/func_800F7748.c"

#include "../shared/rock_07/func_800F777C.c"

#include "../shared/rock_07/func_800F77C8.c"

#include "common.h"
#include "psyq/libgte.h"

extern s32 D_800F9794;
extern s32 D_800F9798;
extern s32 D_800F979C;

void func_800F7820(u8* arg0) {
    s32 m;

    arg0[3] = 1;
    *(s32**)(arg0 + 0x50) = &D_800F9794;
    *(s32**)(arg0 + 0x54) = &D_800F9798;
    *(s32**)(arg0 + 0x68) = &D_800F979C;
    m = rcos(*(s32*)(arg0 + 0x84)) * 0x10;
    *(s32*)(arg0 + 0x20) = m * 2 + m;
    m = rsin(*(s32*)(arg0 + 0x84)) * 0x10;
    *(s32*)(arg0 + 0x24) = m * 2 + m;
    if (*(s32*)(arg0 + 0x20) > 0) {
        arg0[0x15] = 0x40;
    } else {
        arg0[0x15] = 0;
    }
    *(s16*)(arg0 + 0x88) = 0x20;
    arg0[6]++;
}

#include "../shared/rock_07/func_800F78C8.c"

#include "../shared/rock_07/func_800F793C.c"

#include "../shared/rock_07/func_800F7970.c"

// clang-format off
INCLUDE_ASM("asm/rock_07/nonmatchings/E9860", D_800F79D0);
// clang-format on
