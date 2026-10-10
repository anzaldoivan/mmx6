/* Probe (phase 1.4 T6): sltiu range check, frame + jal. Game TU 120A0. */
#include "common.h"

extern u8 D_800CCEDC;
void func_8001854C(void);

void func_8001E78C(void) {
    if ((u32)(D_800CCEDC - 9) >= 2) {
        func_8001854C();
    }
}
