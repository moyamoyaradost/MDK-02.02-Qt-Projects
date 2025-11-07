#include <QCoreApplication>
#include <QDebug>
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> vec;

    // Создаём вектор от 0 до 10
    for (int i = 0; i <= 10; i++) {
        vec.push_back(i);
    }
    qDebug() << "Вектор:" << vec;

    // Заменяем элемент с индексом 2 на 65
    vec.replace(2, 65);
    qDebug() << "После замены:" << vec;

    // Находим сумму элементов
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    qDebug() << "Сумма =" << sum;

    return 0;
}
