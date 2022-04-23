//
// Created by asus on 4/23/2022.
//

#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H


#include "../entities/Article.h"
#include <vector>
#include <algorithm>
#include <functional>

class Library {
private:
    vector<Article*> articles;
    ifstream fin;

public:
    explicit Library(string fileName = "");
    explicit Library(const vector<Article*>& articles = {});
    ~Library();

    void addArticle(Article* article);
    void removeArticle(const int& id);
    vector<Article*> getAllArticles() const;
    vector<Article*> getArticlesByGenre(const string& genre) const;
    Article* getArticleById(const int& id) const;
    vector<Article*> getArticlesSortedByYearDesc() const;
    vector<Article*> getArticlesSortedByTitle() const;
    vector<Article*> getArticlesBetweenYears(const int& startYear, const int& endYear) const;
    Library* getArticlesByFilter(const function<bool(Article*)>& filter) const;
    Library* sortArticlesByFilter(const function<bool(Article*, Article*)>& filter) const;

    template<typename T>
    vector<Article*> getArticlesByType() const {
        vector<Article*> result;
        copy_if(articles.begin(), articles.end(), back_inserter(result), [](Article* article) {
            return dynamic_cast<T*>(article) != nullptr;
        });
        return result;
    };

private:
    void initArticles();
};


#endif //LIBRARY_LIBRARY_H
