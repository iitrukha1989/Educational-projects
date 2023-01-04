#ifndef SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_DEPOSIT_H_
#define SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_DEPOSIT_H_

#include <string>

#include "../Model/model_deposit.h"

namespace My {
class ControllerDeposit {
   private:
    std::unique_ptr<CalculatorDeposit> model_;

   public:
    ControllerDeposit();
    ~ControllerDeposit() {}
    std::tuple<double, double, double> PushOnButtonCalc(
        int type_deposit, int supplement, int remove, double deposit_amount,
        double deposit_period, double interest_rate, double tax_interest_rate,
        double supplement_amount, double remove_amount);
};
}  // namespace My

#endif  // SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_DEPOSIT_H_
