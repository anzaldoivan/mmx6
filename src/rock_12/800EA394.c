#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u8 D_800CD40C;

void func_800EA394(void* arg0) {
    if (!(D_800CCF99 & 0x10) || (D_800CD40C == 2)) {
        ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))open_text_box)(
            M2C_FIELD(arg0, u16*, 8), 0xFF, 0);
        M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) + 1);
    }
}

#include "common.h"
#include "mmx6/globals.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK stop_cd_audio(); /* extern */
extern u16 D_800C4570;
#define D_800C4570                                                             \
    (*(u8*)&D_800C4570) /* C0270: retail reads the low byte (lbu) */
extern u8 D_800CD40C;

void func_800EA3F8(void* arg0) {
    if (D_800C4570 != 0) {
        stop_cd_audio();
    }
    if (D_8008EAFC == 0) {
        stop_cd_audio();
        if ((D_800CD40C == 0) && (M2C_FIELD(arg0, s16*, 0xA) != 0)) {
            M2C_FIELD(arg0, s16*, 0xA) =
                (s16)((u16)M2C_FIELD(arg0, s16*, 0xA) - 1);
            M2C_FIELD(arg0, s8*, 3) = 0;
            M2C_FIELD(arg0, u16*, 8) = (u16)(M2C_FIELD(arg0, u16*, 8) + 1);
        }
    }
}
#undef D_800C4570

#include "common.h"

extern void* D_800EA9C4[];

s32 func_800EA480(s8* arg0) {
    // !FAKE: retail holds the handler in the second argument register
    register void* f asm("$5") = *(void**)((arg0[3] << 2) + (s32)D_800EA9C4);

    ((void (*)())f)();
    if (*(s16*)(arg0 + 0xA) == 0) {
        arg0[3] = 0;
        return 1;
    }
    return 0;
}

// clang-format off
INCLUDE_ASM("asm/rock_12/nonmatchings/E9860", func_800EA4DC);

INCLUDE_ASM("asm/rock_12/nonmatchings/E9860", func_800EA904);
// clang-format on
