//Curs 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
#define nmax 40

typedef struct{
  float x,y;
 }vector;

typedef struct{
  float x,y;
 }punct;

typedef struct {
  punct a, b;
}segment;

punct A,B,C;   // A=(A.x, A.y)
vector v, w;   //  v=(v.x, v.y);   v=AB; v=B-A= (B.x-A.x  , B.y-A.y  )
int n;


//OA+AB= OB  => AB= OB-OA

vector aduna(vector v, vector w)
{ vector s;
   s.x=v.x+w.x;   s.y=v.y+w.y;  
    return s;   
       }

vector inmultire(float a, vector v){ // W = a *V  => |W|= a*|V|
       vector w;
       w.x=a*v.x; w.y = a*v.y;
       return w;
       }
//  A(A.x, A.y)  B(B.x,  B.y)  =>  C=  qA+ (1-q) B apartine dreptei AB , C (  q*A.x+ (1-q*B.x) , q*A.y+ (1-q*B.y) ) => AC/AB=q 
// mijlocul lui AB este (0.5*A+0.5*B)

punct mijloc(punct, punct);

punct centru_greutate(punct A, punct B, punct C) {
  punct G = {(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3};
  return G;
}

void draw_point(punct P, int culoare) {
  circle(P.x, P.y, 4);
  floodfill(P.x, P.y, culoare);
}

void desenare_mediane(punct A, punct B, punct C, int culoare) {
    setcolor(culoare);
    punct P = mijloc(A,B), M = mijloc(B,C), N = mijloc(C,A);
    segment M3 = {C, P}, M1 = {A, M}, M2 = {B, N};
    line(M1.a.x, M1.a.y, M1.b.x, M1.b.y);
    line(M2.a.x, M2.a.y, M2.b.x, M2.b.y);
    line(M3.a.x, M3.a.y, M3.b.x, M3.b.y);

    setfillstyle(SOLID_FILL, culoare);
    draw_point(M1.a, culoare);
    draw_point(M1.b, culoare);
    draw_point(M2.a, culoare);
    draw_point(M2.b, culoare);
    draw_point(M3.a, culoare);
    draw_point(M3.b, culoare);
    punct G = centru_greutate(A,B,C);
    draw_point(G, culoare);

    outtextxy(M1.b.x+3,M1.b.y+3,"M");
    outtextxy(M2.b.x+3,M2.b.y+3,"N");
    outtextxy(M3.b.x+3,M3.b.y+3,"P");
    outtextxy(G.x+3,G.y+3,"G");
}

void desenare_triunghi(punct A,punct B,punct C,int culoare){
     setcolor(culoare);
     moveto(A.x,A.y);  
     lineto(B.x,B.y);
     lineto(C.x,C.y);
     lineto(A.x,A.y);
     setcolor(BLUE);
     outtextxy(A.x+3,A.y+3,"A");
     outtextxy(B.x+3,B.y+3,"B");
     outtextxy(C.x+3,C.y+3,"C");
     //getch();
}

float produs_scalar(vector u,vector v){  //  u=(u.x , u.y), v= ( v.x , v.y)   <u, v> = u * v, 
  return (u.x*v.x+u.y*v.y);
}

vector scade(punct A,punct B){  // v=BA
  vector v;
  v.x=A.x-B.x;
  v.y=A.y-B.y;
  return v;
}

float norma(vector v)
 {return  sqrt( produs_scalar(v,v));  // <v,v>  = | v|^2 
         }

float dist(punct A,punct B){
   return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));  // sqrt(produs_scalar(scade(B,A), scade(B,A)))
}

float cosinus(vector u, vector v){
       return produs_scalar(u,v)/ sqrt(produs_scalar(u,u)*produs_scalar(v,v));
}


int perpendiculare (punct A, punct B, punct C, punct D) // daca AB e perpendicular pe CD
  { vector u, v;
     float ps;
     u= scade(A, B); v = scade(C,D);
     ps= produs_scalar(u,v);
     if(ps) return 0;
         else return 1;      // ~return (!ps);  
   }
   
int coliniare (punct A, punct B, punct C){
    vector v,u;
    u=scade(A,C); //u= CA
    v=scade(B,C); // v= CB
    if (  abs(produs_scalar(u,v)) == norma(u)*norma(v)   ) return 1 ; //   A, C,B - coliniare
                else return 0; // necoliniare
    
    }   
   

float tangenta(punct A,punct B,punct C){  // tan(A,B,C)
  vector u=scade(A,B),v=scade(C,B);  
  // tan(u, v) = sqrt(<u,u>*<v,v> - <u,v>^2)/<u,v>
  return sqrt(   produs_scalar(u,u)*produs_scalar(v,v)-produs_scalar(u,v)*produs_scalar(u,v)  )/produs_scalar(u,v);
}

float arie(punct A, punct B, punct C){
    float d1;
    d1=abs((float)(B.x-A.x)*(C.y-A.y)-(float)(C.x-A.x)*(B.y-A.y));
     return d1/2;
}

punct mijloc(punct A, punct B){
    punct M;
    M.x=(A.x+B.x)/2;
    M.y=(A.y+B.y)/2;
    return M;
}


int main(){
punct A,B,C,O;
//citire();
srand(time(NULL));
n=rand(); n=rand();
// A.x=100+rand()%500;
// A.y=100+rand()%500;
// B.x=100+rand()%500;
// B.y=100+rand()%500;
// C.x=100+rand()%500;
// C.y=100+rand()%500;

int width = 2000, height = 1000, left = 10, top = 10;

initwindow(width, height, "Triunghiuri", left, top); 
setbkcolor(WHITE);
cleardevice();

for (int i = 2; i <= 10; ++i) {
  A.x=100+rand()%500;
  A.y=100+rand()%500;
  B.x=100+rand()%500;
  B.y=100+rand()%500;
  C.x=100+rand()%500;
  C.y=100+rand()%500;
  desenare_triunghi(A,B,C,i);
  // desenare_mediane(A, B, C, GREEN); 
}

int x = (width + left) / 2, y = (height + top) / 2;
int start_angle = 0, end_angle = 360;
int x_rad = 300, y_rad = 100;

const int offset = 50;
int dom_start_x = x - x_rad + offset, dom_end_x = x + x_rad - offset,
    dom_start_y = y - y_rad + offset, dom_end_y = y + y_rad - offset;

setcolor(RED);
ellipse(x, y, start_angle, end_angle, x_rad, y_rad);

// setcolor(RED);
for (int i = 1; i <= 1000; ++i) {
  float curr_x = dom_start_x + rand() % (dom_end_x - dom_start_x + 1),
        curr_y = dom_start_y + rand() % (dom_end_y - dom_start_y + 1);

  using namespace std;
  cout << curr_x << " " << curr_y << endl;
  punct curr = {curr_x, curr_y};
  draw_point(curr, RED);
}

// printf("A=(%g,%g) \n", A.x, A.y);
// printf("B=(%g,%g) \n", B.x, B.y);
// printf("C=(%g,%g) \n", C.x, C.y);
// printf("Lungimile segmentelor AB=%g, BC=%g, CA=%g \n", dist(A,B), dist(B,C), dist(C,A)); 
// setcolor(BLUE);
// printf("Aria(ABC) = %g", arie(A,B,C) );


getch();
closegraph();

return 0;
}
