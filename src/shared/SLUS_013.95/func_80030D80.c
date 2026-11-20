#include "common.h"

s32 func_80030D80(u8 arg0) {
    switch (arg0) {
    case 3:
    case 4:
    case 5:
    case 6:
    case 10:
    case 11:
    case 16:
    case 56:
    case 57:
    case 58:
    case 60:
    case 62:
    case 63:
        return 1;
    }
    return 0;
}
