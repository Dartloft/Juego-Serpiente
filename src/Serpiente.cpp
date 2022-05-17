#include "Serpiente.h"

Serpiente::Serpiente()
{

}

void Serpiente::gotoxy(int x,int y)
{
    HANDLE hcon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hcon,dwPos);

}

//Funcion que guarda la posicion de la serpiente
void Serpiente::guardar_posicion()
{
    cuerpo_serpiente[n][0] = x;
    cuerpo_serpiente[n][1] = y;
    n++;
    if(n == tam)
    {
        n = 1;
    }
}

//Funcion de control de la serpiente
void Serpiente::controles()
{
    if(kbhit())
    {
        tecla = getch();
        switch(tecla)
        {
        case 'w':
            if(direccion != 2)
            {
                direccion = 1;
            }
            break;
        case 's':
            if(direccion != 1)
            {
                direccion = 2;
            }
            break;
        case 'd':
            if(direccion != 3)
            {
                direccion = 4;
            }
            break;
        case 'a':
            if(direccion != 4)
            {
                direccion = 3;
            }
            break;

        }
    }
}

//Funcion que dibuja a la serpiente
void Serpiente::dibujar()
{
    for(int i = 1 ; i < tam ; i++)
    {
        gotoxy(cuerpo_serpiente[i][0], cuerpo_serpiente[i][1]);
        cout<<"o"<<endl;
    }

}

void Serpiente::borrar()
{
    gotoxy(cuerpo_serpiente[n][0], cuerpo_serpiente[n][1]);
    cout<<" "<<endl;
}

void Serpiente::actualizar()
{
   while(tecla != 'q' && gameOver())
 {
    borrar();
    guardar_posicion();
    dibujar();
    Comida();
    Puntos_comida();
    controles();

    if(direccion==1){  y--;}
    if(direccion==2){  y++;}
    if(direccion==3){  x--;}
    if(direccion==4){  x++;}

    gotoxy(xc,yc);
    cout<<"x"<<endl;
    Sleep(velocidad);
 }
}

//Funcion que cambia la velocidad de la serpiente cuando come
void Serpiente::cambiar_velocidad()
{
    if(puntos == h*20)
    {
        velocidad -= 10;
        h++;
    }
}

//Funcion de la comida de la serpiente
void Serpiente::Comida()
{
    if(x == xc && y == yc)
    {
        xc=(rand()%73)+4;
        yc=(rand()%19)+4;

        tam++;
        puntos += 10;

        cambiar_velocidad();
    }
}

//Puntos que gana la serpiente cuando come
void Serpiente::Puntos_comida()
{
    gotoxy(3,1);
    cout<<"Puntos Ganados:"<<puntos<<endl;
}

//Funcion que controla  el gameover de la colision de la serpiente contra el tablero o a si mismo
bool Serpiente::gameOver()
{
    if(y == 3 || y == 23|| x == 2 || x == 77) return false;
    for(int j = tam-1;j > 0; j--)
    {
        if(cuerpo_serpiente[j][0] == x && cuerpo_serpiente[j][1] == y)
        return false;

    }
    return true;
}
