SHELL := /bin/bash

TARGET = s21_string_test
LIB_STRING = s21_string.a
LIB_STRING_TEST = s21_string_test.a
CC = gcc 
CFLAGS = -Wall -Werror -Wextra -std=c11
CHECKFLAGS = -lcheck
COVFLAGS = -fprofile-arcs -ftest-coverage

DIR_REPORT = report
DIR_STRING_C = string_c
DIR_STRING_O = string_o
DIR_STRING_RUN = string_run
DIR_TESTS = string_tests
DIR_TESTS_CHECK = string_tests_check
DIR_LIBRARY = s21_library

all: clean $(LIB_STRING)
	make test
	make gcov_report

# object files
SRCS_STRING = $(wildcard $(DIR_STRING_C)/s21_*.c)
SRCS_SPRINTF = $(wildcard $(DIR_STRING_C)/$(DIR_LIBRARY)/s21_*.c)

OBJS = $(patsubst $(DIR_STRING_C)/%.c, $(DIR_STRING_O)/%.o, $(SRCS_STRING))
$(DIR_STRING_O)/%.o: $(DIR_STRING_C)/%.c | $(DIR_STRING_O)
	$(CC) $(CFLAGS) -c $< -o $@

OBJS_SPRINTF  = $(patsubst $(DIR_STRING_C)/$(DIR_LIBRARY)/%.c, $(DIR_STRING_O)/$(DIR_LIBRARY)/%.o, $(SRCS_SPRINTF))
$(DIR_STRING_O)/$(DIR_LIBRARY)/%.o: $(DIR_STRING_C)/$(DIR_LIBRARY)/%.c | $(DIR_STRING_O)
	$(CC) $(CFLAGS) -c $< -o $@

# creating s21_string.a
$(LIB_STRING): $(OBJS) $(OBJS_SPRINTF)
	ar rcs $@ $^

# creating folders
$(DIR_STRING_O):
	@mkdir -p $(DIR_STRING_O)/$(DIR_LIBRARY)
$(DIR_STRING_RUN):
	@mkdir -p $(DIR_STRING_RUN)/$(DIR_LIBRARY)


# testing
SRCS_TESTS = $(wildcard $(DIR_TESTS)/s21_*_test.c)
NAMES_STRING = $(patsubst $(DIR_STRING_C)/s21_%.c, s21_%, $(SRCS_STRING))
NAMES_TESTS = $(patsubst $(DIR_TESTS)/s21_%_test.c, s21_%, $(SRCS_TESTS))
COMMON_NAMES = $(filter $(NAMES_STRING), $(NAMES_TESTS))
EXECUTABLES = $(patsubst s21_%, $(DIR_STRING_RUN)/s21_%, $(COMMON_NAMES))

SRCS_TESTS_SPRINTF = $(wildcard $(DIR_TESTS)/$(DIR_LIBRARY)_test/s21_*_test.c)
NAMES_SPRINTF = $(patsubst $(DIR_STRING_C)/$(DIR_LIBRARY)/s21_%.c, s21_%, $(SRCS_SPRINTF))
NAMES_TESTS_SPRINTF = $(patsubst $(DIR_TESTS)/$(DIR_LIBRARY)_test/s21_%_test.c, s21_%, $(SRCS_TESTS_SPRINTF))
COMMON_NAMES_SPRINTF = $(filter $(NAMES_SPRINTF), $(NAMES_TESTS_SPRINTF))
EXECUTABLES_SPRINTF = $(patsubst s21_%, $(DIR_STRING_RUN)/$(DIR_LIBRARY)/s21_%, $(COMMON_NAMES_SPRINTF))

EXECUTABLES += $(EXECUTABLES_SPRINTF)

$(DIR_STRING_RUN)/s21_%: s21_string.a $(DIR_TESTS)/s21_%_test.c  | $(DIR_STRING_RUN)
	$(CC)$(CFLAGS) $^ -o $@ $(CHECKFLAGS)

