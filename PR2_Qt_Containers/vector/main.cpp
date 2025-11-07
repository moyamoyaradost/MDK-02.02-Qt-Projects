#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Способ 1: Задать размер и заполнить через []
    QVector<float> vect1(3);
    vect1[0] = 1.0;
    vect1[1] = 0.5;
    vect1[2] = -0.4;
    qDebug() << "Способ 1:" << vect1;

    // Способ 2: Вектор с одинаковыми значениями
    QVector<int> vect2(5, 3);
    qDebug() << "Способ 2:" << vect2;

    // Способ 3: push_back()
    QVector<int> vect3;
    vect3.push_back(10);
    vect3.push_back(20);
    vect3.push_back(30);
    qDebug() << "Способ 3:" << vect3;

    // Способ 4: append()
    QVector<float> vect4;
    vect4.append(34.0);
    vect4.append(0.5899);
    vect4.append(-0.678);
    qDebug() << "Способ 4:" << vect4;

    // Способ 5: append() со строками
    QVector<QString> vect5;
    vect5.append("one");
    vect5.append("two");
    vect5.append("three");
    qDebug() << "Способ 5:" << vect5;

    return 0;
}
