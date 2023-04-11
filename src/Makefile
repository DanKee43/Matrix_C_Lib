FLAGS = -g -Wall -Werror -Wextra -std=c11
CHECK_LIB = -lcheck
OS:=$(shell uname -s)

LIB_SRC = lib/*.c


ifeq ($(OS), Linux)
	CHECK_LIB += -lrt -lpthread -lm -lsubunit
endif


all: clean test gcov_report


s21_matrix.a: s21_matrix.o
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

s21_matrix.o:
	gcc $(FLAGS) -c $(LIB_SRC) -lm


test: s21_matrix.a clean
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage $(LIB_SRC) test.c -o test $(CHECK_LIB)
	./test

style:
	clang-format -n s21_matrix.h *.c lib/*.c

gcov_report: test
	@mkdir coverage
	@lcov --directory . --capture -o coverage/lcov.info
	@genhtml -o coverage/ coverage/lcov.info --highlight --legend --title "s21_matrix coverage"
ifeq ($(OS), Darwin)
	@open coverage/index.html
else
	@xdg-open coverage/index.html
endif


rebuild: clean all

clean:
	rm -rf *.out
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf test
	rm -rf coverage