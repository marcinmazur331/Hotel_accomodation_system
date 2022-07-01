//
// Created by student on 08.06.2022.
//

#ifndef INTRODUCTIONPROJECT_ROOMMANAGER_H
#define INTRODUCTIONPROJECT_ROOMMANAGER_H
#include "../repositories/RoomRepository.h"

class RoomManager {
    RoomRepository repository;
public:

    RoomPtr registerRoom(int roomNumber, int roomCapacity, double basePrice);

    void unregisterRoom(RoomPtr room);

    std::vector<RoomPtr> findRoom(const RoomPredicate &predicate);

    std::vector<RoomPtr> findAllRoom();

    RoomPtr getRoom(const int &roomNumber) const;
};


#endif //INTRODUCTIONPROJECT_ROOMMANAGER_H
