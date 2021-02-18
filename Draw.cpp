#include "Menu.h"
#include "Draw.h"
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include <string.h>
#include <cmath>
using namespace std;

double donVi[3][3];

Wing *w = new Wing[4];
Wing *w1 = new Wing[4];

Thor *t = new Thor;
Bua *b = new Bua[2];

void xoaInfor(){
	for(int i = 0; i < 580; i++){
		outtextxy(1004, 34 + i, "                                         ");	
	}
}

void roundPixel(int &x, int &y){
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
	x = a;
	y = b;
}

void clearPoint(){
	bar(301,2,999,698);
	veGridPixel();
    veTTD();
}
//ve 3D
double matran2D[2][8];
double matran12D[2][4];
Point ToaDo3D(int x,int y,int z)
{
	Point kq;
	double X,Y;
	X=x-(y/2)*cos((PI * 45) / 180);
	Y=(y/2)*cos((PI * 45) / 180)-z;
	kq.x=X;kq.y=Y;
	return kq;
}

//hinh non
void drawNon3D(int x, int y, int z){
	int bk1, bk2;
	hinhNon(x, y, z);
	bk1 = abs(matran12D[0][0] - matran12D[2][0]);
	bk2 = (bk1/2)*cos((PI * 45) / 180);
	
	elipMidpoint(matran12D[0][0], matran12D[0][1], bk1, bk2, 0, false);
	elipMidpointND(matran12D[0][0], matran12D[0][1], bk1, bk2, 15, false);
	lineMidPoint(matran12D[1][0], matran12D[1][1], matran12D[2][0], matran12D[2][1], 0, false);//AB
	lineMidPoint(matran12D[1][0], matran12D[1][1], matran12D[3][0], matran12D[3][1], 0, false);// AC
	
}
void hinhNon(int x, int y, int z){
	Point p;
	//O
	p=ToaDo3D(x, y, z);
	matran12D[0][0]=p.x;
	matran12D[0][1]=p.y;
	//A
	p=ToaDo3D(x, y, z+250);
	matran12D[1][0]=p.x;
	matran12D[1][1]=p.y;
	//B
	p=ToaDo3D(x-150, y, z);
	matran12D[2][0]=p.x;
	matran12D[2][1]=p.y;
	//C
	p=ToaDo3D(x+150, y, z);
	matran12D[3][0]=p.x;
	matran12D[3][1]=p.y;
}
// hinh lap phuong
void ToaDo3D_8D(int x,int y,int z)
{
	Point p;
	//A
	p=ToaDo3D(x, y, z);
	matran2D[0][0]=p.x;
	matran2D[0][1]=p.y;
	//B
	p=ToaDo3D(x+200, y, z);
	matran2D[1][0]=p.x;
	matran2D[1][1]=p.y;
	//C
	p=ToaDo3D(x+200, y, z+200);
	matran2D[2][0]=p.x;
	matran2D[2][1]=p.y;
	//D
	p=ToaDo3D(x, y, z+200);
	matran2D[3][0]=p.x;
	matran2D[3][1]=p.y;
	//A'
	p=ToaDo3D(x, y+200, z);
	matran2D[4][0]=p.x;
	matran2D[4][1]=p.y;
	//B'
	p=ToaDo3D(x+200, y+200, z);
	matran2D[5][0]=p.x;
	matran2D[5][1]=p.y;
	//C'
	p=ToaDo3D(x+200, y+200, z+200);
	matran2D[6][0]=p.x;
	matran2D[6][1]=p.y;
	//D'
	p=ToaDo3D(x, y+200, z+200);
	matran2D[7][0]=p.x;
	matran2D[7][1]=p.y;
}

void drawHLP(int x, int y, int z){
	ToaDo3D_8D(x, y, z);
	//lineMidPoint(matran2D[0][0], matran2D[0][1], matran2D[1][0], matran2D[1][1], 15, false);//AB
	lineHidePoints(matran2D[0][0], matran2D[0][1], matran2D[1][0], matran2D[1][1], 0);
	lineHidePoints(matran2D[3][0], matran2D[3][1], matran2D[0][0], matran2D[0][1], 0);
	lineHidePoints(matran2D[0][0], matran2D[0][1], matran2D[4][0], matran2D[4][1], 0);
	lineMidPoint(matran2D[1][0], matran2D[1][1], matran2D[2][0], matran2D[2][1], 0, false);// BC
	lineMidPoint(matran2D[2][0], matran2D[2][1], matran2D[3][0], matran2D[3][1], 0, false);//CD
	//lineMidPoint(matran2D[3][0], matran2D[3][1], matran2D[0][0], matran2D[0][1], 15, false);//DA
		
	
	lineMidPoint(matran2D[4][0], matran2D[4][1], matran2D[5][0], matran2D[5][1], 0, false);//A'B'
	lineMidPoint(matran2D[5][0], matran2D[5][1], matran2D[6][0], matran2D[6][1], 0, false);//B'C'
	lineMidPoint(matran2D[6][0], matran2D[6][1], matran2D[7][0], matran2D[7][1], 0, false);//C'D'
	lineMidPoint(matran2D[7][0], matran2D[7][1], matran2D[4][0], matran2D[4][1], 0, false);//D'A'
	
	//lineMidPoint(matran2D[0][0], matran2D[0][1], matran2D[4][0], matran2D[4][1], 15, false);//AA'
	lineMidPoint(matran2D[1][0], matran2D[1][1], matran2D[5][0], matran2D[5][1], 0, false);//BB'
	lineMidPoint(matran2D[2][0], matran2D[2][1], matran2D[6][0], matran2D[6][1], 0, false);//CC'
	lineMidPoint(matran2D[3][0], matran2D[3][1], matran2D[7][0], matran2D[7][1], 0, false);//DD'
	
}
// ma tran
void nhanMaTran(double maTran[2][3], double maTran1[2][3], double maTran2[3][3]){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			maTran[i][j] = 0;
			for(int k = 0; k < 3; k++){
				maTran[i][j] += maTran1[i][k] * maTran2[k][j];
			}
		}
	}  
}

twoPoint tinhTien(twoPoint tp, int dx, int dy){
	twoPoint tpNew;
	
	double maTran[2][3];
	double maTran1[2][3];
	double maTran2[3][3];
	
	maTran2[0][0] = 1; maTran2[0][1] = 0; maTran2[0][2] = 0;
    maTran2[1][0] = 0; maTran2[1][1] = 1; maTran2[1][2] = 0;
    maTran2[2][0] = dx; maTran2[2][1] = dy; maTran2[2][2] = 1;
    
    maTran1[0][0] = tp.x1; maTran1[0][1] = tp.y1; maTran1[0][2] = 1;
    maTran1[1][0] = tp.x2; maTran1[1][1] = tp.y2; maTran1[1][2] = 1;
    
    nhanMaTran(maTran, maTran1, maTran2);
    
    tpNew.x1 = maTran[0][0]; tpNew.y1 = maTran[0][1];
    tpNew.x2 = maTran[1][0]; tpNew.y2 = maTran[1][1];

	return tpNew;
}

twoPoint bdQuay(twoPoint tp, int a, int x, int y){
	twoPoint tpNew;
	
	double maTran[2][3];
	double maTran1[2][3];
	double maTran2[3][3];
	double maTran3[3][3];
	double maTran4[3][3];
	// ma tran duong thang
    maTran1[0][0] = tp.x1; maTran1[0][1] = tp.y1; maTran1[0][2] = 1;
    maTran1[1][0] = tp.x2; maTran1[1][1] = tp.y2; maTran1[1][2] = 1;
	// ma tran tinh tien ve toa do goc
	maTran2[0][0] = 1; maTran2[0][1] = 0; maTran2[0][2] = 0;
    maTran2[1][0] = 0; maTran2[1][1] = 1; maTran2[1][2] = 0;
    maTran2[2][0] = -x; maTran2[2][1] = -y; maTran2[2][2] = 1;    
    nhanMaTran(maTran, maTran1, maTran2);
    // ma tran quay
    double s = sin((PI * a) / 180);
    double c = cos((PI * a) / 180);
    maTran3[0][0] = c; maTran3[0][1] = s; maTran3[0][2] = 0;
    maTran3[1][0] = -1 * s; maTran3[1][1] = c; maTran3[1][2] = 0;
    maTran3[2][0] = 0; maTran3[2][1] = 0; maTran3[2][2] = 1;
    nhanMaTran(maTran1, maTran, maTran3);
    //ma tran tinh tien ve vi tri cu
    maTran4[0][0] = 1; maTran4[0][1] = 0; maTran4[0][2] = 0;
    maTran4[1][0] = 0; maTran4[1][1] = 1; maTran4[1][2] = 0;
    maTran4[2][0] = x; maTran4[2][1] = y; maTran4[2][2] = 1;
    nhanMaTran(maTran, maTran1, maTran4);
    //gan gia tri moi
    tpNew.x1 = maTran[0][0]; tpNew.y1 = maTran[0][1];
    tpNew.x2 = maTran[1][0]; tpNew.y2 = maTran[1][1];
    
	return tpNew;
}

twoPoint coGian(twoPoint tp, double sx, double sy, int x, int y){
	twoPoint tpNew;
	
	double maTran[2][3];
	double maTran1[2][3];
	double maTran2[3][3];
	double maTran3[3][3];
	double maTran4[3][3];
	// ma tran duong thang
    maTran1[0][0] = tp.x1; maTran1[0][1] = tp.y1; maTran1[0][2] = 1;
    maTran1[1][0] = tp.x2; maTran1[1][1] = tp.y2; maTran1[1][2] = 1;
    // ma tran tinh tien ve toa do goc
	maTran2[0][0] = 1; maTran2[0][1] = 0; maTran2[0][2] = 0;
    maTran2[1][0] = 0; maTran2[1][1] = 1; maTran2[1][2] = 0;
    maTran2[2][0] = -x; maTran2[2][1] = -y; maTran2[2][2] = 1;    
    nhanMaTran(maTran, maTran1, maTran2);
    // ma tran quay
    maTran3[0][0] = sx; maTran3[0][1] = 0; maTran3[0][2] = 0;
    maTran3[1][0] = 0; maTran3[1][1] = sy; maTran3[1][2] = 0;
    maTran3[2][0] = 0; maTran3[2][1] = 0; maTran3[2][2] = 1;
    nhanMaTran(maTran1, maTran, maTran3);
	// ma tran tinh tien tro lai
	maTran2[0][0] = 1; maTran2[0][1] = 0; maTran2[0][2] = 0;
    maTran2[1][0] = 0; maTran2[1][1] = 1; maTran2[1][2] = 0;
    maTran2[2][0] = x; maTran2[2][1] = y; maTran2[2][2] = 1;    
    nhanMaTran(maTran, maTran1, maTran2);
    //gan gia tri moi
    tpNew.x1 = maTran[0][0]; tpNew.y1 = maTran[0][1];
    tpNew.x2 = maTran[1][0]; tpNew.y2 = maTran[1][1];
    
	return tpNew;
}
//ve hinh 2D thu hai
//in toa do ra man hinh
void giaoDienThor(int i, int k){
	if(i == 1) outtextxy(1005, 35, "      > Thu Nho Thor <"); // tieu de
	if(i == 2) outtextxy(1005, 35, "  > Thor Quay Nguoi  <"); // tieu de
	if(i == 3) outtextxy(1005, 35, "  > Bua Thor Bay Di <"); // tieu de
	if(i == 4) outtextxy(1005, 35, "  > Bua Thor Bay Ve <"); // tieu de
	if(i == 5) outtextxy(1005, 35, "      > Thor Ban Dau <"); // tieu de
	outtextxy(1015, 65, "Hinh Tron:"); // hinh tron	
	outtextxy(1015, 125, "Diem 1:");
	outtextxy(1015, 155, "Diem 2:");
	outtextxy(1015, 185, "Diem 3:");
	outtextxy(1015, 215, "Diem 4:");
	outtextxy(1015, 245, "Diem 5:");
	outtextxy(1015, 275, "Diem 6:");
	outtextxy(1015, 305, "Diem 7:");
	if(k == 1){
		outtextxy(1015, 335, "Diem 8:");
		outtextxy(1015, 365, "Diem 9:");
		outtextxy(1015, 395, "Diem 10:");
		outtextxy(1015, 425, "Diem 11:");
		outtextxy(1015, 455, "Diem 12:");
		outtextxy(1015, 485, "Diem 13:");
		outtextxy(1015, 515, "Diem 14:");
		outtextxy(1015, 545, "Diem 15:");
	}
}

