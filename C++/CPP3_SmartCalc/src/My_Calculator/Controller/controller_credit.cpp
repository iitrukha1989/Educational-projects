#include "controller_credit.h"

namespace My {
ControllerCredit::ControllerCredit()
    : model_(std::make_unique<CalculatorCredit>()) {}
std::tuple<double, double, double> ControllerCredit::PushOnButtonCalc(
    double credit_amount, double credit_period, double interest_rate,
    int index) {
    model_->CalculateCredit(credit_amount, credit_period, interest_rate, index);
    return std::make_tuple(model_->GetTotalAmount(),
                           model_->GetMonthlyPayment(),
                           model_->GetOverPayment());
}
}  // namespace My
