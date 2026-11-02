// clang-format off
INCLUDE_ASM("asm/rock_21/nonmatchings/E9860", D_800E9860);
// clang-format on

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CD40C;
extern M2C_UNK D_800ED240;
extern M2C_UNK D_800ED440;
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern M2C_UNK D_800F1E40;
extern M2C_UNK D_800F2040;
extern s16 D_800F2240;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800E9864(u8* arg0) {
    if ((u8)D_800CD40C == 2) {
        {
            u8* s = (u8*)SPAD28;
            __builtin_memcpy((u8*)&D_800ED240, s + 0xC00, 0x20);
            __builtin_memcpy((u8*)&D_800ED640, s + 0xE00, 0x200);
        }
        __builtin_memcpy((u8*)&D_800EFA40, (u8*)(SPAD28 + 0x1000), 0x200);
        __builtin_memcpy((u8*)&D_800F1E40, (u8*)(SPAD28 + 0xC20), 0x20);
        D_800F2240 = 0x60;
        D_800F2242 = 0x60;
        D_800F2244 = 0x60;
        func_8002B410(&D_800ED440, &D_800ED240, 0x10, 0x60, 0x60);
        load_palette(0x60, &D_800ED440, 1);
        func_8002B410(&D_800EE840, &D_800ED640, 0x100, D_800F2242, 0x60);
        load_palette(0x70, &D_800EE840, 0x10);
        func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, D_800F2244, 0x60);
        load_palette(0x80, &D_800F0C40, 0x10);
        func_8002B410(&D_800F2040, &D_800F1E40, 0x10, D_800F2240, 0x60);
        load_palette(0x61, &D_800F2040, 1);
        background_objects[0].x_pos.u.hi = 0;
        background_objects[0].y_pos.u.hi = 0;
        background_objects[0].unk4C = 1;
        background_objects[1].x_pos.u.hi = 0x200;
        background_objects[1].y_pos.u.hi = 0;
        background_objects[1].unk4C = 1;
        background_objects[2].x_pos.u.hi = 0x400;
        background_objects[2].y_pos.u.hi = 0;
        background_objects[2].unk4C = 1;
        background_objects[0].unk3 = 1;
        background_objects[1].unk3 = 1;
        background_objects[2].unk3 = 1;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED240;
extern M2C_UNK D_800ED440;
extern s16 D_800F2240;

void func_800E9C9C(u8* arg0) {
    s32 flag;

    if ((*(s16*)(arg0 + 4))++ >= 0x1E) {
        *(s16*)(arg0 + 4) = 0;
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag) {
        s32 i;

        D_800F2240 = 0;
        func_8002B410(&D_800ED440, &D_800ED240, 0x10, 0, 0x60);
        load_palette(0x60, &D_800ED440, 0x10);
        for (i = 0; i < 0x10; i++) {
            ((u16*)&D_800ED440)[i] = ((u16*)&D_800ED240)[i] & 0x7FFF;
        }
        load_palette(0x60, &D_800ED440, 0x10);
        background_objects[0].x_pos.u.hi = 0x200;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 0;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800E9DA8(u8* arg0) {
    func_8002B410(&D_800EE840, &D_800ED640, 0x100, ++D_800F2242, 0x60);
    load_palette(0x70, &D_800EE840, 0x10);
    func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, --D_800F2244, 0x60);
    load_palette(0x80, &D_800F0C40, 0x10);
    if (D_800F2244 == 0) {
        __builtin_memcpy((u8*)&D_800ED640, (u8*)(SPAD28 + 0x1200), 0x200);
        func_8002B410(&D_800EE840, &D_800ED640, 0x100, D_800F2242, 0x60);
        load_palette(0x90, &D_800EE840, 0x10);
        background_objects[1].x_pos.u.hi = 0x600;
        background_objects[1].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800E9FA4(u8* arg0) {
    func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, ++D_800F2244, 0x60);
    load_palette(0x80, &D_800F0C40, 0x10);
    func_8002B410(&D_800EE840, &D_800ED640, 0x100, --D_800F2242, 0x60);
    load_palette(0x90, &D_800EE840, 0x10);
    if (D_800F2242 == 0) {
        __builtin_memcpy((u8*)&D_800EFA40, (u8*)(SPAD28 + 0x1400), 0x200);
        func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, D_800F2244, 0x60);
        load_palette(0xA0, &D_800F0C40, 0x10);
        background_objects[2].x_pos.u.hi = 0x800;
        background_objects[2].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern s8 D_8008EAB0;
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800EA1A0(u8* arg0) {
    func_8002B410(&D_800EE840, &D_800ED640, 0x100, ++D_800F2242, 0x60);
    load_palette(0x90, &D_800EE840, 0x10);
    func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, --D_800F2244, 0x60);
    load_palette(0xA0, &D_800F0C40, 0x10);
    if (D_800F2244 == 0) {
        __builtin_memcpy((u8*)&D_800ED640, (u8*)(SPAD28 + 0x1600), 0x200);
        func_8002B410(&D_800EE840, &D_800ED640, 0x100, D_800F2242, 0x60);
        load_palette(0xB0, &D_800EE840, 0x10);
        background_objects[1].x_pos.u.hi = 0xA00;
        background_objects[1].unk4C = 1;
        D_8008EAB0 = 1;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800EA3A8(u8* arg0) {
    func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, ++D_800F2244, 0x60);
    load_palette(0xA0, &D_800F0C40, 0x10);
    func_8002B410(&D_800EE840, &D_800ED640, 0x100, --D_800F2242, 0x60);
    load_palette(0xB0, &D_800EE840, 0x10);
    if (D_800F2242 == 0) {
        __builtin_memcpy((u8*)&D_800EFA40, (u8*)(SPAD28 + 0x1800), 0x200);
        func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, D_800F2244, 0x60);
        load_palette(0xC0, &D_800F0C40, 0x10);
        background_objects[2].x_pos.u.hi = 0xC00;
        background_objects[2].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800EA5A4(u8* arg0) {
    func_8002B410(&D_800EE840, &D_800ED640, 0x100, ++D_800F2242, 0x60);
    load_palette(0xB0, &D_800EE840, 0x10);
    func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, --D_800F2244, 0x60);
    load_palette(0xC0, &D_800F0C40, 0x10);
    if (D_800F2244 == 0) {
        background_objects[1].x_pos.u.hi = 0xE00;
        background_objects[1].unk4C = 1;
        arg0[1]++;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800ED240;
extern M2C_UNK D_800ED440;
extern s16 D_800F2240;

void func_800EA6A4(u8* arg0) {
    s32 flag;

    if ((*(s16*)(arg0 + 4))++ >= 0x1E) {
        *(s16*)(arg0 + 4) = 0;
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag) {
        s32 i;

        D_800F2240 = 0;
        func_8002B410(&D_800ED440, &D_800ED240, 0x10, 0, 0x60);
        load_palette(0x60, &D_800ED440, 0x10);
        for (i = 0; i < 0x10; i++) {
            ((u16*)&D_800ED440)[i] = ((u16*)&D_800ED240)[i] & 0x7FFF;
        }
        load_palette(0x60, &D_800ED440, 0x10);
        background_objects[0].x_pos.u.hi = 0x1600;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 0;
        arg0[1]++;
    }
}

// clang-format off
INCLUDE_ASM("asm/rock_21/nonmatchings/E9860", func_800EA7B0);
// clang-format on

#include "common.h"

extern s16 D_800ED230;
extern void (*func_800ECBE8[])(u8*);
void func_800206C0(void);
void func_80025FB0();

void func_800EB70C(u8* arg0) {
    D_800ED230 = 1;
    func_800ECBE8[*(s8*)(arg0 + 1)](arg0);
    func_800206C0();
    func_80025FB0();
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK reset_level();   /* extern */
M2C_UNK func_8002C2B8(); /* extern */

void func_800EB764(void* arg0) {
    reset_level();
    func_8002C2B8();
    M2C_FIELD(arg0, s8*, 0x1F) = 0;
    M2C_FIELD(arg0, s8*, 0x24) = 0;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}

#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017E24(void);
M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);
void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
extern struct X4_BackgroundObj background_objects[3];

void func_800EB7A4(u8* arg0) {
    u8* base;
    u8* p;
    u8 i;

    i = 0;
    base = arg0 + 0x26;
    do {
        base[i] = 0;
        i++;
    } while (i < 0x10);
    ((void (*)())func_80017E24)(base);
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 0;
    *(s16*)(arg0 + 4) = 0;
    arg0[2] = 0;
    play_bgm_xa_track(7, 0x73);
    ((void (*)(M2C_UNK))SetDispMask)(1);
    arg0[1] = arg0[1] + 1;
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800ED240;
extern M2C_UNK D_800ED440;
extern s16 D_800F2240;

void func_800EB844(u8* arg0) {
    u16* src;
    u16* dst;
    s32 i;

    D_800F2240--;
    func_8002B410(&D_800ED440, &D_800ED240, 0x10, D_800F2240, 0x60);
    load_palette(0x60, &D_800ED440, 1);
    if (D_800F2240 == 0) {
        dst = (u16*)&D_800ED440;
        src = (u16*)&D_800ED240;
        for (i = 0xF; i >= 0; i--) {
            *dst++ = *src++ & 0x7FFF;
        }
        load_palette(0x60, &D_800ED440, 1);
        arg0[1]++;
    }
}

#include "common.h"

extern s8 D_800971FB;

static inline s32 func_800EB928_tick(u8* p) {
    if ((*(s16*)(p + 4))++ >= 0x186) {
        *(s16*)(p + 4) = 0;
        return 1;
    }
    return 0;
}

void func_800EB928(u8* arg0) {
    if (func_800EB928_tick(arg0)) {
        D_800971FB = 0;
        arg0[1] += 1;
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800ED640;
extern M2C_UNK D_800EE840;
extern s16 D_800F2242;

void func_800EB97C(void* arg0) {
    func_8002B410(&D_800EE840, &D_800ED640, 0x100, --D_800F2242, 0x60);
    load_palette(0x70, &D_800EE840, 0x10);
    if (D_800F2242 == 0) {
        *((u8*)arg0 + 1) += 1;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EBA18(void* self) {
    s32 done;
    u16 t;

    if ((u32)(F(u16, 4) - 0x1E) >= 0x385U) {
        background_objects[0].unk3 = 0;
    } else {
        background_objects[0].unk3 = 1;
    }
    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x3C0) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0x400;
        background_objects[0].unk4C = 1;
        F(u8, 1)++;
    }
}

#undef F

#include "../shared/rock_21/func_800EBAB4.c"

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EBB44(void* self) {
    s32 done;
    u16 t;

    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x1E) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0x600;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 0;
        F(u8, 1)++;
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EBBB0(void* self) {
    s32 done;
    u16 t;

    if ((u32)(F(u16, 4) - 0x1E) >= 0x385U) {
        background_objects[0].unk3 = 0;
    } else {
        background_objects[0].unk3 = 1;
    }
    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x3C0) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0x800;
        background_objects[0].unk4C = 1;
        F(u8, 1)++;
    }
}

#undef F

#define func_800EBAB4 func_800EBC4C
#define background_objects background_objects
#include "../shared/rock_21/func_800EBAB4.c"
#undef func_800EBAB4
#undef background_objects

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

void func_800EBCDC(void* arg0) {
    s32 var_v0;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0x1E) {
        M2C_FIELD(arg0, u16*, 4) = 0;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        background_objects[0].x_pos.i.hi = 0xA00;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 0;
        M2C_FIELD(arg0, u8*, 1) = M2C_FIELD(arg0, u8*, 1) + 1;
    }
}

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

void func_800EBD48(void* arg0) {
    s32 var_v0;
    u16 temp_v0;

    if ((u32)(M2C_FIELD(arg0, u16*, 4) - 0x1E) >= 0x385U) {
        background_objects[0].unk3 = 0;
    } else {
        background_objects[0].unk3 = 1;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0x3C0) {
        M2C_FIELD(arg0, u16*, 4) = 0;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        background_objects[0].x_pos.i.hi = 0xC00;
        background_objects[0].unk4C = 1;
        M2C_FIELD(arg0, u8*, 1) = M2C_FIELD(arg0, u8*, 1) + 1;
    }
}

#define func_800EBAB4 func_800EBDE4
#define background_objects background_objects
#include "../shared/rock_21/func_800EBAB4.c"
#undef func_800EBAB4
#undef background_objects

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EBE74(void* self) {
    s32 done;
    u16 t;

    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x1E) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0xE00;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 0;
        F(u8, 1)++;
    }
}

#undef F

#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

void func_800EBEE0(void* arg0) {
    s32 var_v0;
    u16 temp_v0;

    if ((u32)(M2C_FIELD(arg0, u16*, 4) - 0x1E) >= 0x385U) {
        background_objects[0].unk3 = 0;
    } else {
        background_objects[0].unk3 = 1;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = temp_v0 + 1;
    if ((s16)temp_v0 >= 0x3C0) {
        M2C_FIELD(arg0, u16*, 4) = 0;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        background_objects[0].x_pos.i.hi = 0x1000;
        background_objects[0].unk4C = 1;
        M2C_FIELD(arg0, u8*, 1) = M2C_FIELD(arg0, u8*, 1) + 1;
    }
}

#define func_800EBAB4 func_800EBF7C
#define background_objects background_objects
#include "../shared/rock_21/func_800EBAB4.c"
#undef func_800EBAB4
#undef background_objects

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EC00C(void* self) {
    s32 done;
    u16 t;

    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x1E) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0x1200;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 0;
        F(u8, 1)++;
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EC078(void* self) {
    s32 done;
    u16 t;

    if ((u32)(F(u16, 4) - 0x1E) >= 0x385U) {
        background_objects[0].unk3 = 0;
    } else {
        background_objects[0].unk3 = 1;
    }
    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x3C0) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0x1400;
        background_objects[0].unk4C = 1;
        F(u8, 1)++;
    }
}

#undef F

#define func_800EBAB4 func_800EC114
#define background_objects background_objects
#include "../shared/rock_21/func_800EBAB4.c"
#undef func_800EBAB4
#undef background_objects

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EC1A4(void* self) {
    s32 done;
    u16 t;

    if ((u32)(F(u16, 4) - 0x1E) >= 0x385U) {
        background_objects[0].unk3 = 0;
    } else {
        background_objects[0].unk3 = 1;
    }
    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x3C0) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0x1800;
        background_objects[0].unk4C = 1;
        F(u8, 1)++;
    }
}

#undef F

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800EC240(void* self) {
    s32 done;
    u16 t;

    if ((u32)(F(u16, 4) - 0x1E) >= 0x385U) {
        background_objects[0].unk3 = 0;
    } else {
        background_objects[0].unk3 = 1;
    }
    t = F(u16, 4);
    F(u16, 4) = t + 1;
    if ((s16)t >= 0x3C0) {
        F(u16, 4) = 0;
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        background_objects[0].x_pos.u.hi = 0x1A00;
        background_objects[0].unk4C = 1;
        F(u8, 1)++;
    }
}

#undef F

#define func_800EBAB4 func_800EC2DC
#define background_objects background_objects
#include "../shared/rock_21/func_800EBAB4.c"
#undef func_800EBAB4
#undef background_objects

#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800EFA40;
extern M2C_UNK D_800F0C40;
extern M2C_UNK D_800F1E40;
extern M2C_UNK D_800F2040;
extern s16 D_800F2242;
extern s16 D_800F2244;

void func_800EC36C(u8* arg0) {
    func_8002B410(&D_800F0C40, &D_800EFA40, 0x100, ++D_800F2244, 0x60);
    load_palette(0xC0, &D_800F0C40, 0x10);
    func_8002B410(&D_800F2040, &D_800F1E40, 0x10, --D_800F2242, 0x60);
    load_palette(0x61, &D_800F2040, 1);
    if (D_800F2242 == 0) {
        arg0[1]++;
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC458(void* arg0) {
    s32 var_v0;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x438) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800F1E40;
extern M2C_UNK D_800F2040;
extern s16 D_800F2242;

void func_800EC4A8(u8* arg0) {
    func_8002B410(&D_800F2040, &D_800F1E40, 0x10, ++D_800F2242, 0x60);
    load_palette(0x61, &D_800F2040, 1);
    if (D_800F2242 == 0x60) {
        arg0[1]++;
    }
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */

void func_800EC54C(void* arg0) {
    s32 var_v0;
    u16 temp_v0;
    void* temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x78) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_v0_2 = alloc_sprite_slot();
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s8*, 0) = 1;
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 2) = 0;
            M2C_FIELD(temp_v0_2, s16*, 0xA) = 0x100;
            M2C_FIELD(temp_v0_2, s16*, 0xE) = 0x20;
        }
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */

void func_800EC5E8(void* arg0) {
    s32 var_v0;
    u16 temp_v0;
    void* temp_v0_2;
    s32 one;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x28) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_v0_2 = alloc_sprite_slot();
        one = 1;
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 0) = one;
            M2C_FIELD(temp_v0_2, s8*, 2) = one;
            M2C_FIELD(temp_v0_2, s16*, 0xA) = 0x100;
            M2C_FIELD(temp_v0_2, s16*, 0xE) = 0x40;
        }
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */

