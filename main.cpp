/*
 * Name: Gabriel Santos
 * Course: CS 210
 * Project One: Chada Tech Clocks
 * Description: This program simulates Chada Tech's clock functionality by
 *              displaying 12-hour and 24-hour clocks at the same time. The
 *              user can add one hour, one minute, or one second until exiting.
 */

#include "Clock.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Prompts the user until a valid integer in the required range is entered.
int getValidatedInput(const string& prompt, int minimum, int maximum) {
    int value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail() && value >= minimum && value <= maximum) {
            return value;
        }

        cout << "Invalid input. Please enter a number from " << minimum
             << " to " << maximum << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Gets the initial time from the user and stores it in the Clock object.
void getInitialTime(Clock& clock) {
    int hour;
    int minute;
    int second;

    cout << "Enter the initial time using 24-hour format." << endl;
    hour = getValidatedInput("Hour (0-23): ", 0, 23);
    minute = getValidatedInput("Minute (0-59): ", 0, 59);
    second = getValidatedInput("Second (0-59): ", 0, 59);

    clock.setTime(hour, minute, second);
}

// Creates a string with repeated characters for the clock display border.
string repeatChar(char character, int count) {
    return string(count, character);
}

// Displays both the 12-hour clock and the 24-hour clock side by side.
void displayClocks(const Clock& clock) {
    cout << endl;
    cout << repeatChar('*', 27) << "   " << repeatChar('*', 27) << endl;
    cout << "*      12-Hour Clock      *   *      24-Hour Clock      *" << endl;
    cout << "*      " << clock.getTime12Hour() << "       *   *        "
         << clock.getTime24Hour() << "         *" << endl;
    cout << repeatChar('*', 27) << "   " << repeatChar('*', 27) << endl;
}

// Displays the user menu after the clock is shown.
void displayMenu() {
    cout << endl;
    cout << repeatChar('*', 27) << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << repeatChar('*', 27) << endl;
}

// Runs the menu loop and performs the option selected by the user.
void processMenuSelection(Clock& clock) {
    int menuChoice = 0;

    while (menuChoice != 4) {
        displayClocks(clock);
        displayMenu();
        menuChoice = getValidatedInput("Enter your choice: ", 1, 4);

        switch (menuChoice) {
            case 1:
                clock.addHour();
                break;
            case 2:
                clock.addMinute();
                break;
            case 3:
                clock.addSecond();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                break;
        }
    }
}

int main() {
    Clock clock;

    getInitialTime(clock);
    processMenuSelection(clock);

    return 0;
}
