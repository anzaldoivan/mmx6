/* psyq/libgte.h -- prototypes of the LIBGTE.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBGTE_H
#define PSYQ_LIBGTE_H

// LIBGTE GEO_00.OBJ+0x0, retail SLUS_013.95 0x80065944
int rsin(int);
// LIBGTE GEO_00.OBJ+0x3c, retail SLUS_013.95 0x80065980
int sin_1();
// LIBGTE GEO_01.OBJ+0x0, retail SLUS_013.95 0x80065A14
int rcos(int);
// LIBGTE MSC00.OBJ+0x8, retail SLUS_013.95 0x80065ABC
void InitGeom();
// LIBGTE REG12.OBJ+0x0, retail SLUS_013.95 0x80065B44
void SetGeomOffset(long, long);
// LIBGTE REG13.OBJ+0x0, retail SLUS_013.95 0x80065B64
void SetGeomScreen(long);
// LIBGTE RATAN.OBJ+0x0, retail SLUS_013.95 0x80065B74
long ratan2(long, long);
// LIBGTE PATCHGTE.OBJ+0x0, retail SLUS_013.95 0x80065CF4
int _patch_gte();

#endif /* PSYQ_LIBGTE_H */
