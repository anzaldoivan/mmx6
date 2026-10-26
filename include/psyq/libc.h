/* psyq/libc.h -- prototypes of the LIBC.LIB functions the retail SLUS_013.95 links.
 *
 * Written for mmx6 from interface facts only: name, address and call signature. No SDK header text.
 * Each prototype carries one line: library, object+offset inside it, retail address.
 * basis: config/psyq/names.tsv (ok rows), prototypes config/psyq/protos.tsv (written by T4.c2 from both).
 */
#ifndef PSYQ_LIBC_H
#define PSYQ_LIBC_H

// LIBC A63.OBJ+0x8, retail SLUS_013.95 0x80069D2C
void puts(const char *);
// LIBC C19.OBJ+0x0, retail SLUS_013.95 0x80069D44
int setjmp(int *);
// LIBC C23.OBJ+0x0, retail SLUS_013.95 0x80069D54
int strcmp();
// LIBC C24.OBJ+0x0, retail SLUS_013.95 0x80069D64
int strncmp(const char *, const char *, int);
// LIBC C25.OBJ+0x0, retail SLUS_013.95 0x80069D74
char *strcpy();
// LIBC C42.OBJ+0x0, retail SLUS_013.95 0x80069D84
void *memcpy();
// LIBC C43.OBJ+0x0, retail SLUS_013.95 0x80069D94
void *memset();
// LIBC C63.OBJ+0x0, retail SLUS_013.95 0x80069DA4
int printf(const char *, ...);
// LIBC C40.OBJ+0x0, retail SLUS_013.95 0x8006B754
void *bzero(unsigned char *, int);

#endif /* PSYQ_LIBC_H */
