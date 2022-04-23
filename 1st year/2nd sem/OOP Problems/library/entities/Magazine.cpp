//
// Created by asus on 4/23/2022.
//

#include "Magazine.h"

Magazine::Magazine(const int &id, string title, const int& releaseYear, string genre,
                   const int &number, string format, const vector<string>& topics):
                   Article(id, move(title), releaseYear, move(genre)),
                   number(number), format(move(format)), topics(topics) {}

Magazine::Magazine(const Magazine& magazine):
                   Article(magazine), number(magazine.number),
                   format(magazine.format), topics(magazine.topics) {}

Magazine &Magazine::operator=(const Magazine &magazine) {
    if (this != &magazine) {
        Article::operator=(magazine);
        number = magazine.number;
        format = magazine.format;
        topics = magazine.topics;
    }
    return *this;
}

Magazine::~Magazine() {
    topics.clear();
}

int Magazine::getNumber() const {
    return number;
}

string Magazine::getFormat() const {
    return format;
}

vector<string> Magazine::getTopics() const {
    return topics;
}

void Magazine::setNumber(const int &number) {
    this->number = number;
}

void Magazine::setFormat(const string &format) {
    this->format = format;
}

void Magazine::setTopics(const vector<string>& topics) {
    this->topics = topics;
}

string Magazine::toString() const {
    stringstream ss;
    ss << "Type: Magazine" << endl;
    ss << Article::toString()
    << "Number: " << number << endl
    << "Format: " << format << endl
    << "Topics: " << topics.size() << endl;
    for (const auto& topic: topics) {
        ss << topic << endl;
    }
    return ss.str();
}

void Magazine::read(ifstream &from) {
    Article::read(from);
    int topicsSize;
    from >> topicsSize;
    string topic;
    from.ignore();
    for (int i = 0; i < topicsSize; ++i) {
        getline(from, topic);
        topics.push_back(topic);
    }
    from >> number;
    from.ignore();
    getline(from, format);
}

ifstream &operator>>(ifstream &in, Magazine &magazine) {
    magazine.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Magazine &magazine) {
    out << magazine.toString();
    return out;
}

ifstream &operator>>(ifstream &in, Magazine*& magazine) {
    magazine->read(in);
    return in;
}

ostream &operator<<(ostream &out, const Magazine* magazine) {
    out << magazine->toString();
    return out;
}