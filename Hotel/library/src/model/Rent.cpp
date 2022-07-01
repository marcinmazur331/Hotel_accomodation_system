//
// Created by student on 08.06.2022.
//

#include "../../include/model/Rent.h"
#include "../../include/exceptions/ParameterException.h"

Rent::Rent(const int &id, const ClientPtr &client, const RoomPtr &room, const pt::ptime &beginRentTime)
        : id(id), client(client), room(room), beginRentTime(beginRentTime) {
    if(client == nullptr ) { throw ParameterException("You have to pass Client!");}
    if(room == nullptr ) { throw ParameterException("You have to pass Room!");}
    if(id < 0 ) { throw ParameterException("Id cannot be lower than 0!");}
}

Rent::~Rent() {

}

const int &Rent::getId() const {
    return id;
}

double Rent::getRentCost() const {
    return rentCost;
}

const pt::ptime &Rent::getBeginRentTime() const {
    return beginRentTime;
}

const pt::ptime &Rent::getEndRentTime() const {
    return endRentTime;
}

const ClientPtr &Rent::getClient() const {
    return client;
}

const RoomPtr &Rent::getRoom() const {
    return room;
}

void Rent::endRent(const pt::ptime &parameter_endRentTime) {
    pt::ptime currentTime = pt::second_clock::local_time();
    if(endRentTime!=pt::not_a_date_time) return;
    if(parameter_endRentTime == pt::not_a_date_time) endRentTime = pt::second_clock::local_time();
    if(parameter_endRentTime<beginRentTime) endRentTime = currentTime;
    else endRentTime = parameter_endRentTime;
    CalculateFinalRentCost();

}

int Rent::getRentDays() {
//    if(endRentTime.is_not_a_date_time()) return 0;
//    pt::time_period period(beginRentTime,endRentTime);
//    if(period.length().hours()==0 && period.length().minutes()==0 || period.length().hours()==0 && period.length().minutes()==1) return 0;
//    return ((period.length().hours())/24) +1;
    int days= std::ceil(pt::time_period(beginRentTime, endRentTime).length().hours() / 24.0);
    if (days > 0) return days;
    return 0;

}

double Rent::CalculateFinalRentCost() {
    rentCost = getClient()->applyDiscount(getRentDays()*getRoom()->getBasePrice())*getRoom()->getRoomCapacity();
    return rentCost;
}

std::string Rent::toString() {
    std::ostringstream stream ;
    stream << "Type: Rent\tID: " << getId() << "\tClient info: " << getClient()->toString() << "\tRoom info: "
             << getRoom()->toString() << "\tbegin time: " << getBeginRentTime() << ", end time: "
             << getEndRentTime() << ", To pay: " + std::to_string(getRentCost());
    return stream.str();
}
