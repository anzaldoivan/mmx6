#include "common.h"
#include "mmx6/x4.h"

void start_saber(void* arg0, s32 arg1);
void func_8003FAFC(void* arg0);
void func_8003FB48(void* arg0);
void func_8003FBBC(void* arg0);
void func_8003FBF8(void* arg0);
void func_8003FC88(void* arg0);
void func_8003FCD4(void* arg0);
void func_8003FD18(void* arg0);
void func_8003FE74(void* arg0, s32 arg1);
void func_8003FF1C(void* arg0, s32 arg1);

void start_player_attack(void* arg0, s32 arg1) {
    switch (((struct PlayerObj*)arg0)->shot_type) {
    case 3:
    case 0x32:
        start_saber(arg0, arg1);
        break;
    case 0x2E:
        func_8003FF1C(arg0, arg1);
        break;
    case 0xD:
        func_8003FAFC(arg0);
        break;
    case 0xB:
        func_8003FB48(arg0);
        break;
    case 0xC:
        func_8003FBBC(arg0);
        break;
    case 5:
        func_8003FBF8(arg0);
        break;
    case 0xE:
        func_8003FC88(arg0);
        break;
    case 0x10:
        func_8003FCD4(arg0);
        break;
    case 0x11:
        func_8003FD18(arg0);
        break;
    case 0x38:
        func_8003FE74(arg0, arg1);
        break;
    }
}
