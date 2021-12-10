#include "widget.h"
#include "ui_widget.h"
#include "math.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::Result_print(double res){
    ui->lineEdit_result->setText(QString::number(res));
}

void Widget::on_Button_Result_clicked()
{
    ui->label_error->clear();
    if(ui->radioButton_sqrt->isChecked()){
        ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        bool ok1 = false;
        double element_1 = ui->lineEdit_1stElement->text().toDouble(&ok1);
        if(ok1 && element_1 > 0){
            Result_print(sqrt(element_1));
        }
        else{
            ui->label_1stElement->clear();
            ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
            ui->label_error->setText("Введите положительное число");
        }
    }
    else if(ui->radioButton_sin->isChecked()){
        ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        bool ok1 = false;
        double element_1 = ui->lineEdit_1stElement->text().toDouble(&ok1);
        if(ok1){
            if(abs(sin(element_1 * M_PI / 180)) < 1e-10){
                Result_print(0);
            }
            else {
                Result_print(sin(element_1*M_PI/180));
            }
        }
        else{
            ui->label_1stElement->clear();
            ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
            ui->label_error->setText("Введите число");
        }
    }
    else if(ui->radioButton_cos->isChecked()){
        ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        bool ok1 = false;
        double element_1 = ui->lineEdit_1stElement->text().toDouble(&ok1);
        if(ok1){
            if(abs(cos(element_1 * M_PI / 180)) < 1e-10)
                Result_print(0);
            else{
                Result_print(cos(element_1*M_PI/180));
            }
        }
        else {

            ui->label_1stElement->clear();
            ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
            ui->label_error->setText("Введите число");
        }
    }
    else if(ui->radioButton_arcsin->isChecked()){
        ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        bool ok1 = false;
        double element_1 = ui->lineEdit_1stElement->text().toDouble(&ok1);
        if(ok1){
            if(abs(asin(element_1 * M_PI / 180)) < 1e-10){
                Result_print(0);
            }
            else{
                Result_print(asin(element_1*M_PI/180));
            }
        }
        else {
            ui->label_1stElement->clear();
            ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
            ui->label_error->setText("Введите число");
        }
    }
    else if(ui->radioButton_arccos->isChecked()){
        ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        bool ok1 = false;
        double element_1 = ui->lineEdit_1stElement->text().toDouble(&ok1);
        if(ok1){
            if(abs(acos(element_1 * M_PI / 180)) < 1e-10){
                Result_print(0);
            }
            else{
                Result_print(acos(element_1*M_PI/180));
            }
        }
        else {
            ui->label_1stElement->clear();
            ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
            ui->label_error->setText("Введите число");
        }
    }
    else{
        ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        ui->lineEdit_2ndElement->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
        bool ok1 = false, ok2 = false;
        double element_1 = ui->lineEdit_1stElement->text().toDouble(&ok1);
        double element_2 = ui->lineEdit_2ndElement->text().toDouble(&ok2);

        if (ok1 and ok2){
            if (ui->radioButton_plus->isChecked()){
                ui->label_1stElement->setText("Первое слагаемое");
                ui->label_2ndElement->setText("Второе слагаемое");
                ui->label_result->setText("Сумма");
                Result_print(element_1 + element_2);
            }
            if (ui->radioButton_minus->isChecked()){
                ui->label_1stElement->setText("Уменьшаемое");
                ui->label_2ndElement->setText("Вычитаемое");
                ui->label_result->setText("Разность");
                Result_print(element_1 - element_2);
            }
            if (ui->radioButton_multiply->isChecked()){
                ui->label_1stElement->setText("Первый множитель");
                ui->label_2ndElement->setText("Второй множитель");
                ui->label_result->setText("Произведение");
                Result_print(element_1 * element_2);
            }
            if (ui->radioButton_divine->isChecked()){
                if(element_2 == 0){
                    ui->label_error->setText("Нельзя делить на ноль");
                    ui->lineEdit_2ndElement->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");
                    ui->lineEdit_result->clear();
                }
                else{
                    ui->label_1stElement->setText("Делимое");
                    ui->label_2ndElement->setText("Делитель");
                    ui->label_result->setText("Частное");
                    Result_print(element_1/element_2);
                }
            }
        }
        else {
            ui->label_error->setText("Введите  число");
            if(!ok1){
                ui->lineEdit_1stElement->clear();
                ui->lineEdit_1stElement->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");     }
            if(!ok2){
                ui->lineEdit_2ndElement->clear();
                ui->lineEdit_2ndElement->setStyleSheet("QLineEdit { background: rgb(255, 0, 0); }");     }
            ui->lineEdit_result->clear();
        }
    }
}

void Widget::on_radioButton_sqrt_toggled(bool checked)
{
    ui->lineEdit_2ndElement->clear();
    ui->label_2ndElement->setVisible(!checked);
    ui->lineEdit_2ndElement->setVisible(!checked);
    ui->label_1stElement->setText("Число");
    ui->label_result->setText("Корень");
}

void Widget::on_radioButton_sin_toggled(bool checked)
{
    ui->lineEdit_2ndElement->clear();
    ui->label_2ndElement->setVisible(!checked);
    ui->lineEdit_2ndElement->setVisible(!checked);
    ui->label_1stElement->setText("Число");
    ui->label_result->setText("sin");

}

void Widget::on_radioButton_cos_toggled(bool checked){
    ui->lineEdit_2ndElement->clear();
    ui->label_2ndElement->setVisible(!checked);
    ui->lineEdit_2ndElement->setVisible(!checked);
    ui->label_1stElement->setText("Число");
    ui->label_result->setText("cos");
}

void Widget::on_radioButton_arcsin_toggled(bool checked){
    ui->lineEdit_2ndElement->clear();
    ui->label_2ndElement->setVisible(!checked);
    ui->lineEdit_2ndElement->setVisible(!checked);
    ui->label_1stElement->setText("Число");
    ui->label_result->setText("arcsin");
}

void Widget::on_radioButton_arccos_toggled(bool checked){
    ui->lineEdit_2ndElement->clear();
    ui->label_2ndElement->setVisible(!checked);
    ui->lineEdit_2ndElement->setVisible(!checked);
    ui->label_1stElement->setText("Число");
    ui->label_result->setText("arccos");
}
