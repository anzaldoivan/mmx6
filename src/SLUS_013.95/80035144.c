#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D5D0(void*);          /* extern */
void func_8003AD18(void* arg0);        /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_8003CCBC();               /* extern */
void func_8003D394(void* arg0);        /* extern */
M2C_UNK func_8003D630(void*);          /* extern */
M2C_UNK func_8003D718(void*);          /* extern */
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEEC;

void func_80035144(void* arg0) {
    s8 temp_v0;

    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xCE) != 0) {
            if (--M2C_FIELD(arg0, s8*, 0xCE) == 0) {
                func_8003CCBC(arg0);
            }
            func_8002D5D0(arg0);
            return;
        }
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            func_8003BA04(arg0, 2);
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            background_objects[0].unk44 = 1;
            background_objects[1].unk44 = 1;
            background_objects[2].unk44 = 1;
            M2C_FIELD(arg0, s8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            return;
        }
        func_8002D5D0(arg0);
        func_8003D394(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        func_8003D718(arg0);
        func_8003D630(arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        D_800CCEEC = 0;
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            func_8003D718(arg0);
            func_8003D630(arg0);
        }
        func_8003AD18(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039C40(void*);      /* extern */
s32 func_80039C9C(void*);      /* extern */
s32 func_80039CFC(void*);      /* extern */
s32 try_enter_ladder(void*);      /* extern */
s32 func_8003A628(void*);      /* extern */
s32 check_ceiling_jump(void*); /* extern */
M2C_UNK func_8003AE8C(void*);  /* extern */
M2C_UNK func_8003CCBC();       /* extern */
s32 func_8003F13C(void*);      /* extern */
s32 func_801EA254(void*);      /* extern */
s32 func_801EA560(void*);      /* extern */
M2C_UNK func_801EB61C(void*);  /* extern */
s32 func_801EBE04(void*);      /* extern */
s32 func_801EBE54(void*);      /* extern */
s32 func_801EBEDC(void*);      /* extern */
s32 func_801EC86C(void*);      /* extern */
M2C_UNK func_801EC9C4(void*);  /* extern */

void func_80035274(void* arg0) {
    func_8003CCBC();
    if ((func_8003A628(arg0) == 0) && (try_enter_ladder(arg0) == 0) &&
        (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (check_ceiling_jump(arg0) == 0) && (func_80039C40(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) &&
          ((func_801EA254(arg0) != 0) || (func_801EBEDC(arg0) == 0)))) &&
        (func_80039C9C(arg0) == 0)) {
        if (func_80039CFC(arg0) != 0) {
            func_8003AE8C(arg0);
            return;
        }
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_801EB61C(arg0);
            return;
        }
        func_801EC9C4(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D5D0(void*);          /* extern */
s32 func_80039C40(void*);              /* extern */
s32 func_80039CFC(void*);              /* extern */
s32 try_enter_ladder(void*);              /* extern */
s32 func_8003A628();                   /* extern */
void func_8003ADB4(void* arg0);        /* extern */
M2C_UNK func_8003AED4(void*);          /* extern */
s32 func_8003F13C(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EBE04(void*);              /* extern */
s32 func_801EBE54(void*);              /* extern */
s32 func_801EBEDC(void*);              /* extern */
s32 func_801EC86C(void*);              /* extern */

void func_800353C0(void* arg0) {
    if ((((s32(*)())func_8003A628)() == 0) && (try_enter_ladder(arg0) == 0) &&
        (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (func_80039C40(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0)))) {
        if (func_80039CFC(arg0) != 0) {
            ((void (*)())func_80017A04)(arg0);
            if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
                func_8003AED4(arg0);
                return;
            }
            func_8002D5D0(arg0);
            func_8003F508(arg0, 7);
            return;
        }
        func_8003ADB4(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D5D0(void*);          /* extern */
s32 func_80039C40(void*);              /* extern */
s32 func_80039C9C(void*);              /* extern */
s32 func_80039D7C(void*);              /* extern */
s32 try_enter_ladder(void*);              /* extern */
s32 func_8003A628();                   /* extern */
s32 check_ceiling_jump(void*);         /* extern */
void func_8003ADB4(void* arg0);        /* extern */
s32 func_8003F13C(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA254(void*);              /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EBE04(void*);              /* extern */
s32 func_801EBE54(void*);              /* extern */
s32 func_801EBEDC(void*);              /* extern */
s32 func_801EC86C(void*);              /* extern */

void func_800354E8(void* arg0) {
    if ((((s32(*)())func_8003A628)() == 0) && (try_enter_ladder(arg0) == 0) &&
        (func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (check_ceiling_jump(arg0) == 0) && (func_80039C40(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) &&
          ((func_801EA254(arg0) != 0) || (func_801EBEDC(arg0) == 0)))) &&
        (func_80039C9C(arg0) == 0)) {
        if (func_80039D7C(arg0) != 0) {
            func_80017A04(arg0);
            func_8002D5D0(arg0);
            func_8003F508(arg0, 8);
            return;
        }
        func_8003ADB4(arg0);
    }
}
