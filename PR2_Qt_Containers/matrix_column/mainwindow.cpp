#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <ctime>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(0));

    // Создаём матрицу 5x10 со случайными числами от 1 до 20
    for (int i = 0; i < 5; i++) {
        QVector<int> row;
        for (int j = 0; j < 10; j++) {
            row.append(rand() % 20 + 1);
        }
        matrix.append(row);
    }

    // Выводим матрицу
    ui->textEdit->clear();
    ui->textEdit->append("Матрица 5x10:");
    ui->textEdit->append("");

    for (int i = 0; i < matrix.size(); i++) {
        QString str = "";
        for (int j = 0; j < matrix[i].size(); j++) {
            str += QString::number(matrix[i][j]).rightJustified(4) + " ";
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
    // Получаем номер столбца
    bool ok;
    int k = ui->lineEdit->text().toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Введите целое число!");
        return;
    }

    if (k < 1 || k > 10) {
        QMessageBox::warning(this, "Ошибка", "Номер столбца должен быть от 1 до 10!");
        return;
    }

    // Индекс столбца (начинается с 0)
    int colIndex = k - 1;

    // Вычисляем сумму или произведение
    int selectedOperation = ui->comboBox->currentIndex();

    if (selectedOperation == 0) {
        // Сумма
        int sum = 0;
        for (int i = 0; i < matrix.size(); i++) {
            sum += matrix[i][colIndex];
        }
        ui->labelResult->setText("Сумма элементов " + QString::number(k) + "-го столбца: " + QString::number(sum));
    } else {
        // Произведение
        long long product = 1;
        for (int i = 0; i < matrix.size(); i++) {
            product *= matrix[i][colIndex];
        }
        ui->labelResult->setText("Произведение элементов " + QString::number(k) + "-го столбца: " + QString::number(product));
    }
}
