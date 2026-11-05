@echo off
REM Script de compilación para Windows
REM Compila todos los archivos .cpp del directorio src/ usando el estándar C++17
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I./include src/*.cpp -o app.exe
echo Compilacion finalizada. Ejecuta app.exe para iniciar.
pause