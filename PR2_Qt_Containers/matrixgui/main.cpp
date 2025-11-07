#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Введите размер массива N:";
    QTextStream in(stdin);
    int n = in.readLine().toInt();

    QVector<int> vec;
    qDebug() << "Введите" << n << "элементов:";

    for (int i = 0; i < n; i++) {
        int num = in.readLine().toInt();
        vec.append(num);
    }

    qDebug() << "Исходный массив:" << vec;

    // Выводим в обратном порядке
    qDebug() << "Массив в обратном порядке:";
    QVector<int> reversed;
    for (int i = vec.size() - 1; i >= 0; i--) {
        reversed.append(vec[i]);
    }
    qDebug() << reversed;

    return 0;
}
