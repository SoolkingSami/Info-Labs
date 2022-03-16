#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50

/**
* Citeste de la tastatura un sir de 'max' caractere si il pune in sir. *
Inainte elimina din buffer-ul tastaturii orice caracter. * Testat pe
CodeBlocks/Dev++
*/

void citesteSirCuSpatii(char *sir, int max) {
    if(cin.fail())
        cin.clear();
    cin.sync();
    cin.getline(sir, max,'\n');
    cin.clear();
    cin.sync();
}

class Carte {
private:
    char titlu[MAX];
    char autor[MAX];
    int anAparitie;
public:
    Carte(char *titlu="", char *autor="", int anAparitie=0);
    Carte(const Carte &c);
    ~Carte();
    void afisare();
    void citire();
    char* getTitlu();
    char* getAutor();
    int getAnAparitie();
    void setTitlu(char *titlu);
    void setAutor(char *autor);
    void setAnAparitie(int anAparitie);
};

Carte::Carte(char *titlu, char *autor, int anAparitie) {
    strncpy(this->titlu, titlu, sizeof(this->titlu));
    strncpy(this->autor, autor, sizeof(this->autor));
    this -> anAparitie = anAparitie;
    cout<<"Apel constructor"<<endl;
}

Carte::Carte(const Carte &c) {
    strncpy(this->titlu, c.titlu, sizeof(this->titlu));
    strncpy(this->autor, c.autor, sizeof(this->autor));
    this -> anAparitie = c.anAparitie;
    cout<<"Apel constructor de copiere"<<endl;
}

Carte::~Carte(){
    cout<<"Apel destructor"<<endl;
}

void Carte::afisare() {
    cout<<"----------------------"<<endl;
    cout<<"Titlu:\t"<<titlu<<endl;
    cout<<"Autor:\t"<<autor<<endl;
    cout<<"An:\t"<<anAparitie<<endl;
    cout<<"----------------------"<<endl;
}

void Carte::citire() {
    cout<<"Titlu:\t";
    citesteSirCuSpatii(titlu,sizeof(titlu));
    cout<<"Autor:\t";
    citesteSirCuSpatii(autor,sizeof(autor));
    cout<<"An:\t";
    cin>>anAparitie;
}

char *Carte::getTitlu() {
    return titlu;
}

char *Carte::getAutor() {
    return autor;
}

int Carte::getAnAparitie() {
    return anAparitie;
}

void Carte::setTitlu(char *titlu) {
    strncpy(this->titlu, titlu, sizeof(this->titlu));
}

void Carte::setAutor(char *autor) {
    strncpy(this->autor, autor, sizeof(this->autor));
}

void Carte::setAnAparitie(int anAparitie) {
    this -> anAparitie = anAparitie;
}

class Biblioteca {
private:
    Carte *carti;
    int nrCarti;
public:
    Biblioteca(int nrCarti=0, Carte *carti=NULL);
    ~Biblioteca();
    void adaugaCarte(Carte* carte);
    Carte cautaCarte(char *titlu);
    bool eliminaCarte(char *titlu);
    void afisare();
};

Biblioteca::Biblioteca(int nrCarti, Carte *carti) {
    this->nrCarti = nrCarti;
    this->carti = carti;
    cout<<"Apel constructor"<<endl;
}

Biblioteca::~Biblioteca() {
    delete [] carti;
    cout<<"Apel destructor"<<endl;
}

void Biblioteca::afisare() {
    for(int i=0; i<nrCarti; i++)
        carti[i].afisare();
}

void Biblioteca::adaugaCarte(Carte* carte) {
    cout << "Adaugare carte: " << carte->getTitlu() << endl;
    // save current array of books
    Carte *aux = carti;
    // create new array of books
    carti = new Carte[++nrCarti];
    // copy old books to new array
    for(int i=0; i<nrCarti-1; i++)
        carti[i] = aux[i];
    // add new book
    carti[nrCarti-1] = *carte;
}

bool Biblioteca::eliminaCarte(char *titlu) {
    cout << "Eliminare carte: " << titlu << endl;
    int i;
    for(i=0; i<nrCarti; i++) {
        if(strcmp(carti[i].getTitlu(), titlu) == 0) {
            for(int j=i; j<nrCarti-1; j++) {
                carti[j] = carti[j+1];
            }
            nrCarti--;
            return true;
        }
    }
    return false;
}

Carte Biblioteca::cautaCarte(char *titlu) {
    cout << "Cautare carte: " << titlu << endl;
    for(int i=0; i<nrCarti; i++) {
        if(strcmp(carti[i].getTitlu(), titlu) == 0) {
            return carti[i];
        }
    }
    return {};
}

int main() {
//    Carte c1("Ion", "Liviu Rebreanu", 1920);
//    c1.afisare();
//    int n=3;
//    Carte *carti= new Carte[3];
////    Carte carti[n];
//    for(int i=0;i<n;i++){
//    carti[i].citire();
//    }
//    for(int i=0;i<n;i++){
//    carti[i].afisare();
//    }
//    delete []carti;

    Carte* carti = new Carte[3];
    carti[0] = Carte("Ion", "Liviu Rebreanu", 1920);
    carti[1] = Carte("Morometii", "Marin Preda", 1955);
    carti[2] = Carte("Enigma Otiliei", "George Calinescu", 1938);

    Biblioteca biblioteca(3, carti);
    biblioteca.afisare();

    biblioteca.adaugaCarte(new Carte("Harap-Alb", "Ion Creanga", 1877));
    biblioteca.afisare();

    biblioteca.eliminaCarte("Ion");
    biblioteca.afisare();

    biblioteca.cautaCarte("Ion").afisare();
    biblioteca.cautaCarte("Harap-Alb").afisare();

    Carte c1("Ion", "Ion", 201), c2("Ion", "Alin", 90);
    c1.afisare();
    c2.afisare();
    c1 = c2;
    c1.afisare();
    c2.afisare();

    delete [] carti;
    return 0;
}