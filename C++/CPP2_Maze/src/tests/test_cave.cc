#include <gtest/gtest.h>

#include <iostream>

#include "../Maze/Controller/controller.h"

std::string file_cave_1 = "examples/example_cave_1.txt";
std::string file_cave_2 = "examples/example_cave_2.txt";
std::string file_cave_3 = "examples/example_cave_3.txt";
std::string file_cave_4 = "examples/example_cave_4.txt";
std::string file_cave_5 = "examples/example_cave_4(bad).txt";

s21::ModelCave cave_value;
s21::Controller controller_value;
s21::ParseFile parse_value;

TEST(ReadFile, test_parsing_1) {
    parse_value.ReadData(file_cave_1);
    auto reader_vertical = parse_value.GetMazeVert();
    auto reader_horizont = parse_value.GetMazeHoriz();
    controller_value.OpenFile(file_cave_1);
    auto controller_vertical = controller_value.GetMaze().first;
    auto controller_horizont = controller_value.GetMaze().second;
    ASSERT_EQ(reader_vertical.size(), controller_vertical.size());
    ASSERT_EQ(reader_horizont.size(), controller_horizont.size());
    ASSERT_EQ(parse_value.GetRows(), controller_value.GetRows());
    ASSERT_EQ(parse_value.GetColunms(), controller_value.GetColumns());
}

TEST(ReadFile, test_parsing_2) {
    parse_value.ReadData(file_cave_2);
    auto reader_vertical = parse_value.GetMazeVert();
    auto reader_horizont = parse_value.GetMazeHoriz();
    controller_value.OpenFile(file_cave_2);
    auto controller_vertical = controller_value.GetMaze().first;
    auto controller_horizont = controller_value.GetMaze().second;
    ASSERT_EQ(reader_vertical.size(), controller_vertical.size());
    ASSERT_EQ(reader_horizont.size(), controller_horizont.size());
    ASSERT_EQ(parse_value.GetRows(), controller_value.GetRows());
    ASSERT_EQ(parse_value.GetColunms(), controller_value.GetColumns());
}

TEST(ReadFile, test_parsing_3) {
    parse_value.ReadData(file_cave_3);
    auto reader_vertical = parse_value.GetMazeVert();
    auto reader_horizont = parse_value.GetMazeHoriz();
    controller_value.OpenFile(file_cave_3);
    auto controller_vertical = controller_value.GetMaze().first;
    auto controller_horizont = controller_value.GetMaze().second;
    ASSERT_EQ(reader_vertical.size(), controller_vertical.size());
    ASSERT_EQ(reader_horizont.size(), controller_horizont.size());
    ASSERT_EQ(parse_value.GetRows(), controller_value.GetRows());
    ASSERT_EQ(parse_value.GetColunms(), controller_value.GetColumns());
}

TEST(ReadFile, test_parsing_4) {
    parse_value.ReadData(file_cave_4);
    auto reader_vertical = parse_value.GetMazeVert();
    auto reader_horizont = parse_value.GetMazeHoriz();
    controller_value.OpenFile(file_cave_4);
    auto controller_vertical = controller_value.GetMaze().first;
    auto controller_horizont = controller_value.GetMaze().second;
    ASSERT_EQ(reader_vertical.size(), controller_vertical.size());
    ASSERT_EQ(reader_horizont.size(), controller_horizont.size());
    ASSERT_EQ(parse_value.GetRows(), controller_value.GetRows());
    ASSERT_EQ(parse_value.GetColunms(), controller_value.GetColumns());
}

TEST(ReadFile, test_parsing_5) {
    parse_value.ReadData(file_cave_5);
    ASSERT_ANY_THROW(parse_value.CheckCave());
    controller_value.OpenFile(file_cave_5);
    ASSERT_ANY_THROW(controller_value.CheckCave());
}

TEST(GeneratorCave, test_generate_1) {
    cave_value.GeneratorCave(10, 10, 0);
    std::vector<size_t> cave_array = cave_value.GetIndexArray();
    for (auto element : cave_array) {
        ASSERT_EQ(static_cast<int>(element), 0);
    }
}

TEST(GeneratorCave, test_generate_2) {
    cave_value.GeneratorCave(25, 25, 0);
    std::vector<size_t> cave_array = cave_value.GetIndexArray();
    for (auto element : cave_array) {
        ASSERT_EQ(static_cast<int>(element), 0);
    }
}

TEST(GeneratorCave, test_generate_3) {
    cave_value.GeneratorCave(50, 50, 0);
    std::vector<size_t> cave_array = cave_value.GetIndexArray();
    for (auto element : cave_array) {
        ASSERT_EQ(static_cast<int>(element), 0);
    }
}

TEST(GeneratorCave, test_generate_4) {
    cave_value.GeneratorCave(10, 10, 1);
    int count_check = 0;
    std::vector<size_t> cave_array = cave_value.GetIndexArray();
    for (auto element : cave_array) {
        count_check = count_check + static_cast<int>(element);
    }
    ASSERT_GT(count_check, 0);
}

TEST(GeneratorCave, test_generate_5) {
    cave_value.GeneratorCave(10, 10, 2);
    int count_check = 0;
    std::vector<size_t> cave_array = cave_value.GetIndexArray();
    for (auto element : cave_array) {
        count_check = count_check + static_cast<int>(element);
    }
    ASSERT_GT(count_check, 0);
}

TEST(GeneratorCave, test_generate_6) {
    cave_value.GeneratorCave(10, 10, 7);
    int count_check = 0;
    std::vector<size_t> cave_array = cave_value.GetIndexArray();
    for (auto element : cave_array) {
        count_check = count_check + static_cast<int>(element);
    }
    ASSERT_GT(count_check, 0);
}

TEST(NextState, test_next_1) {
    cave_value.GeneratorCave(10, 10, 1);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState, test_next_2) {
    cave_value.GeneratorCave(25, 25, 3);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState, test_next_3) {
    cave_value.GeneratorCave(50, 50, 6);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState_Birth, test_birth_1) {
    cave_value.GeneratorCave(10, 10, 1);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitBirth(2);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState_Birth, test_birth_2) {
    cave_value.GeneratorCave(25, 25, 3);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitBirth(4);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState_Birth, test_birth_3) {
    cave_value.GeneratorCave(50, 50, 6);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitBirth(7);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}
TEST(NextState_Death, test_death_1) {
    cave_value.GeneratorCave(10, 10, 1);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitDeath(2);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState_Death, test_death_2) {
    cave_value.GeneratorCave(25, 25, 3);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitDeath(4);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState_Death, test_death_3) {
    cave_value.GeneratorCave(50, 50, 6);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitDeath(7);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState_BirthDeath, test_birth_death_1) {
    cave_value.GeneratorCave(10, 10, 1);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitBirth(7);
    cave_value.SetLimitDeath(2);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState_BirthDeath, test_birth_death_2) {
    cave_value.GeneratorCave(25, 25, 3);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitBirth(1);
    cave_value.SetLimitDeath(4);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}

TEST(NextState_BirthDeath, test_birth_death_3) {
    cave_value.GeneratorCave(50, 50, 6);
    std::vector<size_t> cave_array_1 = cave_value.GetIndexArray();
    cave_value.SetLimitBirth(5);
    cave_value.SetLimitDeath(3);
    cave_value.NextState();
    std::vector<size_t> cave_array_2 = cave_value.GetIndexArray();
    ASSERT_EQ(cave_array_1.size(), cave_array_2.size());
}
