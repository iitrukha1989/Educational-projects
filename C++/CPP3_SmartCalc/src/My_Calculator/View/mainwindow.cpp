#include "mainwindow.h"

#include <iostream>

#include "ui_mainwindow.h"

char input_data[1000] = "";
char formula_data[1000] = "";
char tmp_data[1000] = "";
int tmp_index = 0;
int formula_index = 0;
int check_x = 0;
double result;
double tmp_result_x;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(read_button()));
    connect(ui->pushButton_degree, SIGNAL(clicked()), this,
            SLOT(read_button()));
    connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
            SLOT(read_button()));
    connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
            SLOT(read_button()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(read_button()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::read_button() {
    QPushButton *button = (QPushButton *)sender();
    if (button->text() == "1") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '1');
        input_data[tmp_index] = '1';
        tmp_index++;
        formula_data[formula_index] = '1';
        formula_index++;
    }
    if (button->text() == "2") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '2');
        input_data[tmp_index] = '2';
        tmp_index++;
        formula_data[formula_index] = '2';
        formula_index++;
    }
    if (button->text() == "3") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '3');
        input_data[tmp_index] = '3';
        tmp_index++;
        formula_data[formula_index] = '3';
        formula_index++;
    }
    if (button->text() == "4") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '4');
        input_data[tmp_index] = '4';
        tmp_index++;
        formula_data[formula_index] = '4';
        formula_index++;
    }
    if (button->text() == "5") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '5');
        input_data[tmp_index] = '5';
        tmp_index++;
        formula_data[formula_index] = '5';
        formula_index++;
    }
    if (button->text() == "6") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '6');
        input_data[tmp_index] = '6';
        tmp_index++;
        formula_data[formula_index] = '6';
        formula_index++;
    }
    if (button->text() == "7") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '7');
        input_data[tmp_index] = '7';
        tmp_index++;
        formula_data[formula_index] = '7';
        formula_index++;
    }
    if (button->text() == "8") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '8');
        input_data[tmp_index] = '8';
        tmp_index++;
        formula_data[formula_index] = '8';
        formula_index++;
    }
    if (button->text() == "9") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '9');
        input_data[tmp_index] = '9';
        tmp_index++;
        formula_data[formula_index] = '9';
        formula_index++;
    }
    if (button->text() == "0") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '0');
        input_data[tmp_index] = '0';
        tmp_index++;
        formula_data[formula_index] = '0';
        formula_index++;
    }
    if (button->text() == ".") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '.');
        input_data[tmp_index] = '.';
        tmp_index++;
        formula_data[formula_index] = '.';
        formula_index++;
    }
    if (button->text() == "+") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '+');
        input_data[tmp_index] = '+';
        tmp_index++;
        formula_data[formula_index] = '+';
        formula_index++;
    }
    if (button->text() == "-") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '-');
        input_data[tmp_index] = '-';
        tmp_index++;
        formula_data[formula_index] = '-';
        formula_index++;
    }
    if (button->text() == "*") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '*');
        input_data[tmp_index] = '*';
        tmp_index++;
        formula_data[formula_index] = '*';
        formula_index++;
    }
    if (button->text() == "/") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + '/');
        input_data[tmp_index] = '/';
        tmp_index++;
        formula_data[formula_index] = '/';
        formula_index++;
    }
    if (button->text() == "Mod") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = '%';
        tmp_index++;
        formula_data[formula_index] = 'm';
        formula_index++;
        formula_data[formula_index] = 'o';
        formula_index++;
        formula_data[formula_index] = 'd';
        formula_index++;
    }
    if (button->text() == "Sin") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = 'S';
        tmp_index++;
        formula_data[formula_index] = 's';
        formula_index++;
        formula_data[formula_index] = 'i';
        formula_index++;
        formula_data[formula_index] = 'n';
        formula_index++;
    }
    if (button->text() == "Cos") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = 'C';
        tmp_index++;
        formula_data[formula_index] = 'c';
        formula_index++;
        formula_data[formula_index] = 'o';
        formula_index++;
        formula_data[formula_index] = 's';
        formula_index++;
    }
    if (button->text() == "Tan") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = 'T';
        tmp_index++;
        formula_data[formula_index] = 't';
        formula_index++;
        formula_data[formula_index] = 'a';
        formula_index++;
        formula_data[formula_index] = 'n';
        formula_index++;
    }
    if (button->text() == "Asin") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = '@';
        tmp_index++;
        formula_data[formula_index] = 'a';
        formula_index++;
        formula_data[formula_index] = 's';
        formula_index++;
        formula_data[formula_index] = 'i';
        formula_index++;
        formula_data[formula_index] = 'n';
        formula_index++;
    }
    if (button->text() == "Acos") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = '#';
        tmp_index++;
        formula_data[formula_index] = 'a';
        formula_index++;
        formula_data[formula_index] = 'c';
        formula_index++;
        formula_data[formula_index] = 'o';
        formula_index++;
        formula_data[formula_index] = 's';
        formula_index++;
    }
    if (button->text() == "Atan") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = '$';
        tmp_index++;
        formula_data[formula_index] = 'a';
        formula_index++;
        formula_data[formula_index] = 't';
        formula_index++;
        formula_data[formula_index] = 'a';
        formula_index++;
        formula_data[formula_index] = 'n';
        formula_index++;
    }
    if (button->text() == "Log") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = 'L';
        tmp_index++;
        formula_data[formula_index] = 'l';
        formula_index++;
        formula_data[formula_index] = 'o';
        formula_index++;
        formula_data[formula_index] = 'g';
        formula_index++;
    }
    if (button->text() == "Ln") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = 'N';
        tmp_index++;
        formula_data[formula_index] = 'l';
        formula_index++;
        formula_data[formula_index] = 'o';
        formula_index++;
        formula_data[formula_index] = 'g';
        formula_index++;
        formula_data[formula_index] = '1';
        formula_index++;
        formula_data[formula_index] = '0';
        formula_index++;
    }
    if (button->text() == "Sqrt") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = '&';
        tmp_index++;
        formula_data[formula_index] = 's';
        formula_index++;
        formula_data[formula_index] = 'q';
        formula_index++;
        formula_data[formula_index] = 'r';
        formula_index++;
        formula_data[formula_index] = 't';
        formula_index++;
    }
    if (button->text() == "^") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = '^';
        tmp_index++;
        formula_data[formula_index] = 'p';
        formula_index++;
        formula_data[formula_index] = 'o';
        formula_index++;
        formula_data[formula_index] = 'w';
        formula_index++;
    }
    if (button->text() == "(") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = '(';
        tmp_index++;
        formula_data[formula_index] = '(';
        formula_index++;
    }
    if (button->text() == ")") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = ')';
        tmp_index++;
        formula_data[formula_index] = ')';
        formula_index++;
    }
    if (button->text() == "X") {
        if (tmp_index == 0) {
            ui->notation_show->setText("");
        }
        ui->notation_show->setText(ui->notation_show->text() + button->text());
        input_data[tmp_index] = 'X';
        check_x++;
        tmp_index++;
        formula_data[formula_index] = 'X';
        formula_index++;
    }
}

