#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Rectangle;
}
QT_END_NAMESPACE

class Rectangle : public QMainWindow
{
    Q_OBJECT

public:
    Rectangle(QWidget *parent = nullptr);
    ~Rectangle();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Rectangle *ui;
};
#endif // RECTANGLE_H
