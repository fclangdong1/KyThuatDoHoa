#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include <string.h>
#include "Menu.h">
#include "Draw.h"

using namespace std;

int main(){
    setbkcolor(12);
    int x,y;
    initwindow(WIDTH,HEIGHT);
    bar(301,2,1000,698);
    veGridPixel();
    veTTD();
    veKhungGD();
	mainMenu();
    //menu3D();
    //giaoDienSuriken();
    //drawNon3D(999, 1200, 105);
    //elipMidpoint(650, 350, 100, 50, 0);
    //getch();
	cleardevice();
    closegraph();
}
