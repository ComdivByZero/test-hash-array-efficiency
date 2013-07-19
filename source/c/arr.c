#include "arr.h"

#include <stdlib.h>
#include <string.h>

typedef struct {
	const char *key;
	int value;
} Item;

struct Array_Realization {
	int count;
	Item *items;
};

static int hash(const char str[], int mod) {
	int i, h;
	i = 1;
	h = str[0];
	while ((i < 3) && (str[i] != '\0')) {
		h = (h * 256 + (unsigned char)str[i]) % mod;
		i++;
	}
	return h;
}

extern Array* arrCreate(int count) {
	Array *arr;
	arr = (Array *)malloc(sizeof(Array) + sizeof(Item) * count);
	if (arr != NULL) {
		arr->items = (Item *)(arr + 1);
		arr->count = count;
		memset(arr->items, 0, count * sizeof(Item));
	}
	return arr;
}

extern void arrRelease(Array **arr) {
	free(*arr); *arr = NULL;
}

static int arrIndex(Array *arr, const char *key) {
	int h, cnt;
	Item *el;
	el = arr->items;
	cnt = arr->count;
	h = hash(key, cnt);
	while ((el[h].key != NULL) && (strcmp(el[h].key, key) != 0)) {
		h = (h + 1) % cnt;
	}
	return h;
}

extern int arrSet(Array *arr, const char *key, int value) {
	int h;
	h = arrIndex(arr, key);
	if (arr->items[h].key == NULL) {
		arr->items[h].key = key;
		arr->items[h].value = value;
	} else {
		h = -h;
	}
	return h;
}

extern int arrGet(Array *arr, const char *key) {
	int h, v;
	h = arrIndex(arr, key);
	if (arr->items[h].key != NULL) {
		v = arr->items[h].value;
	} else {
		v = -1;
	}
	return v;
}