void toaDoThor(int xc, int yc, int i){
	char chx[6], chy[6];
	int x, y;
	x = xc; y = yc;
	roundPixel(x, y);
	x = x - 650;
	y = y - 350;
	sprintf(chx, "%d", x);
	sprintf(chy, "%d", y);
	//cac diem khac
	if(i == 1){
		outtextxy(1170, 125, "                 ");
		outtextxy(1160, 125, "("); outtextxy(1240, 125, ","); outtextxy(1305, 125, ")");
		outtextxy(1175, 125, chx); outtextxy(1250, 125, chy);
	}
	if(i == 2){
		outtextxy(1170, 155, "                 ");
		outtextxy(1160, 155, "("); outtextxy(1240, 155, ","); outtextxy(1305, 155, ")");
		outtextxy(1175, 155, chx); outtextxy(1250, 155, chy);
	}
	if(i == 3){
		outtextxy(1175, 185, "                 ");
		outtextxy(1160, 185, "("); outtextxy(1240, 185, ","); outtextxy(1305, 185, ")");
		outtextxy(1175, 185, chx); outtextxy(1250, 185, chy);
	}
	if(i == 4){
		outtextxy(1175, 215, "                 ");
		outtextxy(1160, 215, "("); outtextxy(1240, 215, ","); outtextxy(1305, 215, ")");
		outtextxy(1175, 215, chx); outtextxy(1250, 215, chy);
	}
	if(i == 5){
		outtextxy(1175, 245, "                 ");
		outtextxy(1160, 245, "("); outtextxy(1240, 245, ","); outtextxy(1305, 245, ")");
		outtextxy(1175, 245, chx); outtextxy(1250, 245, chy);
	}
	if(i == 6){
		outtextxy(1175, 275, "                 ");
		outtextxy(1160, 275, "("); outtextxy(1240, 275, ","); outtextxy(1305, 275, ")");
		outtextxy(1175, 275, chx); outtextxy(1250, 275, chy);
	}
	//hinh tron
	if(i == 7){
		outtextxy(1175, 65, "                 ");
		outtextxy(1160, 65, "("); outtextxy(1240, 65, ","); outtextxy(1305, 65, ")");
		outtextxy(1175, 65, chx); outtextxy(1250, 65, chy);
	}
	if(i == 8){
		outtextxy(1175, 95, "                 ");
		outtextxy(1160, 95, "("); outtextxy(1240, 95, ","); outtextxy(1305, 95, ")");
		outtextxy(1175, 95, chx); outtextxy(1250, 95, chy);
	}
	//cac diem khac
	if(i == 9){
		outtextxy(1175, 305, "                 ");
		outtextxy(1160, 305, "("); outtextxy(1240, 305, ","); outtextxy(1305, 305, ")");
		outtextxy(1175, 305, chx); outtextxy(1250, 305, chy);
	}
	//bua
	if(i == 10){
		outtextxy(1175, 335, "                 ");
		outtextxy(1160, 335, "("); outtextxy(1240, 335, ","); outtextxy(1305, 335, ")");
		outtextxy(1175, 335, chx); outtextxy(1250, 335, chy);
	}
	if(i == 11){
		outtextxy(1175, 365, "                 ");
		outtextxy(1160, 365, "("); outtextxy(1240, 365, ","); outtextxy(1305, 365, ")");
		outtextxy(1175, 365, chx); outtextxy(1250, 365, chy);
	}
	if(i == 12){
		outtextxy(1175, 395, "                 ");
		outtextxy(1160, 395, "("); outtextxy(1240, 395, ","); outtextxy(1305, 395, ")");
		outtextxy(1175, 395, chx); outtextxy(1250, 395, chy);
	}
	if(i == 13){
		outtextxy(1175, 425, "                 ");
		outtextxy(1160, 425, "("); outtextxy(1240, 425, ","); outtextxy(1305, 425, ")");
		outtextxy(1175, 425, chx); outtextxy(1250, 425, chy);
	}
	if(i == 14){
		outtextxy(1175, 455, "                 ");
		outtextxy(1160, 455, "("); outtextxy(1240, 455, ","); outtextxy(1305, 455, ")");
		outtextxy(1175, 455, chx); outtextxy(1250, 455, chy);
	}
	if(i == 15){
		outtextxy(1175, 485, "                 ");
		outtextxy(1160, 485, "("); outtextxy(1240, 485, ","); outtextxy(1305, 485, ")");
		outtextxy(1175, 485, chx); outtextxy(1250, 485, chy);
	}
	if(i == 16){
		outtextxy(1175, 515, "                 ");
		outtextxy(1160, 515, "("); outtextxy(1240, 515, ","); outtextxy(1305, 515, ")");
		outtextxy(1175, 515, chx); outtextxy(1250, 515, chy);
	}
	if(i == 17){
		outtextxy(1175, 545, "                 ");
		outtextxy(1160, 545, "("); outtextxy(1240, 545, ","); outtextxy(1305, 545, ")");
		outtextxy(1175, 545, chx); outtextxy(1250, 545, chy);
	}
}
//ve thor
void ganGiaTriThor(int x1, int y1, int x2, int y2, int k){
	//dau
	if(k == 1){
		t->dau.x1 = x1;
		t->dau.y1 = y1;
		t->dau.x2 = x2;
		t->dau.y2 = y2;
	}
	//than
	if(k == 2){
		t->than.x1 = x1;
		t->than.y1 = y1;
		t->than.x2 = x2;
		t->than.y2 = y2;
	}
	//tTrai1
	if(k == 3){
		t->tTrai1.x1 = x1;
		t->tTrai1.y1 = y1;
		t->tTrai1.x2 = x2;
		t->tTrai1.y2 = y2;
	}
	//tTrai2
	if(k == 4){
		t->tTrai2.x1 = x1;
		t->tTrai2.y1 = y1;
		t->tTrai2.x2 = x2;
		t->tTrai2.y2 = y2;
	}
	//tPhai1
	if(k == 5){
		t->tPhai1.x1 = x1;
		t->tPhai1.y1 = y1;
		t->tPhai1.x2 = x2;
		t->tPhai1.y2 = y2;
	}
	//tPhai2
	if(k == 6){
		t->tPhai2.x1 = x1;
		t->tPhai2.y1 = y1;
		t->tPhai2.x2 = x2;
		t->tPhai2.y2 = y2;
	}
	//cTrai
	if(k == 7){
		t->cTrai.x1 = x1;
		t->cTrai.y1 = y1;
		t->cTrai.x2 = x2;
		t->cTrai.y2 = y2;
	}
	//cPhai
	if(k == 8){
		t->cPhai.x1 = x1;
		t->cPhai.y1 = y1;
		t->cPhai.x2 = x2;
		t->cPhai.y2 = y2;
	}
}

void ganGiaTriBua(int x1, int y1, int x2, int y2, int i, int k){
	if(k == 1){
		b[i].cTren.x1 = x1;
		b[i].cTren.y1 = y1;
		b[i].cTren.x2 = x2;
		b[i].cTren.y2 = y2;
	}
	if(k == 2){
		b[i].cTrai.x1 = x1;
		b[i].cTrai.y1 = y1;
		b[i].cTrai.x2 = x2;
		b[i].cTrai.y2 = y2;
	}
	if(k == 3){
		b[i].cDuoi.x1 = x1;
		b[i].cDuoi.y1 = y1;
		b[i].cDuoi.x2 = x2;
		b[i].cDuoi.y2 = y2;
	}
	if(k == 4){
		b[i].cPhai.x1 = x1;
		b[i].cPhai.y1 = y1;
		b[i].cPhai.x2 = x2;
		b[i].cPhai.y2 = y2;
	}
	
}

void drawThor(){
	//thor -------------------------------------------------
	ganGiaTriThor(600, 280, 650, 280, 1);//dau
	ganGiaTriThor(600, 330, 600, 480, 2);//than
	ganGiaTriThor(600, 360, 490, 300, 3);//tay trai
	ganGiaTriThor(600, 360, 650, 455, 5);//tay phai
	ganGiaTriThor(600, 480, 540, 630, 7);//ctrai
	ganGiaTriThor(600, 480, 660, 630, 8);//cPhai
	//bua cua thor -----------------------------------------
	//than
	ganGiaTriBua(520, 295, 460, 295, 0, 1);
	ganGiaTriBua(520, 295, 520, 305, 0, 2);
	ganGiaTriBua(520, 305, 460, 305, 0, 3);
	ganGiaTriBua(460, 305, 460, 295, 0, 4);
	//dau
	ganGiaTriBua(410, 255, 460, 255, 1, 1);
	ganGiaTriBua(410, 255, 410, 345, 1, 2);
	ganGiaTriBua(410, 345, 460, 345, 1, 3);
	ganGiaTriBua(460, 345, 460, 255, 1, 4);
	
	for(int i = 0; i < 2; i++){
		//thor
		xoaInfor();
		giaoDienThor(1, 1);
		
		toaDoThor(t->than.x1, t->than.y1, 1);
		toaDoThor(t->tTrai1.x1, t->tTrai1.y1, 2);
		toaDoThor(t->tTrai1.x2, t->tTrai1.y2, 3);
		toaDoThor(t->tPhai1.x2, t->tPhai1.y2, 4);
		toaDoThor(t->than.x2, t->than.y2, 5);
		toaDoThor(t->cTrai.x1, t->cTrai.y1, 6);
		toaDoThor(t->cPhai.x1, t->cPhai.y1, 9);
		toaDoThor(t->dau.x1, t->dau.y1, 7);
		toaDoThor(t->dau.x2, t->dau.y2, 8);
		//than
		toaDoThor(b[0].cTren.x1, b[0].cTren.y1, 10);
		toaDoThor(b[0].cTrai.x2, b[0].cTrai.y2, 11);
		toaDoThor(b[0].cDuoi.x2, b[0].cDuoi.y2, 12);
		toaDoThor(b[0].cPhai.x2, b[0].cPhai.y2, 13);
		//dau
		toaDoThor(b[1].cTren.x1, b[1].cTren.y1, 14);
		toaDoThor(b[1].cTrai.x2, b[1].cTrai.y2, 15);
		toaDoThor(b[1].cDuoi.x2, b[1].cDuoi.y2, 16);
		toaDoThor(b[1].cPhai.x2, b[1].cPhai.y2, 17);
		
		lineMidPoint(t->than.x1, t->than.y1, t->than.x2, t->than.y2, 0, false);// than
		lineMidPoint(t->tTrai1.x1, t->tTrai1.y1, t->tTrai1.x2, t->tTrai1.y2, 0, false);// tay trai khuc dau
		lineMidPoint(t->tPhai1.x1, t->tPhai1.y1, t->tPhai1.x2, t->tPhai1.y2, 0, false);// tay phai khuc dau
		lineMidPoint(t->cTrai.x1, t->cTrai.y1, t->cTrai.x2, t->cTrai.y2, 0, false);// chan trai
		lineMidPoint(t->cPhai.x1, t->cPhai.y1, t->cPhai.x2, t->cPhai.y2, 0, false);// chan phai
		drawCircleMidpoint(t->dau.x1, t->dau.y1, t->dau.x2, t->dau.y2, 0, false);
		//bua
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 0, false);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 0, false);//canh phai
		
		delay(500);
		if(i == 1) break;
		lineMidPoint(t->than.x1, t->than.y1, t->than.x2, t->than.y2, 15, true);// than
		lineMidPoint(t->tTrai1.x1, t->tTrai1.y1, t->tTrai1.x2, t->tTrai1.y2, 15, true);// tay trai khuc dau
		lineMidPoint(t->tPhai1.x1, t->tPhai1.y1, t->tPhai1.x2, t->tPhai1.y2, 15, true);// tay phai khuc dau
		lineMidPoint(t->cTrai.x1, t->cTrai.y1, t->cTrai.x2, t->cTrai.y2, 15, true);// chan trai
		lineMidPoint(t->cPhai.x1, t->cPhai.y1, t->cPhai.x2, t->cPhai.y2, 15, true);// chan phai
		drawCircleMidpoint(t->dau.x1, t->dau.y1, t->dau.x2, t->dau.y2, 15, true);
		
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 15, true);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 15, true);//canh phai
		
		
		
		//thor
		t->dau = coGian(t->dau, 0.3, 0.3, 555, 425);
		t->than = coGian(t->than, 0.3, 0.3, 555, 425);
		t->tTrai1 = coGian(t->tTrai1, 0.3, 0.3, 555, 425);
		t->tPhai1 = coGian(t->tPhai1, 0.3, 0.3, 555, 425);
		t->cTrai = coGian(t->cTrai, 0.3, 0.3, 555, 425);
		t->cPhai = coGian(t->cPhai, 0.3, 0.3, 555, 425);
		
		t->dau = tinhTien(t->dau, -200, 0);
		t->than = tinhTien(t->than, -200, 0);
		t->tTrai1 = tinhTien(t->tTrai1, -200, 0);
		t->tPhai1 = tinhTien(t->tPhai1, -200, 0);
		t->cTrai = tinhTien(t->cTrai, -200, 0);
		t->cPhai = tinhTien(t->cPhai, -200, 0);
		//bua
		b[0].cTren = coGian(b[0].cTren, 0.3, 0.3, 555, 425);
		b[0].cTrai = coGian(b[0].cTrai, 0.3, 0.3, 555, 425);
		b[0].cDuoi = coGian(b[0].cDuoi, 0.3, 0.3, 555, 425);
		b[0].cPhai = coGian(b[0].cPhai, 0.3, 0.3, 555, 425);
		
		b[1].cTren = coGian(b[1].cTren, 0.3, 0.3, 555, 425);
		b[1].cTrai = coGian(b[1].cTrai, 0.3, 0.3, 555, 425);
		b[1].cDuoi = coGian(b[1].cDuoi, 0.3, 0.3, 555, 425);
		b[1].cPhai = coGian(b[1].cPhai, 0.3, 0.3, 555, 425);
		
		b[0].cTren = tinhTien(b[0].cTren, -200, 0);
		b[0].cTrai = tinhTien(b[0].cTrai, -200, 0);
		b[0].cDuoi = tinhTien(b[0].cDuoi, -200, 0);
		b[0].cPhai = tinhTien(b[0].cPhai, -200, 0);
		
		b[1].cTren = tinhTien(b[1].cTren, -200, 0);
		b[1].cTrai = tinhTien(b[1].cTrai, -200, 0);
		b[1].cDuoi = tinhTien(b[1].cDuoi, -200, 0);
		b[1].cPhai = tinhTien(b[1].cPhai, -200, 0);
	}
	drawCircleMidpoint(860, 120, 820, 120, 0, false);
	lineMidPoint(860, 160, 860, 300, 0, false);
	lineMidPoint(860, 180, 910, 250, 0, false);
	lineMidPoint(860, 180, 810, 250, 0, false);
	lineMidPoint(860, 300, 910, 430, 0, false);
	lineMidPoint(860, 300, 810, 430, 0, false);
}

