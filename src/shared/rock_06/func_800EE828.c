#include "common.h"

void func_800EE828(void* self) {
    s32 flag;
    s8 st;
    s32 t;
    register s32 one asm("$2");

    if (*(u8*)((u8*)self + 0x8D) == 0 && !(*(u8*)((u8*)self + 0x97) & 2) &&
        (*(u16*)((u8*)self + 0x8A) & 0x100)) {
        if (*(s8*)((u8*)self + 0x2) == 0) {
            one = 1;
            st = *(s8*)((u8*)self + 0x5);
            do {
                if (st == one) {
                    goto zero;
                }
                if (st == 2) {
                    goto zero;
                }
            } while (0);
            if (st == 5) {
                goto zero;
            }
            flag = 1;
        } else {
            one = 1;
            st = *(s8*)((u8*)self + 0x5);
            flag = 1;
            if (st == 0) {
                goto done;
            }
            do {
                if (st == one) {
                    goto zero;
                }
                if (st == 2) {
                    goto zero;
                }
                if (st == 5) {
                    goto zero;
                }
                if (st == 4) {
                    goto zero;
                }
            } while (0);
            if (st == 12) {
                do {
                zero:
                    flag = 0;
                } while (0);
            }
        }
    done:
        if (flag == 0) {
            if (*(s8*)((u8*)self + 0x67) == 0) {
                t = *(u8*)((u8*)self + 0x97);
                *(s8*)((u8*)self + 0x5) = 7;
                goto common;
            }
            if (*(u8*)((u8*)self + 0x7D) == 0) {
                t = *(u8*)((u8*)self + 0x97);
                *(s8*)((u8*)self + 0x5) = 0xF;
            common:
                do {
                    *(s8*)((u8*)self + 0x6) = 0;
                } while (0);
                t |= 8;
                *(u8*)((u8*)self + 0x97) = t;
            }
        }
    }
}
