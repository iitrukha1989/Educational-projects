#include "model_calc.h"

namespace My {
Calculation::Calculation()
    : input_data_(""), check_data_(""), error_value_(""), data_(0) {}
Calculation::~Calculation() {}
double Calculation::GetData() { return data_; }
std::string Calculation::GetError() { return error_value_; }

void Calculation::Clear() {
    data_ = 0;
    input_data_ = "";
    error_value_ = "";
    check_data_ = "";
    while (stack_value_.empty() == false) {
        stack_value_.pop();
    }
    while (rpn_stack_value_.empty() == false) {
        rpn_stack_value_.pop();
    }
    while (sup_stack_value_.empty() == false) {
        sup_stack_value_.pop();
    }
}

void Calculation::Calculate(const std::string& input_data_) {
    check_input(input_data_);
    if (error_value_.empty() == true) {
        parsing();
        reverse_stack();
        rpn();
        calculate();
    }
}

void Calculation::check_input(std::string input_data_) {
    size_t limit_value = input_data_.size();
    int check_bracket = 0;
    for (size_t i = 0; i < limit_value; i++) {
        if (input_data_[i] == '(' &&
            ((i + 1) == limit_value - 1 || input_data_[i + 1] == ')')) {
            error_value_ = "Incorrect_input";
        }
        if (input_data_[i] == ')' && check_bracket == 0) {
            error_value_ = "Incorrect_input";
        }
        if (input_data_[i] == '(') {
            check_bracket++;
        }
        if (input_data_[i] == ')' && check_bracket != 0) {
            check_bracket--;
        }
        if ((input_data_[i] == '+' || input_data_[i] == '-' ||
             input_data_[i] == '*' || input_data_[i] == '/' ||
             input_data_[i] == '^' || input_data_[i] == '.' ||
             input_data_[i] == '%') &&
            i != limit_value - 1) {
            if (input_data_[i + 1] == '+' || input_data_[i + 1] == '-' ||
                input_data_[i + 1] == '*' || input_data_[i + 1] == '/' ||
                input_data_[i + 1] == '^' || input_data_[i + 1] == '.' ||
                input_data_[i + 1] == '%') {
                error_value_ = "Incorrect_input";
            }
        }
        if ((input_data_[i] == 'S' || input_data_[i] == 'C' ||
             input_data_[i] == 'T' || input_data_[i] == '@' ||
             input_data_[i] == '#' || input_data_[i] == '$' ||
             input_data_[i] == '&' || input_data_[i] == 'L' ||
             input_data_[i] == 'N') &&
            i + 1 != limit_value - 1 && input_data_[i + 1] != '(') {
            error_value_ = "Incorrect_input";
        }
    }
    if (input_data_[0] == '-' || input_data_[0] == '+' ||
        input_data_[0] == '*' || input_data_[0] == '/') {
        input_data_.push_back(input_data_[limit_value - 1]);
        for (size_t i = limit_value; i > 0; i--) {
            input_data_[i] = input_data_[i - 1];
        }
        input_data_[0] = 48;
        limit_value++;
    }
    if (input_data_[limit_value - 1] == '-' ||
        input_data_[limit_value - 1] == '+' ||
        input_data_[limit_value - 1] == '*' ||
        input_data_[limit_value - 1] == '/') {
        input_data_.push_back('0');
        limit_value++;
    }
    for (size_t i = 0; i < limit_value; i++) {
        if (input_data_[i] == '(' && (i + 1) != limit_value &&
            (input_data_[i + 1] == '-' || input_data_[i + 1] == '+')) {
            input_data_.push_back(input_data_[limit_value - 1]);
            for (size_t j = limit_value; j > i; j--) {
                input_data_[j] = input_data_[j - 1];
            }
            input_data_[i + 1] = '0';
            limit_value++;
        }
    }
    if (check_bracket != 0) {
        error_value_ = "Incorrect_input";
    }
    check_data_ = input_data_;
}

void Calculation::parsing() {
    size_t limit_value = check_data_.size();
    int index = 0;
    double value = 0;
    char value_number[255] = "";
    for (size_t i = 0; i < limit_value; i++) {
        if (check_data_[i] == '.') {
            value_number[index] = '.';
            index++;
        }
        if (check_data_[i] >= 48 && check_data_[i] <= 57) {
            value_number[index] = check_data_[i];
            index++;
        }
        if (((check_data_[i] < 48 || check_data_[i] > 57) && index != 0 &&
             check_data_[i] != '.')) {
            value = atof(value_number);
            sup_stack_value_.push(
                std::make_pair(value, std::make_pair(NUMBER, NUMBER_X)));
            index = 0;
            for (size_t j = 0; j < 255; j++) {
                value_number[j] = 0;
            }
        }
        if (check_data_[i] == '+') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(SUM, SUM_SUB)));
        }
        if (check_data_[i] == '-') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(SUB, SUM_SUB)));
        }
        if (check_data_[i] == '*') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(MUL, MUL_DIV_MOD)));
        }
        if (check_data_[i] == '/') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(DIV, MUL_DIV_MOD)));
        }
        if (check_data_[i] == '%') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(MOD, MUL_DIV_MOD)));
        }
        if (check_data_[i] == '(') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(BRACKET_LEFT, NUMBER_X)));
        }
        if (check_data_[i] == ')') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(BRACKET_RIGHT, NUMBER_X)));
        }
        if (check_data_[i] == 'S') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(SIN, FUNCTION)));
        }
        if (check_data_[i] == 'C') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(COS, FUNCTION)));
        }
        if (check_data_[i] == 'T') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(TAN, FUNCTION)));
        }
        if (check_data_[i] == '@') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(ASIN, FUNCTION)));
        }
        if (check_data_[i] == '#') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(ACOS, FUNCTION)));
        }
        if (check_data_[i] == '$') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(ATAN, FUNCTION)));
        }
        if (check_data_[i] == '&') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(SQRT, FUNCTION)));
        }
        if (check_data_[i] == 'L') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(LOG, FUNCTION)));
        }
        if (check_data_[i] == 'N') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(LN, FUNCTION)));
        }
        if (check_data_[i] == '^') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(DEGR, DEGREE)));
        }
        if (check_data_[i] == 'X') {
            sup_stack_value_.push(
                std::make_pair(0, std::make_pair(ARGUMENT_X, NUMBER_X)));
        }
    }
    if (index != 0) {
        value = atof(value_number);
        sup_stack_value_.push(
            std::make_pair(value, std::make_pair(NUMBER, NUMBER_X)));
        for (size_t j = 0; j < 255; j++) {
            value_number[j] = 0;
        }
    }
}

