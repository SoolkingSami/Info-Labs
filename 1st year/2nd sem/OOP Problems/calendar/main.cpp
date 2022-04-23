#include <iostream>
#include <map>

using namespace std;

map<int, string> monthToString = {
    {1, "January"},
    {2, "February"},
    {3, "March"},
    {4, "April"},
    {5, "May"},
    {6, "June"},
    {7, "July"},
    {8, "August"},
    {9, "September"},
    {10, "October"},
    {11, "November"},
    {12, "December"}
};

map<int, int> monthToDays = {
    {1, 31},
    {2, 28},
    {3, 31},
    {4, 30},
    {5, 31},
    {6, 30},
    {7, 31},
    {8, 31},
    {9, 30},
    {10, 31},
    {11, 30},
    {12, 31}
};

class CalendarDay {
private:
    int day;
    int month;
    int year;

public:
    explicit CalendarDay(int day = 1, int month = 1, int year = 1900);
    CalendarDay(const CalendarDay &other);

    friend int getDifference(const CalendarDay &day1, const CalendarDay &day2);

    bool isLeapYear() const;
    string toStringMonth() const;

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
    int days = 0;
    int yearDiff = abs(day1.getYear() - day2.getYear());
    int monthDiff = abs(day1.getMonth() - day2.getMonth());
    int dayDiff = abs(day1.getDay() - day2.getDay());

    if (yearDiff > 0) {
        for (int i = 0; i < yearDiff; i++) {
            if (day1.isLeapYear()) {
                days += 366;
            } else {
                days += 365;
            }
        }
    }

    if (monthDiff > 0) {
        for (int i = 0; i < monthDiff; i++) {
            days += monthToDays[day1.getMonth()];
        }
    }

    if (dayDiff > 0) {
        days += dayDiff;
    }

    return days;
}

string CalendarDay::toStringMonth() const {
    return to_string(day) + " " + monthToString[month] + " " + to_string(year);
}

bool CalendarDay::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    CalendarDay day1, day2;
    cout << "Enter first date (day/month/year):\n";
    cin >> day1;
    cout << "Enter second date (day/month/year):\n";
    cin >> day2;

    cout << "Date Time 1: " << day1.toStringMonth() << endl;
    cout << "Date Time 2: " << day2.toStringMonth() << endl;

    cout << "The difference between " << day1 << " and " << day2
         << " is of " << getDifference(day1, day2) << " days" << endl;

    return 0;
}
