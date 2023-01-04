#include "credit_calculate.h"

#include "ui_credit_calculate.h"

Credit_calculate::Credit_calculate(QWidget *parent)
    : QDialog(parent), ui(new Ui::Credit_calculate) {
    ui->setupUi(this);
}

Credit_calculate::~Credit_calculate() { delete ui; }

void Credit_calculate::on_pushButton_clicked() {
    int index = ui->type_payment->currentIndex();
    double credit_amount = ui->Credit_amount->text().toDouble();
    double credit_period = ui->Credit_period->text().toDouble();
    double interest_rate = ui->Interest_rate->text().toDouble();
    sender_ = std::make_unique<My::ControllerCredit>();
    std::tuple<double, double, double> result = sender_->PushOnButtonCalc(
        credit_amount, credit_period, interest_rate, index);
    QString str_monthly_payment;
    QString str_overpayment;
    QString str_total;
    str_monthly_payment = QString::number(std::get<1>(result), 'g', 10);
    str_overpayment = QString::number(std::get<2>(result), 'g', 10);
    str_total = QString::number(std::get<0>(result), 'g', 10);
    ui->Monthly_payment->setText(str_monthly_payment);
    ui->Overpayment_on_the_loan->setText(str_overpayment);
    ui->Total_payment->setText(str_total);
}