$(DIR_STRING_RUN)/$(DIR_LIBRARY)/s21_%: s21_string.a $(DIR_TESTS)/$(DIR_LIBRARY)_test/s21_%_test.c  | $(DIR_STRING_RUN)
	$(CC)$(CFLAGS) $^ -o $@ $(CHECKFLAGS)

test: clean $(EXECUTABLES)
	@for exec in $(EXECUTABLES); do \
    echo "Running $$exec:"; \
    $$exec; \
	done

# creating ".c" files from ".check" files
CHECK_FILES = $(wildcard $(DIR_TESTS_CHECK)/*.check)
C_FILES = $(patsubst $(DIR_TESTS_CHECK)/%.check, $(DIR_TESTS)/%.c, $(CHECK_FILES))

$(DIR_TESTS)/%.c: $(DIR_TESTS_CHECK)/%.check	
	checkmk clean_mode=1 $< > $@

CHECK_FILES_SPRINTF = $(wildcard $(DIR_TESTS_CHECK)/$(DIR_LIBRARY)_check/*.check)
C_FILES_SPRINTF = $(patsubst $(DIR_TESTS_CHECK)/$(DIR_LIBRARY)_check/%.check, $(DIR_TESTS)/$(DIR_LIBRARY)_test/%.c, $(CHECK_FILES_SPRINTF))

$(DIR_TESTS)/%.c: $(DIR_TESTS_CHECK)/%.check	
	checkmk clean_mode=1 $< > $@

$(DIR_TESTS)/$(DIR_LIBRARY)_test/%.c: $(DIR_TESTS_CHECK)/$(DIR_LIBRARY)_check/%.check
	checkmk clean_mode=1 $< > $@

checkmk: clean $(C_FILES) $(C_FILES_SPRINTF)
	# make clang

clang:
	clang-format -i *.h **/*.c **/**/*.c 

# cleaning
clean:
	rm -rf $(DIR_STRING_O)/
	rm -rf $(DIR_STRING_RUN)/
	rm -rf $(DIR_REPORT)/
	rm -f $(LIB_STRING)
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.o
	rm -f *.info

# creating html report
GCOV_EXECUTABLES = $(patsubst s21_%, $(DIR_STRING_RUN)/s21_%_gcov, $(COMMON_NAMES))
GCOV_EXECUTABLES_SPRINTF = $(patsubst s21_%, $(DIR_STRING_RUN)/$(DIR_LIBRARY)/s21_%_gcov, $(COMMON_NAMES_SPRINTF))
# GCOV_EXECUTABLES += GCOV_EXECUTABLES_SPRINTF

$(DIR_STRING_RUN)/s21_%_gcov: s21_string.a $(DIR_TESTS)/s21_%_test.c  | $(DIR_STRING_RUN)
	$(CC)$(CFLAGS) --coverage $(CHECKFLAGS) $^ -o $@

$(DIR_STRING_RUN)/$(DIR_LIBRARY)/s21_%_gcov: s21_string.a $(DIR_TESTS)/$(DIR_LIBRARY)_test/s21_%_test.c  | $(DIR_STRING_RUN)
	$(CC)$(CFLAGS) --coverage $(CHECKFLAGS) $^ -o $@

gcov_report: clean $(GCOV_EXECUTABLES) $(GCOV_EXECUTABLES_SPRINTF)
	@for exec in $(GCOV_EXECUTABLES); do \
    echo "Running $$exec:"; \
    $$exec; \
	done
	@for exec in $(GCOV_EXECUTABLES_SPRINTF); do \
    echo "Running $$exec:"; \
    $$exec; \
	done
	lcov -t "s21_test" -d . -c -o s21_test.info 
	genhtml -o $(DIR_REPORT) s21_test.info 
	open $(DIR_REPORT)/index.html
	rm -f *.gcda
	rm -f *.gcno

rebuild :
	make clean
	make all
