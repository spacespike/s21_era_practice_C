CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname)
TEST_FILE_NAME = tests.c
TARGET = s21_matrix.a

SRC:=$(shell find . -maxdepth 1 -name "s21*.c")
OBJS:=$(SRC:%.c=%.o)

GCOV_FLAGS:=-fprofile-arcs -ftest-coverage
CHECKFLAGS_BREW = -I$$(brew --prefix check)/include -L"$$(brew --prefix check)/lib" -lcheck
#TEST_LIBS_VAR3:=$(shell pkg-config --cflags --libs check)

ifeq ($(OS), Darwin)
	TEST_LIBS= -lcheck
else
	TEST_LIBS= -lcheck -lsubunit -pthread -lrt -lm
endif

all: s21_matrix.a gcov_report

clean:
	rm -rf *.*o *.a *.so *.g* *.html *.css test report *.txt test.dSYM
	
test: $(TEST_FILE_NAME) s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_FILE_NAME) $(TARGET) -o test $(TEST_LIBS) --coverage
	./test

tests_macOS_fix_brew: $(TEST_FILE_NAME) s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_FILE_NAME) $(TARGET) -o test $(CHECKFLAGS_BREW) --coverage
	./test

s21_matrix.a: clean $(OBJS)
	ar -rcs s21_matrix.a $(OBJS)
	rm -f *.o

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h
	make test

ifeq ($(OS), Darwin)
	leaks --atExit -- test 
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif

style:
	clang-format -style=Google -n *.[ch]

.PHONY: all clean test gcov_report check style