#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Button_Result_clicked();
    void Result_print(double res);
    void on_radioButton_sqrt_toggled(bool checked);

    void on_radioButton_sin_toggled(bool checked);
    void on_radioButton_cos_toggled(bool checked);
    void on_radioButton_arcsin_toggled(bool checked);
    void on_radioButton_arccos_toggled(bool checked);
    void on_radioButton_plus_clicked();

    void on_radioButton_minus_clicked();

    void on_radioButton_multiply_clicked();

    void on_radioButton_divine_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
