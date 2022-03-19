#include <iostream>

using namespace std;

class CalendarDay {
private:
    int day;
    int month;
    int year;

public:
    explicit CalendarDay(int day = 1, int month = 1, int year = 1900);
    CalendarDay(const CalendarDay &other);

    friend int getDifference(const CalendarDay &day1, const CalendarDay &day2);

    friend istream& operator>>(istream& is, CalendarDay& cd);
    friend ostream& operator<<(ostream& os, const CalendarDay& cd);

    int getDay() const {
        return day;
    }

    void setDay(int _day) {
        day = _day;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int _month) {
        month = _month;
    }

    int getYear() const {
        return year;
    }

    void setYear(int _year) {
        year = _year;
    }
};

CalendarDay::CalendarDay(int day, int month, int year):
    day(day), month(month), year(year) {}

CalendarDay::CalendarDay(const CalendarDay &other) = default;

istream& operator>>(istream& is, CalendarDay& cd) {
    is >> cd.day >> cd.month >> cd.year;
    return is;
}

ostream& operator<<(ostream& os, const CalendarDay& cd) {
    os << cd.day << "/" << cd.month << "/" << cd.year;
    return os;
}

int getDifference(const CalendarDay &day1, const CalendarDay &day2) {
    int days;
    if (day1.year == day2.year) {
        if (day1.month == day2.month) {
            days = day2.day - day1.day;
        } else {
            days = (day2.day - day1.day) + (day2.month - day1.month) * 30;
        }
    } else {
        days = (day2.day - day1.day)
                + (day2.month - day1.month) * 30
                + (day2.year - day1.year) * 365;
    }
    return abs(days);
}

int main() {
    CalendarDay day1, day2;
    cout << "Enter first date (day/month/year):\n";
    cin >> day1;
    cout << "Enter second date (day/month/year):\n";
    cin >> day2;

    cout << "The difference between " << day1 << " and " << day2
         << " is of " << getDifference(day1, day2) << " days" << endl;

    return 0;
}
