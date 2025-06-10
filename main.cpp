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

//Defines da bola
#define Tam_Bola 15
#define Vel_bola 8

//defines dos tijolos
#define Qtd_Linha 4
#define Qtd_Coluna 6
#define  Tijolo_Largura 150
#define Tijolo_Altura 40
#define Tijolo_gap 15
#define tijolo_topo 60

//Variaveis grobais da bola

int tijolo[Qtd_Linha][Qtd_Coluna];
int bolaX = 512, bolaY = 288,bolaDX = Vel_bola,bolaDY = Vel_bola;

//Variaveis Grobais do Player
int vida;
int pontos;

//Fim das Variaveis Grobais

void DesenharRaquete();
void DesenhaBola();
void DesenhaTijolo();

int main()
{
    //A janela abrira ao centro da tela
    int monitorX, monitorY;
    monitorX = (getmaxwidth()/2) - (LarguraTela/2);
    monitorY = (getmaxheight()/2) - (AlturaTela/2);



    initwindow(LarguraTela,AlturaTela, Title,monitorX,monitorY);

    int sizeX = getmaxx(), sizeY = getmaxy();

    while(!kbhit())
    {

        DesenharRaquete();
        DesenhaBola();
        DesenhaTijolo();

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
    delay(35);
    cleardevice();

}

void DesenhaBola()
{

    fillellipse(bolaX,bolaY,Tam_Bola, Tam_Bola);

    bolaX += bolaDX;
    bolaY += bolaDY;


    if(bolaX - Tam_Bola <= 0 || bolaX + Tam_Bola >= LarguraTela)
    {
        bolaDX = -bolaDX;
    }

    if (bolaY - Tam_Bola <=0)
    {
        bolaDY = -bolaDY;
        bolaY = Tam_Bola +1;
    }

    if (bolaY - Tam_Bola >= AlturaTela)
    {
        setcolor(RED);
        settextstyle(4,HORIZ_DIR, 4);
        outtextxy(LarguraTela/2,AlturaTela/2, "Game Over");
    }

    if(bolaX >= mousex()-Tam_Raquete && bolaX <= mousex()+ Tam_Raquete)
    {
        if((bolaY + Tam_Bola)> Cima_Raquete && (bolaY = Tam_Bola) <= Cima_Raquete+(Cima_Raquete-Abaixo_Raquete) )
        {
            bolaY = Cima_Raquete - Tam_Bola - 1;
            bolaDY = -bolaDY;
        }
    }
}


void DesenhaTijolo()
{

    for (int l=0;l<Qtd_Linha;l++)
    {
        for (int c =0;c<Qtd_Coluna;c++)
        {

            tijolo[l][c] = 1;
            if (!tijolo[l][c])
            {
                continue;
            }



            int x = c *(Tijolo_Largura+ Tijolo_gap) + Tijolo_gap;
            int y = tijolo_topo + l * (Tijolo_Altura + Tijolo_gap);

            setfillstyle(1,RED);
            bar(x,y,x+Tijolo_Largura,y +Tijolo_Altura);
            if(bolaX + Tam_Bola > x-1 && bolaX - Tam_Bola < x + Tijolo_Largura +1 && bolaY + Tam_Bola > y+1 && bolaY - Tam_Bola < y + Tijolo_Altura+1)
            {
                tijolo[l][c] = 0;

                bolaDY = -bolaDY;


            }


        }
    }

}


