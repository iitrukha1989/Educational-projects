#ifndef SRC_My_CALCULATOR_VIEW_CREDIT_CALCULATE_H_
#define SRC_My_CALCULATOR_VIEW_CREDIT_CALCULATE_H_

#include <QDialog>

#include "../Controller/controller_credit.h"

namespace Ui {
class Credit_calculate;
}

class Credit_calculate : public QDialog {
    Q_OBJECT

   public:
    explicit Credit_calculate(QWidget *parent = nullptr);
    ~Credit_calculate();

   private slots:
    void on_pushButton_clicked();

   private:
    Ui::Credit_calculate *ui;
    std::unique_ptr<My::ControllerCredit> sender_;
};

#endif  // SRC_My_CALCULATOR_VIEW_CREDIT_CALCULATE_H_
