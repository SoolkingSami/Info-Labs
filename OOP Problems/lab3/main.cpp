#include <conio.h>
#include <iostream>

using namespace std;

class Punct {
private:
    float x;
    float y;

public:
    Punct();
    Punct(float x , float y);
//    Punct(float x=0 , float y=0);
    ~Punct();
    void afisare();
};

Punct::Punct() {
    x = 0;
    y = 0;
    cout << "Apel constructor Implicit pentru clasa Punct("<<x<<","<<y<<")"<<endl;
}

Punct::Punct(float x, float y) {
    this->x = x;
    this->y = y;
    cout << "Apel constructor cu parametri pentru clasa Punct("<<x<<","<<y<<")"<<endl;
}

/*
Punct::Punct(float x, float y) {
this -> x = x;
this -> y = y;
cout << "Apel constructor cu parametri pentru clasa Punct("<<x<<","<<y<<")"<<endl;
}
*/

Punct::~Punct() {
    cout << "Apel destructor clasa Punct. Se distruge obiectul Punct("<<x<<","<<y<<")" <<endl;
}

void Punct::afisare() {
    cout<<"("<<x<<","<<y<<")";
}

class Segment {
    Punct o;
    Punct v;

public:
    Segment (float x1, float y1, float x2, float y2);
    Segment(const Punct& o, const Punct& v);
    ~Segment();
    void afisare();
};

Segment::Segment(float x1, float y1, float x2, float y2) : o(x1 ,y1), v(x2,y2) {
    cout << "Apel constructor clasa Segment" << endl;
    cout << "Creat obiectul ";
    afisare();
}

Segment::Segment(const Punct& _o, const Punct& _v) : o(_o), v(_v) {
    cout << "Apel constructor clasa Segment" << endl;
    cout << "Creat obiectul ";
    afisare();
}

Segment::~Segment() {
    cout << "Apel destructor clasa Segment" << endl;
}

void Segment::afisare() {
    cout << "[" ; o.afisare(); cout << " , " ; v.afisare(); cout << "]" << endl;
}

int main() {
    Segment s(0, 0, 3 ,4);
    s.afisare();
    getch();
    return 0;
}