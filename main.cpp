//Includes
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

//Defines de Criação de tela
#define LarguraTela 1024
#define AlturaTela 576
#define Title "Atari-Breakout Em C de Arthur Melo Vieira e Otavio Morais Santos"

//Defines da Raquete
#define Tam_Raquete 100
#define Cima_Raquete 550
#define Abaixo_Raquete 560


void DesenharRaquete();

int main()
{
    initwindow(LarguraTela,AlturaTela, Title);
    int sizeX = getmaxx(), sizeY = getmaxy();

    while(!kbhit())
    {
        DesenharRaquete();
    }
    closegraph();
    return 0;
}


void DesenharRaquete()
{
    int Xmouse = mousex(), Ymouse = mousey();
    int Esq_raquete = (Xmouse -Tam_Raquete), Dir_Raquete = (Xmouse + Tam_Raquete);

    setfillstyle(1,3);
    bar(Esq_raquete,Cima_Raquete,Dir_Raquete,Abaixo_Raquete);
    delay(1);
    cleardevice();

}
