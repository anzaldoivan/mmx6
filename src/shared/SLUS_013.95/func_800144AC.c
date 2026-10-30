#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void pump_file_loads(void);                         /* extern */

void func_800144AC(void) {
    func_80014F70(0, 0, 0);
    pump_file_loads();
}
