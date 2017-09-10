#include <unordered_map>
#include <string.h>

struct CharsHash {
	std::size_t operator()(const char* str) const {
		int i, h;
		i = 1;
		h = str[0];
		while ((i < 3) && (str[i] != '\0')) {
			h = (h * 256 + (unsigned char)str[i]) % 65536;
			i++;
		}
		return h;
	}
};

struct CharsEqual {
	bool operator()(const char *a, const char *b) const {
		return strcmp(a, b) == 0;
	}
};

typedef std::unordered_map<const char *, int, CharsHash, CharsEqual> RArray;

static RArray* newArray(int size) {
	RArray *a = new RArray();
	a->reserve(size);
	return a;
}
