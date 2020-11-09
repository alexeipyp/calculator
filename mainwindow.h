#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calculator.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_sub_clicked();
    void on_add_clicked();
    void on_mult_clicked();
    void on_clr_clicked();
    void on_abs_clicked();
    void on_div_clicked();

private:
    Ui::MainWindow *ui;
    Calculator calc;

    void processDoubleValueFunctions(int functionIndex);
    void processAbs();
};
#endif // MAINWINDOW_H
