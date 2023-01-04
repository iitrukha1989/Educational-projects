#ifndef SRC_s21_CALCULATOR_VIEW_DIALOG_H_
#define SRC_s21_CALCULATOR_VIEW_DIALOG_H_

#include <QDialog>
#include <cstdlib>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT

   public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    double Begin_point();

   private slots:
    void on_pushButton_build_clicked();

   private:
    Ui::Dialog *ui;
    QVector<double> x, y;
};

#endif  // SRC_s21_CALCULATOR_VIEW_DIALOG_H_
