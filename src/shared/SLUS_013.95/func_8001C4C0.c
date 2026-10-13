#include "common.h"
#include "mmx6/x4.h"

extern const struct X4_MemcardPath D_800100AC;
extern u8 D_800E2F96;
s32 func_8001C5EC(s32);
void func_80069D94(void* dst, s32 c, s32 n);
char* func_80069D74(char* dst, char* src);
void* func_80069F44(void* dir);
void* func_8006A0E4(char* name, void* dir);

static inline void func_8001C4C0_name(char* path, char* name) {
    *(struct X4_MemcardPath*)path = D_800100AC;
    func_80069D94(path + 6, 0, 0x1A);
    func_80069D74(path + 5, name);
}

s32 func_8001C4C0(s32 arg0, u8* arg1, char* arg2) {
    s32 dir[10];
    char path[32];
    s32 ret;
    s32 size;
    s32* sizes;

    func_8001C4C0_name(path, arg2);
    arg1[0x14A] = 0;
    *(s32*)(arg1 + 0x14C) = 0;
    path[2] += arg0;
    if (func_8006A0E4(path, dir) == dir) {
        sizes = (s32*)(arg1 + 0x150);
        do {
            func_80069D74((char*)(arg1 + arg1[0x14A] * 0x16), (char*)dir);
            size = dir[6];
            *(s32*)((u8*)sizes + (arg1[0x14A] << 2)) = size;
            *(s32*)(arg1 + 0x14C) += size;
            arg1[0x14A]++;
        } while (func_80069F44(dir) == dir);
        ret = 0;
    } else {
        ret = 1;
    }
    if (ret == 0) {
        return 0;
    }
    return func_8001C5EC(D_800E2F96);
}
