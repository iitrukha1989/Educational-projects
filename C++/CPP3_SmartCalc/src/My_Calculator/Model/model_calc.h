#ifndef SRC_My_CALCULATOR_MODEL_MODEL_CALC_H_
#define SRC_My_CALCULATOR_MODEL_MODEL_CALC_H_

//*  PROJECT: My_SMARTCALC_v2.0
//*  Developer: aedie

#include <cmath>
#include <iostream>
#include <stack>
#include <string>

namespace My {
class Calculation {
   public:
    Calculation();
    ~Calculation();
    void Calculate(const std::string& input_data_);
    double GetData();
    std::string GetError();
    void Clear();

   private:
    enum Operator {
        NUMBER = 0,
        ARGUMENT_X = 1,  // X
        SUM = 2,
        SUB = 3,
        MUL = 4,
        DIV = 5,
        MOD = 6,  // %
        BRACKET_LEFT = 7,
        BRACKET_RIGHT = 8,
        SIN = 9,    // S
        COS = 10,   // C
        TAN = 11,   // T
        ASIN = 12,  // @
        ACOS = 13,  // #
        ATAN = 14,  // $
        SQRT = 15,  // &
        LOG = 16,   // L
        LN = 17,    // N
        DEGR = 18
    };

    enum Priority {
        NUMBER_X = 0,
        SUM_SUB = 1,
        MUL_DIV_MOD = 2,
        DEGREE = 3,
        FUNCTION = 4
    };

    std::string input_data_;
    std::string check_data_;
    std::string error_value_;
    double data_;
    std::stack<std::pair<double, std::pair<My::Calculation::Operator,
                                           My::Calculation::Priority>>>
        stack_value_;
    std::stack<std::pair<double, std::pair<My::Calculation::Operator,
                                           My::Calculation::Priority>>>
        rpn_stack_value_;
    std::stack<std::pair<double, std::pair<My::Calculation::Operator,
                                           My::Calculation::Priority>>>
        sup_stack_value_;
    void check_input(std::string input_data_);
    void parsing();
    void rpn();
    void reverse_stack();
    void calculate();
    void calculate_option(double data_value_2, double data_value_1,
                          My::Calculation::Operator operator_value);
    void top_stack(int option, double* data_value,
                   My::Calculation::Operator* operator_value,
                   My::Calculation::Priority* priority_value);
};
}  // namespace My

#endif  // SRC_My_CALCULATOR_MODEL_MODEL_CALC_H_
