//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_RENT_H
#define INTRODUCTIONPROJECT_RENT_H


#include <boost/uuid/uuid.hpp>
#include <boost/date_time.hpp>
#include "../typedef.h"
#include "Client.h"
#include "Room.h"
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
class Client;

class Rent {
    int id;
    double rentCost = 0.0;
    pt::ptime beginRentTime = pt::not_a_date_time;
    pt::ptime endRentTime = pt::not_a_date_time;
    ClientPtr client;
    RoomPtr room;
public:
    Rent(const int &id, const ClientPtr &client, const RoomPtr &room, const pt::ptime &beginRentTime);

    virtual ~Rent();

    const int &getId() const;

    double getRentCost() const;

    const pt::ptime &getBeginRentTime() const;

    const pt::ptime &getEndRentTime() const;

    const ClientPtr &getClient() const;

    const RoomPtr &getRoom() const;

    void endRent(const pt::ptime &endRentTime);

    int getRentDays();

    double CalculateFinalRentCost();

    std::string toString();
};


#endif //INTRODUCTIONPROJECT_RENT_H
