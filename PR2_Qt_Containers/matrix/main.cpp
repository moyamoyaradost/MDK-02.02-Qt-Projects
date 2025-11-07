#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Двумерный вектор
    QVector<QVector<int>> matrix;

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение матрицы 3x3 случайными числами от 100 до 199
    for (int i = 0; i < 3; i++) {
        QVector<int> line;
        for (int j = 0; j < 3; j++) {
            line.append(rand() % 100 + 100);
        }
        matrix.append(line);
    }

    // Вывод матрицы
    QTextStream stream(stdout);
    for (int i = 0; i < matrix.length(); i++) {
        QString str = "";
        for (int j = 0; j < matrix[i].length(); j++) {
            str += QString::number(matrix[i][j]) + " ";
        }
        stream << str << "\n";
        stream.flush();
    }

    // Поиск максимального элемента
    int max = matrix[0][0];
    for (int i = 0; i < matrix.length(); i++) {
        for (int j = 0; j < matrix[i].length(); j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    stream << "Максимальный элемент: " << max << "\n";
    stream.flush();

    return 0;
}
