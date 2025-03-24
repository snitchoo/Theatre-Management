#pragma once
#include "ShowManager.h"

class TicketManager {
public:
    bool buyTicket(const std::string& showName, int seat, ShowManager& showManager); 
};

