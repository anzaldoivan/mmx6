#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void* alloc_class4_slot();
M2C_UNK func_8002F288(M2C_UNK*);
extern s16 D_800F6C10[];

void func_800ECC10(void* arg0) {
    void* p;
    void* e;

    p = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(arg0, s8*, 7) == 4) {
        M2C_FIELD(p, u8*, 5)--;
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) > 0x170) {
        ((void (*)(void*))func_8002F288)(arg0);
        if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
            if (M2C_FIELD(arg0, s8*, 3) != 0) {
                play_sound(2, 0x11, arg0);
            }
            M2C_FIELD(arg0, s8*, 7) = 1;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
            e = alloc_class4_slot();
            if (e != 0) {
                M2C_FIELD(e, u8*, 0) = 0x41;
                M2C_FIELD(e, u8*, 1) = 7;
                M2C_FIELD(e, u8*, 2) = 0xB;
                M2C_FIELD(e, s16*, 0xA) =
                    M2C_FIELD(arg0, s16*, 0xA) +
                    D_800F6C10[M2C_FIELD(arg0, s8*, 2) - 1];
                M2C_FIELD(e, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
            }
            if ((u16)(M2C_FIELD(arg0, u16*, 0xE) - 0x3D1) < 0x2E ||
                (u16)(M2C_FIELD(arg0, u16*, 0xE) - 0x2E1) < 0x2E) {
                e = alloc_class4_slot();
                if (e != 0) {
                    M2C_FIELD(e, u8*, 0) = 0x41;
                    M2C_FIELD(e, u8*, 1) = 7;
                    M2C_FIELD(e, u8*, 2) = 0xB;
                    M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) - 0x90;
                    M2C_FIELD(e, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
                }
            }
            if ((u16)(M2C_FIELD(arg0, u16*, 0xE) - 0x341) < 0x2E ||
                (u16)(M2C_FIELD(arg0, u16*, 0xE) - 0x2B1) < 0x2E) {
                e = alloc_class4_slot();
                if (e != 0) {
                    M2C_FIELD(e, u8*, 0) = 0x41;
                    M2C_FIELD(e, u8*, 1) = 7;
                    M2C_FIELD(e, u8*, 2) = 0xB;
                    M2C_FIELD(e, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA) + 0x90;
                    M2C_FIELD(e, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
                }
            }
            M2C_FIELD(arg0, s8*, 4) = 2;
        }
    }
}
