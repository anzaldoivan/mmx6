#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void task_yield(s32);
M2C_UNK func_800139A0(s8);
void func_800146F4(void);
void func_80014E60(s32, s32);
void init_loading_screen(void);
M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern s8 D_80097424;
extern u8 D_800E0378;
extern u8 D_800E037A;

// Inlined twin of the PC port's file-table lookup: stores the member size, returns its lba.
static inline s32 wait_for_file_load_lookup(u8 idx, s32* out) {
    s32* e = rock_dat_file_table[idx];
    *out = e[1];
    return e[0];
}

void wait_for_file_load(s32 a0, s32 a1) {
    u8 arg0 = a0;
    u8 arg1 = a1;
    u8 sp10[8];
    u8 sp18;

    sp18 = 0xA0;
    D_800E0378 = 0;
    D_8008EC0C = 0;
    while (D_8009509C != 2 || D_8008EC08 != 0) {
        if (D_800E0378 == 0 && arg1 == 0 && D_80097424 == 0) {
            ((void (*)(s32))func_800139A0)(8);
            D_800E0378++;
        }
        ((void (*)())init_loading_screen)(arg0);
        if (D_8009509C & 0xC0) {
            if (D_800E01C0 == 0) {
                u8 idx = D_800E0379;
                s32 v = D_800E037C;

                if (func_80064894(1, 0) != 0) {
                    CdControlB(9, 0, 0);
                }
                if (D_8009509C != 0x80) {
                    D_800E0380 = 0;
                }
                D_8009509C = 0;
                D_800E0379 = idx;
                D_800E037C = v;
                do {
                    while (CdControlB(1, 0, sp10) == 0) {
                    }
                } while (sp10[0] & 0x40);
                D_800E01C0 = 0;
                D_800E01B4 = wait_for_file_load_lookup(idx, &D_800E01B0);
                D_800E01AC = (u8*)v;
                D_800E01A8 = D_800E01B0;
                ((void (*)(void))func_80014E60)();
            } else {
                func_80014F70(D_800E0379, D_800E037A, D_800E037C);
            }
        } else if (++D_800E0380 >= 0x259) {
            func_800648B4(0);
            while (CdReset(0) == 0) {
            }
            while (CdControlB(0xE, (u8*)&sp18, 0) == 0) {
            }
            VSync(3);
            D_8009509C = 0xC0;
        }
        task_yield(1);
    }
    if (arg1 != 0) {
        func_800146F4();
    }
}
