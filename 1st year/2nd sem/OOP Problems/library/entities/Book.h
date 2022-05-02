//
// Created by asus on 4/23/2022.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H


#include "Article.h"

class Book: public Article {
private:
    string author;
    string publisher;
    int nrOfPages;
    string codeISBN;

public:
    explicit Book(const int& id = 0, string title = "", const int& releaseYear = 0, string genre = "",
         string author = "", string publisher = "", const int& nrOfPages = 0, string codeISBN = "");
    Book(const Book& book);
    Book& operator=(const Book& book);
    ~Book() override = default;

    string getAuthor() const;
    string getPublisher() const;
    int getNrOfPages() const;
    string getCodeISBN() const;

    void setAuthor(const string& author);
    void setPublisher(const string& publisher);
    void setNrOfPages(const int& nrOfPages);
    void setCodeISBN(const string& codeISBN);

    friend ifstream& operator>>(ifstream& in, Book& book);
    friend ostream& operator<<(ostream& os, const Book& book);
    friend ifstream& operator>>(ifstream& in, Book*& book);
    friend ostream& operator<<(ostream& os, const Book* book);

private:
    string toString() const override;
    void read(ifstream& from) override;
};


#endif //LIBRARY_BOOK_H
