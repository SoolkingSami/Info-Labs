#include <iostream>
#include <cmath>
#include <iomanip>

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
    float getX();
    float getY();
    float getDistance(Punct p);
    void setX(float _x);
    void setY(float _y);

    friend float getDistance(Punct p1, Punct p2);
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

Punct::~Punct() {
    cout << "Apel destructor clasa Punct. Se distruge obiectul Punct("<<x<<","<<y<<")" <<endl;
}

void Punct::afisare() {
    cout<<"("<<x<<","<<y<<")";
}

float Punct::getX() {
    return x;
}

float Punct::getY() {
    return y;
}

float Punct::getDistance(Punct p) {
    return sqrt(pow(x - p.getX(),2) + pow(y - p.getY(),2));
}

float getDistance(Punct p1, Punct p2) {
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
}

void Punct::setX(float _x) {
    x = _x;
}

void Punct::setY(float _y) {
    y = _y;
}

class Segment {
    Punct o;
    Punct v;

public:
    Segment (float x1, float y1, float x2, float y2);
//    Segment(const Punct& o, const Punct& v);
    ~Segment();
    void afisare();
    float getDistance();
};

Segment::Segment(float x1, float y1, float x2, float y2) : o(x1 ,y1), v(x2,y2) {
    cout << "Apel constructor clasa Segment" << endl;
    cout << "Creat obiectul ";
    afisare();
}

/*Segment::Segment(const Punct& _o, const Punct& _v) : o(_o), v(_v) {
    cout << "Apel constructor clasa Segment" << endl;
    cout << "Creat obiectul ";
    afisare();
}*/

Segment::~Segment() {
    cout << "Apel destructor clasa Segment" << endl;
}

void Segment::afisare() {
    cout << "[" ; o.afisare(); cout << " , " ; v.afisare(); cout << "]" << endl;
}

float Segment::getDistance() {
    return sqrt(pow(v.getX() - o.getX(), 2) + pow(v.getY() - o.getY(), 2));
}

int main() {
    Segment s(0, 0, 3 ,4);
    s.afisare();
    cout << "Lungimea segmentului: " << fixed << setprecision(2) << s.getDistance() << endl;

    cout << endl;
    Punct p(1,1), q(4, 5);
    cout << "Distante dintre puncte: " << fixed << setprecision(2) << getDistance(p, q) << endl;

    getchar();
    return 0;
}