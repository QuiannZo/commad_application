#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //
    Logic* logic = new Logic();

    MainWindow w(nullptr, *logic);
    w.show();

    int result = a.exec();
    delete logic;
    std::cout << "Application closed." << std::endl;
    return result;
}
