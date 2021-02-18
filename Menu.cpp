#include "Menu.h">
#include "Draw.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<cstring>
#include<iostream>
using namespace std;

void veTTD3D(){
	int maxz = 999;
	int maxy = HEIGHT;
	int midz = (WIDTH - 50) / 2; 
	int midy = HEIGHT / 2; 
	line(midz, midy, midz, 0);				// truc Oz
	line(maxz-7, midy-3, maxz, midy);		// mui ten
	line(maxz-7, midy+3, maxz, midy);
	line(midz, midy, maxz, midy);				// truc Oy
	line(midz-3, 7, midz, 0);				// mui ten
	line(midz+3, 7, midz, 0);
	line(midz,midy,340,maxy-40);					// truc Ox
	line(340,maxy-40,340,maxy-50);					//Mui ten
	line(340,maxy-40,350,maxy-40);
	outtextxy(310, 630, "Y");
	outtextxy(620, 5, "Z");
	outtextxy(970, 365, "X");					
}

void inputNumber(int &giaTri, int k, int start){
	char ch[3];
	while(1){
		char c= getch();
		if(c==ENTER&giaTri!=0) break;
		if(c==ENTER&giaTri == 0){
			outtextxy(k, start, "0");
			break;
		}
//		if (GetAsyncKeyState(VK_ESCAPE));
//		if(c==BACKSPACE) {
//			giaTriX=giaTriX/10;
//			if(giaTriX!=0) outtextxy(60, 350, "123");cout<<giaTriX; cout<<" ";
//			if(giaTriX!=0) cout<<giaTriX;
//		}
		if (c>47&&c<58){
			if(giaTri < 100){
				giaTri= giaTri*10 + c-48;
				sprintf(ch, "%d", giaTri);
				outtextxy(k, start, ch);
			}
		}		
	}
}

void veButton(int small, int big, int start){
	setcolor(start);
	line(4, small, 4, big);
	line(4, small, 291, small);
	line(3, small - 1, 3, big - 1);
	line(3, small - 1, 290, small - 1);
	setcolor(12);
}

void veInput(int small, int big, int start){
	setcolor(start);
	line(57, small, 57, big);
	line(57, big, 229, big);
	line(229, big, 229, small);
	line(229, small, 57, small);
	
	line(56, small - 1, 56, big - 1);
	line(56, big - 1, 228, big - 1);
	line(228, big - 1, 228, small - 1);
	line(228, small - 1, 56, small - 1);
	
	line(112, small - 1 , 112, big - 1);
	line(170, small - 1 , 170, big - 1);
	setcolor(12);
}

void veTTD(){
	//goc toa do (0,0) -> (650, 350)
	setcolor(4);
	int maxx = 999;
	int maxy = HEIGHT;
	int midx = (WIDTH - 50) / 2; 
	int midy = HEIGHT / 2; 
	line(301, midy, maxx, midy);				// truc hoanh
	line(maxx-7, midy-3, maxx, midy);		// mui ten
	line(maxx-7, midy+3, maxx, midy);
	line(midx, 0, midx, maxy);				// truc tung
	line(midx-3, 7, midx, 0);				// mui ten
	line(midx+3, 7, midx, 0);
	setcolor(12);
}

void veGridPixel(){
	setcolor(1);
	int maxx = 1000;
	int maxy = HEIGHT; 
	for(int i = 1; i < 140; i++){
//		if(i % 4 == 0){
//			setcolor(0);
//			line(300, i*5, maxx, i*5);
//			setcolor(1);
//		}else{
			line(300, i*5, maxx, i*5);
	//	}	
	}
	for(int i = 1; i < 140; i++){
//		if(i % 4 == 0){
//			setcolor(0);
//			line(300 + i*5, 2, 300 + i*5, maxy - 2);
//			setcolor(1);
//		}else{
			line(300 + i*5, 2, 300 + i*5, maxy - 2);
		//}	
	}
	setcolor(12);
}

void xoaMenu(){
	for(int i = 0; i < 580; i++){
		outtextxy(2, 80 + i, "                                    ");	
	}
}