void func_800EC684(void* arg0) {
    s32 var_v0;
    u16 temp_v0;
    void* temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x28) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_v0_2 = alloc_sprite_slot();
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0_2, s8*, 0) = 1;
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 2) = 2;
            M2C_FIELD(temp_v0_2, s16*, 0xA) = 0x80;
            M2C_FIELD(temp_v0_2, s16*, 0xE) = 0x60;
        }
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */

void func_800EC724(void* arg0) {
    s32 var_v0;
    u16 temp_v0;
    void* temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x28) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_v0_2 = alloc_sprite_slot();
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0_2, s8*, 0) = 1;
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 2) = 3;
            M2C_FIELD(temp_v0_2, s16*, 0xA) = 0x180;
            M2C_FIELD(temp_v0_2, s16*, 0xE) = 0x80;
        }
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */

void func_800EC7C4(void* arg0) {
    s32 var_v0;
    u16 temp_v0;
    void* temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16*, 4);
    M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
    if ((s16)temp_v0 >= 0x28) {
        M2C_FIELD(arg0, u16*, 4) = 0U;
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_v0_2 = alloc_sprite_slot();
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0_2, s8*, 0) = 1;
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 2) = 0x17;
            M2C_FIELD(temp_v0_2, s16*, 0xA) = 0x150;
            M2C_FIELD(temp_v0_2, s16*, 0xE) = 0xA0;
        }
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */

