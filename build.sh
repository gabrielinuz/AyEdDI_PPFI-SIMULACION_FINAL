#!/bin/bash
# Script de compilación para GNU/Linux
# Compila todos los archivos .cpp del directorio src/ usando el estándar C++17
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I./include src/*.cpp -o app.exe
echo "Compilación finalizada. Ejecuta ./app.exe para iniciar."