void putPixel(int x, int y, int color){
	int a, b;
	int modA = x % 5;
	int modB = y % 5;
	if(modA == 0) a = x;
	if(modB == 0) b = y;
	if(modA == 1 || modA == 2){
		a = x - modA;
	}
	if(modA == 3 || modA == 4){
		a = x - modA + 5;
	}
	if(modB == 1 || modB == 2){
		b = y - modB;
	}
	if(modB == 3 || modB == 4){
		b = y - modB + 5;
	}
	for(int i = b - 3; i <= b + 3; i++){
		if(i == (b - 3) || i == (b + 3)) putpixel(a, i, color);
		if(i == (b - 2) || i == (b + 2)){
			for(int j = a - 1; j <= a + 1; j++){
				putpixel(j, i, color);
			}	
		}
		if(i == (b - 1) || i == (b + 1)){
			for(int j = a - 2; j <= a + 2; j++){
				putpixel(j, i, color);
			}
		}
		if(i == b){
			for(int j = a - 3; j <= a + 3; j++){
				putpixel(j, i, color);
			}
		}
	}
}

void delPixel(int x, int y, int color){
	int a, b;
	int modA = x % 5;
	int modB = y % 5;
	if(modA == 0) a = x;
	if(modB == 0) b = y;
	if(modA == 1 || modA == 2){
		a = x - modA;
	}
	if(modA == 3 || modA == 4){
		a = x - modA + 5;
	}
	if(modB == 1 || modB == 2){
		b = y - modB;
	}
	if(modB == 3 || modB == 4){
		b = y - modB + 5;
	}
	for(int i = b - 3; i <= b + 3; i++){
		if(i == (b - 3) || i == (b + 3)) putpixel(a, i, 1);
		if(i == (b - 2) || i == (b + 2)){
			for(int j = a - 1; j <= a + 1; j++){
				if(j == a){
					putpixel(j, i, 1);
				}
				else{
					putpixel(j, i, color);
				}
			}	
		}
		if(i == (b - 1) || i == (b + 1)){
			for(int j = a - 2; j <= a + 2; j++){
				if(j == a){
					putpixel(j, i, 1);
				}
				else{
					putpixel(j, i, color);
				}
			}
		}
		if(i == b){
			for(int j = a - 3; j <= a + 3; j++){
				putpixel(j, i, 1);
			}
		}
	}
}

void veKhungGD(){
	line(1000, 2, 1000, HEIGHT - 2);
	line(1002, 2, 1002, HEIGHT - 2);
	line(298, 2, 298, HEIGHT - 2);
	line(300, 2, 300, HEIGHT - 2);
	settextstyle(1, HORIZ_DIR, 1);
	outtextxy(1015, 5, "== INFORMATION =="); // chu 10px
	outtextxy(60, 5, "== MENU ==");
	line(1002,30,WIDTH,30);
	line(0,30,297,30);
}

