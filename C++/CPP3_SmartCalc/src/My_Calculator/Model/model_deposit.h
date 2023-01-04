#ifndef SRC_My_CALCULATOR_MODEL_MODEL_DEPOSIT_H_
#define SRC_My_CALCULATOR_MODEL_MODEL_DEPOSIT_H_

#include <cmath>

namespace My {
class CalculatorDeposit {
   public:
    CalculatorDeposit();
    ~CalculatorDeposit();
    void CalculateDeposit(int type_deposit, int supplement, int remove,
                          double deposit_amount, double deposit_period,
                          double interest_rate, double tax_interest_rate,
                          double supplement_amount, double remove_amount);
    double GetAccuredInterest();
    double GetTaxAmount();
    double GetDepositAmount();

   private:
    double accured_interest_;
    double tax_amount_;
    double total_deposit_amount_;
};
}  // namespace My

#endif  // SRC_My_CALCULATOR_MODEL_MODEL_DEPOSIT_H_
