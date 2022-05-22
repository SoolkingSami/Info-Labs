//Curs 2
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

typedef struct {
  punct a, b;
}segment;

typedef struct {
    punct c;
    float r;
} cerc;

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

void dash_line(punct A, punct B) {
    setlinestyle(3, 0, 2);
    line(A.x, A.y, B.x, B.y);
    setlinestyle(0, 0, 0);
}

void draw_figure() {
    setcolor(MAGENTA);
    cerc C1 = {404, 450, 110};
    circle(C1.c.x, C1.c.y, C1.r);

    draw_point(C1.c, MAGENTA);
    outtextxy(C1.c.x - 10, C1.c.y, "O");

    setcolor(GREEN);
    punct C = {C1.c.x, C1.c.y - C1.r}, Cp = {C1.c.x, C1.c.y + C1.r};
    draw_point(C, GREEN);
    outtextxy(C.x, C.y - 10, "C");
    draw_point(Cp, GREEN);
    outtextxy(Cp.x, Cp.y + 10, "C'");
    dash_line(C, Cp);
    outtextxy(C.x - 10, (C.y + C1.c.y) / 2, "R");

    setcolor(LIGHTRED);
    cerc C2 = {576, 530, 80};
    circle(C2.c.x, C2.c.y, C2.r);

    draw_point(C2.c, LIGHTRED);
    outtextxy(C2.c.x + 30, C2.c.y + 10, "W");

    punct A = {C2.c.x, C2.c.y + C2.r};
    draw_point(A, LIGHTRED);
    outtextxy(A.x + 20, A.y + 30, "A");
    setcolor(GREEN);
    dash_line(C, A);
    dash_line(Cp, A);

    setcolor(YELLOW);
    line(C1.c.x, C1.c.y, C2.c.x, C2.c.y);
    punct T = {(C1.c.x + C2.c.x) / 2 + 12, (C1.c.y + C2.c.y) / 2 + 7};
    draw_point(T, YELLOW);
    outtextxy(T.x - 10, T.y + 20, "T");

    setcolor(CYAN);
    setlinestyle(0, 0, 2);
    line(Cp.x - 10, Cp.y + 50, C2.c.x + C2.r + 10, C2.c.y + C2.r);
    outtextxy(C2.c.x + C2.r + 10, C2.c.y + C2.r, "(D)");
    setlinestyle(0, 0, 0);

    setcolor(YELLOW);
    punct B = {A.x, A.y + C1.r}, Bp = {A.x, A.y - C1.r};
    draw_point(B, YELLOW);
    outtextxy(B.x + 25, B.y + 5, "B");
    draw_point(Bp, YELLOW);
    outtextxy(Bp.x + 20, Bp.y + 5, "B'");
    line(Bp.x, Bp.y, B.x, B.y);
    outtextxy((A.x + B.x) / 2 + 20, (A.y + B.y) / 2 + 10, "R");
    line(C1.c.x, C1.c.y, B.x, B.y);
    line(C1.c.x, C1.c.y, Bp.x, Bp.y);

    setcolor(CYAN);
    setlinestyle(0, 0, 2);
    line((C1.c.x + B.x) / 2 - 10, (C1.c.y + B.y) / 2 + 10, C2.c.x + 10, C2.c.y - 10);
    setlinestyle(0, 0, 0);

    setcolor(YELLOW);
    punct Tp = {Cp.x - 50, Cp.y - 10};
    draw_point(Tp, YELLOW);
    outtextxy(Tp.x - 10, Tp.y + 30, "T'");

    punct Wp = {Bp.x, Bp.y - 375};
    draw_point(Wp, YELLOW);
    outtextxy(Wp.x + 20, Wp.y + 30, "W'");
    line(Bp.x, Bp.y, Wp.x, Wp.y);
    line(Tp.x, Tp.y, Wp.x, Wp.y);

    setcolor(GREEN);
    dash_line(Wp, (punct){(C.x + A.x) / 2, (C.y + A.y) / 2});
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
    // punct A,B,C,O;
    // //citire();
    // //srand(time(NULL));
    // n=rand(); n=rand();
    // A.x=100+rand()%500;
    // A.y=100+rand()%500;
    // B.x=100+rand()%500;
    // B.y=100+rand()%500;
    // C.x=100+rand()%500;
    // C.y=100+rand()%500;

    initwindow(1200,800, "Figure 116, pag 201, vol 1",20,20); 
    setbkcolor(BLACK);
    cleardevice();

     // font style
    int font = 3;
    // font direction
    int direction = 2;
    // font size
    int font_size = 2;
    // for setting text style
    settextstyle(font, direction, font_size);


    // desenare_triunghi(A,B,C,RED);
    // desenare_mediane(A, B, C, GREEN); 
    // printf("A=(%g,%g) \n", A.x, A.y);
    // printf("B=(%g,%g) \n", B.x, B.y);
    // printf("C=(%g,%g) \n", C.x, C.y);
    // printf("Lungimile segmentelor AB=%g, BC=%g, CA=%g \n", dist(A,B), dist(B,C), dist(C,A)); 
    // setcolor(BLUE);
    // printf("Aria(ABC) = %g", arie(A,B,C) );

    draw_figure();

    getch();
    closegraph();

    return 0;
}
