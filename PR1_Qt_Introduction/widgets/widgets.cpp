#include "widgets.h"
#include "./ui_widgets.h"

Widgets::Widgets(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widgets)
{
    ui->setupUi(this);
}

Widgets::~Widgets()
{
    delete ui;
}

void Widgets::on_pushButton_clicked()
{
    // Переносим текст из поля ввода в метку
    ui->label->setText(ui->lineEdit->text());

    // Изменяем стиль метки
    ui->label->setStyleSheet("color: blue; "
                             "font-family: 'Comic Sans MS'; "
                             "font-size: 20px;");

    // Очищаем поле ввода
    ui->lineEdit->clear();
}
