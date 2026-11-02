#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_8003AF1C(void*);               /* extern */
void player_spawn_dash_spark(void* arg0);   /* extern */
s32 func_8003F13C();                        /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK);      /* extern */
s32 func_801EA560(void*);                   /* extern */
s32 func_801EBE04(void*);                   /* extern */
s32 func_801EBE54(void*);                   /* extern */
s32 func_801EBEDC(void*);                   /* extern */
s32 func_801EC86C(void*);                   /* extern */

void func_800357A8(void* arg0) {
    u8 temp_v1;

    if ((((s32(*)())func_8003F13C)() == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0) && (func_801EBEDC(arg0) == 0)))) {
        if (M2C_FIELD(arg0, u16*, 0x80) & 0x80) {
            func_8003AF1C(arg0);
            return;
        }
        if ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE54(arg0) == 0)) {
            temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
            if (temp_v1 & 0x20) {
                M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0xF);
                player_spawn_dash_spark(arg0);
            }
            if ((s8)M2C_FIELD(arg0, u8*, 0x45) & 0x80) {
                M2C_FIELD(arg0, u8*, 0x45) =
                    (u8)(M2C_FIELD(arg0, u8*, 0x45) & 0xF);
                play_sound(1, 5, arg0);
                M2C_FIELD(arg0, s8*, 0x8C) = 1;
                M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
                return;
            }
            func_8003F508(arg0, 0x10);
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039FFC(void*);              /* extern */
s32 check_ceiling_jump(void*);         /* extern */
M2C_UNK func_8003AF1C(void*);          /* extern */
M2C_UNK func_8003B218(void*);          /* extern */
void func_8003C7D8(void* arg0);        /* extern */
M2C_UNK func_8003CCBC();               /* extern */
void func_8003CD00(void* arg0);        /* extern */
M2C_UNK func_8003D26C(void*);          /* extern */
s32 func_8003F13C(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EA254(void*);              /* extern */
s32 func_801EA560(void*);              /* extern */
s32 func_801EBE04(void*);              /* extern */
s32 func_801EBE54(void*);              /* extern */
s32 func_801EBEDC(void*);              /* extern */
s32 func_801EC86C(void*);              /* extern */

void func_800358D4(void* arg0) {
    u8 temp_v1;

    func_8003CCBC();
    if ((func_8003F13C(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0) &&
          ((func_801EA254(arg0) != 0) || (func_801EBEDC(arg0) == 0)))) &&
        (check_ceiling_jump(arg0) == 0)) {
        if (M2C_FIELD(arg0, u16*, 0x80) & 0x80) {
            func_8003AF1C(arg0);
            return;
        }
        if ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE54(arg0) == 0)) {
            if (func_80039FFC(arg0) != 0) {
                func_8003B218(arg0);
                return;
            }
            temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
            if (temp_v1 & 0x40) {
                M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0xF);
                func_8003D26C(arg0);
            }
            if (!(M2C_FIELD(arg0, u8*, 0x85) & 3)) {
                func_8003C7D8(arg0);
            }
            func_8003F508(arg0, 0x10);
            func_8003CD00(arg0);
        }
    }
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_80035A2C);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80037A60(void* arg0);        /* extern */
void func_8003AD18(void* arg0);        /* extern */
M2C_UNK func_8003AFF4(s32);            /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
void check_low_health(void* arg0);     /* extern */
void func_8003D394(void* arg0);        /* extern */
extern u8 D_800CCF2F;

void func_80035BDC(void* arg0) {

    func_80037A60(arg0);
    func_8003D394(arg0);
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 0x67) != 0) && (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        if (!(M2C_FIELD(arg0, s32*, 0xEC) & 0x200) &&
            ((M2C_FIELD(arg0, s8*, 2) == 0) || !(D_800CCF2F & 0x20))) {
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
            }
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x61) == 0x3C) {
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            M2C_FIELD(arg0, u8*, 0x67) = 0;
            func_8003AD18(arg0);
        } else if (M2C_FIELD(arg0, s32*, 0x2C) != 0) {
            func_8003BA04(arg0, 0xB);
            {
                // !FAKE: depin: dropping it breaks the match (84/87)
                register s32 m1 asm("$2") = -1;
                // !FAKE: depin: dropping it breaks the match (84/87)
                register s32 k7 asm("$3") = 7;
                M2C_FIELD(arg0, s8*, 0x67) = m1;
                M2C_FIELD(arg0, u8*, 5) = k7;
            }
            M2C_FIELD(arg0, u8*, 6) = 0;
        } else {
            func_8003AFF4((s32)arg0);
        }
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

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80017A04();                    /* extern */
s32 func_80039C40(void*);                   /* extern */
s32 func_80039CFC(void*);                   /* extern */
s32 func_8003A628(void*);                   /* extern */
void func_8003AD18(void* arg0);             /* extern */
M2C_UNK func_8003AE8C(void*);               /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);      /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);  /* extern */
void player_spawn_dash_spark(void* arg0);   /* extern */
M2C_UNK func_8003CCBC();                    /* extern */
void func_8003CD00(void* arg0);             /* extern */
s32 func_8003F644(void*);                   /* extern */
s32 func_801EA560(void*);                   /* extern */
s32 func_801EBEDC(void*);                   /* extern */
s32 func_801EC1F8(void*);                   /* extern */
s32 func_801EC86C(void*);                   /* extern */

