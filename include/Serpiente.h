#ifndef SERPIENTE_H
#define SERPIENTE_H

#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

class Serpiente
{
    private:
        //Variables de la serpiente
        int cuerpo_serpiente[200][2];
        int tam = 2;
        int n = 1;
        int x = 10;
        int y = 12;
        int direccion= 3;
        int velocidad =100;

        char tecla;

        //Variables de la comida
        int xc = 30;
        int yc = 15;
        int puntos = 0;
        int h =1;

    public:
        Serpiente();
        void gotoxy(int x,int y);
        void guardar_posicion();
        void controles();
        void dibujar();
        void borrar();
        void actualizar();
        void cambiar_velocidad();
        void Comida();
        void Puntos_comida();
        bool gameOver();
};

#endif // SERPIENTE_H
