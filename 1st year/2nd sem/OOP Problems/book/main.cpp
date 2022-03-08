#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
    char *title, *author;
    int nrOfPages;

public:
    Book(char* _title, char* _author, int _nrOfPages);
    ~Book();

    void print();

    char* getTitle();
    char* getAuthor();
    int getNrOfPages();

    void setTitle(char* _title);
    void setAuthor(char* _author);
    void setNrOfPages(int _nrOfPages);
};

Book::Book(char *_title, char *_author, int _nrOfPages) {
    title = new char[strlen(_title) + 1];
    strcpy(title, _title);

    author = new char[strlen(_author) + 1];
    strcpy(author, _author);

    nrOfPages = _nrOfPages;
}

Book::~Book() {
    delete[] title;
    delete[] author;
}

void Book::print() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Number of pages: " << nrOfPages << endl;
    cout << endl;
}

char* Book::getTitle() {
    return title;
}

char* Book::getAuthor() {
    return author;
}

int Book::getNrOfPages() {
    return nrOfPages;
}

void Book::setTitle(char *_title) {
    delete[] title;
    title = new char[strlen(_title) + 1];
    strcpy(title, _title);
}

void Book::setAuthor(char *_author) {
    delete[] author;
    author = new char[strlen(_author) + 1];
    strcpy(author, _author);
}

void Book::setNrOfPages(int _nrOfPages) {
    nrOfPages = _nrOfPages;
}

int main() {
    Book book1((char*)"The Lord of the Rings", (char*)"J.R.R. Tolkien", 1000);
    Book book2((char*)"The Hobbit", (char*)"J.R.R. Tolkien", 500);

    book1.print();
    book2.print();

    return 0;
}
