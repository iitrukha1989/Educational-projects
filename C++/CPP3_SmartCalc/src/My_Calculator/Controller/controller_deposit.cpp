#include "controller_deposit.h"

namespace My {
ControllerDeposit::ControllerDeposit()
    : model_(std::make_unique<CalculatorDeposit>()) {}
std::tuple<double, double, double> ControllerDeposit::PushOnButtonCalc(
    int type_deposit, int supplement, int remove, double deposit_amount,
    double deposit_period, double interest_rate, double tax_interest_rate,
    double supplement_amount, double remove_amount) {
    model_->CalculateDeposit(type_deposit, supplement, remove, deposit_amount,
                             deposit_period, interest_rate, tax_interest_rate,
                             supplement_amount, remove_amount);
    return std::make_tuple(model_->GetDepositAmount(), model_->GetTaxAmount(),
                           model_->GetAccuredInterest());
}
}  // namespace My
