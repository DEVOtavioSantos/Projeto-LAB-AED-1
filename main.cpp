//Includes
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
<<<<<<< Updated upstream

//Defines de Criação de tela
#define LarguraTela 1024
#define AlturaTela 576
#define Title "Atari-Breakout Em C de Arthur Melo Vieira e Otavio Morais Santos"

//Defines da Raquete
#define Tam_Raquete 100
#define Cima_Raquete 550
#define Abaixo_Raquete 560

//Defines da bola
#define Tam_Bola 15
#define Vel_bola 2


void CentralizarCanvas(int monitorX, int monitorY);

void DesenharRaquete();
void DesenhaBola();

int main()
{
    //A janela abrira ao centro da tela
    int monitorX, monitorY;
    monitorX = (getmaxwidth()/2) - (LarguraTela/2);
    monitorY = (getmaxheight()/2) - (AlturaTela/2);



    initwindow(LarguraTela,AlturaTela, Title,monitorX,monitorY);
=======
#include <dos.h>
#include <windows.h>

#define larguraTela 800
#define alturaTela 600


int main()
{
    initwindow(larguraTela,alturaTela,"Teste");
>>>>>>> Stashed changes
    int sizeX = getmaxx(), sizeY = getmaxy();

    while(!kbhit())
    {
<<<<<<< Updated upstream
        DesenharRaquete();
        DesenhaBola();
    }
    closegraph();
    return 0;
=======
        setfillstyle(1,1);
        bar(sizeX/2,(sizeY/2)+200,(sizeX/2)+100,(sizeY/2)+250);

        int Xmouse = mousex(), Ymouse = mousey();


        getmouseclick(WM_LBUTTONDOWN, Xmouse, Ymouse);


            if (Xmouse > sizeX/2 && Xmouse < (sizeX/2)+100 )
            {
                if (Ymouse > (sizeY/2)+200 && Ymouse < (sizeY/2)+250  )
                {

                    outtextxy(20,10,"Fell");


                }

            }
        }

closegraph();
return 0;
>>>>>>> Stashed changes
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

void DesenhaBola()
{
    int x=512, y = 288;
    fillellipse(x,y,Tam_Bola, Tam_Bola);







}

void CentralizarCanvas(int monitorX, int monitorY)
{
    monitorX = (getmaxwidth()/2) - (LarguraTela/2);
    monitorY = (getmaxheight()/2) - (AlturaTela/2);
}
