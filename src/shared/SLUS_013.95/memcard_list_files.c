// prog SLUS_013.95 | system memcard | range 0x8001C4C0-0x8001C5E8
// Shared file: included by src/SLUS_013.95/120A0.c, between memcard_read_save_file and func_8001C5EC.
#include "common.h"
#include "mmx6/x4.h"

extern const struct X4_MemcardPath D_800100AC;
extern u8 D_800E2F96;
s32 func_8001C5EC(s32);
void memset(void* dst, s32 c, s32 n);
char* strcpy(char* dst, char* src);
void* nextfile(void* dir);
void* firstfile(char* name, void* dir);

static inline void func_8001C4C0_name(char* path, char* name) {
    *(struct X4_MemcardPath*)path = D_800100AC;
    memset(path + 6, 0, 0x1A);
    strcpy(path + 5, name);
}

// 0x8001C4C0 memcard_list_files: lists the card's files whose name matches, and sums their sizes.
// basis: string strings.tsv:6:SLUS_013.95:0x800100AC
// callers: none known
// str 0x800100AC "bu00:" = "memory card device, slot 1"
s32 memcard_list_files(s32 arg0, u8* arg1, char* arg2) {
    s32 dir[10];
    char path[32];
    s32 ret;
    s32 size;
    s32* sizes;

    func_8001C4C0_name(path, arg2);
    arg1[0x14A] = 0;
    *(s32*)(arg1 + 0x14C) = 0;
    path[2] += arg0;
    if (firstfile(path, dir) == dir) {
        sizes = (s32*)(arg1 + 0x150);
        do {
            strcpy((char*)(arg1 + arg1[0x14A] * 0x16), (char*)dir);
            size = dir[6];
            *(s32*)((u8*)sizes + (arg1[0x14A] << 2)) = size;
            *(s32*)(arg1 + 0x14C) += size;
            arg1[0x14A]++;
        } while (nextfile(dir) == dir);
        ret = 0;
    } else {
        ret = 1;
    }
    if (ret == 0) {
        return 0;
    }
    return func_8001C5EC(D_800E2F96);
}
