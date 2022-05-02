#include <iostream>
#include "entities/Article.h"
#include "data access/Library.h"
#include "entities/Book.h"
#include "entities/Magazine.h"
#include "entities/CD_ROM.h"

using namespace std;

template<typename T>
void print(const vector<T>& v) {
    cout << endl;
    for (const auto& e : v) {
        cout << e << endl;
    }
}

int main() {
    auto* lib = new Library("data.txt");

    cout << "Get the whole library:" << endl;
    print<Article*>(lib->getAllArticles());

    lib->addArticle(new Book(
            19884,
            "The Lord of the Rings",
            1954,
            "fantasy",
            "J.R.R. Tolkien",
            "Harper Collins",
            890,
            "909-988-908-908"
    ));

    cout << "Get all books:" << endl;
    print<Article*>(lib->getArticlesByType<Book>());

    cout << "Removing the magazine with id: 19992" << endl;
    lib->removeArticle(19992);

    cout << "Get all magazines:" << endl;
    print<Article*>(lib->getArticlesByType<Magazine>());

    cout << "Get all articles with scifi genre:" << endl;
    print<Article*>(lib->getArticlesByGenre("scifi"));

    cout << "Get all articles sorted by title:" << endl;
    print<Article*>(lib->getArticlesSortedByTitle());

    cout << "Removing the book with id: 19989" << endl;
    lib->removeArticle(19989);

    cout << "Get all books:" << endl;
    print<Article*>(lib->getArticlesByType<Book>());

    cout << "Get all CD-ROMs:" << endl;
    print<Article*>(lib->getArticlesByType<CD_ROM>());

    cout << "Get all articles sorted by date:" << endl;
    print<Article*>(lib->getArticlesSortedByYearDesc());

    cout << "Get all articles between years: 1950 and 2000:" << endl;
    print<Article*>(lib->getArticlesBetweenYears(1950, 2000));

    cout << "Get the article with id: 98331" << endl;
    cout << lib->getArticleById(98331) << endl;

    cout << "Get all books sorted desc by year between 1950 and 2000:" << endl;

    auto is_book = [](Article* a) {
        return dynamic_cast<Book*>(a) != nullptr;
    };

    auto is_between_years = [](Article* a) {
        return a->getReleaseYear() >= 1950 && a->getReleaseYear() <= 2000;
    };

    auto sort_by_year_desc = [](Article* a, Article* b) {
        return a->getReleaseYear() > b->getReleaseYear();
    };

    print<Article*>(
        lib->getArticlesByFilter(is_book)
        ->getArticlesByFilter(is_between_years)
        ->sortArticlesByFilter(sort_by_year_desc)
        ->getAllArticles());

    cout << "Get all articles:" << endl;
    print<Article*>(lib->getAllArticles());

    cout << "Get all books:" << endl;
    print<Article*>(lib->getArticlesByType<Book>());

    delete lib;
    return 0;
}
