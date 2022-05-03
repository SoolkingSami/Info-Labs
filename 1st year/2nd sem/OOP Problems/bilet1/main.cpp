#include <cstring>
#include <iostream>

using namespace std;

class Angajat{
protected:
    char *nume;
    int calificare;
    float salariu;
public:
    Angajat(char *nume, int calificare, float salariu);
    Angajat(const Angajat &a);
    ~Angajat();
    virtual void afisare();
    Angajat& operator =(Angajat &a);
};
Angajat::Angajat(char *nume, int calificare, float salariu){
    this -> nume = new char[strlen(nume)+1];
    strcpy(this -> nume, nume);
    this -> calificare = calificare;
    this -> salariu = salariu;
}
Angajat::Angajat(const Angajat &a) {
    nume = new char[strlen(a.nume) + 1];
    strcpy(nume, a.nume);
    calificare = a.calificare;
    salariu = a.salariu;
}
Angajat::~Angajat(){
    delete []nume;
}
void Angajat::afisare(){
    cout<<"Nume:" <<nume <<endl;
    cout<<"Calificare:" <<calificare <<endl;
    cout<<"Salariu:" <<salariu <<endl;
}

Angajat& Angajat::operator=(Angajat &a) {
    if (this != &a) {
        delete[]nume;
        nume = new char[strlen(a.nume) + 1];
        strcpy(nume, a.nume);
        calificare = a.calificare;
        salariu = a.salariu;
    }
    return *this;
}

/*
 * SefSectie - clasa derivata de Angajat
 *
 * atribute:
 *     nume
 *     calificare
 *     salariu
 *     departament
 *
 * metode:
*      constructor
 *      destructor
 *      afisare
 *      operator =
 * */
class SefSectie: public Angajat {
private:
    char *departament;
public:
    SefSectie(char *nume, int calificare, float salariu, char *departament);
    SefSectie(const SefSectie &a);
    SefSectie& operator=(SefSectie& a);
    ~SefSectie();
    void afisare();
};

SefSectie::SefSectie(char *nume, int calificare, float salariu, char *departament):Angajat(nume, calificare, salariu){
    this -> departament = new char[strlen(departament)];
    strcpy(this -> departament, departament);
}

SefSectie::SefSectie(const SefSectie& a): Angajat(a) {
    this -> departament = new char[strlen(a.departament)];
    strcpy(this -> departament, a.departament);
}

SefSectie::~SefSectie() {
    delete[] departament;
}

SefSectie& SefSectie::operator=(SefSectie& a) {
    if (this != &a) {
        Angajat::operator=(a);
        delete[] departament;
        departament = new char[strlen(a.departament)];
        strcpy(departament, a.departament);
    }
    return *this;
}

void SefSectie::afisare() {
    Angajat::afisare();
    cout << "Departament: " << departament << endl;
}

class Director: public Angajat {
private:
    float indemnizatie;
public:
    Director(char *nume, int calificare, float salariu, float indemnizatie);
    Director(const Director &a);
    Director& operator=(Director& a);
    ~Director();
    void afisare();
};

Director::Director(char *nume, int calificare, float salariu, float indemnizatie)
    :Angajat(nume, calificare, salariu){
    this -> indemnizatie = indemnizatie;
}

Director::Director(const Director &a): Angajat(a) {
    this -> indemnizatie = a.indemnizatie;
}

Director::~Director() {}

Director &Director::operator=(Director &a) {
    if (this != &a) {
        Angajat::operator=(a);
        this -> indemnizatie = a.indemnizatie;
    }
    return *this;
}

void Director::afisare() {
    Angajat::afisare();
    cout << "Indemnizatie: " << indemnizatie << endl;
}

int main() {
    Angajat a("Ion", 5, 1000);
    a.afisare();
    cout << endl;

    Angajat* b = new SefSectie("Ion", 5, 1000, "Departament1");
    b->afisare();
    cout << endl;

    Angajat* c = new Director("Ion", 5, 1000, 1000);
    c->afisare();
    cout << endl;

    return 0;
}