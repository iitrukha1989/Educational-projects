NAME=My_matrix_oop
SOURСES := My_matrix_oop_const.cpp My_matrix_oop_helper.cpp \
My_matrix_oop_operators.cpp My_matrix_oop_overload.cpp
OBJECTS := My_matrix_oop_const.o My_matrix_oop_helper.o \
My_matrix_oop_operators.o My_matrix_oop_overload.o
CFLAGS :=#-Wall -Werror -Wextra -std=c++17

OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	CHECKFLAGS=-lcheck
else
	CHECKFLAGS=-lcheck -pthread -lrt -lm -lsubunit -ldl
endif

all: $(NAME).a test

$(NAME).a:
	g++ $(CFLAGS) -c -std=c++17 $(SOURСES) 
	@ar rcs lib$(NAME).a $(OBJECTS)
	@ranlib lib$(NAME).a
	@cp lib$(NAME).a $(NAME).a

test:
	@g++ My_matrix_oop_helper.cpp My_matrix_oop_operators.cpp My_matrix_oop_overload.cpp My_matrix_oop_const.cpp My_matrix_oop_test.cpp -lgtest -std=c++17 -o test
	@./test

clean:
	@rm -rf ./*.o ./*.a ./a.out test ./build

#----Checking
linter:
	echo "--------Linter Cpplint.py--------"
	python3 ../materials/linters/cpplint.py --extensions=cpp $(SOURСES) My_matrix_oop.h
leaks:
	echo "--------Leaks Checking--------"
	CK_FORK=no leaks -atExit -- ./test
cppcheck:
	echo "--------Static Code Checking--------"
	cppcheck --enable=all --suppress=missingIncludeSystem ./
valgrind:
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test
#valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./test
