#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

extern "C" {
    #include <graphics.h>
}

int main() {
    initwindow(1024, 576, "Teste", 10, 10);

    int x = getmaxx();
    int y = getmaxy();
    int midy = y / 2;

    char texto[] = "Bem vindo ao Jogo do pato";
    outtextxy(x / 2, midy - 200, texto);

    // Loop até pressionar uma tecla
    do {
        int xmouse = mousex();
        int ymouse = mousey();
        cleardevice(); // Limpa a tela para não deixar rastros
        outtextxy(x / 2, midy - 200, texto); // Redesenha
    }while(!kbhit());
}