#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <graphics.h> 
#include <conio.h> 
#define nmax 40 
typedef struct{ 
 float x,y; 
}vector; 
typedef struct{ 
 float x,y;
}punct; 
int n; 
void desenare_triunghi(punct A,punct B,punct C,int culoare){  setcolor(culoare); 
 moveto(A.x,A.y);  
 lineto(B.x,B.y); 
 lineto(C.x,C.y); 
 lineto(A.x,A.y); 
 outtextxy(A.x+3,A.y+3,"A"); 
 outtextxy(B.x+3,B.y+3,"B"); 
 outtextxy(C.x+3,C.y+3,"C"); 
 getch(); 
} 
float produs_scalar(vector u,vector v){ 
 return (u.x*v.x+u.y*v.y); 
} 
vector scade(punct A,punct B){ 
 vector v; 
 v.x=A.x-B.x; 
 v.y=A.y-B.y; 
 return v; 
} 
float dist(punct a,punct b){ 
 return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)); } 
float tangenta(punct A,punct B,punct C){ 
 vector u=scade(A,B),v=scade(C,B); 
 return sqrt(produs_scalar(u,u)*produs_scalar(v,v)- produs_scalar(u,v)*produs_scalar(u,v))/produs_scalar(u,v); } 
punct centru_cerc(punct A,punct B,punct C){ 
 vector v1=scade(B,A); 
 vector v2=scade(C,B); 
 vector v3=scade(A,C); 
 punct o; 
if(produs_scalar(v1,v3)==0){ 
 o.x=(B.x+C.x)/2; 
 o.y=(B.y+C.y)/2; 
 return o; 
} 
 if(produs_scalar(v1,v2)==0){ 
 o.x=(A.x+C.x)/2; 
 o.y=(A.y+C.y)/2; 
 return o; 
} 
 if(produs_scalar(v2,v3)==0){ 
 o.x=(B.x+A.x)/2; 
 o.y=(B.y+A.y)/2;
 return o; 
} 
 float ta=tangenta(B,A,C),tb=tangenta(A,B,C),tc=tangenta(A,C,B);  float suma=ta+tb+tc; 
 o.x=((tb+tc)*A.x+(ta+tc)*B.x+(ta+tb)*C.x)/(2*suma);  o.y=((tb+tc)*A.y+(ta+tc)*B.y+(ta+tb)*C.y)/(2*suma);  return o; 
} 
void mediatoare(punct A,punct B,punct C,int culoare){ //deseneaza mediatoarea laturilor 
punct F; 
punct O=centru_cerc(A,B,C); 
F.x=(A.x+B.x)/2; 
F.y=(A.y+B.y)/2; 
setcolor(culoare); 
line(O.x,O.y,F.x,F.y); 
} 
void mediatoare_triunghi(punct a,punct b,punct c,int culoare){ 
mediatoare(a,b,c,culoare); 
mediatoare(b,c,a,culoare); 
mediatoare(c,a,b,culoare); 
} 
void cerc(punct A,punct B,punct C){ 
punct O=centru_cerc(A,B,C); 
float raza=dist(O,A); 
setcolor(3); 
circle(O.x,O.y, raza); 
outtextxy(O.x,O.y,"0"); 
} 
int main(){ 
punct A,B,C,O; 
srand(time(NULL));
A.x=100+rand()%500; 
A.y=100+rand()%500; 
B.x=100+rand()%500; 
B.y=100+rand()%500; 
C.x=100+rand()%500; 
C.y=100+rand()%500; 
initwindow(800,600, "Centrul cercului circumscris",200,200);  setbkcolor(15); 
cleardevice(); 
desenare_triunghi(A,B,C,1); 
mediatoare_triunghi(A,B,C,4); 
cerc(A,B,C); 
getch(); 
closegraph(); 
return 0; 
}