void Calculation::rpn() {
    double data_value_1 = 0, data_value_2 = 0;
    My::Calculation::Operator operator_value_1, operator_value_2;
    My::Calculation::Priority priority_value_1, priority_value_2;
    while (stack_value_.empty() == false) {
        top_stack(1, &data_value_1, &operator_value_1, &priority_value_1);
        if (operator_value_1 == 0 && priority_value_1 == 0) {
            rpn_stack_value_.push(std::make_pair(
                data_value_1,
                std::make_pair(operator_value_1, priority_value_1)));
        }
        if (operator_value_1 == 7) {
            sup_stack_value_.push(std::make_pair(
                data_value_1,
                std::make_pair(operator_value_1, priority_value_1)));
        }
        if (operator_value_1 == 8) {
            top_stack(2, &data_value_1, &operator_value_1, &priority_value_1);
            while (operator_value_1 != 7) {
                rpn_stack_value_.push(std::make_pair(
                    data_value_1,
                    std::make_pair(operator_value_1, priority_value_1)));
                top_stack(2, &data_value_1, &operator_value_1,
                          &priority_value_1);
            }
        }
        if (operator_value_1 != 0 && operator_value_1 != 7 &&
            operator_value_1 != 8) {
            if (sup_stack_value_.empty() == false) {
                top_stack(2, &data_value_2, &operator_value_2,
                          &priority_value_2);
                if (priority_value_1 > priority_value_2) {
                    sup_stack_value_.push(std::make_pair(
                        data_value_2,
                        std::make_pair(operator_value_2, priority_value_2)));
                    sup_stack_value_.push(std::make_pair(
                        data_value_1,
                        std::make_pair(operator_value_1, priority_value_1)));
                } else if (priority_value_1 == priority_value_2) {
                    rpn_stack_value_.push(std::make_pair(
                        data_value_2,
                        std::make_pair(operator_value_2, priority_value_2)));
                    sup_stack_value_.push(std::make_pair(
                        data_value_1,
                        std::make_pair(operator_value_1, priority_value_1)));
                } else {
                    rpn_stack_value_.push(std::make_pair(
                        data_value_2,
                        std::make_pair(operator_value_2, priority_value_2)));
                    if (sup_stack_value_.empty() == false) {
                        top_stack(2, &data_value_2, &operator_value_2,
                                  &priority_value_2);
                        while (priority_value_1 <= priority_value_2) {
                            rpn_stack_value_.push(std::make_pair(
                                data_value_2,
                                std::make_pair(operator_value_2,
                                               priority_value_2)));
                            if (sup_stack_value_.empty() == false) {
                                top_stack(2, &data_value_2, &operator_value_2,
                                          &priority_value_2);
                            } else {
                                break;
                            }
                        }
                    }
                    sup_stack_value_.push(std::make_pair(
                        data_value_1,
                        std::make_pair(operator_value_1, priority_value_1)));
                }
            } else {
                sup_stack_value_.push(std::make_pair(
                    data_value_1,
                    std::make_pair(operator_value_1, priority_value_1)));
            }
        }
    }
    while (sup_stack_value_.empty() == false) {
        top_stack(2, &data_value_1, &operator_value_1, &priority_value_1);
        rpn_stack_value_.push(std::make_pair(
            data_value_1, std::make_pair(operator_value_1, priority_value_1)));
    }
}

