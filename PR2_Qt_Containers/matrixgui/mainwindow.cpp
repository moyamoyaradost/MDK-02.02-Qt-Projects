#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Заполнение начальной матрицы
    for (int i = 0; i < 5; i++) {
        QVector<int> vec;
        for (int j = 0; j <= i; j++) {
            vec.append(i * j);
        }
        matrix.append(vec);
    }

    strCount = 5;

    // Вывод матрицы
    ui->textEdit->clear();
    for (int i = 0; i < matrix.length(); i++) {
        QString str = "";
        for (int j = 0; j < matrix[i].length(); j++) {
            str += QString::number(matrix[i][j]) + " | ";
        }
        ui->textEdit->append(str);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QVector<int> line;

    // Заполнение нового вектора
    for (int j = 0; j <= strCount; j++) {
        line.append(strCount * j);
    }

    matrix.append(line);
    strCount++;

    // Если количество строк > 10, очищаем матрицу
    if (strCount > 10) {
        matrix.clear();
        strCount = 0;
    }

    // Вывод в textEdit
    ui->textEdit->setText("strCount: " + QString::number(strCount));
    for (int i = 0; i < matrix.length(); i++) {
        QString str = "";
        for (int j = 0; j < matrix[i].length(); j++) {
            str += " " + QString::number(matrix[i][j]) + " | ";
        }
        ui->textEdit->append(str);
    }
}
