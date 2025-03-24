#include "ShowManager.h"
#include <iostream>
#include <ctime>
#include <sstream>  

using namespace std;

void ShowManager::addShow(const string& name, string date, const string actors[], int seats) { 
    while (!isValidDate(date)) {
        cout << "Please enter a valid future date (DD.MM.YYYY): ";
        cin >> date;  
    }

    Show newShow;
    newShow.name = name;
    newShow.date = date;
    newShow.totalSeats = seats;
    newShow.availableSeats = seats;

    for (int i = 0; i < MAX_ACTORS && !actors[i].empty(); ++i) {
        newShow.actors[i] = actors[i];
    }

    for (int i = 0; i < seats; ++i) {
        newShow.seatsOccupied[i] = false;
    }

    if (showCount < MAX_SEATS) {
        shows[showCount++] = newShow;
    }

    cout << "Show added successfully!" << endl;
}


bool ShowManager::isValidDate(const string& date) {
    time_t now = time(0);
    struct tm ltm;
    localtime_s(&ltm, &now);
    int year = 1900 + ltm.tm_year;
    int month = 1 + ltm.tm_mon;
    int day = ltm.tm_mday;

    int d, m, y;
    sscanf_s(date.c_str(), "%d.%d.%d", &d, &m, &y);

    if (y < year || (y == year && m < month) || (y == year && m == month && d < day)) {
        return false;
    }
    return true;
}

void ShowManager::listShows() const {
    cout << "List of Shows:" << endl;
    for (int i = 0; i < showCount; ++i) {
        cout << "Show: " << shows[i].name << " | Date: " << shows[i].date << " | Available seats: " << shows[i].availableSeats << endl;
        listActors(shows[i]);
    }
}

void ShowManager::listActors(const Show& show) const {
    cout << "Actors: ";
    bool first = true;
    for (int i = 0; i < MAX_ACTORS && !show.actors[i].empty(); ++i) {
        if (!first) {
            cout << ", ";
        }
        cout << show.actors[i];
        first = false;
    }
    cout << endl;
}

bool ShowManager::buyTicket(const string& showName, int seat) {
    for (int i = 0; i < showCount; ++i) {
        if (shows[i].name == showName) {
            if (seat < 1 || seat > shows[i].totalSeats) {
                cout << "Error: The seat number must be between 1 and " << shows[i].totalSeats << "." << endl;
                return false;
            }

            if (shows[i].seatsOccupied[seat - 1]) {
                cout << "Error: This ticket has already been sold." << endl;
                return false;
            }

            shows[i].seatsOccupied[seat - 1] = true;
            shows[i].availableSeats--;
            cout << "Ticket successfully purchased for seat " << seat << " at " << shows[i].name << "!" << endl;
            return true;
        }
    }
    cout << "Error: Show not found." << endl;
    return false;
}

const Show& ShowManager::getShow(int index) const {
    return shows[index];
}

int ShowManager::getShowCount() const {
    return showCount;
}
