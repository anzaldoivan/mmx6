#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
s32 func_8002CFB0(void* arg);          /* extern */
M2C_UNK func_8003AFF4(s32);            /* extern */
M2C_UNK func_8003B054(void*);          /* extern */
void func_8003D394(void* arg0);        /* extern */
s32 func_8003E174(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EC028();                   /* extern */

M2C_UNK func_80036FBC(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        ((void (*)())func_8003B054)();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        var_v0 = func_8003E174(arg0);
    } else {
        if (func_801EA560(arg0) != 0) {
            return;
        }
        var_v0 = func_801EC028(arg0);
    }
    if (var_v0 != 0) {
        return;
    }
    func_80017A04(arg0);
    func_8002CFB0(arg0);
    func_8003D394(arg0);
    if (--M2C_FIELD(arg0, s8*, 0x8A) == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    func_8003F508(arg0, 0xB);
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8003A628(void*);
M2C_UNK func_8003CCBC();
extern void (*D_80073C04[])(struct X4_MainObj*);

void func_800370B0(struct X4_MainObj* self) {
    if (func_8003A628(self) == 0) {
        ((void (*)())func_80017A04)(self);
        D_80073C04[self->unk6](self);
    }
    if (self->unk5 != 0xC && self->terrain_box != 0) {
        ((void (*)())func_8003CCBC)(self);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();      /* extern */
s32 func_80039984(void*);     /* extern */
s32 try_enter_ladder(void*);     /* extern */
M2C_UNK func_8003AFF4(s32);   /* extern */
M2C_UNK func_8003B054(void*); /* extern */
void func_8003B360(void*);    /* extern */
s32 func_8003E174(void*);     /* extern */
extern void (*D_80073C10[])(void*);

void func_80037130(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        ((void (*)())func_8003B054)();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (func_80039984(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (func_8003E174(arg0) != 0) {
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0) {
            func_8003B360(arg0);
            return;
        }
    }
    func_80017A04(arg0);
    (*(void (**)(void*))((M2C_FIELD(arg0, s8*, 6) << 2) + (s32)D_80073C10))(
        arg0);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_8003D26C(void*);               /* extern */
s32 func_801EC028();                        /* extern */

void func_80037220(void* arg0) {
    u8 temp_v1;

    if ((M2C_FIELD(arg0, s8*, 2) != 0) && (func_801EC028() != 0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = -1;
        M2C_FIELD(arg0, s8*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = (s32)M2C_FIELD(arg0, s32*, 0x100);
        return;
    }
    temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
    if (temp_v1 & 0x40) {
        M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0x3F);
        func_8003D26C(arg0);
    }
    if ((s8)M2C_FIELD(arg0, u8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, u8*, 0x45) = (u8)(M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
        play_sound(1, 5, arg0);
        M2C_FIELD(arg0, s8*, 0x8C) = 1;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039FFC(void*);     /* extern */
M2C_UNK func_8003B30C(void*); /* extern */
M2C_UNK func_8003D26C(void*); /* extern */
s32 func_801EC028();          /* extern */

void func_800372DC(void* arg0) {
    u8 temp_v1;

    if ((M2C_FIELD(arg0, s8*, 2) != 0) && (func_801EC028() != 0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = -1;
        M2C_FIELD(arg0, s8*, 0x84) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = (s32)M2C_FIELD(arg0, s32*, 0x100);
        return;
    }
    if (func_80039FFC(arg0) != 0) {
        func_8003B30C(arg0);
        return;
    }
    temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
    if (temp_v1 & 0x40) {
        M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0x3F);
        func_8003D26C(arg0);
    }
}
