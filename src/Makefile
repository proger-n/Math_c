CC = gcc -Wall -Werror -Wextra
OS := $(shell uname)

ifeq ($(OS),Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
	OPEN_CMD = xdg-open
else
	FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
	OPEN_CMD = open
endif

all: clean s21_math.a gcov_report

s21_math.a:
	$(CC) -c functions/s21*.c
	ar -crs s21_math.a s21_*.o
	
test: clean s21_math.a
	$(CC) tests/test_prog.c s21_math.a $(FLAGS) -o test_prog
	./test_prog

gcov_report: clean
	$(CC) tests/test_prog.c functions/s21*.c $(FLAGS) -o test_prog
	./test_prog
	lcov -t "./test_prog" -o report.info --no-external -c -d .
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o s21_math.a test_prog *.gcno *gcda *.gcov gcov report report.info

clang:
	clang-format -style=Google -n *.c *.h
