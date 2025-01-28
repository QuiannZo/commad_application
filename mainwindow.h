#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

#include "src/Logic.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, Logic& logic);
    ~MainWindow();

private slots:
    void on_systemBtn_clicked();

    void on_gitBtn_clicked();

private:
    Ui::MainWindow *ui;
    Logic& logic;
};
#endif // MAINWINDOW_H
