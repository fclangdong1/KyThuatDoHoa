#pragma once
#define PI 3.141592654
#define ROUND(a) (int)(a+0.5)
// 1 diem
struct P{
	int x;
	int y;
};
typedef struct P Point;
// 1 canh
struct TP{
	int x1;// tam
	int y1;
	int x2;// ban kinh
	int y2;
};
typedef struct TP twoPoint;
// 1 canh phi tieu
struct W{
	twoPoint cDai1, cDai2, cNgan1, cNgan2, cGiua, hTron;
};
typedef struct W Wing;
//bua Thor
struct B{
	twoPoint cTren, cTrai, cDuoi, cPhai;
};
typedef struct B Bua;

struct T{
	twoPoint dau, than, tTrai1, tTrai2, tPhai1, tPhai2, cTrai, cPhai;
};
typedef struct T Thor;


void drawNon3D(int x, int y, int z);
void hinhNon(int x, int y, int z);
Point ToaDo3D(int x,int y,int z);
void drawHLP(int x, int y, int z);
void ToaDo3D_8D(int x,int y,int z);
void xoaInfor();
void clearPoint();
void roundPixel(int &x, int &y);

void nhanMaTran(double maTran[2][3], double maTran1[2][3], double maTran2[3][3]);
twoPoint tinhTien(twoPoint tp, int dx, int dy);
twoPoint bdQuay(twoPoint tp, int a, int x, int y);
twoPoint bdQuayTay(twoPoint tp, int a, int x, int y);

void toaDoThor(int xc, int yc, int i);
void giaoDienThor(int i, int k);
void ganGiaTriThor(int x1, int y1, int x2, int y2, int k);
void ganGiaTriBua(int x1, int y1, int x2, int y2, int i, int k);
void effectThor();
void drawThor();
void drawBua();
void buaBay();
void buaBayVe();
void drawThor1();

void ganGiaTri1(Wing w, int x1, int y1, int x2, int y2, int i, int k);
void ganGiaTri(Wing w, int x1, int y1, int x2, int y2, int i, int k);
void giaoDienSuriken(int i, int k);
void toaDoSuriken(int xc, int yc, int i);
void drawSuriken();
void effectSuriken(bool &flag1);
void spinSuriken(bool &flag1);
//void draw2DBD();
//void draw2D();

void HBH(int x1, int y1, int x2, int y2, int x3, int y3, int color, bool del);
void drawHBH(bool &flag1);
void drawElips(bool &flag1);
void plot(int xc, int yc, int x, int y, int color, bool del);
void elipMidpoint(int xc,int yc, int a, int b, int color, bool del);
void elipMidpointND(int xc,int yc, int a, int b, int color, bool del);
void drawHinhTron(bool &flag1);
void put8pixel(int xc, int yc, int x, int y, int color, bool del);
void drawCircleMidpoint(int xc, int yc, int x,int y, int color, bool del);
void HCN(int x1, int y1, int x2, int y2, int color, bool del);
void drawHCN(bool &flag1);
void tamGiac(int x1, int y1, int x2, int y2, int x3, int y3, int color, bool del);
void drawTamGiac(bool &flag1);
void HV(int x1, int y1, int x2, int y2, int color, bool del);
void drawHV(bool &flag1);
void drawLine(bool &flag1);
void drawPoint(bool &flag1);
void lineMidPoint(int x1, int y1, int x2, int y2, int color, bool del);
void lineHidePoints(int x1, int y1, int x2, int y2, int color);
void lineBresenham(int x1, int y1, int x2, int y2, int color);

void LineDDAan(int x1, int y1, int x2, int y2);
