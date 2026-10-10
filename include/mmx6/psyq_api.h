/* psyq_api.h -- the PlayStation runtime-library (PsyQ) interface types and constants the W-x4 ports use.
 *
 * Hand-written for mmx6 (never generated). Written from interface facts only: each type's member order, member
 * types and sizes, and each constant's value, as the compiled code depends on them (verified by the byte gate,
 * `make fleet`). No SDK header text is reproduced here; see docs/prior-art.md. Names carry the X4_ prefix that
 * include/mmx6/x4.h and the banked x4 bodies already use; x4port.py never emits these into x4.h (G102).
 */
#ifndef MMX6_PSYQ_API_H
#define MMX6_PSYQ_API_H

/* ---- scalar shorthands (1, 2, 4 bytes) ---- */
typedef unsigned char X4_u_char;
typedef unsigned short X4_u_short;
typedef unsigned long X4_u_long;

/* 8 bytes: two longs */
typedef struct X4__quad {
    long val[2];
} X4_quad;

/* ---- CD-ROM library ---- */

/* CdControl command: pause the drive */
#ifndef CdlPause
#define CdlPause 0x09
#endif

/* 4 bytes: a disc position, one byte each */
typedef struct {
    X4_u_char minute, second, sector, track;
} X4_CdlLOC;

/* 4 bytes: audio attenuation, four volume bytes */
typedef struct {
    X4_u_char val0, val1, val2, val3;
} X4_CdlATV;

/* completion callback: (status byte, result buffer) */
typedef void (*X4_CdlCB)(X4_u_char, X4_u_char*);

/* ---- graphics library ---- */

/* 8 bytes: a rectangle, x/y then width/height as shorts */
typedef struct {
    short x, y, w, h;
} X4_RECT;

/* 64 bytes: a drawing-environment packet, a tag word and 15 command words */
typedef struct {
    X4_u_long tag, code[15];
} X4_DR_ENV;

/* 92 bytes: drawing environment; offsets 0 clip, 8 ofs, 12 tw, 20 tpage, 22 dtd, 23 dfe, 24 isbg, 25 r0 g0 b0,
   28 dr_env */
typedef struct {
    X4_RECT clip;
    short ofs[2];
    X4_RECT tw;
    X4_u_short tpage;
    X4_u_char dtd, dfe, isbg, r0, g0, b0;
    X4_DR_ENV dr_env;
} X4_DRAWENV;

/* 20 bytes: display environment; offsets 0 disp, 8 screen, 16 isinter, 17 isrgb24, 18-19 padding */
typedef struct {
    X4_RECT disp, screen;
    X4_u_char isinter, isrgb24, pad0, pad1;
} X4_DISPENV;

/* 8 bytes: primitive header; a 24-bit next-pointer and an 8-bit word count in one word, then colour and code */
typedef struct {
    unsigned addr : 24, len : 8;
    X4_u_char r0;
    X4_u_char g0;
    X4_u_char b0;
    X4_u_char code;
} X4_P_TAG;

#endif /* MMX6_PSYQ_API_H */
