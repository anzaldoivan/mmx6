#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80012890(s32 arg0);
M2C_UNK func_80013BF0(void);
M2C_UNK func_80013DE8();
void func_80016178(void);
void func_8001642C(s32 arg0, s32* arg1, u8* arg2);
void func_8001750C(u8 arg0, u8 arg1);
void func_800186A8(void);
void func_80021400(void);
void func_80025F84(void);
void func_8002B838(void);
void func_8002C1DC();
void func_8002C2B8();
extern u8 D_800710BC[];
extern s8 D_80097426;

void func_8001D460(void* arg0) {
    func_80012890(0);
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    D_80097426 = 1;
    func_80025F84();
    func_800186A8();
    func_8001750C(0xFF, 0);
    func_8002B838();
    func_8002C2B8();
    func_8002C1DC();
    ((void (*)())func_8001642C)(D_800710BC[M2C_FIELD(arg0, s8*, 0xC)],
                                0x801F6000);
    func_80016178();
    func_80021400();
    func_80013BF0();
    func_80013DE8();
    M2C_FIELD(arg0, s16*, 0x4) = 0x960;
    M2C_FIELD(arg0, u8*, 0x1) += 1;
}
