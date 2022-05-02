//
// Created by asus on 4/23/2022.
//

#ifndef LIBRARY_CD_ROM_H
#define LIBRARY_CD_ROM_H


#include "Article.h"
#include <vector>

class CD_ROM: public Article {
private:
    int duration;
    int memory;
    string format;
    vector<string> songs;

public:
    explicit CD_ROM(const int& id = 0, string title = "", const int& releaseYear = 0, string genre = "",
           const int& duration = 0, const int& memory = 0, string format = "", const vector<string>& songs = {});
    CD_ROM(const CD_ROM& cd);
    CD_ROM& operator=(const CD_ROM& cd);
    ~CD_ROM() override;

    int getDuration() const;
    int getMemory() const;
    string getFormat() const;
    vector<string> getSongs() const;

    void setDuration(const int& duration);
    void setMemory(const int& memory);
    void setFormat(const string& format);
    void setSongs(const vector<string>& songs);

    friend ifstream& operator>>(ifstream& in, CD_ROM& cd);
    friend ostream& operator<<(ostream& out, const CD_ROM& cd);
    friend ifstream& operator>>(ifstream& in, CD_ROM*& cd);
    friend ostream& operator<<(ostream& out, const CD_ROM* cd);

private:
    string toString() const override;
    void read(ifstream& from) override;
};


#endif //LIBRARY_CD_ROM_H