void effectThor(){
	for(int i = 0; i < 4; i++){
		xoaInfor();
		giaoDienThor(2, 1);
		
		toaDoThor(t->than.x1, t->than.y1, 1);
		toaDoThor(t->tTrai1.x1, t->tTrai1.y1, 2);
		toaDoThor(t->tTrai1.x2, t->tTrai1.y2, 3);
		toaDoThor(t->tPhai1.x2, t->tPhai1.y2, 4);
		toaDoThor(t->than.x2, t->than.y2, 5);
		toaDoThor(t->cTrai.x1, t->cTrai.y1, 6);
		toaDoThor(t->cPhai.x1, t->cPhai.y1, 9);
		toaDoThor(t->dau.x1, t->dau.y1, 7);
		toaDoThor(t->dau.x2, t->dau.y2, 8);
		//than
		toaDoThor(b[0].cTren.x1, b[0].cTren.y1, 10);
		toaDoThor(b[0].cTrai.x2, b[0].cTrai.y2, 11);
		toaDoThor(b[0].cDuoi.x2, b[0].cDuoi.y2, 12);
		toaDoThor(b[0].cPhai.x2, b[0].cPhai.y2, 13);
		//dau
		toaDoThor(b[1].cTren.x1, b[1].cTren.y1, 14);
		toaDoThor(b[1].cTrai.x2, b[1].cTrai.y2, 15);
		toaDoThor(b[1].cDuoi.x2, b[1].cDuoi.y2, 16);
		toaDoThor(b[1].cPhai.x2, b[1].cPhai.y2, 17);
		
		drawCircleMidpoint(t->dau.x1, t->dau.y1, t->dau.x2, t->dau.y2, 0, false);
		lineMidPoint(t->than.x1, t->than.y1, t->than.x2, t->than.y2, 0, false);// than
		lineMidPoint(t->tTrai1.x1, t->tTrai1.y1, t->tTrai1.x2, t->tTrai1.y2, 0, false);// tay trai khuc dau
		lineMidPoint(t->tPhai1.x1, t->tPhai1.y1, t->tPhai1.x2, t->tPhai1.y2, 0, false);// tay phai khuc dau
		
		//bua
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 0, false);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 0, false);//canh phai
		delay(300);
		if(i == 3) break;
		lineMidPoint(t->tTrai1.x1, t->tTrai1.y1, t->tTrai1.x2, t->tTrai1.y2, 15, true);// tay trai khuc dau
		lineMidPoint(t->tPhai1.x1, t->tPhai1.y1, t->tPhai1.x2, t->tPhai1.y2, 15, true);// tay phai khuc dau
		//bua
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 15, true);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 15, true);//canh phai
		
		t->tTrai1 = bdQuay(t->tTrai1, 45, 369, 405);
		t->tPhai1 = bdQuay(t->tPhai1, 20, 369, 405);
		//bua
		b[0].cTren = bdQuay(b[0].cTren, 45, 369, 405);
		b[0].cTrai = bdQuay(b[0].cTrai, 45, 369, 405);
		b[0].cDuoi = bdQuay(b[0].cDuoi, 45, 369, 405);
		b[0].cPhai = bdQuay(b[0].cPhai, 45, 369, 405);
		
		b[1].cTren = bdQuay(b[1].cTren, 45, 369, 405);
		b[1].cTrai = bdQuay(b[1].cTrai, 45, 369, 405);
		b[1].cDuoi = bdQuay(b[1].cDuoi, 45, 369, 405);
		b[1].cPhai = bdQuay(b[1].cPhai, 45, 369, 405);
	}
	buaBay();
}

void buaBay(){
	for(int i = 0; i < 5; i++){
		xoaInfor();
		giaoDienThor(3, 1);
		
		toaDoThor(t->than.x1, t->than.y1, 1);
		toaDoThor(t->tTrai1.x1, t->tTrai1.y1, 2);
		toaDoThor(t->tTrai1.x2, t->tTrai1.y2, 3);
		toaDoThor(t->tPhai1.x2, t->tPhai1.y2, 4);
		toaDoThor(t->than.x2, t->than.y2, 5);
		toaDoThor(t->cTrai.x1, t->cTrai.y1, 6);
		toaDoThor(t->cPhai.x1, t->cPhai.y1, 9);
		toaDoThor(t->dau.x1, t->dau.y1, 7);
		toaDoThor(t->dau.x2, t->dau.y2, 8);
		//than
		toaDoThor(b[0].cTren.x1, b[0].cTren.y1, 10);
		toaDoThor(b[0].cTrai.x2, b[0].cTrai.y2, 11);
		toaDoThor(b[0].cDuoi.x2, b[0].cDuoi.y2, 12);
		toaDoThor(b[0].cPhai.x2, b[0].cPhai.y2, 13);
		//dau
		toaDoThor(b[1].cTren.x1, b[1].cTren.y1, 14);
		toaDoThor(b[1].cTrai.x2, b[1].cTrai.y2, 15);
		toaDoThor(b[1].cDuoi.x2, b[1].cDuoi.y2, 16);
		toaDoThor(b[1].cPhai.x2, b[1].cPhai.y2, 17);
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 0, false);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 0, false);//canh phai
		if(i == 3){
			drawCircleMidpoint(860, 120, 820, 120, 15, true);
			lineMidPoint(860, 160, 860, 300, 15, true);
			lineMidPoint(860, 180, 910, 250, 15, true);
			lineMidPoint(860, 180, 810, 250, 15, true);
			lineMidPoint(860, 300, 910, 430, 15, true);
			lineMidPoint(860, 300, 810, 430, 15, true);
		}
		delay(300);
		if(i == 4) break;
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 15, true);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 15, true);//canh phai
		
		lineMidPoint(t->tTrai1.x1, t->tTrai1.y1, t->tTrai1.x2, t->tTrai1.y2, 0, false);// tay trai khuc dau
		
		if(i < 2){
			b[0].cTren = tinhTien(b[0].cTren, 180, -100);
			b[0].cTrai = tinhTien(b[0].cTrai, 180, -100);
			b[0].cDuoi = tinhTien(b[0].cDuoi, 180, -100);
			b[0].cPhai = tinhTien(b[0].cPhai, 180, -100);
			
			b[1].cTren = tinhTien(b[1].cTren, 180, -100);
			b[1].cTrai = tinhTien(b[1].cTrai, 180, -100);
			b[1].cDuoi = tinhTien(b[1].cDuoi, 180, -100);
			b[1].cPhai = tinhTien(b[1].cPhai, 180, -100);
		}else{
			b[0].cTren = tinhTien(b[0].cTren, 90, -50);
			b[0].cTrai = tinhTien(b[0].cTrai, 90, -50);
			b[0].cDuoi = tinhTien(b[0].cDuoi, 90, -50);
			b[0].cPhai = tinhTien(b[0].cPhai, 90, -50);
			
			b[1].cTren = tinhTien(b[1].cTren, 90, -50);
			b[1].cTrai = tinhTien(b[1].cTrai, 90, -50);
			b[1].cDuoi = tinhTien(b[1].cDuoi, 90, -50);
			b[1].cPhai = tinhTien(b[1].cPhai, 90, -50);
		}
		
	}
	buaBayVe();
}

void buaBayVe(){
	for(int i = 0; i < 4; i++){
		xoaInfor();
		giaoDienThor(1, 1);
		
		toaDoThor(t->than.x1, t->than.y1, 1);
		toaDoThor(t->tTrai1.x1, t->tTrai1.y1, 2);
		toaDoThor(t->tTrai1.x2, t->tTrai1.y2, 3);
		toaDoThor(t->tPhai1.x2, t->tPhai1.y2, 4);
		toaDoThor(t->than.x2, t->than.y2, 5);
		toaDoThor(t->cTrai.x1, t->cTrai.y1, 6);
		toaDoThor(t->cPhai.x1, t->cPhai.y1, 9);
		toaDoThor(t->dau.x1, t->dau.y1, 7);
		toaDoThor(t->dau.x2, t->dau.y2, 8);
		//than
		toaDoThor(b[0].cTren.x1, b[0].cTren.y1, 10);
		toaDoThor(b[0].cTrai.x2, b[0].cTrai.y2, 11);
		toaDoThor(b[0].cDuoi.x2, b[0].cDuoi.y2, 12);
		toaDoThor(b[0].cPhai.x2, b[0].cPhai.y2, 13);
		//dau
		toaDoThor(b[1].cTren.x1, b[1].cTren.y1, 14);
		toaDoThor(b[1].cTrai.x2, b[1].cTrai.y2, 15);
		toaDoThor(b[1].cDuoi.x2, b[1].cDuoi.y2, 16);
		toaDoThor(b[1].cPhai.x2, b[1].cPhai.y2, 17);
		
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 0, false);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 0, false);//canh phai
		if(i != 3) delay(300);
		if(i == 3) break;
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 15, true);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 15, true);//canh phai
		
		if(i < 2){
			b[0].cTren = tinhTien(b[0].cTren, -90, 50);
			b[0].cTrai = tinhTien(b[0].cTrai, -90, 50);
			b[0].cDuoi = tinhTien(b[0].cDuoi, -90, 50);
			b[0].cPhai = tinhTien(b[0].cPhai, -90, 50);
			
			b[1].cTren = tinhTien(b[1].cTren, -90, 50);
			b[1].cTrai = tinhTien(b[1].cTrai, -90, 50);
			b[1].cDuoi = tinhTien(b[1].cDuoi, -90, 50);
			b[1].cPhai = tinhTien(b[1].cPhai, -90, 50);
		}else{
			b[0].cTren = tinhTien(b[0].cTren, -360, 200);
			b[0].cTrai = tinhTien(b[0].cTrai, -360, 200);
			b[0].cDuoi = tinhTien(b[0].cDuoi, -360, 200);
			b[0].cPhai = tinhTien(b[0].cPhai, -360, 200);
			
			b[1].cTren = tinhTien(b[1].cTren, -360, 200);
			b[1].cTrai = tinhTien(b[1].cTrai, -360, 200);
			b[1].cDuoi = tinhTien(b[1].cDuoi, -360, 200);
			b[1].cPhai = tinhTien(b[1].cPhai, -360, 200);
		}	
	}
	drawThor1();
}

