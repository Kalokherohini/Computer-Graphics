#include<iostream>
#include<graphics.h>
using namespace std;
class DDA 
{
		int x1,y1,x2,y2;
	public:
		DDA(int xx1,int yy1, int xx2, int yy2) 
		{
			x1=xx1;
			y1=yy1;
			x2=xx2;
			y2=yy2;
		}
		void read() 
		{
			cout<<"enter the x1 and y1 coordinates(start point):-";
			cin>>x1>>y1;
			cout<<"enter the x2 and y2 coordinates(end point):-";
			cin>>x2>>y2;
		}
		void drawline();
};
void DDA::drawline() 
{
	float dx=x2-x1;
	float dy=y2-y1;
	float length;
	
	if(abs(dx)>=abs(dy))
		length=abs(dx);
	else
		length=abs(dy);
		
	float xi=dx/length;
	float yi=dy/length;
	float x=x1;
	float y=y1;
	for(int i=1; i<=length; i++)
	 {
		putpixel(x,y,WHITE);
		x+=xi;
		y+=yi;
	}
}
class BCA 
{
		int xc,yc,r;
	public:
		BCA(int rr, int x1, int y1) 
		{
			r=rr;
			xc=x1;
			yc=y1;
		}
		void read()
		 {
			
			cout<<"enter the radious:-";
			cin>>r;
			cout<<"enter the x and y coordinates:-";
			cin>>xc>>yc;
		}
		void drawcircle();
		void plot8waysymmetry(int,int);
};

void BCA::plot8waysymmetry(int x,int y) 
{
	putpixel(x+xc,y+yc,WHITE);
	putpixel(y+yc,x+xc,WHITE);
	putpixel(xc-x,y+yc,WHITE);
	putpixel(y+yc,xc-x,WHITE);
	putpixel(x+xc,yc-y,WHITE);
	putpixel(yc-y,x+xc,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(yc-y,xc-x,WHITE);
}
void BCA::drawcircle() 
{
	int x=0,y=r;
	int d=3-2*r;
	putpixel(xc, yc, WHITE);
	while(x<=y) 
	{
		if(d<=0) 
		{
			d+=4*x+6;
			x++;

		}
		 else 
		{
			d+=4*(x-y)+10;
			x++;
			y--;
		}
		plot8waysymmetry(x,y);

	}
}
int main() 
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	BCA cicrle1(50,120,120),circle2(100,120,120);
	DDA line1(34,170,120,20),line2(206,170,120,20),line3(206,170,30,170);
	cicrle1.drawcircle();
	circle2.drawcircle();
	line1.drawline();
	line2.drawline();
	line3.drawline();
	delay(1000);
	getch();
	closegraph();
	return 0;
}
