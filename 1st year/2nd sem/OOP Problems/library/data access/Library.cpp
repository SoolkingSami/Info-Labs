//
// Created by asus on 4/23/2022.
//

#include "../entities/Book.h"
#include "../entities/Magazine.h"
#include "../entities/CD_ROM.h"
#include "Library.h"

Library::Library(string fileName): fin(ifstream(fileName)) {
    if (!fileName.empty()) {
        initArticles();
    }
}

Library::Library(const vector<Article *> &articles): articles(articles) {}

Library::~Library() {
    fin.close();
    for (auto& article: articles) {
        delete article;
    }
    articles.clear();
}

void Library::initArticles() {
    string line;
    while (getline(fin, line)) {
        if (line.empty()) {
            continue;
        }
        stringstream ss(line);
        string type;
        ss >> type;
        if (type == "book") {
            Article* book = new Book();
            fin >> book;
            articles.push_back(book);
        } else if (type == "magazine") {
            Article* magazine = new Magazine();
            fin >> magazine;
            articles.push_back(magazine);
        } else if (type == "cd") {
            Article* cd = new CD_ROM();
            fin >> cd;
            articles.push_back(cd);
        }
    }
}

void Library::addArticle(Article *article) {
    articles.push_back(article);
}

void Library::removeArticle(const int &id) {
    erase_if(articles, [id](Article* article) {
        return article->getId() == id;
    });
}

vector<Article*> Library::getAllArticles() const {
    return articles;
}

vector<Article*> Library::getArticlesByGenre(const string &genre) const {
    vector<Article*> result;
    copy_if(articles.begin(), articles.end(), back_inserter(result), [genre](Article* article) {
        return article->getGenre() == genre;
    });
    return result;
}

Article *Library::getArticleById(const int &id) const {
    auto it = find_if(articles.begin(), articles.end(), [id](Article* article) {
        return article->getId() == id;
    });
    if (it != articles.end()) {
        return *it;
    }
    return nullptr;
}

vector<Article *> Library::getArticlesSortedByYearDesc() const {
    vector<Article*> result;
    copy(articles.begin(), articles.end(), back_inserter(result));
    sort(result.begin(), result.end(), [](Article* article1, Article* article2) {
        return article1->getReleaseYear() > article2->getReleaseYear();
    });
    return result;
}

vector<Article *> Library::getArticlesSortedByTitle() const {
    vector<Article*> result;
    copy(articles.begin(), articles.end(), back_inserter(result));
    sort(result.begin(), result.end(), [](Article* article1, Article* article2) {
        return article1->getTitle() < article2->getTitle();
    });
    return result;
}

vector<Article *> Library::getArticlesBetweenYears(const int &startYear, const int &endYear) const {
    vector<Article*> result;
    copy_if(articles.begin(), articles.end(), back_inserter(result),
            [startYear, endYear](Article* article) {
        return article->getReleaseYear() >= startYear && article->getReleaseYear() <= endYear;
    });
    return result;
}

Library *Library::getArticlesByFilter(const function<bool(Article *)> &filter) const {
    vector<Article*> result;
    copy_if(articles.begin(), articles.end(), back_inserter(result), filter);
    return new Library(result);
}

Library *Library::sortArticlesByFilter(const function<bool(Article *, Article *)> &filter) const {
    vector<Article*> result;
    copy(articles.begin(), articles.end(), back_inserter(result));
    sort(result.begin(), result.end(), filter);
    return new Library(result);
}
