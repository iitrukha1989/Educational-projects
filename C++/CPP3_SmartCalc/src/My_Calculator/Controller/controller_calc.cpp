#include "controller_calc.h"

namespace My {
Controller::Controller() : model_(std::make_unique<Calculation>()) {}

std::pair<double, std::string> Controller::PushOnButtonEqual(
    std::string input_data_) {
    model_->Calculate(input_data_);
    return std::make_pair(model_->GetData(), model_->GetError());
}
}  // namespace My
