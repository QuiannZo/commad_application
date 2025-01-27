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

void MainWindow::on_systemBtn_clicked()
{
    // Test a random csv.
    std::string response;
    ////clientNode.getSensorData(this->clientNode.username, response);  The file is gotten here.
    std::string filePath = "src/data/arch.csv";
    QFile file(filePath);

    // Intentar abrir el archivo en modo lectura
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "No se pudo abrir el archivo: " + filePath);
        return;
    }

    // Crear un QTextStream para leer el archivo
    QTextStream in(&file);
    QString fileContent = in.readAll(); // Leer todo el contenido como QString

    // Convertir QString a std::string
    response = fileContent.toStdString();

    file.close(); // Cerrar el archivo

    // Convertimos la respuesta de std::string a QString
    QString responseStr = QString::fromStdString(response);

    // Dividimos la respuesta en líneas (cada sensor será una línea)
    QStringList lines = responseStr.split("\n");

    // Establecemos el número de filas y columnas en la tabla
    int rowCount = lines.size();
    int colCount = 2; // Name, command.

    // Configuramos la tabla con las filas y columnas
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(colCount);

    // Establecemos los encabezados de las columnas
    QStringList headers = {"idSensor", "Date", "Time", "Value"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Rellenamos la tabla con los datos de cada fila
    for (int i = 0; i < rowCount; ++i) {
        QStringList fields = lines[i].split(",");

        // Aseguramos que la línea tenga el número correcto de columnas
        if (fields.size() == colCount) {
            // Insertamos los datos de cada columna en las filas correspondientes
            for (int j = 0; j < fields.size(); ++j) {
                QTableWidgetItem *item = new QTableWidgetItem(fields[j].trimmed());  // trim() elimina espacios extra
                ui->tableWidget->setItem(i, j, item);
            }
        }
    }

    // Ajusta el ancho de las columnas automáticamente para que se ajusten al contenido
    ui->tableWidget->resizeColumnsToContents();

    // Estira la última columna para que ocupe el espacio sobrante
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}
