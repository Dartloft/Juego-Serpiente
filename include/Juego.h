#ifndef JUEGO_H
#define JUEGO_H
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include"Serpiente.h"

using namespace std;

class Juego
{
    private:
       Serpiente snake1;
    public:
        Juego();
        void gotoxy(int x,int y);
        void Tablero();
        void dibujar();
};

#endif // JUEGO_H