void drawThor1(){
	for(int i = 0; i < 4; i++){
		xoaInfor();
		giaoDienThor(5, 1);
		
		toaDoThor(t->than.x1, t->than.y1, 1);
		toaDoThor(t->tTrai1.x1, t->tTrai1.y1, 2);
		toaDoThor(t->tTrai1.x2, t->tTrai1.y2, 3);
		toaDoThor(t->tPhai1.x2, t->tPhai1.y2, 4);
		toaDoThor(t->than.x2, t->than.y2, 5);
		toaDoThor(t->cTrai.x1, t->cTrai.y1, 6);
		toaDoThor(t->cPhai.x1, t->cPhai.y1, 9);
		toaDoThor(t->dau.x1, t->dau.y1, 7);
		toaDoThor(t->dau.x2, t->dau.y2, 8);
		//than
		toaDoThor(b[0].cTren.x1, b[0].cTren.y1, 10);
		toaDoThor(b[0].cTrai.x2, b[0].cTrai.y2, 11);
		toaDoThor(b[0].cDuoi.x2, b[0].cDuoi.y2, 12);
		toaDoThor(b[0].cPhai.x2, b[0].cPhai.y2, 13);
		//dau
		toaDoThor(b[1].cTren.x1, b[1].cTren.y1, 14);
		toaDoThor(b[1].cTrai.x2, b[1].cTrai.y2, 15);
		toaDoThor(b[1].cDuoi.x2, b[1].cDuoi.y2, 16);
		toaDoThor(b[1].cPhai.x2, b[1].cPhai.y2, 17);
		
		drawCircleMidpoint(t->dau.x1, t->dau.y1, t->dau.x2, t->dau.y2, 0, false);
		lineMidPoint(t->than.x1, t->than.y1, t->than.x2, t->than.y2, 0, false);// than
		lineMidPoint(t->tTrai1.x1, t->tTrai1.y1, t->tTrai1.x2, t->tTrai1.y2, 0, false);// tay trai khuc dau
		lineMidPoint(t->tPhai1.x1, t->tPhai1.y1, t->tPhai1.x2, t->tPhai1.y2, 0, false);// tay phai khuc dau
		
		//bua
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 0, false);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 0, false);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 0, false);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 0, false);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 0, false);//canh phai
		delay(30);
		if(i == 3) break;
		lineMidPoint(t->tTrai1.x1, t->tTrai1.y1, t->tTrai1.x2, t->tTrai1.y2, 15, true);// tay trai khuc dau
		lineMidPoint(t->tPhai1.x1, t->tPhai1.y1, t->tPhai1.x2, t->tPhai1.y2, 15, true);// tay phai khuc dau
		//bua
		lineMidPoint(b[0].cTren.x1, b[0].cTren.y1, b[0].cTren.x2, b[0].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[0].cTrai.x1, b[0].cTrai.y1, b[0].cTrai.x2, b[0].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[0].cDuoi.x1, b[0].cDuoi.y1, b[0].cDuoi.x2, b[0].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[0].cPhai.x1, b[0].cPhai.y1, b[0].cPhai.x2, b[0].cPhai.y2, 15, true);//canh phai
		
		lineMidPoint(b[1].cTren.x1, b[1].cTren.y1, b[1].cTren.x2, b[1].cTren.y2, 15, true);// canh tren
		lineMidPoint(b[1].cTrai.x1, b[1].cTrai.y1, b[1].cTrai.x2, b[1].cTrai.y2, 15, true);//canh trai
		lineMidPoint(b[1].cDuoi.x1, b[1].cDuoi.y1, b[1].cDuoi.x2, b[1].cDuoi.y2, 15, true);//canh duoi
		lineMidPoint(b[1].cPhai.x1, b[1].cPhai.y1, b[1].cPhai.x2, b[1].cPhai.y2, 15, true);//canh phai
		
		t->tTrai1 = bdQuay(t->tTrai1, -45, 369, 405);
		t->tPhai1 = bdQuay(t->tPhai1, -20, 369, 405);
		//bua
		b[0].cTren = bdQuay(b[0].cTren, -45, 369, 405);
		b[0].cTrai = bdQuay(b[0].cTrai, -45, 369, 405);
		b[0].cDuoi = bdQuay(b[0].cDuoi, -45, 369, 405);
		b[0].cPhai = bdQuay(b[0].cPhai, -45, 369, 405);
		
		b[1].cTren = bdQuay(b[1].cTren, -45, 369, 405);
		b[1].cTrai = bdQuay(b[1].cTrai, -45, 369, 405);
		b[1].cDuoi = bdQuay(b[1].cDuoi, -45, 369, 405);
		b[1].cPhai = bdQuay(b[1].cPhai, -45, 369, 405);
	}
}
//ve hinh 2D dau tien
//ve 1 canh phi tieu
//in toa do ra man hinh
void giaoDienSuriken(int i, int k){
	if(i == 1) outtextxy(1005, 35, "  > Canh Suriken Tren <"); // tieu de
	if(i == 2) outtextxy(1005, 35, "  > Canh Suriken Trai  <"); // tieu de
	if(i == 3) outtextxy(1005, 35, "  > Canh Suriken Duoi <"); // tieu de
	if(i == 4) outtextxy(1005, 35, "  > Canh Suriken Phai <"); // tieu de
	if(i == 5) outtextxy(1005, 35, "       > Suriken <"); // tieu de
	outtextxy(1015, 65, "Hinh Tron:"); // hinh tron	
	outtextxy(1015, 125, "Diem 1:");
	outtextxy(1015, 155, "Diem 2:");
	outtextxy(1015, 185, "Diem 3:");
	outtextxy(1015, 215, "Diem 4:");
	outtextxy(1015, 245, "Diem 5:");
	outtextxy(1015, 275, "Diem 6:");
	if(k == 1){
		outtextxy(1015, 305, "Diem 7:");
		outtextxy(1015, 335, "Diem 8:");
		outtextxy(1015, 365, "Diem 9:");
		outtextxy(1015, 395, "Diem 10:");
		outtextxy(1015, 425, "Diem 11:");
		outtextxy(1015, 455, "Diem 12:");
		outtextxy(1015, 485, "Diem 13:");
		outtextxy(1015, 515, "Diem 14:");
		outtextxy(1015, 545, "Diem 15:");
		outtextxy(1015, 575, "Diem 16:");
	}
}

void toaDoSuriken(int xc, int yc, int i){
	char chx[6], chy[6];
	int x, y;
	x = xc; y = yc;
	roundPixel(x, y);
	x = x - 650;
	y = y - 350;
	sprintf(chx, "%d", x);
	sprintf(chy, "%d", y);
	//cac diem khac
	if(i == 1){
		outtextxy(1170, 125, "                 ");
		outtextxy(1160, 125, "("); outtextxy(1240, 125, ","); outtextxy(1305, 125, ")");
		outtextxy(1175, 125, chx); outtextxy(1250, 125, chy);
	}
	if(i == 2){
		outtextxy(1170, 155, "                 ");
		outtextxy(1160, 155, "("); outtextxy(1240, 155, ","); outtextxy(1305, 155, ")");
		outtextxy(1175, 155, chx); outtextxy(1250, 155, chy);
	}
	if(i == 3){
		outtextxy(1175, 185, "                 ");
		outtextxy(1160, 185, "("); outtextxy(1240, 185, ","); outtextxy(1305, 185, ")");
		outtextxy(1175, 185, chx); outtextxy(1250, 185, chy);
	}
	if(i == 4){
		outtextxy(1175, 215, "                 ");
		outtextxy(1160, 215, "("); outtextxy(1240, 215, ","); outtextxy(1305, 215, ")");
		outtextxy(1175, 215, chx); outtextxy(1250, 215, chy);
	}
	if(i == 5){
		outtextxy(1175, 245, "                 ");
		outtextxy(1160, 245, "("); outtextxy(1240, 245, ","); outtextxy(1305, 245, ")");
		outtextxy(1175, 245, chx); outtextxy(1250, 245, chy);
	}
	if(i == 6){
		outtextxy(1175, 275, "                 ");
		outtextxy(1160, 275, "("); outtextxy(1240, 275, ","); outtextxy(1305, 275, ")");
		outtextxy(1175, 275, chx); outtextxy(1250, 275, chy);
	}
	//hinh tron
	if(i == 7){
		outtextxy(1175, 65, "                 ");
		outtextxy(1160, 65, "("); outtextxy(1240, 65, ","); outtextxy(1305, 65, ")");
		outtextxy(1175, 65, chx); outtextxy(1250, 65, chy);
	}
	if(i == 8){
		outtextxy(1175, 95, "                 ");
		outtextxy(1160, 95, "("); outtextxy(1240, 95, ","); outtextxy(1305, 95, ")");
		outtextxy(1175, 95, chx); outtextxy(1250, 95, chy);
	}
	//cac diem khac
	if(i == 9){
		outtextxy(1175, 305, "                 ");
		outtextxy(1160, 305, "("); outtextxy(1240, 305, ","); outtextxy(1305, 305, ")");
		outtextxy(1175, 305, chx); outtextxy(1250, 305, chy);
	}
	if(i == 10){
		outtextxy(1175, 335, "                 ");
		outtextxy(1160, 335, "("); outtextxy(1240, 335, ","); outtextxy(1305, 335, ")");
		outtextxy(1175, 335, chx); outtextxy(1250, 335, chy);
	}
	if(i == 11){
		outtextxy(1175, 365, "                 ");
		outtextxy(1160, 365, "("); outtextxy(1240, 365, ","); outtextxy(1305, 365, ")");
		outtextxy(1175, 365, chx); outtextxy(1250, 365, chy);
	}
	if(i == 12){
		outtextxy(1175, 395, "                 ");
		outtextxy(1160, 395, "("); outtextxy(1240, 395, ","); outtextxy(1305, 395, ")");
		outtextxy(1175, 395, chx); outtextxy(1250, 395, chy);
	}
	if(i == 13){
		outtextxy(1175, 425, "                 ");
		outtextxy(1160, 425, "("); outtextxy(1240, 425, ","); outtextxy(1305, 425, ")");
		outtextxy(1175, 425, chx); outtextxy(1250, 425, chy);
	}
	if(i == 14){
		outtextxy(1175, 455, "                 ");
		outtextxy(1160, 455, "("); outtextxy(1240, 455, ","); outtextxy(1305, 455, ")");
		outtextxy(1175, 455, chx); outtextxy(1250, 455, chy);
	}
	if(i == 15){
		outtextxy(1175, 485, "                 ");
		outtextxy(1160, 485, "("); outtextxy(1240, 485, ","); outtextxy(1305, 485, ")");
		outtextxy(1175, 485, chx); outtextxy(1250, 485, chy);
	}
	if(i == 16){
		outtextxy(1175, 515, "                 ");
		outtextxy(1160, 515, "("); outtextxy(1240, 515, ","); outtextxy(1305, 515, ")");
		outtextxy(1175, 515, chx); outtextxy(1250, 515, chy);
	}
	if(i == 17){
		outtextxy(1175, 545, "                 ");
		outtextxy(1160, 545, "("); outtextxy(1240, 545, ","); outtextxy(1305, 545, ")");
		outtextxy(1175, 545, chx); outtextxy(1250, 545, chy);
	}
	if(i == 18){
		outtextxy(1175, 575, "                 ");
		outtextxy(1160, 575, "("); outtextxy(1240, 575, ","); outtextxy(1305, 575, ")");
		outtextxy(1175, 575, chx); outtextxy(1250, 575, chy);
	}
}