void func_800EC864(void* arg0) {
    s32 var_v0;
    u16 temp_v0;
    void* temp_v0_2;

    if (M2C_FIELD(arg0, u8*, 0x5F) & 0x30) {
        temp_v0 = M2C_FIELD(arg0, u16*, 4);
        M2C_FIELD(arg0, u16*, 4) = (u16)(temp_v0 + 1);
        if ((s16)temp_v0 >= 0x28) {
            M2C_FIELD(arg0, u16*, 4) = 0U;
            var_v0 = 1;
        } else {
            var_v0 = 0;
        }
        if (var_v0 == 0) {
            return;
        }
        temp_v0_2 = alloc_sprite_slot();
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0_2, s8*, 0) = 1;
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 2) = 0x18;
            M2C_FIELD(temp_v0_2, s16*, 0xA) = 0x150;
            M2C_FIELD(temp_v0_2, s16*, 0xE) = 0xC0;
        }
    }
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}

#include "../shared/rock_21/func_800EC918.c"

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK); /* extern */
void* alloc_sprite_slot();      /* extern */
#include "mmx6/state.h"

void func_800EC95C(void* arg0) {
    void* temp_v0;
    void* temp_v0_2;
    void* temp_v0_3;

    if (D_80097420.transition.active == 0) {
        temp_v0 = alloc_sprite_slot();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s8*, 0) = 1;
            M2C_FIELD(temp_v0, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0, s8*, 2) = 0x28;
        }
        temp_v0_2 = alloc_sprite_slot();
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0_2, s8*, 0) = 1;
            M2C_FIELD(temp_v0_2, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_2, s8*, 2) = 0x29;
        }
        temp_v0_3 = alloc_sprite_slot();
        if (temp_v0_3 != 0) {
            M2C_FIELD(temp_v0_3, s8*, 0) = 1;
            M2C_FIELD(temp_v0_3, s8*, 1) = 0x38;
            M2C_FIELD(temp_v0_3, s8*, 2) = 0x2A;
        }
        ((void (*)(s32))func_800139A0)(8);
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
    }
}

