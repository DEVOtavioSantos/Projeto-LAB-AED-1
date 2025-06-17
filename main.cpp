//Includes
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <string.h>


//Defines de Criação de tela
#define LarguraTela 800
#define AlturaTela 600
#define Title "Atari-Breakout Em C de Arthur Melo Vieira e Otavio Morais Santos"

//Defines da Raquete
#define Tam_Raquete 100
#define Cima_Raquete 550
#define Abaixo_Raquete 560

//Defines da bola
#define Tam_Bola 15
#define Vel_bola 10

//defines dos tijolos
#define Qtd_Linha 4
#define Qtd_Coluna 4
#define  Tijolo_Largura 150
#define Tijolo_Altura 40
#define Tijolo_gap 15
#define tijolo_topo 60

//Variaveis grobais da bola

int tijolo[Qtd_Linha][Qtd_Coluna];
int bolaX = 512, bolaY = 288,bolaDX = Vel_bola,bolaDY = Vel_bola;

//Variaveis Grobais do Player
int vida;
int pontos = 0;
int gameRunning;

//Fim das Variaveis Grobais

void DesenharRaquete();
void DesenhaBola();
void DesenhaTijolo();
void geratijolos();
void ValidaColisaoBola();
void ValidaColisaoComRaquete();
void EndGame();

int main()
{
    //A janela abrira ao centro da tela
    int monitorX, monitorY;
    monitorX = (getmaxwidth()/2) - (LarguraTela/2);
    monitorY = (getmaxheight()/2) - (AlturaTela/2);

    char texto[50];

    initwindow(LarguraTela,AlturaTela, Title,monitorX,monitorY);

    int sizeX = getmaxx(), sizeY = getmaxy();

    geratijolos();
    while(!gameRunning)
    {

        DesenhaTijolo();
        DesenhaBola();
        ValidaColisaoBola();
        ValidaColisaoComRaquete();
        DesenharRaquete();
        delay(40);
        cleardevice();
        EndGame();


        sprintf(texto,"Onde a bola está: X: %d | Y: %d | Pontos: %d", bolaX,bolaY,pontos);
        settextstyle(2,HORIZ_DIR, 8);
        outtextxy(10,10,texto);


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
}

void DesenhaBola()
{
    setcolor(BLUE);
    setfillstyle(1,3);
    fillellipse(bolaX,bolaY,Tam_Bola, Tam_Bola);



    bolaX -= bolaDX;
    bolaY += bolaDY;
}
void ValidaColisaoBola()
{
    if(bolaX - Tam_Bola <= 1 || bolaX + Tam_Bola >= LarguraTela)
    {
        bolaDX = -bolaDX;
        Beep(440,100);
    }

    if (bolaY - Tam_Bola <=0)
    {
        bolaDY = -bolaDY;
        bolaY = Tam_Bola +1;
        Beep(440,100);
    }

    if (bolaY - Tam_Bola > AlturaTela +Tam_Bola)
    {
        char GameOver[10] = "Game Over";
        setcolor(RED);
        settextstyle(4,HORIZ_DIR, 4);
        outtextxy(LarguraTela/2,AlturaTela/2, GameOver);
        getch();
        gameRunning = 1;

    }


}

void ValidaColisaoComRaquete()
{
    // Colisão com centro a esquerda
    if(bolaX <= mousex() && bolaX >= mousex()-(Tam_Raquete/2))
    {
        if((bolaY + Tam_Bola)> Cima_Raquete && (bolaY - Tam_Bola) <= Cima_Raquete+(Cima_Raquete-Abaixo_Raquete) )
        {
            bolaY = Cima_Raquete - Tam_Bola - 1;
            bolaDY = -bolaDY;
            bolaDX = -bolaDX -2;
            Beep(440,100);
        }
    }

    //Colisão com centro a Direita
    if(bolaX >= mousex()&& bolaX <= mousex()+ (Tam_Raquete/2))
    {
        if((bolaY + Tam_Bola)> Cima_Raquete && (bolaY - Tam_Bola) <= Cima_Raquete+(Cima_Raquete-Abaixo_Raquete) )
        {
            bolaY = Cima_Raquete - Tam_Bola - 1;
            bolaDY = -bolaDY;
            bolaDX = +bolaDX +2;

            Beep(440,100);
        }
    }

    //Colisão com a ponta esquerda
    if(bolaX < mousex() - (Tam_Raquete/2) && bolaX >= mousex() - Tam_Raquete)
    {
        if((bolaY + Tam_Bola)> Cima_Raquete && (bolaY - Tam_Bola) <= Cima_Raquete+(Cima_Raquete-Abaixo_Raquete) )
        {
            bolaY = Cima_Raquete - Tam_Bola - 1;
            bolaDY = -bolaDY;
            bolaDX = -bolaDX -4;
            Beep(440,100);
        }
    }



    //colisão com a ponta direita
    if(bolaX > mousex() + (Tam_Raquete/2) &&  bolaX < mousex() + Tam_Raquete)
    {
        if((bolaY + Tam_Bola)> Cima_Raquete && (bolaY - Tam_Bola) <= Cima_Raquete+(Cima_Raquete-Abaixo_Raquete) )
        {
            bolaY = Cima_Raquete - Tam_Bola - 1;
            bolaDY = -bolaDY;
            bolaDX = +bolaDX +2;
            Beep(440,100);
        }
    }

    //colisao meio
    if (bolaX == mousex())
    {
        if((bolaY + Tam_Bola)> Cima_Raquete && (bolaY - Tam_Bola) <= Cima_Raquete+(Cima_Raquete-Abaixo_Raquete) )
        {
            bolaY = Cima_Raquete - Tam_Bola - 1;
            bolaDY = -bolaDY;
            Beep(440,100);
        }
    }

}






void DesenhaTijolo()
{

    for (int l=0;l<Qtd_Linha;l++)
    {
        for (int c =0;c<Qtd_Coluna;c++)
        {


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


                bolaDY = -bolaDY;
                bolaDX = -bolaDX;
                tijolo[l][c] = 0;
                pontos++;
                Beep(440,100);
                return;



            }


        }
    }

}

void geratijolos()
{

    for (int l =0; l<Qtd_Linha;l++)
    {
        for(int c =0; c< Qtd_Coluna;c++)
        {
            tijolo[l][c] = 1;
        }
    }
}

void EndGame()
{
    if (pontos >= (Qtd_Linha * Qtd_Coluna))
    {
        char Parabens[12] = "Você Ganhou";
        char pressione[35] = "Pressione qualquer tecla para sair";

        gameRunning =1;
        settextstyle(4,HORIZ_DIR, 4);
        outtextxy(LarguraTela/2-(strlen(Parabens)/2), AlturaTela/2,Parabens);
        delay(1000);
        settextstyle(4,HORIZ_DIR, 2);
        outtextxy(LarguraTela /2-(strlen(pressione)/2), (AlturaTela/2)+100,pressione);
        getch();

    }
}
