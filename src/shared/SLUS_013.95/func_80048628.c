#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_AbcObj D_8008EAF0;
extern u16 D_800C4570;
#define D_800C4570 (*(u8*)&D_800C4570)
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
s32 func_8002CB50();

#define ABC_UNK12 M2C_FIELD(&D_8008EAF0, s16*, 0x12)

void func_80048628(void* arg0) {
    s32 v;
    s32 c;

    switch (M2C_FIELD(arg0, s8*, 2)) {
    case 0:
        break;
    case 1:
        if (D_800C4570 != 0) {
            // !FAKE: shared clear_object_slot tail; retail emits one call
            goto call_c9b0;
        }
        if (--M2C_FIELD(arg0, u16*, 0x56) == 0) {
            M2C_FIELD(arg0, u16*, 0x56) = 0x20;
            M2C_FIELD(arg0, u8*, 0x54) ^= 1;
        }
        if (M2C_FIELD(arg0, s8*, 0x54) == 0) {
            break;
        }
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    case 2:
        if (D_8008EAF0.unkC == 0) {
        call_c9b0:
            clear_object_slot(arg0);
            return;
        }
        v = D_8008EAF0.unkD;
        if (v == 0 || v == 4) {
            animate_object(arg0);
        }
        break;
    case 3:
        if (M2C_FIELD(arg0, u8**, 0x50)[D_8008EAF0.unkE] != 0 &&
            (c = D_8008EAF0.unkC) == 1) {
            if (M2C_FIELD(arg0, s8*, 0x55) == 0) {
                set_animation(arg0, 1);
                M2C_FIELD(arg0, s8*, 0x55) = 1;
            } else {
                animate_object(arg0);
                if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
                    M2C_FIELD(arg0, s8*, 0x55) = 0;
                }
            }
        } else if (M2C_FIELD(arg0, s8*, 0x55) != 0) {
            animate_object(arg0);
            if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
                M2C_FIELD(arg0, s8*, 0x55) = 0;
                set_animation(arg0, 0);
            }
        } else {
            ((void (*)(void*, s32))set_animation)(arg0, 0);
        }
        break;
    case 4:
        ((void (*)())animate_object)(arg0);
        break;
    case 5:
        if (D_8008EAF0.unkC == 1) {
            if (M2C_FIELD(arg0, s8*, 0x45) != 0 ||
                (M2C_FIELD(arg0, s8*, 0x55) == 1 &&
                 ABC_UNK12 == M2C_FIELD(arg0, s8*, 0x54)) ||
                (M2C_FIELD(arg0, s8*, 0x55) == 0 &&
                 ABC_UNK12 != M2C_FIELD(arg0, s8*, 0x54))) {
                struct X4_AbcObj* q = &D_8008EAF0;
                if (M2C_FIELD(q, s16*, 0x12) != M2C_FIELD(arg0, s8*, 0x54)) {
                    // !FAKE: joins the set-one block shared with the outer test
                    goto set_one;
                }
                set_animation(arg0, 0);
                M2C_FIELD(arg0, s8*, 0x55) = 0;
            }
        } else if (D_8008EAF0.unkC == 0xFF && M2C_FIELD(arg0, s8*, 0x55) == 0) {
            set_animation(arg0, 1);
            M2C_FIELD(arg0, s8*, 0x55) = 1;
        } else if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        set_one:
            set_animation(arg0, 1);
            M2C_FIELD(arg0, s8*, 0x55) = 1;
        }
        animate_object(arg0);
        func_8002CB50(arg0);
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            M2C_FIELD(arg0, s8*, 3) = 2;
        }
        return;
    case 8:
        if (M2C_FIELD(arg0, s8*, 5) != 0) {
            // !FAKE: shared done tail after the switch
            goto done;
        }
        animate_object(arg0);
        if (--M2C_FIELD(arg0, s8*, 0x56) == 0) {
            M2C_FIELD(arg0, s8*, 5) = 1;
        }
        if (M2C_FIELD(arg0, s8*, 6) != 0) {
            M2C_FIELD(arg0, s32*, 8) =
                M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s32*, 8);
            M2C_FIELD(arg0, s32*, 0xC) =
                M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s32*, 0xC);
        }
        break;
    default:
        return;
    }
    func_8002CB50(arg0);
    return;
done:
    M2C_FIELD(arg0, s8*, 3) = 0;
    clear_object_slot(arg0);
}
#undef D_800C4570
