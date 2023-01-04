#ifndef SRC_My_CALCULATOR_VIEW_DEPOSIT_CALCULATE_H_
#define SRC_My_CALCULATOR_VIEW_DEPOSIT_CALCULATE_H_

#include <QDialog>
#include <iostream>

#include "../Controller/controller_deposit.h"

namespace Ui {
class Deposit_calculate;
}

class Deposit_calculate : public QDialog {
    Q_OBJECT

   public:
    explicit Deposit_calculate(QWidget *parent = nullptr);
    ~Deposit_calculate();

   private slots:
    void on_pushButton_clicked();

   private:
    Ui::Deposit_calculate *ui;
    std::unique_ptr<My::ControllerDeposit> sender_;
};

#endif  // SRC_My_CALCULATOR_VIEW_DEPOSIT_CALCULATE_H_
