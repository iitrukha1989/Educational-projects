NAME :=My_Calculator
SOURCES :=$(NAME)/Controller/controller_calc.cpp \
	$(NAME)/Controller/controller_credit.cpp \
	$(NAME)/Controller/controller_deposit.cpp \
	$(NAME)/Model/model_calc.cpp \
	$(NAME)/Model/model_credit.cpp \
	$(NAME)/Model/model_deposit.cpp \
	$(NAME)/View/credit_calculate.cpp \
	$(NAME)/View/deposit_calculate.cpp \
	$(NAME)/View/dialog.cpp \
	$(NAME)/View/main.cpp \
	$(NAME)/View/mainwindow.cpp \
SOURCES_H :=$(NAME)/Controller/controller_calc.h \
	$(NAME)/Controller/controller_credit.h \
	$(NAME)/Controller/controller_deposit.h \
	$(NAME)/Model/model_calc.h \
	$(NAME)/Model/model_credit.h \
	$(NAME)/Model/model_deposit.h \
	$(NAME)/View/credit_calculate.h \
	$(NAME)/View/deposit_calculate.h \
	$(NAME)/View/dialog.h \
	$(NAME)/View/mainwindow.h \

APP_NAME :=My_Calculator_v2.0
NAME_TEST :=test
CC := g++ -std=c++17
CFLAGS := -Wall -Werror -Wextra
GCOV := -fprofile-arcs -ftest-coverage

OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	GTESTFLAGS=-lgtest -lgtest_main 
	OPENFILE=open
else
	GTESTFLAGS=-lgtest -lgtest_main -lpthread -lrt -lm -lsubunit -ldl
	OPENFILE=xdg-open 
endif

all: tests gcov_report install dist dvi

# before execution the "install" target, you need to correct the directory of the "qmake" utility
install:
	mkdir $(APP_NAME)
	/Users/ilya_truhanovich/Qt/6.3.1/macos/bin/qmake -o NewMakefile $(NAME)/My_calculate.pro
	make -f NewMakefile qmake_all
	make -f NewMakefile -j12
	mv My_calculate.app $(APP_NAME)/My_calculate.app
	rm .qmake.stash moc_credit_calculate.cpp moc_deposit_calculate.cpp \
	moc_dialog.cpp moc_qcustomplot.cpp moc_mainwindow.cpp \
	qmake_qmake_qm_files.qrc qrc_qmake_qmake_qm_files.cpp \
	ui_credit_calculate.h ui_deposit_calculate.h ui_dialog.h ui_mainwindow.h  
	rm -rf .qm/
	make clean

uninstall:
	rm -rf $(APP_NAME)
	rm -rf NewMakefile
	rm -rf $(APP_NAME).tar.gz

# works only on mac
# dvi does not work on mac
dvi:
	makeinfo manual.texi --html
	open ./manual/index.html

dist:
	tar -czvf $(APP_NAME).tar.gz $(APP_NAME)
	
tests: $(NAME_TEST).cpp
	$(CC) $(GCOV) $(NAME_TEST).cpp $(NAME)/Model/model_calc.cpp $(GTESTFLAGS) -o $(NAME_TEST)
	./$(NAME_TEST)

gcov_report: tests
	lcov -t "GcovReport" -o GcovReport.info -c -d . --no-external
	genhtml  -o report GcovReport.info
	$(OPENFILE) ./report/index.html
	rm -f $(NAME_TEST) 
	rm -f *.gcno *.gcda *.info

clean:
	@rm -rf ./*.o ./*.a ./a.out ./GcovReport ./*.gcno ./*.gcda ./report ./*.info test test_debug
	rm -rf manual/
	rm -rf $(APP_NAME).tar.gz

#Checking
linter:
	echo "--------Linter Cpplint.py--------"
	python3 ../materials/linters/cpplint.py --extensions=cpp $(SOURCES) $(SOURCES_H)
leaks:
	echo "--------Leaks Checking--------"
	CK_FORK=no leaks -atExit -- ./$(NAME_TEST)
cppcheck:
	echo "--------Static Code Checking--------"
	cppcheck --enable=all --suppress=missingIncludeSystem --check-config . $(NAME)/
valgrind:
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./$(NAME_TEST) >valgrind-out.txt 2>&1
