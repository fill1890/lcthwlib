CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LDFLAGS=$(OPTLIBS)
PREFIX?=/usr/local

ifeq ($(shell uname -s),Linux)
	LDLIBS=-lm
endif

ifdef $(test -f /usr/include/bsd/stdlib.h && true)
	CFLAGS+=-DBSD_STDLIB
endif

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

PROGRAMS_SRC=$(wildcard bin/*.c)
PROGRAMS=$(patsubst %.c,%,$(PROGRAMS_SRC))

TARGET=build/liblcthw.a

# Target build
all: $(TARGET) test $(PROGRAMS)

dev: CFLAGS=-g -O0 -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(PROGRAMS): LDLIBS+=-L./build -llcthw

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

build:
	@mkdir -p build
	@mkdir -p bin

# Unit tests
.PHONY: test
test: LDLIBS += $(TARGET)
test: $(TESTS)
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS) $(PROGRAMS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# Checker
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true

