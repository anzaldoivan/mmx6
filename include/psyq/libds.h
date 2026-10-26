/* psyq/libds.h -- prototypes of the LIBDS.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBDS_H
#define PSYQ_LIBDS_H

// LIBDS D3_002.OBJ+0x0, retail SLUS_013.95 0x80064CB4
int DsGetSector(void *, int);

#endif /* PSYQ_LIBDS_H */
