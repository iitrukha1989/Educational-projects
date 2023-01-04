#ifndef SRC_My_CALCULATOR_VIEW_MAINWINDOW_H_
#define SRC_My_CALCULATOR_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QVector>
#include <cmath>
#include <cstdlib>
#include <string>

#include "../Controller/controller_calc.h"
#include "credit_calculate.h"
#include "deposit_calculate.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString tmp_value();
    QString tmp_result();

   private:
    Ui::MainWindow *ui;
    Dialog *new_window;
    Credit_calculate *new_credit_calculate;
    Deposit_calculate *new_deposit_calculate;
    std::unique_ptr<My::Controller> sender_;

   private slots:
    void read_button();
    void on_pushButton_ac_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_credit_clicked();
    void on_pushButton_deposit_clicked();
};
#endif  // SRC_My_CALCULATOR_VIEW_MAINWINDOW_H_
