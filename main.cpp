#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
    initwindow(1024,576,"Teste",10,10);
    int x = getmaxx(), y = getmaxy(), midy = getmaxy()/2 ;

    outtextxy(x/2,midy -200, "Bem vindo ao Jogo do pato");





    do
    {
        int xmouse = mousex(), ymouse = mousey();
        circle(xmouse,ymouse, 10);

    }
    while(!kbhit());
}
