#ifndef SRC_My_CALCULATOR_MODEL_MODEL_CREDIT_H_
#define SRC_My_CALCULATOR_MODEL_MODEL_CREDIT_H_

#include <cmath>

namespace My {
class CalculatorCredit {
   public:
    CalculatorCredit();
    ~CalculatorCredit();
    void CalculateCredit(double credit_amount, double credit_period,
                         double interest_rate, int index);
    double GetTotalAmount();
    double GetMonthlyPayment();
    double GetOverPayment();

   private:
    double total_payment_;
    double monthly_payment_;
    double over_payment_;
};
}  // namespace My

#endif  // SRC_My_CALCULATOR_MODEL_MODEL_CREDIT_H_
