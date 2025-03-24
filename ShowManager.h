#pragma once
#include <string>
using  namespace std;

const int MAX_ACTORS = 10;   
const int MAX_SEATS = 100;    

struct Show {
    string name;
    string date;
    string actors[MAX_ACTORS];
    bool seatsOccupied[MAX_SEATS];
    int totalSeats;
    int availableSeats;
};

class ShowManager {
private:
    Show shows[MAX_SEATS]; 
    int showCount = 0;

public:
    void addShow(const string& name, string date, const string actors[], int seats); 
    bool isValidDate(const string& date);
    void listShows() const;
    void listActors(const Show& show) const;
    bool buyTicket(const string& showName, int seat);  
    const Show& getShow(int index) const;
    int getShowCount() const;
};


