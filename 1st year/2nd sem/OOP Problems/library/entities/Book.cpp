//
// Created by asus on 4/23/2022.
//

#include "Book.h"

Book::Book(const int &id, string title, const int& releaseYear, string genre, string author, string publisher,
           const int &nrOfPages, string codeISBN):
           Article(id, move(title), releaseYear, move(genre)),
           author(move(author)), publisher(move(publisher)),
           nrOfPages(nrOfPages), codeISBN(move(codeISBN)) {}

Book::Book(const Book &book): Article(book), author(book.author), publisher(book.publisher),
                              nrOfPages(book.nrOfPages), codeISBN(book.codeISBN) {}

Book& Book::operator=(const Book &book) {
    if (this != &book) {
        Article::operator=(book);
        author = book.author;
        publisher = book.publisher;
        nrOfPages = book.nrOfPages;
        codeISBN = book.codeISBN;
    }
    return *this;
}

string Book::getAuthor() const {
    return author;
}

string Book::getPublisher() const {
    return publisher;
}

int Book::getNrOfPages() const {
    return nrOfPages;
}

string Book::getCodeISBN() const {
    return codeISBN;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setPublisher(const string& publisher) {
    this->publisher = publisher;
}

void Book::setNrOfPages(const int& nrOfPages) {
    this->nrOfPages = nrOfPages;
}

void Book::setCodeISBN(const string& codeISBN) {
    this->codeISBN = codeISBN;
}

ifstream& operator>>(ifstream &in, Book &book) {
    book.read(in);
    return in;
}

ostream& operator<<(ostream &out, const Book& book) {
    out << book.toString();
    return out;
}

string Book::toString() const {
    stringstream ss;
    ss << "Type: Book" << endl
       << Article::toString() << "Author: " << author << endl
       << "Publisher: " << publisher << endl
       << "Nr of pages: " << nrOfPages << endl
       << "Code ISBN: " << codeISBN << endl;
    return ss.str();
}

void Book::read(ifstream& from) {
    Article::read(from);
    getline(from, author);
    getline(from, publisher);
    from >> nrOfPages >> codeISBN;
    from.ignore();
}

ifstream &operator>>(ifstream &in, Book *&book) {
    book->read(in);
    return in;
}

ostream &operator<<(ostream &os, const Book *book) {
    os << book->toString();
    return os;
}
