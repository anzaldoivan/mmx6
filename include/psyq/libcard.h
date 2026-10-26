/* psyq/libcard.h -- prototypes of the LIBCARD.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBCARD_H
#define PSYQ_LIBCARD_H

// LIBCARD C171.OBJ+0x0, retail SLUS_013.95 0x800698D4
long _card_info(long);
// LIBCARD C172.OBJ+0x0, retail SLUS_013.95 0x800698E4
long _card_load(long);
// LIBCARD CARD.OBJ+0x0, retail SLUS_013.95 0x800698F4
long _card_clear(long);
// LIBCARD A78.OBJ+0x0, retail SLUS_013.95 0x80069934
long _card_write(long, long, unsigned char *);
// LIBCARD A80.OBJ+0x0, retail SLUS_013.95 0x80069944
void _new_card(void);
// LIBCARD INIT.OBJ+0x0, retail SLUS_013.95 0x80069954
void InitCARD(long);
// LIBCARD INIT.OBJ+0x90, retail SLUS_013.95 0x800699E4
long StartCARD(void);
// LIBCARD INIT.OBJ+0xd8, retail SLUS_013.95 0x80069A2C
long StopCARD(void);
// LIBCARD A74.OBJ+0x0, retail SLUS_013.95 0x80069A54
int InitCARD2();
// LIBCARD A75.OBJ+0x0, retail SLUS_013.95 0x80069A64
int StartCARD2();
// LIBCARD A76.OBJ+0x0, retail SLUS_013.95 0x80069A74
int StopCARD2();
// LIBCARD PATCH.OBJ+0x0, retail SLUS_013.95 0x80069A84
int _patch_card_info();
// LIBCARD PATCH.OBJ+0xdc, retail SLUS_013.95 0x80069B60
int _patch_card();
// LIBCARD PATCH.OBJ+0x170, retail SLUS_013.95 0x80069BF4
int _patch_card2();
// LIBCARD PATCH.OBJ+0x1e0, retail SLUS_013.95 0x80069C64
int _copy_memcard_patch();
// LIBCARD END.OBJ+0x0, retail SLUS_013.95 0x80069CA4
int _ExitCard();

#endif /* PSYQ_LIBCARD_H */
