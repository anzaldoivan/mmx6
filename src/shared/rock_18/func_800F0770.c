#include "common.h"

extern u8 g_temp_options;
extern u8 option_values[];

void func_800F0770(u8* arg0) {
    arg0[3] = 1;
    if (g_temp_options & option_values[arg0[2] & 0xF]) {
        arg0[0x47] = 0x21;
        return;
    }
    arg0[0x47] = 0x22;
}
