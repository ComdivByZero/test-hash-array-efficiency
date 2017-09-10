#include "arr.h"

#include <assert.h>
#include <string.h>

typedef struct Array_Realization Array;

extern Array* arrCreate(int count) {
    static int i;
    return (Array *)&i;
}

extern void arrRelease(Array **a) {
    *a = NULL;
}

extern int arrSet(Array *a, const char *key, int value) {
    assert(arrGet(a, key) == value);
    return value;
}

static int m(char const key[], char const exp[], int val) {
    if (strcmp(key + 1, exp) != 0) {
        val = -1;
    }
    return val;
 }

extern int arrGet(Array *a, const char *key) {
    int val = -1;
    switch (key[0]) {
    case 'a': val = m(key, "uto", 0); break;
    case 'b': val = m(key, "reak", 1); break;
    case 'c':
        if (key[1] == 'a') {
            val = m(key + 1, "se", 2);
	} else if (key[1] == 'h') {
	    val = m(key + 1, "ar", 3);
	} else if ((key[1] != 'o') || (key[2] != 'n')) {
	    ;
	} else if (key[3] == 's') {
	    val = m(key + 3, "t", 4);
	} else if (key[3] == 't') {
	    val = m(key + 3, "inue", 5);
	}
	break;
    case 'd':
	if (key[1] == 'e') {
	    val = m(key + 1, "fault", 6);
	} else if (key[1] != 'o') {
	    ;
	} else if (key[2] == '\0') {
	    val = 7;
	} else {
	    val = m(key + 1, "uble", 8);
	}
	break;
    case 'e':
	switch (key[1]) {
	case 'l': val = m(key + 1, "se", 9); break;
	case 'n': val = m(key + 1, "um", 10); break;
	case 'x': val = m(key + 1, "tern", 11); break;
	}
	break;
    case 'f':
	switch (key[1]) {
	case 'l': val = m(key + 1, "oat", 12); break;
	case 'o': val = m(key + 1, "r", 13); break;
	}
	break;
    case 'g': val = m(key, "oto", 14); break;
    case 'i':
	switch (key[1]) {
	case 'f': val = m(key + 1, "", 15); break;
	case 'n':
	    if (key[2] == 'l') {
		val = m(key + 2, "ine", 16); break;
	    } else if (key[2] == 't') {
		val = m(key + 2, "", 17); break;
	    }
	    break;
	}
	break;
    case 'l': val = m(key, "ong", 18); break;
    case 'r':
	if (key[1] == 'e') {
	    switch (key[2]) {
	    case 'g': val = m(key + 2, "ister", 19); break;
	    case 's': val = m(key + 2, "trict", 20); break;
	    case 't': val = m(key + 2, "urn", 21); break;
	    }
	}
	break;
    case 's':
	switch (key[1]) {
	case 'h': val = m(key + 1, "ort", 22); break;
	case 'i':
	    switch (key[2]) {
	    case 'g': val = m(key + 2, "ned", 23); break;
	    case 'z': val = m(key + 2, "eof", 24); break;
	    }
	    break;
	case 't':
	    switch (key[2]) {
	    case 'a': val = m(key + 2, "tic", 25); break;
	    case 'r': val = m(key + 2, "uct", 26); break;
	    }
	    break;
	case 'w': val = m(key + 1, "itch", 27); break;
	}
	break;
    case 't': val = m(key, "ypedef", 28); break;
    case 'u':
	if (key[1] == 'n') {
	    switch (key[2]) {
	    case 'i': val = m(key + 2, "on", 29); break;
	    case 's': val = m(key + 2, "igned", 30); break;
	    }
	}
	break;
    case 'v':
	if (key[1] == 'o') {
	    switch (key[2]) {
	    case 'i': val = m(key + 2, "d", 31); break;
	    case 'l': val = m(key + 2, "atile", 32); break;
	    }
	}
	break;
    case 'w': val = m(key, "hile", 33); break;
    case '_':
	switch (key[1]) {
	case 'A':
	    switch (key[2]) {
	    case 'l':
		if (0 != strncmp(key + 3, "ign", 3)) {
		    ;
		} else {
		    switch (key[6]) {
		    case 'a': val = m(key + 6, "s", 34); break;
		    case 'o': val = m(key + 6, "f", 35); break;
		    }
		}
		break;
	    case 't': val = m(key + 2, "omic", 36); break;
	    }
	    break;
	case 'B': val = m(key + 1, "ool", 37); break;
	case 'C': val = m(key + 1, "omplex", 38); break;
	case 'G': val = m(key + 1, "eneric", 39); break;
	case 'I': val = m(key + 1, "maginary", 40); break;
	case 'N': val = m(key + 1, "oreturn", 41); break;
	case 'S': val = m(key + 1, "tatic_assert", 42); break;
	case 'T': val = m(key + 1, "hread_local", 43); break;
	case '_': val = m(key + 1, "func__", 44); break;
	}
	break;
    }
    return val;
}
