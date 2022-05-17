#include "Juego.h"

Juego::Juego()
{
    dibujar();
}

//Funcion que posiciona el mouse en las coordenadas x e y
void Juego::gotoxy(int x,int y)
{
    HANDLE hcon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hcon,dwPos);

}

//Funcion para dibujar el tablero del juego
void Juego::Tablero()
{
    //Lineas horizontales del tablero
    for(int i=2; i< 78;i++)
    {
        gotoxy(i,3);
        cout<<"#"<<endl;
        gotoxy(i,23);
        cout<<"#"<<endl;

    }

    //Lineas verticales del tablero
    for(int i=4; i< 23;i++)
    {
        gotoxy(2,i);
        cout<<"#"<<endl;
        gotoxy(77,i);
        cout<<"#"<<endl;

    }

}

void Juego::dibujar()
{
    snake1.gameOver();
    Tablero();
    snake1.actualizar();

}


