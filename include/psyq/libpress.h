/* psyq/libpress.h -- prototypes of the LIBPRESS.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBPRESS_H
#define PSYQ_LIBPRESS_H

struct DECDCTENV;

// LIBPRESS LIBPRESS.OBJ+0x0, retail SLUS_013.95 0x80068EB4
void DecDCTReset(int);
// LIBPRESS LIBPRESS.OBJ+0x34, retail SLUS_013.95 0x80068EE8
struct DECDCTENV *DecDCTGetEnv(struct DECDCTENV *);
// LIBPRESS LIBPRESS.OBJ+0xc0, retail SLUS_013.95 0x80068F74
struct DECDCTENV *DecDCTPutEnv(struct DECDCTENV *);
// LIBPRESS LIBPRESS.OBJ+0x158, retail SLUS_013.95 0x8006900C
void DecDCTin(unsigned long *, int);
// LIBPRESS LIBPRESS.OBJ+0x1d4, retail SLUS_013.95 0x80069088
void DecDCTout(unsigned long *, int);
// LIBPRESS LIBPRESS.OBJ+0x1f4, retail SLUS_013.95 0x800690A8
int DecDCTinSync(int);
// LIBPRESS LIBPRESS.OBJ+0x230, retail SLUS_013.95 0x800690E4
int DecDCToutSync(int);
// LIBPRESS LIBPRESS.OBJ+0x278, retail SLUS_013.95 0x8006912C
int DecDCTinCallback(void (*)());
// LIBPRESS LIBPRESS.OBJ+0x29c, retail SLUS_013.95 0x80069150
int DecDCToutCallback(void (*)());
// 0x80069174 MDEC_rest: resets the MDEC decoder in the mode its argument selects.
// basis: string strings.tsv:107:SLUS_013.95:0x80012050
// str 0x80012050 "MDEC_rest:bad option(%d)\n" = "debug print for an unknown reset mode"
// static in the vendor object: no prototype, no caller in C
// 0x80069380 MDEC_in_sync: waits until the MDEC input transfer has finished.
// basis: string strings.tsv:108:SLUS_013.95:0x8001206C
// str 0x8001206C "MDEC_in_sync" = "function name in its timeout message"
// static in the vendor object: no prototype, no caller in C
// 0x80069414 MDEC_out_sync: waits until the MDEC output transfer has finished.
// basis: string strings.tsv:109:SLUS_013.95:0x8001207C
// str 0x8001207C "MDEC_out_sync" = "function name in its timeout message"
// static in the vendor object: no prototype, no caller in C
// LIBPRESS VLC.OBJ+0x0, retail SLUS_013.95 0x80069544
int DecDCTvlcSize(int);
// LIBPRESS VLC.OBJ+0x30, retail SLUS_013.95 0x80069574
int DecDCTvlc(unsigned long *, unsigned long *);

#endif /* PSYQ_LIBPRESS_H */
