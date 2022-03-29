#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14;

float x1,x2,yy1,yy2;
const float alpha = 3.1415/8;
int xemax,yemax;

int xe(float x)
 // normalizarea coocdonatei x
{return((int) floor((x-x1)/(x2-x1)*xemax));}

int ye(float y)
 // normalizarea coocdonatei y
{return((int) floor((yy2-y)/(yy2-yy1)*yemax));}

void axe()
{setcolor(15);
 line(xe(x1),ye(0),xe(x2),ye(0)); //axa ox
 line(xe(0),ye(yy1),xe(0),ye(yy2)); //axa oy
 outtextxy(xe(0)-16,ye(0)-15,"O");
 outtextxy(xe(x2)-20,ye(0)-20,"x");
   outtextxy(xe(x2)-6,ye(0)-7,">"); 
 outtextxy(xe(0)-15,ye(yy2)+15,"y");
  outtextxy(xe(0)-1,ye(yy2)+1,"^");

}

float l_x(float theta) {
      float sin_t=sin(theta);
      return alpha/(1+sin_t*sin_t);
      }
      
float l_y(float theta) {
      float sin_t=sin(theta);
      return alpha*cos(theta)/(1+sin_t*sin_t);
      }

void grafic() {
     float theta;
     float x, y;
     float pie = 3.1415;
     float h = 2*pie/4000;
     float r = 1.f;
     theta = 0;
     while (theta<=2*pie) {
           x = l_x(theta)*cos(theta);
           y = l_y(theta)*sin(theta);
           putpixel(xe(x),ye(y),14);
           theta+=h;
           }
  
 

}

int main()
{int gd,gm;
 printf("Limitele domeniului orizontal:\n");
 printf("x1="); scanf("%f",&x1);
 printf("x2="); scanf("%f",&x2);
 printf("Limitele domeniului vertical:\n");
 printf("y1="); scanf("%f",&yy1);
 printf("y2="); scanf("%f",&yy2);
 
 initwindow(800,800, "Exemplu lab 1",200,200); 
 setbkcolor(1);
 cleardevice();
 
 xemax=getmaxx(); yemax=getmaxy();
 axe(); 
 setcolor(1);
 grafic();

 printf("Exit!\n");
 getchar(); getchar();
 closegraph();
 return 0;
}
