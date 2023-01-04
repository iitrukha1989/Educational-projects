#ifndef SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_CREDIT_H_
#define SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_CREDIT_H_

#include <string>

#include "../Model/model_credit.h"

namespace My {
class ControllerCredit {
   private:
    std::unique_ptr<CalculatorCredit> model_;

   public:
    ControllerCredit();
    ~ControllerCredit() {}
    std::tuple<double, double, double> PushOnButtonCalc(double credit_amount,
                                                        double credit_period,
                                                        double interest_rate,
                                                        int index);
};
}  // namespace My

#endif  // SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_CREDIT_H_
