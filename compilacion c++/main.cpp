#include <iostream>
#include "iomanip"
#include <conio.h> // libreria para el _getch()
#include <figura.hpp>

int main()
{

    for (size_t i = 0; i < 100000000; i++)
    {
        objetoMenu.iniciarMenu();
    }
}

void Menu::iniciarMenu()
{
    system("cls"); // Limpia la pantalla de la consola
    cout << "Que figura desea dibujar ? " << endl
         << "[1] Cuadrado" << endl
         << "[2] Triangulo" << endl
         << "[3] Rectangulo" << endl;
    cin >> entrada; // Para decidir entre triangulo y cuadrado

    if (entrada == 1) // Preguntas para la creacion del cuadrado
    {
        system("cls");
        cout << "Ingrese la longitud del cuadrado" << endl;
        cin >> objetoCuadrado.longitud;

        system("cls");
        cout << "[1] Vacio" << endl
             << "[2] Lleno" << endl;
        cin >> objetoCuadrado.llenoVacio;

        system("cls");
        cout << "Ingrese las coordenada incial X" << endl;
        cin >> objetoCuadrado.CoordenadaX;

        system("cls");
        cout << "Ingrese las coordenada incial Y" << endl;
        cin >> objetoCuadrado.CoordenadaY;

        // llama al metodo que dibujara el cuadrado
        objetoCuadrado.dibujarCuadrado(objetoCuadrado.longitud, objetoCuadrado.llenoVacio, objetoCuadrado.CoordenadaX, objetoCuadrado.CoordenadaY);
    }

    if (entrada == 2) // Preguntas para la creacion del Triangulo
    {
        system("cls");
        cout << "Ingrese la longitud del Triangulo" << endl;
        cin >> objetoTriangulo.longitud;

        system("cls");
        cout << "Ingrese las coordenada incial X" << endl;
        cin >> objetoTriangulo.CoordenadaX;

        system("cls");
        cout << "Ingrese las coordenada incial Y" << endl;
        cin >> objetoTriangulo.CoordenadaY;

        // Llama la funcion de dibujo de triangulo
        objetoTriangulo.dibujarTriangulo(objetoTriangulo.longitud, objetoTriangulo.CoordenadaX, objetoTriangulo.CoordenadaY);
    }
    if (entrada == 3) // Preguntas para la creacion del Triangulo
    {
        system("cls");
        cout << "Ingrese el largo del Rectangulo" << endl;
        cin >> objetoRectangulo.longitud;

        system("cls");
        cout << "Ingrese el ancho del Rectangulo" << endl;
        cin >> objetoRectangulo.ancho;

        system("cls");
        cout << "Ingrese las coordenada incial X" << endl;
        cin >> objetoRectangulo.CoordenadaX;

        system("cls");
        cout << "Ingrese las coordenada incial Y" << endl;
        cin >> objetoRectangulo.CoordenadaY;

        // Llama la funcion de dibujo de triangulo
        objetoRectangulo.dibujarRectangulo(objetoRectangulo.longitud, objetoRectangulo.ancho, objetoRectangulo.CoordenadaX, objetoRectangulo.CoordenadaY);
    }
}

