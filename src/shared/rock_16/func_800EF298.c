#include "common.h"

extern void (*D_800F1588[])(void*);

void func_800EF298(void* arg0) {
    s8 c;

    D_800F1588[*(s8*)((u8*)arg0 + 4)](arg0);
    c = *(s8*)((u8*)arg0 + 0x45);
    if (c == 0x13) {
        *(s16*)((u8*)arg0 + 0x42) = 0x7849;
    } else {
        *(s16*)((u8*)arg0 + 0x42) =
            ((c + 0x30) % 16) | ((((c + 0x30) / 16) + 0x1E0) << 6);
    }
}
