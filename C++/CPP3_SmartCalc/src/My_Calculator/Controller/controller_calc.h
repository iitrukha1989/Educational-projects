#ifndef SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_CALC_H_
#define SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_CALC_H_

#include <iostream>
#include <string>

#include "../Model/model_calc.h"

namespace My {
class Controller {
   private:
    std::unique_ptr<Calculation> model_;

   public:
    Controller();
    ~Controller() {}
    std::pair<double, std::string> PushOnButtonEqual(std::string input_data_);
};
}  // namespace My

#endif  // SRC_My_CALCULATOR_CONTROLLER_CONTROLLER_CALC_H_
