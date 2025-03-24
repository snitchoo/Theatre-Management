#include <iostream>
#include <string>
#include <limits>
#include "ShowManager.h"
#include "TicketManager.h"
#include "FileManager.h"

using namespace std;

void showMenu() {
    cout << "\n--- Theatre Management System ---\n";
    cout << "1. Add a new show\n";
    cout << "2. List all shows\n";
    cout << "3. Buy a ticket\n";
    cout << "4. Load data from file\n";
    cout << "5. Save data to file\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

void addShow(ShowManager& showManager) {
    string name, date;
    string actors[MAX_ACTORS];
    int seats;

    cout << "\nEnter the name of the show: ";
    cin.ignore(); 
    getline(cin, name);

    cout << "Enter the date of the show (DD.MM.YYYY): ";
    cin >> date;

    cout << "Enter the number of seats: ";
    cin >> seats;

    cout << "Enter the actors (up to " << MAX_ACTORS << "):\n";
    for (int i = 0; i < MAX_ACTORS; ++i) {
        cout << "Actor " << i + 1 << ": ";
        cin.ignore();
        getline(cin, actors[i]);
    }

    showManager.addShow(name, date, actors, seats);
}

void listShows(const ShowManager& showManager) {
    showManager.listShows();
}

void buyTicket(ShowManager& showManager, TicketManager& ticketManager) {
    string showName;
    int seat;

    cout << "\nEnter the show name: ";
    cin.ignore();
    getline(cin, showName);

    cout << "Enter the seat number: ";
    cin >> seat;

    ticketManager.buyTicket(showName, seat, showManager);
}

int main() {
    ShowManager showManager;
    TicketManager ticketManager;
    FileManager fileManager;
    int choice;

    
    fileManager.loadData(showManager);

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addShow(showManager);
            break;
        case 2:
            listShows(showManager);
            break;
        case 3:
            buyTicket(showManager, ticketManager);
            break;
        case 4:
            fileManager.loadData(showManager);
            break;
        case 5:
            fileManager.saveData(showManager);
            break;
        case 6:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
