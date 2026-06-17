#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock {
public:
    Clock(int hour = 0, int minute = 0, int second = 0);

    void setTime(int hour, int minute, int second);
    void addHour();
    void addMinute();
    void addSecond();

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    std::string getTime24Hour() const;
    std::string getTime12Hour() const;

private:
    int hour;
    int minute;
    int second;

    static int normalize(int value, int maximum);
    static std::string twoDigits(int value);
};

#endif
