SHELL = /bin/sh

CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11
CFLAGS:=$(FLAGS)
GCOV:=$(FLAGS) -coverage
SRC=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))
TEST_SRC=$(wildcard tests/*.c)
TEST_OBJS=$(patsubst %.c,%.o,$(wildcard tests/*.c))

.PHONY: all clean test gcov_report debug run ext1_flag ext2_flag base_flag main

all: clean s21_matrix.a

clean:
	-rm -rf *.out *.o *.gcno *.gcda *.info report/ s21_matrix.a ./test tests/*.o

test: $(TEST_OBJS) s21_matrix.a
	$(CC) $(CFLAGS) $^ -o test -lcheck -lm -lsubunit -L. -l:s21_matrix.a
	-./test

$(TEST_OBJS): $(TEST_SRC) tests/test_s21_matrix.h

s21_matrix.a: $(OBJS)
	ar rc $@ *.o
	ranlib s21_matrix.a

gcov_report: clean ext1_flag s21_matrix.a base_flag $(TEST_OBJS) ext2_flag test
	-rm -rf report/
	lcov -t "s21_matrix_report" -o s21_matrix_report.info -c -d .
	genhtml -o report s21_matrix_report.info

verter: clean
	-chmod +x ../materials/build/run.sh
	-cd ../materials/build/ && ./run.sh

control: clean
	make test
	-clear
	-cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h tests/*.c tests/*.h
	-valgrind --tool=memcheck --leak-check=yes ./test
	-clang-format -n *.c *.h tests/*.c tests/*.h

valgrind:
	make test
	-clear
	-valgrind --tool=memcheck --leak-check=yes ./test
	-clang-format -n *.c *.h tests/*.c tests/*.h

main: s21_math.a debug/main.o
	$(CC) $(CFLAGS) $^ -o debug/main -lcheck -lsubunit -L. -l:s21_matrix.a -lm
	-make clean
	-debug/main

debug/main.o: s21_matrix.h

run:
	-./test

ext1_flag:
	$(eval CFLAGS:=$(GCOV))
ext2_flag:
	$(eval CFLAGS:=$(GCOV))
base_flag:
	$(eval CFLAGS:=$(FLAGS))

$(OBJS): $(SRC) s21_matrix.h