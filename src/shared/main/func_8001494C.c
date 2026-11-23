#include "common.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void task_yield(s32);
void func_80014E60(s32, s32);
u8 func_80016570(void);
s32 func_80064894(s32, s32);
X4_CdlCB func_800648B4(X4_CdlCB func);
extern M2C_UNK* D_800B91B8;

// Inlined twin of the PC port's rock_bin lookup: stores the member lba, returns its size.
static inline s32 func_8001494C_lookup(u8 idx, s32* out) {
    *out = ((s32(*)[2])rock_bin_file_table)[idx][0];
    return ((s32(*)[2])rock_bin_file_table)[idx][1];
}

void func_8001494C(void) {
    u8 sp10;
    u8 idx;
    s32 p;

    sp10 = 0xA0;
    D_8008EC0C = 0;
    while (D_8009509C != 2 || D_8008EC08 != 0) {
        if (D_8009509C & 0xC0) {
            idx = D_800E0379;
            p = D_800E037C;
            D_800E0D30 = D_800B91B8;
            D_800E0D34 = D_800E0374;
            if (func_80064894(1, 0) != 0) {
                CdControlB(9, 0, 0);
            }
            if (D_8009509C != 0x80) {
                D_800E0380 = 0;
            }
            D_8009509C = 0;
            D_800E0379 = idx;
            D_800E037C = p;
            do {
            } while (func_80016570() & 0x40);
            D_800E01C0 = 0;
            D_800E01B0 = func_8001494C_lookup(idx, &D_800E01B4);
            D_800E01AC = (u8*)p;
            D_800E01A8 = D_800E01B0;
            ((void (*)(void))func_80014E60)();
        } else if (++D_800E0380 >= 0x259U) {
            func_800648B4(0);
            while (CdReset(0) == 0) {
            }
            while (CdControlB(0xE, (u8*)&sp10, 0) == 0) {
            }
            VSync(3);
            D_8009509C = 0xC0;
        }
        task_yield(1);
    }
    D_800B91B8 = D_800E0D30;
    D_800E0374 = D_800E0D34;
}
