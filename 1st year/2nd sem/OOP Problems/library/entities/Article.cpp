//
// Created by asus on 4/23/2022.
//

#include "Article.h"


Article::Article(const int& id, string title,
                 const int& releaseYear, string genre):
        id(id), title(move(title)),
        releaseYear(releaseYear), genre(move(genre)) {}

Article::Article(const Article &article):
        id(article.id), title(article.title),
        releaseYear(article.releaseYear), genre(article.genre) {}

int Article::getId() const {
    return id;
}

string Article::getTitle() const {
    return title;
}

int Article::getReleaseYear() const {
    return releaseYear;
}

string Article::getGenre() const {
    return genre;
}

void Article::setId(const int& id) {
    this->id = id;
}

void Article::setTitle(const string& title) {
    this->title = title;
}

void Article::setReleaseYear(const int& releaseYear) {
    this->releaseYear = releaseYear;
}

void Article::setGenre(const string& genre) {
    this->genre = genre;
}

string Article::toString() const {
    stringstream ss;
    ss << "ID: " << id << endl;
    ss << "Title: " << title << endl;
    ss << "Release Year: " << releaseYear << endl;
    ss << "Genre: " << genre << endl;
    return ss.str();
}

ifstream &operator>>(ifstream &in, Article &article) {
    article.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Article &article) {
    out << article.toString();
    return out;
}

Article &Article::operator=(const Article &article) {
    if (this != &article) {
        this->id = article.id;
        this->title = article.title;
        this->releaseYear = article.releaseYear;
        this->genre = article.genre;
    }
    return *this;
}

ifstream &operator>>(ifstream &in, Article *&article) {
    article->read(in);
    return in;
}

ostream& operator<<(ostream &out, const Article *article) {
    out << article->toString();
    return out;
}

void Article::read(ifstream& from) {
    from >> id;
    from.ignore();
    getline(from, title);
    from >> releaseYear;
    from.ignore();
    getline(from, genre);
}
