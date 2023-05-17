CC = g++ -g -Wall -Werror -Wextra #-fsanitize=address
CFLAGS = -c
OFLAGS = -o
COVFLAGS = -fprofile-arcs  -lcheck -ftest-coverage
TESTF = -lgtest -lgtest_main


all: test

gcov_report: test
	gcov -f *.gcda
	lcov/bin/./lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=0
	lcov/bin/./genhtml -o report test.info  --rc lcov_branch_coverage=0
	open report/index.html

test: s21_matrix_oop.a
		$(CC) $(CFLAGS) test.cc
		$(CC) --coverage $(OFLAGS) test.out test.o $(TESTF) -L. s21_matrix_oop.a
		./test.out

s21_matrix_oop.a: s21_matrix_oop.o
		ar rc s21_matrix_oop.a s21_matrix_oop.o
		ranlib s21_matrix_oop.a

s21_matrix_oop.o:
		$(CC) $(CFLAGS) $(COVFLAGS) s21_matrix_oop.cc


leaks: clean test
		leaks -atExit -- ./test.out

cppcheck:
		cppcheck --enable=all --suppress=missingIncludeSystem *.cc

style:
		@cp ../materials/linters/.clang-format .
		clang-format -n *.cc *.h
		@rm -rf .clang-format

clean:
		@rm -rf *.out *.o *.a *.gcov *.gcda *.gcno *.info report