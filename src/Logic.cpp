#include "Logic.hpp"

Logic::Logic(){}

Logic::~Logic(){}

std::string Logic::getData(std::string dataPath){
    std::string response;

    // Read from file.
    std::ifstream file(dataPath);

    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo en la ruta: " << dataPath << "." << std::endl;
        return "Error.";
    }

    // Usar un stringstream para capturar todo el contenido del archivo
    std::ostringstream buffer;
    buffer << file.rdbuf(); // Leer todo el contenido del archivo en el buffer

    response = buffer.str(); // Guardar en un string

    file.close();

    return response;
}