void ganGiaTri(int x1, int y1, int x2, int y2, int i, int k){
	//cDai1
	if(k == 1){
		w[i].cDai1.x1 = x1;
		w[i].cDai1.y1 = y1;
		w[i].cDai1.x2 = x2;
		w[i].cDai1.y2 = y2;
	}
	//cDai2
	if(k == 2){
		w[i].cDai2.x1 = x1;
		w[i].cDai2.y1 = y1;
		w[i].cDai2.x2 = x2;
		w[i].cDai2.y2 = y2;
	}
	//cGiua
	if(k == 3){
		w[i].cGiua.x1 = x1;
		w[i].cGiua.y1 = y1;
		w[i].cGiua.x2 = x2;
		w[i].cGiua.y2 = y2;
	}
	//cNgan1
	if(k == 4){
		w[i].cNgan1.x1 = x1;
		w[i].cNgan1.y1 = y1;
		w[i].cNgan1.x2 = x2;
		w[i].cNgan1.y2 = y2;
	}
	//cNgan2
	if(k == 5){
		w[i].cNgan2.x1 = x1;
		w[i].cNgan2.y1 = y1;
		w[i].cNgan2.x2 = x2;
		w[i].cNgan2.y2 = y2;
	}
	//hTron
	if(k == 6){
		w[i].hTron.x1 = x1;
		w[i].hTron.y1 = y1;
		w[i].hTron.x2 = x2;
		w[i].hTron.y2 = y2;
	}
}

void ganGiaTri1(int x1, int y1, int x2, int y2, int i, int k){
	//cDai1
	if(k == 1){
		w1[i].cDai1.x1 = x1;
		w1[i].cDai1.y1 = y1;
		w1[i].cDai1.x2 = x2;
		w1[i].cDai1.y2 = y2;
	}
	//cDai2
	if(k == 2){
		w1[i].cDai2.x1 = x1;
		w1[i].cDai2.y1 = y1;
		w1[i].cDai2.x2 = x2;
		w1[i].cDai2.y2 = y2;
	}
	//cGiua
	if(k == 3){
		w1[i].cGiua.x1 = x1;
		w1[i].cGiua.y1 = y1;
		w1[i].cGiua.x2 = x2;
		w1[i].cGiua.y2 = y2;
	}
	//cNgan1
	if(k == 4){
		w1[i].cNgan1.x1 = x1;
		w1[i].cNgan1.y1 = y1;
		w1[i].cNgan1.x2 = x2;
		w1[i].cNgan1.y2 = y2;
	}
	//cNgan2
	if(k == 5){
		w1[i].cNgan2.x1 = x1;
		w1[i].cNgan2.y1 = y1;
		w1[i].cNgan2.x2 = x2;
		w1[i].cNgan2.y2 = y2;
	}
	//hTron
	if(k == 6){
		w1[i].hTron.x1 = x1;
		w1[i].hTron.y1 = y1;
		w1[i].hTron.x2 = x2;
		w1[i].hTron.y2 = y2;
	}
}

void drawSuriken(){
	lineMidPoint(600, 180, 650, 20, 0, false); // buoc nhay 120
	lineMidPoint(700, 180, 650, 20, 0, false);
	lineMidPoint(650, 190, 650, 20, 0, false);
	lineMidPoint(600, 180, 620, 200, 0, false);
	lineMidPoint(700, 180, 680, 200, 0, false);
	drawCircleMidpoint(650, 230, 690, 230, 0, false);
	
	//canh duoi
	lineMidPoint(600, 520, 650, 680, 0, false);// canh trai
	lineMidPoint(700, 520, 650, 680, 0, false);//canh phai
	lineMidPoint(650, 510, 650, 680, 0, false);// canh giua
	lineMidPoint(600, 520, 620, 500, 0, false);//canh trai ngan
	lineMidPoint(700, 520, 680, 500, 0, false);// canh phai ngan
	drawCircleMidpoint(650, 470, 690, 470, 0, false);
	
	//canh trai
	lineMidPoint(480, 300, 320, 350, 0, false);// canh tren
	lineMidPoint(480, 400, 320, 350, 0, false);//canh duoi
	lineMidPoint(490, 350, 320, 350, 0, false);// canh giua
	lineMidPoint(480, 400, 500, 380, 0, false);//canh duoi ngan
	lineMidPoint(480, 300, 500, 320, 0, false);// canh tren ngan
	drawCircleMidpoint(530, 350, 570, 350, 0, false);
	
	//canh phai
	lineMidPoint(820, 300, 980, 350, 0, false);// canh tren
	lineMidPoint(820, 400, 980, 350, 0, false);//canh duoi
	lineMidPoint(810, 350, 980, 350, 0, false);// canh giua
	lineMidPoint(820, 300, 800, 320, 0, false);//canh tren ngan
	lineMidPoint(820, 400, 800, 380, 0, false);// canh duoi ngan
	drawCircleMidpoint(770, 350, 810, 350, 0, false);
}

