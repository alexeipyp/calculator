#include "mainwindow.h"
#include "ui_mainwindow.h"

double getInput(QString baseInput, bool *isOk, int mode);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processDoubleValueFunctions(int functionIndex)
{
    bool isFirstValid, isSecondValid;
    calc.setFirstValue(getInput(ui->display->text(), &isFirstValid, 1) );
    calc.setSecondValue(getInput(ui->display->text(), &isSecondValid, 2) );
    if ((isFirstValid==1) && (isSecondValid==1))
    {
        QString output;
        double result;
        switch(functionIndex)
        {
            case 1: //Сложение
                result = calc.getAdd();
            break;
            case 2: //Вычитание
                result = calc.getSub();
            break;
            case 3: //Умножение
                result = calc.getMult();
            break;
            case 4: //Деление
                result = calc.getDiv();
            break;
        }
        output.setNum(result);
        ui->display->setText(output);
    }
    else
    {
        ui->display->setText("Error: Wrong Input");
    }
}

void MainWindow::processAbs()
{
    bool isValueValid;
    calc.setFirstValue(getInput(ui->display->text(), &isValueValid, 0) );
    if (isValueValid == 1)
    {
        QString result;
        result.setNum(calc.getAbs());
        ui->display->setText(result);
    }
    else
    {
        ui->display->setText("Error: Wrong Input");
    }
}

void MainWindow::on_add_clicked()
{
    processDoubleValueFunctions(1);
}
void MainWindow::on_sub_clicked()
{
    processDoubleValueFunctions(2);
}
void MainWindow::on_mult_clicked()
{
    processDoubleValueFunctions(3);
}
void MainWindow::on_div_clicked()
{
    processDoubleValueFunctions(4);
}
void MainWindow::on_abs_clicked()
{
    processAbs();
}
void MainWindow::on_clr_clicked()
{
    ui->display->clear();
}

double getInput(QString baseInput, bool *isOk, int mode)
{
    QString input = baseInput.trimmed();
    double result;
    switch(mode)
    {
        case 0:
            result = input.toDouble(isOk);
        break;
        case 1:
            input.chop( input.length()-input.indexOf(" ") );
            result = input.toDouble(isOk);
        break;
        case 2:
            result = input.remove(0,input.indexOf(" ")+1).toDouble(isOk);
        break;
    }
    return result;
}
