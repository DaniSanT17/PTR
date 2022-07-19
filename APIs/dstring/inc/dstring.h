/* ADT Matrix */

#ifndef _DSTRING_H
#define _DSTRING_H

typedef struct dynamicString {
	char *strBuff;
	int size;
} DString;

DString *dstring_create(char *string, int size); // Done +-
DString *dstring_from_char(char string); // Done +-
DString *dstring_from_int(int size); // Done +-
DString *dstring_from_double(double size); // Done +-
DString *dstring_from_float(float size); // Done +-
DString *dstring_from_long(int long size); // Done +-
DString *dstring_from_dstring(DString *string); // Done +-
DString *dstring_concat(DString *string1, DString *string2); // Done +-
int dstring_size(DString *string); // Done +-
char *dstring_buffer(DString *string); // Done +-
void print_dstring(DString *str); // Done +-

#endif