void Cuadrado::dibujarCuadrado(int longitud, int llenoVacio, int CoordenadaX, int CoordenadaY)
{
    for (size_t i = 0; i < 10000000; i++)
    {
        // limpia pantalla
        system("cls");

        // Se asegura de no recibir coordenadas negativas al moverlo con ASDW
        if (CoordenadaX < 0) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaX = 0;
        }

        if (CoordenadaY < 0) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaY = 0;
        }

        if (CoordenadaX > 30) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaX = 30;
        }

        if (CoordenadaY > 20) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaY = 20;
        }

        // Opciones para cuando el cuadrado se pide lleno o vacio
        if (llenoVacio == 1)
        {
            for (size_t a = 0; a < longitud + CoordenadaY; a++)
            {
                if (a < CoordenadaY)
                {
                    cout << "    ";
                }
                else
                {
                    for (size_t b = 0; b < longitud + CoordenadaX; b++)
                    {
                        if (b < CoordenadaX)
                        {
                            cout << "   ";
                        }
                        else if (b > CoordenadaX && b != CoordenadaX && a != CoordenadaY && b != CoordenadaX + longitud - 1 && a != CoordenadaY + longitud - 1 && a > CoordenadaY)
                        {

                            cout << "   ";
                        }
                        else
                            cout << " * ";
                    }
                }
                cout << endl;
            }
        }

        if (llenoVacio == 2)
        {
            // Dibuja el cuadrado en las cordenadas indicadas por CoordenadaX y CoordenadaY
            for (size_t i = 0; i < longitud + CoordenadaY; i++)
            {
                if (i < CoordenadaY)
                {
                    cout << "   ";
                }
                else
                {
                    for (size_t i = 0; i < longitud + CoordenadaX; i++)
                    {
                        if (i < CoordenadaX)
                        {
                            cout << "   ";
                        }
                        else
                            cout << " * ";
                    }
                }

                cout << endl;
            }
        }

        for (size_t i = 0; i < 10000000; i++)
        {
            // Funcion que permite detectar caracteres directos del teclado sin necesidad de un Enter
            char tecla = _getch();
            // Manda a llamar la funcion de dibujar cuadrado pero con un valor mas o valor menos es una coordenada, de forma que se mueve el cuadrado
            if (tecla == 'A' || tecla == 'a')
            {
                CoordenadaX = CoordenadaX - 1;
                objetoCuadrado.dibujarCuadrado(longitud, llenoVacio, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'S' || tecla == 's')
            {
                CoordenadaY = CoordenadaY + 1;
                objetoCuadrado.dibujarCuadrado(longitud, llenoVacio, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'D' || tecla == 'd')
            {
                CoordenadaX = CoordenadaX + 1;
                objetoCuadrado.dibujarCuadrado(longitud, llenoVacio, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'W' || tecla == 'w')
            {
                CoordenadaY = CoordenadaY - 1;
                objetoCuadrado.dibujarCuadrado(longitud, llenoVacio, CoordenadaX, CoordenadaY);
            }

            if (tecla == 'L' || tecla == 'l')
            {

                objetoMenu.iniciarMenu();
            }
        }
    }
}

void Triangulo::dibujarTriangulo(int longitud, int CoordenadaX, int CoordenadaY)
{

    int contador = 0;
    for (size_t i = 0; i < 10000000; i++)
    {
        // limpia pantalla
        system("cls");

        // Se asegura de no recibir coordenadas negativas al moverlo con ASDW
        if (CoordenadaX < 0) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaX = 0;
        }

        if (CoordenadaY < 0) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaY = 0;
        }
        if (CoordenadaX > 30) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaX = 30;
        }

        if (CoordenadaY > 20) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaY = 20;
        }
        contador = 0;
        // Proceso de dibujo del Triangulo
        for (size_t a = 0; a < longitud + CoordenadaY; a++)
        {
            if (a < CoordenadaY)
            {
                cout << "    ";
            }
            else
            {
                for (size_t b = 0; b < longitud + CoordenadaX; b++)
                {
                    if (b < CoordenadaX)
                    {
                        cout << "   ";
                    }
                    else if (b > CoordenadaX + contador)
                    {
                        cout << "  ";
                    }
                    else
                        cout << " * ";
                }
                contador = contador + 1;
            }
            if (contador >= longitud)
            {
                contador == longitud;
            }
            cout << endl;
        }

        // Dibuja el Triangulo en las cordenadas indicadas por CoordenadaX y CoordenadaY

        for (size_t i = 0; i < 10000000; i++)
        {
            // Funcion que permite detectar caracteres directos del teclado sin necesidad de un Enter
            char tecla = _getch();
            // Manda a llamar la funcion de dibujar cuadrado pero con un valor mas o valor menos es una coordenada, de forma que se mueve el cuadrado
            if (tecla == 'A' || tecla == 'a')
            {
                CoordenadaX = CoordenadaX - 1;
                objetoTriangulo.dibujarTriangulo(longitud, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'S' || tecla == 's')
            {
                CoordenadaY = CoordenadaY + 1;
                objetoTriangulo.dibujarTriangulo(longitud, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'D' || tecla == 'd')
            {
                CoordenadaX = CoordenadaX + 1;
                objetoTriangulo.dibujarTriangulo(longitud, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'W' || tecla == 'w')
            {
                CoordenadaY = CoordenadaY - 1;
                objetoTriangulo.dibujarTriangulo(longitud, CoordenadaX, CoordenadaY);
            }

            if (tecla == 'L' || tecla == 'l')
            {

                objetoMenu.iniciarMenu();
            }
        }
    }
}

void Rectangulo::dibujarRectangulo(int longitud, int ancho, int CoordenadaX, int CoordenadaY)
{
    for (size_t i = 0; i < 10000000; i++)
    {
        // limpia pantalla
        system("cls");

        // Se asegura de no recibir coordenadas negativas al moverlo con ASDW
        if (CoordenadaX < 0) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaX = 0;
        }

        if (CoordenadaY < 0) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaY = 0;
        }

        if (CoordenadaX > 30) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaX = 30;
        }

        if (CoordenadaY > 20) // limite de movimiento para la figura para que no salga de la pantalla
        {
            CoordenadaY = 20;
        }

        // Dibuja el cuadrado en las cordenadas indicadas por CoordenadaX y CoordenadaY
        for (size_t i = 0; i < ancho + CoordenadaY; i++)
        {
            if (i < CoordenadaY)
            {
                cout << "   ";
            }
            else
            {
                for (size_t i = 0; i < longitud + CoordenadaX; i++)
                {
                    if (i < CoordenadaX)
                    {
                        cout << "   ";
                    }
                    else
                        cout << " * ";
                }
            }

            cout << endl;
        }

        for (size_t i = 0; i < 10000000; i++)
        {
            // Funcion que permite detectar caracteres directos del teclado sin necesidad de un Enter
            char tecla = _getch();
            // Manda a llamar la funcion de dibujar cuadrado pero con un valor mas o valor menos es una coordenada, de forma que se mueve el cuadrado
            if (tecla == 'A' || tecla == 'a')
            {
                CoordenadaX = CoordenadaX - 1;
                objetoRectangulo.dibujarRectangulo(longitud, ancho, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'S' || tecla == 's')
            {
                CoordenadaY = CoordenadaY + 1;
                objetoRectangulo.dibujarRectangulo(longitud, ancho, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'D' || tecla == 'd')
            {
                CoordenadaX = CoordenadaX + 1;
                objetoRectangulo.dibujarRectangulo(longitud, ancho, CoordenadaX, CoordenadaY);
            }
            if (tecla == 'W' || tecla == 'w')
            {
                CoordenadaY = CoordenadaY - 1;
                objetoRectangulo.dibujarRectangulo(longitud, ancho, CoordenadaX, CoordenadaY);
            }

            if (tecla == 'L' || tecla == 'l')
            {
                objetoMenu.iniciarMenu();
            }
        }
    }
}