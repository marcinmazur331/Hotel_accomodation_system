//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_RENTMANAGER_H
#define INTRODUCTIONPROJECT_RENTMANAGER_H
#include "../repositories/RentRepository.h"
#include "../model/Default.h"
#include "../model/RegularCustomer.h"

class RentManager {
public:
    const RentRepository &getCurrentRents() const;

    RentPtr rentRoom(int id, ClientPtr client, RoomPtr room);

    void returnRoom(RoomPtr room);

    std::vector<RentPtr> getAllClientRents( ClientPtr client) const;

    RentPtr getRoomRent(RoomPtr room) const;

    double checkClientRentBalance( ClientPtr client) const;

    void changeClientType(ClientPtr client) ;

    std::vector<RentPtr> findRents(const RentPredicate &predicate) const;

    std::vector<RentPtr> findAllRents() ;

private:
    RentRepository currentRents;
    RentRepository archiveRents;



};


#endif //INTRODUCTIONPROJECT_RENTMANAGER_H