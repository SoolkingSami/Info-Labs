//
// Created by asus on 4/23/2022.
//

#ifndef LIBRARY_MAGAZINE_H
#define LIBRARY_MAGAZINE_H


#include "Article.h"
#include <vector>

class Magazine: public Article {
private:
    int number;
    string format;
    vector<string> topics;

public:
    explicit Magazine(const int& id = 0, string title = "", const int& releaseYear = 0, string genre = "",
                      const int& number = 0, string format = "", const vector<string>& topics = {});
    Magazine(const Magazine& magazine);
    Magazine& operator=(const Magazine& magazine);
    ~Magazine() override;

    int getNumber() const;
    string getFormat() const;
    vector<string> getTopics() const;

    void setNumber(const int& number);
    void setFormat(const string& format);
    void setTopics(const vector<string>& topics);

    friend ifstream& operator>>(ifstream& in, Magazine& magazine);
    friend ostream& operator<<(ostream& out, const Magazine& magazine);
    friend ifstream& operator>>(ifstream& in, Magazine*& magazine);
    friend ostream& operator<<(ostream& out, const Magazine* magazine);

private:
    string toString() const override;
    void read(ifstream& from) override;
};


#endif //LIBRARY_MAGAZINE_H
