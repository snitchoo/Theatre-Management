#include "TicketManager.h"
#include <iostream>

using namespace std;

bool TicketManager::buyTicket(const string& showName, int seat, ShowManager& showManager) {
    for (int i = 0; i < showManager.getShowCount(); ++i) {
        const Show& show = showManager.getShow(i);
        if (show.name == showName) {
            if (seat < 1 || seat > show.totalSeats) {
                cout << "Error: The seat number must be between 1 and " << show.totalSeats << "." << endl;
                return false;
            }

            if (show.seatsOccupied[seat - 1]) {
                cout << "Error: This ticket has already been sold." << endl;
                return false;
            }

            showManager.buyTicket(showName, seat);
            return true;
        }
    }
    cout << "Error: Show not found." << endl;
    return false;
}
