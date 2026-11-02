#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);
extern M2C_UNK D_800FD930;
extern M2C_UNK D_800FD9D0;
extern s16 D_800FDA70;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F23D8(void* self) {
    D_800FDA70++;
    func_8002B410(&D_800FD9D0, &D_800FD930, 0x50, D_800FDA70, 0x60);
    load_palette(0x60, &D_800FD9D0, 5);
    if (D_800FDA70 >= 0x60) {
        if (is_text_box_seen(1) == 0) {
            open_text_box(1, 0xFF, 0);
            set_text_box_seen(1);
        }
        F(u8, 6)++;
    }
}

#undef F

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern u8 D_8008EAFC;

void func_800F249C(void* arg0) {
    if (D_8008EAFC == 0) {
        func_800F3E10(arg0, 1);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

void func_800F24E4(void* arg0) {
    if (--H(arg0, 0x7C) == 0) {
        SB(arg0, 0x7) = -1;
        B(arg0, 0x6)++;
    }
}

#include "../shared/rock_11/func_800F2518.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
void func_800F3E10(void* arg0, s32 arg1);
extern M2C_UNK D_800FD530;
extern M2C_UNK D_800FD730;
extern M2C_UNK D_800FD930;
extern M2C_UNK D_800FD9D0;
extern s16 D_800FDA70;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F252C(void* self) {
    F(u8, 7) = 0;
    func_800F3E10(self, 2);
    func_800F3E10(self, 0x10);
    func_800F3E10(self, 0x11);
    func_800F3E10(self, 0x12);
    func_800F3E10(self, 0x13);
    func_8002B410(&D_800FD730, &D_800FD530, 0x100, D_800FDA70, 0x60);
    load_palette(0x3C, &D_800FD730, 0x10);
    func_8002B410(&D_800FD9D0, &D_800FD930, 0x50, D_800FDA70, 0x60);
    load_palette(0x60, &D_800FD9D0, 5);
    F(s16, 0x7C) = 3;
    F(u8, 6)++;
}

#undef F

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F2624(void* arg0) {
    M2C_FIELD(arg0, s8*, 7) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F2638(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800F0050(s32); /* extern */
extern s8 D_800E4480;

void func_800F264C(s32 arg0) {
    D_800E4480 = 0;
    func_8003D330();
    func_800F0050(arg0);
}

#define func_8003744C func_800F2680
#define D_80073C1C D_800FCA70
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */

void func_800F26BC(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 6;
    func_800F3E10(arg0, 0x10);
    func_800F3E10(arg0, 0x11);
    func_800F3E10(arg0, 0x12);
    func_800F3E10(arg0, 0x13);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "../shared/rock_11/func_800F2724.c"

#define func_8003744C func_800F2760
#define D_80073C1C D_800FCA78
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
void func_800F3E10(void* arg0, s32 arg1);

void func_800F279C(void* arg0) {
    M2C_FIELD(arg0, s8*, 7) = 6;
    func_800F3E10(arg0, 0x20);
    func_800F3E10(arg0, 0x21);
    func_800F3E10(arg0, 0x22);
    func_800F3E10(arg0, 0x23);
    func_800F3E10(arg0, 0x24);
    M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
    M2C_FIELD(arg0, s16*, 0x7E) = random_byte() % 3 + 3;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_800F2724 func_800F2840
#include "../shared/rock_11/func_800F2724.c"
#undef func_800F2724

#include "common.h"

void func_800F287C(void) {
}

#define func_8003744C func_800F2884
#define D_80073C1C D_800FCA84
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */

void func_800F28C0(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 6;
    func_800F3E10(arg0, 2);
    func_800F3E10(arg0, 0x10);
    func_800F3E10(arg0, 0x11);
    func_800F3E10(arg0, 0x12);
    func_800F3E10(arg0, 0x13);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */

void func_800F2934(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 7) = 6;
        func_800F3E10(arg0, 0x30);
        func_800F3E10(arg0, 0x31);
        func_800F3E10(arg0, 0x32);
        func_800F3E10(arg0, 0x33);
        func_800F3E10(arg0, 0x34);
        func_800F3E10(arg0, 0x35);
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"

void func_800F4254(void* arg0, u8 arg1);
extern s8 D_800FD51A;
extern s8 D_800FD51B;
extern s8 D_800FD51E;
extern u8 D_800FD522;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F29CC(void* arg0) {
    UB(arg0, 0x7) = 0;
    if (SH(arg0, 0x7C) != 0) {
        if (--SH(arg0, 0x7C) == 0x12) {
            D_800FD51B = 0;
            D_800FD51E = 0;
            D_800FD51A = 0;
            D_800FD522 = 0;
            func_800F4254(arg0, 0x10);
            func_800F4254(arg0, 0x11);
            func_800F4254(arg0, 0x12);
            func_800F4254(arg0, 0x13);
            UB(arg0, 0x6) = UB(arg0, 0x6) + 1;
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern s8 D_800FD51B;

void func_800F2A70(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (D_800FD51B == -3) {
        M2C_FIELD(arg0, u8*, 7) = 6;
        func_800F3E10(arg0, 0x36);
        func_800F3E10(arg0, 0x37);
        func_800F3E10(arg0, 0x38);
        func_800F3E10(arg0, 0x39);
        func_800F3E10(arg0, 0x3A);
        func_800F3E10(arg0, 0x3B);
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#define func_800F2724 func_800F2B08
#include "../shared/rock_11/func_800F2724.c"
#undef func_800F2724

#define func_8003744C func_800F2B44
#define D_80073C1C D_800FCA98
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F0050(s32);               /* extern */
void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern s8 D_800FD51C;
extern s8 D_800FD520;

void func_800F2B80(void* arg0) {
    if (D_800FD520 == 1) {
        func_800F0050((s32)arg0);
        return;
    }
    D_800FD51C = 0;
    M2C_FIELD(arg0, u8*, 7) = 6;
    func_800F3E10(arg0, 2);
    func_800F3E10(arg0, 0x10);
    func_800F3E10(arg0, 0x11);
    func_800F3E10(arg0, 0x12);
    func_800F3E10(arg0, 0x13);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */

void func_800F2C20(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 7) = 6;
        func_800F3E10(arg0, 0x40);
        func_800F3E10(arg0, 0x41);
        func_800F3E10(arg0, 0x42);
        func_800F3E10(arg0, 0x43);
        func_800F3E10(arg0, 0x44);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4254(void* arg0, u8 arg1);

void func_800F2CA8(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    func_800F4254(arg0, 0x40);
    M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */

void func_800F2CE8(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 7) = 6;
        func_800F3E10(arg0, 0x45);
        func_800F3E10(arg0, 0x46);
        func_800F3E10(arg0, 0x47);
        func_800F3E10(arg0, 0x48);
        func_800F3E10(arg0, 0x49);
        {
            // !FAKE: depin: dropping it breaks the match (30/35)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6);
            M2C_FIELD(arg0, s16*, 0x7C) = 0x4B;
            M2C_FIELD(arg0, u8*, 6) = t + 1;
        }
    }
}

#define func_800F2724 func_800F2D74
#include "../shared/rock_11/func_800F2724.c"
#undef func_800F2724

#define func_8003744C func_800F2DB0
#define D_80073C1C D_800FCAAC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800F0050(s32);               /* extern */
void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern u8 D_800CCF38;

void func_800F2DEC(struct X4_MainObj* self) {
    if (D_800CCF38 < 2) {
        func_800F0050((s32)self);
        return;
    }
    self->unk7 = 6;
    func_800F3E10(self, 2);
    func_800F3E10(self, 0x10);
    func_800F3E10(self, 0x11);
    func_800F3E10(self, 0x12);
    func_800F3E10(self, 0x13);
    self->unk7C = 0x28;
    self->unk6++;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F3E10(void* arg0, s32 arg1); /* extern */

void func_800F2E84(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 7) = 6;
        func_800F3E10(arg0, 0x50);
        func_800F3E10(arg0, 0x51);
        func_800F3E10(arg0, 0x52);
        func_800F3E10(arg0, 0x53);
        func_800F3E10(arg0, 0x54);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x6C;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

void func_800F440C(s8 arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800E987C[];

void func_800F2F10(u8* self) {
    u16 pos[4];

    __builtin_memcpy(pos, D_800E987C, 8);
    self[7] = 0;
    switch (--*(s16*)(self + 0x7C)) {
    case 1:
        func_800F440C(0xB, 0x10, background_objects[0].x_pos.u.hi + pos[0],
                      background_objects[0].y_pos.u.hi + pos[1]);
        break;
    case 0:
        func_800F440C(0xB, 0x10, background_objects[0].x_pos.u.hi + pos[2],
                      background_objects[0].y_pos.u.hi + pos[3]);
        *(s16*)(self + 0x7C) = 0x28;
        self[6]++;
        break;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F3010);
// clang-format on

#define func_8003744C func_800F304C
#define D_80073C1C D_800FCABC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);           /* extern */
void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern s8 D_800FD51D;

void func_800F3088(void* arg0) {
    func_80012D9C(7);
    D_800FD51D = 0;
    M2C_FIELD(arg0, u8*, 7) = 6;
    func_800F3E10(arg0, 0x70);
    func_800F3E10(arg0, 0x71);
    func_800F3E10(arg0, 0x72);
    func_800F3E10(arg0, 0x73);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"

s32 func_8002B2F8(s32);
extern s32 D_80090C9C;
extern s8 D_80090D56;
extern s8 D_8009742C;
extern u8 D_800C4560;
extern s8 D_800CF850;

#define F3104(type, off) (*(type*)((u8*)self + (off)))

void func_800F3104(void* self) {
    F3104(u8, 0x7) = 0;
    if (--F3104(s16, 0x7C) == 0) {
        func_8002B2F8(0);
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        D_80090C9C = 0x10000;
        D_800C4560 |= 1;
        F3104(s16, 0x7C) = 3;
        F3104(u8, 0x6)++;
    }
}

#undef F3104

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s16 D_80090D5C;
#include "mmx6/state.h"
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

void func_800F3190(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == -1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 3;
        D_800CF854 += 1;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        D_800C4560 |= 1;
        if ((u16)D_800CF854 >= 0x1F) {
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
    if (D_80097420.frame_counter & 3) {
        func_8002943C(2, 5, 2);
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FB26C[];
extern s8 D_800FD514;
extern s16 D_800FD52A;

#define TB (D_800FB26C + 0xE44)
#define F(type, off) M2C_FIELD(self, type*, off)

void func_800F3254(void* self) {
    s32 r;

    background_objects[0].unk24 = 0x1080;
    background_objects[0].unk28 = D_800FD52A;
    F(s8, 0x6) = 0;
    F(s8, 0x87) = D_800FD514;
    r = random_byte() & 0xF;
    F(s8, 0x85) = r;
    F(s8, 0x86) = 0;
    F(u8, 0x5) = TB[F(s8, 0x87) * 128 + r * 8];
}

#undef F
#undef TB

#define func_8003744C func_800F32D8
#define D_80073C1C D_800FCAD0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);           /* extern */
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);  /* extern */
void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern s8 D_800FD51D;

void func_800F3314(void* arg0) {
    func_80012D9C(7);
    func_8003D308(0x14, 0x40);
    D_800FD51D = 0;
    M2C_FIELD(arg0, u8*, 7) = 6;
    func_800F3E10(arg0, 0x70);
    func_800F3E10(arg0, 0x71);
    func_800F3E10(arg0, 0x72);
    func_800F3E10(arg0, 0x73);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
    M2C_FIELD(arg0, s16*, 0x7E) = 0x3C;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"

s32 func_8002B2F8(s32);
extern s32 D_80090C9C;
extern s8 D_80090D56;
extern s8 D_8009742C;
extern u8 D_800C4560;
extern s8 D_800CF850;

#define F33A4(type, off) (*(type*)((u8*)self + (off)))

void func_800F33A4(void* self) {
    F33A4(u8, 0x7) = 0;
    if (--F33A4(s16, 0x7C) == 0) {
        func_8002B2F8(0);
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        D_80090C9C = 0x10000;
        D_800C4560 |= 1;
        F33A4(s16, 0x7C) = 3;
        F33A4(u8, 0x6)++;
    }
    if (--F33A4(s16, 0x7E) == 0) {
        F33A4(s16, 0x7E) = 0x3C;
    }
}

#undef F33A4

#include "common.h"

void func_80013A48(s8 arg0);

void func_800F3450(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        func_80013A48(0x19);
        {
            // !FAKE: increment temp lands in the second return register as in retail
            register s32 t asm("$3") = arg0[6] + 1;
            arg0[6] = t;
        }
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D330();
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800FD52A;

void func_800F34A4(void* arg0) {
    if (D_80097420.transition.fade_amount == 0) {
        func_8003D330();
        background_objects[0].unk24 = 0x1430;
        background_objects[0].unk28 = D_800FD52A;
        M2C_FIELD(arg0, s8*, 0x4) = 3;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
        M2C_FIELD(arg0, s8*, 0x7) = 0;
    }
}

#define func_8003744C func_800F3508
#define D_80073C1C D_800FCAEC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                   /* extern */
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void func_800F3E10(void* arg0, s32 arg1);         /* extern */
extern s8 D_800FD51D;

void func_800F3544(void* arg0) {
    func_80012D9C(7);
    D_800FD51D = 0;
    func_8002943C(8, 3, 2);
    M2C_FIELD(arg0, s8*, 7) = 6;
    func_800F3E10(arg0, 0x70);
    func_800F3E10(arg0, 0x71);
    func_800F3E10(arg0, 0x72);
    func_800F3E10(arg0, 0x73);
    M2C_FIELD(arg0, s16*, 0x7C) = 0x50;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#define func_8003744C func_800F35D4
#define D_80073C1C D_800FCB14
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4254(void* arg0, u8 arg1);
M2C_UNK func_800F4534(void*, M2C_UNK);
extern s8 D_800FD51B;
extern s8 D_800FD51E;

void func_800F3610(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        D_800FD51E = 0;
        D_800FD51B = 0;
        func_800F4254(arg0, 0x20);
        ((void (*)(void*, M2C_UNK))func_800F4534)(arg0, 0);
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
    }
}

#define func_8003744C func_800F367C
#define D_80073C1C D_800FCB24
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#include "mmx6/x4.h"

extern s8 D_800FD51B;

void func_800F36B8(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        D_800FD51B = -1;
        self->unk6--;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F36F8(void* arg0) {
    switch (F(u8, 0x2) & 0xF) {
    case 1:
        ((void (*)(void*, s32, s32))set_animation_frame)(
            arg0, 0x25, D_80097420.frame_counter & 1);
        F(s16, 0xA) += 6;
        break;
    case 2:
        ((void (*)(void*, s32, s32))set_animation_frame)(
            arg0, 0x21, D_80097420.frame_counter & 1);
        F(s16, 0xE) -= 6;
        break;
    case 3:
        ((void (*)(void*, s32, s32))set_animation_frame)(
            arg0, 0x22, D_80097420.frame_counter & 1);
        F(s16, 0xA) -= 6;
        F(s16, 0xE) += 6;
        break;
    }
    if (func_8002CBFC(arg0, 0x20, 0x20) == 1) {
        F(u8, 0x4) = 3;
    }
}

#define func_8003744C func_800F37F8
#define D_80073C1C D_800FCB34
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

void func_800F3834(void) {
}

#include "common.h"

void func_800F383C(void) {
}

#include "common.h"

void func_800F3844(void) {
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D654(s8*, u8*);
extern struct X4_PlayerObj g_Player;
extern void (*D_800FCB78[])(struct X4_MainObj*);
extern s8 D_800FD51B;

void func_800F384C(struct X4_MainObj* self) {
    s32 r;

    D_800FCB78[self->unk6](self);
    r = func_8002D654((s8*)self, (u8*)&g_Player);
    if (r == 1 && D_800FD51B == 0) {
        D_800FD51B = r;
    }
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800FB26C[];

void func_800F38C4(s8* self) {
    s32 y;

    M2C_FIELD(self, u8**, 0x50) = D_800FB26C + 0x104C;
    M2C_FIELD(self, s16*, 0x7C) = 0xA00;
    M2C_FIELD(self, u8*, 0x3) = 0;
    M2C_FIELD(self, s16*, 0x7E) = 0;
    y = M2C_FIELD(self, u16*, 0xE) - 0xE;
    M2C_FIELD(self, u16*, 0xE) = y;
    M2C_FIELD(self, u16*, 0x84) = M2C_FIELD(self, u16*, 0xA);
    M2C_FIELD(self, u16*, 0x86) = y;
    M2C_FIELD(self, u8*, 0x6) = M2C_FIELD(self, u8*, 0x6) + 1;
}

#include "common.h"
#include "mmx6/x4.h"

void func_800F402C(void* arg0, s32 arg1); /* extern */
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51A;
extern s8 D_800FD51B;

void func_800F3908(struct X4_MainObj* self) {
    s8 v;

    if (--self->unk7C == 0) {
        self->on_screen = 0;
        D_800FD51A = 0;
        D_800FD51B = 2;
        self->state = 3;
        return;
    }
    v = D_800FD51B;
    if (v == 1) {
        D_800FD516 = self->x_pos.u.hi;
        D_800FD518 = self->y_pos.u.hi;
        self->on_screen = v;
        D_800FD51A = v;
        func_800F402C(self, 4);
    }
}

#include "common.h"

void func_800F39A0(void) {
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern s32 D_800FC9A0;
extern void (*D_800FCB88[])(void*);
extern s8 D_800FD51C;

// str 0x800FC9A0 sha1=44c6d6c2ecd801e25abad8013bf897c534962379 = "printable byte run: a table, not text"
void func_800F39A8(void* arg0) {
    if (D_800FD51C == 0) {
        if (M2C_FIELD(arg0, s8*, 6) != 3) {
            ((void (*)(s32, void*, void*))func_800477E4)(4, &D_800FC9A0, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    D_800FCB88[M2C_FIELD(arg0, s8*, 6)](arg0);
}

#include "common.h"

extern u8 D_800FB26C[];

void func_800F3A34(u8* arg0) {
    if (((s8*)arg0)[0x45] == 1) {
        *(u8**)(arg0 + 0x54) = D_800FB26C + 0x1060;
        arg0[6] = arg0[6] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_800F1A90(void* self, u8 arg1);

void func_800F3A60(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        ((void (*)(void*, u8))func_800F1A90)(arg0, 0x30);
        ((void (*)(void*, s32))set_animation)(arg0, 0x3B);
        *(u16*)(arg0 + 0x7C) = 0x28;
        arg0[6] = arg0[6] + 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F3AC4(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = t;
    if ((t << 0x10) == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x53);
        arg0[6] = 1;
    }
}

#include "common.h"

void func_800F3B10(void) {
}

#define func_8003744C func_800F3B18
#define D_80073C1C D_800FCB58
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800FD51C;

void func_800F3B54(void* arg0) {
    D_800FD51C = 0;
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F41D0(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800FD51F;

void func_800F3B70(void* arg0) {
    M2C_FIELD(arg0, s16*, 0x7C) = 3;
    D_800FD51F = 0;
    func_800F41D0(arg0, 0x20, background_objects[0].x_pos.u.hi + 0x10,
                  background_objects[0].y_pos.u.hi + 8);
    func_800F41D0(arg0, 0x20, background_objects[0].x_pos.u.hi + 0x130,
                  background_objects[0].y_pos.u.hi + 8);
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}

#include "common.h"

s32 random_byte();
extern u8 D_800FCB40[];
extern s8 D_800FD521;
extern s16 D_800FD524;

#define F_06(p) (*(u8*)((u8*)(p) + 0x6))
#define F_7C(p) (*(s16*)((u8*)(p) + 0x7C))
#define F_8C(p) (*(s8*)((u8*)(p) + 0x8C))
#define F_8D(p) (*(s8*)((u8*)(p) + 0x8D))

void func_800F3C10(void* arg0) {
    s32 t;

    t = (u16)F_7C(arg0) - 1;
    D_800FD524 = 0;
    F_7C(arg0) = t;
    if ((s16)t == 0) {
        if (D_800FCB40[F_8D(arg0) + F_8C(arg0) * 6] == 0xFF) {
            F_8C(arg0) = random_byte() & 3;
            F_8D(arg0) = 0;
            F_7C(arg0) = 0x78;
        }
        D_800FD524 = D_800FCB40[F_8D(arg0) + F_8C(arg0) * 6];
        F_7C(arg0) = 0x5A;
        F_8D(arg0)++;
    }
    if (D_800FD521 < 5) {
        F_06(arg0)++;
    }
}

#include "common.h"

void func_800F3D14(void) {
}

#include "common.h"

void func_800F3D1C(void) {
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s8 D_800CCEF4;
extern s8 D_800CCF5C;
extern u8 D_800FB26C[];
extern s16 D_800FDA72;

void func_800F3D24(u8* self) {
    s8 state = *(s8*)(self + 0x89);

    if (state == 0) {
        return;
    }
    switch (state) {
    case 1:
        D_800CCEF4 = state;
        *(s8*)(self + 0x5C) = state;
        D_800FDA72 = 3;
        *(void**)(self + 0x50) = 0;
        *(void**)(self + 0x54) = 0;
        self[0x89]++;
        break;
    case 2:
        if (--D_800FDA72 == 0) {
            play_sound(0, 0xE, 0);
            D_800FDA72 = 3;
        }
        if (++*(s8*)(self + 0x5C) == D_800CCF5C) {
            void* a;
            void* b;
            self[0x89] = 0;
            a = D_800FB26C + 0x1044;
            *(void**)(self + 0x50) = a;
            a = 0;
            b = D_800FB26C + 0x1048;
            *(void**)(self + 0x54) = b;
        }
        break;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* func_8002C398(void);

void func_800F3E10(void* arg0, s32 arg1) {
    void* obj;
    u8 b = arg1;

    obj = func_8002C398();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0xB;
        M2C_FIELD(obj, u8*, 2) = b;
        M2C_FIELD(obj, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        {
            s32 a = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(obj, s16*, 8) = 0;
            M2C_FIELD(obj, s16*, 0xA) = a;
        }
        {
            s32 e = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(obj, s16*, 0xC) = 0;
            M2C_FIELD(obj, void**, 0x50) = arg0;
            M2C_FIELD(obj, s16*, 0xE) = e;
        }
        M2C_FIELD(obj, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
        M2C_FIELD(obj, s16*, 0x42) = M2C_FIELD(arg0, s16*, 0x42) & 0x7FFF;
        M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F3EC4 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
struct X4_VisualObj* func_8002C398(void);
extern u32* D_80095098;

void func_800F3EC4(void* arg0, u8 arg1, s16 arg2, s16 arg3) {
    void* obj;
    s32 t;

    obj = func_8002C398();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0xB;
        M2C_FIELD(obj, u8*, 2) = arg1;
        M2C_FIELD(obj, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        t = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, u8*, 0x14) = 0;
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 8) = 0;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        M2C_FIELD(obj, void**, 0x50) = arg0;
        M2C_FIELD(obj, s32*, 0x30) = t;
        M2C_FIELD(obj, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40) + 0x400;
        M2C_FIELD(obj, u16*, 0x40) =
            D_80095098[func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1] >> 7;
        M2C_FIELD(obj, s16*, 0x42) =
            (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1 + 8) / 4 + 0x1E0)
             << 6);
        M2C_FIELD(obj, u8**, 0x3C) =
            (u8*)SPAD20_800F3EC4 +
            SPAD20_800F3EC4[func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1];
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* func_8002C398(void);
extern void* D_800FD510;

void func_800F402C(void* arg0, s32 arg1) {
    void* obj;
    u8 b = arg1;

    obj = func_8002C398();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0xB;
        M2C_FIELD(obj, u8*, 2) = b;
        M2C_FIELD(obj, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        {
            s32 a = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(obj, s16*, 8) = 0;
            M2C_FIELD(obj, s16*, 0xA) = a;
        }
        {
            s32 e = M2C_FIELD(arg0, u16*, 0xE);
            void* d = D_800FD510;
            M2C_FIELD(obj, s16*, 0xC) = 0;
            M2C_FIELD(obj, void**, 0x50) = d;
            M2C_FIELD(obj, s16*, 0xE) = e;
        }
        M2C_FIELD(obj, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
        M2C_FIELD(obj, s16*, 0x42) = M2C_FIELD(arg0, s16*, 0x42) & 0x7FFF;
        M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(obj, u8*, 0x47) = M2C_FIELD(arg0, u8*, 0x47);
    }
}

#include "../shared/rock_11/func_800F40F4.c"

#include "common.h"

void* func_8002C458();

void func_800F41D0(void* arg0, u8 arg1, s16 arg2, s16 arg3) {
    u8* p;

    p = func_8002C458();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x1C;
        *(void**)(p + 0x7C) = arg0;
        p[2] = arg1;
        *(s16*)(p + 0xA) = arg2;
        *(s16*)(p + 0x8) = 0;
        *(s16*)(p + 0xE) = arg3;
        *(s16*)(p + 0xC) = 0;
        p[0x14] = 0;
    }
}

#include "common.h"

void* enemy_slot_alloc();
extern u8 D_800FD522;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F4254(void* arg0, u8 arg1) {
    void* obj;
    u8 b;
    u16 h;

    obj = enemy_slot_alloc();
    if (obj != 0) {
        UB(obj, 0) = 0x41;
        UB(obj, 1) = 0x18;
        b = UB(arg0, 0x15);
        P(obj, 0x80) = arg0;
        UB(obj, 2) = arg1;
        UB(obj, 0x15) = b;
        h = UH(arg0, 0xA);
        UH(obj, 8) = 0;
        UH(obj, 0xA) = h;
        h = UH(arg0, 0xE);
        UH(obj, 0xC) = 0;
        UH(obj, 0xE) = h;
        UH(obj, 0x42) = UH(arg0, 0x42) & 0x7FFF;
        W(obj, 0x30) = W(arg0, 0x30);
        W(obj, 0x3C) = W(arg0, 0x3C);
        UH(obj, 0x40) = UH(arg0, 0x40);
        UB(obj, 0x14) = UB(arg0, 0x14);
        if ((arg1 & 0xF0) == 0x10 && (arg1 & 0xF)) {
            D_800FD522 += 1;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* enemy_slot_alloc();
extern s8 D_800FD521;

void func_800F4328(void* arg0, u8 arg1, s16 arg2, s16 arg3) {
    void* obj;
    u8 b15;

    obj = enemy_slot_alloc();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0x18;
        b15 = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, void**, 0x80) = arg0;
        M2C_FIELD(obj, u8*, 2) = arg1;
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 8) = 0;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        M2C_FIELD(obj, u8*, 0x15) = b15;
        M2C_FIELD(obj, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(obj, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        if ((arg1 & 0xF0) == 0x30) {
            D_800FD521++;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F440C (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* enemy_slot_alloc();
extern u32* D_80095098;

void func_800F440C(s8 arg0, u8 arg1, s16 arg2, s16 arg3) {
    void* obj;

    obj = enemy_slot_alloc();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = arg0;
        M2C_FIELD(obj, u8*, 2) = arg1;
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 8) = 0;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        M2C_FIELD(obj, u16*, 0x40) = D_80095098[func_8002A47C(arg0)] >> 7;
        M2C_FIELD(obj, s16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(obj, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(obj, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(obj, u8**, 0x3C) =
            (u8*)SPAD20_800F440C +
            SPAD20_800F440C[func_8002A47C(M2C_FIELD(obj, s8*, 1))];
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* alloc_class6_slot(void);

M2C_UNK func_800F4534(void* arg0, M2C_UNK arg1) {
    void* obj;
    u8 b = arg1;

    obj = alloc_class6_slot();
    {
        // !FAKE: pin the active-flag constant to the return register before the null test
        register s32 one asm("$2") = 1;
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0) = one;
            M2C_FIELD(obj, u8*, 1) = 0;
            M2C_FIELD(obj, u8*, 2) = b;
            M2C_FIELD(obj, u16*, 0xA) = 0;
            M2C_FIELD(obj, u16*, 0xE) = 0;
            M2C_FIELD(obj, void**, 0x5C) = arg0;
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* alloc_class6_slot(void);

void func_800F4588(void* arg0, s32 arg1) {
    void* obj;
    u8 b = arg1;

    obj = alloc_class6_slot();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
        M2C_FIELD(obj, u8*, 1) = M2C_FIELD(arg0, u8*, 1);
        M2C_FIELD(obj, u8*, 2) = b;
        M2C_FIELD(obj, s32*, 0x5C) = M2C_FIELD(arg0, s32*, 0x5C);
        M2C_FIELD(obj, u16*, 0xA) = 0;
        M2C_FIELD(obj, u16*, 0xE) = 0;
        M2C_FIELD(obj, u16*, 0x34) = M2C_FIELD(arg0, u16*, 0x34);
        M2C_FIELD(obj, u8*, 0x37) = M2C_FIELD(arg0, u8*, 0x37);
        M2C_FIELD(obj, s32*, 0x14) = M2C_FIELD(arg0, s32*, 0x14);
        M2C_FIELD(obj, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(obj, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0x1C);
        M2C_FIELD(obj, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20);
        M2C_FIELD(obj, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x24);
        M2C_FIELD(obj, s32*, 0x28) = M2C_FIELD(arg0, s32*, 0x28);
        M2C_FIELD(obj, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x2C);
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
    }
}

#include "common.h"

#define M2C_UNK s32

s32 random_byte();                           /* extern */
M2C_UNK func_8004A0C0(M2C_UNK, s16, s16, s32); /* extern */

void func_800F4664(s16 arg0, s16 arg1) {
    func_8004A0C0(0, arg0, arg1, (random_byte() & 1) ^ 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
extern void (*D_800FCBB8[])(void*);
extern s8 D_800FD51D;

void func_800F46B4(void* arg0) {
    if (D_800FD51D != 0) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4)++;
        return;
    }
    ((void (*)(void*))func_80017A04)(arg0);
    if ((M2C_FIELD(arg0, u8*, 0x2) & 0xF) != 0x30) {
        func_8002CCB0(arg0, 0x30, 0x30);
    } else {
        func_8002CCB0(arg0, 0x30, 0xA0);
    }
    D_800FCBB8[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    func_80030ECC(arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F475C(void) {
    clear_object_slot();
}

#define func_8003744C func_800F477C
#define D_80073C1C D_800FCBC8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4E20(u8* arg0, u8 arg1, s16 arg2, s16 arg3);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F47B8(void* arg0) {
    s16 i;
    s16 j;

    if (++F(s16, 0x88) == 0x10) {
        F(u8, 0x3) = 0;
        F(u8, 0x4)++;
        return;
    }
    j = 0x27;
    for (i = 0; i < (0xF - F(s16, 0x88)) / 4; i++) {
        j -= 2;
        if (j >= 0) {
            func_800F4E20(arg0, 3, j, 1);
        }
    }
}

#include "common.h"

void func_800F4894(void) {
}

#include "common.h"

void func_800F489C(void) {
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FCBA0;
extern s16 D_800FD516;
extern s16 D_800FD518;

void func_800F48A4(u8* arg0) {
    arg0[0x14] = 0;
    arg0[3] = 0;
    *(void**)(arg0 + 0x50) = &D_800FCBA0;
    *(s16*)(arg0 + 0xA) = background_objects[0].x_pos.u.hi + D_800FD516;
    *(s16*)(arg0 + 0xE) = background_objects[0].y_pos.u.hi + D_800FD518;
    if (--*(s16*)(arg0 + 0x88) == 0) {
        play_sound(2, 0x39, arg0);
        arg0[4]++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)

void func_800F493C(void* arg0) {
    B(arg0, 0x3) = 0;
    if (--H(arg0, 0x88) == 0) {
        B(arg0, 0x4)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800FCBF4[])(void*);
extern s8 D_800FD51D;
extern s8 D_800FD51E;

void func_800F4970(void* arg0) {
    s8 v;

    if ((D_800FD51D != 0 && (v = M2C_FIELD(arg0, s8*, 0x2), v < 5) && v >= 3) ||
        (D_800FD51E != 0 && M2C_FIELD(arg0, s8*, 0x2) == 4)) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4)++;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x2) != 3 && M2C_FIELD(arg0, s8*, 0x5) != 4) {
        func_80017A04(arg0);
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    (*(void (**)(void*))((M2C_FIELD(arg0, s8*, 0x5) << 2) + (s32)D_800FCBF4))(
        arg0);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F4A4C(void) {
    clear_object_slot();
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F4A6C(void* arg0) {
    void* parent;
    s32 state;

    parent = M2C_FIELD(arg0, void**, 0x50);
    if (M2C_FIELD(parent, u8*, 0x7) & 4) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4) += 1;
        return;
    }
    state = M2C_FIELD(arg0, u8*, 0x2) & 0xF;
    if (state == 1) {
        if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
            M2C_FIELD(arg0, u8*, 0x3) = 0;
            M2C_FIELD(arg0, u8*, 0x4) += 1;
            return;
        }
    } else if (state == 2 && M2C_FIELD(arg0, s8*, 0x45) == 1) {
        set_animation(arg0, 0);
    }
    M2C_FIELD(arg0, s16*, 0xA) =
        M2C_FIELD(parent, s16*, 0xA) + M2C_FIELD(arg0, s16*, 0x8);
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(parent, s16*, 0xE) + M2C_FIELD(arg0, s16*, 0xC);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F4B30(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 0x16) = 7;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230();                    /* extern */

void func_800F4B68(void* arg0) {
    func_8002D230();
    if (func_8002CBFC(arg0, 0x20, 0x40) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s8 D_800FD51D;

void func_800F4BB8(void* arg0) {
    s32 sub;

    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    switch (M2C_FIELD(arg0, s8*, 0x2) & 0xF0) {
    case 0:
        sub = M2C_FIELD(arg0, u8*, 0x2) & 0xF;
        switch (sub) {
        case 0:
            play_sound(2, 0x32, arg0);
            M2C_FIELD(arg0, u8*, 0x0) = 0x11;
            M2C_FIELD(arg0, s16*, 0x34) = 0x1F;
            M2C_FIELD(arg0, s8*, 0x37) = -1;
            M2C_FIELD(arg0, u8*, 0x5) = 0;
            break;
        case 1:
            M2C_FIELD(arg0, u8*, 0x5) = sub;
            break;
        }
        break;
    case 0x10: {
        s32 c7;
        s32 c13;

        sub = M2C_FIELD(arg0, u8*, 0x2) & 0xF;
        c7 = 7;
        c13 = 0x13;
        do {
        } while (0);
        sub += 0x14;
        M2C_FIELD(arg0, s16*, 0x34) = sub;
        M2C_FIELD(arg0, u8*, 0x36) = c7;
        M2C_FIELD(arg0, u8*, 0x0) = c13;
        M2C_FIELD(arg0, s16*, 0x48) = 0x1E;
        M2C_FIELD(arg0, s8*, 0x37) = -1;
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        break;
    }
    }
    if (D_800FD51D != 0) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4)++;
    }
}

#include "common.h"

extern void (*D_800FCC18[])(void*);
extern s8 D_800FD51D;
extern s8 D_800FD51E;

void func_800F4CBC(u8* arg0) {
    if ((D_800FD51D != 0) || (D_800FD51E != 0)) {
        arg0[3] = 0;
        arg0[4] = arg0[4] + 1;
        return;
    }
    D_800FCC18[((s8*)arg0)[5]](arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK silence_sound(M2C_UNK, M2C_UNK); /* extern */
M2C_UNK clear_object_slot(void*);            /* extern */

void func_800F4D28(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        silence_sound(2, 0x17);
    }
    clear_object_slot(arg0);
}

#include "common.h"

extern s8 D_800FD51A;

void func_800F4D68(s8* arg0) {
    s8* p = arg0;
    s32 t = p[6];
    u8 u = ((u8*)p)[6];
    if (t == 0) {
        p[3] = D_800FD51A;
        ((u8*)p)[6] = u + 1;
        return;
    }
    p[3] = D_800FD51A;
    ((u8*)p)[4]++;
}

#include "common.h"

extern void (*D_800FCC28[])(s8*);

void func_800F4DA8(s8* arg0) {
    if ((*(s8**)(arg0 + 0x5C))[4] != 2) {
        arg0[3] = 0;
        ((u8*)arg0)[4]++;
        return;
    }
    D_800FCC28[arg0[6]](arg0);
}

#include "common.h"

void func_800F4E10(void) {
}

#include "common.h"

void func_800F4E18(void) {
}

#define func_800F40F4 func_800F4E20
#include "../shared/rock_11/func_800F40F4.c"
#undef func_800F40F4

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F4EFC);
// clang-format on

#define func_800EE70C func_800F503C
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EE70C.c"
#undef func_800EE70C
#undef g_Player

#define func_800EE800 func_800F5130
#define D_80097420 D_80097420
#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800F5130(u8* arg0) {
    s32 a;
    s32 b;
    void* t;

    a = FU16(arg0, 0x80) + 1;
    b = FU16(arg0, 0x82) - 1;
    FU16(arg0, 0x80) = a;
    FU16(arg0, 0x82) = b;
    if (!(D_80097420.frame_counter & 1)) {
        g_Player.x_pos.i.hi = a;
    } else {
        g_Player.x_pos.i.hi = b;
    }
    if (D_80097420.transition.active == 0) {
        background_objects[0].unk44 = 1;
        background_objects[1].unk44 = 1;
        background_objects[2].unk44 = 1;
        g_Player.x_pos.i.hi = FU16(arg0, 0x84);
        t = *(void**)(arg0 + 0x88);
        g_playthrough_state.unk10 = 0;
        g_playthrough_state.unk11 = 0;
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk19 = 0;
        g_Player.unk68 = t;
    }
}
#undef func_800EE800
#undef D_80097420

#define func_800EE8C4 func_800F51F4
#define background_objects background_objects
#include "../shared/commander_yammark/func_800EE8C4.c"
#undef func_800EE8C4
#undef background_objects

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F52F4);

INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F56E8);
// clang-format on

#define func_800EA1D8 func_800F57F4
#define D_800FAA64 D_800FCC7C
#include "../shared/d1000/func_800EA1D8.c"
#undef func_800EA1D8
#undef D_800FAA64

#define func_800EEF10 func_800F5840
#define D_800F7808 D_800FCC8C
#include "../shared/commander_yammark/func_800EEF10.c"
#undef func_800EEF10
#undef D_800F7808

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14(); /* extern */
M2C_UNK func_8002CA54(); /* extern */

void func_800F58BC(struct ObjectHeader* arg0) {
    if (arg0->state == 2) {
        ((M2C_UNK(*)())func_8002CA14)();
        return;
    }
    func_8002CA54();
}

#define func_800EEFCC func_800F58FC
#define g_Player g_Player
#include "../shared/commander_yammark/func_800EEFCC.c"
#undef func_800EEFCC
#undef g_Player

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;
extern s8 D_800CCEF6;

void func_800F5974(void* arg0) {
    if ((D_800CCEF6 == 0) && (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA))) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x5A;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800F59C0(void* arg0) {
    if (D_800970AA >= M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u16*, 0x84) = (u16)D_800970AA;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#define func_8003744C func_800F59FC
#define D_80073C1C D_800FCCA4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_8003744C func_800F5A38
#define D_80073C1C D_800FCD40
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#define func_800EF144 func_800F5A74
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;
extern s8 D_800CCEDF;

void func_800F5A74(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        D_800CCEDF = M2C_FIELD(arg0, u8*, 2) | 0x40;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF144

#define func_800EF1E8 func_800F5B18
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;

void func_800F5B18(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF1E8

#define func_800EF27C func_800F5BAC
#define D_80097420 D_80097420
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

extern s16 D_800970AA;

void func_800F5BAC(void* arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, u16*, 0x80) - 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x82) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a2;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a1;
    if (!(D_80097420.frame_counter & 1)) {
        D_800970AA = temp_a2;
    } else {
        D_800970AA = temp_a1;
    }
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef func_800EF27C
#undef D_80097420

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800F5C14(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD9C_800F5C34 (*(s32**)0x1F80009C)

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007569C;
extern u8 D_800970B4;
extern u16 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)
extern s32 D_800FCED8;
extern s32 D_800FD278;
extern u8 D_800FDA78[];
extern u16 D_800FDA7C;
extern u16 D_800FDA7E;
extern u32 D_800FDA84;

#define P(type, off) M2C_FIELD(arg0, type*, off)

void func_800F5C34(void* arg0) {
    s32 t;
    s32 b;

    if (D_800CCEDC == 0xC) {
        s32* sp = SPAD9C_800F5C34;
        s32 n = *sp;
        P(u16, 0x42) = 0x7948;
        P(u8*, 0x3C) = (u8*)sp + n;
    }
    P(u8, 0x5C) = 0;
    P(u8, 0x60) = 6;
    P(void*, 0x58) = &D_8007569C;
    P(u8, 0x61) = 0;
    P(u8, 0x3) = 0;
    b = D_800970B4;
    P(s32, 0x20) = 0;
    P(s32, 0x24) = 0;
    P(s32, 0x28) = 0;
    P(s32, 0x2C) = 0;
    P(u8, 0x67) = 0;
    P(void*, 0x30) = &D_800FD278;
    P(u8, 0x16) = 5;
    P(s32, 0x50) = 0;
    P(s32, 0x54) = 0;
    P(s32, 0x68) = 0;
    t = P(s8, 0x2) & 0xF0;
    P(u8, 0x14) = b;
    if (t == 0) {
        P(u16, 0x40) = 0x140;
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        P(s8, 0x86) = -1;
        P(u8, 0x87) = 0;
        P(u8, 0x88) = 0;
        P(u8, 0x8A) = 0;
        P(u8, 0x8B) = 0;
        P(u8, 0x8C) = 0;
        P(u8, 0x8D) = 0;
        P(u8, 0x8E) = 0;
        P(void*, 0x68) = &D_800FCED8;
        if (!(P(u8, 0x2) & 0xF)) {
            P(u8, 0x15) = 0;
            D_800FDA78[0] = 0;
            D_800FDA78[1] = 0;
            D_800FDA78[2] = 0;
            D_800FDA7C = 0;
            D_800FDA7E = 0;
            D_800FDA84 = 0;
            P(u8, 0x4) = 1;
            P(u8, 0x5) = 2;
        } else {
            P(u8, 0x5C) = 0x10;
            P(u8, 0x4) = 2;
            P(u8, 0x5) = 3;
        }
    } else if (t == 0x10) {
        P(u8, 0x60) = 4;
        P(u8, 0x5C) = 5;
        P(u8, 0x16) = 5;
        P(u8, 0x4) = 4;
        P(u8, 0x5) = 0;
        P(u8, 0x0) |= 0x10;
    } else if (t == 0x20) {
        set_animation(arg0, 0x15);
        P(u8, 0x8A) = 0;
        P(u16, 0x88) = 0;
        P(u16, 0x86) = 0;
        P(u16, 0x84) = 0;
        P(u8, 0x5C) = 0x32;
        P(u8, 0x16) = 6;
        P(u8, 0x4) = 5;
        P(u8, 0x5) = 0;
    }
    P(u8, 0x6) = 0;
    P(u8, 0x7) = 0;
}
#undef D_800CCEDC

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F5E20);

INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F610C);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_800FA72C(M2C_UNK, void*);
extern struct X4_EngineObj g_playthrough_state;
extern s8* D_800FDA74;
extern u32 D_800FDA84;

void func_800F6298(void* arg0) {
    struct X4_EngineObj* eng;

    M2C_FIELD(arg0, u8*, 0x3) = 0;
    if (D_800FDA74[0] != 0) {
        if (D_800FDA74[7] == 0) {
            if ((s16)--M2C_FIELD(arg0, u16*, 0x7E) == -1) {
                M2C_FIELD(arg0, u16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        eng = &g_playthrough_state;
        M2C_FIELD(arg0, s32*, 0x80) = 0;
        M2C_FIELD(arg0, s32*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x88) = 0;
        M2C_FIELD(arg0, s32*, 0x8C) = 0;
        M2C_FIELD(arg0, s32*, 0x90) = 0;
        M2C_FIELD(arg0, s32*, 0x94) = 0;
        eng->enable_boss = 0;
        eng->boss_ptr = 0;
        if (eng->stage != 0xC) {
            if (D_800FDA84 < 0x1519) {
                func_800FA72C(0x10, eng);
            } else {
                func_800FA72C(0x11, eng);
            }
        } else {
            eng->unkF = -0x80;
            M2C_FIELD(eng, u8*, eng->checkpoint + 0x2C) = 1;
            eng->checkpoint += 8;
        }
        clear_object_slot(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
s32 func_800FA4F8(void* arg0, s16 arg1, s32 arg2);
extern u16 D_80097222;

void func_800F63CC(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
    } else if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
    }
    move_object(arg0);
    switch (M2C_FIELD(arg0, s8*, 0x7)) {
    case 0:
        func_800FA4F8((u8*)arg0 + 0xC, D_80097222 + 0x70, 0x10000);
        break;
    case 1:
        func_800FA4F8((u8*)arg0 + 0xC, D_80097222 + 0x90, 0x10000);
        break;
    case 2:
        func_800FA4F8((u8*)arg0 + 0xC, D_80097222 + 0xB0, 0x10000);
        break;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800FA4C8(struct X4_MainObj* self);
s32 func_800FA4F8(void* arg0, s16 arg1, s32 arg2);
extern struct X4_PlayerObj g_Player;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800F64F0(struct X4_MainObj* self) {
    s32 a;
    s32 b;

    func_800FA4C8(self);
    if (--self->unk7C == -1) {
        self->unk6 += 2;
        return;
    }
    if (self->unk7E == 0) {
        a = self->y_pos.i.hi;
        b = g_Player.y_pos.i.hi;
        if (F8(self, 0x89) >= (a - b >= 0 ? a - b : b - a)) {
            ((void (*)(void*, s32))set_animation)(self, 2);
            self->unk6++;
            return;
        }
    } else {
        self->unk7E--;
    }
    func_800FA4F8(&self->y_pos, g_Player.y_pos.i.hi, 0x18000);
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
extern struct X4_PlayerObj g_Player;

void func_800F65D8(void* arg0) {
    s32 angle;
    s32 d;

    {
        s16 px = g_Player.x_pos.i.hi;
        s16 py = g_Player.y_pos.i.hi;
        angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                       px - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) << 5;
    M2C_FIELD(arg0, s32*, 0x24) = rsin(angle) << 5;
    move_object(arg0);
    d = g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
    if (d >= 0) {
        if (d >= 4) {
            goto block;
        }
    } else if (M2C_FIELD(arg0, s16*, 0xA) - g_Player.x_pos.i.hi >= 4) {
    block:
        if (M2C_FIELD(arg0, s32*, 0x20) >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s8* D_800FDA74;
extern s16 D_800FDA80;
extern u8 func_800E9B90[];

#define F(type, off) M2C_FIELD(arg0, type*, off)
#define E(type, off) M2C_FIELD(e, type*, off)
#define B(type, off) M2C_FIELD(b, type*, off)

void func_800F66D8(void* arg0) {
    u8 tbl[4];
    s8 c;
    struct X4_EngineObj* e;
    struct X4_BackgroundObj* b;

    __builtin_memcpy(tbl, func_800E9B90, 4);
    if (--F(s16, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    c = *D_800FDA74;
    if (c == 0) {
        e = &g_playthrough_state;
        E(s8, 0x24) = 1;
        E(s8, 0x25) = 0;
        E(void*, 0x20) = arg0;
        set_boss_level();
        E(u8, 0x8C) = tbl[E(u8, 0x8F)] + 0x30;
        b = background_objects;
        F(s16, 0xA) = B(s16, 0x26) + 0xD0;
        {
            u16 y = B(u16, 0x2A);
            F(s16, 0x7C) = 2;
            F(s16, 0x7E) = 0x10;
            F(s16, 0xE) = y + 0xD0;
        }
        D_800FDA80 = 0;
        ((s32(*)(s32, s32, void*, void*))play_sound)(2, 0x42, arg0, b);
        F(u8, 0x6)++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
void func_800F9F7C(void* arg0, M2C_UNK arg1, M2C_UNK arg2);
extern struct X4_EngineObj g_playthrough_state;

void func_800F67E8(void* arg0) {
    s8 state;
    s32 one;
    struct X4_EngineObj* eng;

    state = M2C_FIELD(arg0, s8*, 0x45);
    one = 1;
    if (state == one) {
        play_sound(2, 0x44, arg0);
        func_800F9F7C(arg0, 0x30, 0);
        func_800F9F7C(arg0, 0x30, 0x200);
        func_800F9F7C(arg0, 0x30, 0x400);
        func_800F9F7C(arg0, 0x30, 0x600);
        func_800F9F7C(arg0, 0x30, 0x800);
        func_800F9F7C(arg0, 0x30, 0xA00);
        func_800F9F7C(arg0, 0x30, 0xC00);
        func_800F9F7C(arg0, 0x30, 0xE00);
    } else if (state == 2) {
        func_800F9F7C(arg0, 0x30, 0x100);
        func_800F9F7C(arg0, 0x30, 0x300);
        func_800F9F7C(arg0, 0x30, 0x500);
        func_800F9F7C(arg0, 0x30, 0x700);
        func_800F9F7C(arg0, 0x30, 0x900);
        func_800F9F7C(arg0, 0x30, 0xB00);
        func_800F9F7C(arg0, 0x30, 0xD00);
        func_800F9F7C(arg0, 0x30, 0xF00);
    } else if (state == 3) {
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        eng = &g_playthrough_state;
        if (eng->stage != 0xC) {
            open_text_box(0, 0xFF, M2C_FIELD(eng, u8*, 0x2E));
            M2C_FIELD(eng, u8*, 0x2E) = one;
        }
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800FA150(void*, s32);
void func_800FA234(void*, s32);
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800FD2EC[];
extern u8 D_800FDA78[];
extern u16 D_800FDA7C;
#define D_800FDA7C (*(s16*)&D_800FDA7C)

void func_800F6998(void* arg0) {
    s32 i;
    s8 idx;

    play_sound(2, 0x21, arg0);
    set_animation(arg0, 8);
    {
        // !FAKE: depin: dropping it breaks the match (110/113)
        register s32 six asm("$2") = 6;
        M2C_FIELD(arg0, s8*, 0x60) = six;
    }
    M2C_FIELD(arg0, u8*, 0x8B) = 0;
    if (D_800FDA78[0] == 0 || D_800FDA78[1] == 0 || D_800FDA78[2] == 0) {
        idx = (u32)random_byte() % 3;
        for (i = 0; i < 3; i++) {
            if (D_800FDA78[idx] == 1) {
                idx++;
                if (idx >= 3) {
                    idx = 0;
                }
            }
        }
        func_800FA234(arg0, (u8)(idx + 0x20));
    }
    if (D_800FDA7C <
        D_800FD2EC[(u8)g_playthrough_state.player_initial_data[0x46]]) {
        func_800FA150(arg0, 1);
    }
    if (M2C_FIELD(arg0, s16*, 0xA) < g_Player.x_pos.i.hi) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFFB0000;
        M2C_FIELD(arg0, s32*, 0x28) = -0x4000;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0x50000;
        M2C_FIELD(arg0, s32*, 0x28) = -0x4000;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}
#undef D_800FDA7C

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
s32 random_byte();
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF38;

void func_800F6B5C(void* arg0) {
    s32 angle;
    s32 v;
    s32 t;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        s16 px = g_Player.x_pos.i.hi;
        s16 py = g_Player.y_pos.i.hi;
        angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - py,
                       px - M2C_FIELD(arg0, s16*, 0xA));
        v = rcos(angle);
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x20) = ((v * 32 + t) << 1) / 4;
        v = rsin(angle);
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x24) = ((v * 32 + t) << 1) / 4;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x24) * 2;
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20) * 2;
        }
        move_object(arg0);
        v = M2C_FIELD(arg0, s32*, 0x20);
        if (v >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = ((u32)random_byte() % 40 & 0xFF) + 0x32;
        M2C_FIELD(arg0, u8*, 0x5)++;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
void func_800FA31C(void* arg0);
s32 func_800FA584(s16* arg0, s16 arg1, s16 arg2, s16 arg3);
extern s16 D_8009721E;
extern u8 D_800FD45C[];

void func_800F6CB0(void* arg0) {
    u16 t;

    if (M2C_FIELD(arg0, s8*, 0x8A) != 0) {
        M2C_FIELD(arg0, s8*, 0x8A) = 0;
        M2C_FIELD(arg0, u16*, 0x88) += 0x20;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        if ((M2C_FIELD(arg0, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0x88)) <
            (D_8009721E + 0x10)) {
            M2C_FIELD(arg0, u16*, 0x88) =
                (u16)(M2C_FIELD(arg0, u16*, 0xA) - 0x10) - (u16)D_8009721E;
        }
    } else if ((M2C_FIELD(arg0, s16*, 0xA) + M2C_FIELD(arg0, s16*, 0x88)) >
               (D_8009721E + 0x140)) {
        M2C_FIELD(arg0, u16*, 0x88) =
            (u16)D_8009721E - (u16)(M2C_FIELD(arg0, u16*, 0xA) - 0x140);
    }
    func_800FA584((s8*)arg0 + 0x86, M2C_FIELD(arg0, s16*, 0x88), 4, 1);
    func_800FA31C(arg0);
    if (M2C_FIELD(arg0, u16*, 0x84) & 0xF) {
        t = M2C_FIELD(arg0, u16*, 0x86);
        if (!(t & 0xF)) {
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                func_80027BA0(0, (M2C_FIELD(arg0, s16*, 0xA) - (s16)t) & 0xFFF0,
                              M2C_FIELD(arg0, s16*, 0xE) & 0xFFF0, D_800FD45C);
            } else {
                func_80027BA0(
                    0, ((M2C_FIELD(arg0, s16*, 0xA) + (s16)t) & 0xFFF0) - 0x10,
                    M2C_FIELD(arg0, s16*, 0xE) & 0xFFF0, D_800FD45C);
            }
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, u16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
    M2C_FIELD(arg0, u16*, 0x84) = M2C_FIELD(arg0, u16*, 0x86);
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F6E4C);
// clang-format on

#include "../shared/rock_11/func_800F70B8.c"

#include "../shared/rock_11/func_800F7284.c"

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
s32 func_800FA630(void*, s16, s16);
extern s16 D_800970AA;

#define F_U8(o) (*(u8*)((u8*)self + (o)))
#define F_S16(o) (*(s16*)((u8*)self + (o)))
#define F_S32(o) (*(s32*)((u8*)self + (o)))

void func_800F73B0(void* self) {
    s16 x;
    s32 d;
    s32 v;
    // !FAKE: depin: dropping it breaks the match (101/103)
    register s32 t asm("$2");

    if (F_U8(0x15) == 0) {
        if (func_800FA630(self, F_S16(0xA) - 0x10, F_S16(0xE)) != 0) {
            set_animation(self, 0xC);
            F_S32(0x50) = 0;
            F_U8(0x6) = 4;
            F_S16(0xA) -= 0x12;
            return;
        }
        if (!(F_U8(0x70) & 2)) {
            goto gen;
        }
        goto inc;
    } else if (F_U8(0x15) == 0x40) {
        if (func_800FA630(self, F_S16(0xA) + 0x10, F_S16(0xE)) != 0) {
            set_animation(self, 0xC);
            F_S32(0x50) = 0;
            F_U8(0x6) = 4;
            F_S16(0xA) += 0x12;
            return;
        }
        if (F_U8(0x70) & 1) {
            goto inc;
        }
    }
gen:
    x = F_S16(0xA);
    d = x - D_800970AA;
    if (d >= 0) {
        if (d < 9) {
            goto inc;
        }
    } else if (D_800970AA - x < 9) {
    inc:
        F_U8(0x6)++;
        return;
    }
    if (F_S32(0x84) == 1) {
        set_animation(self, 0xC);
        t = F_U8(0x15);
        if (t == 0) {
            v = (u16)F_S16(0xA) - 0x12;
        } else {
            v = (u16)F_S16(0xA) + 0x12;
        }
        F_S16(0xA) = v;
        F_S32(0x50) = 0;
        F_U8(0x6) = 4;
        return;
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
s32 func_800FA630(void*, s16, s16);

#define F_S8(o) (*(s8*)((u8*)self + (o)))
#define F_U8(o) (*(u8*)((u8*)self + (o)))
#define F_S16(o) (*(s16*)((u8*)self + (o)))
#define F_S32(o) (*(s32*)((u8*)self + (o)))

void func_800F754C(void* self) {
    if (F_S8(0x7) == 0) {
        if (func_800FA630(self, F_S16(0xA), F_S16(0xE) - 0x10) != 0 ||
            (F_U8(0x70) & 4)) {
            set_animation(self, 0xC);
            F_S32(0x50) = 0;
            F_S16(0xE) -= 0x12;
            F_U8(0x6)++;
            return;
        }
        if (F_S32(0x84) == 1) {
            set_animation(self, 0xC);
            F_S32(0x50) = 0;
            F_S16(0xE) -= 0x12;
            F_U8(0x6)++;
            return;
        }
    } else if (func_800FA630(self, F_S16(0xA), F_S16(0xE) + 0x10) != 0 ||
               (F_U8(0x70) & 8) || F_S32(0x84) == 1) {
        set_animation(self, 0xC);
        F_S32(0x50) = 0;
        F_S16(0xE) += 0x12;
        F_U8(0x6)++;
        return;
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F7BE4(void* arg0);

void func_800F7670(void* arg0) {
    s32 kind;
    u8 sub;

    sub = M2C_FIELD(arg0, u8*, 0x2);
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    kind = M2C_FIELD(arg0, s8*, 0x2) & 0xF0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    if (kind == 0) {
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        M2C_FIELD(arg0, s16*, 0x54) = 0x1E;
        M2C_FIELD(arg0, u8*, 0x0) |= 0x10;
    } else if (kind == 0x10) {
        switch (sub & 0xF) {
        case 0:
            ((void (*)(void*, s32))set_animation)(arg0, 0x10);
            break;
        case 1:
            ((void (*)(void*, s32))set_animation)(arg0, 0x11);
            break;
        }
        M2C_FIELD(arg0, u8*, 0x3) = 1;
        M2C_FIELD(arg0, u8*, 0x5) = 1;
    } else if (kind == 0x20) {
        M2C_FIELD(arg0, u8*, 0x16) = 7;
        if ((sub & 0xF) == 1) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x1B);
            ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x80, 0x80);
        } else {
            func_800F7BE4(arg0);
        }
        M2C_FIELD(arg0, u8*, 0x4)++;
    } else if (kind == 0x30) {
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        M2C_FIELD(arg0, s16*, 0x54) = 0x1E;
        M2C_FIELD(arg0, u8*, 0x0) |= 0x10;
    }
}

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
s32 random_byte();

void func_800F77A8(void* self) {
    void* t;
    s32 ang;
    s32 d;
    s32 v;
    s32 w;

    t = M2C_FIELD(self, void**, 0x50);
    if (--M2C_FIELD(self, s16*, 0x56) == 0) {
        M2C_FIELD(self, u16*, 0x56) = (random_byte() & 7) + 5;
        M2C_FIELD(self, s16*, 0x58) = (u8)((u32)random_byte() % 3);
    }
    v = M2C_FIELD(t, s16*, 0xA);
    w = M2C_FIELD(t, s16*, 0xE);
    ang =
        ratan2(M2C_FIELD(self, s16*, 0xE) - w, v - M2C_FIELD(self, s16*, 0xA));
    switch (M2C_FIELD(self, s16*, 0x58)) {
    case 0:
    default:
        M2C_FIELD(self, s32*, 0x20) = rcos(ang) * 16 / 3;
        M2C_FIELD(self, s32*, 0x24) = rsin(ang) * 16 / 3;
        break;
    case 1:
        v = rcos(ang) * 16;
        M2C_FIELD(self, s32*, 0x20) = v / 4;
        w = rsin(ang) * 16;
        M2C_FIELD(self, s32*, 0x24) = w / 4;
        break;
    case 2:
        M2C_FIELD(self, s32*, 0x20) = rcos(ang) * 16 / 6;
        M2C_FIELD(self, s32*, 0x24) = rsin(ang) * 16 / 6;
        break;
    }
    if (M2C_FIELD(self, s32*, 0x20) < 0) {
        M2C_FIELD(self, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(self, u8*, 0x15) = 0x40;
    }
    move_object(self);
    d = M2C_FIELD(t, s16*, 0xA) - M2C_FIELD(self, s16*, 0xA);
    if (d >= 0) {
        if (d < 2) {
            goto near_x;
        }
        return;
    }
    if (M2C_FIELD(self, s16*, 0xA) - M2C_FIELD(t, s16*, 0xA) < 2) {
    near_x:
        d = M2C_FIELD(t, s16*, 0xE) - M2C_FIELD(self, s16*, 0xE);
        if (d >= 0) {
            if (d < 2) {
                goto near_y;
            }
            return;
        }
        if (M2C_FIELD(self, s16*, 0xE) - M2C_FIELD(t, s16*, 0xE) < 2) {
        near_y:
            M2C_FIELD(t, u8*, 0x7)--;
            M2C_FIELD(self, u8*, 0x6)++;
        }
    }
}

#include "../shared/rock_11/func_800F79D0.c"

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800FA418(void*);

#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F7BE4(void* arg0) {
    s16 a;
    s16 b;
    s16 e;
    s16 q;
    s32 n;
    s16 x;
    s16 i;
    s16 r;
    s16 m;

    a = M2C_FIELD(arg0, s16*, 0xA);
    b = M2C_FIELD(arg0, s16*, 0x8);
    e = M2C_FIELD(arg0, s16*, 0xE);
    if (ABS(b - a) < 5) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        return;
    }
    q = ABS(a - b) / 48;
    m = ABS(a - b) % 48;
    {
        // !FAKE: depin: dropping it breaks the match (64/149)
        register s32 v asm("$2");
        if (m != 0) {
            v = q;
        } else {
            v = q - 1;
        }
        n = (s8)v;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        x = a - 0x18;
    } else {
        x = a + 0x18;
    }
    for (i = 0; i < n; i++) {
        M2C_FIELD(arg0, s16*, 0xA) = x;
        M2C_FIELD(arg0, s16*, 0xE) = e;
        func_800FA418(arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            x = x - 0x30;
        } else {
            x = x + 0x30;
        }
    }
    M2C_FIELD(arg0, s16*, 0xA) = x;
    M2C_FIELD(arg0, s16*, 0xE) = e;
    r = ABS(a - b) - n * 48;
    r = r / 4 - 1;
    M2C_FIELD(arg0, s8*, 0x47) = r - 0x65;
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    func_8002CCB0(arg0, 0x80, 0x80);
}

#include "../shared/rock_11/func_800F7E38.c"

#define func_80041AB8 func_800F7EA8
#define D_80075FD8 D_800FD358
#define FAMILY_FIELD 5
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8
#undef FAMILY_FIELD

#include "../shared/rock_11/func_800F7EE4.c"

#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class3_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s8* D_800FDA74;

void func_800F7F70(void* arg0) {
    void* p;
    s8 t;
    s16 h;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        p = alloc_class3_slot();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0x0) = 1;
            M2C_FIELD(p, u8*, 0x1) = 0x1A;
            M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
            M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            D_800FDA74 = p;
        }
    }
    func_8002CCB0(arg0, 0x60, 0x60);
    {
        // !FAKE: depin: dropping it breaks the match (54/61)
        register s32 q asm("$2");
        q = M2C_FIELD(arg0, u16*, 0x7E) - 1;
        M2C_FIELD(arg0, s16*, 0x7E) = q;
        h = q;
    }
    if (h == -1) {
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
        M2C_FIELD(arg0, s8*, 0x61) -= 5;
        if (M2C_FIELD(arg0, s8*, 0x61) >= 0x1A) {
            M2C_FIELD(arg0, s8*, 0x61) = 0;
        }
        t = M2C_FIELD(arg0, s8*, 0x61);
        {
            // !FAKE: depin: dropping it breaks the match (53/61)
            register s32 m asm("$2");
            if (t >= 6) {
                m = t;
                M2C_FIELD(arg0, s16*, 0x7E) = m;
            } else {
                m = 5;
                M2C_FIELD(arg0, s16*, 0x7E) = m;
            }
        }
    }
}

#include "../shared/rock_11/func_800F8064.c"

#include "../shared/rock_11/func_800F8130.c"

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F81F8);
// clang-format on

#include "../shared/rock_11/func_800F82AC.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F8370(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 6;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 check_enemy_hits(void*);
s32 func_800FA664(u8* arg0);
extern s8 D_800970A2;
extern s32 D_800FD44C;

void func_800F8390(void* arg0) {
    s32 temp_v0;
    s8 temp_s1;

    temp_s1 = M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 4);
    if (temp_s1 != 1) {
        M2C_FIELD(arg0, s8*, 4) = 6;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    func_80017A04(arg0);
    (*(void (**)(void*))((M2C_FIELD(arg0, s8*, 5) << 2) + (s32)&D_800FD44C))(
        arg0);
    temp_v0 = check_enemy_hits(arg0);
    if (temp_v0 > 0) {
        if ((D_800970A2 != 0) || (temp_v0 == temp_s1)) {
            M2C_FIELD(arg0, s8*, 0x8A) = temp_s1;
        }
        M2C_FIELD(arg0, s8*, 0x5C) = 0x32;
    }
    if (func_800FA664(arg0) != 0) {
        M2C_FIELD(arg0, s8*, 0x8A) = 1;
    }
}

#include "../shared/rock_11/func_800F8454.c"

#include "common.h"

s32 func_800FA4F8(void* arg0, s16 arg1, s32 arg2);
extern u16 D_80097222;
#define CALL func_800FA4F8

void func_800F84A8(void* arg0, s32 arg1) {
    // !FAKE: depin: dropping it breaks the match (47/49)
    register s32 b asm("$2") = *((u8*)arg0 + 2);
    s32 kind = b & 0xF;
    // !FAKE: depin: dropping it breaks the match (5/49)
    register s32 one asm("$3") = 1;
#define ONE one
    if (kind == ONE) {
        goto c1;
    }
    if (kind < 2) {
        if (kind == 0) {
            goto c0;
        }
        goto end;
    }
    if (kind == 2) {
        goto c2;
    }
    goto end;
c0:
    arg1 = CALL((u8*)arg0 + 0xC, D_80097222 + 0xF2, 0x50000);
    goto end;
c1:
    arg1 = CALL((u8*)arg0 + 0xC, D_80097222 + 0xC2, 0x50000);
    goto end;
c2:
    arg1 = CALL((u8*)arg0 + 0xC, D_80097222 + 0x92, 0x50000);
end:
    if (arg1 != 0) {
        *(s16*)((u8*)arg0 + 0x7C) = 0xE10;
        *((u8*)arg0 + 5) += 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
void func_800FA31C(void* arg0);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FD464[];
extern u8 D_800FDA78[];

#define F856C(o, type, off) (*(type*)((u8*)(o) + (off)))

void func_800F856C(void* arg0) {
    s32 i;

    if (--F856C(arg0, s16, 0x7C) == 0) {
        for (i = 0; i < 0x13; i++) {
            func_80027BA0(0, background_objects[0].unk26 + 0x10 + i * 0x10,
                          F856C(arg0, s16, 0xE) & 0xFFF0, D_800FD464);
        }
        D_800FDA78[F856C(arg0, u8, 0x2) & 0xF] = 0;
        F856C(arg0, u8, 0x4) = 6;
        return;
    }
    if (F856C(arg0, s16, 0x7C) & 1) {
        func_800FA31C(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */
extern u16 D_800FDA7C;
extern u16 D_800FDA7E;

void func_800F8638(void* arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    if (temp_v1 == 0) {
        D_800FDA7C -= 1;
    } else if (temp_v1 == 0x10) {
        D_800FDA7E -= 1;
    }
    ((M2C_UNK(*)())clear_object_slot)();
}

#define func_8003744C func_800F869C
#define D_80073C1C D_800FD364
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F86D8.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F6E4C(); /* extern */

void func_800F8778(void* arg0) {
    M2C_FIELD(arg0, s8*, 7) = 0;
    func_800F6E4C();
}

#define func_8003744C func_800F8798
#define D_80073C1C D_800FD370
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800FA4C8(struct X4_MainObj* self);
extern u8 D_800CCF5F;
extern u8 D_800E9B80[];

void func_800F87D4(void* arg0) {
    u16 tbl[4];
    u32 r;

    __builtin_memcpy((u8*)tbl, (u8*)D_800E9B80, 8);
    func_800FA4C8(arg0);
    set_animation(arg0, 1);
    M2C_FIELD(arg0, u16*, 0x7C) = tbl[D_800CCF5F];
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
    r = random_byte();
    M2C_FIELD(arg0, u8*, 6)++;
    M2C_FIELD(arg0, u8*, 0x89) = r % 24 + 8;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F9E00(u8* arg0, u8 arg1);
extern s8 D_800CCF5C;

void func_800F8894(u8* arg0) {
    s8 state = *(s8*)(arg0 + 0x45);

    if (state == 1) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        if (D_800CCF5C / 2 >= *(s8*)(arg0 + 0x5C)) {
            func_800F9E00(arg0, 1);
        } else {
            func_800F9E00(arg0, 0);
        }
    } else if (state == 2) {
        set_animation(arg0, 1);
        {
            u32 r;
            {
                // !FAKE: depin: dropping it breaks the match (64/66)
                register s32 k asm("$2") = 0x5A;
                *(s16*)(arg0 + 0x7E) = k;
            }
            r = random_byte();
            arg0[6]--;
            *(u8*)(arg0 + 0x89) = r % 24 + 8;
        }
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F899C(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 4;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800F89AC
#define D_80073C1C D_800FD380
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F89E8.c"

#include "../shared/rock_11/func_800F8A28.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800FA4C8(struct X4_MainObj* self);
extern struct X4_BackgroundObj background_objects[3];

void func_800F8A7C(struct X4_MainObj* self) {
    struct X4_BackgroundObj* bg;

    play_sound(2, 0x48, self);
    set_animation(self, 5);
    bg = &background_objects[0];
    self->x_pos.i.hi = bg->unk26 + 0xA8;
    self->y_pos.i.hi = bg->unk2A + 0x90;
    func_800FA4C8(self);
    self->unk6++;
}

#include "../shared/rock_11/func_800F8AF0.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
void func_800FA4C8(struct X4_MainObj* self);

void func_800F8B44(struct X4_MainObj* self) {
    func_800FA4C8(self);
    if (self->collision_flags & 8) {
        play_sound(2, 0x49, self);
        func_8002943C(8, 3, 1);
        set_animation(self, 4);
        {
            // !FAKE: the incremented byte lives in the first return register
            register s32 next asm("$2") = (u8)self->unk6 + 1;
            self->unk7 = 0;
            self->unk6 = next;
        }
        return;
    }
    move_object(self);
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
void func_800F9E00(u8* arg0, u8 arg1);

void func_800F8BC0(u8* arg0) {
    s8 state = arg0[0x45];

    if (state == 1) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x4B, arg0);
        func_800F9E00(arg0, 0x10);
        func_800F9E00(arg0, 0x11);
    } else if (state == 2) {
        arg0[6]++;
    } else if (state == 3) {
        play_sound(2, 0x4A, arg0);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F8C84(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 7) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 4;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "../shared/rock_11/func_800F8CA4.c"

#define func_8003744C func_800F8CD8
#define D_80073C1C D_800FD39C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F8D14.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F8D80(void* arg0) {
    M2C_FIELD(arg0, s8*, 5) = 4;
    M2C_FIELD(arg0, s8*, 6) = 0;
}

#define func_8003744C func_800F8D90
#define D_80073C1C D_800FD3A4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F8DCC.c"

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F8E14);
// clang-format on

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9EB4(u8* arg0, u8 arg1, s16 arg2);

void func_800F8E50(void* arg0) {
    s8 kind;
    s32 one;

    kind = M2C_FIELD(arg0, s8*, 0x45);
    one = 1;
    if (kind == one) {
        play_sound(2, 0x25, arg0);
        play_sound(2, 0x47, arg0);
        func_800F9EB4(arg0, 0x30, 0);
        func_800F9EB4(arg0, 0x30, 0x400);
        func_800F9EB4(arg0, 0x30, 0x800);
        func_800F9EB4(arg0, 0x30, 0xC00);
        func_800F9EB4(arg0, 0x30, 0x200);
        func_800F9EB4(arg0, 0x30, 0x600);
        func_800F9EB4(arg0, 0x30, 0xA00);
        func_800F9EB4(arg0, 0x30, 0xE00);
    } else if (kind == 2) {
        s32 t;
        t = M2C_FIELD(arg0, u8*, 0x8C) - 1;
        M2C_FIELD(arg0, u8*, 0x8C) = t;
        if ((t << 24) == 0) {
            M2C_FIELD(arg0, u8*, 0x5) = 4;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        } else {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            M2C_FIELD(arg0, u8*, 0x6) = one;
        }
    }
}

#define func_8003744C func_800F8F78
#define D_80073C1C D_800FD3B4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F8FB4.c"

#include "../shared/rock_11/func_800F900C.c"

#include "common.h"
#include "mmx6/x4.h"

void func_800FA4C8(struct X4_MainObj* self);
extern s8 D_800CCF5C;

void func_800F90A0(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        func_800FA4C8(self);
        self->unk7C = 8;
        if (self->unk7E != 0) {
            self->unk7E--;
            if (++self->hp >= D_800CCF5C) {
                self->hp = D_800CCF5C;
                self->unk6++;
            }
        } else {
            self->unk6++;
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F9148);
// clang-format on

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F9EB4(u8* arg0, u8 arg1, s16 arg2);

void func_800F9184(u8* arg0) {
    s8 state = arg0[0x45];

    if (state == 1) {
        play_sound(2, 0x25, arg0);
        play_sound(2, 0x47, arg0);
        func_800F9EB4(arg0, 0x30, 0);
        func_800F9EB4(arg0, 0x30, 0x400);
        func_800F9EB4(arg0, 0x30, 0x800);
        func_800F9EB4(arg0, 0x30, 0xC00);
        func_800F9EB4(arg0, 0x30, 0x200);
        func_800F9EB4(arg0, 0x30, 0x600);
        func_800F9EB4(arg0, 0x30, 0xA00);
        func_800F9EB4(arg0, 0x30, 0xE00);
    } else if (state == 2) {
        if (--((s8*)arg0)[0x8C] == 0) {
            *(s16*)(arg0 + 0x84) = 1;
            arg0[5] = 4;
            arg0[6] = 0;
        } else {
            arg0[6]--;
        }
    }
}

#define func_8003744C func_800F92A0
#define D_80073C1C D_800FD3C8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F92DC.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 random_byte();
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800FA06C(void* arg0, u8 arg1);
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E9B88[];
extern u16 D_800FDA7E;
#define D_800FDA7E (*(s16*)&D_800FDA7E)

void func_800F9340(void* arg0) {
    s8 buf[4];
    s16 i;
    // !FAKE: depin: dropping it breaks the match (81/83)
    register s32 n asm("$4");
    // !FAKE: depin: dropping it breaks the match (77/83)
    register s32 v asm("$2");
    s8 t;

    __builtin_memcpy(buf, D_800E9B88, 4);
    t = *(s8*)((u8*)arg0 + 0x45);

    if (t == 1) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x4D, arg0);
        if (buf[(u8)g_playthrough_state.player_initial_data[0x46]] > 0) {
            i = 0;
            do {
                if (D_800FDA7E >= 10) {
                    break;
                }
                func_800FA06C(arg0, 0x10);
                i++;
                v = i;
                n = v < buf[(u8)g_playthrough_state.player_initial_data[0x46]];
            } while (n);
        }
    } else if (t == 2) {
        *((u8*)arg0 + 6) += 1;
    }
}
#undef D_800FDA7E

#include "../shared/rock_11/func_800F948C.c"

#define func_8003744C func_800F94A0
#define D_80073C1C D_800FD3FC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F94DC.c"

#include "../shared/rock_11/func_800F9524.c"

#define func_8003744C func_800F9588
#define D_80073C1C D_800FD3D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800FA150(void*, s32);
extern s16 D_800970AA;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E9B8C[];
extern s8 D_800FD2EC[];
extern u16 D_800FDA7C;
#define D_800FDA7C (*(s16*)&D_800FDA7C)

void func_800F95C4(void* arg0) {
    s8 buf[4];
    s8 t;

    __builtin_memcpy(buf, D_800E9B8C, 4);
    set_animation(arg0, 8);
    if (D_800FDA7C <
        (t = D_800FD2EC[(u8)g_playthrough_state.player_initial_data[0x46]])) {
        if ((random_byte() & 0xF) >=
            buf[(u8)g_playthrough_state.player_initial_data[0x46]]) {
            func_800FA150(arg0, 1);
        }
    }
    if (*(s16*)((u8*)arg0 + 0xA) < D_800970AA) {
        *((u8*)arg0 + 0x15) = 0x40;
        *(s32*)((u8*)arg0 + 0x20) = 0xFFFB0000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    } else {
        *((u8*)arg0 + 0x15) = 0;
        *(s32*)((u8*)arg0 + 0x20) = 0x50000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    }
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *((u8*)arg0 + 6) += 1;
}
#undef D_800FDA7C

#include "../shared/rock_11/func_800F96E0.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F6E4C(); /* extern */

void func_800F9780(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s16*, 0x84) = 0x28;
        func_800F6E4C();
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
void func_800FA150(void*, s32);
extern s16 D_800970AA;
extern u8 D_800E9B8C[];

void func_800F97BC(void* arg0) {
    s8 buf[4];

    __builtin_memcpy(buf, D_800E9B8C, 4);
    set_animation(arg0, 8);
    func_800FA150(arg0, 1);
    if (*(s16*)((u8*)arg0 + 0xA) < D_800970AA) {
        *((u8*)arg0 + 0x15) = 0x40;
        *(s32*)((u8*)arg0 + 0x20) = 0xFFFB0000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    } else {
        *((u8*)arg0 + 0x15) = 0;
        *(s32*)((u8*)arg0 + 0x20) = 0x50000;
        *(s32*)((u8*)arg0 + 0x28) = -0x4000;
    }
    *(s32*)((u8*)arg0 + 0x24) = 0;
    *(s32*)((u8*)arg0 + 0x2C) = 0;
    *((u8*)arg0 + 6) = 1;
}

#define func_8003744C func_800F9864
#define D_80073C1C D_800FD3E4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F98A0.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800F6E4C(); /* extern */

void func_800F98E0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 0x8A) = 0;
        func_800F6E4C();
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F9910(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F9924(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F9938(void* arg0) {
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800F6E4C(); /* extern */

void func_800F994C(void) {
    func_800F6E4C();
}

#define func_8003744C func_800F996C
#define D_80073C1C D_800FD404
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK); /* extern */

void func_800F99A8(void* arg0) {
    func_8003D308(0x14, 0x40);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* alloc_class3_slot();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern struct X4_EngineObj g_playthrough_state;
extern s8* D_800FDA74;

void func_800F99E0(u8* arg0) {
    s8 s;
    s8* p;

    if (g_playthrough_state.unkF == 0) {
        s = D_800970A5;
        if (s == 0x14) {
            if (g_playthrough_state.stage != 0xC) {
                func_8003D308(0x1D, 0x40);
            }
            p = alloc_class3_slot();
            if (p != 0) {
                p[0] = 1;
                p[1] = 0x18;
                D_800FDA74 = p;
            }
            *(s16*)(arg0 + 0x7C) = s;
            arg0[6]++;
        }
    }
}

#include "common.h"
#define M2C_UNK s32

s32 random_byte();
void func_800F9F7C(void* arg0, M2C_UNK arg1, M2C_UNK arg2);
extern s16 D_800FDA80;

void func_800F9A80(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == -1) {
        *(s16*)(arg0 + 0x7C) = 2;
        if (--*(s16*)(arg0 + 0x7E) == 0) {
            arg0[6]++;
            return;
        }
        {
            s16* p = &D_800FDA80;
            s32 v = random_byte() + 0xFF;
            *p += v;
            func_800F9F7C(arg0, 0, *p);
        }
    }
}

#include "../shared/rock_11/func_800F9B24.c"

#define func_800F4BA8 func_800F9B80
#include "../shared/rock_04/func_800F4BA8.c"
#undef func_800F4BA8

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80040498(); /* extern */

void func_800F9BC4(void* arg0) {
    if (func_80040498() == 0) {
        M2C_FIELD(arg0, s16*, 0x7E) = 3;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#define func_800F4D48 func_800F9C00
#include "../shared/rock_04/func_800F4D48.c"
#undef func_800F4D48

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8003D330();    /* extern */
M2C_UNK func_800F6E4C(s32); /* extern */

void func_800F9C84(s32 arg0) {
    func_8003D330();
    func_800F6E4C(arg0);
}

#define func_8003744C func_800F9CB0
#define D_80073C1C D_800FD42C
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800F9CEC.c"

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800F9D8C);
// clang-format on

#include "common.h"

void func_800F9DC8(void) {
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_800FCEDC;
extern M2C_UNK D_800FCEE0;

void func_800F9DD0(void* arg0) {
    M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FCEDC;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FCEE0;
    if (M2C_FIELD(arg0, u8*, 0x8A) != 0) {
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = NULL;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = NULL;
    }
}

#include "../shared/rock_11/func_800F9E00.c"

#include "../shared/rock_11/func_800F9EB4.c"

#include "../shared/rock_11/func_800F9F7C.c"

#include "common.h"

void* enemy_slot_alloc();
extern u16 D_800FDA7E;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800FA06C(void* arg0, u8 arg1) {
    void* obj;

    obj = enemy_slot_alloc();
    if (obj != 0) {
        UB(obj, 0) = 0x41;
        UB(obj, 1) = 0x3A;
        UB(obj, 0x15) = UB(arg0, 0x15);
        UB(obj, 2) = arg1;
        UH(obj, 0xA) = UH(arg0, 0xA);
        UH(obj, 8) = 0;
        UH(obj, 0xE) = UH(arg0, 0xE);
        UH(obj, 0xC) = 0;
        UH(obj, 0x42) = UH(arg0, 0x42) & 0x7FFF;
        W(obj, 0x30) = W(arg0, 0x30);
        W(obj, 0x3C) = W(arg0, 0x3C);
        UH(obj, 0x40) = UH(arg0, 0x40);
        UB(obj, 0x14) = UB(arg0, 0x14);
        if (SB(arg0, 2) == 0) {
            P(obj, 0x80) = arg0;
        } else {
            P(obj, 0x80) = P(arg0, 0x80);
        }
        D_800FDA7E += 1;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800FA150);
// clang-format on

#include "../shared/rock_11/func_800FA234.c"

#include "../shared/rock_11/func_800FA31C.c"

#include "../shared/rock_11/func_800FA418.c"

#define func_80042C18 func_800FA4C8
#include "../shared/commander_yammark/func_80042C18.c"
#undef func_80042C18

#include "../shared/rock_11/func_800FA4F8.c"

#include "../shared/rock_11/func_800FA584.c"

#include "../shared/rock_11/func_800FA630.c"

#include "../shared/rock_11/func_800FA664.c"

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800FA72C);
// clang-format on

#include "../shared/rock_11/func_800FA76C.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot(); /* extern */

void func_800FA7E0(void* arg0) {
    void* temp_v1;

    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x20) {
        temp_v1 = M2C_FIELD(arg0, void**, 0x7C);
        M2C_FIELD(temp_v1, u8*, 7) = (u8)(M2C_FIELD(temp_v1, u8*, 7) - 1);
    }
    ((M2C_UNK(*)())clear_object_slot)();
}

#define func_8003744C func_800FA82C
#define D_80073C1C D_800FD4AC
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800FD46C[];
extern s32 D_800FD478[];

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800FA868(void* arg0) {
    F(s32*, 0x50) = D_800FD46C;
    F(s32, 0x54) = 0;
    F(s32*, 0x68) = D_800FD478;
    {
        // !FAKE: pin the byte test into the first return register
        register s32 t asm("$2") = F(u8, 0x15);

        if (t == 0) {
            F(s32, 0x20) = 0xFFFEC000;
        } else {
            F(s32, 0x20) = 0x14000;
        }
    }
    if ((F(u8, 0x2) & 0xF) == 1) {
        F(s32, 0x20) = F(s32, 0x20) * 2;
    }
    F(s32, 0x24) = 0;
    F(u8, 0x6) = F(u8, 0x6) + 1;
}

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AE;
extern u8 D_800FD470[];
extern u8 D_800FD474[];
extern u8 D_800FD47C[];
extern u8 D_800FD480[];

void func_800FA8DC(void* self) {
    play_sound(2, 0x46, self);
    if (M2C_FIELD(self, s16*, 0xE) > D_800970AE) {
        set_animation(self, 0xA);
        M2C_FIELD(self, void**, 0x50) = D_800FD470;
        M2C_FIELD(self, void**, 0x68) = D_800FD47C;
        M2C_FIELD(self, s32*, 0x24) = 0x18000;
        M2C_FIELD(self, u8*, 0x7) = 0;
        M2C_FIELD(self, u8*, 0x6)++;
    } else {
        set_animation(self, 0xB);
        M2C_FIELD(self, void**, 0x50) = D_800FD474;
        M2C_FIELD(self, void**, 0x68) = D_800FD480;
        M2C_FIELD(self, s32*, 0x24) = 0xFFFE8000;
        M2C_FIELD(self, u8*, 0x7) = 1;
        M2C_FIELD(self, u8*, 0x6)++;
    }
    M2C_FIELD(self, s32*, 0x20) = 0;
    if ((M2C_FIELD(self, u8*, 0x2) & 0xF) == 1) {
        M2C_FIELD(self, s32*, 0x24) *= 2;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA9C4(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_8003744C func_800FA9E4
#define D_80073C1C D_800FD4C0
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u16 D_80097222;
extern s32 D_800FD484;
extern s32 D_800FD488;

void func_800FAA20(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FD484;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FD488;
    M2C_FIELD(arg0, s16*, 0xE) = D_80097222 + 0x120;
    if (!(M2C_FIELD(arg0, u8*, 2) & 0xF)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
    }
    M2C_FIELD(arg0, s16*, 0x88) = 0xC;
    M2C_FIELD(arg0, s16*, 0x8A) = 4;
    M2C_FIELD(arg0, u8*, 6) += 1;
}

#include "../shared/rock_11/func_800FAA98.c"

#define func_8003744C func_800FAAFC
#define D_80073C1C D_800FD4C8
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "../shared/rock_11/func_800FAB38.c"

#include "../shared/rock_11/func_800FABA0.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FABF8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_8003744C func_800FAC14
#define D_80073C1C D_800FD4D4
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"
#include "psyq/libgte.h"

extern s32 D_800FD484;
extern s32 D_800FD488;

void func_800FAC50(u8* arg0) {
    s32 m;

    arg0[3] = 1;
    *(s32**)(arg0 + 0x50) = &D_800FD484;
    *(s32**)(arg0 + 0x54) = &D_800FD488;
    m = rcos(*(s32*)(arg0 + 0x84)) * 0x10;
    *(s32*)(arg0 + 0x20) = (m * 2 + m) * 2;
    m = -rsin(*(s32*)(arg0 + 0x84)) * 0x10;
    *(s32*)(arg0 + 0x24) = (m * 2 + m) * 2;
    arg0[6]++;
}

#include "common.h"

#define M2C_UNK s32

M2C_UNK move_object(); /* extern */

void func_800FACD8(void) {
    ((M2C_UNK(*)())move_object)();
}

#include "../shared/rock_11/func_800FACF8.c"

#include "common.h"

#define M2C_UNK s32

M2C_UNK clear_object_slot(); /* extern */

void func_800FAD90(void) {
    ((M2C_UNK(*)())clear_object_slot)();
}

#include "../shared/rock_11/func_800FADB0.c"

#include "../shared/rock_11/func_800FAE34.c"

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FAF0C(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s8*, 3) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FAF40(void* arg0) {
    void* temp_a0;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, u8*, 3) = 0U;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    temp_a0 = M2C_FIELD(arg0, void**, 0x50);
    M2C_FIELD(arg0, u16*, 0xA) = (u16)M2C_FIELD(temp_a0, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) = (u16)M2C_FIELD(temp_a0, u16*, 0xE);
    M2C_FIELD(arg0, u8*, 3) = (u8)M2C_FIELD(temp_a0, u8*, 3);
}

#define func_8003744C func_800FAF94
#define D_80073C1C D_800FD500
#include "../shared/entity/state_dispatch.c"
#undef func_8003744C
#undef D_80073C1C

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK move_object();                      /* extern */

void func_800FAFD0(void* arg0) {
    ((M2C_UNK(*)())move_object)();
    if (func_8002CBFC(arg0, 0x20, 0x20) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", func_800FB020);
// clang-format on

#include "../shared/rock_11/func_800FB068.c"

#define func_80041AB8 func_800FB13C
#define D_80075FD8 D_800FD508
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FB1B4(u8* arg0); /* extern */
extern s8 D_800972A4;

void func_800FB178(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x15) = 0;
    M2C_FIELD(arg0, s8*, 0x14) = 0;
    M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    D_800972A4 = 5;
    ((void (*)())func_800FB1B4)();
}

#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FB1B4(u8* arg0) {
    s32 one = 1;

    *(s16*)(arg0 + 0x16) = one;
    *(s8*)(arg0 + 0x15) += arg0[0x16];
    if (*(s8*)(arg0 + 0x15) >= 0) {
        if (*(s8*)(arg0 + 0x15) < 0x10) {
            return;
        }
        if (++*(s8*)(arg0 + 0x14) >= 3) {
            *(s8*)(arg0 + 0x14) = 0;
        }
    } else {
        if (*(s8*)(arg0 + 0x15) >= -0xF) {
            return;
        }
        if (--*(s8*)(arg0 + 0x14) < 0) {
            *(s8*)(arg0 + 0x14) = 2;
        }
    }
    {
        s32 t = *(s8*)(arg0 + 0x14);
        background_objects[2].unk4C = one;
        background_objects[2].y_pos.u.hi = t << 8;
    }
    *(s8*)(arg0 + 0x15) = 0;
}

// clang-format off
INCLUDE_ASM("asm/rock_11/nonmatchings/E9860", D_800FB26C);
// clang-format on
