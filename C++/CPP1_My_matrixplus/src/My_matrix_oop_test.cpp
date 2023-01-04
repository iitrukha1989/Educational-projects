#include "My_matrix_oop.h"

#include <gtest/gtest.h>

TEST(MyMatrix, test_creat) {
    MyMatrix test_matrix_1;
    MyMatrix test_matrix_2;
    MyMatrix test_matrix_3(5, 5);
    MyMatrix test_matrix_4(5, 5);
    int index_array = 0;
    double input_array_1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double input_array_2[25] = {7, 2, 5, 14, 52, 16, 27, 38, 9,
                                7, 2, 5, 14, 52, 16, 27, 38, 9,
                                7, 2, 5, 14, 52, 16, 27};
    for (int i = 0; i < test_matrix_1.get_rows(); i++) {
        for (int j = 0; j < test_matrix_1.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_1.get_index_matrix(i, j),
                        test_matrix_2.get_index_matrix(i, j), 1e-6);
        }
    }
    for (int i = 0; i < test_matrix_3.get_rows(); i++) {
        for (int j = 0; j < test_matrix_3.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_3.get_index_matrix(i, j),
                        test_matrix_4.get_index_matrix(i, j), 1e-6);
        }
    }
    for (int i = 0; i < test_matrix_1.get_rows(); i++) {
        for (int j = 0; j < test_matrix_1.get_cols(); j++) {
            test_matrix_1.set_index_matrix(input_array_1[index_array], i, j);
            test_matrix_2.set_index_matrix(input_array_1[index_array], i, j);
            index_array++;
        }
    }
    index_array = 0;
    for (int i = 0; i < test_matrix_3.get_rows(); i++) {
        for (int j = 0; j < test_matrix_3.get_cols(); j++) {
            test_matrix_3.set_index_matrix(input_array_2[index_array], i, j);
            test_matrix_4.set_index_matrix(input_array_2[index_array], i, j);
            index_array++;
        }
    }
    for (int i = 0; i < test_matrix_1.get_rows(); i++) {
        for (int j = 0; j < test_matrix_1.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_1.get_index_matrix(i, j),
                        test_matrix_2.get_index_matrix(i, j), 1e-6);
        }
    }
    for (int i = 0; i < test_matrix_3.get_rows(); i++) {
        for (int j = 0; j < test_matrix_3.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_3.get_index_matrix(i, j),
                        test_matrix_4.get_index_matrix(i, j), 1e-6);
        }
    }
    MyMatrix test_matrix_5(test_matrix_1);
    for (int i = 0; i < test_matrix_5.get_rows(); i++) {
        for (int j = 0; j < test_matrix_5.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_5.get_index_matrix(i, j),
                        test_matrix_1.get_index_matrix(i, j), 1e-6);
        }
    }
    MyMatrix test_matrix_6(std::move(test_matrix_1));
    index_array = 0;
    for (int i = 0; i < test_matrix_6.get_rows(); i++) {
        for (int j = 0; j < test_matrix_6.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_6.get_index_matrix(i, j),
                        input_array_1[index_array], 1e-6);
            index_array++;
        }
    }
}

