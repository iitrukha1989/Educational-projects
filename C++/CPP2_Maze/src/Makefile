PROJECT_DIR_NAME :=Maze
SOURCES :=$(PROJECT_DIR_NAME)/Controller/controller.cc \
    $(PROJECT_DIR_NAME)/View/main.cc \
    $(PROJECT_DIR_NAME)/View/mainwindow.cc  \
    $(PROJECT_DIR_NAME)/Model/eller_labyrinth.cc \
    $(PROJECT_DIR_NAME)/Model/matrix.cc \
	$(PROJECT_DIR_NAME)/Model/model_cave.cc \
	$(PROJECT_DIR_NAME)/Model/parse_file.cc \
	$(PROJECT_DIR_NAME)/Model/find_way.cc
HEADERS :=$(PROJECT_DIR_NAME)/Controller/controller.h \
    $(PROJECT_DIR_NAME)/View/mainwindow.h \
    $(PROJECT_DIR_NAME)/Model/eller_labyrinth.h \
    $(PROJECT_DIR_NAME)/Model/matrix.h \
    $(PROJECT_DIR_NAME)/Model/model_cave.h \
	$(PROJECT_DIR_NAME)/Model/parse_file.h \
	$(PROJECT_DIR_NAME)/Model/find_way.h
TEST_DIR :=tests
TEST_NAME :=$(TEST_DIR)/test
TEST_FILES :=$(TEST_DIR)/test_cave.cc \
	$(TEST_DIR)/test_findway.cc \
	$(TEST_DIR)/test_labyrinth.cc
TEXI2HTML :=makeinfo --no-split --html --no-warn
MAKEINFO :=makeinfo --no-warn
TEXI2DVI :=texi2dvi --dvipdf -q
CC := g++ -std=c++17 
CFLAGS := -Wall -Werror -Wextra
GCOV := -fprofile-arcs -ftest-coverage
OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	GTESTFLAGS=-lgtest -lgtest_main
	OPENFILE=open
	APP_NAME=Maze.app
	APP_DIR_NAME=$(HOME)/Applications/MAZE/
	AVOID_EXCEPTION_LEAKS=-fsanitize=address
else
	GTESTFLAGS=-lgtest -lgtest_main -lpthread -lrt -lm -lsubunit -ldl
	OPENFILE=xdg-open
	APP_NAME=Maze
	APP_DIR_NAME=MAZE_out
	AVOID_EXCEPTION_LEAKS=
endif
.PHONY: tests

all: install html dist

install:
	@mkdir $(APP_DIR_NAME)
	qmake -o NewMakefile $(PROJECT_DIR_NAME)/Maze.pro
	make -f NewMakefile qmake_all
#надо проверить, нужно ли строчка ниже?
	make -f NewMakefile -j1
	@mv $(APP_NAME) $(APP_DIR_NAME)/$(APP_NAME)
	@make clean

uninstall:
	rm -rf $(APP_DIR_NAME)
	@rm -rf $(APP_DIR_NAME).tar.gz

info: manual.texi
	mkdir -p $(APP_DIR_NAME)
	$(MAKEINFO) manual.texi
	mv manual.info $(APP_DIR_NAME)/manual.info

html: manual.texi 
	mkdir -p $(APP_DIR_NAME)
	$(TEXI2HTML) manual.texi
	mv manual.html $(APP_DIR_NAME)/manual.html
	@$(OPENFILE) $(APP_DIR_NAME)/manual.html

# This aim doesn't work properly on Mac
# Only for english text
dvi: manual.texi
	mkdir -p $(APP_DIR_NAME)
	$(TEXI2DVI) manual.texi
	find . \( -name "*.dvi" -o -name "*.log" -o -name "*.toc" -o -name "*.aux" -o -name "*.pdf" \) \
	-exec mv  -t ./$(APP_DIR_NAME) "{}" +

dist: 
	tar -czvf $(APP_DIR_NAME).tar.gz $(APP_DIR_NAME)

tests: $(TEST_FILES)
	$(CC) $(CFLAGS) $(AVOID_EXCEPTION_LEAKS) $(GCOV) $(TEST_FILES) $(PROJECT_DIR_NAME)/Model/*.cc $(PROJECT_DIR_NAME)/Controller/*.cc $(GTESTFLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)

gcov_report: tests
	@lcov -t "GcovReport" -o GcovReport.info -c -d . --no-external
	@lcov --remove GcovReport.info '*/src/Maze/Model/matrix.cc' -o GcovReportNew.info
	@genhtml  -o report GcovReportNew.info
	$(OPENFILE) ./report/index.html
	@rm -f $(TEST_NAME)
	@rm -f *.gcno *.gcda *.info
	
clean:
	@rm -rf *.o *.a a.out *.txt ./$(PROJECT_DIR_NAME)/*.pro.user
	@rm -rf $(TEST_NAME)
	@rm -rf *.gcno *.gcda *.info
	@rm -rf ./report
	@rm -rf moc_* ui_* .qmake.stash qrc_rsc.cpp NewMakefile
	@rm -rf build*

rebuild: clean all

clang:
	clang-format -i $(SOURCES) $(HEADERS)

#----Checking
linter:
	echo "--------Linter Clang-Format--------"
	clang-format -n $(SOURCES) $(HEADERS)
leaks:
	echo "--------Leaks Checking--------"
	CK_FORK=no leaks -atExit -- ./$(TEST_NAME) >leaks-out.txt 2>&1
cppcheck:
	echo "--------Static Code Checking--------"
	cppcheck --enable=all --suppress=missingIncludeSystem --check-config . $(PROJECT_DIR_NAME)/
valgrind:
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes $(TEST_NAME) >valgrind-out.txt 2>&1
