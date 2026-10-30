#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0);                    /* extern */
M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void pump_file_loads(void);                         /* extern */
void reset_level(void);                           /* extern */

void silence_sound(u8, u8);
void func_80017E6C(void);
void stop_cd_audio(void);
void func_80025F84();
void func_8002C2B8();
void func_8001DC6C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    ((M2C_UNK(*)())func_80025F84)();
    ((M2C_UNK(*)())stop_cd_audio)();
    silence_sound(0xFF, 0);
    reset_level();
    ((M2C_UNK(*)())func_8002C2B8)();
    func_80014F70(0xA2, 0, 0);
    pump_file_loads();
    set_resolution(1);
    ((M2C_UNK(*)())func_80017E6C)();
    M2C_FIELD(arg0, s16*, 4) = 4;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}
