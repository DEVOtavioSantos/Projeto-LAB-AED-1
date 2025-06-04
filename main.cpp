#include <graphics.h>
#include <conio.h>
#include <iostream>

int main() {
    int gd = DETECT, gm;
    initwindow(100,200,"Teste",10,10);

   
    outtextxy(10, 50, (char*)"Teste");
    
    
    getch(); // Aguarda tecla
    closegraph();
    return 0;
}
