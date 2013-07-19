#include "arr.h"

#include <string.h>

#include "arrdef.h"

extern Array* arrCreate(int count) {
	return (Array *)(new RArray());
}

extern void arrRelease(Array **a) {
	delete (RArray *)*a;
	*a = NULL;
}

extern int arrSet(Array *arr, const char *key, int value) {
	(*(RArray *)arr)[key] = value;
	return 0;
}

extern int arrGet(Array *arr, const char *key) {
	RArray::const_iterator item;
	int v;
	item = ((RArray *)arr)->find(key);
	if (item == ((RArray *)arr)->end()) {
		v = -1;
	} else {
		v = item->second;
	}
	return v;
}
