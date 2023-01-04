#include "model_credit.h"

namespace My {
CalculatorCredit::CalculatorCredit()
    : total_payment_(0), monthly_payment_(0), over_payment_(0) {}
CalculatorCredit::~CalculatorCredit() {}

void CalculatorCredit::CalculateCredit(double credit_amount,
                                       double credit_period,
                                       double interest_rate, int index) {
    if (index == 0) {
        monthly_payment_ = credit_amount * (interest_rate / (100 * 12)) /
                           (1 - pow((1 + (interest_rate / (100 * 12))),
                                    (credit_period * 12 * -1)));
        over_payment_ = monthly_payment_ * credit_period * 12 - credit_amount;
        total_payment_ = credit_amount + over_payment_;
    } else {
        monthly_payment_ = (credit_amount / (credit_period * 12)) +
                           credit_amount * (interest_rate / 100) / 12;
        for (int i = 0; i < (credit_period * 12); i++) {
            total_payment_ +=
                (credit_amount / (credit_period * 12)) +
                (credit_amount - ((credit_amount / (credit_period * 12))) * i) *
                    (interest_rate / 100) / 12;
        }
        over_payment_ = total_payment_ - credit_amount;
    }
}

double CalculatorCredit::GetTotalAmount() { return total_payment_; }
double CalculatorCredit::GetMonthlyPayment() { return monthly_payment_; }
double CalculatorCredit::GetOverPayment() { return over_payment_; }

}  // namespace My
