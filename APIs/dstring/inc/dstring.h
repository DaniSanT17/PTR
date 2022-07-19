/* ADT Matrix */

#ifndef _DSTRING_H
#define _DSTRING_H

typedef struct dynamicString {
	char *strBuff;
	int size;
} DString;

DString *dstring_create(char *string);
DString *dstring_from_char(char string);
DString *dstring_from_int(int size);
DString *dstring_from_double(double size);
DString *dstring_from_float(float size);
DString *dstring_from_long(int long size);
DString *dstring_from_dstring(DString *string);
DString *dstring_concat(DString *string1, DString string2);
int dstring_size(DString string);
char *dstring_buffer(DString string);

#endif
