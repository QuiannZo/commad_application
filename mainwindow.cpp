#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Establecer las propiedades de la ventana
    setWindowFlag(Qt::FramelessWindowHint); // Sin bordes
    setWindowFlag(Qt::WindowStaysOnTopHint); // Siempre en la parte superior
    setWindowFlag(Qt::Window); // Comportamiento de ventana

    // Tamaño y posición inicial
    resize(600, 400); // Cambia según el tamaño deseado
    move(500, 300);   // Cambia según la posición inicial deseada

    // Inicializar la UI
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
