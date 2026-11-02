#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80039F78(void* arg0) {
    s8 temp_v0;
    u16 temp_v0_2;

    M2C_FIELD(arg0, s8*, 0x87) = 0;
    if ((M2C_FIELD(arg0, s8*, 0xD3) == 0) &&
        (temp_v0 = M2C_FIELD(arg0, s8*, 5), (temp_v0 != 0)) && (temp_v0 != 1)) {
        if (M2C_FIELD(arg0, s8*, 0x88) == 0) {
            temp_v0_2 = M2C_FIELD(arg0, u16*, 0x80) & 3;
            M2C_FIELD(arg0, u16*, 0x82) = temp_v0_2;
            if (temp_v0_2 != 0) {
                M2C_FIELD(arg0, s8*, 0x88) = 0xC;
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x88) =
                (s8)((u8)M2C_FIELD(arg0, s8*, 0x88) - 1);
            if (M2C_FIELD(arg0, u16*, 0x80) & M2C_FIELD(arg0, u16*, 0x82)) {
                M2C_FIELD(arg0, s8*, 0x87) = 1;
                M2C_FIELD(arg0, s8*, 0x88) = 0;
            }
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CFB0(void* arg);

s32 func_80039FFC(void* arg0) {
    s32 mask;
    // !FAKE: the limit stays in the second return register across both arms
    register s32 lim asm("$3");
    s32 cond;
    s32 bits;
    s32 ret;

    mask = 2;
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        mask = 1;
    }
    if (M2C_FIELD(arg0, u8*, 0x89) & mask) {
        return 1;
    }
    func_8002CFB0(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        cond = M2C_FIELD(arg0, s32*, 0x20);
        lim = M2C_FIELD(arg0, s32*, 0x108);
        cond = cond < lim;
    } else {
        lim = -M2C_FIELD(arg0, s32*, 0x108);
        cond = lim < M2C_FIELD(arg0, s32*, 0x20);
    }
    if (cond) {
        M2C_FIELD(arg0, s32*, 0x20) = lim;
    }
    if (--M2C_FIELD(arg0, s8*, 0x85) == 0) {
        return 1;
    }
    bits = M2C_FIELD(arg0, u16*, 0x7C) & 0x103;
    if (bits == 0) {
        return 1;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if ((bits & 2) == 0) {
            // !FAKE: the flag-2 zero test branches to the shared return-0 tail
            goto zero;
        }
    one:
        return 1;
    }
    bits &= 1;
    if (bits != 0) {
        // !FAKE: the flag-1 test branches to the shared return-1 block
        goto one;
    }
zero:
    return 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CFB0(void* arg); /* extern */

s32 func_8003A0E8(void* arg0) {
    s32 mask;
    s32 lim;
    s32 flags;

    mask = 2;
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        mask = 1;
    }
    if (M2C_FIELD(arg0, u8*, 0x89) & mask) {
        return 1;
    }
    func_8002CFB0(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (M2C_FIELD(arg0, s32*, 0x20) < M2C_FIELD(arg0, s32*, 0x108)) {
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x108);
        }
    } else {
        lim = -M2C_FIELD(arg0, s32*, 0x108);
        if (lim < M2C_FIELD(arg0, s32*, 0x20)) {
            M2C_FIELD(arg0, s32*, 0x20) = lim;
        }
    }
    if (--M2C_FIELD(arg0, s8*, 0x85) == 0) {
        return 1;
    }
    flags = M2C_FIELD(arg0, u16*, 0x7C) & 0x103;
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (flags & 2) {
            return 1;
        }
    } else if (flags & 1) {
        return 1;
    }
    return 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_8003CDBC();               /* extern */

void func_8003A1C8(void* arg0) {
    s32 var_a0;
    u8 temp_a1;

    if ((M2C_FIELD(arg0, s8*, 0xD4) > 0) && (M2C_FIELD(arg0, s8*, 0xA4) <= 0)) {
        func_8003CDBC();
        temp_a1 = M2C_FIELD(arg0, u8*, 0x17);
        var_a0 = temp_a1 == 5;
        if (temp_a1 == 6) {
            var_a0 = 1;
        }
        if (temp_a1 == 0xC) {
            var_a0 = 1;
        }
        if (var_a0 != 0) {
            func_8003BA04(arg0, 0x26);
        }
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s8*, 0xD4) = -1;
        M2C_FIELD(arg0, s8*, 0x8C) = 0;
        M2C_FIELD(arg0, s8*, 5) = 0x13;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CDF0();      /* extern */
M2C_UNK func_8003F3DC(void*); /* extern */

void func_8003A268(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD5) > 0) {
        func_8003CDF0();
        func_8003F3DC(arg0);
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = 1;
        M2C_FIELD(arg0, s8*, 5) = 0x12;
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s8*, 0xD5) = (s8) - (s8)(u8)M2C_FIELD(arg0, s8*, 0xD5);
    }
}
