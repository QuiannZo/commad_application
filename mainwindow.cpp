#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Logic& logic)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , logic(logic)
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

    // Btns icons.
    // Set git icon
    QIcon icon1("../../../commad_application/img/git.png"); // Usa un recurso de Qt o una ruta absoluta/relativa
    ui->gitBtn->setIcon(icon1);
    ui->gitBtn->setIconSize(QSize(40, 40));

    // Set arch icon
    QIcon icon2("../../../commad_application/img/arch.png"); // Usa un recurso de Qt o una ruta absoluta/relativa
    ui->systemBtn->setIcon(icon2);
    ui->systemBtn->setIconSize(QSize(40, 40));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_systemBtn_clicked()
{
    // Func
    qDebug() << "Directorio actual:" << QDir::currentPath();
    std::string response;
    std::string src = "../../../commad_application/src/data/arch.csv"; // Relative to the executable on build/
    //// get data here.
    response = logic.getData(src);

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
    QStringList headers = {"Name", "Command"};
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

// Git btn.
void MainWindow::on_gitBtn_clicked()
{

}

