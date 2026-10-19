#include "common.h"
#include "mmx6/x4.h"

extern u8* D_800733C4[][2];
extern struct X4_EngineObj D_800CCED0;

s32 func_8002A47C(s32 arg0) {
    u8 id;
    s32 i;
    u8 c;

    id = arg0;
    i = 0;
    while (1) {
        c = D_800733C4[D_800CCED0.stage][D_800CCED0.substage][i];
        if (c == 0xFF || c == id) {
            return i;
        }
        i = (i + 1) & 0xFF;
    }
}
