#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0);
M2C_UNK func_800139A0(s8);
void func_800144AC(void);
void silence_sound(u8, u8);
void func_80017E6C(void);
void stop_cd_audio(void);
void func_80025F84(void);
void reset_level(void);
void func_8002C2B8();
void* alloc_sprite_slot();

void func_8001D7AC(void* arg0) {
    u8* obj;

    set_resolution(1);
    M2C_FIELD(arg0, u8*, 0xD) = 1;
    func_80025F84();
    stop_cd_audio();
    silence_sound(0xFF, 0);
    reset_level();
    func_8002C2B8();
    func_800144AC();
    func_80017E6C();
    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[1] = 0x15;
        obj[0] = 1;
        obj[0x47] = 0;
        obj[2] = 0;
        M2C_FIELD(obj, s16*, 0xA) = 0x80;
        M2C_FIELD(obj, s16*, 0xE) = 0x78;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[1] = 0x15;
        obj[0] = 1;
        obj[0x47] = 1;
        obj[2] = 0;
        M2C_FIELD(obj, s16*, 0xA) = 0x180;
        M2C_FIELD(obj, s16*, 0xE) = 0x78;
    }
    M2C_FIELD(arg0, s16*, 4) = 0x12C;
    ((void (*)(s8))func_800139A0)(8);
    M2C_FIELD(arg0, u8*, 1) += 1;
}
