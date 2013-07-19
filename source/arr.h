typedef struct Array_Realization Array;

extern Array* arrCreate(int count);
extern void arrRelease(Array **a);

extern int arrSet(Array *a, const char *key, int value);
extern int arrGet(Array *a, const char *key);
