#include "common.h"
#include "mmx6/x4.h"

/* stack-sized visual object (X4_VisualObj prefix, 0x50 bytes) */

void func_800232D4(void*);

void func_8001A330(u8 arg0, s32 x, s32 y, s32 arg3, s32 arg4, s32 arg5) {
    VisObj50 obj;
    s32* table;
    s32 off;

    obj.bg_offset = -1;
    obj.x = x;
    obj.y = y;
    table = *(s32**)SP(0x3C);
    off = table[arg5];
    obj.unk47 = arg0;
    obj.unk15 = 0;
    obj.unk40 = (arg4 << 8) + 0x1D00;
    obj.unk3C = (u8*)table + off;
    obj.unk42 = (arg3 % 4 + 0x10) | ((arg3 / 4 + 0x1F0) << 6);
    obj.active = 1;
    obj.unk16 = 5;
    func_800232D4(&obj);
}