#define func_8001DBD8 func_800ECA18
#include "../shared/save_file/func_8001DBD8.c"
#undef func_8001DBD8

#define func_800EC918 func_800ECA44
#include "../shared/rock_21/func_800EC918.c"
#undef func_800EC918

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK create_task(M2C_UNK, M2C_UNK*);
M2C_UNK func_800133A0();
void stop_cd_audio();
extern M2C_UNK D_8001D0E4;
extern s32 D_8008EC0C;
extern M2C_UNK D_800CD3F8;
extern s8 D_800F2246;

void func_800ECA88(void) {
    if (D_80097420.transition.active == 0) {
        M2C_FIELD(&D_800CD3F8, s8*, 0) = 3;
        M2C_FIELD(&D_800CD3F8, s8*, 1) = 0;
        M2C_FIELD(&D_800CD3F8, s8*, 2) = 0;
        M2C_FIELD(&D_800CD3F8, s8*, 3) = 0;
        D_800F2246 = 1;
        D_8008EC0C = 0;
        stop_cd_audio();
        create_task(0, &D_8001D0E4);
        func_800133A0();
    }
}

#include "common.h"

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot(); /* extern */

void func_800ECAF8(void* arg0) {
    void* temp_v0;

    temp_v0 = alloc_sprite_slot();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8*, 0) = 0x41;
        M2C_FIELD(temp_v0, s8*, 1) = 0x38;
        M2C_FIELD(temp_v0, s8*, 2) = (s8)(M2C_FIELD(arg0, u8*, 2) + 1);
        M2C_FIELD(temp_v0, s32*, 0x54) = (s32)M2C_FIELD(arg0, s32*, 0x54);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_800CCED1;

void func_800ECB50(void* arg0) {
    if ((D_800CCED1 >= 0x28) && ((u32)(M2C_FIELD(arg0, u8*, 2) - 0x28) >= 3U)) {
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}

#define func_800FA8A0 func_800ECB8C
#include "../shared/rock_22/func_800FA8A0.c"
#undef func_800FA8A0

#define func_80041AB8 func_800ECBAC
#define D_80075FD8 D_800ECCE8
#include "../shared/save_file/func_80041AB8.c"
#undef func_80041AB8
#undef D_80075FD8

// clang-format off
INCLUDE_ASM("asm/rock_21/nonmatchings/E9860", func_800ECBE8);
// clang-format on
