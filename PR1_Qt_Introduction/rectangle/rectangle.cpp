#include "rectangle.h"
#include "./ui_rectangle.h"
#include <QMessageBox>

Rectangle::Rectangle(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Rectangle)
{
    ui->setupUi(this);
}

Rectangle::~Rectangle()
{
    delete ui;
}

void Rectangle::on_pushButton_clicked()
{
    // Получаем текст из полей ввода
    QString firstNumStr = ui->lineEdit->text();
    QString secondNumStr = ui->lineEdit_2->text();
    bool ok;

    // Проверка первого числа (длина)
    float firstNum = firstNumStr.toFloat(&ok);
    if (!ok) {
        QMessageBox::information(this, "Ошибка", "Введите число для длины!");
        return;
    }

    // Проверка второго числа (ширина)
    float secondNum = secondNumStr.toFloat(&ok);
    if (!ok) {
        QMessageBox::information(this, "Ошибка", "Введите число для ширины!");
        return;
    }

    // Проверка на отрицательные значения
    if (firstNum <= 0 || secondNum <= 0) {
        QMessageBox::information(this, "Ошибка", "Длина и ширина должны быть положительными!");
        return;
    }

    // Расчет площади
    float result = firstNum * secondNum;

    // Вывод результата
    ui->lineEdit_3->setText(QString::number(result));
}
