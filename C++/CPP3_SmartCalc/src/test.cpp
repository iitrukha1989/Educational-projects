#include <gtest/gtest.h>

#include <iostream>

#include "My_Calculator/Model/model_calc.h"

TEST(TestSum, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("5+2+3+1");
    ASSERT_NEAR(tmp_value.GetData(), (5 + 2 + 3 + 1), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("10+15+47+99");
    ASSERT_NEAR(tmp_value.GetData(), (10 + 15 + 47 + 99), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("113+433+700+918");
    ASSERT_NEAR(tmp_value.GetData(), (113 + 433 + 700 + 918), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("1642+3792+5982+8190");
    ASSERT_NEAR(tmp_value.GetData(), (1642 + 3792 + 5982 + 8190), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("1642+3792+5982+8190");
    ASSERT_NEAR(tmp_value.GetData(), (1642 + 3792 + 5982 + 8190), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("1642.451+3792.1245+5982.3145+8190.5612");
    ASSERT_NEAR(tmp_value.GetData(),
                (1642.451 + 3792.1245 + 5982.3145 + 8190.5612), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestSum, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("5++2+3+1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("10+15+47++99");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("113++433++700++918");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("1642+3792+5982+8190++");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("++1642.451++3792.1245++5982.3145+8190.5612");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestSub, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("9-2-3-1");
    ASSERT_NEAR(tmp_value.GetData(), (9 - 2 - 3 - 1), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("99-13-37-19");
    ASSERT_NEAR(tmp_value.GetData(), (99 - 13 - 37 - 19), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("113-433-700-918");
    ASSERT_NEAR(tmp_value.GetData(), (113 - 433 - 700 - 918), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("8190-1235-2351-3601");
    ASSERT_NEAR(tmp_value.GetData(), (8190 - 1235 - 2351 - 3601), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("1642.451-3792.1245-5982.3145-8190.5612");
    ASSERT_NEAR(tmp_value.GetData(),
                (1642.451 - 3792.1245 - 5982.3145 - 8190.5612), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestSub, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("9--2-3-1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("99-13--37-19--");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("--113-433-700-918--");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("8190--1235--2351--3601");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("1642.451-3792.1245---5982.3145-8190.5612");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestMul, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("9*2*3*1");
    ASSERT_NEAR(tmp_value.GetData(), (9 * 2 * 3 * 1), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("99*13*37*19");
    ASSERT_NEAR(tmp_value.GetData(), (99 * 13 * 37 * 19), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("113*433*700");
    ASSERT_NEAR(tmp_value.GetData(), (113 * 433 * 700), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("8190*1235");
    ASSERT_NEAR(tmp_value.GetData(), (8190 * 1235), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("1642.451*3792.1245");
    ASSERT_NEAR(tmp_value.GetData(), (1642.451 * 3792.1245), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestMul, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("9*2**3*1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("**99*13*37**19");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("113***433**700**918");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("**8190*1235*2351**");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("1642.451*3792.1245**5982.3145");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestDiv, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("9/2/3/1");
    ASSERT_NEAR(tmp_value.GetData(), (9.0 / 2 / 3 / 1), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("99/13/37/19");
    ASSERT_NEAR(tmp_value.GetData(), (99.0 / 13 / 37 / 19), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("918/542/123/327");
    ASSERT_NEAR(tmp_value.GetData(), (918.0 / 542 / 123 / 327), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("8190/1235");
    ASSERT_NEAR(tmp_value.GetData(), (8190.0 / 1235), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("1554982.3145/1642.451");
    ASSERT_NEAR(tmp_value.GetData(), (1554982.3145 / 1642.451), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestDiv, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("9//2/3/1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("99//13/37/19//");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("918//542//123//327");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("//8190/1235");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("1554982.3145///1642.451");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestMod, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("5%2");
    ASSERT_NEAR(tmp_value.GetData(), (fmod(5, 2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("99%37");
    ASSERT_NEAR(tmp_value.GetData(), (fmod(99, 37)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("37%99");
    ASSERT_NEAR(tmp_value.GetData(), (fmod(37, 99)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("9792%1982");
    ASSERT_NEAR(tmp_value.GetData(), (fmod(9792, 1982)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("8190.5612%4001.234");
    ASSERT_NEAR(tmp_value.GetData(), (fmod(8190.5612, 4001.234)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestMod, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("5%%2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("99%%37");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("37%%99");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("9792%%1982");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("8190.5612%%4001.234");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestSin, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("S(1)");
    ASSERT_NEAR(tmp_value.GetData(), (sin(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("S(-1)");
    std::cout << "Check" << std::endl;
    ASSERT_NEAR(tmp_value.GetData(), (sin(-1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("S(3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (sin(3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("S(-3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (sin(-3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("S(0)");
    ASSERT_NEAR(tmp_value.GetData(), (sin(0)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestSin, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("S(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("S(-1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("S(3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("S(-3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("S(0");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestCos, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("C(1)");
    ASSERT_NEAR(tmp_value.GetData(), (cos(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("C(-1)");
    ASSERT_NEAR(tmp_value.GetData(), (cos(-1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("C(3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (cos(3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("C(-3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (cos(-3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("C(0)");
    ASSERT_NEAR(tmp_value.GetData(), (cos(0)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestCos, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("C(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("C(-1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("C(3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("C(-3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("C(0");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestTan, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("T(1)");
    ASSERT_NEAR(tmp_value.GetData(), (tan(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("T(-1)");
    ASSERT_NEAR(tmp_value.GetData(), (tan(-1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("T(3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (tan(3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("T(-3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (tan(-3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("T(0)");
    ASSERT_NEAR(tmp_value.GetData(), (tan(0)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestTan, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("T(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("T(-1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("T(3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("T(-3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("T(0");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestAsin, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("@(1)");
    ASSERT_NEAR(tmp_value.GetData(), (asin(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("@(-1)");
    ASSERT_NEAR(tmp_value.GetData(), (asin(-1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("@(0.5)");
    ASSERT_NEAR(tmp_value.GetData(), (asin(0.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("@(-0.5)");
    ASSERT_NEAR(tmp_value.GetData(), (asin(-0.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("@(0)");
    ASSERT_NEAR(tmp_value.GetData(), (asin(0)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestAsin, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("@(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("@(-1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("@(0.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("@(-0.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("@(0");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestAcos, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("#(1)");
    ASSERT_NEAR(tmp_value.GetData(), (acos(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("#(-1)");
    ASSERT_NEAR(tmp_value.GetData(), (acos(-1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("#(0.5)");
    ASSERT_NEAR(tmp_value.GetData(), (acos(0.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("#(-0.5)");
    ASSERT_NEAR(tmp_value.GetData(), (acos(-0.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("#(0)");
    ASSERT_NEAR(tmp_value.GetData(), (acos(0)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestAcos, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("#(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("#(-1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("#(0.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("#(-0.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("#(0");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestAtan, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("$(1)");
    ASSERT_NEAR(tmp_value.GetData(), (atan(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("$(-1)");
    ASSERT_NEAR(tmp_value.GetData(), (atan(-1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("$(3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (atan(3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("$(-3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (atan(-3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("$(0)");
    ASSERT_NEAR(tmp_value.GetData(), (atan(0)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestAtan, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("$(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("$(-1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("$(3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("$(-3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("$(0");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestLog, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("L(1)");
    ASSERT_NEAR(tmp_value.GetData(), (log10(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("L(1.5)");
    ASSERT_NEAR(tmp_value.GetData(), (log10(1.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("L(3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (log10(3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("L(10)");
    ASSERT_NEAR(tmp_value.GetData(), (log10(10)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("L(10.5)");
    ASSERT_NEAR(tmp_value.GetData(), (log10(10.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(Testlog, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("L(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("L(1.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("L(3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("L(10");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("L(10.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestLn, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("N(1)");
    ASSERT_NEAR(tmp_value.GetData(), (log(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("N(1.5)");
    ASSERT_NEAR(tmp_value.GetData(), (log(1.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("N(3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (log(3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("N(10)");
    ASSERT_NEAR(tmp_value.GetData(), (log(10)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("N(10.5)");
    ASSERT_NEAR(tmp_value.GetData(), (log(10.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestLn, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("N(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("N(1.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("N(3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("N(10");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("N(10.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestSqrt, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("&(1)");
    ASSERT_NEAR(tmp_value.GetData(), (sqrt(1)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("&(4)");
    ASSERT_NEAR(tmp_value.GetData(), (sqrt(4)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("&(3.2)");
    ASSERT_NEAR(tmp_value.GetData(), (sqrt(3.2)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("&(100)");
    ASSERT_NEAR(tmp_value.GetData(), (sqrt(100)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("&(1001.5)");
    ASSERT_NEAR(tmp_value.GetData(), (sqrt(1001.5)), 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

TEST(TestSqrt, test_incorrect) {
    My::Calculation tmp_value;
    tmp_value.Calculate("&(1");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("&(4");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("&(3.2");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("&(100");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();

    tmp_value.Calculate("&(1001.5");
    ASSERT_NEAR(tmp_value.GetData(), 0, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "Incorrect_input");
    tmp_value.Clear();
}

TEST(TestMix, test_correct) {
    My::Calculation tmp_value;
    tmp_value.Calculate("S(5*(-2))");
    ASSERT_NEAR(tmp_value.GetData(), 0.5440211, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("S(2)+(5-8)");
    ASSERT_NEAR(tmp_value.GetData(), -2.0907025, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("C(2.45)+(5.12-8.65)");
    ASSERT_NEAR(tmp_value.GetData(), -4.3002312, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("2-16/4+5-10");
    ASSERT_NEAR(tmp_value.GetData(), -7, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();

    tmp_value.Calculate("6+15-8^2-16/4+5-10");
    ASSERT_NEAR(tmp_value.GetData(), -52, 0.0000001);
    ASSERT_EQ(tmp_value.GetError(), "");
    tmp_value.Clear();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
