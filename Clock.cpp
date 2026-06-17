/*
 * Name: Gabriel Santos
 * Course: CS 210
 * Project One: Chada Tech Clocks
 * Description: Implements clock logic for adding hours, minutes, and seconds
 *              and for returning both 12-hour and 24-hour formatted time.
 */

#include "Clock.h"
#include <iomanip>
#include <sstream>

Clock::Clock(int hour, int minute, int second) {
    setTime(hour, minute, second);
}

void Clock::setTime(int hour, int minute, int second) {
    this->hour = normalize(hour, 24);
    this->minute = normalize(minute, 60);
    this->second = normalize(second, 60);
}

void Clock::addHour() {
    hour = (hour + 1) % 24;
}

void Clock::addMinute() {
    minute++;

    if (minute >= 60) {
        minute = 0;
        addHour();
    }
}

void Clock::addSecond() {
    second++;

    if (second >= 60) {
        second = 0;
        addMinute();
    }
}

int Clock::getHour() const {
    return hour;
}

int Clock::getMinute() const {
    return minute;
}

int Clock::getSecond() const {
    return second;
}

std::string Clock::getTime24Hour() const {
    return twoDigits(hour) + ":" + twoDigits(minute) + ":" + twoDigits(second);
}

std::string Clock::getTime12Hour() const {
    int displayHour = hour % 12;
    std::string period = " A M";

    if (displayHour == 0) {
        displayHour = 12;
    }

    if (hour >= 12) {
        period = " P M";
    }

    return twoDigits(displayHour) + ":" + twoDigits(minute) + ":" + twoDigits(second) + period;
}

int Clock::normalize(int value, int maximum) {
    value %= maximum;

    if (value < 0) {
        value += maximum;
    }

    return value;
}

std::string Clock::twoDigits(int value) {
    std::ostringstream output;
    output << std::setw(2) << std::setfill('0') << value;
    return output.str();
}