void MainWindow::on_pushButton_ac_clicked() {
    ui->notation_show->setText("0");
    ui->result_show->setText("0");
    tmp_index = 0;
    formula_index = 0;
    check_x = 0;
    input_data[0] = '\0';
    memset(input_data, 0, sizeof(input_data));
    formula_data[0] = '\0';
    memset(formula_data, 0, sizeof(formula_data));
    tmp_data[0] = '\0';
    memset(tmp_data, 0, sizeof(tmp_data));
}

void MainWindow::on_pushButton_equal_clicked() {
    QString tmp_string(input_data);
    std::string input_string = tmp_string.toStdString();
    sender_ = std::make_unique<My::Controller>();
    if (check_x == 0) {
        std::pair<double, std::string> result =
            sender_->PushOnButtonEqual(input_string);
        if (result.second != "Incorrect_input") {
            QString str_result;
            str_result = QString::number(result.first, 'g', 15);
            ui->result_show->setText(str_result);
        } else {
            ui->result_show->setText("Invalid input");
        }
    } else {
        new_window = new Dialog(this);
        new_window->show();
    }
}

QString MainWindow::tmp_value() { return formula_data; }

QString MainWindow::tmp_result() {
    QString tmp_str;
    Dialog tmp_dialog;
    double xBegin = tmp_dialog.Begin_point();
    int tmp_limit = (int)strlen(input_data);
    int tmp_index = 0;
    int tmp_xBegin = 0;
    for (int i = 0; i < tmp_limit; i++) {
        if (input_data[i] == 'X') {
            if (xBegin < 0) {
                tmp_data[tmp_index] = '0';
                tmp_index++;
                tmp_data[tmp_index] = '-';
                tmp_index++;
            }
            if (xBegin != 0) {
                tmp_data[tmp_index] = abs((int)xBegin) + 48;
                tmp_xBegin = (int)((abs(xBegin) - abs((int)xBegin)) * 10);
                tmp_index++;
                tmp_data[tmp_index] = '.';
                tmp_index++;
                tmp_data[tmp_index] = tmp_xBegin + 48;
                tmp_index++;
            } else if (xBegin == 0) {
                tmp_data[tmp_index] = '0';
                tmp_index++;
            }
        } else {
            tmp_data[tmp_index] = input_data[i];
            tmp_index++;
        }
    }
    QString tmp_string(tmp_data);
    std::string input_string = tmp_string.toStdString();
    sender_ = std::make_unique<My::Controller>();
    std::pair<double, std::string> result =
        sender_->PushOnButtonEqual(input_string);
    tmp_str = QString::number(result.first);
    ui->result_show->setText(tmp_str);
    tmp_data[0] = '\0';
    memset(tmp_data, 0, sizeof(tmp_data));
    return tmp_str;
}

void MainWindow::on_pushButton_credit_clicked() {
    new_credit_calculate = new Credit_calculate(this);
    new_credit_calculate->show();
}

void MainWindow::on_pushButton_deposit_clicked() {
    new_deposit_calculate = new Deposit_calculate(this);
    new_deposit_calculate->show();
}
