#include "deposit_calculate.h"

#include <iostream>

#include "ui_deposit_calculate.h"

Deposit_calculate::Deposit_calculate(QWidget *parent)
    : QDialog(parent), ui(new Ui::Deposit_calculate) {
    ui->setupUi(this);
    ui->supplement_amount->setText(0);
    ui->remove_amount->setText(0);
}

Deposit_calculate::~Deposit_calculate() { delete ui; }

void Deposit_calculate::on_pushButton_clicked() {
    int type_deposit = ui->type_deposit->currentIndex();
    int supplement = ui->supplement->currentIndex();
    int remove = ui->remove->currentIndex();
    double deposit_amount = ui->deposit_amount->text().toDouble();
    double deposit_period = ui->deposit_period->text().toDouble();
    double interest_rate = ui->interest_rate->text().toDouble();
    double tax_interest_rate = ui->tax_interest_rate->text().toDouble();
    double supplement_amount = ui->supplement_amount->text().toDouble();
    double remove_amount = ui->remove_amount->text().toDouble();
    sender_ = std::make_unique<My::ControllerDeposit>();
    std::tuple<double, double, double> result = sender_->PushOnButtonCalc(
        type_deposit, supplement, remove, deposit_amount, deposit_period,
        interest_rate, tax_interest_rate, supplement_amount, remove_amount);
    QString str_accured_interest;
    QString str_tax_amount;
    QString str_deposit_amount;
    str_accured_interest = QString::number(std::get<2>(result), 'g', 10);
    str_tax_amount = QString::number(std::get<1>(result), 'g', 10);
    str_deposit_amount = QString::number(std::get<0>(result), 'g', 10);
    ui->res_accrued_interest->setText(str_accured_interest);
    ui->res_tax_amount->setText(str_tax_amount);
    ui->res_deposit_amount->setText(str_deposit_amount);
}
