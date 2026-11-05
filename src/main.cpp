/**
 * @file main.cpp
 * @brief Punto de entrada del programa.
 * 
 * Se cumple con el requerimiento estricto de desplazar toda la lógica a clases
 * encapsuladas. Este main sólo se encarga de la inicialización estática de 
 * la clase Application del namespace cosmetic y devolver el código de estado 0.
 */
#include "application.hpp"

int main() 
{
    cosmetic::Application app;
    app.run();
    
    return 0;
}