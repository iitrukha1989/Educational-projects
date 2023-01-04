#include <gtest/gtest.h>

#include "../Maze/Controller/controller.h"

std::string file_1 = "examples/example_maze_1.txt";
std::string file_3 = "examples/example_maze_3.txt";
std::string file_6 = "examples/example_maze_6(bad).txt";
std::string file_8 = "examples/example_maze_8(bad).txt";
s21::ParseFile reader;
s21::Controller lab_2;
s21::FindWay findway;

TEST(FindWayLabyrinth, test_parsing_1) {
    reader.ReadData(file_1);
    auto reader_vertical = reader.GetMazeVert();
    auto reader_horizont = reader.GetMazeHoriz();
    lab_2.OpenFile(file_1);
    auto lab_vertical = lab_2.GetMaze().first;
    auto lab_horizont = lab_2.GetMaze().second;
    ASSERT_EQ(reader_vertical.size(), lab_vertical.size());
    ASSERT_EQ(reader_horizont.size(), lab_horizont.size());
    ASSERT_EQ(reader.GetRows(), lab_2.GetRows());
    ASSERT_EQ(reader.GetColunms(), lab_2.GetColumns());
}

TEST(FindWayLabyrinth, test_parsing_2) {
    reader.ReadData(file_3);
    auto reader_vertical = reader.GetMazeVert();
    auto reader_horizont = reader.GetMazeHoriz();
    lab_2.OpenFile(file_3);
    auto lab_vertical = lab_2.GetMaze().first;
    auto lab_horizont = lab_2.GetMaze().second;
    ASSERT_EQ(reader_vertical.size(), lab_vertical.size());
    ASSERT_EQ(reader_horizont.size(), lab_horizont.size());
    ASSERT_EQ(reader.GetRows(), lab_2.GetRows());
    ASSERT_EQ(reader.GetColunms(), lab_2.GetColumns());
}

TEST(FindWayLabyrinth, test_parsing_3) {
    reader.ReadData(file_6);
    ASSERT_ANY_THROW(reader.CheckMaze());
    lab_2.OpenFile(file_6);
    ASSERT_ANY_THROW(lab_2.CheckMaze());
}

TEST(FindWayLabyrinth, test_parsing_4) {
    reader.ReadData(file_8);
    auto reader_vertical = reader.GetMazeVert();
    auto reader_horizont = reader.GetMazeHoriz();
    lab_2.OpenFile(file_8);
    auto lab_vertical = lab_2.GetMaze().first;
    auto lab_horizont = lab_2.GetMaze().second;
    ASSERT_EQ(reader_vertical.size(), lab_vertical.size());
    ASSERT_EQ(reader_horizont.size(), lab_horizont.size());
    ASSERT_EQ(reader.GetRows(), lab_2.GetRows());
    ASSERT_EQ(reader.GetColunms(), lab_2.GetColumns());
}

TEST(FindWayLabyrinth, test_findway_1) {
    lab_2.OpenFile(file_1);
    auto map = lab_2.GetMaze();
    auto rows = lab_2.GetRows();
    auto cols = lab_2.GetColumns();
    std::pair<size_t, size_t> start = std::make_pair(0, 0);
    std::pair<size_t, size_t> finish = std::make_pair(9, 9);
    auto result_1 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_1.size()), 49);

    start = std::make_pair(9, 9);
    finish = std::make_pair(0, 0);
    auto result_2 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_2.size()), 49);

    start = std::make_pair(2, 1);
    finish = std::make_pair(6, 6);
    auto result_3 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_3.size()), 36);

    start = std::make_pair(0, 4);
    finish = std::make_pair(9, 1);
    auto result_4 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_4.size()), 33);

    start = std::make_pair(3, 2);
    finish = std::make_pair(3, 1);
    auto result_5 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_5.size()), 2);
}

TEST(FindWayLabyrinth, test_findway_2) {
    lab_2.OpenFile(file_3);
    auto map = lab_2.GetMaze();
    auto rows = lab_2.GetRows();
    auto cols = lab_2.GetColumns();
    std::pair<size_t, size_t> start = std::make_pair(0, 0);
    std::pair<size_t, size_t> finish = std::make_pair(19, 19);
    auto result_1 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_1.size()), 53);

    start = std::make_pair(19, 19);
    finish = std::make_pair(0, 0);
    auto result_2 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_2.size()), 53);

    start = std::make_pair(9, 2);
    finish = std::make_pair(9, 12);
    auto result_3 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_3.size()), 29);

    start = std::make_pair(15, 12);
    finish = std::make_pair(11, 8);
    auto result_4 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_4.size()), 13);

    start = std::make_pair(1, 13);
    finish = std::make_pair(1, 14);
    auto result_5 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_5.size()), 2);
}

TEST(FindWayLabyrinth, test_findway_3) {
    lab_2.OpenFile(file_8);
    auto map = lab_2.GetMaze();
    auto rows = lab_2.GetRows();
    auto cols = lab_2.GetColumns();
    std::pair<size_t, size_t> start = std::make_pair(0, 0);
    std::pair<size_t, size_t> finish = std::make_pair(3, 1);
    auto result_1 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_1.size()), 5);

    start = std::make_pair(3, 0);
    finish = std::make_pair(3, 1);
    auto result_2 = lab_2.SolveLabyrinth(start, finish, rows, cols, map);
    ASSERT_EQ(static_cast<int>(result_2.size()), 2);

    start = std::make_pair(1, 1);
    finish = std::make_pair(3, 2);
    ASSERT_ANY_THROW(lab_2.SolveLabyrinth(start, finish, rows, cols, map));
}