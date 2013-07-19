CPPC:=g++
OPTS:=-O3

all: wordfilter words.data c.test cpp.test cpp.uo.test

wordfilter:
	mkdir -p binary
	flex -o /tmp/wf.lex.c source/wf.l
	$(CC) /tmp/wf.lex.c -lfl -o binary/$@

CC_CALL:=$(CC) source/*.c source/c/*.c -Isource -Isource/c

words.data:
	$(CC_CALL) -E | binary/wordfilter > data/$@;

c.test:
	mkdir -p binary
	$(CC_CALL) $(OPTS) -o binary/$@

CPPC_CALL:=$(CPPC) $(OPTS) source/*.c source/cpp/*.c* -Isource -Isource/cpp

cpp.test:
	mkdir -p binary
	$(CPPC_CALL) -Isource/cpp/map -o binary/$@

cpp.uo.test:
	mkdir -p binary
	$(CPPC_CALL) -Isource/cpp/unordered -std=c++0x -o binary/$@

clean:
	rm -rf binary data/words.data

.PHONY: all clean
