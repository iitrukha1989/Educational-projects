#include "dialog.h"

#include <iostream>

#include "mainwindow.h"
#include "qcustomplot.h"
#include "ui_dialog.h"

double tmp_xBegin = 0;

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);
    MainWindow tmp_window;
    QString tmp_str = tmp_window.tmp_value();
    ui->notation_show_1->setText(tmp_str);
}

Dialog::~Dialog() { delete ui; }

void Dialog::on_pushButton_build_clicked() {
    MainWindow tmp_window;
    double xBegin, xEnd, h, scope_min, scope_max;
    h = 0.1;
    xBegin = ui->Begin_point->text().toInt();
    xEnd = ui->End_point->text().toInt() + h;
    scope_min = ui->Scope_min->text().toInt();
    scope_max = ui->Scope_max->text().toInt();
    tmp_xBegin = xBegin;

    ui->widget->xAxis->setRange(-10, 10);
    ui->widget->yAxis->setRange(scope_min, scope_max);

    for (double X = xBegin; X <= xEnd; X += h) {
        x.push_back(X);
        y.push_back(tmp_window.tmp_result().toDouble());
        tmp_xBegin += h;
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}

double Dialog::Begin_point() { return tmp_xBegin; }
