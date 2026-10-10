/* func_80042F20: table lookup by stage/substage. TU 32208. Our own C. */
#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80075FE8[];
extern struct X4_EngineObj D_800CCED0;

u8 func_80042F20(void) {
    return D_80075FE8[D_800CCED0.substage + D_800CCED0.stage * 2];
}
