#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Заполняем вектор начальными значениями
    for (int i = 0; i < 10; i++) {
        vec.append(10 + i * 2);
    }

    // Выводим вектор в textEdit
    QString str;
    for (int i = 0; i < vec.size(); i++) {
        str += QString::number(vec[i]) + " ";
    }
    ui->textEdit->setText(str);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0: {
        int size = vec.size();
        ui->lineEdit->setText("Vector size: " + QString::number(size));
        break;
    }
    case 1: {
        bool ok;
        int num = ui->lineEdit->text().toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Ошибка", "Введите целое число!");
            return;
        }
        vec.push_back(num);
        break;
    }
    case 2: {
        bool ok;
        int pos = ui->lineEdit->text().toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Ошибка", "Введите целое число!");
            return;
        }
        if (pos < 0 || pos >= vec.size()) {
            QMessageBox::warning(this, "Ошибка",
                                 "Индекс вне диапазона! Допустимые значения: 0-" + QString::number(vec.size() - 1));
            return;
        }
        vec.remove(pos);
        break;
    }
    }

    ui->textEdit->clear();
    QString str;
    for (int i = 0; i < vec.size(); i++) {
        str += QString::number(vec[i]) + " ";
    }
    ui->textEdit->setText(str);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->lineEdit->clear();

    if (index == 0) {
        ui->lineEdit->setReadOnly(true);
        ui->label->setText("Поле для вывода:");
    } else {
        ui->lineEdit->setReadOnly(false);
        if (index == 1) {
            ui->label->setText("Введите значение элемента:");
        } else if (index == 2) {
            ui->label->setText("Введите индекс элемента:");
        }
    }
}
