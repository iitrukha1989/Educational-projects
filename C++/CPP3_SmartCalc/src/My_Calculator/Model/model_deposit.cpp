#include "model_deposit.h"

namespace My {
CalculatorDeposit::CalculatorDeposit()
    : accured_interest_(0), tax_amount_(0), total_deposit_amount_(0) {}
CalculatorDeposit::~CalculatorDeposit() {}
void CalculatorDeposit::CalculateDeposit(
    int type_deposit, int supplement, int remove, double deposit_amount,
    double deposit_period, double interest_rate, double tax_interest_rate,
    double supplement_amount, double remove_amount) {
    if (type_deposit == 0) {
        if (supplement == 0 && remove == 0) {
            accured_interest_ = deposit_amount * interest_rate *
                                (365 * deposit_period) / 365 / 100;
        } else {
            for (int i = 0; i < (deposit_period * 12); i++) {
                accured_interest_ +=
                    deposit_amount * interest_rate * 30 / 365 / 100;
                if (supplement == 1) {
                    deposit_amount += supplement_amount;
                }
                if (remove == 1) {
                    deposit_amount -= remove_amount;
                }
            }
        }
        total_deposit_amount_ = deposit_amount + accured_interest_;
    } else {
        if (supplement == 0 && remove == 0) {
            accured_interest_ =
                deposit_amount * pow((1 + interest_rate * 30 / 365 / 100),
                                     (deposit_period * 12)) -
                deposit_amount;
            total_deposit_amount_ = deposit_amount + accured_interest_;
        } else {
            for (int i = 0; i < (deposit_period * 12); i++) {
                accured_interest_ +=
                    deposit_amount * interest_rate * 30 / 365 / 100;
                if (supplement == 1) {
                    deposit_amount += supplement_amount;
                }
                if (remove == 1) {
                    deposit_amount -= remove_amount;
                }
                deposit_amount += accured_interest_;
            }
            total_deposit_amount_ = deposit_amount;
        }
    }
    if (accured_interest_ > 42500) {
        tax_amount_ = (accured_interest_ - 42500) * tax_interest_rate / 100;
        accured_interest_ -= tax_amount_;
        total_deposit_amount_ -= tax_amount_;
    } else {
        tax_amount_ = 0;
    }
}

double CalculatorDeposit::GetAccuredInterest() { return accured_interest_; }
double CalculatorDeposit::GetDepositAmount() { return total_deposit_amount_; }
double CalculatorDeposit::GetTaxAmount() { return tax_amount_; }
}  // namespace My
