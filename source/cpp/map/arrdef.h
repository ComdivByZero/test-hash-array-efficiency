#include <map>

struct Cmp {
	bool operator()(char const *a, char const *b) {
		return strcmp(a, b) < 0;
	}
};

typedef std::map<const char *, int, Cmp> RArray;