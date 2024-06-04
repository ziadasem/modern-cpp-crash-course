#include "16oop.h"

AirlineTicket::AirlineTicket(): m_passengerName {"unknown"}, m_numberOfMiles {-1}, m_hasEliteSuperRewardsStatus {false} 
{
    
    /*
    If your class additionally needs to perform some other types of initializations, such as opening a
    file, allocating memory, and so on, then you still need to write a constructor to handle those initializations.
    */
}

//or
/*
AirlineTicket::AirlineTicket()
{
   m_passengerName = "unknown";
   m_numberOfMiles = -1 ;
   m_hasEliteSuperRewardsStatus = false ;
}
*/

AirlineTicket::~AirlineTicket()
{
// Nothing to do in terms of cleanup
}

double AirlineTicket::calculatePriceInDollars()
{
    if (hasEliteSuperRewardsStatus()) {
        // Elite Super Rewards customers fly for free!
        return 0;
    }
    // The cost of the ticket is the number of miles times 0.1.
    // Real airlines probably have a more complicated formula!
    return getNumberOfMiles() * 0.1;
}
std::string AirlineTicket::getPassengerName() { return m_passengerName; }
void AirlineTicket::setPassengerName(std::string name) { m_passengerName = name; }
int AirlineTicket::getNumberOfMiles() { return m_numberOfMiles; }
void AirlineTicket::setNumberOfMiles(int miles) { m_numberOfMiles = miles; }
bool AirlineTicket::hasEliteSuperRewardsStatus()
{
    return m_hasEliteSuperRewardsStatus;
}
void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
    m_hasEliteSuperRewardsStatus = status;
}