void func_80035D38(void* arg0) {
    s8 temp_s0;
    s8 temp_v1;

    ((void (*)())func_8003CCBC)();
    if (M2C_FIELD(arg0, u16*, 0x80) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x80) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if ((func_8003A628(arg0) == 0) && (func_8003F644(arg0) == 0)) {
        if (func_80039C40(arg0) != 0) {
            if (M2C_FIELD(arg0, s8*, 5) == 0xC) {
                func_8003CD00(arg0);
                if (M2C_FIELD(arg0, s8*, 0x8E) != 0) {
                    func_8003BB94(arg0, 0x80, 5);
                } else {
                    func_8003BB94(arg0, 0x10, 5);
                }
                player_spawn_dash_spark(arg0);
                play_sound(1, 5, arg0);
                M2C_FIELD(arg0, u8*, 0x8C) = 1;
                M2C_FIELD(arg0, u8*, 6) += 1;
            }
        } else if ((M2C_FIELD(arg0, s8*, 2) == 0) ||
                   ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
                    (func_801EC1F8(arg0) == 0) && (func_801EBEDC(arg0) == 0))) {
            if (!(M2C_FIELD(arg0, u16*, 0x7C) & 8) &&
                (func_80039CFC(arg0) != 0)) {
                func_8003AE8C(arg0);
                return;
            }
            func_80017A04(arg0);
            temp_v1 = M2C_FIELD(arg0, s8*, 6);
            if (temp_v1 == 0) {
                if ((M2C_FIELD(arg0, s8*, 0x8F) != 0) &&
                    (M2C_FIELD(arg0, s8*, 2) == 0)) {
                    temp_s0 = M2C_FIELD(arg0, s8*, 0x44);
                    func_8003BB94(arg0, 0x6D,
                                  M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
                    M2C_FIELD(arg0, s8*, 0x44) = temp_s0;
                }
                if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                    M2C_FIELD(arg0, u8*, 6) += 1;
                }
            } else if (temp_v1 == 1) {
                func_8003CD00(arg0);
                if ((M2C_FIELD(arg0, s8*, 0x8F) != 0) &&
                    (M2C_FIELD(arg0, s8*, 2) == 0)) {
                    temp_v1 = M2C_FIELD(arg0, s8*, 0x96);
                    if ((temp_v1 == 0x12) || (temp_v1 == 0x14) ||
                        (temp_v1 == 0x2E) || (temp_v1 == 0x13) ||
                        (temp_v1 == 0x2B)) {
                        func_8003BA04(arg0, 0x8B);
                    } else {
                        func_8003BA04(arg0, 0x6C);
                    }
                } else if ((M2C_FIELD(arg0, s8*, 0x8E) == 0) &&
                           (M2C_FIELD(arg0, s8*, 2) == 0)) {
                    func_8003BB94(arg0, 0x51, 2);
                }
                if (!(M2C_FIELD(arg0, u16*, 0x7C) & 8)) {
                    if ((M2C_FIELD(arg0, s32*, 0x8C) & 0xFFFF0000) &&
                        (M2C_FIELD(arg0, s8*, 2) == 0)) {
                        func_8003BA04(arg0, 0x6E);
                    } else {
                        func_8003BA04(arg0, 0x52);
                    }
                    M2C_FIELD(arg0, u8*, 6) = 2;
                }
            } else if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                func_8003AD18(arg0);
            }
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80017A04();                    /* extern */
void func_800389B4(void* arg0);             /* extern */
s32 func_80038BA8(void* arg0);              /* extern */
s32 func_8003A764(void*);                   /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);  /* extern */
s32 func_8003E06C(void*);                   /* extern */
s32 func_801EA004(void*);                   /* extern */
s32 func_801EA560(void*);                   /* extern */

