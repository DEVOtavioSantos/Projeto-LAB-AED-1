#include <graphics.h>


int main() {
    int MidX, Midy,Xmouse, ymouse;
    initwindow(1024,576,"Teste",10,10);


    MidX = getmaxx() /2 ;
    Midy = getmaxy() /2;

    outtextxy(MidX, Midy-200,"Acerte o pato");
    do
    {

        Xmouse = mousex();
        ymouse = mousey();





    }while(!kbhit());



    getch();
    closegraph();

    return 0;
}
