#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14;

float x1,x2,yy1,yy2;
int xemax,yemax;

int xe(float x)
 // normalizarea coocdonatei x
{return((int) floor((x-x1)/(x2-x1)*xemax));}

int ye(float y)
 // normalizarea coocdonatei y
{return((int) floor((yy2-y)/(yy2-yy1)*yemax));}

void axe()
{setcolor(15);
 line(xe(x1),ye(0),xe(x2),ye(0));
 line(xe(0),ye(yy1),xe(0),ye(yy2));
 outtextxy(xe(0)-15,ye(0)-15,"O");
 outtextxy(xe(x2)-20,ye(0)-20,"x");
   outtextxy(xe(x2)-6,ye(0)-7,">");
 outtextxy(xe(0)-15,ye(yy2)+15,"y");
  outtextxy(xe(0)-1,ye(yy2)+1,"^");

}

float f(float theta){
 float pie=3.14;
 return (2*0.7*sin(theta)*tan(theta));
}


void grafic() {
     
  int i=10;
  int xa,ya,xb,yb,xc,yc,c;
  for (i=1;i<16;i++)
    { xa=rand()%20; ya=-rand()%20;
    printf("x%d= (%d , %d) \n", i, xa,ya);
     xb=rand()%20; yb=-rand()%20;
     xc=rand()%20; yc=-rand()%20;
     c= rand()%14+1;
     putpixel(xe(xa),ye(ya),c);
     putpixel(xe(xc),ye(yc),c);
    putpixel(xe(xb),ye(yb),c);
  }
     
 setcolor(4);
 outtextxy(xe(7)+10,ye(10)-10,"A");
 circle(xe(7),ye(10),2);
 setcolor(10);
 line(xe(7),ye(10),xe(1),ye(1));
 
 outtextxy(xe(10)+10,ye(4)-10,"B");
 circle(xe(1),ye(1),2);
 setcolor(15);
 line(xe(7),ye(10),xe(10),ye(4));
 
 outtextxy(xe(1)+10,ye(1)-10,"C");
 circle(xe(5),ye(4),2);
 setcolor(13);
 line(xe(10),ye(4),xe(1),ye(1));
}

int main()
{int gd,gm;
 
 printf("Limitele domeniului orizontal:\n");
 printf("x1="); scanf("%f",&x1);
 printf("x2="); scanf("%f",&x2);
 printf("Limitele domeniului vertical:\n");
 printf("y1="); scanf("%f",&yy1);
 printf("y2="); scanf("%f",&yy2);
 initwindow(800,600, "Exemplu lab 2",200,200); 
 setbkcolor(0);
 cleardevice();
 
 xemax=getmaxx(); yemax=getmaxy();
 axe(); 
 setcolor(14);
 grafic();

 getchar(); getchar();
 closegraph();
 return 0;
}