void func_8003605C(void* arg0) {
    s8 temp_s0;
    s32 temp_v0;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if ((func_8003E06C(arg0) == 0) && (func_8003A764(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EA560(arg0) == 0) && (func_801EA004(arg0) == 0)))) {
        if (M2C_FIELD(arg0, s8*, 6) == 0) {
            ((void (*)())func_80017A04)(arg0);
            if ((M2C_FIELD(arg0, s8*, 0x8F) != 0) &&
                (M2C_FIELD(arg0, s8*, 2) == 0)) {
                temp_s0 = M2C_FIELD(arg0, s8*, 0x44);
                func_8003BB94(arg0, 0x90, M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
                M2C_FIELD(arg0, s8*, 0x44) = temp_s0;
            }
            if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                M2C_FIELD(arg0, u8*, 6) = 1;
            }
        } else {
            func_80038BA8(arg0);
            func_800389B4(arg0);
            if (M2C_FIELD(arg0, s32*, 0x1C) != M2C_FIELD(arg0, s32*, 0xC)) {
                if (M2C_FIELD(arg0, s8*, 0xDE) == 0) {
                    play_sound(0, 0x27, arg0);
                }
                temp_v0 = M2C_FIELD(arg0, u8*, 0xDE) + 1;
                M2C_FIELD(arg0, u8*, 0xDE) = temp_v0;
                if ((s8)temp_v0 >= 0x15) {
                    goto block_19;
                }
            } else {
            block_19:
                M2C_FIELD(arg0, u8*, 0xDE) = 0;
            }
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80017A04();                    /* extern */
s32 func_8002FE30(void*);                   /* extern */
void func_80038CD0(void* arg0);             /* extern */
s32 func_80038F64(void* arg0);              /* extern */
s32 func_8003A764(void*);                   /* extern */
s32 func_8003A814(void*, s32);              /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8);  /* extern */
s32 func_8003E06C(void*);                   /* extern */
s32 func_801EA124(void*);                   /* extern */
s32 func_801EA560(void*);                   /* extern */

void func_800361D4(void* arg0) {
    s8 temp_s0;
    s32 temp_v0;

    if (M2C_FIELD(arg0, u16*, 0x7C) & 2) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, u16*, 0x7C) & 1) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    if ((func_8003E06C(arg0) == 0) && (func_8003A764(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EA560(arg0) == 0) && (func_801EA124(arg0) == 0)))) {
        if (M2C_FIELD(arg0, s8*, 6) == 0) {
            ((void (*)())func_80017A04)(arg0);
            if ((M2C_FIELD(arg0, s8*, 0x8F) != 0) &&
                (M2C_FIELD(arg0, s8*, 2) == 0)) {
                temp_s0 = M2C_FIELD(arg0, s8*, 0x44);
                func_8003BB94(arg0,
                              func_8003A814(arg0, func_8002FE30(arg0) & 0xFF) +
                                  0x94,
                              M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
                M2C_FIELD(arg0, s8*, 0x44) = temp_s0;
            }
            if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
                M2C_FIELD(arg0, u8*, 6) = 1;
            }
        } else {
            func_80038F64(arg0);
            func_80038CD0(arg0);
            if (M2C_FIELD(arg0, s32*, 0x18) != M2C_FIELD(arg0, s32*, 8)) {
                if (M2C_FIELD(arg0, s8*, 0xDE) == 0) {
                    play_sound(0, 0x27, arg0);
                }
                temp_v0 = M2C_FIELD(arg0, u8*, 0xDE) + 1;
                M2C_FIELD(arg0, u8*, 0xDE) = temp_v0;
                if ((s8)temp_v0 >= 0x15) {
                    goto block_19;
                }
            } else {
            block_19:
                M2C_FIELD(arg0, u8*, 0xDE) = 0;
            }
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80017A04();                    /* extern */
s32 func_8002CFB0(void* arg);               /* extern */
s32 func_8003A628(void*);                   /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);      /* extern */

void func_80036364(void* arg0) {
    s8 temp_v1;

    ((void (*)())func_80017A04)(arg0);
    func_8002CFB0(arg0);
    temp_v1 = M2C_FIELD(arg0, s8*, 6);
    if (temp_v1 == 2) {
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            func_8003A628(arg0);
        }
    } else if (temp_v1 == 1) {
        if (M2C_FIELD(arg0, s32*, 0x20) <= 0) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0x52);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    } else if (temp_v1 == 0) {
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            M2C_FIELD(arg0, u8*, 0x45) = M2C_FIELD(arg0, u8*, 0x45) & 0x3F;
            play_sound(1, 1, arg0);
        }
        if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0xB);
            M2C_FIELD(arg0, s8*, 0x67) = -1;
        }
        if ((M2C_FIELD(arg0, s8*, 0x67) == -1) &&
            (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0x51);
            M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}
