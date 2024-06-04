#include "16oop.cpp"
#include <iostream>

int main() {
    AirlineTicket myTicket;
    myTicket.setPassengerName("Ziad Assem");
    myTicket.setNumberOfMiles(700);
    double cost { myTicket.calculatePriceInDollars() };
    std::cout<<"This ticket will cost " <<cost;;
    return 0;
}
