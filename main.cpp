#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#define tamanho 50

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

int main()
{
    initwindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Tester",10,10);//Cria uma janela
    int sizeX = getmaxx(), sizeY = getmaxy();//Define variaveis referente ao tamanho da janela



    do
    {
        int xmouse, ymouse;



        while(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);
            readimagefile("joao.jpg",xmouse-20,ymouse-15,xmouse+20,ymouse+20);
            delay(100);
            cleardevice();

        }



        setcolor(RED);
        rectangle(sizeX/2,sizeY/2,(sizeX/2)+tamanho,(sizeY/2)+tamanho);

    //aqui reconhece onde o mouse clicou
        if (xmouse > sizeX/2 && xmouse  < (sizeX/2)+tamanho)
        {
            if (ymouse > sizeY/2 && ymouse <(sizeY/2)+tamanho)
            {
                setcolor(RED);
                outtextxy(sizeX/2, (sizeY/2)-200,"Acertou");






            }

        }





    }while(!kbhit());

    closegraph();

    return 0;
}
