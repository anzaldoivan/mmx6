#include "common.h"

void func_800F6B94(u8*, s32, s16, s16);

void func_800F3C80(u8* self) {
    u8* parent = *(u8**)(self + 0x8C);

    if (*(s8*)(parent + 4) != 3) {
        self[4] = 2;
        self[3] = 0;
        return;
    }
    self[3] = parent[3];
    if (*(u16*)(parent + 0x42) & 0x8000) {
        *(u16*)(self + 0x42) |= 0x8000;
    } else {
        *(u16*)(self + 0x42) &= 0x7FFF;
    }
    if (self[0x15] == 0) {
        switch (*(s8*)(self + 0x45)) {
        case 1:
            func_800F6B94(self, 0x31, *(s16*)(self + 0xA) + 0x70,
                          *(s16*)(self + 0xE) - 0x38);
            break;
        case 2:
            func_800F6B94(self, 0x32, *(s16*)(self + 0xA) + 0x50,
                          *(s16*)(self + 0xE) - 0x28);
            break;
        case 3:
            func_800F6B94(self, 0x33, *(s16*)(self + 0xA) + 0x30,
                          *(s16*)(self + 0xE) - 0x18);
            break;
        case 4:
            func_800F6B94(self, 0x34, *(s16*)(self + 0xA) + 0x10,
                          *(s16*)(self + 0xE) - 0x8);
            break;
        case 5:
            func_800F6B94(self, 0x35, *(s16*)(self + 0xA) - 0x10,
                          *(s16*)(self + 0xE) + 0x8);
            break;
        case 6:
            func_800F6B94(self, 0x36, *(s16*)(self + 0xA) - 0x30,
                          *(s16*)(self + 0xE) + 0x18);
            break;
        case 7:
            func_800F6B94(self, 0x37, *(s16*)(self + 0xA) - 0x50,
                          *(s16*)(self + 0xE) + 0x28);
            break;
        case 16:
            *(s16*)(self + 0x88) = 0x3C;
            self[6]++;
            break;
        }
    } else {
        switch (*(s8*)(self + 0x45)) {
        case 1:
            func_800F6B94(self, 0x31, *(s16*)(self + 0xA) - 0x70,
                          *(s16*)(self + 0xE) - 0x38);
            break;
        case 2:
            func_800F6B94(self, 0x32, *(s16*)(self + 0xA) - 0x50,
                          *(s16*)(self + 0xE) - 0x28);
            break;
        case 3:
            func_800F6B94(self, 0x33, *(s16*)(self + 0xA) - 0x30,
                          *(s16*)(self + 0xE) - 0x18);
            break;
        case 4:
            func_800F6B94(self, 0x34, *(s16*)(self + 0xA) - 0x10,
                          *(s16*)(self + 0xE) - 0x8);
            break;
        case 5:
            func_800F6B94(self, 0x35, *(s16*)(self + 0xA) + 0x10,
                          *(s16*)(self + 0xE) + 0x8);
            break;
        case 6:
            func_800F6B94(self, 0x36, *(s16*)(self + 0xA) + 0x30,
                          *(s16*)(self + 0xE) + 0x18);
            break;
        case 7:
            func_800F6B94(self, 0x37, *(s16*)(self + 0xA) + 0x50,
                          *(s16*)(self + 0xE) + 0x28);
            break;
        case 16:
            *(s16*)(self + 0x88) = 0x3C;
            self[6]++;
            break;
        }
    }
}
