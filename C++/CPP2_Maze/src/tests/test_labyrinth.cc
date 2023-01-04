#include <gtest/gtest.h>

#include "../Maze/Controller/controller.h"
s21::Controller lab_1;

TEST(GenerationLabyrinth, test_1) {
    auto result = lab_1.GenerateIdealLabyrinth(10, 10);
    s21::EllerLabyrinth lab_model(10, 10);
    lab_model.GenerateLabyrinth();
    ASSERT_EQ(result.first.size(), lab_model.GetVerticalBorders().size());
    ASSERT_EQ(result.second.size(), lab_model.GetHorizontalBorders().size());
}

TEST(GenerationLabyrinth, test_2) {
    auto result = lab_1.GenerateIdealLabyrinth(9, 35);
    s21::EllerLabyrinth lab_model(9, 35);
    lab_model.GenerateLabyrinth();
    ASSERT_EQ(result.first.size(), lab_model.GetVerticalBorders().size());
    ASSERT_EQ(result.second.size(), lab_model.GetHorizontalBorders().size());
}

TEST(GenerationLabyrinth, test_3) {
    auto result = lab_1.GenerateIdealLabyrinth(25, 5);
    s21::EllerLabyrinth lab_model(25, 5);
    lab_model.GenerateLabyrinth();
    ASSERT_EQ(result.first.size(), lab_model.GetVerticalBorders().size());
    ASSERT_EQ(result.second.size(), lab_model.GetHorizontalBorders().size());
}

TEST(GenerationLabyrinth, test_4) {
    auto result = lab_1.GenerateIdealLabyrinth(50, 50);
    s21::EllerLabyrinth lab_model(50, 50);
    lab_model.GenerateLabyrinth();
    ASSERT_EQ(result.first.size(), lab_model.GetVerticalBorders().size());
    ASSERT_EQ(result.second.size(), lab_model.GetHorizontalBorders().size());
}

TEST(GenerationLabyrinth, test_5) {
    ASSERT_ANY_THROW(lab_1.GenerateIdealLabyrinth(0, 0));
    ASSERT_ANY_THROW(s21::EllerLabyrinth lab_model(0, 0));
}

TEST(GenerationLabyrinth, test_6) {
    ASSERT_ANY_THROW(lab_1.GenerateIdealLabyrinth(51, 51));
    ASSERT_ANY_THROW(s21::EllerLabyrinth lab_model(51, 51));
}