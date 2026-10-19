#include "common.h"

extern u8 D_80075FE8[];

u8 func_80042F50(s8 stage, s8 substage) {
    return D_80075FE8[substage + stage * 2];
}
