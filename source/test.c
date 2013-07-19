#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "arr.h"

typedef struct {
	char *wp[65536];
	int count;
} Words;

static void split(char buf[], void word(void *cont, char *w, int n), void *cont) {
	int i, j, k;
	i = 0;
	j = 0;
	while (buf[j] != '\0') {
		k = j;
		while ((buf[j] != '\0') && (buf[j] != '\n')) {
			j++;
		}
		if (k < j) {
			buf[j] = '\0';
			word(cont, buf + k, i);
			i++;
		}
		j++;
	}
}

static bool load(char buf[], const char *fname, int size) {
	FILE *f;
	int len;
	f = fopen(fname, "r");
	if (f == NULL) {
		len = 0;
	} else {
		len = fread(buf, sizeof(char), size, f);
		fclose(f);
	}
	buf[len] = '\0';
	buf[len + 1] = '\0';
	return len > 0;
}

static void wordsMark(Words *ws, char *w, int i) {
	ws->wp[i] = w;
	ws->count = i + 1;
}

static Array* init(char keys[], char words[], Words *wp) {
	Array *a;
	if (load(keys, "data/keywords.data", 512) && load(words, "data/words.data", 512 * 1024)) {
		a = arrCreate(1023);
		split(keys, (void (*)(void *, char *, int))arrSet, (void *)a);
		split(words, (void (*)(void *, char *, int))wordsMark, (void *)wp);
	} else {
		a = NULL;
	}
	return a;
}

static long test(Array *a, Words *wp, int count) {
	int i;
	long sum;
	sum = 0;
	while (count > 0) {
		for (i = 0; i < wp->count; i++) {
			sum += arrGet(a, wp->wp[i]);
		}
		count--;
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	Array *a;
	long sum;
	char keywords[512 + 2];
	char words[512 * 1024 + 2];
	Words wp;
	int count;
	if (argc > 1) {
		count = atoi(argv[1]);
		if (count <= 0) {
			count = 1;
		}
	} else {
		count = 1;
	}
	a = init(keywords, words, &wp);
	sum = test(a, &wp, count);
	printf("%ld\n", sum);
	arrRelease(&a);
	return 0;
}