void effectSuriken(bool &flag1){
	//gan gia tri pixel suriken tren
	ganGiaTri(600, 180, 650, 20, 0, 1);
	ganGiaTri(700, 180, 650, 20, 0, 2);
	ganGiaTri(650, 190, 650, 20, 0, 3);
	ganGiaTri(600, 180, 620, 200, 0, 4);
	ganGiaTri(700, 180, 680, 200, 0, 5);
	ganGiaTri(650, 230, 690, 230, 0, 6);
	//gan gia tri pixel suriken trai
	ganGiaTri(480, 300, 320, 350, 1, 1);
	ganGiaTri(480, 400, 320, 350, 1, 2);
	ganGiaTri(490, 350, 320, 350, 1, 3);
	ganGiaTri(480, 400, 500, 380, 1, 4);
	ganGiaTri(480, 300, 500, 320, 1, 5);
	ganGiaTri(530, 350, 570, 350, 1, 6);
	//gan gia tri pixel suriken duoi
	ganGiaTri(600, 520, 650, 680, 2, 1);
	ganGiaTri(700, 520, 650, 680, 2, 2);
	ganGiaTri(650, 510, 650, 680, 2, 3);
	ganGiaTri(600, 520, 620, 500, 2, 4);
	ganGiaTri(700, 520, 680, 500, 2, 5);
	ganGiaTri(650, 470, 690, 470, 2, 6);
	//gan gia tri pixel suriken phai
	ganGiaTri(820, 300, 980, 350, 3, 1);
	ganGiaTri(820, 400, 980, 350, 3, 2);
	ganGiaTri(810, 350, 980, 350, 3, 3);
	ganGiaTri(820, 300, 800, 320, 3, 4);
	ganGiaTri(820, 400, 800, 380, 3, 5);
	ganGiaTri(770, 350, 810, 350, 3, 6);
	
	for(int i = 0; i <= 4; i++){
		if(i == 0) giaoDienSuriken(1, 0);
		toaDoSuriken(w[0].cDai1.x2, w[0].cDai1.y2, 1);
		toaDoSuriken(w[0].cDai1.x1, w[0].cDai1.y1, 2);
		toaDoSuriken(w[0].cDai2.x1, w[0].cDai2.y1, 3);
		toaDoSuriken(w[0].cNgan1.x2, w[0].cNgan1.y2, 4);
		toaDoSuriken(w[0].cGiua.x1, w[0].cDai1.y1, 5);
		toaDoSuriken(w[0].cNgan2.x2, w[0].cNgan2.y2, 6);
		toaDoSuriken(w[0].hTron.x1, w[0].hTron.y1, 7);
		toaDoSuriken(w[0].hTron.x2, w[0].hTron.y2, 8);

		lineMidPoint(w[0].cDai1.x1, w[0].cDai1.y1, w[0].cDai1.x2, w[0].cDai1.y2,0, false);
		lineMidPoint(w[0].cDai2.x1, w[0].cDai2.y1, w[0].cDai2.x2, w[0].cDai1.y2,0, false);
		lineMidPoint(w[0].cGiua.x1, w[0].cGiua.y1, w[0].cGiua.x2, w[0].cGiua.y2,0, false);
		lineMidPoint(w[0].cNgan1.x1, w[0].cNgan1.y1, w[0].cNgan1.x2, w[0].cNgan1.y2,0, false);
		lineMidPoint(w[0].cNgan2.x1, w[0].cNgan2.y1, w[0].cNgan2.x2, w[0].cNgan2.y2,0, false);
		drawCircleMidpoint(w[0].hTron.x1, w[0].hTron.y1, w[0].hTron.x2, w[0].hTron.y2,0, false);
		if(i == 4) break;
		lineMidPoint(w[0].cDai1.x1, w[0].cDai1.y1, w[0].cDai1.x2, w[0].cDai1.y2,15, true);
		lineMidPoint(w[0].cDai2.x1, w[0].cDai2.y1, w[0].cDai2.x2, w[0].cDai1.y2,15, true);
		lineMidPoint(w[0].cGiua.x1, w[0].cGiua.y1, w[0].cGiua.x2, w[0].cGiua.y2,15, true);
		lineMidPoint(w[0].cNgan1.x1, w[0].cNgan1.y1, w[0].cNgan1.x2, w[0].cNgan1.y2,15, true);
		lineMidPoint(w[0].cNgan2.x1, w[0].cNgan2.y1, w[0].cNgan2.x2, w[0].cNgan2.y2,15, true);
		drawCircleMidpoint(w[0].hTron.x1, w[0].hTron.y1, w[0].hTron.x2, w[0].hTron.y2,15, true);
	    w[0].cDai1 = tinhTien(w[0].cDai1, 0, 30);
	    w[0].cDai2 = tinhTien(w[0].cDai2, 0, 30);
	    w[0].cGiua = tinhTien(w[0].cGiua, 0, 30);
	    w[0].cNgan1 = tinhTien(w[0].cNgan1, 0, 30);
	    w[0].cNgan2 = tinhTien(w[0].cNgan2, 0, 30);
	    w[0].hTron = tinhTien(w[0].hTron, 0, 30);
	} 
	
	for(int i = 0; i <= 4; i++){
		if(i == 0){
			xoaInfor();
			giaoDienSuriken(2, 0);
		} 
		toaDoSuriken(w[1].cDai1.x2, w[1].cDai1.y2, 1);
		toaDoSuriken(w[1].cDai1.x1, w[1].cDai1.y1, 2);
		toaDoSuriken(w[1].cDai2.x1, w[1].cDai2.y1, 3);
		toaDoSuriken(w[1].cNgan1.x2, w[1].cNgan1.y2, 4);
		toaDoSuriken(w[1].cGiua.x1, w[1].cDai1.y1, 5);
		toaDoSuriken(w[1].cNgan2.x2, w[1].cNgan2.y2, 6);
		toaDoSuriken(w[1].hTron.x1, w[1].hTron.y1, 7);
		toaDoSuriken(w[1].hTron.x2, w[1].hTron.y2, 8);
		
		lineMidPoint(w[1].cDai1.x1, w[1].cDai1.y1, w[1].cDai1.x2, w[1].cDai1.y2,0, false);
		lineMidPoint(w[1].cDai2.x1, w[1].cDai2.y1, w[1].cDai2.x2, w[1].cDai1.y2,0, false);
		lineMidPoint(w[1].cGiua.x1, w[1].cGiua.y1, w[1].cGiua.x2, w[1].cGiua.y2,0, false);
		lineMidPoint(w[1].cNgan1.x1, w[1].cNgan1.y1, w[1].cNgan1.x2, w[1].cNgan1.y2,0, false);
		lineMidPoint(w[1].cNgan2.x1, w[1].cNgan2.y1, w[1].cNgan2.x2, w[1].cNgan2.y2,0, false);
		drawCircleMidpoint(w[1].hTron.x1, w[1].hTron.y1, w[1].hTron.x2, w[1].hTron.y2,0, false);
		if(i == 4) break;
		lineMidPoint(w[1].cDai1.x1, w[1].cDai1.y1, w[1].cDai1.x2, w[1].cDai1.y2,15, true);
		lineMidPoint(w[1].cDai2.x1, w[1].cDai2.y1, w[1].cDai2.x2, w[1].cDai1.y2,15, true);
		lineMidPoint(w[1].cGiua.x1, w[1].cGiua.y1, w[1].cGiua.x2, w[1].cGiua.y2,15, true);
		lineMidPoint(w[1].cNgan1.x1, w[1].cNgan1.y1, w[1].cNgan1.x2, w[1].cNgan1.y2,15, true);
		lineMidPoint(w[1].cNgan2.x1, w[1].cNgan2.y1, w[1].cNgan2.x2, w[1].cNgan2.y2,15, true);
		drawCircleMidpoint(w[1].hTron.x1, w[1].hTron.y1, w[1].hTron.x2, w[1].hTron.y2,15, true);
	    w[1].cDai1 = tinhTien(w[1].cDai1, 30, 0);
		w[1].cDai2 = tinhTien(w[1].cDai2, 30, 0);
	    w[1].cGiua = tinhTien(w[1].cGiua, 30, 0);
	    w[1].cNgan1 = tinhTien(w[1].cNgan1, 30, 0);
	    w[1].cNgan2 = tinhTien(w[1].cNgan2, 30, 0);
	    w[1].hTron = tinhTien(w[1].hTron, 30, 0);
	    if(i >= 2){
			drawCircleMidpoint(650, 350, 690, 350, 0, false);
			lineMidPoint(600, 300, 620, 320, 0, false);// canh phai ngan
		} 
	} 
	for(int i = 0; i <= 4; i++){
		if(i == 0){
			xoaInfor();
			giaoDienSuriken(3, 0);
		} 
		toaDoSuriken(w[2].cDai1.x2, w[2].cDai1.y2, 1);
		toaDoSuriken(w[2].cDai1.x1, w[2].cDai1.y1, 2);
		toaDoSuriken(w[2].cDai2.x1, w[2].cDai2.y1, 3);
		toaDoSuriken(w[2].cNgan1.x2, w[2].cNgan1.y2, 4);
		toaDoSuriken(w[2].cGiua.x1, w[2].cDai1.y1, 5);
		toaDoSuriken(w[2].cNgan2.x2, w[2].cNgan2.y2, 6);
		toaDoSuriken(w[2].hTron.x1, w[2].hTron.y1, 7);
		toaDoSuriken(w[2].hTron.x2, w[2].hTron.y2, 8);
		
		lineMidPoint(w[2].cDai1.x1, w[2].cDai1.y1, w[2].cDai1.x2, w[2].cDai1.y2,0, false);
		lineMidPoint(w[2].cDai2.x1, w[2].cDai2.y1, w[2].cDai2.x2, w[2].cDai1.y2,0, false);
		lineMidPoint(w[2].cGiua.x1, w[2].cGiua.y1, w[2].cGiua.x2, w[2].cGiua.y2,0, false);
		lineMidPoint(w[2].cNgan1.x1, w[2].cNgan1.y1, w[2].cNgan1.x2, w[2].cNgan1.y2,0, false);
		lineMidPoint(w[2].cNgan2.x1, w[2].cNgan2.y1, w[2].cNgan2.x2, w[2].cNgan2.y2,0, false);
		drawCircleMidpoint(w[2].hTron.x1, w[2].hTron.y1, w[2].hTron.x2, w[2].hTron.y2,0, false);
		if(i == 4) break;
		lineMidPoint(w[2].cDai1.x1, w[2].cDai1.y1, w[2].cDai1.x2, w[2].cDai1.y2,15, true);
		lineMidPoint(w[2].cDai2.x1, w[2].cDai2.y1, w[2].cDai2.x2, w[2].cDai1.y2,15, true);
		lineMidPoint(w[2].cGiua.x1, w[2].cGiua.y1, w[2].cGiua.x2, w[2].cGiua.y2,15, true);
		lineMidPoint(w[2].cNgan1.x1, w[2].cNgan1.y1, w[2].cNgan1.x2, w[2].cNgan1.y2,15, true);
		lineMidPoint(w[2].cNgan2.x1, w[2].cNgan2.y1, w[2].cNgan2.x2, w[2].cNgan2.y2,15, true);
		drawCircleMidpoint(w[2].hTron.x1, w[2].hTron.y1, w[2].hTron.x2, w[2].hTron.y2,15, true);
	    w[2].cDai1 = tinhTien(w[2].cDai1, 0, -30);
		w[2].cDai2 = tinhTien(w[2].cDai2, 0, -30);
		w[2].cGiua = tinhTien(w[2].cGiua, 0, -30);
	    w[2].cNgan1 = tinhTien(w[2].cNgan1, 0, -30);
	    w[2].cNgan2 = tinhTien(w[2].cNgan2, 0, -30);
	    w[2].hTron = tinhTien(w[2].hTron, 0, -30);
	    if(i >= 2){
			drawCircleMidpoint(650, 350, 690, 350, 0, false);
			lineMidPoint(600, 400, 620, 380, 0, false);//canh trai ngan
		}
	} 
	for(int i = 0; i <= 4; i++){
		if(i == 0){
			xoaInfor();
			giaoDienSuriken(4, 0);
		} 
		toaDoSuriken(w[3].cDai1.x2, w[3].cDai1.y2, 1);
		toaDoSuriken(w[3].cDai1.x1, w[3].cDai1.y1, 2);
		toaDoSuriken(w[3].cDai2.x1, w[3].cDai2.y1, 3);
		toaDoSuriken(w[3].cNgan1.x2, w[3].cNgan1.y2, 4);
		toaDoSuriken(w[3].cGiua.x1, w[3].cDai1.y1, 5);
		toaDoSuriken(w[3].cNgan2.x2, w[3].cNgan2.y2, 6);
		toaDoSuriken(w[3].hTron.x1, w[3].hTron.y1, 7);
		toaDoSuriken(w[3].hTron.x2, w[3].hTron.y2, 8);
		
		lineMidPoint(w[3].cDai1.x1, w[3].cDai1.y1, w[3].cDai1.x2, w[3].cDai1.y2,0, false);
		lineMidPoint(w[3].cDai2.x1, w[3].cDai2.y1, w[3].cDai2.x2, w[3].cDai2.y2,0, false);
		lineMidPoint(w[3].cGiua.x1, w[3].cGiua.y1, w[3].cGiua.x2, w[3].cGiua.y2,0, false);
		lineMidPoint(w[3].cNgan1.x1, w[3].cNgan1.y1, w[3].cNgan1.x2, w[3].cNgan1.y2,0, false);
		lineMidPoint(w[3].cNgan2.x1, w[3].cNgan2.y1, w[3].cNgan2.x2, w[3].cNgan2.y2,0, false);
		drawCircleMidpoint(w[3].hTron.x1, w[3].hTron.y1, w[3].hTron.x2, w[3].hTron.y2,0, false);
		if(i == 4) break;
		lineMidPoint(w[3].cDai1.x1, w[3].cDai1.y1, w[3].cDai1.x2, w[3].cDai1.y2,15, true);
		lineMidPoint(w[3].cDai2.x1, w[3].cDai2.y1, w[3].cDai2.x2, w[3].cDai2.y2,15, true);
		lineMidPoint(w[3].cGiua.x1, w[3].cGiua.y1, w[3].cGiua.x2, w[3].cGiua.y2,15, true);
		lineMidPoint(w[3].cNgan1.x1, w[3].cNgan1.y1, w[3].cNgan1.x2, w[3].cNgan1.y2,15, true);
		lineMidPoint(w[3].cNgan2.x1, w[3].cNgan2.y1, w[3].cNgan2.x2, w[3].cNgan2.y2,15, true);
		drawCircleMidpoint(w[3].hTron.x1, w[3].hTron.y1, w[3].hTron.x2, w[3].hTron.y2,15, true);
	    w[3].cDai1 = tinhTien(w[3].cDai1, -30, 0);
		w[3].cDai2 = tinhTien(w[3].cDai2, -30, 0);
		w[3].cGiua = tinhTien(w[3].cGiua, -30, 0);
	    w[3].cNgan1 = tinhTien(w[3].cNgan1, -30, 0);
	    w[3].cNgan2 = tinhTien(w[3].cNgan2, -30, 0);
	    w[3].hTron = tinhTien(w[3].hTron, -30, 0);
	    if(i >= 2){
			drawCircleMidpoint(650, 350, 690, 350, 0, false);
			lineMidPoint(700, 300, 680, 320, 0, false);//canh trai ngan
			lineMidPoint(700, 400, 680, 380, 0, false);// canh phai ngan
		}
	}
	drawCircleMidpoint(650, 350, 685, 345, 0, false);
	flag1 = false;
	delay(100);
	spinSuriken(flag1);
}