void mainMenu(){
	bool flag1 = false;
	settextstyle(1, HORIZ_DIR, 1);
	while(1){
		bool flag = false;
		// option 1
		veButton(108, 132, 12);
		outtextxy(7, 110, "         DRAW 2D");
		// option 2
		veButton(148, 172, 12);
		outtextxy(7, 150, "         DRAW 3D");
		// option 2
		veButton(188, 212, 12);
		outtextxy(7, 190, "        EFFECT 2D");
		//nút BACK		
		veButton(650, 674, 12);
		outtextxy(7, 652, "           EXIT");
		int x, y;
		while (1){
	        delay(0.0001);
		    if(ismouseclick(WM_LBUTTONDOWN)){
		        getmouseclick(WM_LBUTTONDOWN, x, y);
	    	    if(x >= 4 && x <= 291 && y >= 108 && y <= 132){
	    	    	veButton(108, 132, 9);
	    	    	setcolor(9);
					outtextxy(7, 110, "         DRAW 2D");
					delay(150);
					veButton(108, 132, 12);
					outtextxy(7, 110, "         DRAW 2D");
	        	   	xoaMenu();
	           		menu2D();
	           		flag = true;
				}
				if(x >= 4 && x <= 291 && y >= 148 && y <= 172){
					veButton(148, 172, 9);
					setcolor(9);
					outtextxy(7, 150, "         DRAW 3D");
					delay(150);
					veButton(148, 172, 12);
					outtextxy(7, 150, "         DRAW 3D");
	        	   	xoaMenu();
	        	   	bar(301,2,999,698);
					veGridPixel();
	        	   	veTTD3D();
					menu3D();
					flag = true;
				}
				if(x >= 4 && x <= 291 && y >= 188 && y <= 212){
					veButton(188, 212, 9);
					setcolor(9);
					outtextxy(7, 190, "        EFFECT 2D");
					delay(150);
					veButton(188, 212, 12);
					outtextxy(7, 190, "        EFFECT 2D");
	        	   	xoaMenu();
					menuTrans2D();
					flag = true;
				}
				if(x >= 4 && x <= 291 && y >= 650 && y <= 674){
					veButton(650, 674, 9);
					setcolor(9);
					outtextxy(7, 652, "           EXIT");
					delay(150);
					veButton(650, 674, 12);
					outtextxy(7, 652, "           EXIT");
        	   		xoaMenu();
        	   		flag = true;
           			flag1 = true;
				}
	    	}
	    	if(flag == true) break;
		}
		if(flag1 == true) break;
	}
}

