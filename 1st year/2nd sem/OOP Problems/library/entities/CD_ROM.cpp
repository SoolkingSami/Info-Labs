//
// Created by asus on 4/23/2022.
//

#include "CD_ROM.h"

CD_ROM::CD_ROM(const int &id, string title, const int& releaseYear, string genre,
               const int &duration, const int &memory, string format, const vector<string> &songs):
               Article(id, move(title), releaseYear, move(genre)),
               duration(duration), memory(memory), format(move(format)), songs(songs) {}

CD_ROM::CD_ROM(const CD_ROM &cd): Article(cd), duration(cd.duration), memory(cd.memory),
                                  format(cd.format), songs(cd.songs) {}

CD_ROM::~CD_ROM() {
    songs.clear();
}

CD_ROM &CD_ROM::operator=(const CD_ROM &cd) {
    if (this != &cd) {
        Article::operator=(cd);
        duration = cd.duration;
        memory = cd.memory;
        format = cd.format;
        songs = cd.songs;
    }
    return *this;
}

int CD_ROM::getDuration() const {
    return duration;
}

int CD_ROM::getMemory() const {
    return memory;
}

string CD_ROM::getFormat() const {
    return format;
}

vector<string> CD_ROM::getSongs() const {
    return songs;
}

void CD_ROM::setDuration(const int &duration) {
    this->duration = duration;
}

void CD_ROM::setMemory(const int &memory) {
    this->memory = memory;
}

void CD_ROM::setFormat(const string &format) {
    this->format = format;
}

void CD_ROM::setSongs(const vector<string> &songs) {
    this->songs = songs;
}

string CD_ROM::toString() const {
    stringstream ss;
    ss << "Type: CD-ROM" << endl;
    ss << Article::toString() << "Duration: " << duration << " minutes" << endl;
    ss << "Memory: " << memory << " MB" << endl;
    ss << "Format: " << format << endl;
    ss << "Songs: " << songs.size() << endl;
    for (const auto &song: songs) {
        ss << song << endl;
    }
    return ss.str();
}

void CD_ROM::read(ifstream& from) {
    Article::read(from);
    int nrOfSongs;
    from >> nrOfSongs;
    from.ignore();
    string song;
    for (int i = 0; i < nrOfSongs; ++i) {
        getline(from, song);
        songs.push_back(song);
    }
    from >> memory;
    from.ignore();
    getline(from, format);
    from >> duration;
    from.ignore();
}

ifstream &operator>>(ifstream &in, CD_ROM &cd) {
    cd.read(in);
    return in;
}

ostream &operator<<(ostream &out, const CD_ROM &cd) {
    out << cd.toString();
    return out;
}

ifstream &operator>>(ifstream &in, CD_ROM *&cd) {
    cd->read(in);
    return in;
}

ostream &operator<<(ostream &out, const CD_ROM *cd) {
    out << cd->toString();
    return out;
}
