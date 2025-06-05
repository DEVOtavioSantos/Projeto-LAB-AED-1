#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#define tamanho 50

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
    initwindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Tester",10,10);
    int sizeX = getmaxx(), sizeY = getmaxy();



    do
    {
        int xmouse, ymouse;



        getmouseclick(WM_LBUTTONDOWN, xmouse, ymouse);



            readimagefile("joao.jpg",xmouse-20,ymouse-15,xmouse+20,ymouse+20);

                setcolor(RED);


        rectangle(sizeX/2,sizeY/2,(sizeX/2)+tamanho,(sizeY/2)+tamanho);


        if (xmouse > sizeX/2 && xmouse  < (sizeX/2)+tamanho)
        {
            if (ymouse > sizeY/2 && ymouse <(sizeY/2)+tamanho)
            {
                setcolor(RED);
                outtextxy(10,10,"Acertou");
            }
        }




    }while(!kbhit());

    closegraph();

    return 0;
}