void menu2D(){
	settextstyle(1, HORIZ_DIR, 1);
	// option 1
	veButton(108, 132, 12);
	outtextxy(7, 110, "            POINT");
	// option 2
	veButton(148, 172, 12);
	outtextxy(7, 150, "             LINE");
	// option 3
	veButton(188, 212, 12);
	outtextxy(7, 190, "         SQUARE");
	// option 4
	veButton(228, 252, 12);
	outtextxy(7, 230, "      RECTANGLE");
	// option 5
	veButton(268, 292, 12);
	outtextxy(7, 270, "       TRIANGLE");
	// option 6
	veButton(308, 332, 12);
	outtextxy(7, 310, "          CIRCLE");
	// option 7
	veButton(348, 372, 12);
	outtextxy(7, 350, "         ELLIPSE");
	// option 8
	veButton(388, 412, 12);
	outtextxy(7, 390, "PARALLELOGRAM");
	
	//nút CLEAR
	veButton(610, 634, 12);
	outtextxy(7, 612, "          CLEAR");
	//nút BACK
	veButton(650, 674, 12);
	outtextxy(7, 652, "           BACK");
	int x, y;
	bool flag1;
	bool flag = false;
	while (1){
		flag1 = false;
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	        getmouseclick(WM_LBUTTONDOWN, x, y);
			if(x >= 4 && x <= 292 && y >= 108 && y <= 132){
				veButton(108, 132, 9);
				setcolor(9);
				outtextxy(7, 110, "            POINT");
        	   	drawPoint(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 148 && y <= 172){
				veButton(148, 172, 9);
				setcolor(9);
				outtextxy(7, 150, "             LINE");
        	   	drawLine(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 188 && y <= 212){
				veButton(188, 212, 9);
				setcolor(9);
				outtextxy(7, 190, "         SQUARE");
        	   	drawHV(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 228 && y <= 252){
				veButton(228, 252, 9);
				setcolor(9);
				outtextxy(7, 230, "      RECTANGLE");
        	   	drawHCN(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 268 && y <= 292){
				veButton(268, 292, 9);
				setcolor(9);
				outtextxy(7, 270, "       TRIANGLE");
        	   	drawTamGiac(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 308 && y <= 332){
				veButton(308, 332, 9);
				setcolor(9);
				outtextxy(7, 310, "          CIRCLE");
        	   	drawHinhTron(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 348 && y <= 372){
				veButton(348, 372, 9);
				setcolor(9);
				outtextxy(7, 350, "         ELLIPSE");
        	   	drawElips(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 388 && y <= 412){
				veButton(388, 412, 9);
				setcolor(9);
				outtextxy(7, 390, "PARALLELOGRAM");
        	   	drawHBH(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 610 && y <= 634){
				veButton(610, 634, 9);
	        	setcolor(9);
				outtextxy(7, 612, "          CLEAR");
				delay(150);
				veButton(610, 634, 12);
				outtextxy(7, 612, "          CLEAR");
        	   	clearPoint();
			}
			if(x >= 4 && x <= 291 && y >= 650 && y <= 674){
        	   	veButton(650, 674, 9);
    	    	setcolor(9);
				outtextxy(7, 652, "           BACK");
				delay(150);
				veButton(650, 674, 12);
				outtextxy(7, 652, "           BACK");
        	   	xoaMenu();
           		flag = true;
			}
    	}
    	if(flag == true) break;
	}
}

void menu3D(){
	int giaTriX = 0;
	int giaTriY = 0;
	int giaTriZ = 0;
	settextstyle(1, HORIZ_DIR, 1);
	setcolor(15);
	outtextxy(7, 110, "MODEL 1: ");
	setcolor(14);
	outtextxy(7, 150, "          (X,Y,Z)");
	setcolor(12);
	veInput(188, 212, 8);
	// option 3
	veButton(228, 252, 12);
	outtextxy(7, 230, "           DRAW");
	// option 4
	setcolor(15);
	outtextxy(7, 270, "MODEL 2: ");
	setcolor(14);
	outtextxy(7, 310, "          (X,Y,Z)");
	setcolor(12);
	veInput(348, 372, 8);
	// option 5
	veButton(388, 412, 12);
	outtextxy(7, 390, "           DRAW");
	//nút CLEAR
	veButton(610, 634, 12);
	outtextxy(7, 612, "          CLEAR");
	//nút BACK
	veButton(650, 674, 12);
	outtextxy(7, 652, "           BACK");
	int x, y;
	bool flag1;
	bool flag = false;
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	        getmouseclick(WM_LBUTTONDOWN, x, y);
	        if(x >= 56 && x <= 228 && y >= 188 && y <= 212){
	        	veInput(188, 212, 14);
	        	setcolor(11);
				inputNumber(giaTriX, 60, 190);
				inputNumber(giaTriY, 118, 190);
				inputNumber(giaTriZ, 176, 190);
				setcolor(12);
				veInput(188, 212, 10);
				cout << giaTriX<< giaTriY<< giaTriZ; 
			}
			if(x >= 4 && x <= 292 && y >= 228 && y <= 252){
				veButton(228, 252, 9);
				setcolor(9);
				outtextxy(7, 230, "           DRAW");
				delay(150);
				veButton(228, 252, 12);
				outtextxy(7, 230, "           DRAW");
        	   	drawHLP(giaTriX + 1105, giaTriY + 1286, giaTriZ + 105);
			}
			if(x >= 56 && x <= 228 && y >= 348 && y <= 372){
				veInput(348, 372, 14);
	        	setcolor(11);
				inputNumber(giaTriX, 60, 350);
				inputNumber(giaTriY, 118, 350);
				inputNumber(giaTriZ, 176, 350);
				setcolor(12);
				veInput(348, 372, 10);
				cout << endl << giaTriX<< giaTriY<< giaTriZ;
			}
			if(x >= 4 && x <= 292 && y >= 388 && y <= 412){
				veButton(388, 412, 9);
				setcolor(9);
				outtextxy(7, 390, "           DRAW");
				delay(150);
				veButton(388, 412, 12);
				outtextxy(7, 390, "           DRAW");
        	   	drawNon3D(giaTriX + 1105, giaTriY + 1286, giaTriZ + 105);
			}
	        if(x >= 4 && x <= 292 && y >= 610 && y <= 634){
	        	veButton(610, 634, 9);
	        	setcolor(9);
				outtextxy(7, 612, "          CLEAR");
				delay(150);
				veButton(610, 634, 12);
				outtextxy(7, 612, "          CLEAR");
        	   	bar(301,2,999,698);
				veGridPixel();
	           	veTTD3D();
        	   	outtextxy(0, 190,"                             ");
				outtextxy(0, 350,"                             ");
        	   	veInput(348, 372, 8);
        	   	veInput(188, 212, 8);
        	   	giaTriX = 0;
				giaTriY = 0;
				giaTriZ = 0;
			}
    	    if(x >= 4 && x <= 291 && y >= 650 && y <= 674){
    	    	veButton(650, 674, 9);
    	    	setcolor(9);
				outtextxy(7, 652, "           BACK");
				delay(150);
				veButton(650, 674, 12);
				outtextxy(7, 652, "           BACK");
        	   	xoaMenu();
        	   	bar(301,2,999,698);
				veGridPixel();
	        	veTTD();
           		flag = true;
			}
    	}
    	if(flag == true) break;
	}
}

void menuTrans2D(){
	settextstyle(1, HORIZ_DIR, 1);
	setcolor(15);
	outtextxy(7, 110, "MODEL 1: ");
	setcolor(12);
	// option 2
	veButton(148, 172, 12);
	outtextxy(7, 150, "           DRAW");
	// option 3
	veButton(188, 212, 12);
	outtextxy(7, 190, "          EFFECT");
	// option 4
	setcolor(15);
	outtextxy(7, 230, "MODEL 2: ");
	setcolor(12);
	// option 5
	veButton(268, 292, 12);
	outtextxy(7, 270, "           DRAW");
	// option 5
	veButton(308, 332, 12);
	outtextxy(7, 310, "          EFFECT");
	//nút STOP
	veButton(570, 594, 12);
	outtextxy(7, 572, "           STOP");
	//nút CLEAR
	veButton(610, 634, 12);
	outtextxy(7, 612, "          CLEAR");
	//nút BACK
	veButton(650, 674, 12);
	outtextxy(7, 652, "           BACK");
	int x, y;
	bool flag1;
	bool flag = false;
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	        getmouseclick(WM_LBUTTONDOWN, x, y);
	        if(x >= 4 && x <= 292 && y >= 148 && y <= 172){
				veButton(148, 172, 9);
				setcolor(9);
				outtextxy(7, 150, "           DRAW");
				delay(150);
				veButton(148, 172, 12);
				outtextxy(7, 150, "           DRAW");
        	   	drawSuriken();
			}
			if(x >= 4 && x <= 292 && y >= 188 && y <= 212){
				veButton(188, 212, 9);
				setcolor(9);
				outtextxy(7, 190, "          EFFECT");
				delay(150);
				veButton(188, 212, 12);
				outtextxy(7, 190, "          EFFECT");
        	   	effectSuriken(flag1);
			}
			if(x >= 4 && x <= 292 && y >= 268 && y <= 292){
				veButton(268, 292, 9);
				setcolor(9);
				outtextxy(7, 270, "           DRAW");
				delay(150);
				veButton(268, 292, 12);
				outtextxy(7, 270, "           DRAW");
        	   	drawThor();
			}
			if(x >= 4 && x <= 292 && y >= 308 && y <= 332){
				veButton(308, 332, 9);
				setcolor(9);
				outtextxy(7, 310, "          EFFECT");
				delay(150);
				veButton(308, 332, 12);
				outtextxy(7, 310, "          EFFECT");
        	   	effectThor();
			}
			if(x >= 4 && x <= 292 && y >= 570 && y <= 594){
	        	veButton(570, 594, 9);
	        	setcolor(9);
				outtextxy(7, 572, "           STOP");
				delay(150);
				veButton(570, 594, 12);
				outtextxy(7, 572, "           STOP");
			}
	        if(x >= 4 && x <= 292 && y >= 610 && y <= 634){
	        	veButton(610, 634, 9);
	        	setcolor(9);
				outtextxy(7, 612, "          CLEAR");
				delay(150);
				veButton(610, 634, 12);
				outtextxy(7, 612, "          CLEAR");
        	   	clearPoint();
        	   	xoaInfor();
			}
    	    if(x >= 4 && x <= 291 && y >= 650 && y <= 674){
    	    	veButton(650, 674, 9);
    	    	setcolor(9);
				outtextxy(7, 652, "           BACK");
				delay(150);
				veButton(650, 674, 12);
				outtextxy(7, 652, "           BACK");
        	   	xoaMenu();
           		flag = true;
           		xoaInfor();
			}
    	}
    	if(flag == true) break;
	}
}
