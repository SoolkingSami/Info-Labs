//
// Created by asus on 4/23/2022.
//

#ifndef LIBRARY_ARTICLE_H
#define LIBRARY_ARTICLE_H


#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Article {
protected:
    int id;
    string title;
    int releaseYear;
    string genre;

public:
    explicit Article(const int& id = 0, string title = "", const int& releaseYear = 0, string genre = "");
    Article(const Article &article);
    Article& operator=(const Article &article);
    virtual ~Article() = default;

    int getId() const;
    string getTitle() const;
    int getReleaseYear() const;
    string getGenre() const;

    void setId(const int& id);
    void setTitle(const string& title);
    void setReleaseYear(const int& releaseYear);
    void setGenre(const string& genre);

    friend ifstream &operator>>(ifstream &in, Article &article);
    friend ostream& operator<<(ostream& os, const Article& article);
    friend ifstream &operator>>(ifstream &in, Article*& article);
    friend ostream& operator<<(ostream& os, const Article* article);

protected:
    virtual string toString() const;
    virtual void read(ifstream& from);
};


#endif //LIBRARY_ARTICLE_H
