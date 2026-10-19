#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EF2E8(struct X4_MainObj* self);
extern u8 D_800CCF38;
extern u16 D_800F70DC;
#define D_800F70DC (*(s16*)&D_800F70DC)

void func_800EE628(void* arg0) {
    if (D_800CCF38 >= 2) {
        if (D_800F70DC < 2) {
            // !FAKE: both range tests share the call block, as retail does
            goto call;
        }
    } else if (D_800F70DC <= 0) {
        // !FAKE: both range tests share the call block, as retail does
        goto call;
    }
    M2C_FIELD(arg0, u8*, 5) = 6;
    M2C_FIELD(arg0, u8*, 6) = 0;
    return;
call:
    func_800179A4(arg0, 4);
    func_800EF2E8(arg0);
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
#undef D_800F70DC