TEST(MyMatrix, test_arithmetic) {
    MyMatrix test_matrix_7;
    MyMatrix test_matrix_8;
    MyMatrix test_matrix_9(5, 5);
    MyMatrix test_matrix_10(5, 5);
    int index_array = 0;
    double tmp_number = 5.545;
    double input_array_1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double input_array_2[25] = {7, 2, 5, 14, 52, 16, 27, 38, 9,
                                7, 2, 5, 14, 52, 16, 27, 38, 9,
                                7, 2, 5, 14, 52, 16, 27};
    double input_array_3[9] = {1 * 2, 2 * 2, 3 * 2, 4 * 2, 5 * 2,
                               6 * 2, 7 * 2, 8 * 2, 9 * 2};
    double input_array_4[25] = {
        7 * 2, 2 * 2, 5 * 2, 14 * 2, 52 * 2, 16 * 2, 27 * 2, 38 * 2, 9 * 2,
        7 * 2, 2 * 2, 5 * 2, 14 * 2, 52 * 2, 16 * 2, 27 * 2, 38 * 2, 9 * 2,
        7 * 2, 2 * 2, 5 * 2, 14 * 2, 52 * 2, 16 * 2, 27 * 2};
    double input_array_5[9] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
    double input_array_6[9] = {
        30 * tmp_number,  36 * tmp_number,  42 * tmp_number,
        66 * tmp_number,  81 * tmp_number,  96 * tmp_number,
        102 * tmp_number, 126 * tmp_number, 150 * tmp_number};

    for (int i = 0; i < test_matrix_7.get_rows(); i++) {
        for (int j = 0; j < test_matrix_7.get_cols(); j++) {
            test_matrix_7.set_index_matrix(input_array_1[index_array], i, j);
            test_matrix_8.set_index_matrix(input_array_1[index_array], i, j);
            index_array++;
        }
    }
    index_array = 0;
    for (int i = 0; i < test_matrix_9.get_rows(); i++) {
        for (int j = 0; j < test_matrix_9.get_cols(); j++) {
            test_matrix_9.set_index_matrix(input_array_2[index_array], i, j);
            test_matrix_10.set_index_matrix(input_array_2[index_array], i, j);
            index_array++;
        }
    }
    bool tmp_value_equal = test_matrix_7.eq_matrix(test_matrix_8);
    ASSERT_NEAR(tmp_value_equal, true, 1e-6);
    test_matrix_7.sum_matrix(test_matrix_8);
    test_matrix_9.sum_matrix(test_matrix_10);
    index_array = 0;
    for (int i = 0; i < test_matrix_7.get_rows(); i++) {
        for (int j = 0; j < test_matrix_7.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_7.get_index_matrix(i, j),
                        input_array_3[index_array], 1e-6);
            index_array++;
        }
    }
    tmp_value_equal = test_matrix_7.eq_matrix(test_matrix_8);
    ASSERT_NEAR(tmp_value_equal, false, 1e-6);
    index_array = 0;
    for (int i = 0; i < test_matrix_9.get_rows(); i++) {
        for (int j = 0; j < test_matrix_9.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_9.get_index_matrix(i, j),
                        input_array_4[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_7.sub_matrix(test_matrix_8);
    test_matrix_9.sub_matrix(test_matrix_10);
    index_array = 0;
    for (int i = 0; i < test_matrix_7.get_rows(); i++) {
        for (int j = 0; j < test_matrix_7.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_7.get_index_matrix(i, j),
                        input_array_1[index_array], 1e-6);
            index_array++;
        }
    }
    index_array = 0;
    for (int i = 0; i < test_matrix_9.get_rows(); i++) {
        for (int j = 0; j < test_matrix_9.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_9.get_index_matrix(i, j),
                        input_array_2[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_7.mul_matrix(test_matrix_8);
    index_array = 0;
    for (int i = 0; i < test_matrix_7.get_rows(); i++) {
        for (int j = 0; j < test_matrix_7.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_7.get_index_matrix(i, j),
                        input_array_5[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_7.mul_number(tmp_number);
    index_array = 0;
    for (int i = 0; i < test_matrix_7.get_rows(); i++) {
        for (int j = 0; j < test_matrix_7.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_7.get_index_matrix(i, j),
                        input_array_6[index_array], 1e-6);
            index_array++;
        }
    }
}

TEST(MyMatrix, test_convert) {
    MyMatrix test_matrix_11;
    MyMatrix test_matrix_12(5, 5);
    MyMatrix test_matrix_13;
    MyMatrix test_matrix_14(5, 5);
    int index_array = 0;
    double input_array_1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double input_array_2[25] = {7, 2, 5, 14, 52, 16, 27, 38, 9,
                                7, 2, 5, 14, 52, 16, 27, 38, 9,
                                7, 2, 5, 14, 52, 16, 27};
    double input_array_3[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
    double input_array_4[25] = {7, 16, 2,  27, 5,  2, 27, 5,  38, 14, 5, 38, 14,
                                9, 52, 14, 9,  52, 7, 16, 52, 7,  16, 2, 27};
    double input_array_5[9] = {-3, 6, -3, 6, -12, 6, -3, 6, -3};
    double input_array_6[25] = {932475,   -685550,  93282,   4861,    255,
                                4147743,  -3101696, 677659,  121470,  -536917,
                                165961,   -141435,  9427,    130674,  -52989,
                                -1977923, 1639808,  -364621, -61865,  254905,
                                -2823053, 2086808,  -333921, -113708, 362486};
    double input_array_7[9] = {14, 55, 72, 26, 8, 39, 31, 42, 10};
    double input_array_8[25] = {93, 47, 61, 23, 5,  50, 16, 35, 80,
                                68, 32, 75, 27, 21, 32, 41, 47, 67,
                                15, 38, 55, 61, 28, 45, 62};
    double input_array_9[9] = {-0.0170925, 0.0271418,  0.0172132,
                               0.0104113,  -0.0229509, 0.0145473,
                               0.00925936, 0.0122544,  -0.0144595};
    double input_array_10[25] = {
        0.0114275,    -0.0116291,   -0.0231893, -0.0066292,  0.0278646,
        -0.000563547, -0.000122754, 0.0246006,  -0.00551914, -0.00913428,
        -0.000799283, 0.00861706,   0.00675167, 0.0185651,   -0.0242498,
        0.00302507,   0.0273041,    0.0321065,  -0.0139997,  -0.038181,
        -0.0114175,   -0.0132722,   -0.0299849, 0.0130877,   0.0390609};
    for (int i = 0; i < test_matrix_11.get_rows(); i++) {
        for (int j = 0; j < test_matrix_11.get_cols(); j++) {
            test_matrix_11.set_index_matrix(input_array_1[index_array], i, j);
            index_array++;
        }
    }
    index_array = 0;
    for (int i = 0; i < test_matrix_12.get_rows(); i++) {
        for (int j = 0; j < test_matrix_12.get_cols(); j++) {
            test_matrix_12.set_index_matrix(input_array_2[index_array], i, j);
            index_array++;
        }
    }
    test_matrix_13 = test_matrix_11.transpose();
    index_array = 0;
    for (int i = 0; i < test_matrix_13.get_rows(); i++) {
        for (int j = 0; j < test_matrix_13.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_13.get_index_matrix(i, j),
                        input_array_3[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_14 = test_matrix_12.transpose();
    index_array = 0;
    for (int i = 0; i < test_matrix_14.get_rows(); i++) {
        for (int j = 0; j < test_matrix_14.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_14.get_index_matrix(i, j),
                        input_array_4[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_13 = test_matrix_11.calc_complements();
    index_array = 0;
    for (int i = 0; i < test_matrix_13.get_rows(); i++) {
        for (int j = 0; j < test_matrix_13.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_13.get_index_matrix(i, j),
                        input_array_5[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_14 = test_matrix_12.calc_complements();
    index_array = 0;
    for (int i = 0; i < test_matrix_14.get_rows(); i++) {
        for (int j = 0; j < test_matrix_14.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_14.get_index_matrix(i, j),
                        input_array_6[index_array], 1e-6);
            index_array++;
        }
    }
    index_array = 0;
    for (int i = 0; i < test_matrix_11.get_rows(); i++) {
        for (int j = 0; j < test_matrix_11.get_cols(); j++) {
            test_matrix_11.set_index_matrix(input_array_7[index_array], i, j);
            index_array++;
        }
    }
    index_array = 0;
    for (int i = 0; i < test_matrix_12.get_rows(); i++) {
        for (int j = 0; j < test_matrix_12.get_cols(); j++) {
            test_matrix_12.set_index_matrix(input_array_8[index_array], i, j);
            index_array++;
        }
    }
    ASSERT_NEAR(test_matrix_11.determinant(), 91151, 1e-6);
    ASSERT_NEAR(test_matrix_12.determinant(), 365747812, 1e-6);
    test_matrix_13 = test_matrix_11.inverse_matrix();
    index_array = 0;
    for (int i = 0; i < test_matrix_13.get_rows(); i++) {
        for (int j = 0; j < test_matrix_13.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_13.get_index_matrix(i, j),
                        input_array_9[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_14 = test_matrix_12.inverse_matrix();
    index_array = 0;
    for (int i = 0; i < test_matrix_14.get_rows(); i++) {
        for (int j = 0; j < test_matrix_14.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_14.get_index_matrix(i, j),
                        input_array_10[index_array], 1e-6);
            index_array++;
        }
    }
}

TEST(MyMatrix, test_overload) {
    MyMatrix test_matrix_15;
    MyMatrix test_matrix_16;
    int index_array = 0;
    double tmp_number = 5.545;
    double input_array_1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double input_array_3[9] = {1 * 2, 2 * 2, 3 * 2, 4 * 2, 5 * 2,
                               6 * 2, 7 * 2, 8 * 2, 9 * 2};
    double input_array_4[9] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
    double input_array_5[9] = {
        30 * tmp_number,  36 * tmp_number,  42 * tmp_number,
        66 * tmp_number,  81 * tmp_number,  96 * tmp_number,
        102 * tmp_number, 126 * tmp_number, 150 * tmp_number};
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            test_matrix_15.set_index_matrix(input_array_1[index_array], i, j);
            test_matrix_16.set_index_matrix(input_array_1[index_array], i, j);
            index_array++;
        }
    }
    test_matrix_15.operator+(test_matrix_16);
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        input_array_3[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_15.operator-(test_matrix_16);
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        input_array_1[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_15.operator+=(test_matrix_16);
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        input_array_3[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_15.operator-=(test_matrix_16);
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        input_array_1[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_15.operator*(test_matrix_16);
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        input_array_4[index_array], 1e-6);
            index_array++;
        }
    }
    test_matrix_15.operator*(tmp_number);
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        input_array_5[index_array], 1e-6);
            index_array++;
        }
    }
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            test_matrix_15.set_index_matrix(input_array_1[index_array], i, j);
            index_array++;
        }
    }
    test_matrix_15.operator*=(test_matrix_16);
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        input_array_4[index_array], 1e-6);
            index_array++;
        }
    }
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            test_matrix_15.set_index_matrix(input_array_4[index_array], i, j);
            index_array++;
        }
    }
    test_matrix_15.operator*=(tmp_number);
    index_array = 0;
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        input_array_5[index_array], 1e-6);
            index_array++;
        }
    }
    tmp_number = test_matrix_15.operator()(0, 0);
    ASSERT_NEAR(tmp_number, input_array_5[0], 1e-6);
    bool tmp_number_equal = test_matrix_15.operator==(test_matrix_16);
    ASSERT_NEAR(tmp_number_equal, false, 1e-6);
    test_matrix_15.operator=(test_matrix_16);
    for (int i = 0; i < test_matrix_15.get_rows(); i++) {
        for (int j = 0; j < test_matrix_15.get_cols(); j++) {
            ASSERT_NEAR(test_matrix_15.get_index_matrix(i, j),
                        test_matrix_16.get_index_matrix(i, j), 1e-6);
        }
    }
    tmp_number_equal = test_matrix_15.operator==(test_matrix_16);
    ASSERT_NEAR(tmp_number_equal, true, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
