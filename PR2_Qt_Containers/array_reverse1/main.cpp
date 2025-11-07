#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream in(stdin);
    QTextStream out(stdout);

    out << "Введите размер массива N: ";
    out.flush();
    int n = in.readLine().toInt();

    QVector<int> vec;
    out << "Введите " << n << " элементов (по одному на строку):\n";
    out.flush();

    for (int i = 0; i < n; i++) {
        int num = in.readLine().toInt();
        vec.append(num);
    }

    out << "Исходный массив: ";
    for (int i = 0; i < vec.size(); i++) {
        out << vec[i] << " ";
    }
    out << "\n";
    out.flush();

    // Выводим в обратном порядке
    out << "Массив в обратном порядке: ";
    for (int i = vec.size() - 1; i >= 0; i--) {
        out << vec[i] << " ";
    }
    out << "\n";
    out.flush();

    return 0;
}
