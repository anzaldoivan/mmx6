#include "common.h"

extern u8 D_801F3714[];

#define OBJ_U8(p, off) (*(u8*)((u8*)(p) + (off)))
#define OBJ_U16(p, off) (*(u16*)((u8*)(p) + (off)))
#define OBJ_S32(p, off) (*(s32*)((u8*)(p) + (off)))

s32 func_801EC3AC(void* arg0) {
    s32 var_v0;
    u16 input;
    u8 bob;

    bob = D_801F3714[*(volatile u8*)((u8*)arg0 + 0xDA)];
    OBJ_U8(arg0, 0xDA) = (OBJ_U8(arg0, 0xDA) + 1) & 0xF;
    OBJ_S32(arg0, 0x20) = 0;
    OBJ_U16(arg0, 0xE) += (s8)bob;
    input = OBJ_U16(arg0, 0x7C);
    if (!(input & 3)) {
        return 0;
    }
    if (input & 1) {
        var_v0 = 1;
        if (!(OBJ_U8(arg0, 0x89) & 1)) {
            OBJ_S32(arg0, 0x20) = OBJ_S32(arg0, 0xF4);
            if (OBJ_U8(arg0, 0x15) != 0) {
                return var_v0;
            }
            return -1;
        }
        return 0;
    }
    var_v0 = 0;
    if (OBJ_U8(arg0, 0x89) & 2) {
        return var_v0;
    }
    var_v0 = -1;
    OBJ_S32(arg0, 0x20) = -OBJ_S32(arg0, 0xF4);
    if (OBJ_U8(arg0, 0x15) != 0) {
        return var_v0;
    }
    return 1;
}
