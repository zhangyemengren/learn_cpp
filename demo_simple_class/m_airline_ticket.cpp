#include "m_airline_ticket.h"

AirlineTicket::AirlineTicket()
        : m_passengerName{"Unknown Passenger"},
          m_numberOfMiles{0},
          m_hasEliteSuperRewardsStatus{true}{

}

AirlineTicket::~AirlineTicket() {

}

double AirlineTicket::calculatePriceInDollars() {
    if (hasEliteSuperRewardsStatus()) {
        return 500;
    }
    return 200;
}

std::string AirlineTicket::getPassengerName() {
    return m_passengerName;
}

void AirlineTicket::setPassengerName(std::string name) {
    m_passengerName = name;
}

int AirlineTicket::getNumberOfMiles() {
    return m_numberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles) {
    m_numberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus() {
    return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status) {
    m_hasEliteSuperRewardsStatus = status;
}
