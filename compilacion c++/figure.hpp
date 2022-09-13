#include <iostream>
#include "iomanip"
#include <conio.h> // libreria para el _getch()

using namespace std;

class Figura // Clase padre
{
public:
    int longitud;
    int CoordenadaX;
    int CoordenadaY;
};

class Cuadrado : public Figura // Clase derivada
{
public:
    int llenoVacio;
    void dibujarCuadrado(int, int, int, int);
};

class Triangulo : public Figura
{
public:
    void dibujarTriangulo(int, int, int);
};

class Rectangulo : public Figura
{
public:
    int ancho;
    void dibujarRectangulo(int, int, int, int);
};

class Menu
{
public:
    int entrada;
    void iniciarMenu();
};

// Objetos
Menu objetoMenu;
Cuadrado objetoCuadrado;
Triangulo objetoTriangulo;
Rectangulo objetoRectangulo;
