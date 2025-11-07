#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()  // или Task1_swap::on_pushButton_clicked()
{
    // Получаем текст из полей ввода
    QString xStr = ui->lineEditX->text();
    QString yStr = ui->lineEditY->text();
    bool okX, okY;

    // Преобразуем в числа
    float x = xStr.toFloat(&okX);
    float y = yStr.toFloat(&okY);

    // Проверка корректности ввода
    if (!okX || !okY) {
        QMessageBox::warning(this, "Ошибка", "Введите корректные числа!");
        return;
    }

    // Перераспределяем значения (меньшее в X, большее в Y)
    if (x > y) {
        // Меняем местами
        float temp = x;
        x = y;
        y = temp;
    }

    // Выводим результат
    QString result = QString("X = %1,  Y = %2").arg(x).arg(y);
    ui->labelResult->setText(result);

    // Обновляем значения в полях ввода (опционально)
    ui->lineEditX->setText(QString::number(x));
    ui->lineEditY->setText(QString::number(y));
}

