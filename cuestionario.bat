@echo off 
:start
echo Bienvenido al cuestionario
echo 1
echo 2
echo 3
echo 4
echo 5
echo 6 Salir. 

set /p option="Elije el numero de opcion: "

if "%option%" == "1" goto ques1
if "%option%" == "2" goto ques2
if "%option%" == "3" goto ques3
if "%option%" == "4" goto ques4
if "%option%" == "5" goto ques5
if "%option%" == "6" goto finish

rem Mensaje de error
echo No es valido
echo.
pause
goto start

:ques1
cls
echo Segun el teorema del maestro. Sea a>= 1 y b>1 constantes y sea f(n) una funcion, definimos 
echo a T(n) como entero no negativo por la recurrencia: 
echo 1) T(n) = aT(n*b) + f(n).
echo 2) T(n) = aT(n/b) + f(n).
echo 3) T(n) = aT(n/b) - f(n).
set /p resp_1="Respuesta: "

rem Validar la respuesta correcta
if "%resp_1%" == "2" (
    echo Respuesta correcta.
) else (
    echo Respuesta incorrecta. La respuesta correcta es 2.
)
pause
cls 
goto start

:ques2
cls
echo El algoritmo merge-sort que tipo de estrategia o paradigma usa en su procedimiento.
echo 1) Programacion dinamica.
echo 2) Algoritmos voraces.
echo 3) Divide y venceras. 
set /p resp_1="Respuesta: "

rem Validar la respuesta correcta
if "%resp_1%" == "3" (
    echo Respuesta correcta.
) else (
    echo Respuesta incorrecta. La respuesta correcta es 3.
)
pause
cls
goto start

:ques3
cls
echo El algoritmo Dijkstra aborda problemas de peso y...
echo 1) Direccion de grafos.
echo 2) Sentidos opuestos.
echo 3) Optimizacion de recorridos.
set /p resp_1="Respuesta: "

rem Validar la respuesta correcta
if "%resp_1%" == "1" (
    echo Respuesta correcta.
) else (
    echo Respuesta incorrecta. La respuesta correcta es 1.
)
pause
cls
goto start

:ques4
cls
echo Una maquina expendedora basa sus sitema en base al algoritmo de la moneda, que consiste en usar el menor numero de monedas para dar el cambio:
echo 1) Programacion lineal. 
echo 2) Programacion dinamica. 
echo 3) Backtracking.
set /p resp_1="Respuesta: "

rem Validar la respuesta correcta
if "%resp_1%" == "2" (
    echo Respuesta correcta.
) else (
    echo Respuesta incorrecta. La respuesta correcta es 2.
)
pause
cls
goto start

:ques5
cls Si tuvieras una imagen de n x m pixeles, y tuvieras que invertir los colores de la imagen pixel por pixel, ¿que estrategia usarias para resolverlo?
echo Como resolverias 
echo 1) Divide y venceras.
echo 2) Backtracking. 
set /p resp_1="Respuesta: "

rem Validar la respuesta correcta
if "%resp_1%" == "2" (
    echo Respuesta correcta.
) else (
    echo Respuesta incorrecta. La respuesta correcta es 2.
)
pause
cls
goto start

:finish
exit