void spinSuriken(bool &flag1){
	ganGiaTri1(600, 300, 650, 140, 0, 1);// canh trai
	ganGiaTri1(700, 300, 650, 140, 0, 2);//canh phai
	ganGiaTri1(650, 310, 650, 140, 0, 3);// canh giua
	ganGiaTri1(600, 300, 620, 320, 0, 4);//canh trai ngan
	ganGiaTri1(700, 300, 680, 320, 0, 5);// canh phai ngan
	ganGiaTri1(650, 350, 690, 350, 0, 6);	
	//canh duoi
	ganGiaTri1(600, 400, 650, 560, 1, 1);// canh trai
	ganGiaTri1(700, 400, 650, 560, 1, 2);//canh phai
	ganGiaTri1(650, 390, 650, 560, 1, 3);// canh giua
	ganGiaTri1(600, 400, 620, 380, 1, 4);//canh trai ngan
	ganGiaTri1(700, 400, 680, 380, 1, 5);// canh phai ngan
	ganGiaTri1(650, 350, 685, 345, 1, 6);
	//canh trai
	ganGiaTri1(600, 300, 440, 350, 2, 1);// canh trai
	ganGiaTri1(600, 400, 440, 350, 2, 2);//canh phai
	ganGiaTri1(610, 350, 440, 350, 2, 3);// canh giua
	ganGiaTri1(600, 400, 620, 380, 2, 4);//canh trai ngan
	ganGiaTri1(600, 300, 620, 320, 2, 5);// canh phai ngan
	//canh phai
	ganGiaTri1(700, 300, 860, 350, 3, 1);// canh trai
	ganGiaTri1(700, 400, 860, 350, 3, 2);//canh phai
	ganGiaTri1(690, 350, 860, 350, 3, 3);// canh giua
	ganGiaTri1(700, 300, 680, 320, 3, 4);//canh trai ngan
	ganGiaTri1(700, 400, 680, 380, 3, 5);// canh phai ngan
	
	int a, b;
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
			if(a >= 4 && a <= 292 && b >= 570 && b <= 594){
				flag1 = true;
			}
    	}
    	delay(100);
    	clearPoint();
    	
		xoaInfor();
		giaoDienSuriken(5, 1);
		
		toaDoSuriken(w1[0].cDai1.x2, w1[0].cDai1.y2, 1);
		toaDoSuriken(w1[2].cDai1.x2, w1[0].cDai1.y2, 2);
		toaDoSuriken(w1[1].cDai1.x2, w1[0].cDai1.y2, 3);
		toaDoSuriken(w1[3].cDai1.x2, w1[0].cDai1.y2, 4);
		
		toaDoSuriken(w1[0].cDai1.x1, w1[0].cDai1.y1, 5);
		toaDoSuriken(w1[2].cDai1.x1, w1[2].cDai1.y1, 6);
		toaDoSuriken(w1[1].cDai1.x1, w1[1].cDai1.y1, 9);
		toaDoSuriken(w1[3].cDai1.x1, w1[3].cDai1.y1, 10);
		
		toaDoSuriken(w1[0].cGiua.x1, w1[0].cGiua.y1, 11);
		toaDoSuriken(w1[0].cNgan1.x2, w1[2].cNgan1.y2, 12);
		toaDoSuriken(w1[2].cGiua.x1, w1[2].cGiua.y1, 13);
		toaDoSuriken(w1[2].cNgan1.x2, w1[2].cNgan1.y2, 14);
		toaDoSuriken(w1[1].cGiua.x1, w1[1].cGiua.y1, 15);
		toaDoSuriken(w1[1].cNgan1.x2, w1[1].cNgan1.y2, 16);
		toaDoSuriken(w1[3].cGiua.x1, w1[3].cGiua.y1, 17);
		toaDoSuriken(w1[3].cNgan1.x2, w1[2].cNgan1.y2, 18);
		
		toaDoSuriken(w1[1].hTron.x1, w1[1].hTron.y1, 7);
		toaDoSuriken(w1[1].hTron.x2, w1[1].hTron.y2, 8);
		
		lineMidPoint(w1[0].cDai1.x1, w1[0].cDai1.y1, w1[0].cDai1.x2, w1[0].cDai1.y2,0, false);
		lineMidPoint(w1[0].cDai2.x1, w1[0].cDai2.y1, w1[0].cDai2.x2, w1[0].cDai1.y2,0, false);
		lineMidPoint(w1[0].cGiua.x1, w1[0].cGiua.y1, w1[0].cGiua.x2, w1[0].cGiua.y2,0, false);
		lineMidPoint(w1[0].cNgan1.x1, w1[0].cNgan1.y1, w1[0].cNgan1.x2, w1[0].cNgan1.y2,0, false);
		lineMidPoint(w1[0].cNgan2.x1, w1[0].cNgan2.y1, w1[0].cNgan2.x2, w1[0].cNgan2.y2,0, false);
		drawCircleMidpoint(w1[0].hTron.x1, w1[0].hTron.y1, w1[0].hTron.x2, w1[0].hTron.y2,0, false);
		//	
		lineMidPoint(w1[1].cDai1.x1, w1[1].cDai1.y1, w1[1].cDai1.x2, w1[1].cDai1.y2,0, false);
		lineMidPoint(w1[1].cDai2.x1, w1[1].cDai2.y1, w1[1].cDai2.x2, w1[1].cDai1.y2,0, false);
		lineMidPoint(w1[1].cGiua.x1, w1[1].cGiua.y1, w1[1].cGiua.x2, w1[1].cGiua.y2,0, false);
		lineMidPoint(w1[1].cNgan1.x1, w1[1].cNgan1.y1, w1[1].cNgan1.x2, w1[1].cNgan1.y2,0, false);
		lineMidPoint(w1[1].cNgan2.x1, w1[1].cNgan2.y1, w1[1].cNgan2.x2, w1[1].cNgan2.y2,0, false);
		drawCircleMidpoint(w1[1].hTron.x1, w1[1].hTron.y1, w1[1].hTron.x2, w1[1].hTron.y2,0, false);
		//
		lineMidPoint(w1[2].cDai1.x1, w1[2].cDai1.y1, w1[2].cDai1.x2, w1[2].cDai1.y2,0, false);
		lineMidPoint(w1[2].cDai2.x1, w1[2].cDai2.y1, w1[2].cDai2.x2, w1[2].cDai1.y2,0, false);
		lineMidPoint(w1[2].cGiua.x1, w1[2].cGiua.y1, w1[2].cGiua.x2, w1[2].cGiua.y2,0, false);
		lineMidPoint(w1[2].cNgan1.x1, w1[2].cNgan1.y1, w1[2].cNgan1.x2, w1[2].cNgan1.y2,0, false);
		lineMidPoint(w1[2].cNgan2.x1, w1[2].cNgan2.y1, w1[2].cNgan2.x2, w1[2].cNgan2.y2,0, false);
		//drawCircleMidpoint(w1[2].hTron.x1, w1[2].hTron.y1, w1[2].hTron.x2, w1[2].hTron.y2,0, false);
		lineMidPoint(w1[3].cDai1.x1, w1[3].cDai1.y1, w1[3].cDai1.x2, w1[3].cDai1.y2,0, false);
		lineMidPoint(w1[3].cDai2.x1, w1[3].cDai2.y1, w1[3].cDai2.x2, w1[3].cDai1.y2,0, false);
		lineMidPoint(w1[3].cGiua.x1, w1[3].cGiua.y1, w1[3].cGiua.x2, w1[3].cGiua.y2,0, false);
		lineMidPoint(w1[3].cNgan1.x1, w1[3].cNgan1.y1, w1[3].cNgan1.x2, w1[3].cNgan1.y2,0, false);
		lineMidPoint(w1[3].cNgan2.x1, w1[3].cNgan2.y1, w1[3].cNgan2.x2, w1[3].cNgan2.y2,0, false);
		//drawCircleMidpoint(w1[3].hTron.x1, w1[3].hTron.y1, w1[3].hTron.x2, w1[3].hTron.y2,0, false);
		if(flag1 == true) break;
		//
	    w1[0].cDai1 = bdQuay(w1[0].cDai1, 30, 650, 350);
	    w1[0].cDai2 = bdQuay(w1[0].cDai2, 30, 650, 350);
	    w1[0].cGiua = bdQuay(w1[0].cGiua, 30, 650, 350);
	    w1[0].cNgan1 = bdQuay(w1[0].cNgan1, 30, 650, 350);
	    w1[0].cNgan2 = bdQuay(w1[0].cNgan2, 30, 650, 350);
	    w1[0].hTron = bdQuay(w1[0].hTron, 30, 650, 350);
	    //
	    w1[1].cDai1 = bdQuay(w1[1].cDai1, 30, 650, 350);
	    w1[1].cDai2 = bdQuay(w1[1].cDai2, 30, 650, 350);
	    w1[1].cGiua = bdQuay(w1[1].cGiua, 30, 650, 350);
	    w1[1].cNgan1 = bdQuay(w1[1].cNgan1, 30, 650, 350);
	    w1[1].cNgan2 = bdQuay(w1[1].cNgan2, 30, 650, 350);
	    w1[1].hTron = bdQuay(w1[1].hTron, 30, 650, 350);
	    //
	    w1[2].cDai1 = bdQuay(w1[2].cDai1, 30, 650, 350);
	    w1[2].cDai2 = bdQuay(w1[2].cDai2, 30, 650, 350);
	    w1[2].cGiua = bdQuay(w1[2].cGiua, 30, 650, 350);
	    w1[2].cNgan1 = bdQuay(w1[2].cNgan1, 30, 650, 350);
	    w1[2].cNgan2 = bdQuay(w1[2].cNgan2, 30, 650, 350);
	    //w1[2].hTron = bdQuay(w1[2].hTron, 30);
	    w1[3].cDai1 = bdQuay(w1[3].cDai1, 30, 650, 350);
	    w1[3].cDai2 = bdQuay(w1[3].cDai2, 30, 650, 350);
	    w1[3].cGiua = bdQuay(w1[3].cGiua, 30, 650, 350);
	    w1[3].cNgan1 = bdQuay(w1[3].cNgan1, 30, 650, 350);
	    w1[3].cNgan2 = bdQuay(w1[3].cNgan2, 30, 650, 350);
	    //w1[3].hTron = bdQuay(w1[3].hTron, 30);
	} 
}

//ve Hinh Binh Hanh
void HBH(int x1, int y1, int x2, int y2, int x3, int y3, int color, bool del){
	int a, b, kCach;
	roundPixel(x1, y1);
	roundPixel(x2, y2);
	if(x1 == x2){
		kCach = abs(y1 - y2);
		if(y1 < y2){
			lineMidPoint(x2, y2, x1, y1, color, del);
			lineMidPoint(x1, y1, x3, y3, color, del);
			lineMidPoint(x3, y3, x3, y3 + kCach, color, del);
			lineMidPoint(x3, y3 + kCach, x2, y2, color, del);
		}else{
			lineMidPoint(x1, y1, x2, y2, color, del);
			lineMidPoint(x2, y2, x3, y3, color, del);
			lineMidPoint(x3, y3, x3, y3 + kCach, color, del);
			lineMidPoint(x3, y3 + kCach, x1, y1, color, del);
		}
	}
	if(y1 == y2){
		kCach = abs(x1 - x2);
		if(x1 < x2){
			lineMidPoint(x2, y2, x1, y1, color, del);
			lineMidPoint(x1, y1, x3, y3, color, del);
			lineMidPoint(x3, y3, x3 + kCach, y3, color, del);
			lineMidPoint(x3 + kCach, y3, x2, y2, color, del);
		}else{
			lineMidPoint(x1, y1, x2, y2, color, del);
			lineMidPoint(x2, y2, x3, y3, color, del);
			lineMidPoint(x3, y3, x3 + kCach, y3, color, del);
			lineMidPoint(x3 + kCach, y3, x1, y1, color, del);
		}
	}
	if(x1 != x2 && y1 != y2){
		a = abs(y1 - y2);
		b = abs(x2 - x3);
		if(y1 > y2){
			lineMidPoint(x1, y1, x2, y2, color, del);
			lineMidPoint(x2, y2, x3, y3, color, del);
			lineMidPoint(x3, y3, x1 + b, y3 + a, color, del);
			lineMidPoint(x1 + b, y3 + a, x1, y1, color, del);
		}else{
			lineMidPoint(x2, y2, x1, y1, color, del);
			lineMidPoint(x1, y1, x3, y3, color, del);
			lineMidPoint(x3, y3, x1 + b, y3 + a, color, del);
			lineMidPoint(x1 + b, y3 + a, x2, y2, color, del);
		}	
	}
}
void drawHBH(bool &flag1){
	int i = 0;
	int a, b;
	Point *p = new Point[3];
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
    	    if(a >= 301 && a <= 999 && b >= 0 && b <= 700){
        	   	putPixel(a, b, 0);
        	   	p[i].x = a;
        	   	p[i].y = b;
        	   	i += 1;
        	   	if(i == 3){
					HBH(p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y, 0, false); 
					i = 0;	
				}
			}
			if(a >= 4 && a <= 292 && b >= 388 && b <= 412){
				veButton(388, 412, 12);
				outtextxy(7, 390, "PARALLELOGRAM");
				flag1 = true;
			}
    	}
    	if(flag1 == true) break;
	}
}
//ve hinh elips
void tinhBK(int &bk, int ac, int b){
//	roundPixel(ac, b);
	bk = abs(ac - b);
}

void drawElips(bool &flag1){
	int i = 0;
	int a, b;
	int bk1, bk2;
	Point *p = new Point[3];
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
    	    if(a >= 301 && a <= 999 && b >= 0 && b <= 700){
        	   	putPixel(a, b, 0);
        	   	p[i].x = a;
        	   	p[i].y = b;
        	   	i += 1;
        	   	if(i == 3){
        	   		tinhBK(bk1, p[0].x, p[1].x);
        	   		tinhBK(bk2, p[0].y, p[2].y);
					elipMidpoint(p[0].x, p[0].y, bk1, bk2, 0, false); 
					i = 0;	
				}
			}
			if(a >= 4 && a <= 292 && b >= 348 && b <= 372){
				veButton(348, 372, 12);
				outtextxy(7, 350, "         ELLIPSE");
				flag1 = true;
			}
    	}
    	if(flag1 == true) break;
	}
}
void plot(int xc, int yc, int x, int y, int color, bool del)
{
	if(del == true){
		delPixel(xc+x, yc+y, color);
	    delPixel(xc-x, yc+y, color);
	    delPixel(xc+x, yc-y, color);
	    delPixel(xc-x, yc-y, color);
	}else{
		putPixel(xc+x, yc+y, color);
	    putPixel(xc-x, yc+y, color);
	    putPixel(xc+x, yc-y, color);
	    putPixel(xc-x, yc-y, color);
	}
}
void elipMidpoint(int xc,int yc, int a, int b, int color, bool del)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    plot(xc, yc, x, y, color, del);
    p = ROUND(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        plot(xc, yc, x, y, color, del);
    }
    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
        y--;
        fy -= 2*a2; 
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        plot(xc, yc, x, y, color, del);
    }
}

