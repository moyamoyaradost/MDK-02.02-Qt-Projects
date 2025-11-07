#ifndef WIDGETS_H
#define WIDGETS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widgets;
}
QT_END_NAMESPACE

class Widgets : public QMainWindow
{
    Q_OBJECT

public:
    Widgets(QWidget *parent = nullptr);
    ~Widgets();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widgets *ui;
};
#endif // WIDGETS_H