void Calculation::reverse_stack() {
    double data_value;
    My::Calculation::Operator operator_value;
    My::Calculation::Priority priority_value;
    while (sup_stack_value_.empty() == false) {
        data_value = sup_stack_value_.top().first;
        operator_value = sup_stack_value_.top().second.first;
        priority_value = sup_stack_value_.top().second.second;
        sup_stack_value_.pop();
        stack_value_.push(std::make_pair(
            data_value, std::make_pair(operator_value, priority_value)));
    }
}

void Calculation::calculate() {
    double data_value_1 = 0;
    double data_value_2 = 0;
    My::Calculation::Operator operator_value_1;
    My::Calculation::Operator operator_value_2;
    My::Calculation::Priority priority_value_1;
    while (rpn_stack_value_.empty() == false) {
        data_value_1 = rpn_stack_value_.top().first;
        operator_value_1 = rpn_stack_value_.top().second.first;
        priority_value_1 = rpn_stack_value_.top().second.second;
        rpn_stack_value_.pop();
        sup_stack_value_.push(std::make_pair(
            data_value_1, std::make_pair(operator_value_1, priority_value_1)));
    }
    while (sup_stack_value_.empty() == false) {
        data_value_1 = sup_stack_value_.top().first;
        operator_value_1 = sup_stack_value_.top().second.first;
        priority_value_1 = sup_stack_value_.top().second.second;
        sup_stack_value_.pop();
        if (priority_value_1 != 0 && priority_value_1 != 4) {
            operator_value_2 = operator_value_1;
            data_value_1 = stack_value_.top().first;
            stack_value_.pop();
            data_value_2 = stack_value_.top().first;
            stack_value_.pop();
            calculate_option(data_value_1, data_value_2, operator_value_2);
            stack_value_.push(
                std::make_pair(data_, std::make_pair(NUMBER, NUMBER_X)));
        } else if (priority_value_1 == 4) {
            operator_value_2 = operator_value_1;
            data_value_1 = stack_value_.top().first;
            stack_value_.pop();
            calculate_option(data_value_1, 0, operator_value_2);
            stack_value_.push(
                std::make_pair(data_, std::make_pair(NUMBER, NUMBER_X)));
        } else {
            stack_value_.push(std::make_pair(
                data_value_1,
                std::make_pair(operator_value_1, priority_value_1)));
        }
    }
    while (stack_value_.empty() == false) {
        stack_value_.pop();
    }
    while (sup_stack_value_.empty() == false) {
        sup_stack_value_.pop();
    }
}

void Calculation::calculate_option(double data_value_2, double data_value_1,
                                   My::Calculation::Operator operator_value) {
    int tmp_operator = operator_value;
    switch (tmp_operator) {
        case 2:
            data_ = data_value_1 + data_value_2;
            break;
        case 3:
            data_ = data_value_1 - data_value_2;
            break;
        case 4:
            data_ = data_value_1 * data_value_2;
            break;
        case 5:
            data_ = data_value_1 / data_value_2;
            break;
        case 6:
            data_ = fmod(data_value_1, data_value_2);
            break;
        case 9:
            data_ = sin(data_value_1 + data_value_2);
            break;
        case 10:
            data_ = cos(data_value_1 + data_value_2);
            break;
        case 11:
            data_ = tan(data_value_1 + data_value_2);
            break;
        case 12:
            data_ = asin(data_value_1 + data_value_2);
            break;
        case 13:
            data_ = acos(data_value_1 + data_value_2);
            break;
        case 14:
            data_ = atan(data_value_1 + data_value_2);
            break;
        case 15:
            data_ = sqrt(data_value_1 + data_value_2);
            break;
        case 16:
            data_ = log10(data_value_1 + data_value_2);
            break;
        case 17:
            data_ = log(data_value_1 + data_value_2);
            break;
        case 18:
            data_ = pow(data_value_1, data_value_2);
            break;
    }
}

void My::Calculation::top_stack(int option, double* data_value,
                                My::Calculation::Operator* operator_value,
                                My::Calculation::Priority* priority_value) {
    if (option == 1) {
        *data_value = stack_value_.top().first;
        *operator_value = stack_value_.top().second.first;
        *priority_value = stack_value_.top().second.second;
        stack_value_.pop();
    } else if (option == 2) {
        *data_value = sup_stack_value_.top().first;
        *operator_value = sup_stack_value_.top().second.first;
        *priority_value = sup_stack_value_.top().second.second;
        sup_stack_value_.pop();
    }
}

}  // namespace My
