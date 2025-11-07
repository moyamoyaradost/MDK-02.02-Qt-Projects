#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::on_pushButton_clicked()
{
    // Получаем значения из полей ввода
    QString xStr = ui->lineEditX->text();
    QString yStr = ui->lineEditY->text();
    QString zStr = ui->lineEditZ->text();
    bool okX, okY, okZ;

    // Преобразуем в числа
    float x = xStr.toFloat(&okX);
    float y = yStr.toFloat(&okY);
    float z = zStr.toFloat(&okZ);

    // Проверка корректности ввода
    if (!okX || !okY || !okZ) {
        QMessageBox::warning(this, "Ошибка", "Введите корректные числа для всех трех переменных!");
        return;
    }

    // Проверяем упорядоченность
    bool ascending = (x <= y && y <= z);   // по возрастанию: X ≤ Y ≤ Z
    bool descending = (x >= y && y >= z);  // по убыванию: X ≥ Y ≥ Z

    if (ascending || descending) {
        // Упорядочены → удваиваем
        x = x * 2;
        y = y * 2;
        z = z * 2;
    } else {
        // Не упорядочены → заменяем на противоположные
        x = -x;
        y = -y;
        z = -z;
    }

    // Выводим результат
    QString result = QString("X = %1,  Y = %2,  Z = %3").arg(x).arg(y).arg(z);
    ui->labelResult->setText(result);

    // Обновляем значения в полях ввода
    ui->lineEditX->setText(QString::number(x));
    ui->lineEditY->setText(QString::number(y));
    ui->lineEditZ->setText(QString::number(z));
}