void elipMidpointND(int xc,int yc, int a, int b, int color, bool del)
{
	int dem = 0;
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    dem++;
    if(dem == 9){
       	delPixel(xc+x, yc-y, color);
    	delPixel(xc-x, yc-y, color);
    	dem = 0;
	}
    p = ROUND(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        dem++;
        if(dem == 9){
        	delPixel(xc+x, yc-y, color);
	    	delPixel(xc-x, yc-y, color);
	    	dem = 0;
		}
    }
    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
        y--;
        fy -= 2*a2;
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        dem++;
        if(dem == 9){
        	delPixel(xc+x, yc-y, color);
	    	delPixel(xc-x, yc-y, color);
	    	dem = 0;
		}
    }
}
//ve hinh tron
void drawHinhTron(bool &flag1){
	int i = 0;
	int a, b;
	Point *p = new Point[2];
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
    	    if(a >= 301 && a <= 999 && b >= 0 && b <= 700){
        	   	putPixel(a, b, 0);
        	   	cout << a << ":" << b;
        	   	p[i].x = a;
        	   	p[i].y = b;
        	   	i += 1;
        	   	if(i == 2){
        	   		drawCircleMidpoint(p[0].x, p[0].y, p[1].x, p[1].y, 0, false);
					i = 0;	
				}
			}
			if(a >= 4 && a <= 292 && b >= 308 && b <= 332){
				veButton(308, 332, 12);
				outtextxy(7, 310, "          CIRCLE");
				flag1 = true;
			}
    	}
    	if(flag1 == true) break;
	}
}

void put8pixel(int xc, int yc, int x, int y, int color, bool del){
	roundPixel(xc, yc);
	roundPixel(x, y);
	if(del == true){
		delPixel(x + xc, y + yc, color);
	    delPixel(-x + xc, y + yc, color);
	    delPixel(x + xc, -y + yc, color);
	    delPixel(-x + xc, -y + yc, color);
	    delPixel( y + xc, x + yc, color);
	    delPixel(-y + xc, x + yc, color);
	    delPixel(y + xc, -x + yc, color);
	    delPixel(-y + xc, -x + yc, color);
	}else{
		putPixel(x + xc, y + yc, color);
	    putPixel(-x + xc, y + yc, color);
	    putPixel(x + xc, -y + yc, color);
	    putPixel(-x + xc, -y + yc, color);
	    putPixel( y + xc, x + yc, color);
	    putPixel(-y + xc, x + yc, color);
	    putPixel(y + xc, -x + yc, color);
	    putPixel(-y + xc, -x + yc, color);
	}
}

void drawCircleMidpoint(int xc, int yc, int x,int y, int color, bool del){
	int R=sqrt(pow((x-xc),2)+pow((y-yc),2));
	x=0; y=R;
    int p = (5/4) - R;
    put8pixel(xc, yc, x, y, color, del);
    while (y>x)
    {
        if (p < 0) p+=2*x+3;
        else
        {
            p += 2*(x-y)+5;
            y--;
        }
        x++;
        put8pixel(xc, yc, x, y, color, del);
    }
}
//ve hinh chu nhat
void HCN(int x1, int y1, int x2, int y2, int color, bool del){
	lineMidPoint(x1, y1, x1, y2, color, del);
	lineMidPoint(x1, y2, x2, y2, color, del);
	lineMidPoint(x2, y2, x2, y1, color, del);
	lineMidPoint(x2, y1, x1, y1, color, del);
}
void drawHCN(bool &flag1){
	int i = 0;
	int a, b;
	Point *p = new Point[2];
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
    	    if(a >= 301 && a <= 999 && b >= 0 && b <= 700){
        	   	putPixel(a, b, 0);
        	   	p[i].x = a;
        	   	p[i].y = b;
        	   	i += 1;
        	   	if(i == 2){
        	   		HCN(p[0].x, p[0].y, p[1].x, p[1].y, 0, false);
					i = 0;	
				}
			}
			if(a >= 4 && a <= 292 && b >= 228 && b <= 252){
				veButton(228, 252, 12);
				outtextxy(7, 230, "      RECTANGLE");
				flag1 = true;
			}
    	}
    	if(flag1 == true) break;
	}
}
//ve tam giac
bool dieuKienTamGiac(int x1, int y1, int x2, int y2, int x3, int y3){
	roundPixel(x1, y1);
	roundPixel(x2, y2);
	roundPixel(x3, y3);
	cout << x1 << x2 << x3 << endl;
	cout << y1 << y2 << y3;
	if(x1 == x2 && x2 == x3) return false;
	if(y1 == y2 && y2 == y3) return false;
	return true;
}

void tamGiac(int x1, int y1, int x2, int y2, int x3, int y3, int color, bool del){
	lineMidPoint(x1, y1, x2, y2, color, del);
	lineMidPoint(x2, y2, x3, y3, color, del);
	lineMidPoint(x3, y3, x1, y1, color, del);
}

void drawTamGiac(bool &flag1){
	int i = 0;
	int a, b;
	Point *p = new Point[3];
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
    	    if(a >= 301 && a <= 999 && b >= 0 && b <= 700){
        	   	putPixel(a, b, 0);
        	   	p[i].x = a;
        	   	p[i].y = b;
        	   	i += 1;
        	   	if(i == 3){
        	   		if(dieuKienTamGiac(p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y) == false){
        	   			outtextxy(1010, 652, "      ERROR!");	
					}else{
						tamGiac(p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y, 0, false);
					} 
					i = 0;	
				}
			}
			if(a >= 4 && a <= 292 && b >= 268 && b <= 292){
				veButton(268, 292, 12);
				outtextxy(7, 270, "       TRIANGLE");
				flag1 = true;
			}
    	}
    	if(flag1 == true) break;
	}
}
//ve hinh vuong
void HV(int x1, int y1, int x2, int y2, int color, bool del){
	roundPixel(x1, y1);
	roundPixel(x2, y2);
	int kCach;
	//ve sang phai
	if(x1 == x2){
		kCach = abs(y1 - y2);
		lineMidPoint(x1, y1, x1, y2, color, del);
		lineMidPoint(x1, y2, x2 + kCach, y2, color, del);
		lineMidPoint(x2 + kCach, y2, x2 + kCach, y1, color, del);
		lineMidPoint(x2 + kCach, y1, x1, y1, color, del);
	}
	//ve xuong duoi
	if(y1 == y2){
		kCach = abs(x1 - x2);
		lineMidPoint(x1, y1, x2, y2, color, del);
		lineMidPoint(x2, y2 , x2, y2 + kCach, color, del);
		lineMidPoint(x2, y2 + kCach, x1, y1 + kCach, color, del);
		lineMidPoint(x1, y1 + kCach, x1, y1, color, del);
	}
}

void drawHV(bool &flag1){
	int i = 0;
	int a, b;
	Point *p = new Point[2];
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
    	    if(a >= 301 && a <= 999 && b >= 0 && b <= 700){
        	   	putPixel(a, b, 0);
        	   	p[i].x = a;
        	   	p[i].y = b;
        	   	i += 1;
        	   	if(i == 2){
        	   		HV(p[0].x, p[0].y, p[1].x, p[1].y, 0, false);
					i = 0;	
				}
			}
			if(a >= 4 && a <= 292 && b >= 188 && b <= 212){
				veButton(188, 212, 12);
				outtextxy(7, 190, "         SQUARE");
				flag1 = true;
			}
    	}
    	if(flag1 == true) break;
	}
}
// ve duong thang
void drawLine(bool &flag1){
	int i = 0;
	int a, b;
	Point *p = new Point[2];
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
    	    if(a >= 301 && a <= 999 && b >= 0 && b <= 700){
        	   	putPixel(a, b, 0);
        	   	p[i].x = a;
        	   	p[i].y = b;
        	   	i += 1;
        	   	if(i == 2){
        	   		lineMidPoint(p[0].x, p[0].y, p[1].x, p[1].y, 0, false);
					i = 0;	
				}
			}
			if(a >= 4 && a <= 292 && b >= 148 && b <= 172){
				veButton(148, 172, 12);
				outtextxy(7, 150, "             LINE");
				flag1 = true;
			}
    	}
    	if(flag1 == true) break;
	}
}

void lineMidPoint(int x1, int y1, int x2, int y2, int color, bool del){
	roundPixel(x1, y1);
	roundPixel(x2, y2);
	int x, y, dX, dY, d1, d2, fabsdX, fabsdY, xE, yE;
	dX = x2 - x1;
	dY = y2 - y1;
	fabsdX = fabs(double(dX));
	fabsdY = fabs(double(dY));
	d1 = fabsdY - (fabsdX >> 1);
	d2 = fabsdX - (fabsdY >> 1);

	int xUnit, yUnit;
	float m = float(dY) / dX;

	if (m < 0){
		xUnit = yUnit = -1;
	}
	else{
		xUnit = yUnit = 1;
	}

	if (fabsdY <= fabsdX){
		if (dX >= 0){
			x = x1;
			y = y1;
			xE = x2;
		}
		else{
			x = x2;
			y = y2;
			xE = x1;
		}
		if(del == true){
			delPixel(x, y, color);
		}else{
			putPixel(x, y, color);
		}
		for (x; x < xE; x++){
			if (d1 <= 0) d1 += fabsdY;
			else{
				y += yUnit;
				d1 += (fabsdY - fabsdX);
			}
			if(del == true){
				delPixel(x, y, color);
			}else{
				putPixel(x, y, color);
			}
		}
	}
	else{
		if (dY >= 0){
			x = x1;
			y = y1;
			yE = y2;
		}
		else{
			x = x2;
			y = y2;
			yE = y1;
		}
		if(del == true){
			delPixel(x, y, color);
		}else{
			putPixel(x, y, color);
		}
		for (y; y < yE; y++){
			if (d2 <= 0)	d2 += fabsdX;
			else{
				x += xUnit;
				d2 += (fabsdX - fabsdY);
			}
			if(del == true){
				delPixel(x, y, color);
			}else{
				putPixel(x, y, color);
			}
		}
	}
}

void lineHidePoints(int x1, int y1, int x2, int y2, int color){
	int dem=0;
	roundPixel(x1, y1);
	roundPixel(x2, y2);
	int x, y, dX, dY, d1, d2, fabsdX, fabsdY, xE, yE;
	dX = x2 - x1;
	dY = y2 - y1;
	fabsdX = fabs(double(dX));
	fabsdY = fabs(double(dY));
	d1 = fabsdY - (fabsdX >> 1);
	d2 = fabsdX - (fabsdY >> 1);

	int xUnit, yUnit;
	float m = float(dY) / dX;

	if (m < 0){
		xUnit = yUnit = -1;
	}
	else{
		xUnit = yUnit = 1;
	}

	if (fabsdY <= fabsdX){
		if (dX >= 0){
			x = x1;
			y = y1;
			xE = x2;
		}
		else{
			x = x2;
			y = y2;
			xE = x1;
		}
			delPixel(x, y, color);
		for (x; x < xE; x++){
			dem++;
			if (d1 <= 0) d1 += fabsdY;
			else{
				y += yUnit;
				d1 += (fabsdY - fabsdX);
			}
			if(dem==3){
				delPixel(x,y,15);
				dem=0;
			}else{
				delPixel(x,y,color);
			}
			
		}
	}
	else{
		if (dY >= 0){
			x = x1;
			y = y1;
			yE = y2;
		}
		else{
			x = x2;
			y = y2;
			yE = y1;
		}

			delPixel(x, y, color);
		for (y; y < yE; y++){
			dem++;
			if (d2 <= 0)	d2 += fabsdX;
			else{
				x += xUnit;
				d2 += (fabsdX - fabsdY);
			}
			if(dem == 3){
				delPixel(x, y, 15);
				dem=0;
			}else{
				delPixel(x, y, color);
			}
		}
	}
}
// ve diem
void drawPoint(bool &flag1){
	int a, b;
	while (1){
        delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	    	getmouseclick(WM_LBUTTONDOWN, a, b);
    	    if(a >= 301 && a <= 999 && b >= 0 && b <= 700){
        	   	putPixel(a, b, 0);
			}
			if(a >= 4 && a <= 292 && b >= 108 && b <= 132){
				veButton(108, 132, 12);
				outtextxy(7, 110, "           	 POINT");
				flag1 = true;
			}
    	}
    	if(flag1 == true) break;
	}
}
